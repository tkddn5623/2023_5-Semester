// Generated from /mnt/hgfs/!!Programming projects/2022_5-Semester/programmingLanguagePA1/Expr.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ExprLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, NUMBER=9, 
		ID=10, INT=11, FLOAT=12, DIGIT=13, LETTER=14, WS=15, NEWLINE=16;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "NUMBER", 
			"ID", "INT", "FLOAT", "DIGIT", "LETTER", "WS", "NEWLINE"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, "NUMBER", "ID", 
			"INT", "FLOAT", "DIGIT", "LETTER", "WS", "NEWLINE"
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


	public ExprLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Expr.g4"; }

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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\22j\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\3\2\3\2\3"+
		"\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\5\n\66"+
		"\n\n\3\13\3\13\3\13\7\13;\n\13\f\13\16\13>\13\13\3\f\5\fA\n\f\3\f\6\f"+
		"D\n\f\r\f\16\fE\3\r\5\rI\n\r\3\r\7\rL\n\r\f\r\16\rO\13\r\3\r\3\r\3\r\3"+
		"\r\3\r\5\rV\n\r\3\r\7\rY\n\r\f\r\16\r\\\13\r\3\16\3\16\3\17\3\17\3\20"+
		"\6\20c\n\20\r\20\16\20d\3\20\3\20\3\21\3\21\2\2\22\3\3\5\4\7\5\t\6\13"+
		"\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22\3\2\6\3\2"+
		"\62;\5\2C\\aac|\5\2\13\f\17\17\"\"\4\2\f\f\17\17\2s\2\3\3\2\2\2\2\5\3"+
		"\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2"+
		"\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3"+
		"\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\3#\3\2\2\2\5%\3\2\2\2\7\'"+
		"\3\2\2\2\t)\3\2\2\2\13+\3\2\2\2\r-\3\2\2\2\17/\3\2\2\2\21\61\3\2\2\2\23"+
		"\65\3\2\2\2\25\67\3\2\2\2\27@\3\2\2\2\31H\3\2\2\2\33]\3\2\2\2\35_\3\2"+
		"\2\2\37b\3\2\2\2!h\3\2\2\2#$\7?\2\2$\4\3\2\2\2%&\7-\2\2&\6\3\2\2\2\'("+
		"\7/\2\2(\b\3\2\2\2)*\7,\2\2*\n\3\2\2\2+,\7\61\2\2,\f\3\2\2\2-.\7\'\2\2"+
		".\16\3\2\2\2/\60\7*\2\2\60\20\3\2\2\2\61\62\7+\2\2\62\22\3\2\2\2\63\66"+
		"\5\27\f\2\64\66\5\31\r\2\65\63\3\2\2\2\65\64\3\2\2\2\66\24\3\2\2\2\67"+
		"<\5\35\17\28;\5\35\17\29;\5\33\16\2:8\3\2\2\2:9\3\2\2\2;>\3\2\2\2<:\3"+
		"\2\2\2<=\3\2\2\2=\26\3\2\2\2><\3\2\2\2?A\7/\2\2@?\3\2\2\2@A\3\2\2\2AC"+
		"\3\2\2\2BD\5\33\16\2CB\3\2\2\2DE\3\2\2\2EC\3\2\2\2EF\3\2\2\2F\30\3\2\2"+
		"\2GI\7/\2\2HG\3\2\2\2HI\3\2\2\2IM\3\2\2\2JL\5\33\16\2KJ\3\2\2\2LO\3\2"+
		"\2\2MK\3\2\2\2MN\3\2\2\2NU\3\2\2\2OM\3\2\2\2PQ\7\60\2\2QV\5\33\16\2RS"+
		"\5\33\16\2ST\7\60\2\2TV\3\2\2\2UP\3\2\2\2UR\3\2\2\2VZ\3\2\2\2WY\5\33\16"+
		"\2XW\3\2\2\2Y\\\3\2\2\2ZX\3\2\2\2Z[\3\2\2\2[\32\3\2\2\2\\Z\3\2\2\2]^\t"+
		"\2\2\2^\34\3\2\2\2_`\t\3\2\2`\36\3\2\2\2ac\t\4\2\2ba\3\2\2\2cd\3\2\2\2"+
		"db\3\2\2\2de\3\2\2\2ef\3\2\2\2fg\b\20\2\2g \3\2\2\2hi\t\5\2\2i\"\3\2\2"+
		"\2\r\2\65:<@EHMUZd\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}