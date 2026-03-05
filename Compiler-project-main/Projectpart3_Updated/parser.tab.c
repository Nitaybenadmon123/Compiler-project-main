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
#include "three_address_code.h"
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
    AST* program_ast = NULL;

#line 95 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OR = 3,                         /* OR  */
  YYSYMBOL_AND = 4,                        /* AND  */
  YYSYMBOL_EQ = 5,                         /* EQ  */
  YYSYMBOL_NE = 6,                         /* NE  */
  YYSYMBOL_GT = 7,                         /* GT  */
  YYSYMBOL_GE = 8,                         /* GE  */
  YYSYMBOL_LT = 9,                         /* LT  */
  YYSYMBOL_LE = 10,                        /* LE  */
  YYSYMBOL_PLUS = 11,                      /* PLUS  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_MULT = 13,                      /* MULT  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
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
  YYSYMBOL_function_body = 58,             /* function_body  */
  YYSYMBOL_nested_func_list = 59,          /* nested_func_list  */
  YYSYMBOL_function = 60,                  /* function  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_63_3 = 63,                      /* $@3  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_par_list = 65,                  /* par_list  */
  YYSYMBOL_param_list_item_list = 66,      /* param_list_item_list  */
  YYSYMBOL_par_list_item = 67,             /* par_list_item  */
  YYSYMBOL_type = 68,                      /* type  */
  YYSYMBOL_stmt_list = 69,                 /* stmt_list  */
  YYSYMBOL_stmt = 70,                      /* stmt  */
  YYSYMBOL_assignment = 71,                /* assignment  */
  YYSYMBOL_mixed_id_list = 72,             /* mixed_id_list  */
  YYSYMBOL_id_list = 73,                   /* id_list  */
  YYSYMBOL_var_stmt = 74,                  /* var_stmt  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_76_6 = 76,                      /* $@6  */
  YYSYMBOL_block_content = 77,             /* block_content  */
  YYSYMBOL_type_decls = 78,                /* type_decls  */
  YYSYMBOL_string_id_list = 79,            /* string_id_list  */
  YYSYMBOL_type_decl = 80,                 /* type_decl  */
  YYSYMBOL_id_value_list = 81,             /* id_value_list  */
  YYSYMBOL_literal = 82,                   /* literal  */
  YYSYMBOL_return_stmt = 83,               /* return_stmt  */
  YYSYMBOL_if_stmt = 84,                   /* if_stmt  */
  YYSYMBOL_elif_list = 85,                 /* elif_list  */
  YYSYMBOL_while_stmt = 86,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 87,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 88,                  /* for_stmt  */
  YYSYMBOL_update_expr = 89,               /* update_expr  */
  YYSYMBOL_call_args = 90,                 /* call_args  */
  YYSYMBOL_call_list = 91,                 /* call_list  */
  YYSYMBOL_assignment_call = 92,           /* assignment_call  */
  YYSYMBOL_void_call = 93,                 /* void_call  */
  YYSYMBOL_block = 94,                     /* block  */
  YYSYMBOL_nested_block = 95,              /* nested_block  */
  YYSYMBOL_96_7 = 96,                      /* $@7  */
  YYSYMBOL_97_8 = 97,                      /* $@8  */
  YYSYMBOL_expr = 98                       /* expr  */
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
#define YYLAST   1449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  377

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
       0,    58,    58,    62,    68,    69,    72,    73,    74,    75,
      78,    83,    84,    87,    87,   134,   134,   175,   175,   216,
     216,   254,   255,   259,   262,   269,   284,   285,   286,   287,
     288,   289,   290,   291,   295,   299,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   321,   348,
     372,   401,   407,   410,   413,   416,   421,   422,   427,   427,
     433,   433,   443,   448,   455,   458,   463,   466,   471,   475,
     479,   483,   487,   491,   495,   499,   503,   507,   511,   515,
     525,   529,   533,   538,   542,   546,   550,   554,   558,   562,
     566,   570,   574,   578,   582,   586,   589,   593,   597,   601,
     605,   612,   615,   622,   623,   624,   625,   626,   631,   639,
     649,   654,   659,   664,   669,   677,   682,   689,   694,   699,
     706,   711,   716,   723,   728,   735,   738,   743,   744,   748,
     752,   760,   789,   816,   819,   824,   824,   832,   832,   842,
     843,   857,   868,   879,   890,   901,   912,   923,   934,   945,
     956,   967,   969,   986,   993,   994,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1022,  1050,  1051,  1052,  1054,
    1086,  1109
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
  "\"end of file\"", "error", "\"invalid token\"", "OR", "AND", "EQ",
  "NE", "GT", "GE", "LT", "LE", "PLUS", "MINUS", "MULT", "DIV", "NOT",
  "ID", "CHAR_LITERAL", "STRING_LITERAL", "NUM", "TRUE", "FALSE",
  "TYPE_INT", "TYPE_CHAR", "TYPE_REAL", "TYPE_BOOL", "TYPE_STRING",
  "TYPE_INT_PTR", "TYPE_CHAR_PTR", "TYPE_REAL_PTR", "DEF", "T_BEGIN",
  "T_END", "IF", "ELSE", "ELIF", "WHILE", "FOR", "DO", "CALL", "RETURN",
  "RETURNS", "VAR", "NULLPTR", "ASSIGN", "ADDRESS", "COLON", "SEMICOLON",
  "COMMA", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "BAR", "TYPE",
  "$accept", "program", "func_list", "function_body", "nested_func_list",
  "function", "$@1", "$@2", "$@3", "$@4", "par_list",
  "param_list_item_list", "par_list_item", "type", "stmt_list", "stmt",
  "assignment", "mixed_id_list", "id_list", "var_stmt", "$@5", "$@6",
  "block_content", "type_decls", "string_id_list", "type_decl",
  "id_value_list", "literal", "return_stmt", "if_stmt", "elif_list",
  "while_stmt", "do_while_stmt", "for_stmt", "update_expr", "call_args",
  "call_list", "assignment_call", "void_call", "block", "nested_block",
  "$@7", "$@8", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-304)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-129)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,  -304,    22,    44,    19,  -304,     8,  -304,  -304,    -3,
     110,    49,    53,    25,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,    64,    57,    66,   114,   127,   110,   -14,
     104,  -304,  -304,  -304,   238,    97,  -304,   110,   -14,   -14,
    -304,  -304,   891,  1384,   -22,  -304,  -304,  -304,  -304,  -304,
     281,  -304,   934,   101,   109,   107,   147,   797,  -304,  -304,
     150,   934,   934,   159,   668,  -304,   324,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,   137,  -304,  -304,  -304,
    1435,   831,   -23,  -304,  -304,  -304,  -304,   934,    48,   177,
     186,  -304,     7,  -304,   977,   848,   934,  -304,  -304,   367,
    1308,   934,  1352,     5,   668,   164,  -304,  1101,    97,    97,
     -10,   222,   818,   156,  -304,   410,  -304,  -304,   934,   934,
     934,   934,   934,   934,   934,   934,   934,   934,   934,   934,
     934,   178,   199,   202,   204,   206,   219,   221,   233,   453,
    -304,   -14,   934,   934,   237,   171,   266,  1146,   240,   868,
    -304,   711,  1158,   668,   272,     4,   279,   934,   754,   274,
     286,   848,  -304,   -15,   161,   934,   934,  -304,  -304,  -304,
    -304,  1435,  1120,    56,   176,   176,   176,   176,   176,   176,
      11,    11,  -304,  -304,   289,   309,   313,   315,   317,   322,
     337,   349,  -304,   496,  -304,  1170,   953,   848,   319,  -304,
    -304,   328,   281,   340,    40,  -304,  -304,  -304,   332,   934,
     934,   352,  1215,   101,   934,   934,   358,   539,  -304,  -304,
    1227,  1039,    95,   122,   136,   148,   102,   160,   170,   173,
     197,   245,   256,   260,   269,   288,   304,   311,   -11,   331,
     347,   354,   334,   374,   364,   390,   368,   397,  -304,  -304,
    -304,   369,   848,   934,   668,   385,   378,   393,   934,   430,
    1071,  1020,  1089,  1239,  1284,   404,  -304,   582,  -304,  -304,
     108,  -304,  -304,   438,  -304,   442,  -304,   444,   329,  -304,
    -304,  -304,  -304,   372,  -304,  -304,  -304,  -304,   415,  -304,
    -304,  -304,  -304,   458,  -304,   443,  -304,  -304,   451,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,   447,  1296,   625,
    -304,   668,   449,  1364,   448,   934,   328,    62,   455,  1435,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,   454,  -304,  -304,
    -304,   457,  -304,   461,   463,  -304,   476,   477,   478,   483,
     456,   480,   490,  -304,  -304,  -304,  -304,  -304,   509,   449,
    1376,   934,   498,  -304,   501,   501,  -304,  -304,  -304,  -304,
    -304,   499,   529,  -304,  -304,  -304,   509,  1435,   668,  -304,
    -304,  -304,   510,  -304,  -304,  -304,  -304
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     2,     5,     0,     1,     4,     0,
       0,     0,     0,    21,    24,    26,    27,    28,    29,    30,
      31,    32,    33,     0,    19,     0,     0,     0,     0,     0,
      17,    23,    25,    15,   128,     0,    20,     0,     0,     0,
     162,   161,   139,   139,   155,   156,   157,   154,   159,   160,
     128,     8,   139,   139,     0,     0,     0,   139,    58,   158,
       0,   139,   139,     0,   128,    12,   128,    35,    36,    44,
      38,    37,    40,    43,    41,    42,   127,    46,    45,    39,
     130,     0,     0,    65,    13,    18,    16,   139,   155,     0,
       0,   169,   155,   168,   139,   139,   139,   134,    47,   128,
       0,   139,     0,     0,   128,     0,   109,     0,     0,     0,
     170,     0,     0,     0,    11,   128,     6,    34,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,     0,     0,     0,     0,     0,     0,     0,     0,   128,
      64,     0,   139,   139,     0,   170,     0,     0,     0,     0,
     133,   128,     0,   128,     0,     0,     0,   139,   128,    35,
      39,   139,   108,     0,   128,   139,   139,   151,   153,   140,
       7,   129,   167,   166,   145,   146,   148,   150,   147,   149,
     141,   142,   143,   144,     0,     0,     0,     0,     0,     0,
       0,     0,    10,   128,    14,     0,     0,   139,     0,    48,
     165,   152,   128,   112,   111,   117,   119,    39,     0,   139,
     139,     0,     0,   139,   139,   139,     0,   128,    59,    61,
       0,     0,    52,     0,     0,     0,    52,     0,     0,     0,
      52,     0,     0,     0,    52,     0,     0,     0,    52,     0,
       0,     0,    56,     0,    56,     0,    56,     0,     9,    50,
     152,     0,   139,   139,   128,     0,     0,     0,   139,     0,
       0,   139,     0,     0,     0,   164,    63,   128,    51,   171,
       0,    68,    97,     0,    83,     0,    92,     0,     0,    70,
      98,    85,    93,     0,    72,   100,    86,    95,     0,    69,
      96,    84,    91,     0,    71,     0,    99,    90,     0,    94,
      80,    87,    81,    88,    82,    89,   164,     0,     0,   128,
     138,   128,     0,     0,     0,   139,     0,   155,     0,   126,
     120,   121,   122,   132,    62,   106,   107,   103,   104,   105,
      53,    54,    57,     0,   106,   103,   103,   104,   105,   107,
       0,     0,   164,    49,   136,   113,   135,   110,     0,     0,
       0,   139,     0,    74,     0,     0,    75,    73,    77,    78,
      76,    66,     0,   131,   115,   114,     0,   125,   128,    55,
     102,    79,     0,   116,   124,    39,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -304,  -304,  -304,   -32,  -304,    26,  -304,  -304,  -304,  -304,
    -304,  -304,   524,    -5,   -31,   -62,   450,    52,   -30,  -304,
    -304,  -304,  -304,   373,  -304,   -70,    75,   133,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,   -90,  -304,  -304,  -304,  -102,
    -303,  -304,  -304,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    36,    64,    98,   141,    39,    38,    29,
      12,    13,    14,    23,    99,    67,    68,   223,   224,    69,
     108,   109,   218,    82,   240,    83,   225,   330,    70,    71,
     259,    72,    73,    74,   318,    75,    76,    77,    78,    79,
     204,   254,   255,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    93,   160,    66,   117,   148,    85,    86,   139,   347,
     100,   102,   140,    10,     1,   107,   217,    34,   154,   111,
     112,   155,    94,    33,   129,   130,     5,    95,    35,    96,
       8,    81,    84,   115,   165,   293,   294,   117,     6,    81,
     295,   166,   159,     2,     7,    91,   365,    11,   209,     2,
     156,   207,   147,   117,   149,   210,    95,     9,   143,   152,
      65,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   216,    26,   158,   257,   258,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   203,
     114,   206,   142,   140,   140,    24,   117,    95,    28,   143,
     195,   196,   219,    25,    40,    41,   351,   251,   193,   194,
      27,    95,    30,   143,    87,   212,    43,    92,    45,    46,
      47,    48,    49,   220,   221,   325,   326,   327,   328,   329,
      10,   117,    15,    16,    17,    18,    19,    20,    21,    22,
      89,   270,   271,    32,    59,    37,    90,   101,   278,   279,
      61,    81,    62,   104,    63,   228,   232,   236,   103,   243,
     245,   247,   307,   105,    40,    41,   110,   147,   260,   272,
     273,   262,   263,   264,    42,   113,    43,    44,    45,    46,
      47,    48,    49,   274,   275,   118,   267,   127,   128,   129,
     130,     2,    50,   144,    52,   276,   277,    53,    54,    55,
      56,    57,   145,    58,    59,   117,    60,   280,   273,   169,
      61,   308,    62,   161,    63,    81,   313,   281,   275,   319,
     282,   277,   166,   309,   184,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   227,   231,   235,
     239,    40,    41,   283,   284,   185,   364,   117,   186,   345,
     187,    42,   188,    43,    44,    45,    46,    47,    48,    49,
     229,   233,   237,   241,   373,   189,   375,   190,     2,    50,
      51,    52,   167,   350,    53,    54,    55,    56,    57,   191,
      58,    59,   198,    60,    40,    41,   197,    61,   208,    62,
     200,    63,   285,   273,    42,   211,    43,    44,    45,    46,
      47,    48,    49,   286,   275,   222,   374,   287,   277,   367,
     214,     2,    50,    97,    52,   288,   289,    53,    54,    55,
      56,    57,   215,    58,    59,   226,    60,    40,    41,   230,
      61,   234,    62,   238,    63,   290,   273,    42,   242,    43,
      44,    45,    46,    47,    48,    49,   334,   326,   335,   328,
     329,   291,   275,   244,     2,    50,   116,    52,   292,   277,
      53,    54,    55,    56,    57,   246,    58,    59,   252,    60,
      40,    41,   253,    61,   256,    62,   142,    63,   296,   273,
      42,   300,    43,    44,    45,    46,    47,    48,    49,   325,
     326,   336,   328,   329,   297,   298,   165,     2,    50,   150,
      52,   299,   277,    53,    54,    55,    56,    57,   265,    58,
      59,   302,    60,    40,    41,   304,    61,   310,    62,   306,
      63,   301,   275,    42,   311,    43,    44,    45,    46,    47,
      48,    49,   325,   326,   335,   337,   338,   303,   275,   312,
       2,    50,   170,    52,   305,   275,    53,    54,    55,    56,
      57,   323,    58,    59,   331,    60,    40,    41,   332,    61,
     333,    62,   340,    63,   314,   315,    42,   341,    43,    44,
      45,    46,    47,    48,    49,   325,   339,   335,   328,   329,
     346,   163,   164,     2,    50,   192,    52,   369,   370,    53,
      54,    55,    56,    57,   349,    58,    59,   342,    60,    40,
      41,   353,    61,   354,    62,   352,    63,   355,   361,    42,
     356,    43,    44,    45,    46,    47,    48,    49,   325,   326,
     335,   328,   329,   357,   358,   359,     2,    50,   248,    52,
     360,   362,    53,    54,    55,    56,    57,   363,    58,    59,
      50,    60,    40,    41,   368,    61,   371,    62,   372,    63,
      31,     0,    42,   157,    43,    44,    45,    46,    47,    48,
      49,     0,   376,     0,     0,     0,     0,     0,     0,     2,
      50,   266,    52,     0,     0,    53,    54,    55,    56,    57,
       0,    58,    59,     0,    60,    40,    41,     0,    61,     0,
      62,     0,    63,     0,     0,    42,     0,    43,    44,    45,
      46,    47,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     2,    50,   324,    52,     0,     0,    53,    54,
      55,    56,    57,     0,    58,    59,     0,    60,    40,    41,
       0,    61,     0,    62,     0,    63,     0,     0,    42,     0,
      43,    44,    45,    46,    47,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     2,    50,   344,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    58,    59,     0,
      60,    40,    41,     0,    61,     0,    62,     0,    63,     0,
       0,    42,     0,    43,    44,    45,    46,    47,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     2,    50,
       0,    52,     0,     0,    53,    54,    55,    56,    57,     0,
      58,    59,     0,    60,    40,    41,     0,    61,     0,    62,
       0,    63,     0,     0,    42,     0,    43,    44,    45,    46,
      47,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     2,   202,     0,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,     0,    60,    40,    41,     0,
      61,     0,    62,     0,    63,     0,     0,    42,     0,    43,
      44,    45,    46,    47,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    50,     0,    52,     0,     0,
     213,    54,    55,    56,    57,     0,    58,    59,     0,    60,
      40,    41,     0,    61,     0,    62,     0,    63,     0,     0,
      87,     0,    43,    92,    45,    46,    47,    48,    49,     0,
       0,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,    89,     0,     0,     0,
      59,     0,    90,     0,   106,     0,    61,     0,    62,     0,
      63,    40,    41,   131,   132,   133,   134,   135,   136,   137,
     138,    87,     0,    43,    92,    45,    46,    47,    48,    49,
     168,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,     0,    89,     0,     0,
       0,    59,     0,    90,    40,    41,     0,    61,  -128,    62,
       0,    63,     0,     0,    87,     0,    43,    88,    45,    46,
      47,    48,    49,     0,     0,     0,     0,     0,     0,     0,
     201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,    59,     0,    90,    40,    41,     0,
      61,     0,    62,     0,    63,     0,     0,    87,     0,    43,
      92,    45,    46,    47,    48,    49,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,     0,     0,    89,     0,     0,     0,    59,     0,    90,
      40,    41,     0,    61,     0,    62,     0,    63,     0,     0,
      87,     0,    43,    92,    45,    46,    47,    48,    49,     0,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,     0,     0,     0,
      59,     0,    90,    40,    41,     0,    61,     0,    62,     0,
      63,     0,     0,    87,     0,    43,   317,    45,    46,    47,
      48,    49,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,    89,
       0,     0,     0,    59,     0,    90,     0,     0,     0,    61,
       0,    62,     0,    63,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,   269,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,   316,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   153,   320,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   162,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,   199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   321,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   343,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,   153,    43,
      92,    45,    46,    47,    48,    49,     0,     0,     0,     0,
     348,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   366,    89,     0,     0,     0,    59,     0,    90,
       0,     0,     0,    61,     0,    62,     0,    63,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130
};

