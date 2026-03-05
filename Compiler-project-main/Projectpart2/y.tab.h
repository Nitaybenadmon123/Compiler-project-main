/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    OR = 258,                      /* OR  */
    AND = 259,                     /* AND  */
    PLUS = 260,                    /* PLUS  */
    MINUS = 261,                   /* MINUS  */
    MULT = 262,                    /* MULT  */
    DIV = 263,                     /* DIV  */
    EQ = 264,                      /* EQ  */
    NE = 265,                      /* NE  */
    GT = 266,                      /* GT  */
    GE = 267,                      /* GE  */
    LT = 268,                      /* LT  */
    LE = 269,                      /* LE  */
    NOT = 270,                     /* NOT  */
    ID = 271,                      /* ID  */
    CHAR_LITERAL = 272,            /* CHAR_LITERAL  */
    STRING_LITERAL = 273,          /* STRING_LITERAL  */
    NUM = 274,                     /* NUM  */
    TRUE = 275,                    /* TRUE  */
    FALSE = 276,                   /* FALSE  */
    TYPE_INT = 277,                /* TYPE_INT  */
    TYPE_CHAR = 278,               /* TYPE_CHAR  */
    TYPE_REAL = 279,               /* TYPE_REAL  */
    TYPE_BOOL = 280,               /* TYPE_BOOL  */
    TYPE_STRING = 281,             /* TYPE_STRING  */
    TYPE_INT_PTR = 282,            /* TYPE_INT_PTR  */
    TYPE_CHAR_PTR = 283,           /* TYPE_CHAR_PTR  */
    TYPE_REAL_PTR = 284,           /* TYPE_REAL_PTR  */
    DEF = 285,                     /* DEF  */
    T_BEGIN = 286,                 /* T_BEGIN  */
    T_END = 287,                   /* T_END  */
    IF = 288,                      /* IF  */
    ELSE = 289,                    /* ELSE  */
    ELIF = 290,                    /* ELIF  */
    WHILE = 291,                   /* WHILE  */
    FOR = 292,                     /* FOR  */
    DO = 293,                      /* DO  */
    CALL = 294,                    /* CALL  */
    RETURN = 295,                  /* RETURN  */
    RETURNS = 296,                 /* RETURNS  */
    VAR = 297,                     /* VAR  */
    NULLPTR = 298,                 /* NULLPTR  */
    ASSIGN = 299,                  /* ASSIGN  */
    ADDRESS = 300,                 /* ADDRESS  */
    COLON = 301,                   /* COLON  */
    SEMICOLON = 302,               /* SEMICOLON  */
    COMMA = 303,                   /* COMMA  */
    LPAREN = 304,                  /* LPAREN  */
    RPAREN = 305,                  /* RPAREN  */
    LBRACK = 306,                  /* LBRACK  */
    RBRACK = 307,                  /* RBRACK  */
    BAR = 308,                     /* BAR  */
    TYPE = 309                     /* TYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define OR 258
#define AND 259
#define PLUS 260
#define MINUS 261
#define MULT 262
#define DIV 263
#define EQ 264
#define NE 265
#define GT 266
#define GE 267
#define LT 268
#define LE 269
#define NOT 270
#define ID 271
#define CHAR_LITERAL 272
#define STRING_LITERAL 273
#define NUM 274
#define TRUE 275
#define FALSE 276
#define TYPE_INT 277
#define TYPE_CHAR 278
#define TYPE_REAL 279
#define TYPE_BOOL 280
#define TYPE_STRING 281
#define TYPE_INT_PTR 282
#define TYPE_CHAR_PTR 283
#define TYPE_REAL_PTR 284
#define DEF 285
#define T_BEGIN 286
#define T_END 287
#define IF 288
#define ELSE 289
#define ELIF 290
#define WHILE 291
#define FOR 292
#define DO 293
#define CALL 294
#define RETURN 295
#define RETURNS 296
#define VAR 297
#define NULLPTR 298
#define ASSIGN 299
#define ADDRESS 300
#define COLON 301
#define SEMICOLON 302
#define COMMA 303
#define LPAREN 304
#define RPAREN 305
#define LBRACK 306
#define RBRACK 307
#define BAR 308
#define TYPE 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

    struct ast_node* ast ;
    char* sval;

#line 180 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
