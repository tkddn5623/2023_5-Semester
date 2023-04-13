// Generated from java-escape by ANTLR 4.11.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ExprParser}.
 */
public interface ExprListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ExprParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(ExprParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(ExprParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(ExprParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(ExprParser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#assn}.
	 * @param ctx the parse tree
	 */
	void enterAssn(ExprParser.AssnContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#assn}.
	 * @param ctx the parse tree
	 */
	void exitAssn(ExprParser.AssnContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(ExprParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(ExprParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#term}.
	 * @param ctx the parse tree
	 */
	void enterTerm(ExprParser.TermContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#term}.
	 * @param ctx the parse tree
	 */
	void exitTerm(ExprParser.TermContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactor(ExprParser.FactorContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactor(ExprParser.FactorContext ctx);
}