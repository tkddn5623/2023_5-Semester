// Generated from /mnt/hgfs/!!Programming projects/2023_5-Semester/programmingLanguagePA2/B.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class BParser extends Parser {
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
	public static final int
		RULE_program = 0, RULE_definition = 1, RULE_funcdef = 2, RULE_statement = 3, 
		RULE_autostmt = 4, RULE_declstmt = 5, RULE_blockstmt = 6, RULE_ifstmt = 7, 
		RULE_whilestmt = 8, RULE_expressionstmt = 9, RULE_returnstmt = 10, RULE_nullstmt = 11, 
		RULE_expr = 12, RULE_atom = 13, RULE_expression = 14, RULE_funcinvocation = 15, 
		RULE_constant = 16, RULE_name = 17, RULE_directive = 18;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "definition", "funcdef", "statement", "autostmt", "declstmt", 
			"blockstmt", "ifstmt", "whilestmt", "expressionstmt", "returnstmt", "nullstmt", 
			"expr", "atom", "expression", "funcinvocation", "constant", "name", "directive"
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

	@Override
	public String getGrammarFileName() { return "B.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public BParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(BParser.EOF, 0); }
		public List<DirectiveContext> directive() {
			return getRuleContexts(DirectiveContext.class);
		}
		public DirectiveContext directive(int i) {
			return getRuleContext(DirectiveContext.class,i);
		}
		public List<DefinitionContext> definition() {
			return getRuleContexts(DefinitionContext.class);
		}
		public DefinitionContext definition(int i) {
			return getRuleContext(DefinitionContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(42);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==AUTO || _la==SHARP_DIRECTIVE) {
				{
				setState(40);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case SHARP_DIRECTIVE:
					{
					setState(38);
					directive();
					}
					break;
				case AUTO:
					{
					setState(39);
					definition();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(44);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(45);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DefinitionContext extends ParserRuleContext {
		public AutostmtContext autostmt() {
			return getRuleContext(AutostmtContext.class,0);
		}
		public DeclstmtContext declstmt() {
			return getRuleContext(DeclstmtContext.class,0);
		}
		public FuncdefContext funcdef() {
			return getRuleContext(FuncdefContext.class,0);
		}
		public DefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_definition; }
	}

	public final DefinitionContext definition() throws RecognitionException {
		DefinitionContext _localctx = new DefinitionContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_definition);
		try {
			setState(50);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(47);
				autostmt();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(48);
				declstmt();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(49);
				funcdef();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FuncdefContext extends ParserRuleContext {
		public List<TerminalNode> AUTO() { return getTokens(BParser.AUTO); }
		public TerminalNode AUTO(int i) {
			return getToken(BParser.AUTO, i);
		}
		public List<NameContext> name() {
			return getRuleContexts(NameContext.class);
		}
		public NameContext name(int i) {
			return getRuleContext(NameContext.class,i);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public FuncdefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcdef; }
	}

	public final FuncdefContext funcdef() throws RecognitionException {
		FuncdefContext _localctx = new FuncdefContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_funcdef);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(52);
			match(AUTO);
			setState(53);
			name();
			setState(54);
			match(T__0);
			setState(65);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==AUTO) {
				{
				setState(55);
				match(AUTO);
				setState(56);
				name();
				setState(62);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__1) {
					{
					{
					setState(57);
					match(T__1);
					setState(58);
					match(AUTO);
					setState(59);
					name();
					}
					}
					setState(64);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(67);
			match(T__2);
			setState(68);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public AutostmtContext autostmt() {
			return getRuleContext(AutostmtContext.class,0);
		}
		public DeclstmtContext declstmt() {
			return getRuleContext(DeclstmtContext.class,0);
		}
		public BlockstmtContext blockstmt() {
			return getRuleContext(BlockstmtContext.class,0);
		}
		public IfstmtContext ifstmt() {
			return getRuleContext(IfstmtContext.class,0);
		}
		public WhilestmtContext whilestmt() {
			return getRuleContext(WhilestmtContext.class,0);
		}
		public ExpressionstmtContext expressionstmt() {
			return getRuleContext(ExpressionstmtContext.class,0);
		}
		public ReturnstmtContext returnstmt() {
			return getRuleContext(ReturnstmtContext.class,0);
		}
		public NullstmtContext nullstmt() {
			return getRuleContext(NullstmtContext.class,0);
		}
		public DirectiveContext directive() {
			return getRuleContext(DirectiveContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_statement);
		try {
			setState(79);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(70);
				autostmt();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(71);
				declstmt();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(72);
				blockstmt();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(73);
				ifstmt();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(74);
				whilestmt();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(75);
				expressionstmt();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(76);
				returnstmt();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(77);
				nullstmt();
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(78);
				directive();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AutostmtContext extends ParserRuleContext {
		public TerminalNode AUTO() { return getToken(BParser.AUTO, 0); }
		public List<NameContext> name() {
			return getRuleContexts(NameContext.class);
		}
		public NameContext name(int i) {
			return getRuleContext(NameContext.class,i);
		}
		public TerminalNode SEMI() { return getToken(BParser.SEMI, 0); }
		public List<TerminalNode> ASSN() { return getTokens(BParser.ASSN); }
		public TerminalNode ASSN(int i) {
			return getToken(BParser.ASSN, i);
		}
		public List<ConstantContext> constant() {
			return getRuleContexts(ConstantContext.class);
		}
		public ConstantContext constant(int i) {
			return getRuleContext(ConstantContext.class,i);
		}
		public AutostmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_autostmt; }
	}

	public final AutostmtContext autostmt() throws RecognitionException {
		AutostmtContext _localctx = new AutostmtContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_autostmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(81);
			match(AUTO);
			setState(82);
			name();
			setState(85);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSN) {
				{
				setState(83);
				match(ASSN);
				setState(84);
				constant();
				}
			}

			setState(95);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__1) {
				{
				{
				setState(87);
				match(T__1);
				setState(88);
				name();
				setState(91);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ASSN) {
					{
					setState(89);
					match(ASSN);
					setState(90);
					constant();
					}
				}

				}
				}
				setState(97);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(98);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclstmtContext extends ParserRuleContext {
		public List<TerminalNode> AUTO() { return getTokens(BParser.AUTO); }
		public TerminalNode AUTO(int i) {
			return getToken(BParser.AUTO, i);
		}
		public NameContext name() {
			return getRuleContext(NameContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(BParser.SEMI, 0); }
		public DeclstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declstmt; }
	}

	public final DeclstmtContext declstmt() throws RecognitionException {
		DeclstmtContext _localctx = new DeclstmtContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_declstmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(100);
			match(AUTO);
			setState(101);
			name();
			setState(102);
			match(T__0);
			setState(111);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==AUTO) {
				{
				setState(103);
				match(AUTO);
				setState(108);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__1) {
					{
					{
					setState(104);
					match(T__1);
					setState(105);
					match(AUTO);
					}
					}
					setState(110);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(113);
			match(T__2);
			setState(114);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockstmtContext extends ParserRuleContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public BlockstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockstmt; }
	}

	public final BlockstmtContext blockstmt() throws RecognitionException {
		BlockstmtContext _localctx = new BlockstmtContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_blockstmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(116);
			match(T__3);
			setState(120);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__3) | (1L << AUTO) | (1L << PLUS) | (1L << MINUS) | (1L << NOT) | (1L << SEMI) | (1L << IF) | (1L << WHILE) | (1L << RETURN) | (1L << BOOL) | (1L << NAME) | (1L << INT) | (1L << REAL) | (1L << STRING) | (1L << CHAR) | (1L << SHARP_DIRECTIVE))) != 0)) {
				{
				{
				setState(117);
				statement();
				}
				}
				setState(122);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(123);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfstmtContext extends ParserRuleContext {
		public TerminalNode IF() { return getToken(BParser.IF, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(BParser.ELSE, 0); }
		public IfstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifstmt; }
	}

	public final IfstmtContext ifstmt() throws RecognitionException {
		IfstmtContext _localctx = new IfstmtContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_ifstmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(125);
			match(IF);
			setState(126);
			match(T__0);
			setState(127);
			expr(0);
			setState(128);
			match(T__2);
			setState(129);
			statement();
			setState(132);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				{
				setState(130);
				match(ELSE);
				setState(131);
				statement();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhilestmtContext extends ParserRuleContext {
		public TerminalNode WHILE() { return getToken(BParser.WHILE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public WhilestmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whilestmt; }
	}

	public final WhilestmtContext whilestmt() throws RecognitionException {
		WhilestmtContext _localctx = new WhilestmtContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_whilestmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(134);
			match(WHILE);
			setState(135);
			match(T__0);
			setState(136);
			expr(0);
			setState(137);
			match(T__2);
			setState(138);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionstmtContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(BParser.SEMI, 0); }
		public ExpressionstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expressionstmt; }
	}

	public final ExpressionstmtContext expressionstmt() throws RecognitionException {
		ExpressionstmtContext _localctx = new ExpressionstmtContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_expressionstmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(140);
			expression();
			setState(141);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ReturnstmtContext extends ParserRuleContext {
		public TerminalNode RETURN() { return getToken(BParser.RETURN, 0); }
		public TerminalNode SEMI() { return getToken(BParser.SEMI, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ReturnstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_returnstmt; }
	}

	public final ReturnstmtContext returnstmt() throws RecognitionException {
		ReturnstmtContext _localctx = new ReturnstmtContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_returnstmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(143);
			match(RETURN);
			setState(149);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(144);
				expression();
				}
				break;
			case 2:
				{
				setState(145);
				match(T__0);
				setState(146);
				expression();
				setState(147);
				match(T__2);
				}
				break;
			}
			setState(151);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NullstmtContext extends ParserRuleContext {
		public TerminalNode SEMI() { return getToken(BParser.SEMI, 0); }
		public NullstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nullstmt; }
	}

	public final NullstmtContext nullstmt() throws RecognitionException {
		NullstmtContext _localctx = new NullstmtContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_nullstmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(153);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public TerminalNode PLUS() { return getToken(BParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(BParser.MINUS, 0); }
		public TerminalNode NOT() { return getToken(BParser.NOT, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode MUL() { return getToken(BParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(BParser.DIV, 0); }
		public TerminalNode GT() { return getToken(BParser.GT, 0); }
		public TerminalNode GTE() { return getToken(BParser.GTE, 0); }
		public TerminalNode LT() { return getToken(BParser.LT, 0); }
		public TerminalNode LTE() { return getToken(BParser.LTE, 0); }
		public TerminalNode EQ() { return getToken(BParser.EQ, 0); }
		public TerminalNode NEQ() { return getToken(BParser.NEQ, 0); }
		public TerminalNode AND() { return getToken(BParser.AND, 0); }
		public TerminalNode OR() { return getToken(BParser.OR, 0); }
		public TerminalNode QUEST() { return getToken(BParser.QUEST, 0); }
		public TerminalNode COLON() { return getToken(BParser.COLON, 0); }
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 24;
		enterRecursionRule(_localctx, 24, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(157);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << PLUS) | (1L << MINUS) | (1L << NOT))) != 0)) {
				{
				setState(156);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << PLUS) | (1L << MINUS) | (1L << NOT))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			setState(159);
			atom();
			}
			_ctx.stop = _input.LT(-1);
			setState(187);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(185);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
					case 1:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(161);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(162);
						_la = _input.LA(1);
						if ( !(_la==MUL || _la==DIV) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(163);
						expr(8);
						}
						break;
					case 2:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(164);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(165);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(166);
						expr(7);
						}
						break;
					case 3:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(167);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(168);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << GT) | (1L << GTE) | (1L << LT) | (1L << LTE))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(169);
						expr(6);
						}
						break;
					case 4:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(170);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(171);
						_la = _input.LA(1);
						if ( !(_la==EQ || _la==NEQ) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(172);
						expr(5);
						}
						break;
					case 5:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(173);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(174);
						match(AND);
						setState(175);
						expr(4);
						}
						break;
					case 6:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(176);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(177);
						match(OR);
						setState(178);
						expr(3);
						}
						break;
					case 7:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(179);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(180);
						match(QUEST);
						setState(181);
						expr(0);
						setState(182);
						match(COLON);
						setState(183);
						expr(2);
						}
						break;
					}
					} 
				}
				setState(189);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class AtomContext extends ParserRuleContext {
		public NameContext name() {
			return getRuleContext(NameContext.class,0);
		}
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public FuncinvocationContext funcinvocation() {
			return getRuleContext(FuncinvocationContext.class,0);
		}
		public AtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_atom; }
	}

	public final AtomContext atom() throws RecognitionException {
		AtomContext _localctx = new AtomContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_atom);
		try {
			setState(197);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(190);
				name();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(191);
				constant();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(192);
				match(T__0);
				setState(193);
				expression();
				setState(194);
				match(T__2);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(196);
				funcinvocation();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public NameContext name() {
			return getRuleContext(NameContext.class,0);
		}
		public TerminalNode ASSN() { return getToken(BParser.ASSN, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_expression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(202);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				{
				setState(199);
				name();
				setState(200);
				match(ASSN);
				}
				break;
			}
			setState(204);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FuncinvocationContext extends ParserRuleContext {
		public NameContext name() {
			return getRuleContext(NameContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public FuncinvocationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcinvocation; }
	}

	public final FuncinvocationContext funcinvocation() throws RecognitionException {
		FuncinvocationContext _localctx = new FuncinvocationContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_funcinvocation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(206);
			name();
			setState(207);
			match(T__0);
			setState(216);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << PLUS) | (1L << MINUS) | (1L << NOT) | (1L << BOOL) | (1L << NAME) | (1L << INT) | (1L << REAL) | (1L << STRING) | (1L << CHAR))) != 0)) {
				{
				setState(208);
				expr(0);
				setState(213);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__1) {
					{
					{
					setState(209);
					match(T__1);
					setState(210);
					expr(0);
					}
					}
					setState(215);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(218);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(BParser.INT, 0); }
		public TerminalNode REAL() { return getToken(BParser.REAL, 0); }
		public TerminalNode STRING() { return getToken(BParser.STRING, 0); }
		public TerminalNode BOOL() { return getToken(BParser.BOOL, 0); }
		public TerminalNode CHAR() { return getToken(BParser.CHAR, 0); }
		public ConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant; }
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_constant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(220);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BOOL) | (1L << INT) | (1L << REAL) | (1L << STRING) | (1L << CHAR))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NameContext extends ParserRuleContext {
		public TerminalNode NAME() { return getToken(BParser.NAME, 0); }
		public NameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_name; }
	}

	public final NameContext name() throws RecognitionException {
		NameContext _localctx = new NameContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(222);
			match(NAME);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DirectiveContext extends ParserRuleContext {
		public TerminalNode SHARP_DIRECTIVE() { return getToken(BParser.SHARP_DIRECTIVE, 0); }
		public DirectiveContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_directive; }
	}

	public final DirectiveContext directive() throws RecognitionException {
		DirectiveContext _localctx = new DirectiveContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_directive);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(224);
			match(SHARP_DIRECTIVE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 12:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 7);
		case 1:
			return precpred(_ctx, 6);
		case 2:
			return precpred(_ctx, 5);
		case 3:
			return precpred(_ctx, 4);
		case 4:
			return precpred(_ctx, 3);
		case 5:
			return precpred(_ctx, 2);
		case 6:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\'\u00e5\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\3\2\3\2\7\2+\n\2\f\2\16\2.\13\2\3\2\3\2\3\3\3\3\3"+
		"\3\5\3\65\n\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\7\4?\n\4\f\4\16\4B\13\4"+
		"\5\4D\n\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\5\5R\n\5\3\6"+
		"\3\6\3\6\3\6\5\6X\n\6\3\6\3\6\3\6\3\6\5\6^\n\6\7\6`\n\6\f\6\16\6c\13\6"+
		"\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\7\7m\n\7\f\7\16\7p\13\7\5\7r\n\7\3\7"+
		"\3\7\3\7\3\b\3\b\7\by\n\b\f\b\16\b|\13\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3"+
		"\t\3\t\5\t\u0087\n\t\3\n\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\f\3\f\3"+
		"\f\3\f\3\f\3\f\5\f\u0098\n\f\3\f\3\f\3\r\3\r\3\16\3\16\5\16\u00a0\n\16"+
		"\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16"+
		"\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\7\16\u00bc"+
		"\n\16\f\16\16\16\u00bf\13\16\3\17\3\17\3\17\3\17\3\17\3\17\3\17\5\17\u00c8"+
		"\n\17\3\20\3\20\3\20\5\20\u00cd\n\20\3\20\3\20\3\21\3\21\3\21\3\21\3\21"+
		"\7\21\u00d6\n\21\f\21\16\21\u00d9\13\21\5\21\u00db\n\21\3\21\3\21\3\22"+
		"\3\22\3\23\3\23\3\24\3\24\3\24\2\3\32\25\2\4\6\b\n\f\16\20\22\24\26\30"+
		"\32\34\36 \"$&\2\b\4\2\t\n\r\r\3\2\13\f\3\2\t\n\3\2\16\21\3\2\22\23\4"+
		"\2\36\36 #\2\u00f6\2,\3\2\2\2\4\64\3\2\2\2\6\66\3\2\2\2\bQ\3\2\2\2\nS"+
		"\3\2\2\2\ff\3\2\2\2\16v\3\2\2\2\20\177\3\2\2\2\22\u0088\3\2\2\2\24\u008e"+
		"\3\2\2\2\26\u0091\3\2\2\2\30\u009b\3\2\2\2\32\u009d\3\2\2\2\34\u00c7\3"+
		"\2\2\2\36\u00cc\3\2\2\2 \u00d0\3\2\2\2\"\u00de\3\2\2\2$\u00e0\3\2\2\2"+
		"&\u00e2\3\2\2\2(+\5&\24\2)+\5\4\3\2*(\3\2\2\2*)\3\2\2\2+.\3\2\2\2,*\3"+
		"\2\2\2,-\3\2\2\2-/\3\2\2\2.,\3\2\2\2/\60\7\2\2\3\60\3\3\2\2\2\61\65\5"+
		"\n\6\2\62\65\5\f\7\2\63\65\5\6\4\2\64\61\3\2\2\2\64\62\3\2\2\2\64\63\3"+
		"\2\2\2\65\5\3\2\2\2\66\67\7\b\2\2\678\5$\23\28C\7\3\2\29:\7\b\2\2:@\5"+
		"$\23\2;<\7\4\2\2<=\7\b\2\2=?\5$\23\2>;\3\2\2\2?B\3\2\2\2@>\3\2\2\2@A\3"+
		"\2\2\2AD\3\2\2\2B@\3\2\2\2C9\3\2\2\2CD\3\2\2\2DE\3\2\2\2EF\7\5\2\2FG\5"+
		"\b\5\2G\7\3\2\2\2HR\5\n\6\2IR\5\f\7\2JR\5\16\b\2KR\5\20\t\2LR\5\22\n\2"+
		"MR\5\24\13\2NR\5\26\f\2OR\5\30\r\2PR\5&\24\2QH\3\2\2\2QI\3\2\2\2QJ\3\2"+
		"\2\2QK\3\2\2\2QL\3\2\2\2QM\3\2\2\2QN\3\2\2\2QO\3\2\2\2QP\3\2\2\2R\t\3"+
		"\2\2\2ST\7\b\2\2TW\5$\23\2UV\7\35\2\2VX\5\"\22\2WU\3\2\2\2WX\3\2\2\2X"+
		"a\3\2\2\2YZ\7\4\2\2Z]\5$\23\2[\\\7\35\2\2\\^\5\"\22\2][\3\2\2\2]^\3\2"+
		"\2\2^`\3\2\2\2_Y\3\2\2\2`c\3\2\2\2a_\3\2\2\2ab\3\2\2\2bd\3\2\2\2ca\3\2"+
		"\2\2de\7\30\2\2e\13\3\2\2\2fg\7\b\2\2gh\5$\23\2hq\7\3\2\2in\7\b\2\2jk"+
		"\7\4\2\2km\7\b\2\2lj\3\2\2\2mp\3\2\2\2nl\3\2\2\2no\3\2\2\2or\3\2\2\2p"+
		"n\3\2\2\2qi\3\2\2\2qr\3\2\2\2rs\3\2\2\2st\7\5\2\2tu\7\30\2\2u\r\3\2\2"+
		"\2vz\7\6\2\2wy\5\b\5\2xw\3\2\2\2y|\3\2\2\2zx\3\2\2\2z{\3\2\2\2{}\3\2\2"+
		"\2|z\3\2\2\2}~\7\7\2\2~\17\3\2\2\2\177\u0080\7\31\2\2\u0080\u0081\7\3"+
		"\2\2\u0081\u0082\5\32\16\2\u0082\u0083\7\5\2\2\u0083\u0086\5\b\5\2\u0084"+
		"\u0085\7\32\2\2\u0085\u0087\5\b\5\2\u0086\u0084\3\2\2\2\u0086\u0087\3"+
		"\2\2\2\u0087\21\3\2\2\2\u0088\u0089\7\33\2\2\u0089\u008a\7\3\2\2\u008a"+
		"\u008b\5\32\16\2\u008b\u008c\7\5\2\2\u008c\u008d\5\b\5\2\u008d\23\3\2"+
		"\2\2\u008e\u008f\5\36\20\2\u008f\u0090\7\30\2\2\u0090\25\3\2\2\2\u0091"+
		"\u0097\7\34\2\2\u0092\u0098\5\36\20\2\u0093\u0094\7\3\2\2\u0094\u0095"+
		"\5\36\20\2\u0095\u0096\7\5\2\2\u0096\u0098\3\2\2\2\u0097\u0092\3\2\2\2"+
		"\u0097\u0093\3\2\2\2\u0097\u0098\3\2\2\2\u0098\u0099\3\2\2\2\u0099\u009a"+
		"\7\30\2\2\u009a\27\3\2\2\2\u009b\u009c\7\30\2\2\u009c\31\3\2\2\2\u009d"+
		"\u009f\b\16\1\2\u009e\u00a0\t\2\2\2\u009f\u009e\3\2\2\2\u009f\u00a0\3"+
		"\2\2\2\u00a0\u00a1\3\2\2\2\u00a1\u00a2\5\34\17\2\u00a2\u00bd\3\2\2\2\u00a3"+
		"\u00a4\f\t\2\2\u00a4\u00a5\t\3\2\2\u00a5\u00bc\5\32\16\n\u00a6\u00a7\f"+
		"\b\2\2\u00a7\u00a8\t\4\2\2\u00a8\u00bc\5\32\16\t\u00a9\u00aa\f\7\2\2\u00aa"+
		"\u00ab\t\5\2\2\u00ab\u00bc\5\32\16\b\u00ac\u00ad\f\6\2\2\u00ad\u00ae\t"+
		"\6\2\2\u00ae\u00bc\5\32\16\7\u00af\u00b0\f\5\2\2\u00b0\u00b1\7\24\2\2"+
		"\u00b1\u00bc\5\32\16\6\u00b2\u00b3\f\4\2\2\u00b3\u00b4\7\25\2\2\u00b4"+
		"\u00bc\5\32\16\5\u00b5\u00b6\f\3\2\2\u00b6\u00b7\7\26\2\2\u00b7\u00b8"+
		"\5\32\16\2\u00b8\u00b9\7\27\2\2\u00b9\u00ba\5\32\16\4\u00ba\u00bc\3\2"+
		"\2\2\u00bb\u00a3\3\2\2\2\u00bb\u00a6\3\2\2\2\u00bb\u00a9\3\2\2\2\u00bb"+
		"\u00ac\3\2\2\2\u00bb\u00af\3\2\2\2\u00bb\u00b2\3\2\2\2\u00bb\u00b5\3\2"+
		"\2\2\u00bc\u00bf\3\2\2\2\u00bd\u00bb\3\2\2\2\u00bd\u00be\3\2\2\2\u00be"+
		"\33\3\2\2\2\u00bf\u00bd\3\2\2\2\u00c0\u00c8\5$\23\2\u00c1\u00c8\5\"\22"+
		"\2\u00c2\u00c3\7\3\2\2\u00c3\u00c4\5\36\20\2\u00c4\u00c5\7\5\2\2\u00c5"+
		"\u00c8\3\2\2\2\u00c6\u00c8\5 \21\2\u00c7\u00c0\3\2\2\2\u00c7\u00c1\3\2"+
		"\2\2\u00c7\u00c2\3\2\2\2\u00c7\u00c6\3\2\2\2\u00c8\35\3\2\2\2\u00c9\u00ca"+
		"\5$\23\2\u00ca\u00cb\7\35\2\2\u00cb\u00cd\3\2\2\2\u00cc\u00c9\3\2\2\2"+
		"\u00cc\u00cd\3\2\2\2\u00cd\u00ce\3\2\2\2\u00ce\u00cf\5\32\16\2\u00cf\37"+
		"\3\2\2\2\u00d0\u00d1\5$\23\2\u00d1\u00da\7\3\2\2\u00d2\u00d7\5\32\16\2"+
		"\u00d3\u00d4\7\4\2\2\u00d4\u00d6\5\32\16\2\u00d5\u00d3\3\2\2\2\u00d6\u00d9"+
		"\3\2\2\2\u00d7\u00d5\3\2\2\2\u00d7\u00d8\3\2\2\2\u00d8\u00db\3\2\2\2\u00d9"+
		"\u00d7\3\2\2\2\u00da\u00d2\3\2\2\2\u00da\u00db\3\2\2\2\u00db\u00dc\3\2"+
		"\2\2\u00dc\u00dd\7\5\2\2\u00dd!\3\2\2\2\u00de\u00df\t\7\2\2\u00df#\3\2"+
		"\2\2\u00e0\u00e1\7\37\2\2\u00e1%\3\2\2\2\u00e2\u00e3\7$\2\2\u00e3\'\3"+
		"\2\2\2\27*,\64@CQW]anqz\u0086\u0097\u009f\u00bb\u00bd\u00c7\u00cc\u00d7"+
		"\u00da";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}