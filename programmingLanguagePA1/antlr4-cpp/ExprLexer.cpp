
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
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "NUMBER", "ID", "INT", "FLOAT", "DIGIT", "LETTER", "WS", "NEWLINE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,17,108,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,
  	1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,3,9,56,8,9,1,10,1,10,1,10,5,10,61,
  	8,10,10,10,12,10,64,9,10,1,11,3,11,67,8,11,1,11,4,11,70,8,11,11,11,12,
  	11,71,1,12,3,12,75,8,12,1,12,5,12,78,8,12,10,12,12,12,81,9,12,1,12,1,
  	12,1,12,1,12,1,12,3,12,88,8,12,1,12,5,12,91,8,12,10,12,12,12,94,9,12,
  	1,13,1,13,1,14,1,14,1,15,4,15,101,8,15,11,15,12,15,102,1,15,1,15,1,16,
  	1,16,0,0,17,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,
  	25,13,27,14,29,15,31,16,33,17,1,0,4,1,0,48,57,3,0,65,90,95,95,97,122,
  	3,0,9,10,13,13,32,32,2,0,10,10,13,13,117,0,1,1,0,0,0,0,3,1,0,0,0,0,5,
  	1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,
  	0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,
  	27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,1,35,1,0,0,0,3,37,1,
  	0,0,0,5,39,1,0,0,0,7,41,1,0,0,0,9,43,1,0,0,0,11,45,1,0,0,0,13,47,1,0,
  	0,0,15,49,1,0,0,0,17,51,1,0,0,0,19,55,1,0,0,0,21,57,1,0,0,0,23,66,1,0,
  	0,0,25,74,1,0,0,0,27,95,1,0,0,0,29,97,1,0,0,0,31,100,1,0,0,0,33,106,1,
  	0,0,0,35,36,5,59,0,0,36,2,1,0,0,0,37,38,5,61,0,0,38,4,1,0,0,0,39,40,5,
  	43,0,0,40,6,1,0,0,0,41,42,5,45,0,0,42,8,1,0,0,0,43,44,5,42,0,0,44,10,
  	1,0,0,0,45,46,5,47,0,0,46,12,1,0,0,0,47,48,5,37,0,0,48,14,1,0,0,0,49,
  	50,5,40,0,0,50,16,1,0,0,0,51,52,5,41,0,0,52,18,1,0,0,0,53,56,3,23,11,
  	0,54,56,3,25,12,0,55,53,1,0,0,0,55,54,1,0,0,0,56,20,1,0,0,0,57,62,3,29,
  	14,0,58,61,3,29,14,0,59,61,3,27,13,0,60,58,1,0,0,0,60,59,1,0,0,0,61,64,
  	1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,63,22,1,0,0,0,64,62,1,0,0,0,65,67,
  	5,45,0,0,66,65,1,0,0,0,66,67,1,0,0,0,67,69,1,0,0,0,68,70,3,27,13,0,69,
  	68,1,0,0,0,70,71,1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,72,24,1,0,0,0,73,
  	75,5,45,0,0,74,73,1,0,0,0,74,75,1,0,0,0,75,79,1,0,0,0,76,78,3,27,13,0,
  	77,76,1,0,0,0,78,81,1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,87,1,0,0,0,
  	81,79,1,0,0,0,82,83,5,46,0,0,83,88,3,27,13,0,84,85,3,27,13,0,85,86,5,
  	46,0,0,86,88,1,0,0,0,87,82,1,0,0,0,87,84,1,0,0,0,88,92,1,0,0,0,89,91,
  	3,27,13,0,90,89,1,0,0,0,91,94,1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,
  	26,1,0,0,0,94,92,1,0,0,0,95,96,7,0,0,0,96,28,1,0,0,0,97,98,7,1,0,0,98,
  	30,1,0,0,0,99,101,7,2,0,0,100,99,1,0,0,0,101,102,1,0,0,0,102,100,1,0,
  	0,0,102,103,1,0,0,0,103,104,1,0,0,0,104,105,6,15,0,0,105,32,1,0,0,0,106,
  	107,7,3,0,0,107,34,1,0,0,0,11,0,55,60,62,66,71,74,79,87,92,102,1,6,0,
  	0
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
