// Generated from java-escape by ANTLR 4.11.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class ExprLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.11.1", RuntimeMetaData.VERSION); }

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
		"\u0004\u0000\u0010h\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001"+
		"\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001"+
		"\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001"+
		"\b\u0001\b\u0003\b4\b\b\u0001\t\u0001\t\u0001\t\u0005\t9\b\t\n\t\f\t<"+
		"\t\t\u0001\n\u0003\n?\b\n\u0001\n\u0004\nB\b\n\u000b\n\f\nC\u0001\u000b"+
		"\u0003\u000bG\b\u000b\u0001\u000b\u0005\u000bJ\b\u000b\n\u000b\f\u000b"+
		"M\t\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0003\u000bT\b\u000b\u0001\u000b\u0005\u000bW\b\u000b\n\u000b\f\u000b"+
		"Z\t\u000b\u0001\f\u0001\f\u0001\r\u0001\r\u0001\u000e\u0004\u000ea\b\u000e"+
		"\u000b\u000e\f\u000eb\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f"+
		"\u0000\u0000\u0010\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005"+
		"\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019"+
		"\r\u001b\u000e\u001d\u000f\u001f\u0010\u0001\u0000\u0004\u0001\u00000"+
		"9\u0003\u0000AZ__az\u0003\u0000\t\n\r\r  \u0002\u0000\n\n\r\rq\u0000\u0001"+
		"\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005"+
		"\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001"+
		"\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000"+
		"\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000"+
		"\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015\u0001\u0000"+
		"\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000\u0019\u0001\u0000"+
		"\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000\u001d\u0001\u0000"+
		"\u0000\u0000\u0000\u001f\u0001\u0000\u0000\u0000\u0001!\u0001\u0000\u0000"+
		"\u0000\u0003#\u0001\u0000\u0000\u0000\u0005%\u0001\u0000\u0000\u0000\u0007"+
		"\'\u0001\u0000\u0000\u0000\t)\u0001\u0000\u0000\u0000\u000b+\u0001\u0000"+
		"\u0000\u0000\r-\u0001\u0000\u0000\u0000\u000f/\u0001\u0000\u0000\u0000"+
		"\u00113\u0001\u0000\u0000\u0000\u00135\u0001\u0000\u0000\u0000\u0015>"+
		"\u0001\u0000\u0000\u0000\u0017F\u0001\u0000\u0000\u0000\u0019[\u0001\u0000"+
		"\u0000\u0000\u001b]\u0001\u0000\u0000\u0000\u001d`\u0001\u0000\u0000\u0000"+
		"\u001ff\u0001\u0000\u0000\u0000!\"\u0005=\u0000\u0000\"\u0002\u0001\u0000"+
		"\u0000\u0000#$\u0005+\u0000\u0000$\u0004\u0001\u0000\u0000\u0000%&\u0005"+
		"-\u0000\u0000&\u0006\u0001\u0000\u0000\u0000\'(\u0005*\u0000\u0000(\b"+
		"\u0001\u0000\u0000\u0000)*\u0005/\u0000\u0000*\n\u0001\u0000\u0000\u0000"+
		"+,\u0005%\u0000\u0000,\f\u0001\u0000\u0000\u0000-.\u0005(\u0000\u0000"+
		".\u000e\u0001\u0000\u0000\u0000/0\u0005)\u0000\u00000\u0010\u0001\u0000"+
		"\u0000\u000014\u0003\u0015\n\u000024\u0003\u0017\u000b\u000031\u0001\u0000"+
		"\u0000\u000032\u0001\u0000\u0000\u00004\u0012\u0001\u0000\u0000\u0000"+
		"5:\u0003\u001b\r\u000069\u0003\u001b\r\u000079\u0003\u0019\f\u000086\u0001"+
		"\u0000\u0000\u000087\u0001\u0000\u0000\u00009<\u0001\u0000\u0000\u0000"+
		":8\u0001\u0000\u0000\u0000:;\u0001\u0000\u0000\u0000;\u0014\u0001\u0000"+
		"\u0000\u0000<:\u0001\u0000\u0000\u0000=?\u0005-\u0000\u0000>=\u0001\u0000"+
		"\u0000\u0000>?\u0001\u0000\u0000\u0000?A\u0001\u0000\u0000\u0000@B\u0003"+
		"\u0019\f\u0000A@\u0001\u0000\u0000\u0000BC\u0001\u0000\u0000\u0000CA\u0001"+
		"\u0000\u0000\u0000CD\u0001\u0000\u0000\u0000D\u0016\u0001\u0000\u0000"+
		"\u0000EG\u0005-\u0000\u0000FE\u0001\u0000\u0000\u0000FG\u0001\u0000\u0000"+
		"\u0000GK\u0001\u0000\u0000\u0000HJ\u0003\u0019\f\u0000IH\u0001\u0000\u0000"+
		"\u0000JM\u0001\u0000\u0000\u0000KI\u0001\u0000\u0000\u0000KL\u0001\u0000"+
		"\u0000\u0000LS\u0001\u0000\u0000\u0000MK\u0001\u0000\u0000\u0000NO\u0005"+
		".\u0000\u0000OT\u0003\u0019\f\u0000PQ\u0003\u0019\f\u0000QR\u0005.\u0000"+
		"\u0000RT\u0001\u0000\u0000\u0000SN\u0001\u0000\u0000\u0000SP\u0001\u0000"+
		"\u0000\u0000TX\u0001\u0000\u0000\u0000UW\u0003\u0019\f\u0000VU\u0001\u0000"+
		"\u0000\u0000WZ\u0001\u0000\u0000\u0000XV\u0001\u0000\u0000\u0000XY\u0001"+
		"\u0000\u0000\u0000Y\u0018\u0001\u0000\u0000\u0000ZX\u0001\u0000\u0000"+
		"\u0000[\\\u0007\u0000\u0000\u0000\\\u001a\u0001\u0000\u0000\u0000]^\u0007"+
		"\u0001\u0000\u0000^\u001c\u0001\u0000\u0000\u0000_a\u0007\u0002\u0000"+
		"\u0000`_\u0001\u0000\u0000\u0000ab\u0001\u0000\u0000\u0000b`\u0001\u0000"+
		"\u0000\u0000bc\u0001\u0000\u0000\u0000cd\u0001\u0000\u0000\u0000de\u0006"+
		"\u000e\u0000\u0000e\u001e\u0001\u0000\u0000\u0000fg\u0007\u0003\u0000"+
		"\u0000g \u0001\u0000\u0000\u0000\u000b\u000038:>CFKSXb\u0001\u0006\u0000"+
		"\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}