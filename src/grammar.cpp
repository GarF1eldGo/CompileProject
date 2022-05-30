/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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

#line 87 "/home/lumina/Documents/CompileProject/src/grammar.cpp"

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

#include "grammar.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_SIZEOF = 6,                     /* SIZEOF  */
  YYSYMBOL_CHAR_LITERAL = 7,               /* CHAR_LITERAL  */
  YYSYMBOL_INC_OP = 8,                     /* INC_OP  */
  YYSYMBOL_DEC_OP = 9,                     /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 10,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 11,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 13,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 16,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 17,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 18,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 19,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 20,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 21,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 22,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 23,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 24,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 25,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 26,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 27,                 /* OR_ASSIGN  */
  YYSYMBOL_CHAR = 28,                      /* CHAR  */
  YYSYMBOL_SHORT = 29,                     /* SHORT  */
  YYSYMBOL_INT = 30,                       /* INT  */
  YYSYMBOL_LONG = 31,                      /* LONG  */
  YYSYMBOL_FLOAT = 32,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 33,                    /* DOUBLE  */
  YYSYMBOL_VOID = 34,                      /* VOID  */
  YYSYMBOL_ELLIPSIS = 35,                  /* ELLIPSIS  */
  YYSYMBOL_IF = 36,                        /* IF  */
  YYSYMBOL_ELSE = 37,                      /* ELSE  */
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_DO = 39,                        /* DO  */
  YYSYMBOL_FOR = 40,                       /* FOR  */
  YYSYMBOL_CONTINUE = 41,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_RETURN = 43,                    /* RETURN  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* '['  */
  YYSYMBOL_48_ = 48,                       /* ']'  */
  YYSYMBOL_49_ = 49,                       /* '?'  */
  YYSYMBOL_50_ = 50,                       /* ':'  */
  YYSYMBOL_51_ = 51,                       /* '|'  */
  YYSYMBOL_52_ = 52,                       /* '^'  */
  YYSYMBOL_53_ = 53,                       /* '&'  */
  YYSYMBOL_54_ = 54,                       /* '<'  */
  YYSYMBOL_55_ = 55,                       /* '>'  */
  YYSYMBOL_56_ = 56,                       /* '+'  */
  YYSYMBOL_57_ = 57,                       /* '-'  */
  YYSYMBOL_58_ = 58,                       /* '*'  */
  YYSYMBOL_59_ = 59,                       /* '/'  */
  YYSYMBOL_60_ = 60,                       /* '%'  */
  YYSYMBOL_61_ = 61,                       /* ','  */
  YYSYMBOL_62_ = 62,                       /* '~'  */
  YYSYMBOL_63_ = 63,                       /* '!'  */
  YYSYMBOL_64_ = 64,                       /* '='  */
  YYSYMBOL_65_ = 65,                       /* '{'  */
  YYSYMBOL_66_ = 66,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_translation_unit = 68,          /* translation_unit  */
  YYSYMBOL_external_declaration = 69,      /* external_declaration  */
  YYSYMBOL_function_definition = 70,       /* function_definition  */
  YYSYMBOL_type_specifier = 71,            /* type_specifier  */
  YYSYMBOL_declarator = 72,                /* declarator  */
  YYSYMBOL_constant_expression = 73,       /* constant_expression  */
  YYSYMBOL_conditional_expression = 74,    /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 75,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 76,    /* logical_and_expression  */
  YYSYMBOL_inclusive_or_expression = 77,   /* inclusive_or_expression  */
  YYSYMBOL_exclusive_or_expression = 78,   /* exclusive_or_expression  */
  YYSYMBOL_and_expression = 79,            /* and_expression  */
  YYSYMBOL_equality_expression = 80,       /* equality_expression  */
  YYSYMBOL_relational_expression = 81,     /* relational_expression  */
  YYSYMBOL_shift_expression = 82,          /* shift_expression  */
  YYSYMBOL_additive_expression = 83,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 84, /* multiplicative_expression  */
  YYSYMBOL_cast_expression = 85,           /* cast_expression  */
  YYSYMBOL_type_name = 86,                 /* type_name  */
  YYSYMBOL_expression = 87,                /* expression  */
  YYSYMBOL_assignment_expression = 88,     /* assignment_expression  */
  YYSYMBOL_unary_expression = 89,          /* unary_expression  */
  YYSYMBOL_postfix_expression = 90,        /* postfix_expression  */
  YYSYMBOL_primary_expression = 91,        /* primary_expression  */
  YYSYMBOL_argument_expression_list = 92,  /* argument_expression_list  */
  YYSYMBOL_unary_operator = 93,            /* unary_operator  */
  YYSYMBOL_assignment_operator = 94,       /* assignment_operator  */
  YYSYMBOL_parameter_list = 95,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 96,     /* parameter_declaration  */
  YYSYMBOL_compound_statement = 97,        /* compound_statement  */
  YYSYMBOL_statement_list = 98,            /* statement_list  */
  YYSYMBOL_declaration_list = 99,          /* declaration_list  */
  YYSYMBOL_statement = 100,                /* statement  */
  YYSYMBOL_expression_statement = 101,     /* expression_statement  */
  YYSYMBOL_selection_statement = 102,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 103,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 104,           /* jump_statement  */
  YYSYMBOL_declaration = 105,              /* declaration  */
  YYSYMBOL_init_declarator_list = 106,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 107           /* init_declarator  */
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
typedef yytype_uint8 yy_state_t;

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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   685

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
       2,     2,     2,    63,     2,     2,     2,    60,    53,     2,
      45,    46,    58,    56,    61,    57,     2,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    44,
      54,    64,    55,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,    51,    66,    62,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    55,    67,    72,    85,    98,    99,   100,
     101,   102,   103,   104,   109,   116,   125,   135,   144,   154,
     168,   178,   183,   199,   204,   217,   222,   235,   240,   253,
     258,   271,   276,   289,   294,   302,   315,   320,   328,   336,
     344,   357,   362,   370,   383,   388,   396,   409,   414,   422,
     430,   443,   448,   463,   473,   478,   491,   496,   508,   513,
     520,   527,   533,   540,   556,   561,   571,   580,   590,   597,
     610,   617,   624,   631,   640,   652,   657,   670,   671,   672,
     673,   674,   675,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,   691,   699,   704,   717,   728,   736,   745,
     754,   769,   774,   785,   790,   801,   806,   811,   816,   821,
     831,   837,   849,   861,   881,   893,   906,   920,   939,   947,
     955,   963,   977,   990,   995,  1007,  1012
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "CHAR_LITERAL", "INC_OP",
  "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "CHAR", "SHORT", "INT", "LONG", "FLOAT",
  "DOUBLE", "VOID", "ELLIPSIS", "IF", "ELSE", "WHILE", "DO", "FOR",
  "CONTINUE", "BREAK", "RETURN", "';'", "'('", "')'", "'['", "']'", "'?'",
  "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "','", "'~'", "'!'", "'='", "'{'", "'}'", "$accept",
  "translation_unit", "external_declaration", "function_definition",
  "type_specifier", "declarator", "constant_expression",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "type_name",
  "expression", "assignment_expression", "unary_expression",
  "postfix_expression", "primary_expression", "argument_expression_list",
  "unary_operator", "assignment_operator", "parameter_list",
  "parameter_declaration", "compound_statement", "statement_list",
  "declaration_list", "statement", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "declaration", "init_declarator_list", "init_declarator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    59,    40,    41,    91,    93,    63,
      58,   124,    94,    38,    60,    62,    43,    45,    42,    47,
      37,    44,   126,    33,    61,   123,   125
};
#endif

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      87,  -116,  -116,  -116,  -116,  -116,  -116,  -116,    76,  -116,
    -116,    10,  -116,  -116,  -116,    10,   150,    29,  -116,   -31,
     153,    26,   561,   160,  -116,  -116,    10,  -116,  -116,    10,
     -42,  -116,  -116,  -116,  -116,   593,  -116,   622,   622,   439,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,   -26,  -116,   -12,
      56,   -39,    61,    41,   131,    57,   138,    95,   148,  -116,
    -116,    30,  -116,   561,  -116,  -116,    27,    77,   109,   166,
     177,   180,   239,  -116,  -116,    10,    34,  -116,  -116,   267,
     224,  -116,  -116,  -116,  -116,  -116,  -116,    -3,  -116,   -27,
    -116,    87,   439,  -116,   561,  -116,  -116,  -116,   188,   -20,
    -116,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
    -116,  -116,   471,   561,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,   561,   561,   561,   396,
    -116,  -116,  -116,    36,    42,  -116,   561,  -116,  -116,  -116,
     310,  -116,  -116,   189,   561,  -116,    56,   -33,   -39,    61,
      41,   131,    57,    57,   138,   138,   138,   138,    95,    95,
     148,   148,  -116,  -116,  -116,  -116,  -116,    35,   -38,  -116,
      98,   101,   500,   500,  -116,  -116,  -116,  -116,  -116,  -116,
     561,  -116,   561,  -116,   353,   353,   532,   561,  -116,  -116,
     199,  -116,   353,   111,   112,   353,  -116,   353,   353,  -116,
    -116,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     8,     9,    10,    11,    12,    13,     7,     0,     2,
       4,     0,     1,     3,    14,     0,   125,     0,   123,     0,
       0,     0,     0,     0,     6,     5,     0,    15,    19,     0,
       0,    94,    70,    71,    72,     0,    74,     0,     0,     0,
      17,    77,    79,    80,    78,    81,    82,     0,    20,    21,
      23,    25,    27,    29,    31,    33,    36,    41,    44,    47,
      51,    58,    64,     0,    56,   126,    51,     0,     0,     0,
       0,     0,     0,   110,    97,     0,     0,    54,   105,     0,
       0,   101,   106,   107,   108,   109,   103,   125,   124,    96,
      18,     0,     0,    62,     0,    59,    60,    53,     0,     0,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      68,    69,     0,     0,    61,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    83,     0,     0,     0,     0,
     118,   119,   120,     0,     0,   111,     0,    98,   102,    99,
       0,   104,    95,     0,     0,    73,    24,     0,    26,    28,
      30,    32,    34,    35,    39,    40,    37,    38,    42,    43,
      45,    46,    48,    49,    50,    66,    75,     0,     0,    57,
       0,     0,     0,     0,   121,   122,    55,   100,    63,    52,
       0,    67,     0,    65,     0,     0,     0,     0,    22,    76,
     112,   114,     0,     0,     0,     0,   115,     0,     0,   113,
     116,   117
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,   229,  -116,     1,    -4,  -116,   -19,  -116,   137,
     136,   145,   135,   144,    67,    68,    96,   104,   -55,   149,
     -36,   -22,    22,  -116,  -116,  -116,  -116,  -116,  -116,   168,
     235,   181,  -116,   -52,  -115,  -116,  -116,  -116,   -74,   203,
     237
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    75,    87,    47,    64,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    98,
      76,    77,    66,    61,    62,   177,    63,   136,    30,    31,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    17,
      18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      65,    11,    48,    99,    90,   101,   151,    16,   124,    11,
     193,    19,   104,    14,    20,    27,    21,   190,    20,    91,
      21,    29,   100,   146,   182,    89,   155,   148,   146,    32,
      33,    34,    35,    36,    37,    38,   143,   102,   120,   121,
      97,   146,    20,    60,    21,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    15,    99,    93,    99,    95,
      96,    22,   172,   173,   174,   183,   157,   196,   197,   109,
     110,    39,   103,    25,    40,   122,    12,   123,   145,    41,
     184,   191,    42,    43,    44,    60,   185,   178,    45,    46,
      26,   135,    29,    97,   106,   146,   192,   146,   148,   189,
     176,   180,   181,    26,     1,     2,     3,     4,     5,     6,
       7,   111,   112,   105,   179,     1,     2,     3,     4,     5,
       6,     7,   137,    60,   186,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,   200,   201,   194,   107,   108,   195,   113,   114,
     206,   115,   116,   209,   138,   210,   211,   207,   208,   146,
     203,   204,   146,    32,    33,    34,    35,    36,    37,    38,
     199,   198,   146,   146,   162,   163,    60,   164,   165,   166,
     167,     1,     2,     3,     4,     5,     6,     7,     1,     2,
       3,     4,     5,     6,     7,    20,    67,    21,    68,    28,
      69,    70,    71,    72,    73,    39,   117,   118,   119,   168,
     169,   139,    60,    41,    22,    23,    42,    43,    44,   170,
     171,   140,    45,    46,   141,    23,    74,    32,    33,    34,
      35,    36,    37,    38,   154,   188,   205,    13,   156,   158,
     160,   153,    32,    33,    34,    35,    36,    37,    38,   159,
     161,    24,     1,     2,     3,     4,     5,     6,     7,   152,
      67,   150,    68,    88,    69,    70,    71,    72,    73,    39,
      32,    33,    34,    35,    36,    37,    38,    41,   144,     0,
      42,    43,    44,   142,    39,     0,    45,    46,     0,    23,
     149,     0,    41,     0,     0,    42,    43,    44,     0,     0,
       0,    45,    46,    67,     0,    68,     0,    69,    70,    71,
      72,    73,    39,    32,    33,    34,    35,    36,    37,    38,
      41,     0,     0,    42,    43,    44,     0,     0,     0,    45,
      46,     0,    23,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,    68,     0,
      69,    70,    71,    72,    73,    39,    32,    33,    34,    35,
      36,    37,    38,    41,     0,     0,    42,    43,    44,     0,
       0,     0,    45,    46,     0,    23,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,    68,     0,    69,    70,    71,    72,    73,    39,    32,
      33,    34,    35,    36,    37,    38,    41,     0,     0,    42,
      43,    44,     0,     0,     0,    45,    46,     0,    23,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    39,    32,    33,    34,    35,    36,    37,    38,    41,
       0,     0,    42,    43,    44,     0,     0,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,    32,    33,    34,    35,    36,    37,
      38,     0,     0,     0,    39,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,    42,    43,    44,     0,     0,
       0,    45,    46,    32,    33,    34,    35,    36,    37,    38,
       0,     0,     0,     0,     0,     0,    39,   175,     0,     0,
       0,     0,     0,     0,    41,     0,     0,    42,    43,    44,
       0,     0,     0,    45,    46,    32,    33,    34,    35,    36,
      37,    38,     0,     0,    73,    39,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,    42,    43,    44,     0,
       0,     0,    45,    46,    32,    33,    34,    35,    36,    37,
      38,     0,     0,     0,     0,     0,     0,    39,   202,     0,
       0,     0,     0,     0,     0,    41,     0,     0,    42,    43,
      44,     0,     0,     0,    45,    46,    32,    33,    34,    35,
      36,    37,    38,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,    42,    43,    44,
       0,     0,     0,    45,    46,    32,    33,    34,    35,    36,
      37,    38,     0,     0,     0,     0,     0,     0,    92,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,    42,
      43,    44,     0,     0,     0,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,    42,    43,
      44,     0,     0,     0,    45,    46
};