static const yytype_int16 yycheck[] =
{
      42,    43,   104,    34,    66,    95,    38,    39,    31,   312,
      52,    53,    82,    16,     1,    57,    31,    31,    13,    61,
      62,    16,    44,    28,    13,    14,     0,    49,    42,    51,
       4,    54,    37,    64,    44,    46,    47,    99,    16,    54,
      51,    51,   104,    30,     0,    87,   349,    50,    44,    30,
      45,   153,    94,   115,    96,    51,    49,    49,    51,   101,
      34,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,   161,    47,   104,    34,    35,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   151,
      64,   153,    44,   163,   164,    46,   158,    49,    41,    51,
     142,   143,   164,    50,     3,     4,    44,   197,   139,   141,
      46,    49,    46,    51,    13,   157,    15,    16,    17,    18,
      19,    20,    21,   165,   166,    17,    18,    19,    20,    21,
      16,   193,    22,    23,    24,    25,    26,    27,    28,    29,
      39,    46,    47,    16,    43,    41,    45,    46,    46,    47,
      49,    54,    51,    46,    53,   185,   186,   187,    49,   189,
     190,   191,   252,    16,     3,     4,    16,   209,   210,    47,
      48,   213,   214,   215,    13,    16,    15,    16,    17,    18,
      19,    20,    21,    47,    48,    48,   217,    11,    12,    13,
      14,    30,    31,    16,    33,    47,    48,    36,    37,    38,
      39,    40,    16,    42,    43,   267,    45,    47,    48,    53,
      49,   253,    51,    49,    53,    54,   258,    47,    48,   261,
      47,    48,    51,   254,    46,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   185,   186,   187,
     188,     3,     4,    46,    47,    46,   348,   309,    46,   311,
      46,    13,    46,    15,    16,    17,    18,    19,    20,    21,
     185,   186,   187,   188,   366,    46,   368,    46,    30,    31,
      32,    33,    50,   315,    36,    37,    38,    39,    40,    46,
      42,    43,    16,    45,     3,     4,    49,    49,    16,    51,
      50,    53,    47,    48,    13,    16,    15,    16,    17,    18,
      19,    20,    21,    47,    48,    16,   368,    47,    48,   351,
      36,    30,    31,    32,    33,    46,    47,    36,    37,    38,
      39,    40,    36,    42,    43,    16,    45,     3,     4,    16,
      49,    16,    51,    16,    53,    47,    48,    13,    16,    15,
      16,    17,    18,    19,    20,    21,    17,    18,    19,    20,
      21,    47,    48,    16,    30,    31,    32,    33,    47,    48,
      36,    37,    38,    39,    40,    16,    42,    43,    49,    45,
       3,     4,    44,    49,    34,    51,    44,    53,    47,    48,
      13,    47,    15,    16,    17,    18,    19,    20,    21,    17,
      18,    19,    20,    21,    47,    48,    44,    30,    31,    32,
      33,    47,    48,    36,    37,    38,    39,    40,    50,    42,
      43,    47,    45,     3,     4,    47,    49,    32,    51,    50,
      53,    47,    48,    13,    46,    15,    16,    17,    18,    19,
      20,    21,    17,    18,    19,    20,    21,    47,    48,    46,
      30,    31,    32,    33,    47,    48,    36,    37,    38,    39,
      40,    47,    42,    43,    16,    45,     3,     4,    16,    49,
      16,    51,    19,    53,    34,    35,    13,    16,    15,    16,
      17,    18,    19,    20,    21,    17,    18,    19,    20,    21,
      31,   108,   109,    30,    31,    32,    33,   354,   355,    36,
      37,    38,    39,    40,    46,    42,    43,    50,    45,     3,
       4,    47,    49,    46,    51,    50,    53,    46,    52,    13,
      47,    15,    16,    17,    18,    19,    20,    21,    17,    18,
      19,    20,    21,    47,    47,    47,    30,    31,    32,    33,
      47,    51,    36,    37,    38,    39,    40,    47,    42,    43,
      31,    45,     3,     4,    46,    49,    47,    51,    19,    53,
      26,    -1,    13,   103,    15,    16,    17,    18,    19,    20,
      21,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    42,    43,    -1,    45,     3,     4,    -1,    49,    -1,
      51,    -1,    53,    -1,    -1,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    42,    43,    -1,    45,     3,     4,
      -1,    49,    -1,    51,    -1,    53,    -1,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    42,    43,    -1,
      45,     3,     4,    -1,    49,    -1,    51,    -1,    53,    -1,
      -1,    13,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      42,    43,    -1,    45,     3,     4,    -1,    49,    -1,    51,
      -1,    53,    -1,    -1,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    42,    43,    -1,    45,     3,     4,    -1,
      49,    -1,    51,    -1,    53,    -1,    -1,    13,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    38,    39,    40,    -1,    42,    43,    -1,    45,
       3,     4,    -1,    49,    -1,    51,    -1,    53,    -1,    -1,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      43,    -1,    45,    -1,    47,    -1,    49,    -1,    51,    -1,
      53,     3,     4,    22,    23,    24,    25,    26,    27,    28,
      29,    13,    -1,    15,    16,    17,    18,    19,    20,    21,
      52,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    43,    -1,    45,     3,     4,    -1,    49,    50,    51,
      -1,    53,    -1,    -1,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    43,    -1,    45,     3,     4,    -1,
      49,    -1,    51,    -1,    53,    -1,    -1,    13,    -1,    15,
      16,    17,    18,    19,    20,    21,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,    45,
       3,     4,    -1,    49,    -1,    51,    -1,    53,    -1,    -1,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      43,    -1,    45,     3,     4,    -1,    49,    -1,    51,    -1,
      53,    -1,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    43,    -1,    45,    -1,    -1,    -1,    49,
      -1,    51,    -1,    53,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    52,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    39,    -1,    -1,    -1,    43,    -1,    45,
      -1,    -1,    -1,    49,    -1,    51,    -1,    53,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    30,    56,    57,    60,    16,     0,    60,    49,
      16,    50,    65,    66,    67,    22,    23,    24,    25,    26,
      27,    28,    29,    68,    46,    50,    47,    46,    41,    64,
      46,    67,    16,    68,    31,    42,    58,    41,    63,    62,
       3,     4,    13,    15,    16,    17,    18,    19,    20,    21,
      31,    32,    33,    36,    37,    38,    39,    40,    42,    43,
      45,    49,    51,    53,    59,    60,    69,    70,    71,    74,
      83,    84,    86,    87,    88,    90,    91,    92,    93,    94,
      98,    54,    78,    80,    68,    58,    58,    13,    16,    39,
      45,    98,    16,    98,    44,    49,    51,    32,    60,    69,
      98,    46,    98,    49,    46,    16,    47,    98,    75,    76,
      16,    98,    98,    16,    60,    69,    32,    70,    48,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    22,    23,    24,    25,    26,    27,    28,    29,    31,
      80,    61,    44,    51,    16,    16,    39,    98,    90,    98,
      32,    46,    98,    46,    13,    16,    45,    71,    69,    70,
      94,    49,    47,    78,    78,    44,    51,    50,    52,    53,
      32,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    46,    46,    46,    46,    46,    46,
      46,    46,    32,    69,    58,    98,    98,    49,    16,    47,
      50,    52,    31,    70,    95,    47,    70,    94,    16,    44,
      51,    16,    98,    36,    36,    36,    90,    31,    77,    70,
      98,    98,    16,    72,    73,    81,    16,    72,    73,    81,
      16,    72,    73,    81,    16,    72,    73,    81,    16,    72,
      79,    81,    16,    73,    16,    73,    16,    73,    32,    47,
      52,    90,    49,    44,    96,    97,    34,    34,    35,    85,
      98,    47,    98,    98,    98,    50,    32,    69,    47,    52,
      46,    47,    47,    48,    47,    48,    47,    48,    46,    47,
      47,    47,    47,    46,    47,    47,    47,    47,    46,    47,
      47,    47,    47,    46,    47,    51,    47,    47,    48,    47,
      47,    47,    47,    47,    47,    47,    50,    90,    98,    69,
      32,    46,    46,    98,    34,    35,    52,    16,    89,    98,
      47,    47,    47,    47,    32,    17,    18,    19,    20,    21,
      82,    16,    16,    16,    17,    19,    19,    20,    21,    18,
      19,    16,    50,    47,    32,    70,    31,    95,    46,    46,
      98,    44,    50,    47,    46,    46,    47,    47,    47,    47,
      47,    52,    51,    47,    94,    95,    46,    98,    46,    82,
      82,    47,    19,    94,    70,    94,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    59,    59,    61,    60,    62,    60,    63,    60,    64,
      60,    65,    65,    66,    66,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      71,    71,    72,    72,    72,    72,    73,    73,    75,    74,
      76,    74,    77,    77,    78,    78,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    83,    83,
      84,    84,    84,    84,    84,    85,    85,    86,    86,    86,
      87,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    93,    94,    94,    96,    95,    97,    95,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     3,     4,     2,     5,
       4,     2,     1,     0,    10,     0,     9,     0,     8,     0,
       7,     1,     0,     3,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     7,
       5,     5,     1,     3,     3,     5,     1,     3,     0,     4,
       0,     4,     3,     2,     2,     1,     4,     6,     5,     5,
       5,     5,     5,     7,     7,     7,     7,     7,     7,     8,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     3,     5,     1,     1,     1,     1,     1,     3,     2,
       7,     4,     4,     7,     8,     4,     5,     4,     4,     4,
       6,     6,     6,     9,     9,     3,     1,     1,     0,     3,
       1,     8,     6,     3,     2,     0,     4,     0,     3,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     3,     3,     2,     2,
       2,     5
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
#line 58 "parser.y"
              {
         program_ast = (yyvsp[0].ast);
        print_ast((yyvsp[0].ast), 0);
    }
#line 1647 "parser.tab.c"
    break;

  case 3: /* program: error  */
#line 62 "parser.y"
          {
        yyerror("Could not parse input");
    }
#line 1655 "parser.tab.c"
    break;

  case 4: /* func_list: func_list function  */
#line 68 "parser.y"
                       { (yyval.ast) = make_node("CODE", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1661 "parser.tab.c"
    break;

  case 5: /* func_list: function  */
#line 69 "parser.y"
             { (yyval.ast) = make_node("CODE", 1, (yyvsp[0].ast)); }
#line 1667 "parser.tab.c"
    break;

  case 6: /* function_body: T_BEGIN stmt_list T_END  */
#line 72 "parser.y"
                            { (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); }
#line 1673 "parser.tab.c"
    break;

  case 7: /* function_body: T_BEGIN nested_func_list stmt_list T_END  */
#line 73 "parser.y"
                                             { (yyval.ast) = make_node("BLOCK", 2, (yyvsp[-2].ast), (yyvsp[-1].ast)); }
#line 1679 "parser.tab.c"
    break;

  case 8: /* function_body: T_BEGIN T_END  */
#line 74 "parser.y"
                  { (yyval.ast) = make_node("BLOCK", 0); }
#line 1685 "parser.tab.c"
    break;

  case 9: /* function_body: VAR type_decls T_BEGIN stmt_list T_END  */
#line 75 "parser.y"
                                            { 
        (yyval.ast) = make_node("VAR_BLOCK", 2, (yyvsp[-3].ast), make_node("BLOCK", 1, (yyvsp[-1].ast))); 
    }
#line 1693 "parser.tab.c"
    break;

  case 10: /* function_body: VAR type_decls T_BEGIN T_END  */
#line 78 "parser.y"
                                 { 
        (yyval.ast) = make_node("VAR_BLOCK", 2, (yyvsp[-2].ast), make_node("BLOCK", 0)); 
    }
#line 1701 "parser.tab.c"
    break;

  case 11: /* nested_func_list: nested_func_list function  */
#line 83 "parser.y"
                              { (yyval.ast) = make_node("", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1707 "parser.tab.c"
    break;

  case 12: /* nested_func_list: function  */
#line 84 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1713 "parser.tab.c"
    break;

  case 13: /* $@1: %empty  */
#line 87 "parser.y"
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
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, (yyvsp[-6].sval));
        //enter_scope();
    }
#line 1752 "parser.tab.c"
    break;

  case 14: /* function: DEF ID LPAREN par_list RPAREN COLON RETURNS type $@1 function_body  */
#line 120 "parser.y"
                    {
         //exit_scope();
        inside_main = 0;
        current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-8].sval), 0),
             (yyvsp[-6].ast),
             make_node("RET", 1, (yyvsp[-2].ast)),
             make_node("BODY", 1, (yyvsp[0].ast)));
              exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", (yyvsp[-8].sval), current_scope);
    }
