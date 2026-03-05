/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include "ast.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.h"

    AST* make_node(char* name, int count, ...);
    void print_ast(AST* node, int indent);
    void yyerror(const char* s);
    void print_symbol_tables();
    int yylex();
    int yydebug = 1;
    int inside_main = 0;
    int scope_parent[100] = {-1};  
    int function_scopes[100] = {0}; 
    int current_function = 0; 
    int main_defined = 0;  
    extern int preserve_symbol_tables;
    char current_function_name[256] = "";
    int current_param_index = 0;

#line 94 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 260 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OR = 3,                         /* OR  */
  YYSYMBOL_AND = 4,                        /* AND  */
  YYSYMBOL_PLUS = 5,                       /* PLUS  */
  YYSYMBOL_MINUS = 6,                      /* MINUS  */
  YYSYMBOL_MULT = 7,                       /* MULT  */
  YYSYMBOL_DIV = 8,                        /* DIV  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_NE = 10,                        /* NE  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_GE = 12,                        /* GE  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_ID = 16,                        /* ID  */
  YYSYMBOL_CHAR_LITERAL = 17,              /* CHAR_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 18,            /* STRING_LITERAL  */
  YYSYMBOL_NUM = 19,                       /* NUM  */
  YYSYMBOL_TRUE = 20,                      /* TRUE  */
  YYSYMBOL_FALSE = 21,                     /* FALSE  */
  YYSYMBOL_TYPE_INT = 22,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_CHAR = 23,                 /* TYPE_CHAR  */
  YYSYMBOL_TYPE_REAL = 24,                 /* TYPE_REAL  */
  YYSYMBOL_TYPE_BOOL = 25,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_STRING = 26,               /* TYPE_STRING  */
  YYSYMBOL_TYPE_INT_PTR = 27,              /* TYPE_INT_PTR  */
  YYSYMBOL_TYPE_CHAR_PTR = 28,             /* TYPE_CHAR_PTR  */
  YYSYMBOL_TYPE_REAL_PTR = 29,             /* TYPE_REAL_PTR  */
  YYSYMBOL_DEF = 30,                       /* DEF  */
  YYSYMBOL_T_BEGIN = 31,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 32,                     /* T_END  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_ELSE = 34,                      /* ELSE  */
  YYSYMBOL_ELIF = 35,                      /* ELIF  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_DO = 38,                        /* DO  */
  YYSYMBOL_CALL = 39,                      /* CALL  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_RETURNS = 41,                   /* RETURNS  */
  YYSYMBOL_VAR = 42,                       /* VAR  */
  YYSYMBOL_NULLPTR = 43,                   /* NULLPTR  */
  YYSYMBOL_ASSIGN = 44,                    /* ASSIGN  */
  YYSYMBOL_ADDRESS = 45,                   /* ADDRESS  */
  YYSYMBOL_COLON = 46,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 47,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 48,                     /* COMMA  */
  YYSYMBOL_LPAREN = 49,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 50,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 51,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 52,                    /* RBRACK  */
  YYSYMBOL_BAR = 53,                       /* BAR  */
  YYSYMBOL_TYPE = 54,                      /* TYPE  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_program = 56,                   /* program  */
  YYSYMBOL_func_list = 57,                 /* func_list  */
  YYSYMBOL_function = 58,                  /* function  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_61_3 = 61,                      /* $@3  */
  YYSYMBOL_62_4 = 62,                      /* $@4  */
  YYSYMBOL_par_list = 63,                  /* par_list  */
  YYSYMBOL_param_list_item_list = 64,      /* param_list_item_list  */
  YYSYMBOL_par_list_item = 65,             /* par_list_item  */
  YYSYMBOL_type = 66,                      /* type  */
  YYSYMBOL_stmt_list = 67,                 /* stmt_list  */
  YYSYMBOL_stmt = 68,                      /* stmt  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_id_list = 70,                   /* id_list  */
  YYSYMBOL_var_stmt = 71,                  /* var_stmt  */
  YYSYMBOL_type_decls = 72,                /* type_decls  */
  YYSYMBOL_type_decl = 73,                 /* type_decl  */
  YYSYMBOL_return_stmt = 74,               /* return_stmt  */
  YYSYMBOL_if_stmt = 75,                   /* if_stmt  */
  YYSYMBOL_elif_list = 76,                 /* elif_list  */
  YYSYMBOL_while_stmt = 77,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 78,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 79,                  /* for_stmt  */
  YYSYMBOL_update_expr = 80,               /* update_expr  */
  YYSYMBOL_call_args = 81,                 /* call_args  */
  YYSYMBOL_call_list = 82,                 /* call_list  */
  YYSYMBOL_assignment_call = 83,           /* assignment_call  */
  YYSYMBOL_void_call = 84,                 /* void_call  */
  YYSYMBOL_block = 85,                     /* block  */
  YYSYMBOL_86_5 = 86,                      /* $@5  */
  YYSYMBOL_87_6 = 87,                      /* $@6  */
  YYSYMBOL_expr = 88                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   873

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  311

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    56,    62,    63,    66,    66,   107,   107,
     142,   142,   177,   177,   209,   210,   214,   217,   224,   237,
     238,   239,   240,   241,   242,   243,   244,   248,   252,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   274,   301,   325,   354,   361,   362,   367,   370,   375,
     378,   383,   387,   391,   395,   399,   403,   407,   411,   415,
     419,   423,   427,   437,   441,   445,   450,   454,   458,   462,
     466,   470,   474,   478,   491,   502,   512,   517,   522,   527,
     532,   540,   545,   552,   557,   562,   569,   574,   579,   586,
     591,   598,   601,   606,   607,   611,   615,   623,   652,   679,
     679,   686,   686,   696,   707,   718,   729,   740,   751,   762,
     773,   784,   795,   806,   808,   825,   832,   833,   842,   843,
     844,   845,   846,   847,   848,   849,   850,   861,   889,   890,
     891,   893,   925,   948
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OR", "AND", "PLUS",
  "MINUS", "MULT", "DIV", "EQ", "NE", "GT", "GE", "LT", "LE", "NOT", "ID",
  "CHAR_LITERAL", "STRING_LITERAL", "NUM", "TRUE", "FALSE", "TYPE_INT",
  "TYPE_CHAR", "TYPE_REAL", "TYPE_BOOL", "TYPE_STRING", "TYPE_INT_PTR",
  "TYPE_CHAR_PTR", "TYPE_REAL_PTR", "DEF", "T_BEGIN", "T_END", "IF",
  "ELSE", "ELIF", "WHILE", "FOR", "DO", "CALL", "RETURN", "RETURNS", "VAR",
  "NULLPTR", "ASSIGN", "ADDRESS", "COLON", "SEMICOLON", "COMMA", "LPAREN",
  "RPAREN", "LBRACK", "RBRACK", "BAR", "TYPE", "$accept", "program",
  "func_list", "function", "$@1", "$@2", "$@3", "$@4", "par_list",
  "param_list_item_list", "par_list_item", "type", "stmt_list", "stmt",
  "assignment", "id_list", "var_stmt", "type_decls", "type_decl",
  "return_stmt", "if_stmt", "elif_list", "while_stmt", "do_while_stmt",
  "for_stmt", "update_expr", "call_args", "call_list", "assignment_call",
  "void_call", "block", "$@5", "$@6", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-82)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,   -82,     2,    42,    -7,   -82,    34,   -82,   -82,   -10,
     238,     5,    43,    40,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,    67,    62,    70,   107,   109,   238,   361,
      79,   -82,   -82,   -82,   -82,   -82,   467,   803,   -27,   -82,
     -82,   -82,   -82,   -82,   -82,   510,   411,    83,    89,   125,
     460,    94,   -82,   155,   510,   510,    -7,   361,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   159,   -82,   -82,
     -82,    23,   238,   361,   361,   510,    14,   199,   227,   182,
      15,   -82,   517,   510,   510,   361,   212,   771,   510,   783,
      -2,   361,   196,   -82,   609,   247,    91,   -82,    -5,   156,
     176,   -82,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   -82,   361,   361,   510,   510,
     197,   240,   261,   624,   242,   226,   318,   -82,   361,   636,
     361,   277,    38,   278,   510,   404,   259,   260,   510,   -82,
     274,   280,   281,   283,   284,   285,   286,   294,   -82,   -82,
     -82,   510,   510,   -82,   -82,    23,   213,   305,   376,   376,
     182,   182,   -82,   -82,   -82,   -82,   -82,   -82,   361,   654,
     245,   510,   275,   -82,   -82,   279,   -82,   307,    26,   -82,
     -82,   -82,   298,   510,   510,   299,   681,   411,   510,   510,
     296,   328,   329,   336,   337,   343,   346,   350,   354,   699,
     276,   361,   -82,   -82,   321,   510,   510,   326,   327,   510,
      56,   295,   560,   579,   711,   726,   348,    50,    57,    97,
      90,   100,   104,   110,   126,    68,     4,   349,   129,   355,
     163,   358,   165,   -82,   -82,   -82,   324,   756,   361,   344,
     801,   347,   510,   279,    37,   359,    23,   -82,   -82,   -82,
     -82,   394,   -82,   -82,   400,   416,   -82,   -82,   398,   -82,
     -82,   221,   -82,   -82,   418,   -82,   419,   420,   -82,   -82,
     -82,   -82,   -82,   -82,   401,   -82,   -82,   -82,   344,   344,
     827,   510,   399,   405,   -82,   412,   414,   421,   422,   425,
     406,   413,   -82,   -82,   -82,   344,    23,   361,   -82,   -82,
     -82,   -82,   -82,   -82,   426,   442,   -82,   -82,   -82,   -82,
     -82
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     2,     5,     0,     1,     4,     0,
       0,     0,     0,    14,    17,    19,    20,    21,    22,    23,
      24,    25,    26,     0,    12,     0,     0,     0,     0,    94,
      10,    16,    18,     8,   124,   123,     0,   125,   117,   118,
     119,   116,   121,   122,    99,     0,     0,     0,     0,     0,
       0,     0,   120,     0,     0,     0,    40,    13,    28,    29,
      37,    31,    30,    33,    36,    34,    35,    93,    39,    38,
      32,    96,     0,    94,    94,     0,   117,     0,     0,   131,
     117,   130,     0,    94,     0,    94,     0,     0,     0,     0,
       0,     0,     0,    75,     0,     0,    94,    50,   132,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,    11,     9,     0,     0,
       0,   132,     0,     0,     0,     0,     0,   102,    94,     0,
      94,     0,     0,     0,     0,     0,    28,    32,    94,    74,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
      32,     0,     0,   113,   115,    95,   129,   128,   103,   104,
     105,   106,   107,   108,   110,   112,   109,   111,    94,     0,
       0,    94,     0,    41,   127,   114,   100,    78,    32,    83,
      85,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,    43,   114,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    44,   133,   126,     0,     0,    94,     0,
       0,     0,     0,     0,   117,     0,    92,    86,    87,    88,
      98,     0,    51,    66,     0,     0,    53,    68,     0,    55,
      69,     0,    52,    67,     0,    54,     0,     0,    63,    70,
      64,    71,    65,    72,   126,    42,    79,    76,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,    97,    81,    80,     0,    91,    94,    57,    58,
      56,    60,    61,    59,     0,     0,    82,    90,    32,    62,
      73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   451,    -3,   -82,   -82,   -82,   -82,   -82,   -82,
     440,   -15,   -66,   -29,   402,     7,   -82,   -82,   395,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -79,   -82,   -82,   -82,
     -81,   -82,   -82,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    56,     5,   168,    74,    73,    29,    12,    13,
      14,    23,    57,   101,    59,   218,    60,    96,    97,    61,
      62,   210,    63,    64,    65,   245,    66,    67,    68,    69,
      70,    85,    86,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,     8,    79,    81,   124,   131,    10,   116,   117,     1,
     137,    87,    89,    33,   132,   150,    94,    82,     6,   126,
      99,   100,    83,     2,    84,   135,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     2,   151,
      11,    79,     7,   133,    58,    58,   152,   178,   123,   181,
     125,    24,   254,     8,   129,   267,    58,   115,   118,   190,
     208,   209,   136,    83,    83,   119,   119,   148,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   281,   183,     9,   169,   170,    83,    26,   119,   184,
     241,   242,   204,    25,    34,    35,   251,   252,    36,   177,
     186,   180,   201,    28,   253,   254,    37,    38,    39,    40,
      41,    42,    43,    27,   264,   265,    30,   199,   200,   266,
      72,     2,    44,    10,    45,    32,   236,    46,    47,    48,
      49,    50,    90,    51,    52,    91,    53,   257,   254,    58,
      54,    92,    55,   255,   256,    95,   258,   259,    95,   123,
     211,   260,   254,   213,   214,   215,   261,   262,   277,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    98,   237,   263,   254,   240,   269,   254,   246,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   109,   110,   111,   112,   113,   114,   293,   294,   220,
     222,   224,   226,   228,   230,   232,   153,   102,   280,   276,
     271,   254,   273,   254,   306,   120,   308,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   154,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   287,   288,   121,   127,   138,   171,   296,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      15,    16,    17,    18,    19,    20,    21,    22,   307,   140,
     141,   142,   143,   144,   145,   146,   147,   172,   175,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   152,   174,   182,   185,   188,   189,   203,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     191,    34,    35,   206,   205,    36,   192,   193,   234,   194,
     195,   196,   197,    37,    38,    39,    40,    41,    42,    43,
     198,   207,   118,   151,   217,   219,   216,   243,     2,    44,
     176,    45,   221,   223,    46,    47,    48,    49,    50,   225,
      51,    52,   227,    53,    34,    35,   229,    54,    36,    55,
     231,   235,   238,   239,   274,    44,    37,    38,    39,    40,
      41,    42,    43,   107,   108,   109,   110,   111,   112,   113,
     114,     2,    44,   279,    45,   250,   268,    46,    47,    48,
      49,    50,   270,    51,    52,   272,    53,    34,    35,   282,
      54,    36,    55,   283,    34,    35,   284,   286,    75,    37,
      38,    39,    40,    41,    42,    43,    37,    80,    39,    40,
      41,    42,    43,   285,     2,    44,   289,    45,   290,   291,
     187,    47,    48,    49,    50,   297,    51,    52,   292,    53,
      77,     4,   298,    54,    52,    55,    78,    88,   304,   299,
      54,   300,    55,    34,    35,   305,    31,    75,   301,   302,
      34,    35,   303,   309,    75,    37,    80,    39,    40,    41,
      42,    43,    37,    76,    39,    40,    41,    42,    43,   310,
       0,   149,   134,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,    52,     0,    78,    77,    93,     0,    54,
      52,    55,    78,    34,    35,     0,    54,    75,    55,     0,
      34,    35,     0,     0,    75,    37,    80,    39,    40,    41,
      42,    43,    37,    80,    39,    40,    41,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,    52,     0,    78,   122,     0,     0,    54,
      52,    55,    78,    34,    35,     0,    54,    75,    55,     0,
       0,     0,     0,     0,     0,    37,   244,    39,    40,    41,
      42,    43,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,    77,
       0,     0,     0,    52,     0,    78,     0,     0,     0,    54,
       0,    55,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,   130,   247,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,   139,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     0,     0,     0,     0,
       0,   202,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     0,     0,   212,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,   249,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     0,     0,
       0,     0,     0,   275,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     0,   128,    37,    80,
      39,    40,    41,    42,    43,     0,     0,     0,     0,   130,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    77,     0,     0,     0,    52,   278,    78,     0,
       0,     0,    54,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295
};

