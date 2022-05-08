/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     INC_OP = 262,
     DEC_OP = 263,
     LEFT_OP = 264,
     RIGHT_OP = 265,
     LE_OP = 266,
     GE_OP = 267,
     EQ_OP = 268,
     NE_OP = 269,
     AND_OP = 270,
     OR_OP = 271,
     MUL_ASSIGN = 272,
     DIV_ASSIGN = 273,
     MOD_ASSIGN = 274,
     ADD_ASSIGN = 275,
     SUB_ASSIGN = 276,
     LEFT_ASSIGN = 277,
     RIGHT_ASSIGN = 278,
     AND_ASSIGN = 279,
     XOR_ASSIGN = 280,
     OR_ASSIGN = 281,
     CHAR = 282,
     SHORT = 283,
     INT = 284,
     LONG = 285,
     FLOAT = 286,
     DOUBLE = 287,
     VOID = 288,
     ELLIPSIS = 289,
     IF = 290,
     ELSE = 291,
     WHILE = 292,
     DO = 293,
     FOR = 294,
     CONTINUE = 295,
     BREAK = 296,
     RETURN = 297
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define INC_OP 262
#define DEC_OP 263
#define LEFT_OP 264
#define RIGHT_OP 265
#define LE_OP 266
#define GE_OP 267
#define EQ_OP 268
#define NE_OP 269
#define AND_OP 270
#define OR_OP 271
#define MUL_ASSIGN 272
#define DIV_ASSIGN 273
#define MOD_ASSIGN 274
#define ADD_ASSIGN 275
#define SUB_ASSIGN 276
#define LEFT_ASSIGN 277
#define RIGHT_ASSIGN 278
#define AND_ASSIGN 279
#define XOR_ASSIGN 280
#define OR_ASSIGN 281
#define CHAR 282
#define SHORT 283
#define INT 284
#define LONG 285
#define FLOAT 286
#define DOUBLE 287
#define VOID 288
#define ELLIPSIS 289
#define IF 290
#define ELSE 291
#define WHILE 292
#define DO 293
#define FOR 294
#define CONTINUE 295
#define BREAK 296
#define RETURN 297




/* Copy the first part of user declarations.  */
#line 1 "grammar.y"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<vector>
#include "ast.h"
#include "define.cpp"

int yylex();
void yyerror(char const *s);

