// B2CMain.cpp
#include <iostream>
#include <string.h>
#include <map>
#include <stack>
#include "antlr4-runtime.h"
#include "antlr4-cpp/BBaseVisitor.h"
#include "antlr4-cpp/BLexer.h"
#include "antlr4-cpp/BParser.h"

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;

static enum {
	UNDEFINED, INT, REAL, STRING, BOOL, CHAR
} types_enum;
static const string types[] = {
	"void", "int", "double", "string", "bool", "char"
};
vector<map<string, int>> type_maps;
vector<int> scope_prev;
map<string, int> scope_func_map;
map<string, vector<int>> params_func_map;

int type_assign(string str, int lexer_num, int scope) {
	auto tmap = &type_maps[scope];
	auto it = tmap->find(str);
	if (it == tmap->end() || it->second == lexer_num) {
		tmap->insert_or_assign(str, lexer_num);
		return 0;
	}
	else {
		cout << "// Error:[ASSIGNMENT](Type conflict occured.):" << str << endl;
		cerr << "// Error:[ASSIGNMENT](Type conflict occured.):" << str << endl;
		tmap->insert_or_assign(str, 0);
		return -1;
	}
}
int type_search(string str, int scope) {
	while (scope > -1) {
		auto it = type_maps[scope].find(str);
		if (it == type_maps[scope].end()) {
			scope = scope_prev[scope];
		}
		else return it->second;
	}
	return 0;
}
int lex2enum(int a) {
	switch (a) {
	case BParser::BOOL: return BOOL;
	case BParser::INT: return INT;
	case BParser::REAL: return REAL;
	case BParser::STRING: return STRING;
	case BParser::CHAR: return CHAR;
	default: break;
	}
	return 0;
}
// Building symbol tables,
// infer types for 'auto' variables and functions
// ...
class TypeAnalysisVisitor : public BBaseVisitor {
public:
	any visitProgram(BParser::ProgramContext* ctx) override {
		vector<int> visit_twice(ctx->children.size());
		scope_prev.push_back(-1);
		scope_stack.push(scope_prev.size() - 1);
		type_maps.push_back(map<string, int>());
		visitChildren(ctx);
		/*for (int i = 0; i < ctx->children.size(); i++) {

		}*/
		return nullptr;
	}
	any visitFuncdef(BParser::FuncdefContext* ctx) {
		string name = ctx->name(0)->getText();
		if (scope_func_map.find(name) == scope_func_map.end()) {
			scope_func_map.insert_or_assign(name, scope_prev.size());
		}
		visitChildren(ctx);
		if (expr_last_lexer == 0 && name == "main") {
			expr_last_lexer = BLexer::INT;
		}
		type_assign(name, expr_last_lexer, scope_stack.top());
		params_func_map.insert({ name, vector<int>(12) });
		return nullptr;
	}
	any visitAutostmt(BParser::AutostmtContext* ctx) override {
		for (int i = 0, j = 0; i < ctx->name().size(); i++) {
			string name = ctx->name(i)->getText();
			int idx_assn = 1 + i * 2 + j * 2 + 1;  // auto name (= const)?, name (= const)?, ...
			int lexer_num;
			if (ctx->children[idx_assn]->getText().compare("=") == 0) {
				if (ctx->constant(j)) {
					auto c = ctx->constant(j);
					if (c->INT()) lexer_num = BLexer::INT;
					else if (c->REAL()) lexer_num = BLexer::REAL;
					else if (c->STRING()) lexer_num = BLexer::STRING;
					else if (c->BOOL()) lexer_num = BLexer::BOOL;
					else if (c->CHAR()) lexer_num = BLexer::CHAR;
					type_assign(name, lexer_num, scope_stack.top());
					j++;
				}
			}
		}
		return nullptr;
	}
	any visitBlockstmt(BParser::BlockstmtContext* ctx) override {
		scope_prev.push_back(scope_stack.top());
		scope_stack.push(scope_prev.size() - 1);
		type_maps.push_back(map<string, int>());
		visitChildren(ctx);
		scope_stack.pop();
		return nullptr;
	}
	any visitExpressionstmt(BParser::ExpressionstmtContext* ctx) override {
		expr_last_lexer = 0;
		visitChildren(ctx);
		return nullptr;
	}
	any visitReturnstmt(BParser::ReturnstmtContext* ctx) override {
		expr_last_lexer = 0;
		visitChildren(ctx);
		return nullptr;
	}
	any visitExpression(BParser::ExpressionContext* ctx) override {
		int expr_type;
		visit(ctx->expr());
		if (ctx->ASSN()) {
			string name = ctx->name()->getText();
			type_assign(name, expr_last_lexer, scope_stack.top());
		}
		return nullptr;
	}
	any visitAtom(BParser::AtomContext* ctx) override {
		int t;
		if (ctx->name()) {
			t = type_search(ctx->name()->getText(), scope_stack.top());
			if (expr_last_lexer && t != expr_last_lexer) {
				cout << "// Error:[Expression] (Type conflict occured.)::" << ctx->getText() << endl;
				cerr << "// Error:[Expression] (Type conflict occured.)::" << ctx->getText() << endl;

			}
			expr_last_lexer = t;
		}
		else if (ctx->constant()) {
			auto c = ctx->constant();
			if (c->INT()) t = BLexer::INT;
			else if (c->REAL()) t = BLexer::REAL;
			else if (c->STRING()) t = BLexer::STRING;
			else if (c->BOOL()) t = BLexer::BOOL;
			else if (c->CHAR()) t = BLexer::CHAR;
			if (expr_last_lexer && t != expr_last_lexer) {
				cout << "// Error:[Expression] (Type conflict occured.)::" << ctx->getText() << endl;
				cerr << "// Error:[Expression] (Type conflict occured.)::" << ctx->getText() << endl;
			}
			expr_last_lexer = t;
		}
		else if (ctx->expression()) {
			visit(ctx->expression());
		}
		else {
			visit(ctx->funcinvocation());
		}
		return nullptr;

	}
	any visitFuncinvocation(BParser::FuncinvocationContext* ctx) override {
		string functionName = ctx->name()->getText();
		int ell_save = expr_last_lexer;
		for (int i = 0; i < ctx->expr().size(); i++) {
			expr_last_lexer = 0;
			visit(ctx->expr(i));
		}
		return nullptr;
	}
private:
	stack<int> scope_stack;
	int expr_last_lexer;
};