static const yytype_int16 yycheck[] =
{
      29,     4,    36,    37,    83,     7,    16,    73,    74,     1,
      91,    45,    46,    28,    16,    96,    50,    44,    16,    85,
      54,    55,    49,    30,    51,    91,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    30,    44,
      50,    75,     0,    45,    73,    74,    51,   128,    82,   130,
      84,    46,    48,    56,    88,    51,    85,    72,    44,   138,
      34,    35,    91,    49,    49,    51,    51,    96,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,    44,    49,   118,   119,    49,    47,    51,    51,
      34,    35,   171,    50,     3,     4,    46,    47,     7,   128,
     134,   130,   168,    41,    47,    48,    15,    16,    17,    18,
      19,    20,    21,    46,    46,    47,    46,   151,   152,    51,
      41,    30,    31,    16,    33,    16,   205,    36,    37,    38,
      39,    40,    49,    42,    43,    46,    45,    47,    48,   168,
      49,    16,    51,    46,    47,    54,    46,    47,    54,   183,
     184,    47,    48,   187,   188,   189,    46,    47,   239,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    16,   206,    47,    48,   209,    47,    48,   212,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     9,    10,    11,    12,    13,    14,   278,   279,   192,
     193,   194,   195,   196,   197,   198,    50,    48,   242,   238,
      47,    48,    47,    48,   295,    16,   297,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    52,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    20,    21,    16,    32,    49,    49,   281,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      22,    23,    24,    25,    26,    27,    28,    29,   297,    22,
      23,    24,    25,    26,    27,    28,    29,    16,    52,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    51,    50,    16,    16,    36,    36,    52,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      46,     3,     4,    44,    49,     7,    46,    46,    52,    46,
      46,    46,    46,    15,    16,    17,    18,    19,    20,    21,
      46,    34,    44,    44,    16,    16,    50,    52,    30,    31,
      32,    33,    16,    16,    36,    37,    38,    39,    40,    16,
      42,    43,    16,    45,     3,     4,    16,    49,     7,    51,
      16,    50,    46,    46,    50,    31,    15,    16,    17,    18,
      19,    20,    21,     7,     8,     9,    10,    11,    12,    13,
      14,    30,    31,    46,    33,    47,    47,    36,    37,    38,
      39,    40,    47,    42,    43,    47,    45,     3,     4,    50,
      49,     7,    51,    19,     3,     4,    16,    19,     7,    15,
      16,    17,    18,    19,    20,    21,    15,    16,    17,    18,
      19,    20,    21,    17,    30,    31,    18,    33,    19,    19,
      36,    37,    38,    39,    40,    46,    42,    43,    47,    45,
      39,     0,    47,    49,    43,    51,    45,    46,    52,    47,
      49,    47,    51,     3,     4,    52,    26,     7,    47,    47,
       3,     4,    47,    47,     7,    15,    16,    17,    18,    19,
      20,    21,    15,    16,    17,    18,    19,    20,    21,    47,
      -1,    96,    90,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    43,    -1,    45,    39,    47,    -1,    49,
      43,    51,    45,     3,     4,    -1,    49,     7,    51,    -1,
       3,     4,    -1,    -1,     7,    15,    16,    17,    18,    19,
      20,    21,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    43,    -1,    45,    39,    -1,    -1,    49,
      43,    51,    45,     3,     4,    -1,    49,     7,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    43,    -1,    45,    -1,    -1,    -1,    49,
      -1,    51,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    46,    47,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    47,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    47,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    47,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    47,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    47,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    46,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    46,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    39,    -1,    -1,    -1,    43,    46,    45,    -1,
      -1,    -1,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    30,    56,    57,    58,    16,     0,    58,    49,
      16,    50,    63,    64,    65,    22,    23,    24,    25,    26,
      27,    28,    29,    66,    46,    50,    47,    46,    41,    62,
      46,    65,    16,    66,     3,     4,     7,    15,    16,    17,
      18,    19,    20,    21,    31,    33,    36,    37,    38,    39,
      40,    42,    43,    45,    49,    51,    57,    67,    68,    69,
      71,    74,    75,    77,    78,    79,    81,    82,    83,    84,
      85,    88,    41,    61,    60,     7,    16,    39,    45,    88,
      16,    88,    44,    49,    51,    86,    87,    88,    46,    88,
      49,    46,    16,    47,    88,    54,    72,    73,    16,    88,
      88,    68,    48,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    66,    67,    67,    44,    51,
      16,    16,    39,    88,    81,    88,    67,    32,    46,    88,
      46,     7,    16,    45,    69,    67,    68,    85,    49,    47,
      22,    23,    24,    25,    26,    27,    28,    29,    68,    73,
      85,    44,    51,    50,    52,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    59,    88,
      88,    49,    16,    47,    50,    52,    32,    68,    85,    47,
      68,    85,    16,    44,    51,    16,    88,    36,    36,    36,
      81,    46,    46,    46,    46,    46,    46,    46,    46,    88,
      88,    67,    47,    52,    81,    49,    44,    34,    34,    35,
      76,    88,    47,    88,    88,    88,    50,    16,    70,    16,
      70,    16,    70,    16,    70,    16,    70,    16,    70,    16,
      70,    16,    70,    47,    52,    50,    81,    88,    46,    46,
      88,    34,    35,    52,    16,    80,    88,    47,    47,    47,
      47,    46,    47,    47,    48,    46,    47,    47,    46,    47,
      47,    46,    47,    47,    46,    47,    51,    51,    47,    47,
      47,    47,    47,    47,    50,    47,    68,    85,    46,    46,
      88,    44,    50,    19,    16,    17,    19,    20,    21,    18,
      19,    19,    47,    85,    85,    46,    88,    46,    47,    47,
      47,    47,    47,    47,    52,    52,    85,    68,    85,    47,
      47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    59,    58,    60,    58,
      61,    58,    62,    58,    63,    63,    64,    64,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    76,    76,    77,    77,    77,    78,    78,    78,    79,
      79,    80,    80,    81,    81,    82,    82,    83,    84,    86,
      85,    87,    85,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     0,    10,     0,     9,
       0,     8,     0,     7,     1,     0,     3,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     7,     5,     5,     1,     3,     3,     3,     2,
       1,     5,     5,     5,     5,     5,     7,     7,     7,     7,
       7,     7,     8,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     8,     3,     2,     7,     4,     4,     7,
       8,     4,     5,     4,     4,     4,     6,     6,     6,     9,
       9,     3,     1,     1,     0,     3,     1,     8,     6,     0,
       4,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     3,     3,
       2,     2,     2,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: func_list  */
#line 53 "parser.y"
              {
        print_ast((yyvsp[0].ast), 0);
    }
#line 1644 "y.tab.c"
    break;

  case 3: /* program: error  */
#line 56 "parser.y"
          {
        yyerror("Could not parse input");
    }
#line 1652 "y.tab.c"
    break;

  case 4: /* func_list: func_list function  */
#line 62 "parser.y"
                       { (yyval.ast) = make_node("CODE", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1658 "y.tab.c"
    break;

  case 5: /* func_list: function  */
#line 63 "parser.y"
             { (yyval.ast) = make_node("CODE", 1, (yyvsp[0].ast)); }
#line 1664 "y.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 66 "parser.y"
                                                     {
        current_param_index = 0;
        if (symbol_exists_in_current_scope((yyvsp[-6].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-6].sval));
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];
            int param_count = count_params((yyvsp[-4].ast));
            collect_param_types((yyvsp[-4].ast), param_types);
            insert_function_with_param_types((yyvsp[-6].sval), get_type_from_name((yyvsp[0].ast)->name), param_count, param_types);
            printf("Pre-registered function '%s' in scope %d with %d params\n", (yyvsp[-6].sval), current_scope, param_count);
        }
        strcpy(current_function_name, (yyvsp[-6].sval));

        if (strcmp((yyvsp[-6].sval), "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if ((yyvsp[-4].ast)->child_count > 0 && strcmp((yyvsp[-4].ast)->children[0]->name, "NONE") != 0)
                yyerror("Semantic Error: _main_ function cannot take arguments");

            if (get_type_from_name((yyvsp[0].ast)->name) != DT_VOID)
                yyerror("Semantic Error: _main_ function cannot return a value");
        }
        if (get_type_from_name((yyvsp[0].ast)->name) == DT_STRING) {
            yyerror("Semantic Error: Function cannot return string type");
        }
    }
#line 1700 "y.tab.c"
    break;

  case 7: /* function: DEF ID LPAREN par_list RPAREN COLON RETURNS type $@1 stmt_list  */
#line 96 "parser.y"
                {
        inside_main = 0;
        current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-8].sval), 0),
             (yyvsp[-6].ast),
             make_node("RET", 1, (yyvsp[-2].ast)),
             make_node("BODY", 1, (yyvsp[0].ast)));
    }