static const yytype_int16 yycheck[] =
{
      22,     0,    21,    39,    46,    17,    80,    11,    63,     8,
      48,    15,    51,     3,    45,    46,    47,    50,    45,    61,
      47,    20,    48,    61,   139,    29,    46,    79,    61,     3,
       4,     5,     6,     7,     8,     9,    72,    49,     8,     9,
      39,    61,    45,    21,    47,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    45,    92,    35,    94,    37,
      38,    64,   117,   118,   119,   139,   102,   182,   183,    12,
      13,    45,    16,    44,    48,    45,     0,    47,    44,    53,
      44,    46,    56,    57,    58,    63,    44,   123,    62,    63,
      61,    64,    91,    92,    53,    61,    61,    61,   150,   154,
     122,   137,   138,    61,    28,    29,    30,    31,    32,    33,
      34,    54,    55,    52,   136,    28,    29,    30,    31,    32,
      33,    34,    45,   101,   146,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   194,   195,    46,    14,    15,    46,    10,    11,
     202,    56,    57,   205,    45,   207,   208,    46,    46,    61,
     196,   197,    61,     3,     4,     5,     6,     7,     8,     9,
     192,   190,    61,    61,   107,   108,   154,   109,   110,   111,
     112,    28,    29,    30,    31,    32,    33,    34,    28,    29,
      30,    31,    32,    33,    34,    45,    36,    47,    38,    46,
      40,    41,    42,    43,    44,    45,    58,    59,    60,   113,
     114,    45,   190,    53,    64,    65,    56,    57,    58,   115,
     116,    44,    62,    63,    44,    65,    66,     3,     4,     5,
       6,     7,     8,     9,    46,    46,    37,     8,   101,   103,
     105,    92,     3,     4,     5,     6,     7,     8,     9,   104,
     106,    16,    28,    29,    30,    31,    32,    33,    34,    91,
      36,    80,    38,    26,    40,    41,    42,    43,    44,    45,
       3,     4,     5,     6,     7,     8,     9,    53,    75,    -1,
      56,    57,    58,    44,    45,    -1,    62,    63,    -1,    65,
      66,    -1,    53,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    62,    63,    36,    -1,    38,    -1,    40,    41,    42,
      43,    44,    45,     3,     4,     5,     6,     7,     8,     9,
      53,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,
      40,    41,    42,    43,    44,    45,     3,     4,     5,     6,
       7,     8,     9,    53,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    40,    41,    42,    43,    44,    45,     3,
       4,     5,     6,     7,     8,     9,    53,    -1,    -1,    56,
      57,    58,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,     3,     4,     5,     6,     7,     8,     9,    53,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    62,    63,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    62,    63,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    62,    63,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    62,    63,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    62,    63,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,
      57,    58,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    62,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    29,    30,    31,    32,    33,    34,    68,    69,
      70,    71,     0,    69,     3,    45,    72,   106,   107,    72,
      45,    47,    64,    65,    97,    44,    61,    46,    46,    71,
      95,    96,     3,     4,     5,     6,     7,     8,     9,    45,
      48,    53,    56,    57,    58,    62,    63,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      89,    90,    91,    93,    74,    88,    89,    36,    38,    40,
      41,    42,    43,    44,    66,    71,    87,    88,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    72,   107,    72,
      46,    61,    45,    89,    45,    89,    89,    71,    86,    87,
      48,    17,    49,    16,    51,    52,    53,    14,    15,    12,
      13,    54,    55,    10,    11,    56,    57,    58,    59,    60,
       8,     9,    45,    47,    85,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    64,    94,    45,    45,    45,
      44,    44,    44,    87,   106,    44,    61,    66,   100,    66,
      98,   105,    96,    86,    46,    46,    76,    87,    77,    78,
      79,    80,    81,    81,    82,    82,    82,    82,    83,    83,
      84,    84,    85,    85,    85,    46,    88,    92,    87,    88,
      87,    87,   101,   105,    44,    44,    88,    66,    46,    85,
      50,    46,    61,    48,    46,    46,   101,   101,    74,    88,
     100,   100,    46,    87,    87,    37,   100,    46,    46,   100,
     100,   100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    68,    69,    69,    70,    71,    71,    71,
      71,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    80,    81,    81,    81,    81,
      81,    82,    82,    82,    83,    83,    83,    84,    84,    84,
      84,    85,    85,    86,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    91,    92,    92,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    95,    95,    96,    97,    97,    97,
      97,    98,    98,    99,    99,   100,   100,   100,   100,   100,
     101,   101,   102,   102,   103,   103,   103,   103,   104,   104,
     104,   104,   105,   106,   106,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     4,     3,
       1,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     4,     1,     1,     3,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     4,     3,     4,     2,     2,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     5,     7,     5,     6,     7,     7,     2,     2,
       2,     3,     3,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* translation_unit: external_declaration  */
#line 49 "grammar.y"
                           { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new translation_unit("translation_unit", 1, children);
		ROOT = (yyval.exprPtr);
	}
#line 1454 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 3: /* translation_unit: translation_unit external_declaration  */
#line 55 "grammar.y"
                                            {
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new translation_unit("translation_unit", 2, children);
		ROOT = (yyval.exprPtr);
	}
#line 1466 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 4: /* external_declaration: function_definition  */
#line 67 "grammar.y"
                          { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new external_declaration("external_declaration", 1, children);
	}
#line 1476 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 5: /* external_declaration: type_specifier init_declarator_list ';'  */
#line 72 "grammar.y"
                                              { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(semiColon);
		(yyval.exprPtr) = new external_declaration("external_declaration", 2, children);
	}
#line 1489 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 6: /* function_definition: type_specifier declarator compound_statement  */
#line 85 "grammar.y"
                                                   {
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new function_definition("function_definition", 1, children);
	}
#line 1501 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 7: /* type_specifier: VOID  */
#line 98 "grammar.y"
               { (yyval.exprPtr) = new typeAST(1); }
#line 1507 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 8: /* type_specifier: CHAR  */
#line 99 "grammar.y"
               { (yyval.exprPtr) = new typeAST(2);}
#line 1513 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 9: /* type_specifier: SHORT  */
#line 100 "grammar.y"
                { (yyval.exprPtr) = new typeAST(3);}
#line 1519 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 10: /* type_specifier: INT  */
#line 101 "grammar.y"
              { (yyval.exprPtr) = new typeAST(4);}
#line 1525 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 11: /* type_specifier: LONG  */
#line 102 "grammar.y"
               { (yyval.exprPtr) = new typeAST(5);}
#line 1531 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 12: /* type_specifier: FLOAT  */
#line 103 "grammar.y"
                { (yyval.exprPtr) = new typeAST(6);}
#line 1537 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 13: /* type_specifier: DOUBLE  */
#line 104 "grammar.y"
                 { (yyval.exprPtr) = new typeAST(7);}
#line 1543 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 14: /* declarator: IDENTIFIER  */
#line 109 "grammar.y"
                     { 
		exprAST* id = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(id);
		(yyval.exprPtr) = new declarator("declarator", 1, children);
	}
#line 1555 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 15: /* declarator: '(' declarator ')'  */
#line 116 "grammar.y"
                             { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new declarator("declarator", 2, children);
	}
#line 1569 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 16: /* declarator: declarator '[' constant_expression ']'  */
#line 125 "grammar.y"
                                                 { 
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back((yyvsp[-3].exprPtr));
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new declarator("declarator", 3, children);
	}
#line 1584 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 17: /* declarator: declarator '[' ']'  */
#line 135 "grammar.y"
                             { 
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new declarator("declarator", 4, children);
	}
#line 1598 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 18: /* declarator: declarator '(' parameter_list ')'  */
#line 144 "grammar.y"
                                            { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[-3].exprPtr));
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new declarator("declarator", 5, children);
	}
