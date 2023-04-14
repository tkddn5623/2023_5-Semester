
// Generated from Expr.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ExprParser.
 */
class  ExprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(ExprParser::ProgContext *ctx) = 0;
  virtual void exitProg(ExprParser::ProgContext *ctx) = 0;

  virtual void enterTerminator(ExprParser::TerminatorContext *ctx) = 0;
  virtual void exitTerminator(ExprParser::TerminatorContext *ctx) = 0;

  virtual void enterStmt(ExprParser::StmtContext *ctx) = 0;
  virtual void exitStmt(ExprParser::StmtContext *ctx) = 0;

  virtual void enterAssn(ExprParser::AssnContext *ctx) = 0;
  virtual void exitAssn(ExprParser::AssnContext *ctx) = 0;

  virtual void enterExpr(ExprParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ExprParser::ExprContext *ctx) = 0;

  virtual void enterTerm(ExprParser::TermContext *ctx) = 0;
  virtual void exitTerm(ExprParser::TermContext *ctx) = 0;

  virtual void enterFactor(ExprParser::FactorContext *ctx) = 0;
  virtual void exitFactor(ExprParser::FactorContext *ctx) = 0;


};