#line 1715 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 107 "parser.y"
                                            {
        if (symbol_exists_in_current_scope((yyvsp[-5].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-5].sval));
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];  
            insert_function_with_param_types((yyvsp[-5].sval), get_type_from_name((yyvsp[0].ast)->name), 0, param_types);
            printf("Pre-registered function '%s' in scope %d with 0 params\n", (yyvsp[-5].sval), current_scope);
        }
        strcpy(current_function_name, (yyvsp[-5].sval));

        if (strcmp((yyvsp[-5].sval), "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if (get_type_from_name((yyvsp[0].ast)->name) != DT_VOID)
                yyerror("Semantic Error: _main_ function cannot return a value");
        }
        if (get_type_from_name((yyvsp[0].ast)->name) == DT_STRING) {
            yyerror("Semantic Error: Function cannot return string type");
        }
    }
#line 1745 "y.tab.c"
    break;

  case 9: /* function: DEF ID LPAREN RPAREN COLON RETURNS type $@2 stmt_list  */
#line 131 "parser.y"
                {
        inside_main = 0;
        current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-7].sval), 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, (yyvsp[-2].ast)),
             make_node("BODY", 1, (yyvsp[0].ast)));
    }
#line 1760 "y.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 142 "parser.y"
                                        {
    current_param_index = 0;
        if (symbol_exists_in_current_scope((yyvsp[-4].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-4].sval));
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];
            int param_count = count_params((yyvsp[-2].ast));
            collect_param_types((yyvsp[-2].ast), param_types);
            insert_function_with_param_types((yyvsp[-4].sval), DT_VOID, param_count, param_types);
            printf("Pre-registered function '%s' in scope %d with %d params\n", (yyvsp[-4].sval), current_scope, param_count);
        }
        strcpy(current_function_name, (yyvsp[-4].sval));

        if (strcmp((yyvsp[-4].sval), "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if ((yyvsp[-2].ast)->child_count > 0 && strcmp((yyvsp[-2].ast)->children[0]->name, "NONE") != 0)
                yyerror("Semantic Error: _main_ function cannot take arguments");
        }
    }
