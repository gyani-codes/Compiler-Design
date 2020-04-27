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
#line 3 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lib/symbol_table.h"
#include "lib/scope.h"
#include "lib/misc.h"
#include "lib/stack.h"

#define TRACE_ENABLED false

// Number of rows in Hash table for symbol and constant tables
#define MAX_NODES 1000

void yyerror(const char * s);

symbol_node_t *symbol_table[MAX_NODES];
symbol_node_t *constant_table[MAX_NODES];

scope_node_t *curr_scope;

extern char *yytext;
extern int yylineno;

char datatype[100];
int num_params;

symbol_node_t * redefined_error_check(char *symbol);


// ICG 3-address-code
stack *three_address_code_stack;
TAC_code_stack *TAC_code;

TAC_buffer_node *curr_buff = NULL;
bool BUFFER_ENABLED = true;
// If BUFFER_ENABLED is true, TAC is directed to a buffer instead of stdout

char temp_buf[100];
int LABEL_COUNT = 1;
int loopStartLabel = -1, loopEndLabel = -1;

#line 110 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    SIGNED = 258,
    UNSIGNED = 259,
    LONG = 260,
    SHORT = 261,
    SWITCH = 262,
    BREAK = 263,
    CONTINUE = 264,
    CASE = 265,
    DEFAULT = 266,
    RETURN = 267,
    FOR = 268,
    WHILE = 269,
    DO = 270,
    IF = 271,
    ELSE = 272,
    CONSTANT_INTEGER = 273,
    CONSTANT_FLOAT = 274,
    CONSTANT_STRING = 275,
    CONSTANT_CHAR = 276,
    INCLUDE = 277,
    IDENTIFIER = 278,
    INT = 279,
    CHAR = 280,
    FLOAT = 281,
    DOUBLE = 282,
    VOID = 283,
    ADD_ASSIGN = 284,
    SUB_ASSIGN = 285,
    MUL_ASSIGN = 286,
    DIV_ASSIGN = 287,
    MOD_ASSIGN = 288,
    LEFT_ASSIGN = 289,
    RIGHT_ASSIGN = 290,
    AND_ASSIGN = 291,
    XOR_ASSIGN = 292,
    OR_ASSIGN = 293,
    LOGIC_AND = 294,
    LOGIC_OR = 295,
    NOT = 296,
    INCREMENT_OPERATOR = 297,
    DECREMENT_OPERATOR = 298,
    LESSER_EQUAL = 299,
    GREATER_EQUAL = 300,
    DOUBLE_EQUAL = 301,
    NOT_EQUAL = 302,
    LESSER_THAN = 303,
    GREATER_THAN = 304,
    IfWithoutElse = 305
  };
#endif
/* Tokens.  */
#define SIGNED 258
#define UNSIGNED 259
#define LONG 260
#define SHORT 261
#define SWITCH 262
#define BREAK 263
#define CONTINUE 264
#define CASE 265
#define DEFAULT 266
#define RETURN 267
#define FOR 268
#define WHILE 269
#define DO 270
#define IF 271
#define ELSE 272
#define CONSTANT_INTEGER 273
#define CONSTANT_FLOAT 274
#define CONSTANT_STRING 275
#define CONSTANT_CHAR 276
#define INCLUDE 277
#define IDENTIFIER 278
#define INT 279
#define CHAR 280
#define FLOAT 281
#define DOUBLE 282
#define VOID 283
#define ADD_ASSIGN 284
#define SUB_ASSIGN 285
#define MUL_ASSIGN 286
#define DIV_ASSIGN 287
#define MOD_ASSIGN 288
#define LEFT_ASSIGN 289
#define RIGHT_ASSIGN 290
#define AND_ASSIGN 291
#define XOR_ASSIGN 292
#define OR_ASSIGN 293
#define LOGIC_AND 294
#define LOGIC_OR 295
#define NOT 296
#define INCREMENT_OPERATOR 297
#define DECREMENT_OPERATOR 298
#define LESSER_EQUAL 299
#define GREATER_EQUAL 300
#define DOUBLE_EQUAL 301
#define NOT_EQUAL 302
#define LESSER_THAN 303
#define GREATER_THAN 304
#define IfWithoutElse 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 60 "parser.y" /* yacc.c:355  */

        char char_ptr[100];
    int intval;

#line 255 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 272 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    67,     2,    55,    57,     2,
      62,    61,    53,    51,    60,    52,    68,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    59,
       2,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,    66,     2,     2,     2,     2,
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
      25,    26,    27,    28,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    96,    97,    98,    99,   100,   101,   102,
     107,   112,   113,   116,   124,   125,   128,   136,   137,   142,
     157,   155,   188,   192,   193,   194,   195,   196,   197,   198,
     199,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     217,   217,   217,   217,   221,   227,   238,   245,   248,   251,
     259,   276,   280,   284,   285,   286,   290,   306,   307,   308,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   326,   330,   331,   335,   339,   357,   358,   362,   366,
     370,   374,   378,   385,   386,   390,   398,   399,   403,   407,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   434,   438,   443,
     447,   448,   449,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   466,   471,   475,   479,   485,   494,   504,   517,
     527,   538,   558,   581,   585,   595,   608,   613,   619,   619,
     630,   630,   641,   641,   652,   652,   666,   682,   691,   695,
     696,   700
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SIGNED", "UNSIGNED", "LONG", "SHORT",
  "SWITCH", "BREAK", "CONTINUE", "CASE", "DEFAULT", "RETURN", "FOR",
  "WHILE", "DO", "IF", "ELSE", "CONSTANT_INTEGER", "CONSTANT_FLOAT",
  "CONSTANT_STRING", "CONSTANT_CHAR", "INCLUDE", "IDENTIFIER", "INT",
  "CHAR", "FLOAT", "DOUBLE", "VOID", "'='", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "LOGIC_AND", "LOGIC_OR", "NOT",
  "INCREMENT_OPERATOR", "DECREMENT_OPERATOR", "LESSER_EQUAL",
  "GREATER_EQUAL", "DOUBLE_EQUAL", "NOT_EQUAL", "LESSER_THAN",
  "GREATER_THAN", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'&'",
  "IfWithoutElse", "';'", "','", "')'", "'('", "'['", "']'", "'{'", "'}'",
  "'#'", "'.'", "$accept", "Begin", "Declaration", "Identifier_List",
  "Function_Declaration", "Function_Definition", "$@1", "Bracket_open",
  "Formal_Param_List", "Type", "Modifiers", "Array_Notation",
  "Define_Assign", "Param_List", "Assignment", "Assignment_Operator",
  "Expression", "Logical_Expression", "Relational_Expression",
  "Additive_Expression", "Multiplicative_Expression", "Primary",
  "Compound_Statement", "Scope_Start", "Scope_End", "Statement_List",
  "Statement", "Return_Statement", "While_Statement", "NotWhileLabel",
  "NotWhileGoto", "Do_While_Statement", "NotDoWhileLabel", "For_Statement",
  "IncTop", "RepeatForLabel", "ForExitGoto", "If_Statement", "$@2", "$@3",
  "$@4", "$@5", "IfNotGoto", "ElseNotGoto", "Function_Call",
  "Include_Statement", "Include", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    61,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,    43,    45,    42,    47,    37,    94,    38,   305,    59,
      44,    41,    40,    91,    93,   123,   125,    35,    46
};
# endif