#line 1613 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 19: /* declarator: declarator '(' ')'  */
#line 154 "grammar.y"
                             { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new declarator("declarator", 6, children);
	}
#line 1627 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 20: /* constant_expression: conditional_expression  */
#line 168 "grammar.y"
                                 { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new constant_expression("constant_expression", 1, children);
	}
#line 1637 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 21: /* conditional_expression: logical_or_expression  */
#line 178 "grammar.y"
                                {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new conditional_expression("conditional_expression", 1, children);
	}
#line 1647 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 22: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 183 "grammar.y"
                                                                          {
		exprAST* questionMark = new punctuationAST("?");
		exprAST* colon = new punctuationAST(":");
		vector<exprAST*> children;
		children.push_back((yyvsp[-4].exprPtr));
		children.push_back(questionMark);
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(colon);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new conditional_expression("conditional_expression", 2, children);
	}
#line 1663 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 23: /* logical_or_expression: logical_and_expression  */
#line 199 "grammar.y"
                                 {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new logical_or_expression("logical_or_expression", 1, children);
	}
#line 1673 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 24: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 204 "grammar.y"
                                                             {
		exprAST* orOp = new operatorAST("||");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(orOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new logical_or_expression("logical_or_expression", 2, children);
	}
#line 1686 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 25: /* logical_and_expression: inclusive_or_expression  */
#line 217 "grammar.y"
                                  {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new logical_and_expression("logical_and_expression", 1, children);
	}
#line 1696 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 26: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 222 "grammar.y"
                                                                {
		exprAST* andOp = new operatorAST("&&");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(andOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new logical_and_expression("logical_and_expression", 2, children);
	}
#line 1709 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 27: /* inclusive_or_expression: exclusive_or_expression  */
#line 235 "grammar.y"
                                  {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new inclusive_or_expression("inclusive_or_expression", 1, children);
	}
#line 1719 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 28: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 240 "grammar.y"
                                                              {
		exprAST* orOp = new operatorAST("|");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(orOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new inclusive_or_expression("inclusive_or_expression", 2, children);
	}
#line 1732 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 29: /* exclusive_or_expression: and_expression  */
#line 253 "grammar.y"
                         { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new exclusive_or_expression("exclusive_or_expression", 1, children);
	}
#line 1742 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 30: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 258 "grammar.y"
                                                     {
		exprAST* xorOp = new operatorAST("^");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(xorOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new exclusive_or_expression("exclusive_or_expression", 2, children);
	}
#line 1755 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 31: /* and_expression: equality_expression  */
#line 271 "grammar.y"
                              {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new and_expression("and_expression", 1, children);
	}
#line 1765 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 32: /* and_expression: and_expression '&' equality_expression  */
#line 276 "grammar.y"
                                                 {
		exprAST* andOp = new operatorAST("&");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(andOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new and_expression("and_expression", 2, children);
	}
#line 1778 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 33: /* equality_expression: relational_expression  */
#line 289 "grammar.y"
                                { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new equality_expression("equality_expression", 1, children);
	}
#line 1788 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 34: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 294 "grammar.y"
                                                          {
		exprAST* eqOp = new operatorAST("==");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(eqOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new equality_expression("equality_expression", 2, children);
	}
#line 1801 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 35: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 302 "grammar.y"
                                                          {
		exprAST* neOp = new operatorAST("!=");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(neOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new equality_expression("equality_expression", 3, children);
	}
#line 1814 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 36: /* relational_expression: shift_expression  */
#line 315 "grammar.y"
                           { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 1, children);
	}
#line 1824 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 37: /* relational_expression: relational_expression '<' shift_expression  */
#line 320 "grammar.y"
                                                     {
		exprAST* lessOp = new operatorAST("<");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(lessOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 2, children);
	}
#line 1837 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 38: /* relational_expression: relational_expression '>' shift_expression  */
#line 328 "grammar.y"
                                                     {
		exprAST* greaterOp = new operatorAST(">");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(greaterOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 3, children);
	}
#line 1850 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 39: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 336 "grammar.y"
                                                       {
		exprAST* lessEqualOp = new operatorAST("<=");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(lessEqualOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 4, children);
	}
#line 1863 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 40: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 344 "grammar.y"
                                                       {
		exprAST* greaterEqualOp = new operatorAST(">=");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(greaterEqualOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 5, children);
	}
#line 1876 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 41: /* shift_expression: additive_expression  */
#line 357 "grammar.y"
                              {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new shift_expression("shift_expression", 1, children);
	}
#line 1886 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 42: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 362 "grammar.y"
                                                       {
		exprAST* leftOp = new operatorAST("<<");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(leftOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new shift_expression("shift_expression", 2, children);
	}
#line 1899 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 43: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 370 "grammar.y"
                                                        {
		exprAST* rightOp = new operatorAST(">>");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(rightOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new shift_expression("shift_expression", 3, children);
	}
#line 1912 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 44: /* additive_expression: multiplicative_expression  */
#line 383 "grammar.y"
                                    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new additive_expression("additive_expression", 1, children);
	}
#line 1922 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 45: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 388 "grammar.y"
                                                            {
		exprAST* addOp = new operatorAST("+");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(addOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new additive_expression("additive_expression", 2, children);
	}
#line 1935 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 46: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 396 "grammar.y"
                                                            {
		exprAST* subOp = new operatorAST("-");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(subOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new additive_expression("additive_expression", 3, children);
	}
#line 1948 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 47: /* multiplicative_expression: cast_expression  */
#line 409 "grammar.y"
                          { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 1, children);
	}
#line 1958 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 414 "grammar.y"
                                                        {
		exprAST* mulOp = new operatorAST("*");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(mulOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 2, children);
	}
#line 1971 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 49: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 422 "grammar.y"
                                                        {
		exprAST* divOp = new operatorAST("/");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(divOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 3, children);
	}
#line 1984 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 50: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 430 "grammar.y"
                                                        {
		exprAST* modOp = new operatorAST("%");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(modOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 4, children);
	}
#line 1997 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 51: /* cast_expression: unary_expression  */
#line 443 "grammar.y"
                           { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new cast_expression("cast_expression", 1, children);
	}
#line 2007 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 52: /* cast_expression: '(' type_name ')' cast_expression  */
#line 448 "grammar.y"
                                            {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new cast_expression("cast_expression", 2, children);
	}
#line 2022 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 53: /* type_name: type_specifier  */
#line 463 "grammar.y"
                         { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new type_name("type_name", 1, children);
	}
#line 2032 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 54: /* expression: assignment_expression  */
#line 473 "grammar.y"
                                { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new expression("expression", 1, children);
	}
#line 2042 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 55: /* expression: expression ',' assignment_expression  */
#line 478 "grammar.y"
                                               {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new expression("expression", 2, children);
	}
#line 2055 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 56: /* assignment_expression: conditional_expression  */
#line 491 "grammar.y"
                                 { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new assignment_expression("assignment_expression", 1, children);
	}
#line 2065 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 57: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 496 "grammar.y"
                                                                     { 
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new assignment_expression("assignment_expression", 2, children);
	}
#line 2077 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 58: /* unary_expression: postfix_expression  */
#line 508 "grammar.y"
                             { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 1, children);
	}
#line 2087 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 59: /* unary_expression: INC_OP unary_expression  */
#line 513 "grammar.y"
                                  {
		exprAST* incOp = new operatorAST("++");
		vector<exprAST*> children;
		children.push_back(incOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 2, children);
	}
#line 2099 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 60: /* unary_expression: DEC_OP unary_expression  */
#line 520 "grammar.y"
                                  {
		exprAST* decOp = new operatorAST("--");
		vector<exprAST*> children;
		children.push_back(decOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 3, children);
	}
#line 2111 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 61: /* unary_expression: unary_operator cast_expression  */
#line 527 "grammar.y"
                                         { 
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 4, children);
	}
#line 2122 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 62: /* unary_expression: SIZEOF unary_expression  */
#line 533 "grammar.y"
                                  {
		exprAST* sizeOf = new keywordAST("sizeof");
		vector<exprAST*> children;
		children.push_back(sizeOf);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 5, children);
	}
#line 2134 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 63: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 540 "grammar.y"
                                   {
		exprAST* sizeOf = new keywordAST("sizeof");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(sizeOf);
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new unary_expression("unary_expression", 6, children);
	}
#line 2150 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 64: /* postfix_expression: primary_expression  */
#line 556 "grammar.y"
                             { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 1, children);
	}
#line 2160 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 65: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 561 "grammar.y"
                                                {
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back((yyvsp[-3].exprPtr));
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 2, children);
	}
#line 2175 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 66: /* postfix_expression: postfix_expression '(' ')'  */
#line 571 "grammar.y"
                                     {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 3, children);
	}
#line 2189 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 67: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 580 "grammar.y"
                                                             {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[-3].exprPtr));
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 4, children);
	}