extern exprAST* ROOT;
stack<exprAST*> tokenStack;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "grammar.y"
{
	class exprAST* exprPtr;
}
/* Line 193 of yacc.c.  */
#line 200 "grammar.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 213 "grammar.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   680

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNRULES -- Number of states.  */
#define YYNSTATES  222

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,    58,    51,     2,
      43,    44,    56,    54,    59,    55,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    65,
      52,    62,    53,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,    49,    64,    60,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    16,    18,    21,
      23,    25,    27,    29,    31,    33,    35,    37,    39,    43,
      48,    52,    57,    61,    63,    65,    71,    73,    77,    79,
      83,    85,    89,    91,    95,    97,   101,   103,   107,   111,
     113,   117,   121,   125,   129,   131,   135,   139,   141,   145,
     149,   151,   155,   159,   163,   165,   170,   172,   174,   178,
     180,   184,   186,   189,   192,   195,   198,   203,   205,   210,
     214,   219,   222,   225,   227,   229,   231,   235,   237,   241,
     243,   245,   247,   249,   251,   253,   255,   257,   259,   261,
     263,   265,   267,   269,   271,   273,   275,   277,   281,   283,
     287,   290,   293,   297,   301,   306,   308,   311,   313,   316,
     318,   320,   322,   324,   326,   328,   331,   337,   345,   351,
     359,   366,   374,   382,   385,   388,   391,   395,   399,   401,
     405,   407
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      67,     0,    -1,    68,    -1,    67,    68,    -1,    69,    -1,
     107,    -1,    70,    72,    99,    -1,    71,    -1,    71,    70,
      -1,    33,    -1,    27,    -1,    28,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    73,    -1,     3,    -1,    43,
      72,    44,    -1,    73,    45,    74,    46,    -1,    73,    45,
      46,    -1,    73,    43,    96,    44,    -1,    73,    43,    44,
      -1,    75,    -1,    76,    -1,    76,    47,    88,    48,    75,
      -1,    77,    -1,    76,    16,    77,    -1,    78,    -1,    77,
      15,    78,    -1,    79,    -1,    78,    49,    79,    -1,    80,
      -1,    79,    50,    80,    -1,    81,    -1,    80,    51,    81,
      -1,    82,    -1,    81,    13,    82,    -1,    81,    14,    82,
      -1,    83,    -1,    82,    52,    83,    -1,    82,    53,    83,
      -1,    82,    11,    83,    -1,    82,    12,    83,    -1,    84,
      -1,    83,     9,    84,    -1,    83,    10,    84,    -1,    85,
      -1,    84,    54,    85,    -1,    84,    55,    85,    -1,    86,
      -1,    85,    56,    86,    -1,    85,    57,    86,    -1,    85,
      58,    86,    -1,    90,    -1,    43,    87,    44,    86,    -1,
      71,    -1,    89,    -1,    88,    59,    89,    -1,    75,    -1,
      90,    95,    89,    -1,    91,    -1,     7,    90,    -1,     8,
      90,    -1,    94,    86,    -1,     6,    90,    -1,     6,    43,
      87,    44,    -1,    92,    -1,    91,    45,    88,    46,    -1,
      91,    43,    44,    -1,    91,    43,    93,    44,    -1,    91,
       7,    -1,    91,     8,    -1,     3,    -1,     4,    -1,     5,
      -1,    43,    88,    44,    -1,    89,    -1,    93,    59,    89,
      -1,    51,    -1,    56,    -1,    54,    -1,    55,    -1,    60,
      -1,    61,    -1,    62,    -1,    17,    -1,    18,    -1,    19,
      -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    26,    -1,    97,    -1,    97,    59,    34,
      -1,    98,    -1,    97,    59,    98,    -1,    70,    72,    -1,
      63,    64,    -1,    63,   100,    64,    -1,    63,   101,    64,
      -1,    63,   101,   100,    64,    -1,   102,    -1,   100,   102,
      -1,   107,    -1,   101,   107,    -1,    99,    -1,   103,    -1,
     104,    -1,   105,    -1,   106,    -1,    65,    -1,    88,    65,
      -1,    35,    43,    88,    44,   102,    -1,    35,    43,    88,
      44,   102,    36,   102,    -1,    37,    43,    88,    44,   102,
      -1,    38,   102,    37,    43,    88,    44,    65,    -1,    39,
      43,   103,   103,    44,   102,    -1,    39,    43,   103,   103,
      88,    44,   102,    -1,    39,    43,   107,   103,    88,    44,
     102,    -1,    40,    65,    -1,    41,    65,    -1,    42,    65,
      -1,    42,    88,    65,    -1,    70,   108,    65,    -1,   109,
      -1,   108,    59,   109,    -1,    72,    -1,    72,    62,    89,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    55,    67,    72,    82,    93,    98,   108,
     109,   110,   111,   112,   113,   114,   119,   129,   136,   145,
     155,   164,   174,   188,   198,   203,   219,   224,   237,   242,
     255,   260,   273,   278,   291,   296,   309,   314,   322,   335,
     340,   348,   356,   364,   377,   382,   390,   403,   408,   416,
     429,   434,   442,   450,   463,   468,   483,   493,   498,   511,
     516,   528,   533,   540,   547,   553,   560,   576,   581,   591,
     600,   610,   617,   630,   637,   644,   651,   665,   670,   683,
     684,   685,   686,   687,   688,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   710,   715,   729,   734,
     747,   758,   766,   775,   784,   799,   804,   815,   820,   831,
     836,   841,   846,   851,   861,   867,   879,   891,   911,   923,
     939,   952,   966,   985,   993,  1001,  1009,  1023,  1036,  1041,
    1053,  1058
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN",
  "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "CHAR", "SHORT",
  "INT", "LONG", "FLOAT", "DOUBLE", "VOID", "ELLIPSIS", "IF", "ELSE",
  "WHILE", "DO", "FOR", "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['",
  "']'", "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "','", "'~'", "'!'", "'='", "'{'", "'}'", "';'",
  "$accept", "translation_unit", "external_declaration",
  "function_definition", "declaration_specifiers", "type_specifier",
  "declarator", "direct_declarator", "constant_expression",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "type_name",
  "expression", "assignment_expression", "unary_expression",
  "postfix_expression", "primary_expression", "argument_expression_list",
  "unary_operator", "assignment_operator", "parameter_type_list",
  "parameter_list", "parameter_declaration", "compound_statement",
  "statement_list", "declaration_list", "statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "declaration", "init_declarator_list",
  "init_declarator", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    40,    41,    91,    93,    63,    58,   124,
      94,    38,    60,    62,    43,    45,    42,    47,    37,    44,
     126,    33,    61,   123,   125,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    72,    73,    73,    73,
      73,    73,    73,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    81,    82,
      82,    82,    82,    82,    83,    83,    83,    84,    84,    84,
      85,    85,    85,    85,    86,    86,    87,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    92,    92,    92,    92,    93,    93,    94,
      94,    94,    94,    94,    94,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    97,    97,
      98,    99,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   102,   102,   102,   103,   103,   104,   104,   105,   105,
     105,   105,   105,   106,   106,   106,   106,   107,   108,   108,
     109,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     4,     3,     1,     1,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     4,     1,     1,     3,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     4,     3,
       4,     2,     2,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       2,     2,     3,     3,     4,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     5,     7,     5,     7,
       6,     7,     7,     2,     2,     2,     3,     3,     1,     3,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,    12,    13,    14,    15,     9,     0,     2,
       4,     0,     7,     5,     1,     3,    17,     0,   130,    16,
       0,   128,     8,     0,     0,     0,     6,     0,     0,     0,
     127,    18,    73,    74,    75,     0,     0,     0,     0,    79,
      81,    82,    80,    83,    84,    59,    24,    26,    28,    30,
      32,    34,    36,    39,    44,    47,    50,   131,    54,    61,
      67,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     114,     0,     0,    57,   109,     0,     0,   105,   110,   111,
     112,   113,   107,    22,     0,     0,    96,    98,    20,     0,
      23,    54,   130,   129,     0,    65,     0,    62,    63,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    85,     0,    71,    72,     0,     0,    64,     0,     0,
       0,     0,   123,   124,   125,     0,     0,   115,   102,   106,
     103,     0,   108,   100,    21,     0,    19,     0,     0,    76,
      27,     0,    29,    31,    33,    35,    37,    38,    42,    43,
      40,    41,    45,    46,    48,    49,    51,    52,    53,    60,
      69,    77,     0,     0,     0,     0,     0,     0,     0,   126,
      58,   104,    97,    99,    66,    55,     0,    70,     0,    68,
       0,     0,     0,     0,     0,    25,    78,   116,   118,     0,
       0,     0,     0,     0,     0,   120,     0,     0,   117,   119,
     121,   122
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    71,    12,    92,    19,    89,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,   100,    72,    73,    58,    59,    60,   182,    61,   132,
      85,    86,    87,    74,    75,    76,    77,    78,    79,    80,
      81,    13,    20,    21
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
     124,  -136,  -136,  -136,  -136,  -136,  -136,  -136,    12,  -136,
    -136,     4,   124,  -136,  -136,  -136,  -136,     4,     8,    64,
     -40,  -136,  -136,   -17,   137,   178,  -136,    85,   518,     4,
    -136,  -136,  -136,  -136,  -136,   605,   619,   619,   487,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,     7,    22,    25,    -1,
       5,   114,     6,   123,    80,    41,  -136,  -136,   268,    24,
    -136,   137,    23,    58,   342,    67,    40,    65,   414,  -136,
    -136,     4,   -39,  -136,  -136,   260,   219,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,     4,    93,    89,  -136,  -136,   121,
    -136,  -136,   106,  -136,   487,  -136,   137,  -136,  -136,  -136,
     127,   -30,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,   137,  -136,  -136,   546,   137,  -136,   137,   137,
     135,   383,  -136,  -136,  -136,    -8,   137,  -136,  -136,  -136,
    -136,   301,  -136,  -136,  -136,   340,  -136,   129,   137,  -136,
      22,    17,    25,    -1,     5,   114,     6,     6,   123,   123,
     123,   123,    80,    80,    41,    41,  -136,  -136,  -136,  -136,
    -136,  -136,   -23,    14,   -11,    -9,   132,   446,   446,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,   137,  -136,   137,  -136,
     342,   342,   137,   577,   137,  -136,  -136,   140,  -136,     2,
     342,    60,    62,   342,   112,  -136,   342,   342,  -136,  -136,
    -136,  -136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,   170,  -136,     3,   -22,    11,  -136,  -136,   -26,
    -136,    77,    83,    84,    88,    92,    38,    13,    46,    47,
     -56,    96,     0,   -24,   -27,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,    45,   177,   120,  -136,   -51,  -135,  -136,  -136,
    -136,   -21,  -136,   172
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      57,    91,    90,    11,    82,   137,   187,    16,    95,    97,
      98,    11,    14,   140,   159,    22,    99,   110,   111,    29,
     146,   197,    18,   102,   149,    30,   147,    31,    23,   146,
      84,   133,   134,   200,    91,   201,   198,   104,   101,     1,
       2,     3,     4,     5,     6,     7,   214,    17,   146,   106,
     146,   146,   203,   204,   103,   152,   107,   189,   112,   113,
     199,   146,   176,   177,   178,   196,   138,   135,   145,   136,
      24,    25,    99,   146,   105,    91,   146,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,   101,   153,   101,   118,   119,   120,
     149,   139,   195,   161,   216,   142,   217,    27,   179,    28,
     141,   181,     1,     2,     3,     4,     5,     6,     7,   146,
     188,   146,   190,   168,   169,   170,   171,   108,   109,    83,
     143,    91,   114,   115,   116,   117,   183,   154,   184,   185,
      32,    33,    34,    35,    36,    37,   166,   167,   155,   207,
     208,     1,     2,     3,     4,     5,     6,     7,    84,   215,
     172,   173,   218,   174,   175,   220,   221,   156,    24,    91,
     205,   158,   186,   194,   206,   202,   213,   219,    15,   160,
      38,    32,    33,    34,    35,    36,    37,   162,    39,   163,
     157,    40,    41,    42,   164,    26,   151,    43,    44,   165,
     193,    93,   209,   211,   212,     1,     2,     3,     4,     5,
       6,     7,     0,    62,     0,    63,    64,    65,    66,    67,
      68,    38,    32,    33,    34,    35,    36,    37,     0,    39,
       0,     0,    40,    41,    42,     0,     0,     0,    43,    44,
       0,    25,    69,    70,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     0,    62,     0,    63,    64,    65,    66,
      67,    68,    38,    32,    33,    34,    35,    36,    37,     0,
      39,     0,     0,    40,    41,    42,     0,     0,     0,    43,
      44,     0,    25,   150,    70,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    62,     0,    63,    64,    65,
      66,    67,    68,    38,    32,    33,    34,    35,    36,    37,
       0,    39,     0,     0,    40,    41,    42,     0,     0,     0,
      43,    44,     0,    25,   148,    70,     0,     0,     0,     0,
     131,     0,     0,     0,     0,     0,    62,     0,    63,    64,
      65,    66,    67,    68,    38,    32,    33,    34,    35,    36,
      37,     0,    39,     0,     0,    40,    41,    42,     0,     0,
       0,    43,    44,     0,    25,   191,    70,     1,     2,     3,
       4,     5,     6,     7,   192,     0,     0,    62,     0,    63,
      64,    65,    66,    67,    68,    38,    32,    33,    34,    35,
      36,    37,     0,    39,     0,     0,    40,    41,    42,     0,
       0,     0,    43,    44,     0,    25,     0,    70,     0,     0,
       1,     2,     3,     4,     5,     6,     7,    32,    33,    34,
      35,    36,    37,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,    40,    41,    42,
       0,     0,     0,    43,    44,     0,     0,     0,    70,    32,
      33,    34,    35,    36,    37,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,    40,    41,
      42,     0,     0,     0,    43,    44,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      32,    33,    34,    35,    36,    37,     0,    39,     0,     0,
      40,    41,    42,     0,     0,     0,    43,    44,     0,     0,
       0,    70,     0,     0,     1,     2,     3,     4,     5,     6,
       7,    32,    33,    34,    35,    36,    37,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,    39,     0,
       0,    40,    41,    42,     0,     0,     0,    43,    44,    32,
      33,    34,    35,    36,    37,     0,     0,     0,     0,     0,
       0,    38,     0,     0,    88,     0,     0,     0,     0,    39,
       0,     0,    40,    41,    42,     0,     0,     0,    43,    44,
      32,    33,    34,    35,    36,    37,     0,     0,     0,    38,
     180,     0,     0,     0,     0,     0,     0,    39,     0,     0,
      40,    41,    42,     0,     0,     0,    43,    44,    32,    33,
      34,    35,    36,    37,     0,     0,     0,     0,     0,     0,
      38,   210,    32,    33,    34,    35,    36,    37,    39,     0,
       0,    40,    41,    42,     0,     0,     0,    43,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,    40,
      41,    42,    96,     0,     0,    43,    44,     0,     0,     0,
      39,     0,     0,    40,    41,    42,     0,     0,     0,    43,
      44
};