#line 1790 "y.tab.c"
    break;

  case 11: /* function: DEF ID LPAREN par_list RPAREN COLON $@3 stmt_list  */
#line 166 "parser.y"
                {
        inside_main = 0;
        current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-6].sval), 0),
             (yyvsp[-4].ast),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, (yyvsp[0].ast)));
    }
#line 1805 "y.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 177 "parser.y"
                               {
        if (symbol_exists_in_current_scope((yyvsp[-3].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-3].sval));
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];  
            insert_function_with_param_types((yyvsp[-3].sval), DT_VOID, 0, param_types);
            printf("Pre-registered function '%s' in scope %d with 0 params\n", (yyvsp[-3].sval), current_scope);
        }
    strcpy(current_function_name, (yyvsp[-3].sval));

        if (strcmp((yyvsp[-3].sval), "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;
        }
    }
#line 1829 "y.tab.c"
    break;

  case 13: /* function: DEF ID LPAREN RPAREN COLON $@4 stmt_list  */
#line 195 "parser.y"
                {
        inside_main = 0;
         current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-5].sval), 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, (yyvsp[0].ast)));

    }
#line 1845 "y.tab.c"
    break;

  case 14: /* par_list: param_list_item_list  */
#line 209 "parser.y"
                         { (yyval.ast) = make_node("ARGS", 1, (yyvsp[0].ast)); }
#line 1851 "y.tab.c"
    break;

  case 15: /* par_list: %empty  */
#line 210 "parser.y"
                { (yyval.ast) = make_node("ARGS", 1, make_node("NONE", 0)); }
#line 1857 "y.tab.c"
    break;

  case 16: /* param_list_item_list: param_list_item_list SEMICOLON par_list_item  */