#line 2204 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 68: /* postfix_expression: postfix_expression INC_OP  */
#line 590 "grammar.y"
                                    {
		exprAST* incOp = new operatorAST("++");
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(incOp);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 5, children);
	}
#line 2216 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 69: /* postfix_expression: postfix_expression DEC_OP  */
#line 597 "grammar.y"
                                    {
		exprAST* decOp = new operatorAST("--");
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(decOp);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 6, children);
	}
#line 2228 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 70: /* primary_expression: IDENTIFIER  */
#line 610 "grammar.y"
                     {
		exprAST* identifier = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(identifier);
		(yyval.exprPtr) = new primary_expression("primary_expression", 1, children);
	}
#line 2240 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 71: /* primary_expression: CONSTANT  */
#line 617 "grammar.y"
                   {
		exprAST* constant = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(constant);
		(yyval.exprPtr) = new primary_expression("primary_expression", 2, children);
	}
#line 2252 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 72: /* primary_expression: STRING_LITERAL  */
#line 624 "grammar.y"
                         {
		exprAST* str = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(str);
		(yyval.exprPtr) = new primary_expression("primary_expression", 3, children);
	}
#line 2264 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 73: /* primary_expression: '(' expression ')'  */
#line 631 "grammar.y"
                             {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new primary_expression("primary_expression", 4, children);
	}