static const yytype_int16 yycheck[] =
{
      24,    28,    28,     0,    25,    61,   141,     3,    35,    36,
      37,     8,     0,    64,    44,    12,    38,    11,    12,    59,
      59,    44,    11,    16,    75,    65,    65,    44,    17,    59,
      27,     7,     8,    44,    61,    44,    59,    15,    38,    27,
      28,    29,    30,    31,    32,    33,    44,    43,    59,    50,
      59,    59,   187,   188,    47,    76,    51,    65,    52,    53,
      46,    59,   118,   119,   120,    48,    43,    43,    68,    45,
      62,    63,    94,    59,    49,   102,    59,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    94,    84,    96,    56,    57,    58,
     151,    43,   158,   103,    44,    65,    44,    43,   132,    45,
      43,   135,    27,    28,    29,    30,    31,    32,    33,    59,
     141,    59,   146,   110,   111,   112,   113,    13,    14,    44,
      65,   158,     9,    10,    54,    55,   136,    44,   138,   139,
       3,     4,     5,     6,     7,     8,   108,   109,    59,   200,
     201,    27,    28,    29,    30,    31,    32,    33,   155,   210,
     114,   115,   213,   116,   117,   216,   217,    46,    62,   196,
     196,    44,    37,    44,   198,    43,    36,    65,     8,   102,
      43,     3,     4,     5,     6,     7,     8,   104,    51,   105,
      94,    54,    55,    56,   106,    18,    76,    60,    61,   107,
     155,    29,   202,   203,   204,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,     3,     4,     5,     6,     7,     8,    -1,    51,
      -1,    -1,    54,    55,    56,    -1,    -1,    -1,    60,    61,
      -1,    63,    64,    65,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,     3,     4,     5,     6,     7,     8,    -1,
      51,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,    60,
      61,    -1,    63,    64,    65,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,     3,     4,     5,     6,     7,     8,
      -1,    51,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      60,    61,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,     3,     4,     5,     6,     7,
       8,    -1,    51,    -1,    -1,    54,    55,    56,    -1,    -1,
      -1,    60,    61,    -1,    63,    64,    65,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,     3,     4,     5,     6,
       7,     8,    -1,    51,    -1,    -1,    54,    55,    56,    -1,
      -1,    -1,    60,    61,    -1,    63,    -1,    65,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    55,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    65,     3,
       4,     5,     6,     7,     8,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    55,
      56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
       3,     4,     5,     6,     7,     8,    -1,    51,    -1,    -1,
      54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    65,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    54,    55,    56,    -1,    -1,    -1,    60,    61,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    55,    56,    -1,    -1,    -1,    60,    61,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    55,    56,    -1,    -1,    -1,    60,    61,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,     3,     4,     5,     6,     7,     8,    51,    -1,
      -1,    54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      55,    56,    43,    -1,    -1,    60,    61,    -1,    -1,    -1,
      51,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,    60,
      61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    28,    29,    30,    31,    32,    33,    67,    68,
      69,    70,    71,   107,     0,    68,     3,    43,    72,    73,
     108,   109,    70,    72,    62,    63,    99,    43,    45,    59,
      65,    44,     3,     4,     5,     6,     7,     8,    43,    51,
      54,    55,    56,    60,    61,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    89,    90,    91,
      92,    94,    35,    37,    38,    39,    40,    41,    42,    64,
      65,    70,    88,    89,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    44,    70,    96,    97,    98,    46,    74,
      75,    90,    72,   109,    43,    90,    43,    90,    90,    71,
      87,    88,    16,    47,    15,    49,    50,    51,    13,    14,
      11,    12,    52,    53,     9,    10,    54,    55,    56,    57,
      58,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    62,    95,     7,     8,    43,    45,    86,    43,    43,
     102,    43,    65,    65,    65,    88,    59,    65,    64,   102,
      64,   100,   107,    72,    44,    59,    46,    87,    44,    44,
      77,    88,    78,    79,    80,    81,    82,    82,    83,    83,
      83,    83,    84,    84,    85,    85,    86,    86,    86,    89,
      44,    89,    93,    88,    88,    88,    37,   103,   107,    65,
      89,    64,    34,    98,    44,    86,    48,    44,    59,    46,
      44,    44,    43,   103,   103,    75,    89,   102,   102,    88,
      44,    88,    88,    36,    44,   102,    44,    44,   102,    65,
     102,   102
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 49 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new translation_unit("translation_unit", 1, children);
		ROOT = (yyval.exprPtr);
	;}
    break;

  case 3:
#line 55 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (2)].exprPtr));
		children.push_back((yyvsp[(2) - (2)].exprPtr));
		(yyval.exprPtr) = new translation_unit("translation_unit", 2, children);
		ROOT = (yyval.exprPtr);
	;}
    break;

  case 4:
#line 67 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new external_declaration("external_declaration", 1, children);
	;}
    break;

  case 5:
#line 72 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new external_declaration("external_declaration", 2, children);
	;}
    break;

  case 6:
#line 82 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back((yyvsp[(2) - (3)].exprPtr));
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new function_definition("function_definition", 1, children);
	;}
    break;

  case 7:
#line 93 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new declaration_specifiers("declaration_specifiers", 1, children);
	;}
    break;

  case 8:
#line 98 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (2)].exprPtr));
		children.push_back((yyvsp[(2) - (2)].exprPtr));
		(yyval.exprPtr) = new declaration_specifiers("declaration_specifiers", 2, children);
	;}
    break;

  case 9:
#line 108 "grammar.y"
    { (yyval.exprPtr) = new typeAST(1); ;}
    break;

  case 10:
#line 109 "grammar.y"
    { (yyval.exprPtr) = new typeAST(2);;}
    break;

  case 11:
#line 110 "grammar.y"
    { (yyval.exprPtr) = new typeAST(3);;}
    break;

  case 12:
