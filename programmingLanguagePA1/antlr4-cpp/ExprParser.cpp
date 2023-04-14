
// Generated from Expr.g4 by ANTLR 4.11.1


#include "ExprListener.h"

#include "ExprParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ExprParserStaticData final {
  ExprParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ExprParserStaticData(const ExprParserStaticData&) = delete;
  ExprParserStaticData(ExprParserStaticData&&) = delete;
  ExprParserStaticData& operator=(const ExprParserStaticData&) = delete;
  ExprParserStaticData& operator=(ExprParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag exprParserOnceFlag;
ExprParserStaticData *exprParserStaticData = nullptr;

void exprParserInitialize() {
  assert(exprParserStaticData == nullptr);
  auto staticData = std::make_unique<ExprParserStaticData>(
    std::vector<std::string>{
      "prog", "terminator", "stmt", "assn", "expr", "term", "factor"
    },
    std::vector<std::string>{
      "", "';'", "'('", "')'", "'='"
    },
    std::vector<std::string>{
      "", "", "", "", "OPERATOR1", "OPERATOR2", "OPERATOR3", "NUMBER", "ID", 
      "INT", "FLOAT", "DIGIT", "LETTER", "WS", "NEWLINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,14,71,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	1,0,1,0,5,0,18,8,0,10,0,12,0,21,9,0,5,0,23,8,0,10,0,12,0,26,9,0,1,1,4,
  	1,29,8,1,11,1,12,1,30,1,2,1,2,3,2,35,8,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,
  	1,4,1,4,1,4,5,4,47,8,4,10,4,12,4,50,9,4,1,5,1,5,1,5,1,5,1,5,1,5,5,5,58,
  	8,5,10,5,12,5,61,9,5,1,6,1,6,1,6,1,6,1,6,1,6,3,6,69,8,6,1,6,0,2,8,10,
  	7,0,2,4,6,8,10,12,0,0,71,0,24,1,0,0,0,2,28,1,0,0,0,4,34,1,0,0,0,6,36,
  	1,0,0,0,8,40,1,0,0,0,10,51,1,0,0,0,12,68,1,0,0,0,14,15,3,4,2,0,15,19,
  	3,2,1,0,16,18,5,14,0,0,17,16,1,0,0,0,18,21,1,0,0,0,19,17,1,0,0,0,19,20,
  	1,0,0,0,20,23,1,0,0,0,21,19,1,0,0,0,22,14,1,0,0,0,23,26,1,0,0,0,24,22,
  	1,0,0,0,24,25,1,0,0,0,25,1,1,0,0,0,26,24,1,0,0,0,27,29,5,1,0,0,28,27,
  	1,0,0,0,29,30,1,0,0,0,30,28,1,0,0,0,30,31,1,0,0,0,31,3,1,0,0,0,32,35,
  	3,6,3,0,33,35,3,8,4,0,34,32,1,0,0,0,34,33,1,0,0,0,35,5,1,0,0,0,36,37,
  	5,8,0,0,37,38,5,4,0,0,38,39,3,4,2,0,39,7,1,0,0,0,40,41,6,4,-1,0,41,42,
  	3,10,5,0,42,48,1,0,0,0,43,44,10,2,0,0,44,45,5,5,0,0,45,47,3,10,5,0,46,
  	43,1,0,0,0,47,50,1,0,0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,9,1,0,0,0,50,
  	48,1,0,0,0,51,52,6,5,-1,0,52,53,3,12,6,0,53,59,1,0,0,0,54,55,10,2,0,0,
  	55,56,5,6,0,0,56,58,3,12,6,0,57,54,1,0,0,0,58,61,1,0,0,0,59,57,1,0,0,
  	0,59,60,1,0,0,0,60,11,1,0,0,0,61,59,1,0,0,0,62,63,5,2,0,0,63,64,3,4,2,
  	0,64,65,5,3,0,0,65,69,1,0,0,0,66,69,5,7,0,0,67,69,5,8,0,0,68,62,1,0,0,
  	0,68,66,1,0,0,0,68,67,1,0,0,0,69,13,1,0,0,0,7,19,24,30,34,48,59,68
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  exprParserStaticData = staticData.release();
}

}

ExprParser::ExprParser(TokenStream *input) : ExprParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ExprParser::ExprParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ExprParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *exprParserStaticData->atn, exprParserStaticData->decisionToDFA, exprParserStaticData->sharedContextCache, options);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

const atn::ATN& ExprParser::getATN() const {
  return *exprParserStaticData->atn;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return exprParserStaticData->ruleNames;
}

const dfa::Vocabulary& ExprParser::getVocabulary() const {
  return exprParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ExprParser::getSerializedATN() const {
  return exprParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

ExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::StmtContext *> ExprParser::ProgContext::stmt() {
  return getRuleContexts<ExprParser::StmtContext>();
}

ExprParser::StmtContext* ExprParser::ProgContext::stmt(size_t i) {
  return getRuleContext<ExprParser::StmtContext>(i);
}

std::vector<ExprParser::TerminatorContext *> ExprParser::ProgContext::terminator() {
  return getRuleContexts<ExprParser::TerminatorContext>();
}

ExprParser::TerminatorContext* ExprParser::ProgContext::terminator(size_t i) {
  return getRuleContext<ExprParser::TerminatorContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ProgContext::NEWLINE() {
  return getTokens(ExprParser::NEWLINE);
}

tree::TerminalNode* ExprParser::ProgContext::NEWLINE(size_t i) {
  return getToken(ExprParser::NEWLINE, i);
}


size_t ExprParser::ProgContext::getRuleIndex() const {
  return ExprParser::RuleProg;
}

void ExprParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void ExprParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

ExprParser::ProgContext* ExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 388) != 0) {
      setState(14);
      stmt();
      setState(15);
      terminator();
      setState(19);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::NEWLINE) {
        setState(16);
        match(ExprParser::NEWLINE);
        setState(21);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(26);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TerminatorContext ------------------------------------------------------------------

ExprParser::TerminatorContext::TerminatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::TerminatorContext::getRuleIndex() const {
  return ExprParser::RuleTerminator;
}

void ExprParser::TerminatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerminator(this);
}

void ExprParser::TerminatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerminator(this);
}

ExprParser::TerminatorContext* ExprParser::terminator() {
  TerminatorContext *_localctx = _tracker.createInstance<TerminatorContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleTerminator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(27);
      match(ExprParser::T__0);
      setState(30); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ExprParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

ExprParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::AssnContext* ExprParser::StmtContext::assn() {
  return getRuleContext<ExprParser::AssnContext>(0);
}

ExprParser::ExprContext* ExprParser::StmtContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}


size_t ExprParser::StmtContext::getRuleIndex() const {
  return ExprParser::RuleStmt;
}

void ExprParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void ExprParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}