#line 2278 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 74: /* primary_expression: CHAR_LITERAL  */
#line 640 "grammar.y"
                      {
		exprAST* charLiteral = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(charLiteral);
		(yyval.exprPtr) = new primary_expression("primary_expression", 5, children);
	}
#line 2290 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 75: /* argument_expression_list: assignment_expression  */
#line 652 "grammar.y"
                                { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new argument_expression_list("argument_expression_list", 1, children);
	}
#line 2300 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 76: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 657 "grammar.y"
                                                             {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new argument_expression_list("argument_expression_list", 2, children);
	}
#line 2313 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 77: /* unary_operator: '&'  */
#line 670 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("&"); }
#line 2319 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 78: /* unary_operator: '*'  */
#line 671 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("*"); }
#line 2325 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 79: /* unary_operator: '+'  */
#line 672 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("+"); }
#line 2331 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 80: /* unary_operator: '-'  */
#line 673 "grammar.y"
              {	(yyval.exprPtr) = new operatorAST("-"); }
#line 2337 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 81: /* unary_operator: '~'  */
#line 674 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("~"); }
#line 2343 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 82: /* unary_operator: '!'  */
#line 675 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("!"); }
#line 2349 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 83: /* assignment_operator: '='  */
#line 681 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("="); }
#line 2355 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 84: /* assignment_operator: MUL_ASSIGN  */
#line 682 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("*="); }
#line 2361 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 85: /* assignment_operator: DIV_ASSIGN  */
#line 683 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("/="); }
#line 2367 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 86: /* assignment_operator: MOD_ASSIGN  */
#line 684 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("%="); }
#line 2373 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 87: /* assignment_operator: ADD_ASSIGN  */
#line 685 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("+="); }
#line 2379 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 88: /* assignment_operator: SUB_ASSIGN  */
#line 686 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("-="); }
#line 2385 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 89: /* assignment_operator: LEFT_ASSIGN  */
#line 687 "grammar.y"
                      { (yyval.exprPtr) = new operatorAST("<<="); }
