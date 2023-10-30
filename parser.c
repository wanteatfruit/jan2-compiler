/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.bison" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
	#include "decl.h"
	#include "stmt.h"
	#include "expr.h"
	#include "type.h"
	#include "param_list.h"

    extern char *yytext;
    extern int yylex();
    extern int yyerror( char *str );
	extern FILE *yyin;
	extern struct decl *program_result;

#line 83 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "token.h".  */
#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_ARRAY = 258,
    TOKEN_BOOLEAN = 259,
    TOKEN_CHARACTER = 260,
    TOKEN_FLOAT = 261,
    TOKEN_FUNCTION = 262,
    TOKEN_INTEGER = 263,
    TOKEN_STRING = 264,
    TOKEN_VOID = 265,
    TOKEN_INTEGER_LITERAL = 266,
    TOKEN_CHARACTER_LITERAL = 267,
    TOKEN_STRING_LITERAL = 268,
    TOKEN_FLOAT_LITERAL = 269,
    TOKEN_ELSE = 270,
    TOKEN_FALSE = 271,
    TOKEN_FOR = 272,
    TOKEN_IF = 273,
    TOKEN_PRINT = 274,
    TOKEN_RETURN = 275,
    TOKEN_TRUE = 276,
    TOKEN_WHILE = 277,
    TOKEN_AUTO = 278,
    TOKEN_IDENTIFIER = 279,
    TOKEN_L_PAREN = 280,
    TOKEN_R_PAREN = 281,
    TOKEN_L_BRACKET = 282,
    TOKEN_R_BRACKET = 283,
    TOKEN_L_BRACE = 284,
    TOKEN_R_BRACE = 285,
    TOKEN_POSTINC = 286,
    TOKEN_POSTDEC = 287,
    TOKEN_NEG = 288,
    TOKEN_NOT = 289,
    TOKEN_EXP = 290,
    TOKEN_MUL = 291,
    TOKEN_DIV = 292,
    TOKEN_MOD = 293,
    TOKEN_ADD = 294,
    TOKEN_SUB = 295,
    TOKEN_LESS = 296,
    TOKEN_LE = 297,
    TOKEN_GE = 298,
    TOKEN_GREATER = 299,
    TOKEN_EQUAL = 300,
    TOKEN_NEQUAL = 301,
    TOKEN_AND = 302,
    TOKEN_OR = 303,
    TOKEN_ASSIGN = 304,
    TOKEN_SEMICOLON = 305,
    TOKEN_COLON = 306,
    TOKEN_COMMA = 307,
    TOKEN_BACKSLASH = 308,
    TOKEN_C_COMMENT = 309,
    TOKEN_CPP_COMMENT = 310,
    TOKEN_ERROR = 311,
    TOKEN_EOF = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 74 "parser.bison" /* yacc.c:355  */

	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	struct type *type;
	struct param_list *param_list;