#line 214 "parser.y"
                                                 {
        (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1865 "y.tab.c"
    break;

  case 17: /* param_list_item_list: par_list_item  */
#line 217 "parser.y"
                  {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1873 "y.tab.c"
    break;

  case 18: /* par_list_item: ID type COLON ID  */
#line 224 "parser.y"
                     {
        current_param_index++;
        
        check_param_order((yyvsp[-3].sval), current_param_index);
        
        insert_symbol((yyvsp[0].sval), VAR_SYM, get_type_from_name((yyvsp[-2].ast)->name));
        printf("  Inserted parameter '%s' as variable in scope %d\n", (yyvsp[0].sval), current_scope);
        
        // שינוי כאן: נשתמש בשם היררכי יותר ברור
        (yyval.ast) = make_node((yyvsp[-3].sval), 3, make_node((yyvsp[-3].sval), 0), make_node((yyvsp[-2].ast)->name, 0), make_node((yyvsp[0].sval), 0));
    }
#line 1889 "y.tab.c"
    break;

  case 19: /* type: TYPE_INT  */
#line 237 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1895 "y.tab.c"
    break;

  case 20: /* type: TYPE_CHAR  */
#line 238 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1901 "y.tab.c"
    break;

  case 21: /* type: TYPE_REAL  */
#line 239 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1907 "y.tab.c"
    break;

  case 22: /* type: TYPE_BOOL  */
#line 240 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1913 "y.tab.c"
    break;

  case 23: /* type: TYPE_STRING  */
#line 241 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1919 "y.tab.c"
    break;

  case 24: /* type: TYPE_INT_PTR  */
#line 242 "parser.y"
                 { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1925 "y.tab.c"
    break;

  case 25: /* type: TYPE_CHAR_PTR  */
#line 243 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1931 "y.tab.c"
    break;

  case 26: /* type: TYPE_REAL_PTR  */
#line 244 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1937 "y.tab.c"
    break;

  case 27: /* stmt_list: stmt_list stmt  */
#line 248 "parser.y"
                   { 
        printf("DEBUG: Processing stmt_list + stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = make_node("", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); 
    }
#line 1946 "y.tab.c"
    break;

  case 28: /* stmt_list: stmt  */
#line 252 "parser.y"
           { 
        printf("DEBUG: Processing solo stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = (yyvsp[0].ast); 
    }
#line 1955 "y.tab.c"
    break;

  case 41: /* assignment: ID ASSIGN expr SEMICOLON  */
#line 274 "parser.y"
                            {
        Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-3].sval));
            yyerror(error_msg);
        } else {
            DataType lhs_type = sym->type;
            DataType rhs_type = get_expr_type((yyvsp[-1].ast));
            
            if (rhs_type == DT_PTR_INT && (yyvsp[-1].ast)->name && strcmp((yyvsp[-1].ast)->name, "nullptr") == 0) {
                if (lhs_type != DT_PTR_INT && lhs_type != DT_PTR_CHAR && lhs_type != DT_PTR_REAL) {
                    char error_msg[100];
                    sprintf(error_msg, "Semantic Error: Cannot assign null to non-pointer type %s", 
                            get_name_from_type(lhs_type));
                    yyerror(error_msg);
                }
            }
            else if (!is_type_compatible(lhs_type, rhs_type)) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: Type mismatch in assignment, cannot assign %s to %s", 
                        get_name_from_type(rhs_type), get_name_from_type(lhs_type));
                yyerror(error_msg);
            }
        }
        (yyval.ast) = make_node("=", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
    }
#line 1987 "y.tab.c"
    break;

  case 42: /* assignment: ID LBRACK expr RBRACK ASSIGN expr SEMICOLON  */
#line 301 "parser.y"
                                                  {
        Symbol* sym = lookup_any_scope((yyvsp[-6].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-6].sval));
            yyerror(error_msg);
        } else if (sym->type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                    (yyvsp[-6].sval), get_name_from_type(sym->type));
            yyerror(error_msg);
        } else {
            check_string_index((yyvsp[-4].ast));
            
            DataType rhs_type = get_expr_type((yyvsp[-1].ast));
            if (rhs_type != DT_CHAR) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: String element can only be assigned a char value, got %s", 
                        get_name_from_type(rhs_type));
                yyerror(error_msg);
            }
        }
        (yyval.ast) = make_node("=", 2, make_node("array_access", 2, make_node((yyvsp[-6].sval), 0), (yyvsp[-4].ast)), (yyvsp[-1].ast));
    }
#line 2016 "y.tab.c"
    break;

  case 43: /* assignment: MULT ID ASSIGN expr SEMICOLON  */
#line 325 "parser.y"
                                  {
        Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-3].sval));
            yyerror(error_msg);
        }
        
        DataType type = sym->type;
        if (!is_pointer_type(type)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot dereference non-pointer variable '%s'", (yyvsp[-3].sval));
            yyerror(error_msg);
        }
        
        DataType target_type = get_base_type(type);
        
        DataType expr_type = get_expr_type((yyvsp[-1].ast));
        if (target_type != expr_type) {
            if (!(target_type == DT_REAL && expr_type == DT_INT)) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: Type mismatch in assignment to dereferenced pointer: expected %s, got %s",
                        get_name_from_type(target_type), get_name_from_type(expr_type));
                yyerror(error_msg);
            }
        }
        
        (yyval.ast) = make_node("=", 2, make_node("*", 1, make_node((yyvsp[-3].sval), 0)), (yyvsp[-1].ast));
    }
#line 2050 "y.tab.c"
    break;

  case 44: /* assignment: ADDRESS ID ASSIGN expr SEMICOLON  */
#line 354 "parser.y"
                                       {
        yyerror("Semantic Error: Cannot use address operator on left side of assignment");
        (yyval.ast) = make_node("error", 2, make_node("&", 1, make_node((yyvsp[-3].sval), 0)), (yyvsp[-1].ast));
   }
#line 2059 "y.tab.c"
    break;

  case 45: /* id_list: ID  */
#line 361 "parser.y"
                                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2065 "y.tab.c"
    break;

  case 46: /* id_list: id_list COMMA ID  */
#line 362 "parser.y"
                               { (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), make_node((yyvsp[0].sval), 0)); }
#line 2071 "y.tab.c"
    break;

  case 47: /* var_stmt: VAR type_decls block  */