#define YYPACT_NINF -130

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-130)))

#define YYTABLE_NINF -145

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
       2,    29,    10,    10,    10,    -4,   188,  -130,    10,    -1,
    -130,  -130,  -130,  -130,   236,    20,    31,    11,   429,     1,
    -130,  -130,  -130,  -130,  -130,    53,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,    21,  -130,    -6,
     198,    87,   375,    17,  -130,    21,    87,    21,   -40,   394,
    -130,    35,    67,    48,    50,    22,  -130,  -130,  -130,  -130,
      25,   310,    93,    96,   310,   310,   101,   103,   143,  -130,
    -130,   -33,   161,   -34,    88,  -130,  -130,    21,     8,    87,
      15,  -130,  -130,  -130,  -130,   104,  -130,    68,    75,    26,
     113,    77,  -130,  -130,    87,   161,  -130,  -130,  -130,  -130,
      85,    17,   359,   123,   445,    90,    94,    23,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,  -130,    95,   136,  -130,   105,   139,   115,  -130,  -130,
     102,   198,    40,   198,   110,   118,    87,   410,    87,  -130,
    -130,   161,   161,   -34,   -34,   -34,   -34,   -34,   -34,    88,
      88,  -130,  -130,  -130,  -130,   109,  -130,   119,  -130,  -130,
    -130,   235,  -130,   198,  -130,  -130,    87,  -130,    87,  -130,
    -130,  -130,   129,   133,    87,   155,  -130,  -130,   157,  -130,
    -130,    21,   162,   168,   235,   154,   235,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,   170,   325,   169,
     102,    87,  -130,  -130,  -130,  -130,  -130,  -130,  -130,   171,
    -130,    87,   218,   173,  -130,   175,   183,  -130,    87,  -130,
      87,   235,   178,   235,   185,   240,   247,  -130,  -130,  -130,
     193,  -130,  -130,   325,  -130,   211,   224,  -130,   298,   102,
     298,   102,   229,  -130,  -130,  -130,  -130,   235,  -130,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    43,    42,    41,    40,    31,    34,    32,    35,    33,
       0,     0,     4,     8,     6,     0,     0,   151,     2,     0,
       1,     5,     9,     7,    15,     0,     0,     0,    11,    18,
      36,    39,    37,    38,     3,     0,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    22,     0,
      30,     0,    16,     0,    10,     0,     0,     0,     0,    15,
      12,     0,     0,    33,     0,     0,    92,    93,    95,    94,
      96,     0,     0,     0,     0,     0,     0,     0,     0,   101,
      50,    71,    72,    76,    83,    86,   102,     0,     0,     0,
       0,    14,    52,    17,   149,     0,    44,     0,    20,    24,
       0,    26,   104,   106,    55,    75,   103,   105,   100,    99,
      97,    98,    96,     0,   101,     0,     0,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,    51,     0,     0,     0,    47,    19,
       0,    30,    25,    30,     0,    53,     0,    97,     0,    91,
      90,    73,    74,    80,    79,    81,    82,    78,    77,    84,
      85,    87,    88,    89,    45,     0,    46,     0,   150,   108,
      21,   112,    27,    30,    29,   148,    55,    56,     0,    58,
      48,    49,     0,     0,     0,     0,   127,   130,     0,   123,
     114,     0,     0,     0,   112,     0,   112,   119,   113,   120,
     115,   116,    28,    54,    57,   121,   122,     0,     0,     0,
       0,     0,   117,   118,   111,   109,   107,   110,   124,     0,
      59,     0,     0,     0,   134,     0,     0,   146,     0,   128,
       0,     0,     0,     0,     0,   137,   136,   135,   126,   125,
       0,   147,   147,     0,   129,   142,   138,   133,     0,     0,
       0,     0,     0,   143,   145,   139,   141,     0,   132,   131
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,   100,    83,   -16,  -130,  -130,  -130,   267,   -79,     9,
    -130,   -15,  -130,   117,   -75,   -22,   -31,  -130,   -67,   160,
     -61,   -73,  -129,  -130,  -130,  -103,   -59,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,    63,  -130,  -130,  -130
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,   190,    27,    13,    14,   140,   104,    64,   191,
      16,    79,    29,   144,   192,    51,   193,    81,    82,    83,
      84,    85,   194,   171,   216,   195,   196,   197,   198,   209,
     233,   199,   210,   200,   252,   228,   243,   201,   250,   251,
     248,   249,   231,   245,    86,    17,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,   108,   109,   115,   105,   117,    56,   118,   119,    15,
      94,   170,    61,     1,     2,     3,     4,   126,   127,    24,
      80,    15,    15,    15,    19,    92,   132,    15,    95,    20,
      89,    60,    28,   135,     5,     6,     7,     8,     9,    91,
      28,    93,    28,    52,    59,    99,    62,   116,    35,    25,
     101,   151,   152,    26,    53,   161,   162,   163,   134,    65,
     133,    57,   172,   114,   174,   159,   160,   136,   102,   103,
      54,   131,    28,   145,    25,   100,    58,    10,    26,    26,
      90,   222,   -59,    12,   -59,    97,   141,    48,    49,    49,
     146,   214,   148,   217,   202,    12,    12,    12,   117,    96,
     173,    12,   235,    88,   238,    66,    67,    68,    69,   -23,
      70,    98,    21,    22,    23,   177,   106,   179,    34,   107,
     254,   117,   256,   117,   110,   178,   111,   137,   258,    71,
      72,    73,   138,   219,   139,   220,   142,   143,    74,    75,
      76,   128,   129,   130,    77,   145,   147,   204,    88,    78,
      65,   149,    65,   207,   165,   150,   114,   167,   117,   164,
     117,    66,    67,    68,    69,   168,   112,   169,   247,   166,
     220,   175,   236,   180,   239,   117,    28,   117,   176,   114,
     223,   114,    65,   181,   117,    71,    72,    73,   205,   253,
     225,   255,   206,   114,    74,    75,   113,   232,   259,   234,
      77,     1,     2,     3,     4,    78,   120,   121,   122,   123,
     124,   125,    30,    31,    32,    33,   114,   208,   114,   211,
     215,   212,     5,     6,     7,     8,    63,   213,   114,   218,
     224,   221,   226,   114,   227,   114,   229,   237,     1,     2,
       3,     4,   114,   182,   183,   230,   240,   184,   185,   186,
     187,   188,   244,    66,    67,    68,    69,   241,   112,     5,
       6,     7,     8,     9,   242,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,  -144,    71,    72,    73,
     153,   154,   155,   156,   157,   158,    74,    75,   113,  -140,
     257,    50,    77,   203,   189,     0,    47,    78,    48,    49,
     169,     1,     2,     3,     4,   246,   182,   183,     0,     0,
     184,   185,   186,   187,   188,     0,    66,    67,    68,    69,
       0,   112,     5,     6,     7,     8,     9,     0,    66,    67,
      68,    69,     0,    70,     0,     0,     0,     0,     0,     0,
      71,    72,    73,    66,    67,    68,    69,     0,   112,    74,
      75,   113,     0,    72,    73,    77,     0,   189,     0,     0,
      78,    74,    75,    76,     0,     0,     0,    77,    72,    73,
       0,     0,    78,     0,     0,     0,    74,    75,   113,     0,
       0,     0,    77,     0,     0,     0,     0,    78,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,     0,   102,   103,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,     0,     0,     0,
       0,    48,    49,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,    87,     0,     0,    88,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,     0,     0,     0,    47,     0,     0,    49,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,     0,     0,    88,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,     0,     0,    55
};