class PrintTreeVisitor : public BBaseVisitor {
public:
	any visitProgram(BParser::ProgramContext* ctx) override {
		// Perform some actions when visiting the program
		scope_depth = 0;
		scope_stack.push(scope_depth++);
		for (int i = 0; i < ctx->children.size(); i++) {
			visit(ctx->children[i]);
		}
		return nullptr;
	}

	any visitDefinition(BParser::DefinitionContext* ctx) override {
		visit(ctx->children[0]);
		return nullptr;
	}

	any visitFuncdef(BParser::FuncdefContext* ctx) override {
		// Handle function definition
		string functionName = ctx->name(0)->getText();
		cout << types[lex2enum(type_search(functionName, 0))] << " " << functionName << "(";
		// You can retrieve and visit the parameter list using ctx->name(i)
		for (int i = 1; i < ctx->name().size(); i++) {
			if (i != 1) cout << ", ";
			cout << types[lex2enum(type_search(ctx->name(i)->getText(), scope_func_map.find(functionName)->second))];
			cout << " " << ctx->name(i)->getText();
		}
		cout << ")";

		// visit statement
		visit(ctx->statement());
		return nullptr;
	}

	any visitStatement(BParser::StatementContext* ctx) override {
		visit(ctx->children[0]);
		return nullptr;
	}

	any visitAutostmt(BParser::AutostmtContext* ctx) override {
		// You can retrieve the variable names and constants using ctx->name(i) and ctx->constant(i)
		int prevtype = -1, type_num, isnewline = 0;
		string name;
		// cout << "auto ";
		for (int i = 0, j = 0; i < ctx->name().size(); i++) {
			name = ctx->name(i)->getText();
			type_num = type_search(name, scope_stack.top());
			if (prevtype != type_num) {
				if (i != 0) cout << ";\n";
				if (type_num == 0) {
					cout << "//";
					cerr << "// Error: Never used variable [" << name << "])\n";
				}
				cout << types[lex2enum(type_num)] << " ";
				isnewline = 1;
			}
			if (!isnewline) {
				cout << ", ";
			}
			cout << name;

			int idx_assn = 1 + i * 2 + j * 2 + 1;  // auto name (= const)?, name (= const)?, ...
			if (ctx->children[idx_assn]->getText().compare("=") == 0) {
				if (ctx->constant(j)) {
					cout << " = ";
					visit(ctx->constant(j));
					j++;
				}
			}
			prevtype = type_num;
			isnewline = 0;
		}
		cout << ";" << endl;
		return nullptr;
	}

	any visitDeclstmt(BParser::DeclstmtContext* ctx) override {
		// Handle function declaration
		string functionName = ctx->name()->getText();
		cout << types[lex2enum(type_search(functionName, 0))] << " " << functionName << "(";

		// You can retrieve and visit the parameter type list
		for (int i = 1; i < ctx->AUTO().size(); i++) {
			if (i != 1) cout << ", ";
			cout << "auto ";
		}
		cout << ");" << endl;
		return nullptr;
	}