#line 367 "parser.y"
                         {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 2079 "y.tab.c"
    break;

  case 48: /* var_stmt: VAR type_decls stmt  */
#line 370 "parser.y"
                        {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 2087 "y.tab.c"
    break;

  case 49: /* type_decls: type_decls type_decl  */
#line 375 "parser.y"
                         {
        (yyval.ast) = make_node("DECLS", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 2095 "y.tab.c"
    break;

  case 50: /* type_decls: type_decl  */
#line 378 "parser.y"
              {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2103 "y.tab.c"
    break;

  case 51: /* type_decl: TYPE TYPE_INT COLON ID SEMICOLON  */
#line 383 "parser.y"
                                     {
        insert_checked_variable((yyvsp[-1].sval), DT_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2112 "y.tab.c"
    break;

  case 52: /* type_decl: TYPE TYPE_BOOL COLON ID SEMICOLON  */
#line 387 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2121 "y.tab.c"
    break;

  case 53: /* type_decl: TYPE TYPE_CHAR COLON ID SEMICOLON  */
#line 391 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2130 "y.tab.c"
    break;

  case 54: /* type_decl: TYPE TYPE_STRING COLON ID SEMICOLON  */
#line 395 "parser.y"
                                        {
        insert_checked_variable((yyvsp[-1].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2139 "y.tab.c"
    break;

  case 55: /* type_decl: TYPE TYPE_REAL COLON ID SEMICOLON  */
#line 399 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2148 "y.tab.c"
    break;

  case 56: /* type_decl: TYPE TYPE_REAL COLON ID COLON NUM SEMICOLON  */
#line 403 "parser.y"
                                                  {
        insert_checked_variable((yyvsp[-3].sval), DT_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real", 0), make_node((yyvsp[-3].sval), 1,make_node((yyvsp[-1].sval),0)));
    }
#line 2157 "y.tab.c"
    break;

  case 57: /* type_decl: TYPE TYPE_INT COLON ID COLON NUM SEMICOLON  */
#line 407 "parser.y"
                                               {
        insert_checked_variable((yyvsp[-3].sval), DT_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2166 "y.tab.c"
    break;

  case 58: /* type_decl: TYPE TYPE_CHAR COLON ID COLON CHAR_LITERAL SEMICOLON  */
#line 411 "parser.y"
                                                         {
        insert_checked_variable((yyvsp[-3].sval), DT_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2175 "y.tab.c"
    break;

  case 59: /* type_decl: TYPE TYPE_STRING COLON ID COLON STRING_LITERAL SEMICOLON  */
#line 415 "parser.y"
                                                             {
        insert_checked_variable((yyvsp[-3].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2184 "y.tab.c"
    break;

  case 60: /* type_decl: TYPE TYPE_BOOL COLON ID COLON TRUE SEMICOLON  */
#line 419 "parser.y"
                                                 {
        insert_checked_variable((yyvsp[-3].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-3].sval), 1, make_node("true", 0)));
    }
#line 2193 "y.tab.c"
    break;

  case 61: /* type_decl: TYPE TYPE_BOOL COLON ID COLON FALSE SEMICOLON  */
#line 423 "parser.y"
                                                  {
        insert_checked_variable((yyvsp[-3].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-3].sval), 1, make_node("false", 0)));
    }
#line 2202 "y.tab.c"
    break;

  case 62: /* type_decl: TYPE TYPE_STRING COLON ID LBRACK NUM RBRACK SEMICOLON  */
#line 427 "parser.y"
                                                           {
        int size = atoi((yyvsp[-2].sval));
        if (size <= 0) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: String size must be a positive integer");
            yyerror(error_msg);
        }
        insert_checked_variable((yyvsp[-4].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 3, make_node("string", 0), make_node((yyvsp[-4].sval), 0), make_node((yyvsp[-2].sval), 0));
    }
#line 2217 "y.tab.c"
    break;

  case 63: /* type_decl: TYPE TYPE_INT_PTR COLON ID SEMICOLON  */
#line 437 "parser.y"
                                           {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2226 "y.tab.c"
    break;

  case 64: /* type_decl: TYPE TYPE_CHAR_PTR COLON ID SEMICOLON  */
#line 441 "parser.y"
                                          {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2235 "y.tab.c"
    break;

  case 65: /* type_decl: TYPE TYPE_REAL_PTR COLON ID SEMICOLON  */
#line 445 "parser.y"
                                          {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2244 "y.tab.c"
    break;

  case 66: /* type_decl: TYPE TYPE_INT COLON id_list SEMICOLON  */
#line 450 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_INT);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("int", 0), (yyvsp[-1].ast));
    }
#line 2253 "y.tab.c"
    break;

  case 67: /* type_decl: TYPE TYPE_BOOL COLON id_list SEMICOLON  */
#line 454 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_BOOL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("bool", 0), (yyvsp[-1].ast));
    }
#line 2262 "y.tab.c"
    break;

  case 68: /* type_decl: TYPE TYPE_CHAR COLON id_list SEMICOLON  */
#line 458 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_CHAR);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("char", 0), (yyvsp[-1].ast));
    }
#line 2271 "y.tab.c"
    break;

  case 69: /* type_decl: TYPE TYPE_REAL COLON id_list SEMICOLON  */
#line 462 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_REAL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("real", 0), (yyvsp[-1].ast));
    }
#line 2280 "y.tab.c"
    break;

  case 70: /* type_decl: TYPE TYPE_INT_PTR COLON id_list SEMICOLON  */
#line 466 "parser.y"
                                              {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_INT);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("int*", 0), (yyvsp[-1].ast));
    }
#line 2289 "y.tab.c"
    break;

  case 71: /* type_decl: TYPE TYPE_CHAR_PTR COLON id_list SEMICOLON  */
#line 470 "parser.y"
                                               {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_CHAR);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("char*", 0), (yyvsp[-1].ast));
    }
#line 2298 "y.tab.c"
    break;

  case 72: /* type_decl: TYPE TYPE_REAL_PTR COLON id_list SEMICOLON  */
#line 474 "parser.y"
                                               {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_REAL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("real*", 0), (yyvsp[-1].ast));
    }
#line 2307 "y.tab.c"
    break;

  case 73: /* type_decl: TYPE TYPE_STRING COLON id_list LBRACK NUM RBRACK SEMICOLON  */
#line 478 "parser.y"
                                                                 {
    int size = atoi((yyvsp[-2].sval));
    if (size <= 0) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: String size must be a positive integer");
        yyerror(error_msg);
    }
    add_multiple_variables((yyvsp[-4].ast), DT_STRING);
    (yyval.ast) = make_node("TYPE_STRING_ARRAY", 3, make_node("string", 0), (yyvsp[-4].ast), make_node((yyvsp[-2].sval), 0));
}
#line 2322 "y.tab.c"
    break;

  case 74: /* return_stmt: RETURN expr SEMICOLON  */
#line 491 "parser.y"
                          {
        printf("DEBUG: Processing return with value in function '%s'\n", current_function_name);
        if (strcmp(current_function_name, "_main_") == 0) {
    yyerror("Semantic Error: _main_ function cannot return a value");
}

        
        check_return_type((yyvsp[-1].ast), current_function_name);
        
        (yyval.ast) = make_node("RETURN", 1, (yyvsp[-1].ast));
    }
#line 2338 "y.tab.c"
    break;

  case 75: /* return_stmt: RETURN SEMICOLON  */
#line 502 "parser.y"
                     {
        printf("DEBUG: Processing empty return in function '%s'\n", current_function_name);
        
        check_return_type(make_node("NONE", 0), current_function_name);
        
        (yyval.ast) = make_node("RETURN", 1, make_node("NONE", 0));
    }
#line 2350 "y.tab.c"
    break;

  case 76: /* if_stmt: IF expr COLON block ELSE COLON block  */
#line 513 "parser.y"
    {
        check_boolean_condition((yyvsp[-5].ast), "if");
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2359 "y.tab.c"
    break;

  case 77: /* if_stmt: IF expr COLON block  */
#line 518 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "if");
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2368 "y.tab.c"
    break;

  case 78: /* if_stmt: IF expr COLON stmt  */
#line 523 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "if");
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2377 "y.tab.c"
    break;

  case 79: /* if_stmt: IF expr COLON stmt ELSE COLON stmt  */
#line 528 "parser.y"
    {
        check_boolean_condition((yyvsp[-5].ast), "if");
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2386 "y.tab.c"
    break;

  case 80: /* if_stmt: IF expr COLON block elif_list ELSE COLON block  */
#line 533 "parser.y"
    {
        check_boolean_condition((yyvsp[-6].ast), "if");
        (yyval.ast) = make_node("IF-ELIF-ELSE", 4, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2395 "y.tab.c"
    break;

  case 81: /* elif_list: ELIF expr COLON block  */
#line 541 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "elif");
        (yyval.ast) = make_node("ELIF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2404 "y.tab.c"
    break;

  case 82: /* elif_list: elif_list ELIF expr COLON block  */
#line 546 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "elif");
        (yyval.ast) = make_node("ELIF - ...", 3, (yyvsp[-4].ast), make_node("elif", 2, (yyvsp[-2].ast), (yyvsp[0].ast)));
    }
#line 2413 "y.tab.c"
    break;

  case 83: /* while_stmt: WHILE COLON expr SEMICOLON  */
#line 553 "parser.y"
    {
        check_boolean_condition((yyvsp[-1].ast), "while");
        (yyval.ast) = make_node("while", 1, (yyvsp[-1].ast));
    }
#line 2422 "y.tab.c"
    break;

  case 84: /* while_stmt: WHILE expr COLON block  */
#line 558 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "while");
        (yyval.ast) = make_node("while2", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2431 "y.tab.c"
    break;

  case 85: /* while_stmt: WHILE expr COLON stmt  */
#line 563 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "while");
        (yyval.ast) = make_node("while2", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2440 "y.tab.c"
    break;

  case 86: /* do_while_stmt: DO COLON stmt_list WHILE expr SEMICOLON  */
#line 569 "parser.y"
                                            {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2449 "y.tab.c"
    break;

  case 87: /* do_while_stmt: DO COLON stmt WHILE expr SEMICOLON  */
#line 574 "parser.y"
                                       {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2458 "y.tab.c"
    break;

  case 88: /* do_while_stmt: DO COLON block WHILE expr SEMICOLON  */
#line 579 "parser.y"
                                        {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2467 "y.tab.c"
    break;

  case 89: /* for_stmt: FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON block  */
#line 586 "parser.y"
                                                                        {
        check_boolean_condition((yyvsp[-5].ast), "for"); 
        (yyval.ast) = make_node("for", 4, (yyvsp[-6].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2476 "y.tab.c"
    break;

  case 90: /* for_stmt: FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON stmt  */
#line 591 "parser.y"
                                                                       {
        check_boolean_condition((yyvsp[-5].ast), "for"); 
        (yyval.ast) = make_node("for", 4, (yyvsp[-6].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2485 "y.tab.c"
    break;

  case 91: /* update_expr: ID ASSIGN expr  */
#line 598 "parser.y"
                   {
        (yyval.ast) = make_node("=", 2, make_node((yyvsp[-2].sval), 0), (yyvsp[0].ast));
    }
#line 2493 "y.tab.c"
    break;

  case 92: /* update_expr: expr  */
#line 601 "parser.y"
           {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2501 "y.tab.c"
    break;

  case 93: /* call_args: call_list  */
#line 606 "parser.y"
              { (yyval.ast) = make_node("args", 1, (yyvsp[0].ast)); }
#line 2507 "y.tab.c"
    break;

  case 94: /* call_args: %empty  */
#line 607 "parser.y"
                { (yyval.ast) = make_node("args", 1, make_node("none", 0)); }
#line 2513 "y.tab.c"
    break;

  case 95: /* call_list: call_list COMMA expr  */
#line 612 "parser.y"
    {
        (yyval.ast)= make_node ("par",2,(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2521 "y.tab.c"
    break;

  case 96: /* call_list: expr  */
#line 616 "parser.y"
    {
          (yyval.ast)= make_node ("par",1,(yyvsp[0].ast));
    }
#line 2529 "y.tab.c"
    break;

  case 97: /* assignment_call: ID ASSIGN CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 623 "parser.y"
                                                        {
        Symbol* func = lookup_any_scope((yyvsp[-4].sval));
        if (!func) {
            char msg[100];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration", (yyvsp[-4].sval));
            yyerror(msg);
        } else if (func->kind != FUNC_SYM) {
            char msg[100];
            sprintf(msg, "Semantic Error: '%s' is not a function", (yyvsp[-4].sval));
            yyerror(msg);
        } else {
            int expected = func->param_count;
            int actual = count_actual_params((yyvsp[-2].ast));
            if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d arguments, got %d", (yyvsp[-4].sval), expected, actual);
                yyerror(msg);
            } else {
                check_param_types((yyvsp[-4].sval), (yyvsp[-2].ast));
            }
        }

        (yyval.ast) = make_node("ASSIGN-CALL", 2,
                       make_node((yyvsp[-7].sval), 0),
                       make_node("CALL", 2, make_node((yyvsp[-4].sval), 0), (yyvsp[-2].ast)));
    }
#line 2560 "y.tab.c"
    break;

  case 98: /* void_call: CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 652 "parser.y"
                                              {
        Symbol* func = lookup_any_scope((yyvsp[-4].sval));
        if (!func) {
            char msg[100];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration", (yyvsp[-4].sval));
            yyerror(msg);
        } else if (func->kind != FUNC_SYM) {
            char msg[100];
            sprintf(msg, "Semantic Error: '%s' is not a function", (yyvsp[-4].sval));
            yyerror(msg);
        } else {
            int expected = func->param_count;
            int actual = count_actual_params((yyvsp[-2].ast));
            if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d arguments, got %d", (yyvsp[-4].sval), expected, actual);
                yyerror(msg);
            } else {
                check_param_types((yyvsp[-4].sval), (yyvsp[-2].ast));
            }
        }

        (yyval.ast) = make_node("CALL", 2, make_node((yyvsp[-4].sval), 0), (yyvsp[-2].ast));
    }
#line 2589 "y.tab.c"
    break;

  case 99: /* $@5: %empty  */
#line 679 "parser.y"
            {
        enter_scope();
    }
#line 2597 "y.tab.c"
    break;

  case 100: /* block: T_BEGIN $@5 stmt_list T_END  */
#line 682 "parser.y"
                    {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
        exit_scope();
    }
#line 2606 "y.tab.c"
    break;

  case 101: /* $@6: %empty  */
#line 686 "parser.y"
                 {
        enter_scope();
    }
#line 2614 "y.tab.c"
    break;

  case 102: /* block: T_BEGIN $@6 T_END  */
#line 689 "parser.y"
           {
        (yyval.ast) = make_node("BLOCK", 0); 
        exit_scope();
     }
#line 2623 "y.tab.c"
    break;

  case 103: /* expr: expr PLUS expr  */
#line 696 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '+' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("+", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2639 "y.tab.c"
    break;

  case 104: /* expr: expr MINUS expr  */
#line 707 "parser.y"
                      {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '-' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("-", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2655 "y.tab.c"
    break;

  case 105: /* expr: expr MULT expr  */
#line 718 "parser.y"
                     {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '*' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("*", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2671 "y.tab.c"
    break;

  case 106: /* expr: expr DIV expr  */
#line 729 "parser.y"
                     {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '/' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("/", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2687 "y.tab.c"
    break;

  case 107: /* expr: expr EQ expr  */
#line 740 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (left != right) {
        char msg[200];
        sprintf(msg, "Semantic Error: '==' requires operands of same type, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("==", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2703 "y.tab.c"
    break;

  case 108: /* expr: expr NE expr  */
#line 751 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (left != right) {
        char msg[200];
        sprintf(msg, "Semantic Error: '!=' requires operands of same type, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("!=", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2719 "y.tab.c"
    break;

  case 109: /* expr: expr LT expr  */
#line 762 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '<' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("<", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2735 "y.tab.c"
    break;

  case 110: /* expr: expr GT expr  */
#line 773 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '>' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node(">", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2751 "y.tab.c"
    break;

  case 111: /* expr: expr LE expr  */
#line 784 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '<=' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("<=", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2767 "y.tab.c"
    break;

  case 112: /* expr: expr GE expr  */
#line 795 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '>=' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node(">=", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2783 "y.tab.c"
    break;

  case 113: /* expr: LPAREN expr RPAREN  */
#line 806 "parser.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2789 "y.tab.c"
    break;

  case 114: /* expr: ID LBRACK expr RBRACK  */
#line 808 "parser.y"
                            {
        Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-3].sval));
            yyerror(error_msg);
        } else if (sym->type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                    (yyvsp[-3].sval), get_name_from_type(sym->type));
            yyerror(error_msg);
        } else {
            check_string_index((yyvsp[-1].ast));
        }
        (yyval.ast) = make_node("array_access", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
    }
#line 2810 "y.tab.c"
    break;

  case 115: /* expr: LBRACK expr RBRACK  */
#line 825 "parser.y"
                         {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Invalid use of [] operator");
        yyerror(error_msg);
        (yyval.ast) = (yyvsp[-1].ast); 
    }
#line 2821 "y.tab.c"
    break;

  case 116: /* expr: NUM  */
#line 832 "parser.y"
          { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2827 "y.tab.c"
    break;

  case 117: /* expr: ID  */
#line 833 "parser.y"
         {
        Symbol* sym = lookup_any_scope((yyvsp[0].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[0].sval));
            yyerror(error_msg);
        }
        (yyval.ast) = make_node((yyvsp[0].sval), 0);
    }
#line 2841 "y.tab.c"
    break;

  case 118: /* expr: CHAR_LITERAL  */
#line 842 "parser.y"
                   { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2847 "y.tab.c"
    break;

  case 119: /* expr: STRING_LITERAL  */
#line 843 "parser.y"
                     { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2853 "y.tab.c"
    break;

  case 120: /* expr: NULLPTR  */
#line 844 "parser.y"
              { (yyval.ast) = make_node("nullptr", 0); }
#line 2859 "y.tab.c"
    break;

  case 121: /* expr: TRUE  */
#line 845 "parser.y"
           { (yyval.ast) = make_node("true", 0); }
#line 2865 "y.tab.c"
    break;

  case 122: /* expr: FALSE  */
#line 846 "parser.y"
            { (yyval.ast) = make_node("false", 0); }
#line 2871 "y.tab.c"
    break;

  case 123: /* expr: AND  */
#line 847 "parser.y"
          { (yyval.ast) = make_node("and", 0); }
#line 2877 "y.tab.c"
    break;

  case 124: /* expr: OR  */
#line 848 "parser.y"
         { (yyval.ast) = make_node("or", 0); }
#line 2883 "y.tab.c"
    break;

  case 125: /* expr: NOT  */
#line 849 "parser.y"
          { (yyval.ast) = make_node("not", 0); }
#line 2889 "y.tab.c"
    break;

  case 126: /* expr: CALL ID LPAREN call_args RPAREN  */
#line 850 "parser.y"
                                      {
        Symbol* func = lookup_any_scope((yyvsp[-3].sval));
        if (func && func->kind == FUNC_SYM) {
            int expected = func->param_count;
            int actual = count_actual_params((yyvsp[-1].ast));
            if (expected == actual) {
                check_param_types((yyvsp[-3].sval), (yyvsp[-1].ast));
            }
        }
        (yyval.ast) = make_node("call", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
    }
#line 2905 "y.tab.c"
    break;

  case 127: /* expr: ID LPAREN call_args RPAREN  */
#line 861 "parser.y"
                                 {
        /* קודם–כל: חייב להיות סימבול של פונקציה כבר בטבלה */
        Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
        if (!sym) {
            char msg[128];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration/definition", (yyvsp[-3].sval));
            yyerror(msg);
        }
        else if (sym->kind != FUNC_SYM) {
            char msg[128];
            sprintf(msg, "Semantic Error: '%s' is not a function", (yyvsp[-3].sval));
            yyerror(msg);
        }
        else {
            /* בדיקת ארגומנטים */
            int expected = sym->param_count;
            int actual   = count_actual_params((yyvsp[-1].ast));
          if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d args, got %d",
                        (yyvsp[-3].sval), expected, actual);
                yyerror(msg);
            } else {
                check_param_types((yyvsp[-3].sval), (yyvsp[-1].ast));
            }
        }
        (yyval.ast) = make_node("call", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
    }
#line 2938 "y.tab.c"
    break;

  case 128: /* expr: expr AND expr  */
#line 889 "parser.y"
                    { (yyval.ast) = make_node("and", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2944 "y.tab.c"
    break;

  case 129: /* expr: expr OR expr  */
#line 890 "parser.y"
                   { (yyval.ast) = make_node("or", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2950 "y.tab.c"
    break;

  case 130: /* expr: NOT expr  */
#line 891 "parser.y"
               { (yyval.ast) = make_node("not", 1, (yyvsp[0].ast)); }
#line 2956 "y.tab.c"
    break;

  case 131: /* expr: MULT expr  */
#line 893 "parser.y"
              {
    // בדיקה אם מנסים לדרפר ביטוי שהוא לא מזהה או דירפור
    if (!(yyvsp[0].ast)) {
        yyerror("Semantic Error: Invalid dereference expression");
        (yyval.ast) = make_node("error", 0);
    }
    // אם זה כבר תוצאה של דירפור אחר, נדווח על שגיאה בדירפור כפול
    else if ((yyvsp[0].ast)->name && strcmp((yyvsp[0].ast)->name, "*") == 0) {
        yyerror("Semantic Error: Double dereference is not allowed (cannot use **ptr)");
        (yyval.ast) = make_node("error", 1, (yyvsp[0].ast));
    }
    // אם זה מזהה רגיל, נבדוק אם זה פוינטר
    else if ((yyvsp[0].ast)->name && (yyvsp[0].ast)->child_count == 0) {
        Symbol* sym = lookup_any_scope((yyvsp[0].ast)->name);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[0].ast)->name);
            yyerror(error_msg);
        }
        else if (!is_pointer_type(sym->type)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot dereference non-pointer variable '%s'", (yyvsp[0].ast)->name);
            yyerror(error_msg);
        }
        (yyval.ast) = make_node("*", 1, (yyvsp[0].ast));
    }
    // אחרת זה ביטוי כלשהו - נדווח על שגיאה
    else {
        yyerror("Semantic Error: Cannot dereference non-pointer expression");
        (yyval.ast) = make_node("error", 1, (yyvsp[0].ast));
    }
}
#line 2993 "y.tab.c"
    break;

  case 132: /* expr: ADDRESS ID  */
#line 925 "parser.y"
               {
    Symbol* sym = lookup_any_scope((yyvsp[0].sval));
    if (!sym) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[0].sval));
        yyerror(error_msg);
    } else {
        DataType type = sym->type;
        if (type == DT_PTR_INT || type == DT_PTR_CHAR || type == DT_PTR_REAL) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot take address of pointer variable '%s'", (yyvsp[0].sval));
            yyerror(error_msg);
        } else if (type != DT_INT && type != DT_REAL && type != DT_CHAR && type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot take address of '%s' with type '%s'",
                    (yyvsp[0].sval), get_name_from_type(type));
            yyerror(error_msg);
        }
    }

    (yyval.ast) = make_node("&", 1, make_node((yyvsp[0].sval), 0));
}
#line 3020 "y.tab.c"
    break;

  case 133: /* expr: ADDRESS ID LBRACK expr RBRACK  */
#line 948 "parser.y"
                                {
    Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
    if (!sym) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-3].sval));
        yyerror(error_msg);
    } else if (sym->type != DT_STRING) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                (yyvsp[-3].sval), get_name_from_type(sym->type));
        yyerror(error_msg);
    } else {
        check_string_index((yyvsp[-1].ast));
    }
    
    // מחזיר מצביע לתו (char*)
    (yyval.ast) = make_node("&array_access", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
}
#line 3043 "y.tab.c"
    break;


#line 3047 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 969 "parser.y"


void yyerror(const char* s) {
    extern char* yytext;
    fprintf(stderr, "Syntax Error: %s (current token: %s)\n", s, yytext);
}

int main(int argc, char* argv[]) {
    printf("DEBUG: Starting compiler\n");

    enter_scope();
    int result = yyparse();

    printf("\nDEBUG: Final symbol tables:\n");
    print_symbol_tables();
    preserve_symbol_tables = 1;
    exit_scope();

    if (!main_defined) {
        yyerror("Semantic Error: No _main_ function defined");
    }

    return result;
}