static const yytype_int16 yycheck[] =
{
      15,    74,    75,    78,    71,    78,    28,    40,    41,     0,
      50,   140,    18,     3,     4,     5,     6,    51,    52,    23,
      51,    12,    13,    14,    22,    56,    18,    18,    68,     0,
      52,    47,    47,    18,    24,    25,    26,    27,    28,    55,
      55,    57,    57,    23,    23,    23,    52,    78,    49,    53,
      65,   118,   119,    57,    23,   128,   129,   130,    89,    50,
      52,    60,   141,    78,   143,   126,   127,    52,    43,    44,
      59,    87,    87,   104,    53,    53,    23,    67,    57,    57,
      63,   210,    59,     0,    61,    18,    60,    62,    63,    63,
     112,   194,   114,   196,   173,    12,    13,    14,   171,    64,
      60,    18,   231,    63,   233,    18,    19,    20,    21,    61,
      23,    61,    12,    13,    14,   146,    23,   148,    18,    23,
     249,   194,   251,   196,    23,   147,    23,    23,   257,    42,
      43,    44,    64,   208,    59,   208,    23,    60,    51,    52,
      53,    53,    54,    55,    57,   176,    23,   178,    63,    62,
     141,    61,   143,   184,    18,    61,   171,    18,   231,    64,
     233,    18,    19,    20,    21,    50,    23,    65,   243,    64,
     243,    61,   231,    64,   233,   248,   191,   250,    60,   194,
     211,   196,   173,    64,   257,    42,    43,    44,    59,   248,
     221,   250,    59,   208,    51,    52,    53,   228,   257,   230,
      57,     3,     4,     5,     6,    62,    45,    46,    47,    48,
      49,    50,    24,    25,    26,    27,   231,    62,   233,    62,
      66,    59,    24,    25,    26,    27,    28,    59,   243,    59,
      59,    62,    14,   248,    61,   250,    61,    59,     3,     4,
       5,     6,   257,     8,     9,    62,    61,    12,    13,    14,
      15,    16,    59,    18,    19,    20,    21,    17,    23,    24,
      25,    26,    27,    28,    17,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    65,    42,    43,    44,
     120,   121,   122,   123,   124,   125,    51,    52,    53,    65,
      61,    24,    57,   176,    59,    -1,    60,    62,    62,    63,
      65,     3,     4,     5,     6,   242,     8,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    27,    28,    -1,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    18,    19,    20,    21,    -1,    23,    51,
      52,    53,    -1,    43,    44,    57,    -1,    59,    -1,    -1,
      62,    51,    52,    53,    -1,    -1,    -1,    57,    43,    44,
      -1,    -1,    62,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    62,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    44,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    60,    -1,    -1,    63,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    63,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    63,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    24,    25,    26,    27,    28,
      67,    70,    71,    73,    74,    78,    79,   114,   115,    22,
       0,    70,    70,    70,    23,    53,    57,    72,    80,    81,
      24,    25,    26,    27,    70,    49,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    60,    62,    63,
      76,    84,    23,    23,    59,    60,    84,    60,    23,    23,
      72,    18,    52,    28,    77,    78,    18,    19,    20,    21,
      23,    42,    43,    44,    51,    52,    53,    57,    62,    80,
      85,    86,    87,    88,    89,    90,   113,    60,    63,    84,
      63,    72,    85,    72,    50,    68,    64,    18,    61,    23,
      53,    80,    43,    44,    76,    87,    23,    23,    90,    90,
      23,    23,    23,    53,    80,    83,    85,    90,    40,    41,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    72,    18,    52,    85,    18,    52,    23,    64,    59,
      75,    60,    23,    60,    82,    85,    84,    23,    84,    61,
      61,    87,    87,    88,    88,    88,    88,    88,    88,    89,
      89,    90,    90,    90,    64,    18,    64,    18,    50,    65,
      91,    92,    77,    60,    77,    61,    60,    85,    84,    85,
      64,    64,     8,     9,    12,    13,    14,    15,    16,    59,
      71,    78,    83,    85,    91,    94,    95,    96,    97,   100,
     102,   106,    77,    82,    85,    59,    59,    85,    62,    98,
     101,    62,    59,    59,    94,    66,    93,    94,    59,    83,
      90,    62,    91,    85,    59,    85,    14,    61,   104,    61,
      62,   111,    85,    99,    85,    91,    95,    59,    91,    95,
      61,    17,    17,   105,    59,   112,   112,    83,   109,   110,
     107,   108,   103,    95,    91,    95,    91,    61,    91,    95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      75,    74,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    81,    81,    82,    82,    82,    83,    83,    83,    83,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    88,    88,    88,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    91,    92,    93,
      94,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    97,    97,    98,    99,   100,
     101,   102,   102,   103,   104,   105,   106,   106,   107,   106,
     108,   106,   109,   106,   110,   106,   111,   112,   113,   114,
     114,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       3,     1,     3,     4,     3,     1,     2,     3,     1,     6,
       0,     7,     1,     1,     2,     3,     2,     4,     5,     4,
       0,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     4,     5,     5,     5,     6,     6,
       3,     4,     3,     1,     3,     0,     3,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     2,     2,     2,     2,     3,     1,     1,
       2,     2,     0,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     2,     1,     3,     7,     7,     0,     0,     8,
       0,    12,    12,     0,     0,     0,     6,     6,     0,    10,
       0,    10,     0,    10,     0,    10,     0,     0,     4,     5,
       7,     1
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
        case 12:
#line 113 "parser.y" /* yacc.c:1646  */
    {   redeclaration_error_check((yyvsp[-2].char_ptr));
                                                symbl_tbl_insrt(symbol_table,(yyvsp[-2].char_ptr) , curr_scope->scope_num, datatype, "", yylineno);
                                            }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 116 "parser.y" /* yacc.c:1646  */
    {
                                                redeclaration_error_check((yyvsp[-2].char_ptr));
                                                int len = strlen(datatype);
                                                datatype[len] = '*';
                                                datatype[len +1] = '\0';
                                                symbl_tbl_insrt(symbol_table,(yyvsp[-2].char_ptr) , curr_scope->scope_num, datatype, "", yylineno);
                                                datatype[len] = '\0';
                                            }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "parser.y" /* yacc.c:1646  */
    {
                                                redeclaration_error_check((yyvsp[0].char_ptr));
                                                symbl_tbl_insrt(symbol_table,(yyvsp[0].char_ptr) , curr_scope->scope_num, datatype, "", yylineno);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 128 "parser.y" /* yacc.c:1646  */
    {
                                                redeclaration_error_check((yyvsp[0].char_ptr));
                                                int len = strlen(datatype);
                                                datatype[len] = '*';
                                                datatype[len +1] = '\0';
                                                symbl_tbl_insrt(symbol_table,(yyvsp[0].char_ptr) , curr_scope->scope_num, datatype, "", yylineno);
                                                datatype[len] = '\0';
                                            }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 142 "parser.y" /* yacc.c:1646  */
    {
                                                                        redeclaration_error_check((yyvsp[-4].char_ptr));
                                                                        char funcType[100] = "Function: ";
                                                                        strcat(funcType, datatype);
                                                                        symbol_node_t *node = symbl_tbl_insrt(symbol_table,(yyvsp[-4].char_ptr), curr_scope->scope_num, funcType, "", yylineno);
                                                                        node->is_function_defined = false;
                                                                        node->num_params = num_params;
                                                                    }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 157 "parser.y" /* yacc.c:1646  */
    {   curr_buff = get_new_node(TAC_code);
                                sprintf(temp_buf, "Func %s begin:\n", (yyvsp[-3].char_ptr));
                                strcat(curr_buff->code, temp_buf);
                            }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 161 "parser.y" /* yacc.c:1646  */
    {

                                    symbol_node_t *node = redefined_error_check((yyvsp[-5].char_ptr));
                                    char funcType[100] = "Function: ";
                                    strcat(funcType, datatype);

                                    if(!node) {
                                        symbol_node_t *node = symbl_tbl_insrt(symbol_table,(yyvsp[-5].char_ptr), curr_scope->scope_num, funcType, "", yylineno);
                                        node->num_params = num_params;
                                        curr_buff = get_new_node(TAC_code);
                                        sprintf(temp_buf, "Func end\n");
                                        strcat(curr_buff->code, temp_buf);
                                    }


                                    else {
                                        node->is_function_defined = true;
                                        node->num_params = num_params;
                                        curr_buff = get_new_node(TAC_code);
                                        sprintf(temp_buf, "Func end\n");
                                        strcat(curr_buff->code, temp_buf);
                                    }

                                }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 188 "parser.y" /* yacc.c:1646  */
    { num_params = 0; }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 193 "parser.y" /* yacc.c:1646  */
    { num_params++; void_param_check((yyvsp[-1].char_ptr)); symbl_tbl_insrt(symbol_table,(yyvsp[0].char_ptr) , curr_scope->scope_num, (yyvsp[-1].char_ptr), "", yylineno);trace("Formal_Param_List Rule 1\n");}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 194 "parser.y" /* yacc.c:1646  */
    { num_params++; void_param_check((yyvsp[-2].char_ptr)); symbl_tbl_insrt(symbol_table,(yyvsp[0].char_ptr) , curr_scope->scope_num, (yyvsp[-2].char_ptr), "", yylineno);trace("Formal_Param_List Rule 2\n");}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 195 "parser.y" /* yacc.c:1646  */
    { num_params++; void_param_check((yyvsp[-1].char_ptr)); trace("Formal_Param_List Rule 3\n");}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 196 "parser.y" /* yacc.c:1646  */
    { num_params++; void_param_check((yyvsp[-3].char_ptr)); symbl_tbl_insrt(symbol_table,(yyvsp[-2].char_ptr) , curr_scope->scope_num, (yyvsp[-3].char_ptr), "", yylineno);trace("Formal_Param_List Rule 4\n");}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 197 "parser.y" /* yacc.c:1646  */
    { num_params++; void_param_check((yyvsp[-4].char_ptr)); symbl_tbl_insrt(symbol_table,(yyvsp[-2].char_ptr) , curr_scope->scope_num, (yyvsp[-4].char_ptr), "", yylineno);trace("Formal_Param_List Rule 5\n");}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 198 "parser.y" /* yacc.c:1646  */
    { num_params++; void_param_check((yyvsp[-3].char_ptr)); trace("Formal_Param_List Rule 6\n");}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 203 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.char_ptr), (yyvsp[0].char_ptr)); strcpy(datatype, (yyvsp[0].char_ptr));}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 204 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.char_ptr), (yyvsp[0].char_ptr)); strcpy(datatype, (yyvsp[0].char_ptr));}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 205 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.char_ptr), (yyvsp[0].char_ptr)); strcpy(datatype, (yyvsp[0].char_ptr));}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 206 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.char_ptr), (yyvsp[0].char_ptr)); strcpy(datatype, (yyvsp[0].char_ptr));}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 207 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.char_ptr), (yyvsp[0].char_ptr)); strcpy(datatype, (yyvsp[0].char_ptr));}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 208 "parser.y" /* yacc.c:1646  */
    { strcpy(datatype, (yyvsp[0].char_ptr));}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 209 "parser.y" /* yacc.c:1646  */
    { strcpy(datatype, (yyvsp[0].char_ptr));}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 210 "parser.y" /* yacc.c:1646  */
    { strcpy(datatype, (yyvsp[0].char_ptr));}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 211 "parser.y" /* yacc.c:1646  */
    { strcpy(datatype, (yyvsp[0].char_ptr));}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 221 "parser.y" /* yacc.c:1646  */
    {
                                                char arrayType[100] = "Array: ";strcat(arrayType, datatype);
                                                arr_dimension_check((yyvsp[-3].char_ptr), (yyvsp[-1].char_ptr));
                                                symbl_tbl_insrt(symbol_table,(yyvsp[-3].char_ptr), curr_scope->scope_num, arrayType, (yyvsp[-1].char_ptr), yylineno);
                                                arr_subscript_check((yyvsp[-3].char_ptr));
                                            }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 227 "parser.y" /* yacc.c:1646  */
    {
                                                    redeclaration_error_check((yyvsp[-3].char_ptr));
                                                    arr_dimension_check((yyvsp[-3].char_ptr), (yyvsp[-1].char_ptr));
                                                    int len = strlen(datatype);
                                                    datatype[len] = '*';
                                                    datatype[len +1] = '\0';
                                                    char arrayType[100] = "Array: ";strcat(arrayType, datatype);
                                                    symbl_tbl_insrt(symbol_table,(yyvsp[-3].char_ptr), curr_scope->scope_num, arrayType, (yyvsp[-1].char_ptr), yylineno);
                                                    datatype[len] = '\0';
                                                    arr_subscript_check((yyvsp[-3].char_ptr));
                                                }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 238 "parser.y" /* yacc.c:1646  */
    {
                                                    redeclaration_error_check((yyvsp[-3].char_ptr));
                                                    arr_dimension_check((yyvsp[-3].char_ptr), (yyvsp[-1].char_ptr));
                                                    char arrayType[100] = "Array: ";strcat(arrayType, datatype);
                                                    symbl_tbl_insrt(symbol_table,(yyvsp[-3].char_ptr), curr_scope->scope_num, arrayType, (yyvsp[-1].char_ptr), yylineno);
                                                    arr_subscript_check((yyvsp[-3].char_ptr));
                                                }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 245 "parser.y" /* yacc.c:1646  */
    {
                                        yyerror(strcat((yyvsp[-4].char_ptr), " has non-positive array size"));
                                    }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 248 "parser.y" /* yacc.c:1646  */
    {
                                        yyerror(strcat((yyvsp[-4].char_ptr), " has non-positive array size"));
                                    }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 251 "parser.y" /* yacc.c:1646  */
    {
                                        yyerror(strcat((yyvsp[-4].char_ptr), " has non-positive array size"));
                                    }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 259 "parser.y" /* yacc.c:1646  */
    {
                                                                //redeclaration_error_check($1);
                                                                symbl_tbl_insrt(symbol_table,(yyvsp[-2].char_ptr) , curr_scope->scope_num, datatype, "", yylineno);
                                                                trace("Define_Assign Rule 1\n");

                                                                stack_node op = popStack(three_address_code_stack);
                                                                curr_buff = get_new_node(TAC_code);
                                                                pushStack(three_address_code_stack, (yyvsp[-2].char_ptr));

                                                                if(BUFFER_ENABLED) {
                                                                    sprintf(temp_buf, "%s = %s\n", (yyvsp[-2].char_ptr), op.var_name);
                                                                    strcat(curr_buff->code, temp_buf);
                                                                }
                                                                else
                                                                    printf("%s = %s\n", (yyvsp[-2].char_ptr), op.var_name);

                                                            }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 276 "parser.y" /* yacc.c:1646  */
    {
                                                                //redeclaration_error_check($2);
                                                                symbl_tbl_insrt(symbol_table,(yyvsp[-2].char_ptr) , curr_scope->scope_num, datatype, "", yylineno);
                                                            }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 284 "parser.y" /* yacc.c:1646  */
    { num_params++; }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 285 "parser.y" /* yacc.c:1646  */
    { num_params++; }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 290 "parser.y" /* yacc.c:1646  */
    {
                                                                scope_error_check((yyvsp[-2].char_ptr));
                                                                trace("Assignment Rule 1\n");

                                                                stack_node op = popStack(three_address_code_stack);
                                                                curr_buff = get_new_node(TAC_code);
                                                                pushStack(three_address_code_stack, (yyvsp[-2].char_ptr));

                                                                if(BUFFER_ENABLED) {
                                                                    sprintf(temp_buf, "%s = %s\n", (yyvsp[-2].char_ptr), op.var_name);
                                                                    strcat(curr_buff->code, temp_buf);
                                                                }
                                                                else
                                                                    printf("%s = %s\n", (yyvsp[-2].char_ptr), op.var_name);

                                                            }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 306 "parser.y" /* yacc.c:1646  */
    { scope_error_check((yyvsp[-2].char_ptr)); trace("Assignment Rule 2\n");}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 307 "parser.y" /* yacc.c:1646  */
    { trace("Array Element Assign Rule"); }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 331 "parser.y" /* yacc.c:1646  */
    {
                                                                char op[3] = "&&";
                                                                print_TAC_operator(op);
                                                            }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 335 "parser.y" /* yacc.c:1646  */
    {
                                                                char op[3] = "||";
                                                                print_TAC_operator(op);
                                                            }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 339 "parser.y" /* yacc.c:1646  */
    {
                                                                stack_node op = popStack(three_address_code_stack);
                                                                curr_buff = get_new_node(TAC_code);


                                                                pushStack(three_address_code_stack, TEMP_VAR);
                                                                print_st(three_address_code_stack, curr_buff);

                                                                if(BUFFER_ENABLED) {
                                                                    sprintf(temp_buf, " = NOT %s\n", op.var_name);
                                                                    strcat(curr_buff->code, temp_buf);
                                                                }
                                                                else
                                                                    printf(" = NOT %s\n", op.var_name);
                                                            }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 358 "parser.y" /* yacc.c:1646  */
    {
                                                                    char op[3] = ">";
                                                                    print_TAC_operator(op);
                                                                }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 362 "parser.y" /* yacc.c:1646  */
    {
                                                                    char op[3] = "<";
                                                                    print_TAC_operator(op);
                                                                }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 366 "parser.y" /* yacc.c:1646  */
    {
                                                                    char op[3] = ">=";
                                                                    print_TAC_operator(op);
                                                                }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 370 "parser.y" /* yacc.c:1646  */
    {
                                                                    char op[3] = "<=";
                                                                    print_TAC_operator(op);
                                                                }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 374 "parser.y" /* yacc.c:1646  */
    {
                                                                    char op[3] = "==";
                                                                    print_TAC_operator(op);
                                                                }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 378 "parser.y" /* yacc.c:1646  */
    {
                                                                    char op[3] = "<>";
                                                                    print_TAC_operator(op);
                                                                }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 386 "parser.y" /* yacc.c:1646  */
    {
                                                            char op[3] = "+";
                                                            print_TAC_operator(op);
                                                        }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 390 "parser.y" /* yacc.c:1646  */
    {
                                                            char op[3] = "-";
                                                            print_TAC_operator(op);
                                                        }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 399 "parser.y" /* yacc.c:1646  */
    {
                                                            char op[3] = "*";
                                                            print_TAC_operator(op);
                                                        }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 403 "parser.y" /* yacc.c:1646  */
    {
                                                            char op[3] = "-";
                                                            print_TAC_operator(op);
                                                        }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 407 "parser.y" /* yacc.c:1646  */
    {
                                                            char op[3] = "%";
                                                            print_TAC_operator(op);
                                                        }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 416 "parser.y" /* yacc.c:1646  */
    {pushStack(three_address_code_stack, (yyvsp[0].char_ptr));symbl_tbl_insrt(constant_table, (yyvsp[0].char_ptr), -1, "int", "", yylineno); trace("CONSTANT_INTEGER\n");}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 417 "parser.y" /* yacc.c:1646  */
    {pushStack(three_address_code_stack, (yyvsp[0].char_ptr));symbl_tbl_insrt(constant_table, (yyvsp[0].char_ptr), -1, "float", "", yylineno); trace("CONSTANT_FLOAT\n");}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 418 "parser.y" /* yacc.c:1646  */
    {pushStack(three_address_code_stack, (yyvsp[0].char_ptr));symbl_tbl_insrt(constant_table, (yyvsp[0].char_ptr), -1, "char", "", yylineno); trace("CONSTANT_CHAR\n");}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 419 "parser.y" /* yacc.c:1646  */
    {pushStack(three_address_code_stack, (yyvsp[0].char_ptr));symbl_tbl_insrt(constant_table, (yyvsp[0].char_ptr), -1, "string", "", yylineno); trace("CONSTANT_STRING\n");}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 420 "parser.y" /* yacc.c:1646  */
    {pushStack(three_address_code_stack, (yyvsp[0].char_ptr)); scope_error_check((yyvsp[0].char_ptr));trace("Primary Identifier\n");}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 421 "parser.y" /* yacc.c:1646  */
    {pushStack(three_address_code_stack, (yyvsp[0].char_ptr)); scope_error_check((yyvsp[0].char_ptr));trace("Pointer Identifier\n");}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 422 "parser.y" /* yacc.c:1646  */
    {pushStack(three_address_code_stack, (yyvsp[0].char_ptr)); scope_error_check((yyvsp[0].char_ptr));trace("Address of Identifier\n");}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 427 "parser.y" /* yacc.c:1646  */
    {scope_error_check((yyvsp[0].char_ptr));}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 428 "parser.y" /* yacc.c:1646  */
    {scope_error_check((yyvsp[-1].char_ptr));}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 429 "parser.y" /* yacc.c:1646  */
    {scope_error_check((yyvsp[0].char_ptr));}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 430 "parser.y" /* yacc.c:1646  */
    {scope_error_check((yyvsp[-1].char_ptr));}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 438 "parser.y" /* yacc.c:1646  */
    {   curr_scope = add_child_scope(curr_scope);   }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 443 "parser.y" /* yacc.c:1646  */
    {   curr_scope = goto_parent_scope(curr_scope);   }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 461 "parser.y" /* yacc.c:1646  */
    {
                    curr_buff = get_new_node(TAC_code);
                    sprintf(temp_buf, "GOTO L%d:\n", loopEndLabel);
                    strcat(curr_buff->code, temp_buf);
                }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 466 "parser.y" /* yacc.c:1646  */
    {
                    curr_buff = get_new_node(TAC_code);
                    sprintf(temp_buf, "GOTO L%d:\n", loopStartLabel);
                    strcat(curr_buff->code, temp_buf);
                }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 475 "parser.y" /* yacc.c:1646  */
    {trace("Return_Statement Call\n");}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 479 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(curr_buff->code, "GOTO L%d\n", (yyvsp[-5].intval));
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(curr_buff->code, "\nL%d:\n", (yyvsp[-1].intval));
                                                                                    }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 485 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(curr_buff->code, "GOTO L%d\n", (yyvsp[-5].intval));
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(curr_buff->code, "\nL%d:\n", (yyvsp[-1].intval));
                                                                                    }
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 494 "parser.y" /* yacc.c:1646  */
    {
            curr_buff = get_new_node(TAC_code);
            sprintf(temp_buf, "L%d:\n", LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            loopStartLabel = LABEL_COUNT;
            (yyval.intval) = LABEL_COUNT++;
        }
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 504 "parser.y" /* yacc.c:1646  */
    {
            stack_node reg = popStack(three_address_code_stack);
            curr_buff = get_new_node(TAC_code);

            sprintf(temp_buf, "IF NOT %s GOTO L%d\n", reg.var_name, LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            loopEndLabel = LABEL_COUNT;

            (yyval.intval) = LABEL_COUNT++;
        }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 517 "parser.y" /* yacc.c:1646  */
    {
                                                                                            stack_node reg = popStack(three_address_code_stack);
                                                                                            curr_buff = get_new_node(TAC_code);

                                                                                            sprintf(temp_buf, "IF %s GOTO L%d\n", reg.var_name, (yyvsp[-6].intval));
                                                                                            strcat(curr_buff->code, temp_buf);
                                                                                        }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 527 "parser.y" /* yacc.c:1646  */
    {
            curr_buff = get_new_node(TAC_code);
            sprintf(temp_buf, "L%d:\n", LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            loopStartLabel = LABEL_COUNT;

            (yyval.intval) = LABEL_COUNT++;
        }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 539 "parser.y" /* yacc.c:1646  */
    {
                                                                                                TAC_buffer_node *temp = TAC_code->stack_arr[TAC_code->top -1];
                                                                                                while(temp->next != NULL)
                                                                                                    temp = temp->next;
                                                                                                temp->next = TAC_code->stack_arr[TAC_code->top];
                                                                                                TAC_code->stack_arr[TAC_code->top] = NULL;

                                                                                                while(temp->next != NULL)
                                                                                                    temp = temp->next;
                                                                                                temp->next = TAC_code->stack_arr[TAC_code->top -2];
                                                                                                TAC_code->stack_arr[TAC_code->top -2] = TAC_code->stack_arr[TAC_code->top -1];
                                                                                                TAC_code->stack_arr[TAC_code->top -1] = NULL;
                                                                                                TAC_code->top -= 2;

                                                                                                curr_buff = get_new_node(TAC_code);
                                                                                                sprintf(curr_buff->code, "GOTO L%d\n", (yyvsp[-7].intval));
                                                                                                curr_buff = get_new_node(TAC_code);
                                                                                                sprintf(curr_buff->code, "\nL%d:\n", (yyvsp[-4].intval));
                                                                                            }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 559 "parser.y" /* yacc.c:1646  */
    {
                                                                                                TAC_buffer_node *temp = TAC_code->stack_arr[TAC_code->top -1];
                                                                                                while(temp->next != NULL)
                                                                                                    temp = temp->next;
                                                                                                temp->next = TAC_code->stack_arr[TAC_code->top];
                                                                                                TAC_code->stack_arr[TAC_code->top] = NULL;

                                                                                                while(temp->next != NULL)
                                                                                                    temp = temp->next;
                                                                                                temp->next = TAC_code->stack_arr[TAC_code->top -2];
                                                                                                TAC_code->stack_arr[TAC_code->top -2] = TAC_code->stack_arr[TAC_code->top -1];
                                                                                                TAC_code->stack_arr[TAC_code->top -1] = NULL;
                                                                                                TAC_code->top -= 2;

                                                                                                curr_buff = get_new_node(TAC_code);
                                                                                                sprintf(curr_buff->code, "GOTO L%d\n", (yyvsp[-7].intval));
                                                                                                curr_buff = get_new_node(TAC_code);
                                                                                                sprintf(curr_buff->code, "\nL%d:\n", (yyvsp[-4].intval));
                                                                                            }
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 581 "parser.y" /* yacc.c:1646  */
    { TAC_code->top++; }
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 585 "parser.y" /* yacc.c:1646  */
    {
            curr_buff = get_new_node(TAC_code);
            sprintf(temp_buf, "L%d:\n", LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            loopStartLabel = LABEL_COUNT;
            (yyval.intval) = LABEL_COUNT++;
        }
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 595 "parser.y" /* yacc.c:1646  */
    {
            stack_node reg = popStack(three_address_code_stack);
            curr_buff = get_new_node(TAC_code);

            sprintf(temp_buf, "IF NOT %s GOTO L%d\n", reg.var_name, LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            loopEndLabel = LABEL_COUNT;

            (yyval.intval) = LABEL_COUNT++;
            TAC_code->top++;
        }
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 608 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", (yyvsp[-1].intval));
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    }
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 613 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", (yyvsp[-1].intval));
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    }
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 619 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", (yyvsp[-3].intval));
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    }
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 624 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", (yyvsp[-2].intval));
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    }
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 630 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", (yyvsp[-3].intval));
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 635 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", (yyvsp[-2].intval));
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    }
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 641 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", (yyvsp[-3].intval));
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 646 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", (yyvsp[-2].intval));
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 652 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", (yyvsp[-3].intval));
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    }
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 657 "parser.y" /* yacc.c:1646  */
    {
                                                                                        curr_buff = get_new_node(TAC_code);
                                                                                        sprintf(temp_buf, "\nL%d:\n", (yyvsp[-2].intval));
                                                                                        strcat(curr_buff->code, temp_buf);
                                                                                    }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 666 "parser.y" /* yacc.c:1646  */
    {
            stack_node reg = popStack(three_address_code_stack);
            curr_buff = get_new_node(TAC_code);

            if(BUFFER_ENABLED) {
                sprintf(temp_buf, "IF NOT %s GOTO L%d\n", reg.var_name, LABEL_COUNT);
                strcat(curr_buff->code, temp_buf);
            }
            else
                printf("IF NOT %s GOTO L%d\n", reg.var_name, LABEL_COUNT);

            (yyval.intval) = LABEL_COUNT++;
        }
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 682 "parser.y" /* yacc.c:1646  */
    {
            curr_buff = get_new_node(TAC_code);
            sprintf(temp_buf, "GOTO L%d\n", LABEL_COUNT);
            strcat(curr_buff->code, temp_buf);
            (yyval.intval) = LABEL_COUNT++;
        }
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 691 "parser.y" /* yacc.c:1646  */
    { scope_error_check((yyvsp[-3].char_ptr)); num_param_check((yyvsp[-3].char_ptr)); check_is_function((yyvsp[-3].char_ptr)); /*symbl_tbl_insrt(symbol_table, $1, curr_scope->scope_num, "Function", "", yylineno);trace("Function Call\n"); */}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 695 "parser.y" /* yacc.c:1646  */
    {scope_error_check((yyvsp[-1].char_ptr));}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 696 "parser.y" /* yacc.c:1646  */
    {scope_error_check((yyvsp[-3].char_ptr));scope_error_check((yyvsp[-1].char_ptr));}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2463 "y.tab.c" /* yacc.c:1646  */
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
#line 704 "parser.y" /* yacc.c:1906  */