#line 2391 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 90: /* assignment_operator: RIGHT_ASSIGN  */
#line 688 "grammar.y"
                       { (yyval.exprPtr) = new operatorAST(">>="); }
#line 2397 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 91: /* assignment_operator: AND_ASSIGN  */
#line 689 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("&="); }
#line 2403 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 92: /* assignment_operator: XOR_ASSIGN  */
#line 690 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("^="); }
#line 2409 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 93: /* assignment_operator: OR_ASSIGN  */
#line 691 "grammar.y"
                    { (yyval.exprPtr) = new operatorAST("|="); }
#line 2415 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 94: /* parameter_list: parameter_declaration  */
#line 699 "grammar.y"
                                { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new parameter_list("parameter_list", 1, children);
	}
#line 2425 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 95: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 704 "grammar.y"
                                                   {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new parameter_list("parameter_list", 2, children);
	}
#line 2438 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 96: /* parameter_declaration: type_specifier declarator  */
#line 717 "grammar.y"
                                   { 
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new parameter_declaration("parameter_declaration", 1, children);
	}
#line 2449 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 97: /* compound_statement: '{' '}'  */
#line 728 "grammar.y"
                  { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 1, children);
	}
#line 2462 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 98: /* compound_statement: '{' statement_list '}'  */
#line 736 "grammar.y"
                                 { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 2, children);
	}