#line 189 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKEN_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    93,    93,    96,    97,   100,   101,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   127,   128,   130,   133,
     134,   137,   138,   141,   144,   145,   149,   150,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   165,   170,   171,
     172,   175,   176,   179,   180,   183,   184,   185,   186,   187,
     188,   189,   192,   193,   194,   197,   198,   199,   200,   203,
     204,   207,   208,   209,   212,   213,   214,   217,   218,   219,
     220,   221,   222,   225,   229,   230,   231,   232,   233,   234,
     235
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_ARRAY", "TOKEN_BOOLEAN",
  "TOKEN_CHARACTER", "TOKEN_FLOAT", "TOKEN_FUNCTION", "TOKEN_INTEGER",
  "TOKEN_STRING", "TOKEN_VOID", "TOKEN_INTEGER_LITERAL",
  "TOKEN_CHARACTER_LITERAL", "TOKEN_STRING_LITERAL", "TOKEN_FLOAT_LITERAL",
  "TOKEN_ELSE", "TOKEN_FALSE", "TOKEN_FOR", "TOKEN_IF", "TOKEN_PRINT",
  "TOKEN_RETURN", "TOKEN_TRUE", "TOKEN_WHILE", "TOKEN_AUTO",
  "TOKEN_IDENTIFIER", "TOKEN_L_PAREN", "TOKEN_R_PAREN", "TOKEN_L_BRACKET",
  "TOKEN_R_BRACKET", "TOKEN_L_BRACE", "TOKEN_R_BRACE", "TOKEN_POSTINC",
  "TOKEN_POSTDEC", "TOKEN_NEG", "TOKEN_NOT", "TOKEN_EXP", "TOKEN_MUL",
  "TOKEN_DIV", "TOKEN_MOD", "TOKEN_ADD", "TOKEN_SUB", "TOKEN_LESS",
  "TOKEN_LE", "TOKEN_GE", "TOKEN_GREATER", "TOKEN_EQUAL", "TOKEN_NEQUAL",
  "TOKEN_AND", "TOKEN_OR", "TOKEN_ASSIGN", "TOKEN_SEMICOLON",
  "TOKEN_COLON", "TOKEN_COMMA", "TOKEN_BACKSLASH", "TOKEN_C_COMMENT",
  "TOKEN_CPP_COMMENT", "TOKEN_ERROR", "TOKEN_EOF", "$accept", "program",
  "decl_list", "stmt_list", "stmt", "if_nest", "decl", "param_list",
  "param", "arg_list", "arg", "for_expr", "type", "id", "expr", "expr_or",
  "expr_and", "expr_comp", "expr_add", "expr_mul", "expr_exp",
  "expr_unary", "exp_post", "factor", "arr_subscr", "literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

#define YYPACT_NINF -151

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-151)))

