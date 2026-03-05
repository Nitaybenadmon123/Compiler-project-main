#ifndef YY_parse_h_included
#define YY_parse_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 24 "parser.y"
typedef union {
    struct ast_node* ast ;
    char* sval;
} yy_parse_stype;
#define YY_parse_STYPE yy_parse_stype
#ifndef YY_USE_CLASS
#define YYSTYPE yy_parse_stype
#endif

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_parse_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_parse_COMPATIBILITY 1
 #else
  #define  YY_parse_COMPATIBILITY 0
 #endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_parse_LTYPE
   #define YY_parse_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_parse_STYPE
   #define YY_parse_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_parse_DEBUG
   #define  YY_parse_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_parse_USE_GOTO
  #define YY_parse_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
 #define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_parse_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_parse_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_parse_DEBUG */
#endif

#ifndef YY_parse_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_parse_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
 #ifndef YY_parse_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_parse_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_parse_STYPE
 #define YY_parse_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
 #define YY_parse_PARSE yyparse
#endif

#ifndef YY_parse_LEX
 #define YY_parse_LEX yylex
#endif

#ifndef YY_parse_LVAL
 #define YY_parse_LVAL yylval
#endif

#ifndef YY_parse_LLOC
 #define YY_parse_LLOC yylloc
#endif

#ifndef YY_parse_CHAR
 #define YY_parse_CHAR yychar
#endif

#ifndef YY_parse_NERRS
 #define YY_parse_NERRS yynerrs
#endif

#ifndef YY_parse_DEBUG_FLAG
 #define YY_parse_DEBUG_FLAG yydebug
#endif

#ifndef YY_parse_ERROR
 #define YY_parse_ERROR yyerror
#endif

#ifndef YY_parse_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_parse_PARSE_PARAM
    #ifndef YY_parse_PARSE_PARAM_DEF
     #define YY_parse_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_parse_PARSE_PARAM
  #define YY_parse_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_parse_PURE
  #ifndef yylval
   extern YY_parse_STYPE YY_parse_LVAL;
  #else
   #if yylval != YY_parse_LVAL
    extern YY_parse_STYPE YY_parse_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	OR	258
#define	AND	259
#define	PLUS	260
#define	MINUS	261
#define	MULT	262
#define	DIV	263
#define	EQ	264
#define	NE	265
#define	GT	266
#define	GE	267
#define	LT	268
#define	LE	269
#define	NOT	270
#define	ID	271
#define	CHAR_LITERAL	272
#define	STRING_LITERAL	273
#define	NUM	274
#define	TRUE	275
#define	FALSE	276
#define	TYPE_INT	277
#define	TYPE_CHAR	278
#define	TYPE_REAL	279
#define	TYPE_BOOL	280
#define	TYPE_STRING	281
#define	TYPE_INT_PTR	282
#define	TYPE_CHAR_PTR	283
#define	TYPE_REAL_PTR	284
#define	DEF	285
#define	T_BEGIN	286
#define	T_END	287
#define	IF	288
#define	ELSE	289
#define	ELIF	290
#define	WHILE	291
#define	FOR	292
#define	DO	293
#define	CALL	294
#define	RETURN	295
#define	RETURNS	296
#define	VAR	297
#define	NULLPTR	298
#define	ASSIGN	299
#define	ADDRESS	300
#define	COLON	301
#define	SEMICOLON	302
#define	COMMA	303
#define	LPAREN	304
#define	RPAREN	305
#define	LBRACK	306
#define	RBRACK	307
#define	BAR	308
#define	TYPE	309


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_parse_CLASS
  #define YY_parse_CLASS parse
 #endif

 #ifndef YY_parse_INHERIT
  #define YY_parse_INHERIT
 #endif

 #ifndef YY_parse_MEMBERS
  #define YY_parse_MEMBERS 
 #endif

 #ifndef YY_parse_LEX_BODY
  #define YY_parse_LEX_BODY  
 #endif

 #ifndef YY_parse_ERROR_BODY
  #define YY_parse_ERROR_BODY  
 #endif

 #ifndef YY_parse_CONSTRUCTOR_PARAM
  #define YY_parse_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_parse_USE_CONST_TOKEN
  #define YY_parse_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_parse_USE_CONST_TOKEN != 0
  #ifndef YY_parse_ENUM_TOKEN
   #define YY_parse_ENUM_TOKEN yy_parse_enum_token
  #endif
 #endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
 #if YY_parse_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int OR;
static const int AND;
static const int PLUS;
static const int MINUS;
static const int MULT;
static const int DIV;
static const int EQ;
static const int NE;
static const int GT;
static const int GE;
static const int LT;
static const int LE;
static const int NOT;
static const int ID;
static const int CHAR_LITERAL;
static const int STRING_LITERAL;
static const int NUM;
static const int TRUE;
static const int FALSE;
static const int TYPE_INT;
static const int TYPE_CHAR;
static const int TYPE_REAL;
static const int TYPE_BOOL;
static const int TYPE_STRING;
static const int TYPE_INT_PTR;
static const int TYPE_CHAR_PTR;
static const int TYPE_REAL_PTR;
static const int DEF;
static const int T_BEGIN;
static const int T_END;
static const int IF;
static const int ELSE;
static const int ELIF;
static const int WHILE;
static const int FOR;
static const int DO;
static const int CALL;
static const int RETURN;
static const int RETURNS;
static const int VAR;
static const int NULLPTR;
static const int ASSIGN;
static const int ADDRESS;
static const int COLON;
static const int SEMICOLON;
static const int COMMA;
static const int LPAREN;
static const int RPAREN;
static const int LBRACK;
static const int RBRACK;
static const int BAR;
static const int TYPE;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,OR=258
	,AND=259
	,PLUS=260
	,MINUS=261
	,MULT=262
	,DIV=263
	,EQ=264
	,NE=265
	,GT=266
	,GE=267
	,LT=268
	,LE=269
	,NOT=270
	,ID=271
	,CHAR_LITERAL=272
	,STRING_LITERAL=273
	,NUM=274
	,TRUE=275
	,FALSE=276
	,TYPE_INT=277
	,TYPE_CHAR=278
	,TYPE_REAL=279
	,TYPE_BOOL=280
	,TYPE_STRING=281
	,TYPE_INT_PTR=282
	,TYPE_CHAR_PTR=283
	,TYPE_REAL_PTR=284
	,DEF=285
	,T_BEGIN=286
	,T_END=287
	,IF=288
	,ELSE=289
	,ELIF=290
	,WHILE=291
	,FOR=292
	,DO=293
	,CALL=294
	,RETURN=295
	,RETURNS=296
	,VAR=297
	,NULLPTR=298
	,ASSIGN=299
	,ADDRESS=300
	,COLON=301
	,SEMICOLON=302
	,COMMA=303
	,LPAREN=304
	,RPAREN=305
	,LBRACK=306
	,RBRACK=307
	,BAR=308
	,TYPE=309


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_parse_PARSE(YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
 #ifdef YY_parse_PURE
  #ifdef YY_parse_LSP_NEEDED
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
  #else
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
  #endif
 #else
  virtual int YY_parse_LEX() YY_parse_LEX_BODY;
  YY_parse_STYPE YY_parse_LVAL;
  #ifdef YY_parse_LSP_NEEDED
   YY_parse_LTYPE YY_parse_LLOC;
  #endif
  int YY_parse_NERRS;
  int YY_parse_CHAR;
 #endif
 #if YY_parse_DEBUG != 0
  public:
   int YY_parse_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#endif


#if YY_parse_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_parse_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_parse_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_parse_DEBUG 
   #define YYDEBUG YY_parse_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