inline void print_TAC_operator(char *op) {

    curr_buff = get_new_node(TAC_code);
    stack_node op2 = popStack(three_address_code_stack);
    stack_node op1 = popStack(three_address_code_stack);

    pushStack(three_address_code_stack, TEMP_VAR);
    print_st(three_address_code_stack, curr_buff);

    if(BUFFER_ENABLED) {
        sprintf(temp_buf, " = %s %s %s\n", op1.var_name, op, op2.var_name);
        strcat(curr_buff->code, temp_buf);
    }
    else
        printf(" = %s %s %s\n", op1.var_name, op, op2.var_name);
}

// used the function defined in scope.c for checing the scope error
inline void scope_error_check(char *symbol){
    if(!scope_check(symbol_table, symbol, curr_scope)){
        yyerror(strcat(symbol, " not found in current or ancestor scopes"));
    }
}


// we had count of parameter which we are again verfitying 
// it should have equal count as it has in declaration.
inline void num_param_check(char *symbol) {

    symbol_node_t *node = scope_check(symbol_table, symbol, curr_scope);
    char msg[100] = "Too few arguments passed to ";
    if(node != NULL && num_params > node->num_params) {
        yyerror(strcat(msg, symbol));
    }
    else if(node != NULL && num_params < node->num_params) {
        yyerror(strcat(msg, symbol));
    }
}

