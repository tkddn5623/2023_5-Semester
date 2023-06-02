/* Expr.g4 */
grammar Expr;

<<<<<<< Updated upstream
// parser rules prog: (stmt NEWLINE*)*;
prog: (stmt terminator NEWLINE*)*;

terminator: (';')+;

stmt: assn | expr;

assn: ID OPERATOR1 stmt;

expr: expr OPERATOR2 term | term;

term: term OPERATOR3 factor | factor;

factor: OPERATOR2 factor | '(' stmt ')' | NUMBER | ID;

// lexer rules
OPERATOR1: '=';
OPERATOR2: ('+' | '-');
OPERATOR3: ('*' | '/');
NUMBER: INT | FLOAT;
ID: LETTER (LETTER | DIGIT)*;
INT: (DIGIT)+;
FLOAT: ((DIGIT)* ('.' DIGIT | DIGIT '.') (DIGIT)*);
DIGIT: [0-9];
LETTER: [a-zA-Z_];
WS: [ \t\r\n]+ -> skip;
NEWLINE: [\n\r];
=======
// parser rules
prog: (expr NEWLINE*)*;

expr: '(' expr ')'
    | expr ('*' | '/') expr
	| expr ('+' | '-') expr
	| INT;

// lexer rules
NEWLINE: [\n\r];
INT: [0-9]+;
WS: [ \t\r\n]+ -> skip;

>>>>>>> Stashed changes
