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
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		NUMBER=10, ID=11, INT=12, FLOAT=13, DIGIT=14, LETTER=15, WS=16, NEWLINE=17;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"NUMBER", "ID", "INT", "FLOAT", "DIGIT", "LETTER", "WS", "NEWLINE"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, "NUMBER", 
			"ID", "INT", "FLOAT", "DIGIT", "LETTER", "WS", "NEWLINE"
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
		"\u0004\u0000\u0011l\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0001\u0000\u0001\u0000\u0001"+
		"\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001"+
		"\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001"+
		"\u0007\u0001\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0003\t8\b\t\u0001"+
		"\n\u0001\n\u0001\n\u0005\n=\b\n\n\n\f\n@\t\n\u0001\u000b\u0003\u000bC"+
		"\b\u000b\u0001\u000b\u0004\u000bF\b\u000b\u000b\u000b\f\u000bG\u0001\f"+
		"\u0003\fK\b\f\u0001\f\u0005\fN\b\f\n\f\f\fQ\t\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0003\fX\b\f\u0001\f\u0005\f[\b\f\n\f\f\f^\t\f\u0001"+
		"\r\u0001\r\u0001\u000e\u0001\u000e\u0001\u000f\u0004\u000fe\b\u000f\u000b"+
		"\u000f\f\u000ff\u0001\u000f\u0001\u000f\u0001\u0010\u0001\u0010\u0000"+
		"\u0000\u0011\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b"+
		"\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019\r\u001b"+
		"\u000e\u001d\u000f\u001f\u0010!\u0011\u0001\u0000\u0004\u0001\u000009"+
		"\u0003\u0000AZ__az\u0003\u0000\t\n\r\r  \u0002\u0000\n\n\r\ru\u0000\u0001"+
		"\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005"+
		"\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001"+
		"\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000"+
		"\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000"+
		"\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015\u0001\u0000"+
		"\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000\u0019\u0001\u0000"+
		"\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000\u001d\u0001\u0000"+
		"\u0000\u0000\u0000\u001f\u0001\u0000\u0000\u0000\u0000!\u0001\u0000\u0000"+
		"\u0000\u0001#\u0001\u0000\u0000\u0000\u0003%\u0001\u0000\u0000\u0000\u0005"+
		"\'\u0001\u0000\u0000\u0000\u0007)\u0001\u0000\u0000\u0000\t+\u0001\u0000"+
		"\u0000\u0000\u000b-\u0001\u0000\u0000\u0000\r/\u0001\u0000\u0000\u0000"+
		"\u000f1\u0001\u0000\u0000\u0000\u00113\u0001\u0000\u0000\u0000\u00137"+
		"\u0001\u0000\u0000\u0000\u00159\u0001\u0000\u0000\u0000\u0017B\u0001\u0000"+
		"\u0000\u0000\u0019J\u0001\u0000\u0000\u0000\u001b_\u0001\u0000\u0000\u0000"+
		"\u001da\u0001\u0000\u0000\u0000\u001fd\u0001\u0000\u0000\u0000!j\u0001"+
		"\u0000\u0000\u0000#$\u0005;\u0000\u0000$\u0002\u0001\u0000\u0000\u0000"+
		"%&\u0005=\u0000\u0000&\u0004\u0001\u0000\u0000\u0000\'(\u0005+\u0000\u0000"+
		"(\u0006\u0001\u0000\u0000\u0000)*\u0005-\u0000\u0000*\b\u0001\u0000\u0000"+
		"\u0000+,\u0005*\u0000\u0000,\n\u0001\u0000\u0000\u0000-.\u0005/\u0000"+
		"\u0000.\f\u0001\u0000\u0000\u0000/0\u0005%\u0000\u00000\u000e\u0001\u0000"+
		"\u0000\u000012\u0005(\u0000\u00002\u0010\u0001\u0000\u0000\u000034\u0005"+
		")\u0000\u00004\u0012\u0001\u0000\u0000\u000058\u0003\u0017\u000b\u0000"+
		"68\u0003\u0019\f\u000075\u0001\u0000\u0000\u000076\u0001\u0000\u0000\u0000"+
		"8\u0014\u0001\u0000\u0000\u00009>\u0003\u001d\u000e\u0000:=\u0003\u001d"+
		"\u000e\u0000;=\u0003\u001b\r\u0000<:\u0001\u0000\u0000\u0000<;\u0001\u0000"+
		"\u0000\u0000=@\u0001\u0000\u0000\u0000><\u0001\u0000\u0000\u0000>?\u0001"+
		"\u0000\u0000\u0000?\u0016\u0001\u0000\u0000\u0000@>\u0001\u0000\u0000"+
		"\u0000AC\u0005-\u0000\u0000BA\u0001\u0000\u0000\u0000BC\u0001\u0000\u0000"+
		"\u0000CE\u0001\u0000\u0000\u0000DF\u0003\u001b\r\u0000ED\u0001\u0000\u0000"+
		"\u0000FG\u0001\u0000\u0000\u0000GE\u0001\u0000\u0000\u0000GH\u0001\u0000"+
		"\u0000\u0000H\u0018\u0001\u0000\u0000\u0000IK\u0005-\u0000\u0000JI\u0001"+
		"\u0000\u0000\u0000JK\u0001\u0000\u0000\u0000KO\u0001\u0000\u0000\u0000"+
		"LN\u0003\u001b\r\u0000ML\u0001\u0000\u0000\u0000NQ\u0001\u0000\u0000\u0000"+
		"OM\u0001\u0000\u0000\u0000OP\u0001\u0000\u0000\u0000PW\u0001\u0000\u0000"+
		"\u0000QO\u0001\u0000\u0000\u0000RS\u0005.\u0000\u0000SX\u0003\u001b\r"+
		"\u0000TU\u0003\u001b\r\u0000UV\u0005.\u0000\u0000VX\u0001\u0000\u0000"+
		"\u0000WR\u0001\u0000\u0000\u0000WT\u0001\u0000\u0000\u0000X\\\u0001\u0000"+
		"\u0000\u0000Y[\u0003\u001b\r\u0000ZY\u0001\u0000\u0000\u0000[^\u0001\u0000"+
		"\u0000\u0000\\Z\u0001\u0000\u0000\u0000\\]\u0001\u0000\u0000\u0000]\u001a"+
		"\u0001\u0000\u0000\u0000^\\\u0001\u0000\u0000\u0000_`\u0007\u0000\u0000"+
		"\u0000`\u001c\u0001\u0000\u0000\u0000ab\u0007\u0001\u0000\u0000b\u001e"+
		"\u0001\u0000\u0000\u0000ce\u0007\u0002\u0000\u0000dc\u0001\u0000\u0000"+
		"\u0000ef\u0001\u0000\u0000\u0000fd\u0001\u0000\u0000\u0000fg\u0001\u0000"+
		"\u0000\u0000gh\u0001\u0000\u0000\u0000hi\u0006\u000f\u0000\u0000i \u0001"+
		"\u0000\u0000\u0000jk\u0007\u0003\u0000\u0000k\"\u0001\u0000\u0000\u0000"+
		"\u000b\u00007<>BGJOW\\f\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}