inline void redeclaration_error_check(char *symbol){
    if(check_in_current_scope(symbol_table, symbol, curr_scope)){
        yyerror(strcat(symbol, " already declared in current scope"));
    }
}

symbol_node_t * redefined_error_check(char *symbol){
    symbol_node_t *node = scope_check(symbol_table, symbol, curr_scope);


    if(node != NULL && node->is_function_defined)
        yyerror(strcat(symbol, " : a redefinition"));

    return node;
}

inline void arr_dimension_check(char *symbol, char *arr_size){

    if(atoi(arr_size) < 1){ //  function of ascii to integer 
        yyerror(strcat(symbol, " has non-positive array size"));
    }
}

inline void arr_subscript_check(char *symbol){


    symbol_node_t *node = symbl_tbl_lkp(symbol_table, symbol);

    if(!strstr(node->type, "Array")){ // this function returns the first occurence of substring in other
        yyerror(strcat(symbol, " is not an array"));
    }
}



inline void void_param_check(char *type) {
    if(!strcmp(type, "void")) {
        yyerror("Parameter of function has void datatype");
    }
}

inline void check_is_function(char *func_name) {

    symbol_node_t *node = symbl_tbl_lkp(symbol_table, func_name);
    if(node == NULL) {
        yyerror(strcat(func_name, " function not declared"));
    }
    if(!strstr(node->type, "Function")) {
        yyerror(strcat(func_name, " is not a function"));
    }
}

inline void trace(char *s){
    if(TRACE_ENABLED)
        fprintf(stderr, FORE_CYN "%-20.20s%20.20s%20d\n" RESET, s, yytext, yylineno);
}


int main()
{
    curr_scope = init_scope();
    symbl_tbl_initlze(symbol_table);
    symbl_tbl_initlze(constant_table);
    three_address_code_stack = init_s();

    TAC_code = init_code_stack();
    printf("\n");

    yyparse();

    print_TAC_code(TAC_code);

    // symbl_tbl_prnt(symbol_table, "Symbol Table");
    // symbl_tbl_prnt(constant_table, "Constant Table"); 
    printf(FORE_GRN "\n\n Parsing complete  ✔ \n\n" RESET);

    symbl_tbl_fr(symbol_table);
    symbl_tbl_fr(constant_table);

    // TODO: Free Scope
    f_s(three_address_code_stack);
    return 0;
}


void yyerror(const char *s) {


        printf(FORE_RED "%d : %s %s\n" RESET, yylineno, s, yytext ); // FOR_RED are for color, defined in ascii color code 

        // these re defined in misc.h so that we can use them here easily and convinently
    printf(FORE_RED "\nParsing failed ✘ \n\n" RESET);
    exit(-2);
}