#define YYTABLE_NINF -25

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,  -151,    24,   -30,    -2,   -17,  -151,  -151,  -151,    47,
      11,  -151,  -151,  -151,    47,  -151,  -151,  -151,    55,   343,
      15,   393,  -151,  -151,  -151,  -151,  -151,  -151,  -151,   418,
      47,   418,   418,   418,    -6,    16,  -151,    13,    38,    36,
      69,    22,    60,  -151,    61,    34,  -151,    -2,   293,    40,
      75,  -151,    82,  -151,    62,   108,  -151,  -151,  -151,   368,
     418,    47,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,  -151,  -151,   418,
     109,  -151,    94,   121,   122,    -4,    86,   293,   118,   293,
    -151,   -10,   -39,  -151,  -151,  -151,   418,  -151,   127,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,   130,  -151,  -151,    47,   418,
     418,  -151,   110,  -151,   113,   125,  -151,  -151,   114,  -151,
    -151,  -151,  -151,   107,   115,  -151,   140,  -151,  -151,  -151,
      -2,   418,   318,  -151,   117,   143,   144,   228,   258,   293,
    -151,   155,   157,   126,   418,   418,   418,   160,   133,   162,
     134,   150,   293,   185,   175,   152,   177,   189,   190,   191,
    -151,   293,   418,   318,  -151,   158,   194,   418,   318,   184,
    -151,   318,  -151
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    47,     0,     0,     4,     0,     1,     2,     3,     0,
       0,    40,    41,    39,     0,    38,    42,    43,     0,     0,
       0,     0,    26,    84,    86,    87,    85,    89,    88,     0,
       0,     0,     0,     0,    80,     0,    50,    52,    54,    61,
      64,    68,    70,    73,    76,    78,    79,    30,     6,     0,
       0,    44,     0,    33,    35,    80,    72,    78,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,     0,
       0,    29,     0,     0,     0,     0,     0,     6,     0,     6,
       7,    80,    35,    27,    77,    90,     0,    82,     0,    48,
      45,    51,    53,    56,    58,    59,    60,    55,    57,    62,
      63,    65,    66,    67,    69,     0,    49,    46,     0,    37,
       0,    10,     0,    12,     0,     0,    28,     5,     0,     8,
      34,    81,    83,    31,     0,    36,     0,     9,    11,    16,
       0,    37,     0,    32,     0,     0,     0,     0,     0,     6,
      14,     0,     7,     0,    37,    37,     0,    10,     0,    12,
       0,     0,     0,     8,     0,     0,     0,     9,    11,    16,
      15,     0,    37,     0,    13,     0,     0,    37,     0,     0,
      17,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,   207,   -73,  -136,  -150,     1,  -151,    76,   -56,
     119,   -38,   -12,     0,    65,   156,   154,    63,    48,    49,
     145,   105,  -151,  -151,   124,  -151
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    88,    89,   151,    90,    80,    81,    52,
      53,   134,    18,    34,   135,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,     4,    20,    98,     5,     4,   150,    23,    24,    25,
      26,   129,    27,    96,   125,    59,   127,    28,    51,    59,
       1,    29,     1,   176,     6,    31,   170,     7,   180,   122,
      32,   182,    55,    55,     9,   174,    33,   150,    19,    60,
      47,     9,   170,    60,    61,   174,   121,    82,    91,   100,
      10,    11,    12,    13,    14,    15,    16,    17,    72,    73,
      74,    62,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,   161,    64,    65,    66,
      67,    68,    69,    79,    35,    63,    49,    91,    76,    91,
      93,   158,    77,    78,    50,    75,    54,    23,    24,    25,
      26,    94,    27,   144,    21,    22,   133,    28,    70,    71,
       1,    29,    95,    92,    96,    31,   164,   165,   109,   110,
      32,   111,   112,   113,    54,    99,    33,   103,   104,   105,
     106,   107,   108,    59,   175,   117,   123,    56,    58,   179,
      82,   115,    91,   152,   116,   118,   119,   120,   126,    91,
      54,   124,    92,   131,   128,   139,    57,    57,   132,   140,
     137,    54,    91,   138,   129,   141,   142,   154,   155,   156,
     162,    91,   -18,    91,   152,   -22,   163,   -24,    91,   152,
     169,    91,   152,   167,   168,   136,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
     -19,   171,   172,   173,   -21,   -23,   -20,   153,   177,   178,
     181,     8,    54,   160,    92,   130,   143,   102,   101,     0,
     114,   166,     0,     0,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   153,    23,
      24,    25,    26,   153,    27,     0,   153,     0,     0,    28,
       0,     0,     1,    29,     0,     0,     0,    31,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,    33,    23,
      24,    25,    26,     0,    27,     0,     0,     0,   157,    28,
       0,     0,     1,    29,     0,     0,     0,    31,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   159,    27,
      83,    84,    85,    86,    28,     0,     0,     1,    29,     0,
       0,     0,    87,     0,     0,     0,     0,    32,     0,    23,
      24,    25,    26,    33,    27,   145,   146,   147,   148,    28,
       0,     0,     1,    29,     0,     0,     0,   149,     0,     0,
       0,     0,    32,     0,    23,    24,    25,    26,    33,    27,
       0,     0,     0,     0,    28,     0,     0,     1,    29,     0,
       0,    30,    31,     0,     0,     0,     0,    32,     0,    23,
      24,    25,    26,    33,    27,     0,     0,     0,     0,    28,
       0,     0,     1,    29,    97,     0,     0,    31,     0,     0,
       0,     0,    32,     0,    23,    24,    25,    26,    33,    27,
       0,     0,     0,     0,    28,     0,     0,     1,    29,     0,
       0,     0,    48,     0,     0,     0,     0,    32,     0,    23,
      24,    25,    26,    33,    27,     0,     0,     0,     0,    28,
       0,     0,     1,    29,     0,     0,     0,    31,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,    33
};

