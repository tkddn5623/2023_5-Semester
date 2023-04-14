
// Generated from Expr.g4 by ANTLR 4.11.1


#include "ExprLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ExprLexerStaticData final {
  ExprLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ExprLexerStaticData(const ExprLexerStaticData&) = delete;
  ExprLexerStaticData(ExprLexerStaticData&&) = delete;
  ExprLexerStaticData& operator=(const ExprLexerStaticData&) = delete;
  ExprLexerStaticData& operator=(ExprLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag exprlexerLexerOnceFlag;
ExprLexerStaticData *exprlexerLexerStaticData = nullptr;

void exprlexerLexerInitialize() {
  assert(exprlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<ExprLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "OPERATOR1", "OPERATOR2", "OPERATOR3", "NUMBER", 
      "ID", "INT", "FLOAT", "DIGIT", "LETTER", "WS", "NEWLINE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,14,96,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,
  	1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,3,6,44,8,6,1,7,1,
  	7,1,7,5,7,49,8,7,10,7,12,7,52,9,7,1,8,3,8,55,8,8,1,8,4,8,58,8,8,11,8,
  	12,8,59,1,9,3,9,63,8,9,1,9,5,9,66,8,9,10,9,12,9,69,9,9,1,9,1,9,1,9,1,
  	9,1,9,3,9,76,8,9,1,9,5,9,79,8,9,10,9,12,9,82,9,9,1,10,1,10,1,11,1,11,
  	1,12,4,12,89,8,12,11,12,12,12,90,1,12,1,12,1,13,1,13,0,0,14,1,1,3,2,5,
  	3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,1,0,6,2,0,
  	43,43,45,45,2,0,42,42,47,47,1,0,48,57,3,0,65,90,95,95,97,122,3,0,9,10,
  	13,13,32,32,2,0,10,10,13,13,105,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,
  	7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,
  	0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,
  	1,29,1,0,0,0,3,31,1,0,0,0,5,33,1,0,0,0,7,35,1,0,0,0,9,37,1,0,0,0,11,39,
  	1,0,0,0,13,43,1,0,0,0,15,45,1,0,0,0,17,54,1,0,0,0,19,62,1,0,0,0,21,83,
  	1,0,0,0,23,85,1,0,0,0,25,88,1,0,0,0,27,94,1,0,0,0,29,30,5,59,0,0,30,2,
  	1,0,0,0,31,32,5,40,0,0,32,4,1,0,0,0,33,34,5,41,0,0,34,6,1,0,0,0,35,36,
  	5,61,0,0,36,8,1,0,0,0,37,38,7,0,0,0,38,10,1,0,0,0,39,40,7,1,0,0,40,12,
  	1,0,0,0,41,44,3,17,8,0,42,44,3,19,9,0,43,41,1,0,0,0,43,42,1,0,0,0,44,
  	14,1,0,0,0,45,50,3,23,11,0,46,49,3,23,11,0,47,49,3,21,10,0,48,46,1,0,
  	0,0,48,47,1,0,0,0,49,52,1,0,0,0,50,48,1,0,0,0,50,51,1,0,0,0,51,16,1,0,
  	0,0,52,50,1,0,0,0,53,55,7,0,0,0,54,53,1,0,0,0,54,55,1,0,0,0,55,57,1,0,
  	0,0,56,58,3,21,10,0,57,56,1,0,0,0,58,59,1,0,0,0,59,57,1,0,0,0,59,60,1,
  	0,0,0,60,18,1,0,0,0,61,63,7,0,0,0,62,61,1,0,0,0,62,63,1,0,0,0,63,67,1,
  	0,0,0,64,66,3,21,10,0,65,64,1,0,0,0,66,69,1,0,0,0,67,65,1,0,0,0,67,68,
  	1,0,0,0,68,75,1,0,0,0,69,67,1,0,0,0,70,71,5,46,0,0,71,76,3,21,10,0,72,
  	73,3,21,10,0,73,74,5,46,0,0,74,76,1,0,0,0,75,70,1,0,0,0,75,72,1,0,0,0,
  	76,80,1,0,0,0,77,79,3,21,10,0,78,77,1,0,0,0,79,82,1,0,0,0,80,78,1,0,0,
  	0,80,81,1,0,0,0,81,20,1,0,0,0,82,80,1,0,0,0,83,84,7,2,0,0,84,22,1,0,0,
  	0,85,86,7,3,0,0,86,24,1,0,0,0,87,89,7,4,0,0,88,87,1,0,0,0,89,90,1,0,0,
  	0,90,88,1,0,0,0,90,91,1,0,0,0,91,92,1,0,0,0,92,93,6,12,0,0,93,26,1,0,
  	0,0,94,95,7,5,0,0,95,28,1,0,0,0,11,0,43,48,50,54,59,62,67,75,80,90,1,
  	6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  exprlexerLexerStaticData = staticData.release();
}

}

ExprLexer::ExprLexer(CharStream *input) : Lexer(input) {
  ExprLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *exprlexerLexerStaticData->atn, exprlexerLexerStaticData->decisionToDFA, exprlexerLexerStaticData->sharedContextCache);
}

ExprLexer::~ExprLexer() {
  delete _interpreter;
}

std::string ExprLexer::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprLexer::getRuleNames() const {
  return exprlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ExprLexer::getChannelNames() const {
  return exprlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ExprLexer::getModeNames() const {
  return exprlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ExprLexer::getVocabulary() const {
  return exprlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ExprLexer::getSerializedATN() const {
  return exprlexerLexerStaticData->serializedATN;
}

const atn::ATN& ExprLexer::getATN() const {
  return *exprlexerLexerStaticData->atn;
}




void ExprLexer::initialize() {
  ::antlr4::internal::call_once(exprlexerLexerOnceFlag, exprlexerLexerInitialize);
}
