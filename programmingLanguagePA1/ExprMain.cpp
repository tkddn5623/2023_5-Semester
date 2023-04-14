#include <iostream>
#include <string>
#include <map>
#include <stack>
#include "antlr4-cpp/ExprBaseListener.h"
#include "antlr4-cpp/ExprLexer.h"
#include "antlr4-cpp/ExprParser.h"

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;

class EvalListener: public ExprBaseListener {
public:
	virtual void enterProg(ExprParser::ProgContext* ctx) {
		isassn = false;
	}
	virtual void exitTerminator(ExprParser::TerminatorContext* ctx) {
		if(!isassn & !evalstack.empty()) cout << evalstack.top() << "\n";
		while (!evalstack.empty()) evalstack.pop();
		isassn = false;
	}
	virtual void exitAssn(ExprParser::AssnContext* ctx) {
		const auto op = ctx->getToken(ExprLexer::OPERATOR1, 0);
		const auto lhs = ctx->getToken(ExprLexer::ID, 0);
		double a;
		if (op) {
			string type = op->getSymbol()->getText();
			a = evalstack.top(); evalstack.pop();
			evalstack.pop();
			evalstack.push(a);
			switch (type.at(0)) {
			case '=':
				variables.insert_or_assign(lhs->getSymbol()->getText(), a);
				isassn = true;
				break;
			}
		}
	}
	virtual void exitExpr(ExprParser::ExprContext* ctx) {
		const auto op = ctx->getToken(ExprLexer::OPERATOR2, 0);
		double a, b;
		if (op) {
			string type = op->getSymbol()->getText();
			b = evalstack.top(); evalstack.pop();
			a = evalstack.top(); evalstack.pop();
			switch (type.at(0)) {
			case '+':
				a = a + b;
				break;
			case '-':
				a = a - b;
				break;
			}
			evalstack.push(a);
		}
	}
	virtual void exitTerm(ExprParser::TermContext* ctx) {
		const auto op = ctx->getToken(ExprLexer::OPERATOR3, 0);
		double a, b;
		if (op) {
			string type = op->getSymbol()->getText();
			b = evalstack.top(); evalstack.pop();
			a = evalstack.top(); evalstack.pop();
			switch (type.at(0)) {
			case '*':
				a = a * b;
				break;
			case '/':
				if (b == 0) {
					cout << "Error: divided by 0\n";
					exit(1);
				}
				a = a / b;
				break;
			}
			evalstack.push(a);
		}

	}
	virtual void visitTerminal(antlr4::tree::TerminalNode* node) {
		const string str = node->getText();
		const int type = node->getSymbol()->getType();
		switch (type) {
		case ExprLexer::NUMBER:
			evalstack.push(stod(str));
			break;
		case ExprLexer::ID:
			auto it = variables.find(str);
			if (it == variables.end()) {
				evalstack.push(0);
			}
			else {
				evalstack.push(it->second);
			}
			break;
		}		
	}
	virtual void visitErrorNode(antlr4::tree::ErrorNode* node) {
		cout << "\t\tErrornode: " << node->getText() << "\n";
	}
private:
	bool isassn;
	stack<double> evalstack;
	map<string, double> variables;
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
		exit(1);
	}

	ANTLRInputStream input(stream);
	ExprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	ExprParser parser(&tokens);

	ParseTreeWalker walker;
	EvalListener listener;

	walker.walk(&listener, parser.prog());
}
