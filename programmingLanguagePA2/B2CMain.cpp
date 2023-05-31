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
	INT, REAL, STRING, BOOL, CHAR, UNDEFINED
} Tyenum;
static const string types[] = {
	"int", "double", "string", "bool", "char"
};

// Building symbol tables,
// infer types for 'auto' variables and functions
// ...
class TypeAnalysisVisitor : public BBaseVisitor {
public:

};

// Replace 'auto' in parse tree with inferred types
// ...
class TypeAugmentationVisitor : public BBaseVisitor {
public:
	any visitFuncdef(BParser::FuncdefContext* ctx) override {
		string functionName = ctx->name(0)->getText();
		// ctx->name(0).set
		// You can retrieve and visit the parameter list using ctx->name(i)
		// visit statement
		visit(ctx->statement());
		return nullptr;
	}
};

class PrintTreeVisitor : public BBaseVisitor {
public:
    any visitProgram(BParser::ProgramContext *ctx) override {
    	// Perform some actions when visiting the program
    	for (int i=0; i< ctx->children.size(); i++) {
      	    visit(ctx->children[i]);
    	}
    	return nullptr;
    }

    any visitDefinition(BParser::DefinitionContext *ctx) override {
	visit(ctx->children[0]);
        return nullptr;
    }

    any visitFuncdef(BParser::FuncdefContext *ctx) override {
		// Handle function definition
        string functionName = ctx->name(0)->getText();
		cout << "auto " << functionName << "(" ;
        // You can retrieve and visit the parameter list using ctx->name(i)
		for (int i=1; i < ctx->name().size(); i++) {
			if (i != 1) cout << ", ";
			cout << "auto " << ctx->name(i)->getText();		
		}
		cout << ")";

		// visit statement
		visit(ctx->statement());
        return nullptr;
    }

    any visitStatement(BParser::StatementContext *ctx) override {
		visit(ctx->children[0]);
        return nullptr;
    }

    any visitAutostmt(BParser::AutostmtContext *ctx) override {
    	// You can retrieve the variable names and constants using ctx->name(i) and ctx->constant(i)
		cout << "auto ";
		for (int i=0, j=0; i < ctx->name().size(); i++) {
			if (i != 0) cout << " ,";
			cout << ctx->name(i)->getText();

			int idx_assn = 1 + i*2 + j*2 + 1;  // auto name (= const)?, name (= const)?, ...
			if (ctx->children[idx_assn]->getText().compare("=") == 0) { 
				if (ctx->constant(j)) {
					cout << " = ";    
					visit(ctx->constant(j));
					j++;
				}
			}
		}
		cout << ";" << endl;
    	return nullptr;
    }

    any visitDeclstmt(BParser::DeclstmtContext *ctx) override {
		// Handle function declaration
        string functionName = ctx->name()->getText();
		cout << "auto " << functionName << "(" ;
        
		// You can retrieve and visit the parameter type list
		for (int i=1; i < ctx->AUTO().size(); i++) {
			if (i != 1) cout << ", ";
			cout << "auto ";		
		}
		cout << ");" << endl;
        return nullptr;
    }

    any visitBlockstmt(BParser::BlockstmtContext *ctx) override {
    	// Perform some actions when visiting a block statement
		cout << "{" << endl;
    	for (auto stmt : ctx->statement()) {
      	    visit(stmt);
    	}
		cout << "}" << endl;
    	return nullptr;
    }

    any visitIfstmt(BParser::IfstmtContext *ctx) override {
		cout << "if (";
		visit(ctx->expr());
		cout << ") " ;

		visit(ctx->statement(0));
		if (ctx->ELSE()) {
	   		cout << endl << "else ";
	   		visit(ctx->statement(1));
		}
        return nullptr;
    }

    any visitWhilestmt(BParser::WhilestmtContext *ctx) override {
        cout << "while (";
        visit(ctx->expr());
        cout << ") ";
        visit(ctx->statement());
        return nullptr;
    }

    any visitExpressionstmt(BParser::ExpressionstmtContext *ctx) override {
		visit(ctx->expression());
		cout << ";" << endl;
        return nullptr;
    }

    any visitReturnstmt(BParser::ReturnstmtContext *ctx) override {
		cout << "return";
		if (ctx->expression()) {
			cout << " (";
			visit(ctx->expression());
			cout << ")";
		}
		cout << ";" << endl;
        return nullptr;
    }

    any visitNullstmt(BParser::NullstmtContext *ctx) override {
		cout << ";" << endl;
        return nullptr;
    }

    any visitExpr(BParser::ExprContext *ctx) override {
		// unary operator
        if(ctx->atom()) {
            if (ctx->PLUS()) cout << "+";
            else if (ctx->MINUS()) cout << "-";
	    	else if (ctx->NOT()) cout << "!";
	    	visit(ctx->atom()); 
        }
		// binary operator
		else if (ctx->MUL() || ctx->DIV() || ctx->PLUS() || ctx->MINUS() || 
		 		ctx->GT() || ctx->GTE() || ctx->LT() || ctx->LTE() || ctx->EQ() || ctx->NEQ() ||
		 		ctx->AND() || ctx->OR() ) {
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
   
    any visitAtom(BParser::AtomContext *ctx) override {
		if (ctx->expression()) { // ( expression )
			cout << "(";
			visit(ctx->expression());
			cout << ")";
		}
		else	// name | constant | funcinvocation
			visit(ctx->children[0]);
        return nullptr;
    }
    
    any visitExpression(BParser::ExpressionContext *ctx) override {
        if (ctx->ASSN()) { // assignment
	   		visit(ctx->name());
	  		 cout << " = ";
		}
		visit(ctx->expr());
        return nullptr;
    }

    any visitFuncinvocation(BParser::FuncinvocationContext *ctx) override {
		cout << ctx->name()->getText() << "(";
		for (int i=0; i < ctx->expr().size(); i++) {
			if (i != 0) cout << ", ";
			visit(ctx->expr(i));
		}
		cout << ")";
        return nullptr;
    }
    
    any visitConstant(BParser::ConstantContext *ctx) override {
        cout << ctx->children[0]->getText();
        return nullptr;
    }
    
    any visitName(BParser::NameContext *ctx) override {
		cout << ctx->NAME()->getText();
        return nullptr;
    }
    
    any visitDirective(BParser::DirectiveContext *ctx) override {
		cout << ctx->SHARP_DIRECTIVE()->getText();
		cout << endl;
        return nullptr;
    }
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

    // STEP 2. visit parse tree and augment types for 'auto' typed variables --- you may skip this by keeping the class empty 
    TypeAugmentationVisitor AugmentTree;
    AugmentTree.visit(tree);

    // STEP 3. visit parse tree and print out C code with augmented types
    PrintTreeVisitor PrintTree;
    PrintTree.visit(tree);

    return 0;
}
