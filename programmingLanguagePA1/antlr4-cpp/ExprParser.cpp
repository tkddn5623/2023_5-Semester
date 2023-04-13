
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
      "prog", "stmt", "assn", "expr", "term", "factor"
    },
    std::vector<std::string>{
      "", "';'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "NUMBER", "ID", "INT", "FLOAT", 
      "DIGIT", "LETTER", "WS", "NEWLINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,17,64,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,1,0,
  	5,0,16,8,0,10,0,12,0,19,9,0,5,0,21,8,0,10,0,12,0,24,9,0,1,1,1,1,3,1,28,
  	8,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,5,3,40,8,3,10,3,12,3,43,9,
  	3,1,4,1,4,1,4,1,4,1,4,1,4,5,4,51,8,4,10,4,12,4,54,9,4,1,5,1,5,1,5,1,5,
  	1,5,1,5,3,5,62,8,5,1,5,0,2,6,8,6,0,2,4,6,8,10,0,2,1,0,3,4,1,0,5,7,64,
  	0,22,1,0,0,0,2,27,1,0,0,0,4,29,1,0,0,0,6,33,1,0,0,0,8,44,1,0,0,0,10,61,
  	1,0,0,0,12,13,3,2,1,0,13,17,5,1,0,0,14,16,5,17,0,0,15,14,1,0,0,0,16,19,
  	1,0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,21,1,0,0,0,19,17,1,0,0,0,20,12,
  	1,0,0,0,21,24,1,0,0,0,22,20,1,0,0,0,22,23,1,0,0,0,23,1,1,0,0,0,24,22,
  	1,0,0,0,25,28,3,4,2,0,26,28,3,6,3,0,27,25,1,0,0,0,27,26,1,0,0,0,28,3,
  	1,0,0,0,29,30,5,11,0,0,30,31,5,2,0,0,31,32,3,2,1,0,32,5,1,0,0,0,33,34,
  	6,3,-1,0,34,35,3,8,4,0,35,41,1,0,0,0,36,37,10,2,0,0,37,38,7,0,0,0,38,
  	40,3,8,4,0,39,36,1,0,0,0,40,43,1,0,0,0,41,39,1,0,0,0,41,42,1,0,0,0,42,
  	7,1,0,0,0,43,41,1,0,0,0,44,45,6,4,-1,0,45,46,3,10,5,0,46,52,1,0,0,0,47,
  	48,10,2,0,0,48,49,7,1,0,0,49,51,3,10,5,0,50,47,1,0,0,0,51,54,1,0,0,0,
  	52,50,1,0,0,0,52,53,1,0,0,0,53,9,1,0,0,0,54,52,1,0,0,0,55,56,5,8,0,0,
  	56,57,3,2,1,0,57,58,5,9,0,0,58,62,1,0,0,0,59,62,5,10,0,0,60,62,5,11,0,
  	0,61,55,1,0,0,0,61,59,1,0,0,0,61,60,1,0,0,0,62,11,1,0,0,0,6,17,22,27,
  	41,52,61
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
    setState(22);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3328) != 0) {
      setState(12);
      stmt();
      setState(13);
      match(ExprParser::T__0);
      setState(17);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::NEWLINE) {
        setState(14);
        match(ExprParser::NEWLINE);
        setState(19);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(24);
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
  enterRule(_localctx, 2, ExprParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(27);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(25);
      assn();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(26);
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
  enterRule(_localctx, 4, ExprParser::RuleAssn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(ExprParser::ID);
    setState(30);
    match(ExprParser::T__1);
    setState(31);
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
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, ExprParser::RuleExpr, precedence);

    size_t _la = 0;

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
    setState(34);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(41);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(36);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(37);
        _la = _input->LA(1);
        if (!(_la == ExprParser::T__2

        || _la == ExprParser::T__3)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(38);
        term(0); 
      }
      setState(43);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
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
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, ExprParser::RuleTerm, precedence);

    size_t _la = 0;

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
    setState(45);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(52);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(47);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(48);
        _la = _input->LA(1);
        if (!(((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 224) != 0)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(49);
        factor(); 
      }
      setState(54);
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
  enterRule(_localctx, 10, ExprParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(55);
        match(ExprParser::T__7);
        setState(56);
        stmt();
        setState(57);
        match(ExprParser::T__8);
        break;
      }

      case ExprParser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(59);
        match(ExprParser::NUMBER);
        break;
      }

      case ExprParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(60);
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
    case 3: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 4: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

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