#line 2476 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 99: /* compound_statement: '{' declaration_list '}'  */
#line 745 "grammar.y"
                                   { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 3, children);
	}
#line 2490 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 100: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 754 "grammar.y"
                                                  { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 4, children);
	}
#line 2505 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 101: /* statement_list: statement  */
#line 769 "grammar.y"
                    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement_list("statement_list", 1, children);
	}
#line 2515 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 102: /* statement_list: statement_list statement  */
#line 774 "grammar.y"
                                   { 
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement_list("statement_list", 2, children);
	}
#line 2526 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 103: /* declaration_list: declaration  */
#line 785 "grammar.y"
                      {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new declaration_list("declaration_list", 1, children);
	}
#line 2536 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 104: /* declaration_list: declaration_list declaration  */
#line 790 "grammar.y"
                                       {
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new declaration_list("declaration_list", 2, children);
	}
#line 2547 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 105: /* statement: compound_statement  */
#line 801 "grammar.y"
                             { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement("statement", 1, children);
	}
#line 2557 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 106: /* statement: expression_statement  */
#line 806 "grammar.y"
                               {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement("statement", 2, children);
	}
#line 2567 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 107: /* statement: selection_statement  */
#line 811 "grammar.y"
                              {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement("statement", 3, children);
	}
