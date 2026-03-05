%{
    #include "parser.tab.h"
    #include "ast.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}

DIGIT [0-9]
ID [a-zA-Z_][a-zA-Z0-9_]*
CHAR_LIT \'(\\.|[^\\'])\'
STRING_LIT \"(\\\\.|[^\\\"])*\"
HEX_NUM 0[xX][0-9a-fA-F]+
REAL_NUM ([0-9]*[.])?[0-9]+([eE][-+]?[0-9]+)?
INT_NUM [0-9]+

%%
"#->"([^<]|\n)*"<-#"    { /* ignore comment */ }
    
"def"        {  return DEF; }
"begin"      {  return T_BEGIN; }
"end"        { return T_END; }
"if"         {  return IF; }
"elif"       {  return ELIF; }
"else"       {  return ELSE; }
"while"      {  return WHILE; }
"for"        { return FOR; }
"do"         { return DO; }
"true"|"TRUE"  { yylval.sval = strdup(yytext); return TRUE; }
"false"|"FALSE" { yylval.sval = strdup(yytext); return FALSE; }

"and"        { return AND; }
"or"         {return OR; }
"not"        {  return NOT; }
"call"       {  return CALL; }
"var"        { return VAR; }
"null"       {  return NULLPTR; }
"return"     { return RETURN; }
"returns"    {  return RETURNS; }
"type"         {return TYPE;}

"int"[ \t]*"*"       { yylval.sval = strdup("int*"); return TYPE_INT_PTR; }
"char"[ \t]*"*"      { yylval.sval = strdup("char*"); return TYPE_CHAR_PTR; }
"real"[ \t]*"*"      { yylval.sval = strdup("real*"); return TYPE_REAL_PTR; }
"int"        { yylval.sval = strdup(yytext); return TYPE_INT; }
"real"       {  yylval.sval = strdup(yytext); return TYPE_REAL; }
"char"       { yylval.sval = strdup(yytext); return TYPE_CHAR; }
"bool"       {  yylval.sval = strdup(yytext); return TYPE_BOOL; }
"string"     { yylval.sval = strdup(yytext); return TYPE_STRING; }

"=="         { return EQ; }
"!="         { return NE; }
">="         { return GE; }
"<="         { return LE; }
">"          { return GT; }
"<"          { return LT; }
"="          { return ASSIGN; }
"+"          { return PLUS; }
"-"          { return MINUS; }
"*"          { return MULT; }
"/"          { return DIV; }
"&"          { return ADDRESS; }

":"          {return COLON; }
";"          {  return SEMICOLON; }
","          { return COMMA; }
"("          {  return LPAREN; }
")"          { return RPAREN; }
"["          { return LBRACK; }
"]"          { return RBRACK; }
"|"          { return BAR; }

{CHAR_LIT}       {  yylval.sval = strdup(yytext); return CHAR_LITERAL; }
{STRING_LIT}     { yylval.sval = strdup(yytext); return STRING_LITERAL; }
{HEX_NUM}        { yylval.sval = strdup(yytext); return NUM; }
{REAL_NUM}       { yylval.sval = strdup(yytext); return NUM; }
{INT_NUM}        { yylval.sval = strdup(yytext); return NUM; }

[ \t\r\n]+       { /* דילוג על רווחים */ }

{ID}             { yylval.sval = strdup(yytext); return ID; }

.                { printf("[UNKNOWN:%s]\n", yytext); }

%%

int yywrap() {
    return 1;
}