ExprParser::StmtContext* ExprParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(34);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(32);
      assn();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(33);
      expr(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssnContext ------------------------------------------------------------------

ExprParser::AssnContext::AssnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::AssnContext::ID() {
  return getToken(ExprParser::ID, 0);
}

tree::TerminalNode* ExprParser::AssnContext::OPERATOR1() {
  return getToken(ExprParser::OPERATOR1, 0);
}

ExprParser::StmtContext* ExprParser::AssnContext::stmt() {
  return getRuleContext<ExprParser::StmtContext>(0);
}


size_t ExprParser::AssnContext::getRuleIndex() const {
  return ExprParser::RuleAssn;
}

void ExprParser::AssnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssn(this);
}

void ExprParser::AssnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssn(this);
}

ExprParser::AssnContext* ExprParser::assn() {
  AssnContext *_localctx = _tracker.createInstance<AssnContext>(_ctx, getState());
  enterRule(_localctx, 6, ExprParser::RuleAssn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    match(ExprParser::ID);
    setState(37);
    match(ExprParser::OPERATOR1);
    setState(38);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::TermContext* ExprParser::ExprContext::term() {
  return getRuleContext<ExprParser::TermContext>(0);
}

ExprParser::ExprContext* ExprParser::ExprContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

tree::TerminalNode* ExprParser::ExprContext::OPERATOR2() {
  return getToken(ExprParser::OPERATOR2, 0);
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ExprParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


ExprParser::ExprContext* ExprParser::expr() {
   return expr(0);
}

ExprParser::ExprContext* ExprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExprParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, ExprParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(41);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(48);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(43);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(44);
        match(ExprParser::OPERATOR2);
        setState(45);
        term(0); 
      }
      setState(50);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

ExprParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::FactorContext* ExprParser::TermContext::factor() {
  return getRuleContext<ExprParser::FactorContext>(0);
}

ExprParser::TermContext* ExprParser::TermContext::term() {
  return getRuleContext<ExprParser::TermContext>(0);
}

tree::TerminalNode* ExprParser::TermContext::OPERATOR3() {
  return getToken(ExprParser::OPERATOR3, 0);
}


size_t ExprParser::TermContext::getRuleIndex() const {
  return ExprParser::RuleTerm;
}

void ExprParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void ExprParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


ExprParser::TermContext* ExprParser::term() {
   return term(0);
}

ExprParser::TermContext* ExprParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  ExprParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, ExprParser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(52);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(59);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(54);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(55);
        match(ExprParser::OPERATOR3);
        setState(56);
        factor(); 
      }
      setState(61);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

ExprParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::StmtContext* ExprParser::FactorContext::stmt() {
  return getRuleContext<ExprParser::StmtContext>(0);
}

tree::TerminalNode* ExprParser::FactorContext::NUMBER() {
  return getToken(ExprParser::NUMBER, 0);
}

tree::TerminalNode* ExprParser::FactorContext::ID() {
  return getToken(ExprParser::ID, 0);
}


size_t ExprParser::FactorContext::getRuleIndex() const {
  return ExprParser::RuleFactor;
}

void ExprParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void ExprParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

ExprParser::FactorContext* ExprParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 12, ExprParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(68);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(62);
        match(ExprParser::T__1);
        setState(63);
        stmt();
        setState(64);
        match(ExprParser::T__2);
        break;
      }

      case ExprParser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(66);
        match(ExprParser::NUMBER);
        break;
      }

      case ExprParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(67);
        match(ExprParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 5: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool ExprParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void ExprParser::initialize() {
  ::antlr4::internal::call_once(exprParserOnceFlag, exprParserInitialize);
}