#line 111 "grammar.y"
    { (yyval.exprPtr) = new typeAST(4);;}
    break;

  case 13:
#line 112 "grammar.y"
    { (yyval.exprPtr) = new typeAST(5);;}
    break;

  case 14:
#line 113 "grammar.y"
    { (yyval.exprPtr) = new typeAST(6);;}
    break;

  case 15:
#line 114 "grammar.y"
    { (yyval.exprPtr) = new typeAST(7);;}
    break;

  case 16:
#line 119 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new declarator("declarator", 1, children);
	;}
    break;

  case 17:
#line 129 "grammar.y"
    { 
		exprAST* id = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(id);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 1, children);
	;}
    break;

  case 18:
#line 136 "grammar.y"
    { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[(2) - (3)].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 2, children);
	;}
    break;

  case 19:
#line 145 "grammar.y"
    { 
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (4)].exprPtr));
		children.push_back(left);
		children.push_back((yyvsp[(3) - (4)].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 3, children);
	;}
    break;

  case 20:
#line 155 "grammar.y"
    { 
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 4, children);
	;}
    break;

  case 21:
#line 164 "grammar.y"
    { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (4)].exprPtr));
		children.push_back(left);
		children.push_back((yyvsp[(3) - (4)].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 5, children);
	;}
    break;

  case 22:
#line 174 "grammar.y"
    { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 6, children);
	;}
    break;

  case 23:
#line 188 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new constant_expression("constant_expression", 1, children);
	;}
    break;

  case 24:
#line 198 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new conditional_expression("conditional_expression", 1, children);
	;}
    break;

  case 25:
#line 203 "grammar.y"
    {
		exprAST* questionMark = new punctuationAST("?");
		exprAST* colon = new punctuationAST(":");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (5)].exprPtr));
		children.push_back(questionMark);
		children.push_back((yyvsp[(3) - (5)].exprPtr));
		children.push_back(colon);
		children.push_back((yyvsp[(5) - (5)].exprPtr));
		(yyval.exprPtr) = new conditional_expression("conditional_expression", 2, children);
	;}
    break;

  case 26:
#line 219 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new logical_or_expression("logical_or_expression", 1, children);
	;}
    break;

  case 27:
#line 224 "grammar.y"
    {
		exprAST* orOp = new operatorAST("||");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(orOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new logical_or_expression("logical_or_expression", 2, children);
	;}
    break;

  case 28:
#line 237 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new logical_and_expression("logical_and_expression", 1, children);
	;}
    break;

  case 29:
#line 242 "grammar.y"
    {
		exprAST* andOp = new operatorAST("&&");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(andOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new logical_and_expression("logical_and_expression", 2, children);
	;}
    break;

  case 30:
#line 255 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new inclusive_or_expression("inclusive_or_expression", 1, children);
	;}
    break;

  case 31:
#line 260 "grammar.y"
    {
		exprAST* orOp = new operatorAST("|");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(orOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new inclusive_or_expression("inclusive_or_expression", 2, children);
	;}
    break;

  case 32:
#line 273 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new exclusive_or_expression("exclusive_or_expression", 1, children);
	;}
    break;

  case 33:
#line 278 "grammar.y"
    {
		exprAST* xorOp = new operatorAST("^");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(xorOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new exclusive_or_expression("exclusive_or_expression", 2, children);
	;}
    break;

  case 34:
#line 291 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new and_expression("and_expression", 1, children);
	;}
    break;

  case 35:
#line 296 "grammar.y"
    {
		exprAST* andOp = new operatorAST("&");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(andOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new and_expression("and_expression", 2, children);
	;}
    break;

  case 36:
#line 309 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new equality_expression("equality_expression", 1, children);
	;}
    break;

  case 37:
#line 314 "grammar.y"
    {
		exprAST* eqOp = new operatorAST("==");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(eqOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new equality_expression("equality_expression", 2, children);
	;}
    break;

  case 38:
#line 322 "grammar.y"
    {
		exprAST* neOp = new operatorAST("!=");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(neOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new equality_expression("equality_expression", 3, children);
	;}
    break;

  case 39:
#line 335 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 1, children);
	;}
    break;

  case 40:
#line 340 "grammar.y"
    {
		exprAST* lessOp = new operatorAST("<");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(lessOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 2, children);
	;}
    break;

  case 41:
#line 348 "grammar.y"
    {
		exprAST* greaterOp = new operatorAST(">");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(greaterOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 3, children);
	;}
    break;

  case 42:
#line 356 "grammar.y"
    {
		exprAST* lessEqualOp = new operatorAST("<=");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(lessEqualOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 4, children);
	;}
    break;

  case 43:
#line 364 "grammar.y"
    {
		exprAST* greaterEqualOp = new operatorAST(">=");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(greaterEqualOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 5, children);
	;}
    break;

  case 44:
#line 377 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new shift_expression("shift_expression", 1, children);
	;}
    break;

  case 45:
#line 382 "grammar.y"
    {
		exprAST* leftOp = new operatorAST("<<");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(leftOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new shift_expression("shift_expression", 2, children);
	;}
    break;

  case 46:
#line 390 "grammar.y"
    {
		exprAST* rightOp = new operatorAST(">>");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(rightOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new shift_expression("shift_expression", 3, children);
	;}
    break;

  case 47:
#line 403 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new additive_expression("additive_expression", 1, children);
	;}
    break;

  case 48:
#line 408 "grammar.y"
    {
		exprAST* addOp = new operatorAST("+");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(addOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new additive_expression("additive_expression", 2, children);
	;}
    break;

  case 49:
#line 416 "grammar.y"
    {
		exprAST* subOp = new operatorAST("-");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(subOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new additive_expression("additive_expression", 3, children);
	;}
    break;

  case 50:
#line 429 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 1, children);
	;}
    break;

  case 51:
#line 434 "grammar.y"
    {
		exprAST* mulOp = new operatorAST("*");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(mulOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 2, children);
	;}
    break;

  case 52:
#line 442 "grammar.y"
    {
		exprAST* divOp = new operatorAST("/");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(divOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 3, children);
	;}
    break;

  case 53:
#line 450 "grammar.y"
    {
		exprAST* modOp = new operatorAST("%");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(modOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 4, children);
	;}
    break;

  case 54:
#line 463 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new cast_expression("cast_expression", 1, children);
	;}
    break;

  case 55:
#line 468 "grammar.y"
    {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[(2) - (4)].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[(4) - (4)].exprPtr));
		(yyval.exprPtr) = new cast_expression("cast_expression", 2, children);
	;}
    break;

  case 56:
#line 483 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new type_name("type_name", 1, children);
	;}
    break;

  case 57:
#line 493 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new expression("expression", 1, children);
	;}
    break;

  case 58:
#line 498 "grammar.y"
    {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new expression("expression", 2, children);
	;}
    break;

  case 59:
#line 511 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new assignment_expression("assignment_expression", 1, children);
	;}
    break;

  case 60:
#line 516 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back((yyvsp[(2) - (3)].exprPtr));
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new assignment_expression("assignment_expression", 2, children);
	;}
    break;

  case 61:
#line 528 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 1, children);
	;}
    break;

  case 62:
#line 533 "grammar.y"
    {
		exprAST* incOp = new operatorAST("++");
		vector<exprAST*> children;
		children.push_back(incOp);
		children.push_back((yyvsp[(2) - (2)].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 2, children);
	;}
    break;

  case 63:
#line 540 "grammar.y"
    {
		exprAST* decOp = new operatorAST("--");
		vector<exprAST*> children;
		children.push_back(decOp);
		children.push_back((yyvsp[(2) - (2)].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 3, children);
	;}
    break;

  case 64:
#line 547 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (2)].exprPtr));
		children.push_back((yyvsp[(2) - (2)].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 4, children);
	;}
    break;

  case 65:
#line 553 "grammar.y"
    {
		exprAST* sizeOf = new keywordAST("sizeof");
		vector<exprAST*> children;
		children.push_back(sizeOf);
		children.push_back((yyvsp[(2) - (2)].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 5, children);
	;}
    break;

  case 66:
#line 560 "grammar.y"
    {
		exprAST* sizeOf = new keywordAST("sizeof");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(sizeOf);
		children.push_back(left);
		children.push_back((yyvsp[(3) - (4)].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new unary_expression("unary_expression", 6, children);
	;}
    break;

  case 67:
#line 576 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 1, children);
	;}
    break;

  case 68:
#line 581 "grammar.y"
    {
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (4)].exprPtr));
		children.push_back(left);
		children.push_back((yyvsp[(3) - (4)].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 2, children);
	;}
    break;

  case 69:
#line 591 "grammar.y"
    {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 3, children);
	;}
    break;

  case 70:
#line 600 "grammar.y"
    {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (4)].exprPtr));
		children.push_back(left);
		children.push_back((yyvsp[(3) - (4)].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 4, children);
	;}
    break;

  case 71:
#line 610 "grammar.y"
    {
		exprAST* incOp = new operatorAST("++");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (2)].exprPtr));
		children.push_back(incOp);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 5, children);
	;}
    break;

  case 72:
#line 617 "grammar.y"
    {
		exprAST* decOp = new operatorAST("--");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (2)].exprPtr));
		children.push_back(decOp);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 6, children);
	;}
    break;

  case 73:
#line 630 "grammar.y"
    {
		exprAST* identifier = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(identifier);
		(yyval.exprPtr) = new primary_expression("primary_expression", 1, children);
	;}
    break;

  case 74:
#line 637 "grammar.y"
    {
		exprAST* constant = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(constant);
		(yyval.exprPtr) = new primary_expression("primary_expression", 2, children);
	;}
    break;

  case 75:
#line 644 "grammar.y"
    {
		exprAST* str = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(str);
		(yyval.exprPtr) = new primary_expression("primary_expression", 3, children);
	;}
    break;

  case 76:
#line 651 "grammar.y"
    {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[(2) - (3)].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new primary_expression("primary_expression", 4, children);
	;}
    break;

  case 77:
#line 665 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new argument_expression_list("argument_expression_list", 1, children);
	;}
    break;

  case 78:
#line 670 "grammar.y"
    {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new argument_expression_list("argument_expression_list", 2, children);
	;}
    break;

  case 79:
#line 683 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("&"); ;}
    break;

  case 80:
#line 684 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("*"); ;}
    break;

  case 81:
#line 685 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("+"); ;}
    break;

  case 82:
#line 686 "grammar.y"
    {	(yyval.exprPtr) = new operatorAST("-"); ;}
    break;

  case 83:
#line 687 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("~"); ;}
    break;

  case 84:
#line 688 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("!"); ;}
    break;

  case 85:
#line 694 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("="); ;}
    break;

  case 86:
#line 695 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("*="); ;}
    break;

  case 87:
#line 696 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("/="); ;}
    break;

  case 88:
#line 697 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("%="); ;}
    break;

  case 89:
#line 698 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("+="); ;}
    break;

  case 90:
#line 699 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("-="); ;}
    break;

  case 91:
#line 700 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("<<="); ;}
    break;

  case 92:
#line 701 "grammar.y"
    { (yyval.exprPtr) = new operatorAST(">>="); ;}
    break;

  case 93:
#line 702 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("&="); ;}
    break;

  case 94:
#line 703 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("^="); ;}
    break;

  case 95:
#line 704 "grammar.y"
    { (yyval.exprPtr) = new operatorAST("|="); ;}
    break;

  case 96:
#line 710 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new parameter_type_list("parameter_type_list", 1, children);
	;}
    break;

  case 97:
#line 715 "grammar.y"
    {
		exprAST* comma = new punctuationAST(",");
		exprAST* ellipsis = new keywordAST("...");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(comma);
		children.push_back(ellipsis);
		(yyval.exprPtr) = new parameter_type_list("parameter_type_list", 2, children);
	;}
    break;

  case 98:
#line 729 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new parameter_list("parameter_list", 1, children);
	;}
    break;

  case 99:
#line 734 "grammar.y"
    {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new parameter_list("parameter_list", 2, children);
	;}
    break;

  case 100:
#line 747 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (2)].exprPtr));
		children.push_back((yyvsp[(2) - (2)].exprPtr));
		(yyval.exprPtr) = new parameter_declaration("parameter_declaration", 1, children);
	;}
    break;

  case 101:
#line 758 "grammar.y"
    { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 1, children);
	;}
    break;

  case 102:
#line 766 "grammar.y"
    { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[(2) - (3)].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 2, children);
	;}
    break;

  case 103:
#line 775 "grammar.y"
    { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[(2) - (3)].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 3, children);
	;}
    break;

  case 104:
#line 784 "grammar.y"
    { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[(2) - (4)].exprPtr));
		children.push_back((yyvsp[(3) - (4)].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 4, children);
	;}
    break;

  case 105:
#line 799 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new statement_list("statement_list", 1, children);
	;}
    break;

  case 106:
#line 804 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (2)].exprPtr));
		children.push_back((yyvsp[(2) - (2)].exprPtr));
		(yyval.exprPtr) = new statement_list("statement_list", 2, children);
	;}
    break;

  case 107:
#line 815 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new declaration_list("declaration_list", 1, children);
	;}
    break;

  case 108:
#line 820 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (2)].exprPtr));
		children.push_back((yyvsp[(2) - (2)].exprPtr));
		(yyval.exprPtr) = new declaration_list("declaration_list", 2, children);
	;}
    break;

  case 109:
#line 831 "grammar.y"
    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new statement("statement", 1, children);
	;}
    break;

  case 110:
#line 836 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new statement("statement", 2, children);
	;}
    break;

  case 111:
#line 841 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new statement("statement", 3, children);
	;}
    break;

  case 112:
#line 846 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new statement("statement", 4, children);
	;}
    break;

  case 113:
#line 851 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new statement("statement", 5, children);
	;}
    break;

  case 114:
#line 861 "grammar.y"
    { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(semiColon);
		(yyval.exprPtr) = new expression_statement("expression_statement", 1, children);
	;}
    break;

  case 115:
#line 867 "grammar.y"
    { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (2)].exprPtr));
		children.push_back(semiColon);
		(yyval.exprPtr) = new expression_statement("expression_statement", 2, children);
	;}
    break;

  case 116:
#line 879 "grammar.y"
    { 
		exprAST* oneIF = new keywordAST("if");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneIF);
		children.push_back(left);
		children.push_back((yyvsp[(3) - (5)].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[(5) - (5)].exprPtr));
		(yyval.exprPtr) = new selection_statement("selection_statement", 1, children);
	;}
    break;

  case 117:
#line 891 "grammar.y"
    { 
		exprAST* oneIF = new keywordAST("if");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		exprAST* oneELSE = new keywordAST("else");
		vector<exprAST*> children;
		children.push_back(oneIF);
		children.push_back(left);
		children.push_back((yyvsp[(3) - (7)].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[(5) - (7)].exprPtr));
		children.push_back(oneELSE);
		children.push_back((yyvsp[(7) - (7)].exprPtr));
		(yyval.exprPtr) = new selection_statement("selection_statement", 2, children);
	;}
    break;

  case 118:
#line 911 "grammar.y"
    { 
		exprAST* oneWHILE = new keywordAST("while");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneWHILE);
		children.push_back(left);
		children.push_back((yyvsp[(3) - (5)].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[(5) - (5)].exprPtr));
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 1, children);
	;}
    break;

  case 119:
#line 923 "grammar.y"
    { 
		exprAST* oneDO = new keywordAST("do");
		exprAST* oneWHILE = new keywordAST("while");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneDO);
		children.push_back((yyvsp[(2) - (7)].exprPtr));
		children.push_back(oneWHILE);
		children.push_back(left);
		children.push_back((yyvsp[(5) - (7)].exprPtr));
		children.push_back(right);
		children.push_back(semiColon);
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 2, children);
	;}
    break;

  case 120:
#line 939 "grammar.y"
    { 
		exprAST* oneFOR = new keywordAST("for");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneFOR);
		children.push_back(left);
		children.push_back((yyvsp[(3) - (6)].exprPtr));
		children.push_back((yyvsp[(4) - (6)].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[(6) - (6)].exprPtr));
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 3, children);
	;}
    break;

  case 121:
#line 952 "grammar.y"
    { 
		exprAST* oneFOR = new keywordAST("for");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneFOR);
		children.push_back(left);
		children.push_back((yyvsp[(3) - (7)].exprPtr));
		children.push_back((yyvsp[(4) - (7)].exprPtr));
		children.push_back((yyvsp[(5) - (7)].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[(7) - (7)].exprPtr));
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 4, children);
	;}
    break;

  case 122:
#line 966 "grammar.y"
    {
		exprAST* oneFOR = new keywordAST("for");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneFOR);
		children.push_back(left);
		children.push_back((yyvsp[(3) - (7)].exprPtr));
		children.push_back((yyvsp[(4) - (7)].exprPtr));
		children.push_back((yyvsp[(5) - (7)].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[(7) - (7)].exprPtr));
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 5, children);
	;}
    break;

  case 123:
#line 985 "grammar.y"
    { 
		exprAST* oneCONTINUE = new keywordAST("continue");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneCONTINUE);
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 1, children);
	;}
    break;

  case 124:
#line 993 "grammar.y"
    { 
		exprAST* oneBREAK = new keywordAST("break");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneBREAK);
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 2, children);
	;}
    break;

  case 125:
#line 1001 "grammar.y"
    { 
		exprAST* oneRETURN = new keywordAST("return");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneRETURN);
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 3, children);
	;}
    break;

  case 126:
#line 1009 "grammar.y"
    { 
		exprAST* oneRETURN = new keywordAST("return");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneRETURN);
		children.push_back((yyvsp[(2) - (3)].exprPtr));
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 4, children);
	;}
    break;

  case 127:
#line 1023 "grammar.y"
    { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back((yyvsp[(2) - (3)].exprPtr));
		children.push_back(semiColon);
		(yyval.exprPtr) = new declaration("declaration", 1, children);
	;}
    break;

  case 128:
#line 1036 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new init_declarator_list("init_declarator_list", 1, children);
	;}
    break;

  case 129:
#line 1041 "grammar.y"
    {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new init_declarator_list("init_declarator_list", 2, children);
	;}
    break;

  case 130:
#line 1053 "grammar.y"
    {
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (1)].exprPtr));
		(yyval.exprPtr) = new init_declarator("init_declarator", 1, children);
	;}
    break;

  case 131:
#line 1058 "grammar.y"
    {
		exprAST* eqOp = new operatorAST("=");
		vector<exprAST*> children;
		children.push_back((yyvsp[(1) - (3)].exprPtr));
		children.push_back(eqOp);
		children.push_back((yyvsp[(3) - (3)].exprPtr));
		(yyval.exprPtr) = new init_declarator("init_declarator", 2, children);
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 3058 "grammar.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1068 "grammar.y"



void yyerror(char const *s){
    printf("Error Information\n");
    printf("%s at %s\n",s,yytext);
	return ;
}