#line 1770 "parser.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 134 "parser.y"
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
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, (yyvsp[-5].sval));
        //enter_scope();
    }
#line 1803 "parser.tab.c"
    break;

  case 16: /* function: DEF ID LPAREN RPAREN COLON RETURNS type $@2 function_body  */
#line 161 "parser.y"
                    {
         //exit_scope();
        inside_main = 0;
        current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-7].sval), 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, (yyvsp[-2].ast)),
             make_node("BODY", 1, (yyvsp[0].ast)));
                   exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", (yyvsp[-7].sval), current_scope);
    }
#line 1821 "parser.tab.c"
    break;

  case 17: /* $@3: %empty  */
#line 175 "parser.y"
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
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, (yyvsp[-4].sval));
        //enter_scope();
    }
#line 1854 "parser.tab.c"
    break;

  case 18: /* function: DEF ID LPAREN par_list RPAREN COLON $@3 function_body  */
#line 202 "parser.y"
                    {
         //exit_scope();
        inside_main = 0;
        current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-6].sval), 0),
             (yyvsp[-4].ast),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, (yyvsp[0].ast)));
                   exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", (yyvsp[-6].sval), current_scope);
    }
#line 1872 "parser.tab.c"
    break;

  case 19: /* $@4: %empty  */
