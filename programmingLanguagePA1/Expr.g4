/* Expr.g4 */
grammar Expr;

// parser rules
prog: (stmt NEWLINE*)*;

stmt: ID '=' stmt
    | expr;

expr: expr ('+' | '-') term
    | term;

term: term ('*' | '/' | '%') factor
    | factor;

factor: '(' stmt ')'
      | NUMBER
      | ID;


// lexer rules
NUMBER:   INT | FLOAT;
ID:       LETTER (LETTER | DIGIT)*;
INT:      ('-')?(DIGIT)+;
FLOAT:    ('-')?((DIGIT)* ('.' DIGIT | DIGIT '.') (DIGIT)*);
DIGIT:    [0-9];
LETTER:   [a-zA-Z_];
WS:       [ \t\r\n]+ -> skip;
NEWLINE:  [\n\r];
