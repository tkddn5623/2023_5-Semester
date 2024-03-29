// Generated from /mnt/hgfs/!!Programming projects/2023_5-Semester/programmingLanguagePA2/B.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class BLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, AUTO=6, PLUS=7, MINUS=8, MUL=9, 
		DIV=10, NOT=11, GT=12, GTE=13, LT=14, LTE=15, EQ=16, NEQ=17, AND=18, OR=19, 
		QUEST=20, COLON=21, SEMI=22, IF=23, ELSE=24, WHILE=25, RETURN=26, ASSN=27, 
		BOOL=28, NAME=29, INT=30, REAL=31, STRING=32, CHAR=33, SHARP_DIRECTIVE=34, 
		BLOCKCOMMENT=35, LINECOMMENT=36, WS=37;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "AUTO", "PLUS", "MINUS", "MUL", 
			"DIV", "NOT", "GT", "GTE", "LT", "LTE", "EQ", "NEQ", "AND", "OR", "QUEST", 
			"COLON", "SEMI", "IF", "ELSE", "WHILE", "RETURN", "ASSN", "BOOL", "NAME", 
			"INT", "REAL", "STRING", "CHAR", "SHARP_DIRECTIVE", "BLOCKCOMMENT", "LINECOMMENT", 
			"WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "','", "')'", "'{'", "'}'", "'auto'", "'+'", "'-'", "'*'", 
			"'/'", "'!'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'&&'", "'||'", 
			"'?'", "':'", "';'", "'if'", "'else'", "'while'", "'return'", "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, "AUTO", "PLUS", "MINUS", "MUL", "DIV", 
			"NOT", "GT", "GTE", "LT", "LTE", "EQ", "NEQ", "AND", "OR", "QUEST", "COLON", 
			"SEMI", "IF", "ELSE", "WHILE", "RETURN", "ASSN", "BOOL", "NAME", "INT", 
			"REAL", "STRING", "CHAR", "SHARP_DIRECTIVE", "BLOCKCOMMENT", "LINECOMMENT", 
			"WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public BLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "B.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\'\u00ed\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3"+
		"\6\3\6\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3"+
		"\r\3\r\3\16\3\16\3\16\3\17\3\17\3\20\3\20\3\20\3\21\3\21\3\21\3\22\3\22"+
		"\3\22\3\23\3\23\3\23\3\24\3\24\3\24\3\25\3\25\3\26\3\26\3\27\3\27\3\30"+
		"\3\30\3\30\3\31\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32\3\32\3\32\3\33"+
		"\3\33\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\35\3\35\3\35\3\35\3\35\3\35"+
		"\3\35\3\35\3\35\5\35\u00a3\n\35\3\36\3\36\7\36\u00a7\n\36\f\36\16\36\u00aa"+
		"\13\36\3\37\6\37\u00ad\n\37\r\37\16\37\u00ae\3 \6 \u00b2\n \r \16 \u00b3"+
		"\3 \3 \7 \u00b8\n \f \16 \u00bb\13 \3!\3!\7!\u00bf\n!\f!\16!\u00c2\13"+
		"!\3!\3!\3\"\3\"\3\"\3\"\3#\3#\7#\u00cc\n#\f#\16#\u00cf\13#\3$\3$\3$\3"+
		"$\7$\u00d5\n$\f$\16$\u00d8\13$\3$\3$\3$\3$\3$\3%\3%\3%\3%\7%\u00e3\n%"+
		"\f%\16%\u00e6\13%\3%\3%\3&\3&\3&\3&\3\u00d6\2\'\3\3\5\4\7\5\t\6\13\7\r"+
		"\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25"+
		")\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37= ?!A\"C#E$G%I&K\'\3\2"+
		"\b\4\2C\\c|\6\2\62;C\\aac|\3\2\62;\5\2\f\f\17\17$$\4\2\f\f\17\17\5\2\13"+
		"\f\17\17\"\"\2\u00f5\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2"+
		"\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3"+
		"\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2"+
		"\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2"+
		"\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2"+
		"\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2"+
		"\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\3M\3\2\2\2\5O\3\2\2\2\7Q"+
		"\3\2\2\2\tS\3\2\2\2\13U\3\2\2\2\rW\3\2\2\2\17\\\3\2\2\2\21^\3\2\2\2\23"+
		"`\3\2\2\2\25b\3\2\2\2\27d\3\2\2\2\31f\3\2\2\2\33h\3\2\2\2\35k\3\2\2\2"+
		"\37m\3\2\2\2!p\3\2\2\2#s\3\2\2\2%v\3\2\2\2\'y\3\2\2\2)|\3\2\2\2+~\3\2"+
		"\2\2-\u0080\3\2\2\2/\u0082\3\2\2\2\61\u0085\3\2\2\2\63\u008a\3\2\2\2\65"+
		"\u0090\3\2\2\2\67\u0097\3\2\2\29\u00a2\3\2\2\2;\u00a4\3\2\2\2=\u00ac\3"+
		"\2\2\2?\u00b1\3\2\2\2A\u00bc\3\2\2\2C\u00c5\3\2\2\2E\u00c9\3\2\2\2G\u00d0"+
		"\3\2\2\2I\u00de\3\2\2\2K\u00e9\3\2\2\2MN\7*\2\2N\4\3\2\2\2OP\7.\2\2P\6"+
		"\3\2\2\2QR\7+\2\2R\b\3\2\2\2ST\7}\2\2T\n\3\2\2\2UV\7\177\2\2V\f\3\2\2"+
		"\2WX\7c\2\2XY\7w\2\2YZ\7v\2\2Z[\7q\2\2[\16\3\2\2\2\\]\7-\2\2]\20\3\2\2"+
		"\2^_\7/\2\2_\22\3\2\2\2`a\7,\2\2a\24\3\2\2\2bc\7\61\2\2c\26\3\2\2\2de"+
		"\7#\2\2e\30\3\2\2\2fg\7@\2\2g\32\3\2\2\2hi\7@\2\2ij\7?\2\2j\34\3\2\2\2"+
		"kl\7>\2\2l\36\3\2\2\2mn\7>\2\2no\7?\2\2o \3\2\2\2pq\7?\2\2qr\7?\2\2r\""+
		"\3\2\2\2st\7#\2\2tu\7?\2\2u$\3\2\2\2vw\7(\2\2wx\7(\2\2x&\3\2\2\2yz\7~"+
		"\2\2z{\7~\2\2{(\3\2\2\2|}\7A\2\2}*\3\2\2\2~\177\7<\2\2\177,\3\2\2\2\u0080"+
		"\u0081\7=\2\2\u0081.\3\2\2\2\u0082\u0083\7k\2\2\u0083\u0084\7h\2\2\u0084"+
		"\60\3\2\2\2\u0085\u0086\7g\2\2\u0086\u0087\7n\2\2\u0087\u0088\7u\2\2\u0088"+
		"\u0089\7g\2\2\u0089\62\3\2\2\2\u008a\u008b\7y\2\2\u008b\u008c\7j\2\2\u008c"+
		"\u008d\7k\2\2\u008d\u008e\7n\2\2\u008e\u008f\7g\2\2\u008f\64\3\2\2\2\u0090"+
		"\u0091\7t\2\2\u0091\u0092\7g\2\2\u0092\u0093\7v\2\2\u0093\u0094\7w\2\2"+
		"\u0094\u0095\7t\2\2\u0095\u0096\7p\2\2\u0096\66\3\2\2\2\u0097\u0098\7"+
		"?\2\2\u00988\3\2\2\2\u0099\u009a\7h\2\2\u009a\u009b\7c\2\2\u009b\u009c"+
		"\7n\2\2\u009c\u009d\7u\2\2\u009d\u00a3\7g\2\2\u009e\u009f\7v\2\2\u009f"+
		"\u00a0\7t\2\2\u00a0\u00a1\7w\2\2\u00a1\u00a3\7g\2\2\u00a2\u0099\3\2\2"+
		"\2\u00a2\u009e\3\2\2\2\u00a3:\3\2\2\2\u00a4\u00a8\t\2\2\2\u00a5\u00a7"+
		"\t\3\2\2\u00a6\u00a5\3\2\2\2\u00a7\u00aa\3\2\2\2\u00a8\u00a6\3\2\2\2\u00a8"+
		"\u00a9\3\2\2\2\u00a9<\3\2\2\2\u00aa\u00a8\3\2\2\2\u00ab\u00ad\t\4\2\2"+
		"\u00ac\u00ab\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae\u00ac\3\2\2\2\u00ae\u00af"+
		"\3\2\2\2\u00af>\3\2\2\2\u00b0\u00b2\t\4\2\2\u00b1\u00b0\3\2\2\2\u00b2"+
		"\u00b3\3\2\2\2\u00b3\u00b1\3\2\2\2\u00b3\u00b4\3\2\2\2\u00b4\u00b5\3\2"+
		"\2\2\u00b5\u00b9\7\60\2\2\u00b6\u00b8\t\4\2\2\u00b7\u00b6\3\2\2\2\u00b8"+
		"\u00bb\3\2\2\2\u00b9\u00b7\3\2\2\2\u00b9\u00ba\3\2\2\2\u00ba@\3\2\2\2"+
		"\u00bb\u00b9\3\2\2\2\u00bc\u00c0\7$\2\2\u00bd\u00bf\n\5\2\2\u00be\u00bd"+
		"\3\2\2\2\u00bf\u00c2\3\2\2\2\u00c0\u00be\3\2\2\2\u00c0\u00c1\3\2\2\2\u00c1"+
		"\u00c3\3\2\2\2\u00c2\u00c0\3\2\2\2\u00c3\u00c4\7$\2\2\u00c4B\3\2\2\2\u00c5"+
		"\u00c6\7)\2\2\u00c6\u00c7\13\2\2\2\u00c7\u00c8\7)\2\2\u00c8D\3\2\2\2\u00c9"+
		"\u00cd\7%\2\2\u00ca\u00cc\n\6\2\2\u00cb\u00ca\3\2\2\2\u00cc\u00cf\3\2"+
		"\2\2\u00cd\u00cb\3\2\2\2\u00cd\u00ce\3\2\2\2\u00ceF\3\2\2\2\u00cf\u00cd"+
		"\3\2\2\2\u00d0\u00d1\7\61\2\2\u00d1\u00d2\7,\2\2\u00d2\u00d6\3\2\2\2\u00d3"+
		"\u00d5\13\2\2\2\u00d4\u00d3\3\2\2\2\u00d5\u00d8\3\2\2\2\u00d6\u00d7\3"+
		"\2\2\2\u00d6\u00d4\3\2\2\2\u00d7\u00d9\3\2\2\2\u00d8\u00d6\3\2\2\2\u00d9"+
		"\u00da\7,\2\2\u00da\u00db\7\61\2\2\u00db\u00dc\3\2\2\2\u00dc\u00dd\b$"+
		"\2\2\u00ddH\3\2\2\2\u00de\u00df\7\61\2\2\u00df\u00e0\7\61\2\2\u00e0\u00e4"+
		"\3\2\2\2\u00e1\u00e3\n\6\2\2\u00e2\u00e1\3\2\2\2\u00e3\u00e6\3\2\2\2\u00e4"+
		"\u00e2\3\2\2\2\u00e4\u00e5\3\2\2\2\u00e5\u00e7\3\2\2\2\u00e6\u00e4\3\2"+
		"\2\2\u00e7\u00e8\b%\2\2\u00e8J\3\2\2\2\u00e9\u00ea\t\7\2\2\u00ea\u00eb"+
		"\3\2\2\2\u00eb\u00ec\b&\2\2\u00ecL\3\2\2\2\f\2\u00a2\u00a8\u00ae\u00b3"+
		"\u00b9\u00c0\u00cd\u00d6\u00e4\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}