	any visitBlockstmt(BParser::BlockstmtContext* ctx) override {
		// Perform some actions when visiting a block statement
		scope_stack.push(scope_depth++);
		cout << "{" << endl;
		for (auto stmt : ctx->statement()) {
			visit(stmt);
		}
		cout << "}" << endl;
		scope_stack.pop();
		return nullptr;
	}

	any visitIfstmt(BParser::IfstmtContext* ctx) override {
		cout << "if (";
		visit(ctx->expr());
		cout << ") ";

		visit(ctx->statement(0));
		if (ctx->ELSE()) {
			cout << endl << "else ";
			visit(ctx->statement(1));
		}
		return nullptr;
	}

	any visitWhilestmt(BParser::WhilestmtContext* ctx) override {
		cout << "while (";
		visit(ctx->expr());
		cout << ") ";
		visit(ctx->statement());
		return nullptr;
	}

	any visitExpressionstmt(BParser::ExpressionstmtContext* ctx) override {
		visit(ctx->expression());
		cout << ";" << endl;
		return nullptr;
	}

	any visitReturnstmt(BParser::ReturnstmtContext* ctx) override {
		cout << "return";
		if (ctx->expression()) {
			cout << " (";
			visit(ctx->expression());
			cout << ")";
		}
		cout << ";" << endl;
		return nullptr;
	}

	any visitNullstmt(BParser::NullstmtContext* ctx) override {
		cout << ";" << endl;
		return nullptr;
	}

	any visitExpr(BParser::ExprContext* ctx) override {
		// unary operator
		if (ctx->atom()) {
			if (ctx->PLUS()) cout << "+";
			else if (ctx->MINUS()) cout << "-";
			else if (ctx->NOT()) cout << "!";
			visit(ctx->atom());
		}
		// binary operator
		else if (ctx->MUL() || ctx->DIV() || ctx->PLUS() || ctx->MINUS() ||
				 ctx->GT()  || ctx->GTE() || ctx->LT() || ctx->LTE() || ctx->EQ() || ctx->NEQ() ||
				 ctx->AND() || ctx->OR()) {
			visit(ctx->expr(0));
			cout << " " << ctx->children[1]->getText() << " "; // print binary operator
			visit(ctx->expr(1));
		}
		// ternary operator
		else if (ctx->QUEST()) {
			visit(ctx->expr(0));
			cout << " ? ";
			visit(ctx->expr(1));
			cout << " : ";
			visit(ctx->expr(2));
		}
		else {
			int lineNum = ctx->getStart()->getLine();
			cerr << endl << "[ERROR] visitExpr: unrecognized ops in Line " << lineNum << " --" << ctx->children[1]->getText() << endl;
			exit(-1); // error
		}
		return nullptr;
	}

	any visitAtom(BParser::AtomContext* ctx) override {
		if (ctx->expression()) { // ( expression )
			cout << "(";
			visit(ctx->expression());
			cout << ")";
		}
		else	// name | constant | funcinvocation
			visit(ctx->children[0]);
		return nullptr;
	}

	any visitExpression(BParser::ExpressionContext* ctx) override {
		if (ctx->ASSN()) { // assignment
			visit(ctx->name());
			cout << " = ";
		}
		visit(ctx->expr());
		return nullptr;
	}

	any visitFuncinvocation(BParser::FuncinvocationContext* ctx) override {
		cout << ctx->name()->getText() << "(";
		for (int i = 0; i < ctx->expr().size(); i++) {
			if (i != 0) cout << ", ";
			visit(ctx->expr(i));
		}
		cout << ")";
		return nullptr;
	}

	any visitConstant(BParser::ConstantContext* ctx) override {
		cout << ctx->children[0]->getText();
		return nullptr;
	}

	any visitName(BParser::NameContext* ctx) override {
		cout << ctx->NAME()->getText();
		return nullptr;
	}

	any visitDirective(BParser::DirectiveContext* ctx) override {
		cout << ctx->SHARP_DIRECTIVE()->getText();
		cout << endl;
		return nullptr;
	}
private:
	stack<int> scope_stack;
	int scope_depth;
};

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		cerr << "[Usage] " << argv[0] << "  <input-file>\n";
		exit(0);
	}
	std::ifstream stream;
	stream.open(argv[1]);
	if (stream.fail()) {
		cerr << argv[1] << " : file open fail\n";
		exit(0);
	}

	cout << "/*-- B2C ANTLR visitor --*/\n";

	ANTLRInputStream inputStream(stream);
	BLexer lexer(&inputStream);
	CommonTokenStream tokenStream(&lexer);
	BParser parser(&tokenStream);
	ParseTree* tree = parser.program();

	// STEP 1. visit parse tree and perform type inference for expressions, function calls
	TypeAnalysisVisitor AnalyzeTree;
	AnalyzeTree.visit(tree);

	// STEP 3. visit parse tree and print out C code with augmented types
	PrintTreeVisitor PrintTree;
	PrintTree.visit(tree);
	return 0;
}