static const yytype_int16 yycheck[] =
{
       0,     0,    14,    59,     4,     4,   142,    11,    12,    13,
      14,    50,    16,    52,    87,    25,    89,    21,    30,    25,
      24,    25,    24,   173,     0,    29,   162,    57,   178,    85,
      34,   181,    32,    33,    51,   171,    40,   173,    27,    49,
      25,    51,   178,    49,    28,   181,    50,    47,    48,    61,
       3,     4,     5,     6,     7,     8,     9,    10,    36,    37,
      38,    48,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,   149,    41,    42,    43,
      44,    45,    46,    49,    19,    47,    21,    87,    27,    89,
      50,   147,    31,    32,    29,    35,    31,    11,    12,    13,
      14,    26,    16,   141,    49,    50,   118,    21,    39,    40,
      24,    25,    30,    48,    52,    29,   154,   155,    70,    71,
      34,    72,    73,    74,    59,    60,    40,    64,    65,    66,
      67,    68,    69,    25,   172,    26,    50,    32,    33,   177,
     140,    76,   142,   142,    79,    51,    25,    25,    30,   149,
      85,    86,    87,    26,    89,    30,    32,    33,    28,    52,
      50,    96,   162,    50,    50,    50,    26,    50,    25,    25,
      15,   171,    15,   173,   173,    15,    50,    15,   178,   178,
      30,   181,   181,    50,    50,   120,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      15,    26,    50,    26,    15,    15,    15,   142,    50,    15,
      26,     4,   147,   148,   149,    96,   140,    63,    62,    -1,
      75,   156,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,   173,    11,
      12,    13,    14,   178,    16,    -1,   181,    -1,    -1,    21,
      -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    50,    21,
      -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    50,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    11,
      12,    13,    14,    40,    16,    17,    18,    19,    20,    21,
      -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    -1,    11,    12,    13,    14,    40,    16,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    24,    25,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,    -1,    11,
      12,    13,    14,    40,    16,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    -1,    11,    12,    13,    14,    40,    16,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    11,
      12,    13,    14,    40,    16,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    59,    60,    64,    71,     0,    57,    60,    51,
       3,     4,     5,     6,     7,     8,     9,    10,    70,    27,
      70,    49,    50,    11,    12,    13,    14,    16,    21,    25,
      28,    29,    34,    40,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    25,    29,    72,
      72,    70,    67,    68,    72,    71,    79,    82,    79,    25,
      49,    28,    48,    47,    41,    42,    43,    44,    45,    46,
      39,    40,    36,    37,    38,    35,    27,    31,    32,    49,
      65,    66,    71,    17,    18,    19,    20,    29,    61,    62,
      64,    71,    72,    50,    26,    30,    52,    26,    67,    72,
      70,    73,    74,    75,    75,    75,    75,    75,    75,    76,
      76,    77,    77,    77,    78,    72,    72,    26,    51,    25,
      25,    50,    67,    50,    72,    61,    30,    61,    72,    50,
      68,    26,    28,    70,    69,    72,    72,    50,    50,    30,
      52,    50,    26,    66,    69,    17,    18,    19,    20,    29,
      62,    63,    64,    72,    50,    25,    25,    50,    67,    50,
      72,    61,    15,    50,    69,    69,    72,    50,    50,    30,
      62,    26,    50,    26,    62,    69,    63,    50,    15,    69,
      63,    26,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64,    65,
      65,    66,    66,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    72,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    76,    76,    76,    77,    77,    77,    77,    78,
      78,    79,    79,    79,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    82,    83,    83,    83,    83,    83,    83,
      83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     0,     1,     2,     3,
       2,     3,     2,     9,     5,     7,     3,     7,     1,     2,
       3,     3,     2,     3,     2,     9,     4,     6,     7,     1,
       0,     3,     5,     1,     3,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       1,     2,     2,     1,     2,     2,     1,     3,     1,     1,
       1,     4,     3,     4,     1,     1,     1,     1,     1,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 93 "parser.bison" /* yacc.c:1646  */
    { program_result = (yyvsp[-1].decl);  return 0; }
#line 1473 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 96 "parser.bison" /* yacc.c:1646  */
    { (yyvsp[-1].decl)->next = (yyvsp[0].decl); (yyval.decl) = (yyvsp[-1].decl); }
#line 1479 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 97 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = 0; }
#line 1485 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 100 "parser.bison" /* yacc.c:1646  */
    { (yyvsp[-1].stmt)->next = (yyvsp[0].stmt); (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1491 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 101 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = 0; }
#line 1497 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 104 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), 0, 0, 0, 0, 0, 0); }
#line 1503 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 105 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1509 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 106 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1515 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, 0, 0, 0, 0, 0); }
#line 1521 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 108 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1527 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 109 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, 0, 0, 0, 0, 0); }
#line 1533 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 110 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0, 0); }
#line 1539 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 111 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-2].expr), 0, (yyvsp[0].stmt), 0, 0); }
#line 1545 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 112 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt), 0); }
#line 1551 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 113 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1557 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 116 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt), 0); }
#line 1563 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 117 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), 0, 0, 0, 0, 0, 0); }
#line 1569 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 118 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1575 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 119 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].stmt);}
#line 1581 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 120 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1587 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 121 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, 0, 0, 0, 0, 0); }
#line 1593 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 122 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1599 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 123 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, 0, 0, 0, 0, 0); }
#line 1605 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 124 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0, 0); }
#line 1611 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 127 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((char *)(yyvsp[-3].expr)->name, (yyvsp[-1].type), 0, 0, 0); }
#line 1617 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((char *)(yyvsp[-5].expr)->name, (yyvsp[-3].type), (yyvsp[-1].expr), 0, 0); }
#line 1623 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 130 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((char *)(yyvsp[-6].expr)->name, (yyvsp[-4].type), 0, (yyvsp[-1].stmt), 0); }
#line 1629 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1635 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 134 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = 0;}
#line 1641 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 137 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create((char *)(yyvsp[-2].expr)->name, (yyvsp[0].type), 0);}
#line 1647 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 138 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create((char *)(yyvsp[-4].expr)->name, (yyvsp[-2].type), (yyvsp[0].param_list));}
#line 1653 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 141 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1659 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 144 "parser.bison" /* yacc.c:1646  */
    { (yyvsp[-2].expr)->next = (yyvsp[0].expr); (yyval.expr) = (yyvsp[-2].expr);}
#line 1665 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 145 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1671 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 149 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1677 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 150 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1683 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 154 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, 0, 0); }
#line 1689 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 155 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FLOAT, 0, 0); }
#line 1695 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 156 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0); }
#line 1701 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 157 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHARACTER, 0, 0); }
#line 1707 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 158 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, 0, 0); }
#line 1713 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 159 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_VOID, 0, 0); }
#line 1719 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 160 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), 0); }
#line 1725 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 161 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_with_length(TYPE_ARRAY, (yyvsp[0].type), 0, (yyvsp[-2].expr)); }
#line 1731 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 162 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[-3].type), (yyvsp[-1].param_list));}
#line 1737 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 165 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_name(yytext); }
#line 1743 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 170 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1749 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 171 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1755 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 172 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1761 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 175 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1767 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 176 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1773 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 179 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1779 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 180 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1785 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 183 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1791 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 184 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1797 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 185 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NEQUAL, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1803 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 186 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LE, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1809 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 187 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GE, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1815 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 188 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GREATER, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1821 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 189 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1827 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 192 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1833 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 193 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1839 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 194 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1845 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 197 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1851 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 198 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1857 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 199 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1863 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 200 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1869 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 203 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EXP, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1875 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 204 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1881 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 207 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NEG, 0, (yyvsp[0].expr));}
#line 1887 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 208 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NOT, 0, (yyvsp[0].expr));}
#line 1893 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 209 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1899 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 212 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_POSTINC, (yyvsp[-1].expr), 0);}
#line 1905 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 213 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_POSTDEC, (yyvsp[-1].expr), 0);}
#line 1911 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 214 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1917 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 217 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_PARENTHESES, (yyvsp[-1].expr), 0); }
#line 1923 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 218 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1929 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 219 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1935 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 220 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1941 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 221 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_FUNC, (yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 1947 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 222 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_FUNC, (yyvsp[-2].expr), 0); }
#line 1953 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 225 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ARRAY_SUB, (yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 1959 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 229 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_integer_literal(atoi(yytext)); }
#line 1965 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 230 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_float_literal(atof(yytext)); }
#line 1971 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 231 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_char_literal(yytext[1]); }
#line 1977 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 232 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_string_literal(yytext); }
#line 1983 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 233 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal(1); }
#line 1989 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 234 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal(0); }
#line 1995 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 235 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ARRAY_LITERAL, (yyvsp[-1].expr), 0); }
#line 2001 "parser.c" /* yacc.c:1646  */
    break;


#line 2005 "parser.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 239 "parser.bison" /* yacc.c:1906  */


int yyerror(char *s) {
    printf("parse error: %s\n", s);
    return 1;
}