#line 216 "parser.y"
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
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, (yyvsp[-3].sval));
       // enter_scope();
    }
#line 1899 "parser.tab.c"
    break;

  case 20: /* function: DEF ID LPAREN RPAREN COLON $@4 function_body  */
#line 237 "parser.y"
                    {
        // exit_scope();
        inside_main = 0;
         current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-5].sval), 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, (yyvsp[0].ast)));
                    exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", (yyvsp[-5].sval), current_scope);

    }
#line 1918 "parser.tab.c"
    break;

  case 21: /* par_list: param_list_item_list  */
#line 254 "parser.y"
                         { (yyval.ast) = make_node("ARGS", 1, (yyvsp[0].ast)); }
#line 1924 "parser.tab.c"
    break;

  case 22: /* par_list: %empty  */
#line 255 "parser.y"
                { (yyval.ast) = make_node("ARGS", 1, make_node("NONE", 0)); }
#line 1930 "parser.tab.c"
    break;

  case 23: /* param_list_item_list: param_list_item_list SEMICOLON par_list_item  */
#line 259 "parser.y"
                                                 {
        (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1938 "parser.tab.c"
    break;

  case 24: /* param_list_item_list: par_list_item  */
#line 262 "parser.y"
                  {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1946 "parser.tab.c"
    break;

  case 25: /* par_list_item: ID type COLON ID  */
#line 269 "parser.y"
                     {
        current_param_index++;
        
        check_param_order((yyvsp[-3].sval), current_param_index);
        
        insert_symbol((yyvsp[0].sval), VAR_SYM, get_type_from_name((yyvsp[-2].ast)->name));
        printf("  Inserted parameter '%s' as variable in scope %d\n", (yyvsp[0].sval), current_scope);
        
    
              (yyval.ast) = make_node((yyvsp[-3].sval), 2,
          make_node((yyvsp[-2].ast)->name, 0),
            make_node((yyvsp[0].sval),      0));
    }
#line 1964 "parser.tab.c"
    break;

  case 26: /* type: TYPE_INT  */
#line 284 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1970 "parser.tab.c"
    break;

  case 27: /* type: TYPE_CHAR  */
#line 285 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1976 "parser.tab.c"
    break;

  case 28: /* type: TYPE_REAL  */
#line 286 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1982 "parser.tab.c"
    break;

  case 29: /* type: TYPE_BOOL  */
#line 287 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1988 "parser.tab.c"
    break;

  case 30: /* type: TYPE_STRING  */
#line 288 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1994 "parser.tab.c"
    break;

  case 31: /* type: TYPE_INT_PTR  */
#line 289 "parser.y"
                 { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2000 "parser.tab.c"
    break;

  case 32: /* type: TYPE_CHAR_PTR  */
#line 290 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2006 "parser.tab.c"
    break;

  case 33: /* type: TYPE_REAL_PTR  */
#line 291 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2012 "parser.tab.c"
    break;

  case 34: /* stmt_list: stmt_list stmt  */
#line 295 "parser.y"
                   { 
        printf("DEBUG: Processing stmt_list + stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = make_node("", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); 
    }
#line 2021 "parser.tab.c"
    break;

  case 35: /* stmt_list: stmt  */
#line 299 "parser.y"
           { 
        printf("DEBUG: Processing solo stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = (yyvsp[0].ast); 
    }
#line 2030 "parser.tab.c"
    break;

  case 48: /* assignment: ID ASSIGN expr SEMICOLON  */
#line 321 "parser.y"
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
#line 2062 "parser.tab.c"
    break;

  case 49: /* assignment: ID LBRACK expr RBRACK ASSIGN expr SEMICOLON  */
#line 348 "parser.y"
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
#line 2091 "parser.tab.c"
    break;

  case 50: /* assignment: MULT ID ASSIGN expr SEMICOLON  */
#line 372 "parser.y"
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
#line 2125 "parser.tab.c"
    break;

  case 51: /* assignment: ADDRESS ID ASSIGN expr SEMICOLON  */
#line 401 "parser.y"
                                       {
        yyerror("Semantic Error: Cannot use address operator on left side of assignment");
        (yyval.ast) = make_node("error", 2, make_node("&", 1, make_node((yyvsp[-3].sval), 0)), (yyvsp[-1].ast));
   }
#line 2134 "parser.tab.c"
    break;

  case 52: /* mixed_id_list: ID  */
#line 407 "parser.y"
       {
        (yyval.ast) = make_node((yyvsp[0].sval), 0);  /* משתנה ללא ערך התחלה */
    }
#line 2142 "parser.tab.c"
    break;

  case 53: /* mixed_id_list: ID COLON literal  */
#line 410 "parser.y"
                       {
        (yyval.ast) = make_node((yyvsp[-2].sval), 1, (yyvsp[0].ast));  /* משתנה עם ערך התחלה */
    }
#line 2150 "parser.tab.c"
    break;

  case 54: /* mixed_id_list: mixed_id_list COMMA ID  */
#line 413 "parser.y"
                             {
        (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), make_node((yyvsp[0].sval), 0));  /* הוספת משתנה ללא ערך */
    }
#line 2158 "parser.tab.c"
    break;

  case 55: /* mixed_id_list: mixed_id_list COMMA ID COLON literal  */
#line 416 "parser.y"
                                           {
        (yyval.ast) = make_node("", 2, (yyvsp[-4].ast), make_node((yyvsp[-2].sval), 1, (yyvsp[0].ast)));  /* הוספת משתנה עם ערך */
    }
#line 2166 "parser.tab.c"
    break;

  case 56: /* id_list: ID  */
#line 421 "parser.y"
                                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2172 "parser.tab.c"
    break;

  case 57: /* id_list: id_list COMMA ID  */
#line 422 "parser.y"
                               { (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), make_node((yyvsp[0].sval), 0)); }
#line 2178 "parser.tab.c"
    break;

  case 58: /* $@5: %empty  */
#line 427 "parser.y"
        {
        enter_scope();
        printf("DEBUG: Entered VAR scope %d\n", current_scope);
    }
#line 2187 "parser.tab.c"
    break;

  case 59: /* var_stmt: VAR $@5 type_decls block_content  */
#line 430 "parser.y"
                               {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 2195 "parser.tab.c"
    break;

  case 60: /* $@6: %empty  */
#line 433 "parser.y"
        {
        enter_scope();
        printf("DEBUG: Entered VAR scope %d\n", current_scope);
    }
#line 2204 "parser.tab.c"
    break;

  case 61: /* var_stmt: VAR $@6 type_decls stmt  */
#line 436 "parser.y"
                      {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
        exit_scope();
        printf("DEBUG: Exited VAR scope\n");
    }
#line 2214 "parser.tab.c"
    break;

  case 62: /* block_content: T_BEGIN stmt_list T_END  */
#line 443 "parser.y"
                            {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
        exit_scope();
        printf("DEBUG: Exited VAR scope from block_content\n");
    }
#line 2224 "parser.tab.c"
    break;

  case 63: /* block_content: T_BEGIN T_END  */
#line 448 "parser.y"
                    {
        (yyval.ast) = make_node("BLOCK", 0); 
        exit_scope();
        printf("DEBUG: Exited VAR scope from empty block_content\n");
    }
#line 2234 "parser.tab.c"
    break;

  case 64: /* type_decls: type_decls type_decl  */
#line 455 "parser.y"
                         {
        (yyval.ast) = make_node("DECLS", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 2242 "parser.tab.c"
    break;

  case 65: /* type_decls: type_decl  */
#line 458 "parser.y"
              {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2250 "parser.tab.c"
    break;

  case 66: /* string_id_list: ID LBRACK NUM RBRACK  */
#line 463 "parser.y"
                         {
        (yyval.ast) = make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0));
    }
#line 2258 "parser.tab.c"
    break;

  case 67: /* string_id_list: string_id_list COMMA ID LBRACK NUM RBRACK  */
#line 466 "parser.y"
                                                {
        (yyval.ast) = make_node("", 2, (yyvsp[-5].ast), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2266 "parser.tab.c"
    break;

  case 68: /* type_decl: TYPE TYPE_INT COLON ID SEMICOLON  */
#line 471 "parser.y"
                                     {
        insert_checked_variable((yyvsp[-1].sval), DT_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2275 "parser.tab.c"
    break;

  case 69: /* type_decl: TYPE TYPE_BOOL COLON ID SEMICOLON  */
#line 475 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2284 "parser.tab.c"
    break;

  case 70: /* type_decl: TYPE TYPE_CHAR COLON ID SEMICOLON  */
#line 479 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2293 "parser.tab.c"
    break;

  case 71: /* type_decl: TYPE TYPE_STRING COLON ID SEMICOLON  */
#line 483 "parser.y"
                                        {
        insert_checked_variable((yyvsp[-1].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2302 "parser.tab.c"
    break;

  case 72: /* type_decl: TYPE TYPE_REAL COLON ID SEMICOLON  */
#line 487 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2311 "parser.tab.c"
    break;

  case 73: /* type_decl: TYPE TYPE_REAL COLON ID COLON NUM SEMICOLON  */
#line 491 "parser.y"
                                                  {
        insert_checked_variable((yyvsp[-3].sval), DT_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real", 0), make_node((yyvsp[-3].sval), 1,make_node((yyvsp[-1].sval),0)));
    }
#line 2320 "parser.tab.c"
    break;

  case 74: /* type_decl: TYPE TYPE_INT COLON ID COLON NUM SEMICOLON  */
#line 495 "parser.y"
                                               {
        insert_checked_variable((yyvsp[-3].sval), DT_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2329 "parser.tab.c"
    break;

  case 75: /* type_decl: TYPE TYPE_CHAR COLON ID COLON CHAR_LITERAL SEMICOLON  */
#line 499 "parser.y"
                                                         {
        insert_checked_variable((yyvsp[-3].sval), DT_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2338 "parser.tab.c"
    break;

  case 76: /* type_decl: TYPE TYPE_STRING COLON ID COLON STRING_LITERAL SEMICOLON  */
#line 503 "parser.y"
                                                             {
        insert_checked_variable((yyvsp[-3].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2347 "parser.tab.c"
    break;

  case 77: /* type_decl: TYPE TYPE_BOOL COLON ID COLON TRUE SEMICOLON  */
#line 507 "parser.y"
                                                 {
        insert_checked_variable((yyvsp[-3].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-3].sval), 1, make_node("true", 0)));
    }
#line 2356 "parser.tab.c"
    break;

  case 78: /* type_decl: TYPE TYPE_BOOL COLON ID COLON FALSE SEMICOLON  */
#line 511 "parser.y"
                                                  {
        insert_checked_variable((yyvsp[-3].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-3].sval), 1, make_node("false", 0)));
    }
#line 2365 "parser.tab.c"
    break;

  case 79: /* type_decl: TYPE TYPE_STRING COLON ID LBRACK NUM RBRACK SEMICOLON  */
#line 515 "parser.y"
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
#line 2380 "parser.tab.c"
    break;

  case 80: /* type_decl: TYPE TYPE_INT_PTR COLON ID SEMICOLON  */
#line 525 "parser.y"
                                           {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2389 "parser.tab.c"
    break;

  case 81: /* type_decl: TYPE TYPE_CHAR_PTR COLON ID SEMICOLON  */
#line 529 "parser.y"
                                          {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2398 "parser.tab.c"
    break;

  case 82: /* type_decl: TYPE TYPE_REAL_PTR COLON ID SEMICOLON  */
#line 533 "parser.y"
                                          {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2407 "parser.tab.c"
    break;

  case 83: /* type_decl: TYPE TYPE_INT COLON id_list SEMICOLON  */
#line 538 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_INT);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("int", 0), (yyvsp[-1].ast));
    }
#line 2416 "parser.tab.c"
    break;

  case 84: /* type_decl: TYPE TYPE_BOOL COLON id_list SEMICOLON  */
#line 542 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_BOOL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("bool", 0), (yyvsp[-1].ast));
    }
#line 2425 "parser.tab.c"
    break;

  case 85: /* type_decl: TYPE TYPE_CHAR COLON id_list SEMICOLON  */
#line 546 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_CHAR);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("char", 0), (yyvsp[-1].ast));
    }
#line 2434 "parser.tab.c"
    break;

  case 86: /* type_decl: TYPE TYPE_REAL COLON id_list SEMICOLON  */
#line 550 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_REAL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("real", 0), (yyvsp[-1].ast));
    }
#line 2443 "parser.tab.c"
    break;

  case 87: /* type_decl: TYPE TYPE_INT_PTR COLON id_list SEMICOLON  */
#line 554 "parser.y"
                                              {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_INT);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("int*", 0), (yyvsp[-1].ast));
    }
#line 2452 "parser.tab.c"
    break;

  case 88: /* type_decl: TYPE TYPE_CHAR_PTR COLON id_list SEMICOLON  */
#line 558 "parser.y"
                                               {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_CHAR);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("char*", 0), (yyvsp[-1].ast));
    }
#line 2461 "parser.tab.c"
    break;

  case 89: /* type_decl: TYPE TYPE_REAL_PTR COLON id_list SEMICOLON  */
#line 562 "parser.y"
                                               {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_REAL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("real*", 0), (yyvsp[-1].ast));
    }
#line 2470 "parser.tab.c"
    break;

  case 90: /* type_decl: TYPE TYPE_STRING COLON string_id_list SEMICOLON  */
#line 566 "parser.y"
                                                  {
        add_multiple_string_arrays((yyvsp[-1].ast));
        (yyval.ast) = make_node("TYPE_STRING_MULTI", 2, make_node("string", 0), (yyvsp[-1].ast));
    }
#line 2479 "parser.tab.c"
    break;

  case 91: /* type_decl: TYPE TYPE_BOOL COLON id_value_list SEMICOLON  */
#line 570 "parser.y"
                                               {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_BOOL);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("bool", 0), (yyvsp[-1].ast));
}
#line 2488 "parser.tab.c"
    break;

  case 92: /* type_decl: TYPE TYPE_INT COLON id_value_list SEMICOLON  */
#line 574 "parser.y"
                                              {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_INT);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("int", 0), (yyvsp[-1].ast));
}
#line 2497 "parser.tab.c"
    break;

  case 93: /* type_decl: TYPE TYPE_CHAR COLON id_value_list SEMICOLON  */
#line 578 "parser.y"
                                               {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_CHAR);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("char", 0), (yyvsp[-1].ast));
}
#line 2506 "parser.tab.c"
    break;

  case 94: /* type_decl: TYPE TYPE_STRING COLON id_value_list SEMICOLON  */
#line 582 "parser.y"
                                                 {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_STRING);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("string", 0), (yyvsp[-1].ast));
}
#line 2515 "parser.tab.c"
    break;

  case 95: /* type_decl: TYPE TYPE_REAL COLON id_value_list SEMICOLON  */
#line 586 "parser.y"
                                               {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_REAL);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("real", 0), (yyvsp[-1].ast));
}
#line 2524 "parser.tab.c"
    break;

  case 96: /* type_decl: TYPE TYPE_BOOL COLON mixed_id_list SEMICOLON  */
#line 589 "parser.y"
                                                {
        add_multiple_variables_mixed((yyvsp[-1].ast), DT_BOOL);
        (yyval.ast) = make_node("TYPE_MIXED", 2, make_node("bool", 0), (yyvsp[-1].ast));
    }
#line 2533 "parser.tab.c"
    break;

  case 97: /* type_decl: TYPE TYPE_INT COLON mixed_id_list SEMICOLON  */
#line 593 "parser.y"
                                                {
        add_multiple_variables_mixed((yyvsp[-1].ast), DT_INT);
        (yyval.ast) = make_node("TYPE_MIXED", 2, make_node("int", 0), (yyvsp[-1].ast));
    }
#line 2542 "parser.tab.c"
    break;

  case 98: /* type_decl: TYPE TYPE_CHAR COLON mixed_id_list SEMICOLON  */
#line 597 "parser.y"
                                                 {
        add_multiple_variables_mixed((yyvsp[-1].ast), DT_CHAR);
        (yyval.ast) = make_node("TYPE_MIXED", 2, make_node("char", 0), (yyvsp[-1].ast));
    }
#line 2551 "parser.tab.c"
    break;

  case 99: /* type_decl: TYPE TYPE_STRING COLON mixed_id_list SEMICOLON  */
#line 601 "parser.y"
                                                   {
        add_multiple_variables_mixed((yyvsp[-1].ast), DT_STRING);
        (yyval.ast) = make_node("TYPE_MIXED", 2, make_node("string", 0), (yyvsp[-1].ast));
    }
#line 2560 "parser.tab.c"
    break;

  case 100: /* type_decl: TYPE TYPE_REAL COLON mixed_id_list SEMICOLON  */
#line 605 "parser.y"
                                                 {
        add_multiple_variables_mixed((yyvsp[-1].ast), DT_REAL);
        (yyval.ast) = make_node("TYPE_MIXED", 2, make_node("real", 0), (yyvsp[-1].ast));
    }
#line 2569 "parser.tab.c"
    break;

  case 101: /* id_value_list: ID COLON literal  */
#line 612 "parser.y"
                       {
          (yyval.ast) = make_node((yyvsp[-2].sval), 1, (yyvsp[0].ast));  // $3 כבר AST
      }
#line 2577 "parser.tab.c"
    break;

  case 102: /* id_value_list: id_value_list COMMA ID COLON literal  */
#line 615 "parser.y"
                                           {
          (yyval.ast) = make_node("", 2, (yyvsp[-4].ast), make_node((yyvsp[-2].sval), 1, (yyvsp[0].ast)));
      }
#line 2585 "parser.tab.c"
    break;

  case 103: /* literal: NUM  */
#line 622 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2591 "parser.tab.c"
    break;

  case 104: /* literal: TRUE  */
#line 623 "parser.y"
                { (yyval.ast) = make_node("true", 0); }
#line 2597 "parser.tab.c"
    break;

  case 105: /* literal: FALSE  */
#line 624 "parser.y"
                { (yyval.ast) = make_node("false", 0); }
#line 2603 "parser.tab.c"
    break;

  case 106: /* literal: CHAR_LITERAL  */
#line 625 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2609 "parser.tab.c"
    break;

  case 107: /* literal: STRING_LITERAL  */
#line 626 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2615 "parser.tab.c"
    break;

  case 108: /* return_stmt: RETURN expr SEMICOLON  */
#line 631 "parser.y"
                          {
        printf("DEBUG: Processing return with value in function '%s'\n", current_function_name);

        
        check_return_type((yyvsp[-1].ast), current_function_name);
        
        (yyval.ast) = make_node("RETURN", 1, (yyvsp[-1].ast));
    }
#line 2628 "parser.tab.c"
    break;

  case 109: /* return_stmt: RETURN SEMICOLON  */
#line 639 "parser.y"
                     {
        printf("DEBUG: Processing empty return in function '%s'\n", current_function_name);
        
        check_return_type(make_node("NONE", 0), current_function_name);
        
        (yyval.ast) = make_node("RETURN", 1, make_node("NONE", 0));
    }
#line 2640 "parser.tab.c"
    break;

  case 110: /* if_stmt: IF expr COLON nested_block ELSE COLON nested_block  */
#line 650 "parser.y"
    {
        check_boolean_condition((yyvsp[-5].ast), "if");
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2649 "parser.tab.c"
    break;

  case 111: /* if_stmt: IF expr COLON nested_block  */
#line 655 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "if");
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2658 "parser.tab.c"
    break;

  case 112: /* if_stmt: IF expr COLON stmt  */
#line 660 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "if");
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2667 "parser.tab.c"
    break;

  case 113: /* if_stmt: IF expr COLON stmt ELSE COLON stmt  */
#line 665 "parser.y"
    {
        check_boolean_condition((yyvsp[-5].ast), "if");
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2676 "parser.tab.c"
    break;

  case 114: /* if_stmt: IF expr COLON nested_block elif_list ELSE COLON nested_block  */
#line 670 "parser.y"
    {
        check_boolean_condition((yyvsp[-6].ast), "if");
        (yyval.ast) = make_node("IF-ELIF-ELSE", 4, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2685 "parser.tab.c"
    break;

  case 115: /* elif_list: ELIF expr COLON block  */
#line 678 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "elif");
        (yyval.ast) = make_node("ELIF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2694 "parser.tab.c"
    break;

  case 116: /* elif_list: elif_list ELIF expr COLON block  */
#line 683 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "elif");
        (yyval.ast) = make_node("ELIF - ...", 3, (yyvsp[-4].ast), make_node("elif", 2, (yyvsp[-2].ast), (yyvsp[0].ast)));
    }
#line 2703 "parser.tab.c"
    break;

  case 117: /* while_stmt: WHILE COLON expr SEMICOLON  */
#line 690 "parser.y"
    {
        check_boolean_condition((yyvsp[-1].ast), "while");
        (yyval.ast) = make_node("while", 1, (yyvsp[-1].ast));
    }
#line 2712 "parser.tab.c"
    break;

  case 118: /* while_stmt: WHILE expr COLON block  */
#line 695 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "while");
        (yyval.ast) = make_node("while2", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2721 "parser.tab.c"
    break;

  case 119: /* while_stmt: WHILE expr COLON stmt  */
#line 700 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "while");
        (yyval.ast) = make_node("while2", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2730 "parser.tab.c"
    break;

  case 120: /* do_while_stmt: DO COLON stmt_list WHILE expr SEMICOLON  */
#line 706 "parser.y"
                                            {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2739 "parser.tab.c"
    break;

  case 121: /* do_while_stmt: DO COLON stmt WHILE expr SEMICOLON  */
#line 711 "parser.y"
                                       {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2748 "parser.tab.c"
    break;

  case 122: /* do_while_stmt: DO COLON block WHILE expr SEMICOLON  */
#line 716 "parser.y"
                                        {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2757 "parser.tab.c"
    break;

  case 123: /* for_stmt: FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON block  */
#line 723 "parser.y"
                                                                        {
        check_boolean_condition((yyvsp[-5].ast), "for"); 
        (yyval.ast) = make_node("for", 4, (yyvsp[-6].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2766 "parser.tab.c"
    break;

  case 124: /* for_stmt: FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON stmt  */
#line 728 "parser.y"
                                                                       {
        check_boolean_condition((yyvsp[-5].ast), "for"); 
        (yyval.ast) = make_node("for", 4, (yyvsp[-6].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2775 "parser.tab.c"
    break;

  case 125: /* update_expr: ID ASSIGN expr  */
#line 735 "parser.y"
                   {
        (yyval.ast) = make_node("=", 2, make_node((yyvsp[-2].sval), 0), (yyvsp[0].ast));
    }
#line 2783 "parser.tab.c"
    break;

  case 126: /* update_expr: expr  */
#line 738 "parser.y"
           {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2791 "parser.tab.c"
    break;

  case 127: /* call_args: call_list  */
#line 743 "parser.y"
              { (yyval.ast) = make_node("args", 1, (yyvsp[0].ast)); }
#line 2797 "parser.tab.c"
    break;

  case 128: /* call_args: %empty  */
#line 744 "parser.y"
                { (yyval.ast) = make_node("args", 1, make_node("none", 0)); }
#line 2803 "parser.tab.c"
    break;

  case 129: /* call_list: call_list COMMA expr  */
#line 749 "parser.y"
    {
        (yyval.ast)= make_node ("par",2,(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2811 "parser.tab.c"
    break;

  case 130: /* call_list: expr  */
#line 753 "parser.y"
    {
          (yyval.ast)= make_node ("par",1,(yyvsp[0].ast));
    }
#line 2819 "parser.tab.c"
    break;

  case 131: /* assignment_call: ID ASSIGN CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 760 "parser.y"
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
#line 2850 "parser.tab.c"
    break;

  case 132: /* void_call: CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 789 "parser.y"
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
#line 2879 "parser.tab.c"
    break;

  case 133: /* block: T_BEGIN stmt_list T_END  */
#line 816 "parser.y"
                            {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
    }
#line 2887 "parser.tab.c"
    break;

  case 134: /* block: T_BEGIN T_END  */
#line 819 "parser.y"
                    {
        (yyval.ast) = make_node("BLOCK", 0); 
    }
#line 2895 "parser.tab.c"
    break;

  case 135: /* $@7: %empty  */
#line 824 "parser.y"
            {
        enter_scope();
        printf("DEBUG: Entered nested block scope %d\n", current_scope);
    }
#line 2904 "parser.tab.c"
    break;

  case 136: /* nested_block: T_BEGIN $@7 stmt_list T_END  */
#line 827 "parser.y"
                      {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
        exit_scope();
        printf("DEBUG: Exited nested block scope\n");
    }
#line 2914 "parser.tab.c"
    break;

  case 137: /* $@8: %empty  */
#line 832 "parser.y"
              {
        enter_scope();
        printf("DEBUG: Entered nested block scope %d\n", current_scope);
    }
#line 2923 "parser.tab.c"
    break;

  case 138: /* nested_block: T_BEGIN $@8 T_END  */
#line 835 "parser.y"
            {
        (yyval.ast) = make_node("BLOCK", 0); 
        exit_scope();
        printf("DEBUG: Exited nested block scope\n");
    }
#line 2933 "parser.tab.c"
    break;

  case 140: /* expr: BAR ID BAR  */
#line 843 "parser.y"
             {
        Symbol* sym = lookup_any_scope((yyvsp[-1].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-1].sval));
            yyerror(error_msg);
        } else if (sym->type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Length operator |...| can only be used with string type, '%s' is of type %s", 
                    (yyvsp[-1].sval), get_name_from_type(sym->type));
            yyerror(error_msg);
        }
        (yyval.ast) = make_node("string_length", 1, make_node((yyvsp[-1].sval), 0));
    }
#line 2952 "parser.tab.c"
    break;

  case 141: /* expr: expr PLUS expr  */
#line 857 "parser.y"
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
#line 2968 "parser.tab.c"
    break;

  case 142: /* expr: expr MINUS expr  */
#line 868 "parser.y"
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
#line 2984 "parser.tab.c"
    break;

  case 143: /* expr: expr MULT expr  */
#line 879 "parser.y"
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
#line 3000 "parser.tab.c"
    break;

  case 144: /* expr: expr DIV expr  */
#line 890 "parser.y"
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
#line 3016 "parser.tab.c"
    break;

  case 145: /* expr: expr EQ expr  */
#line 901 "parser.y"
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
#line 3032 "parser.tab.c"
    break;

  case 146: /* expr: expr NE expr  */
#line 912 "parser.y"
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
#line 3048 "parser.tab.c"
    break;

  case 147: /* expr: expr LT expr  */
#line 923 "parser.y"
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
#line 3064 "parser.tab.c"
    break;

  case 148: /* expr: expr GT expr  */
#line 934 "parser.y"
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
#line 3080 "parser.tab.c"
    break;

  case 149: /* expr: expr LE expr  */
#line 945 "parser.y"
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
#line 3096 "parser.tab.c"
    break;

  case 150: /* expr: expr GE expr  */
#line 956 "parser.y"
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
#line 3112 "parser.tab.c"
    break;

  case 151: /* expr: LPAREN expr RPAREN  */
#line 967 "parser.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 3118 "parser.tab.c"
    break;

  case 152: /* expr: ID LBRACK expr RBRACK  */
#line 969 "parser.y"
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
#line 3139 "parser.tab.c"
    break;

  case 153: /* expr: LBRACK expr RBRACK  */
#line 986 "parser.y"
                         {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Invalid use of [] operator");
        yyerror(error_msg);
        (yyval.ast) = (yyvsp[-1].ast); 
    }
#line 3150 "parser.tab.c"
    break;

  case 154: /* expr: NUM  */
#line 993 "parser.y"
          { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 3156 "parser.tab.c"
    break;

  case 155: /* expr: ID  */
#line 994 "parser.y"
         {
        Symbol* sym = lookup_any_scope((yyvsp[0].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[0].sval));
            yyerror(error_msg);
        }
        (yyval.ast) = make_node((yyvsp[0].sval), 0);
    }
#line 3170 "parser.tab.c"
    break;

  case 156: /* expr: CHAR_LITERAL  */
#line 1003 "parser.y"
                   { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 3176 "parser.tab.c"
    break;

  case 157: /* expr: STRING_LITERAL  */
#line 1004 "parser.y"
                     { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 3182 "parser.tab.c"
    break;

  case 158: /* expr: NULLPTR  */
#line 1005 "parser.y"
              { (yyval.ast) = make_node("nullptr", 0); }
#line 3188 "parser.tab.c"
    break;

  case 159: /* expr: TRUE  */
#line 1006 "parser.y"
           { (yyval.ast) = make_node("true", 0); }
#line 3194 "parser.tab.c"
    break;

  case 160: /* expr: FALSE  */
#line 1007 "parser.y"
            { (yyval.ast) = make_node("false", 0); }
#line 3200 "parser.tab.c"
    break;

  case 161: /* expr: AND  */
#line 1008 "parser.y"
          { (yyval.ast) = make_node("and", 0); }
#line 3206 "parser.tab.c"
    break;

  case 162: /* expr: OR  */
#line 1009 "parser.y"
         { (yyval.ast) = make_node("or", 0); }
#line 3212 "parser.tab.c"
    break;

  case 163: /* expr: NOT  */
#line 1010 "parser.y"
          { (yyval.ast) = make_node("not", 0); }
#line 3218 "parser.tab.c"
    break;

  case 164: /* expr: CALL ID LPAREN call_args RPAREN  */
#line 1011 "parser.y"
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
#line 3234 "parser.tab.c"
    break;

  case 165: /* expr: ID LPAREN call_args RPAREN  */
#line 1022 "parser.y"
                                 {
        
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
#line 3267 "parser.tab.c"
    break;

  case 166: /* expr: expr AND expr  */
#line 1050 "parser.y"
                    { (yyval.ast) = make_node("and", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3273 "parser.tab.c"
    break;

  case 167: /* expr: expr OR expr  */
#line 1051 "parser.y"
                   { (yyval.ast) = make_node("or", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3279 "parser.tab.c"
    break;

  case 168: /* expr: NOT expr  */
#line 1052 "parser.y"
               { (yyval.ast) = make_node("not", 1, (yyvsp[0].ast)); }
#line 3285 "parser.tab.c"
    break;

  case 169: /* expr: MULT expr  */
#line 1054 "parser.y"
              {
  
    if (!(yyvsp[0].ast)) {
        yyerror("Semantic Error: Invalid dereference expression");
        (yyval.ast) = make_node("error", 0);
    }
   
    else if ((yyvsp[0].ast)->name && strcmp((yyvsp[0].ast)->name, "*") == 0) {
        yyerror("Semantic Error: Double dereference is not allowed (cannot use **ptr)");
        (yyval.ast) = make_node("error", 1, (yyvsp[0].ast));
    }
    
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
   
    else {
        yyerror("Semantic Error: Cannot dereference non-pointer expression");
        (yyval.ast) = make_node("error", 1, (yyvsp[0].ast));
    }
}
#line 3322 "parser.tab.c"
    break;

  case 170: /* expr: ADDRESS ID  */
#line 1086 "parser.y"
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
#line 3349 "parser.tab.c"
    break;

  case 171: /* expr: ADDRESS ID LBRACK expr RBRACK  */
#line 1109 "parser.y"
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
    
    
    (yyval.ast) = make_node("&array_access", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
}
#line 3372 "parser.tab.c"
    break;


#line 3376 "parser.tab.c"

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

#line 1130 "parser.y"


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

    // בדוק אם יש _main_ רק אם הפרסינג הצליח
    if (result == 0 && !main_defined) {
        yyerror("Semantic Error: No _main_ function defined");
    }

    // גנרט קוד 3AC תמיד אם הפרסינג הצליח (ללא תלות ב-main)
    if (result == 0 && program_ast) {
        printf("\n=== THREE ADDRESS CODE ===\n");
        generate_tac_from_ast(program_ast);
    } else if (result != 0) {
        printf("Parsing failed, cannot generate 3AC\n");
    } else if (!program_ast) {
        printf("No AST available for 3AC generation\n");
    }

    return result;
}