#line 2577 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 108: /* statement: iteration_statement  */
#line 816 "grammar.y"
                              {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement("statement", 4, children);
	}
#line 2587 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 109: /* statement: jump_statement  */
#line 821 "grammar.y"
                         {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement("statement", 5, children);
	}
#line 2597 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 110: /* expression_statement: ';'  */
#line 831 "grammar.y"
              { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(semiColon);
		(yyval.exprPtr) = new expression_statement("expression_statement", 1, children);
	}
#line 2608 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 111: /* expression_statement: expression ';'  */
#line 837 "grammar.y"
                         { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(semiColon);
		(yyval.exprPtr) = new expression_statement("expression_statement", 2, children);
	}
#line 2620 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 112: /* selection_statement: IF '(' expression ')' statement  */
#line 849 "grammar.y"
                                          { 
		exprAST* oneIF = new keywordAST("if");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneIF);
		children.push_back(left);
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new selection_statement("selection_statement", 1, children);
	}
#line 2637 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 113: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 861 "grammar.y"
                                                         { 
		exprAST* oneIF = new keywordAST("if");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		exprAST* oneELSE = new keywordAST("else");
		vector<exprAST*> children;
		children.push_back(oneIF);
		children.push_back(left);
		children.push_back((yyvsp[-4].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(oneELSE);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new selection_statement("selection_statement", 2, children);
	}
#line 2657 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 114: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 881 "grammar.y"
                                             { 
		exprAST* oneWHILE = new keywordAST("while");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneWHILE);
		children.push_back(left);
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 1, children);
	}
#line 2674 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 115: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 893 "grammar.y"
                                                                          { 
		exprAST* oneFOR = new keywordAST("for");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneFOR);
		children.push_back(left);
		children.push_back((yyvsp[-3].exprPtr));
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 2, children);
	}
#line 2692 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 116: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 906 "grammar.y"
                                                                                     { 
		exprAST* oneFOR = new keywordAST("for");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneFOR);
		children.push_back(left);
		children.push_back((yyvsp[-4].exprPtr));
		children.push_back((yyvsp[-3].exprPtr));
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 3, children);
	}
#line 2711 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 117: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 920 "grammar.y"
                                                                            {
		exprAST* oneFOR = new keywordAST("for");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneFOR);
		children.push_back(left);
		children.push_back((yyvsp[-4].exprPtr));
		children.push_back((yyvsp[-3].exprPtr));
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(right);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 4, children);
	}
#line 2730 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 118: /* jump_statement: CONTINUE ';'  */
#line 939 "grammar.y"
                       { 
		exprAST* oneCONTINUE = new keywordAST("continue");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneCONTINUE);
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 1, children);
	}
#line 2743 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 119: /* jump_statement: BREAK ';'  */
#line 947 "grammar.y"
                    { 
		exprAST* oneBREAK = new keywordAST("break");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneBREAK);
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 2, children);
	}
#line 2756 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 120: /* jump_statement: RETURN ';'  */
#line 955 "grammar.y"
                     { 
		exprAST* oneRETURN = new keywordAST("return");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneRETURN);
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 3, children);
	}
#line 2769 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 121: /* jump_statement: RETURN expression ';'  */
#line 963 "grammar.y"
                                { 
		exprAST* oneRETURN = new keywordAST("return");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneRETURN);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 4, children);
	}
#line 2783 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 122: /* declaration: type_specifier init_declarator_list ';'  */
#line 977 "grammar.y"
                                              { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(semiColon);
		(yyval.exprPtr) = new declaration("declaration", 1, children);
	}
#line 2796 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 123: /* init_declarator_list: init_declarator  */
#line 990 "grammar.y"
                          {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new init_declarator_list("init_declarator_list", 1, children);
	}
#line 2806 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 124: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 995 "grammar.y"
                                                  {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new init_declarator_list("init_declarator_list", 2, children);
	}
#line 2819 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 125: /* init_declarator: declarator  */
#line 1007 "grammar.y"
                     {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new init_declarator("init_declarator", 1, children);
	}
#line 2829 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;

  case 126: /* init_declarator: declarator '=' assignment_expression  */
#line 1012 "grammar.y"
                                               {
		exprAST* eqOp = new operatorAST("=");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(eqOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new init_declarator("init_declarator", 2, children);
	}
#line 2842 "/home/lumina/Documents/CompileProject/src/grammar.cpp"
    break;


#line 2846 "/home/lumina/Documents/CompileProject/src/grammar.cpp"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1022 "grammar.y"



void yyerror(char const *s){
    printf("Error Information\n");
    printf("%s at %s\n",s,yytext);
	return ;
}


