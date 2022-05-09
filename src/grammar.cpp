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

#line 87 "grammar.cpp"

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
  YYSYMBOL_INC_OP = 7,                     /* INC_OP  */
  YYSYMBOL_DEC_OP = 8,                     /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 9,                    /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 10,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 11,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 12,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 13,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 14,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 15,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 16,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 17,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 18,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 19,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 20,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 21,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 22,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 23,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 24,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 25,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 26,                 /* OR_ASSIGN  */
  YYSYMBOL_CHAR = 27,                      /* CHAR  */
  YYSYMBOL_SHORT = 28,                     /* SHORT  */
  YYSYMBOL_INT = 29,                       /* INT  */
  YYSYMBOL_LONG = 30,                      /* LONG  */
  YYSYMBOL_FLOAT = 31,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 32,                    /* DOUBLE  */
  YYSYMBOL_VOID = 33,                      /* VOID  */
  YYSYMBOL_ELLIPSIS = 34,                  /* ELLIPSIS  */
  YYSYMBOL_IF = 35,                        /* IF  */
  YYSYMBOL_ELSE = 36,                      /* ELSE  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_DO = 38,                        /* DO  */
  YYSYMBOL_FOR = 39,                       /* FOR  */
  YYSYMBOL_CONTINUE = 40,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 41,                     /* BREAK  */
  YYSYMBOL_RETURN = 42,                    /* RETURN  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_47_ = 47,                       /* '?'  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_49_ = 49,                       /* '|'  */
  YYSYMBOL_50_ = 50,                       /* '^'  */
  YYSYMBOL_51_ = 51,                       /* '&'  */
  YYSYMBOL_52_ = 52,                       /* '<'  */
  YYSYMBOL_53_ = 53,                       /* '>'  */
  YYSYMBOL_54_ = 54,                       /* '+'  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '*'  */
  YYSYMBOL_57_ = 57,                       /* '/'  */
  YYSYMBOL_58_ = 58,                       /* '%'  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_60_ = 60,                       /* '~'  */
  YYSYMBOL_61_ = 61,                       /* '!'  */
  YYSYMBOL_62_ = 62,                       /* '='  */
  YYSYMBOL_63_ = 63,                       /* '{'  */
  YYSYMBOL_64_ = 64,                       /* '}'  */
  YYSYMBOL_65_ = 65,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_translation_unit = 67,          /* translation_unit  */
  YYSYMBOL_external_declaration = 68,      /* external_declaration  */
  YYSYMBOL_function_definition = 69,       /* function_definition  */
  YYSYMBOL_declaration_specifiers = 70,    /* declaration_specifiers  */
  YYSYMBOL_type_specifier = 71,            /* type_specifier  */
  YYSYMBOL_declarator = 72,                /* declarator  */
  YYSYMBOL_direct_declarator = 73,         /* direct_declarator  */
  YYSYMBOL_constant_expression = 74,       /* constant_expression  */
  YYSYMBOL_conditional_expression = 75,    /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 76,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 77,    /* logical_and_expression  */
  YYSYMBOL_inclusive_or_expression = 78,   /* inclusive_or_expression  */
  YYSYMBOL_exclusive_or_expression = 79,   /* exclusive_or_expression  */
  YYSYMBOL_and_expression = 80,            /* and_expression  */
  YYSYMBOL_equality_expression = 81,       /* equality_expression  */
  YYSYMBOL_relational_expression = 82,     /* relational_expression  */
  YYSYMBOL_shift_expression = 83,          /* shift_expression  */
  YYSYMBOL_additive_expression = 84,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 85, /* multiplicative_expression  */
  YYSYMBOL_cast_expression = 86,           /* cast_expression  */
  YYSYMBOL_type_name = 87,                 /* type_name  */
  YYSYMBOL_expression = 88,                /* expression  */
  YYSYMBOL_assignment_expression = 89,     /* assignment_expression  */
  YYSYMBOL_unary_expression = 90,          /* unary_expression  */
  YYSYMBOL_postfix_expression = 91,        /* postfix_expression  */
  YYSYMBOL_primary_expression = 92,        /* primary_expression  */
  YYSYMBOL_argument_expression_list = 93,  /* argument_expression_list  */
  YYSYMBOL_unary_operator = 94,            /* unary_operator  */
  YYSYMBOL_assignment_operator = 95,       /* assignment_operator  */
  YYSYMBOL_parameter_type_list = 96,       /* parameter_type_list  */
  YYSYMBOL_parameter_list = 97,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 98,     /* parameter_declaration  */
  YYSYMBOL_compound_statement = 99,        /* compound_statement  */
  YYSYMBOL_statement_list = 100,           /* statement_list  */
  YYSYMBOL_declaration_list = 101,         /* declaration_list  */
  YYSYMBOL_statement = 102,                /* statement  */
  YYSYMBOL_expression_statement = 103,     /* expression_statement  */
  YYSYMBOL_selection_statement = 104,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 105,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 106,           /* jump_statement  */
  YYSYMBOL_declaration = 107,              /* declaration  */
  YYSYMBOL_init_declarator_list = 108,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 109           /* init_declarator  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   680

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
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
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "CHAR", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE", "VOID", "ELLIPSIS",
  "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE", "BREAK", "RETURN", "'('",
  "')'", "'['", "']'", "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "','", "'~'", "'!'", "'='", "'{'",
  "'}'", "';'", "$accept", "translation_unit", "external_declaration",
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
  "init_declarator", YY_NULLPTR
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
     295,   296,   297,    40,    41,    91,    93,    63,    58,   124,
      94,    38,    60,    62,    43,    45,    42,    47,    37,    44,
     126,    33,    61,   123,   125,    59
};
#endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,   170,  -136,     3,   -22,    11,  -136,  -136,   -26,
    -136,    77,    83,    84,    88,    92,    38,    13,    46,    47,
     -56,    96,     0,   -24,   -27,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,    45,   177,   120,  -136,   -51,  -135,  -136,  -136,
    -136,   -21,  -136,   172
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    71,    12,    92,    19,    89,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,   100,    72,    73,    58,    59,    60,   182,    61,   132,
      85,    86,    87,    74,    75,    76,    77,    78,    79,    80,
      81,    13,    20,    21
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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
static const yytype_int8 yystos[] =
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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
#line 1463 "grammar.cpp"
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
#line 1475 "grammar.cpp"
    break;

  case 4: /* external_declaration: function_definition  */
#line 67 "grammar.y"
                          { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new external_declaration("external_declaration", 1, children);
	}
#line 1485 "grammar.cpp"
    break;

  case 5: /* external_declaration: declaration  */
#line 72 "grammar.y"
                  {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new external_declaration("external_declaration", 2, children);
	}
#line 1495 "grammar.cpp"
    break;

  case 6: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 82 "grammar.y"
                                                           {
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new function_definition("function_definition", 1, children);
	}
#line 1507 "grammar.cpp"
    break;

  case 7: /* declaration_specifiers: type_specifier  */
#line 93 "grammar.y"
                     {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new declaration_specifiers("declaration_specifiers", 1, children);
	}
#line 1517 "grammar.cpp"
    break;

  case 8: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 98 "grammar.y"
                                                {
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new declaration_specifiers("declaration_specifiers", 2, children);
	}
#line 1528 "grammar.cpp"
    break;

  case 9: /* type_specifier: VOID  */
#line 108 "grammar.y"
               { (yyval.exprPtr) = new typeAST(1); }
#line 1534 "grammar.cpp"
    break;

  case 10: /* type_specifier: CHAR  */
#line 109 "grammar.y"
               { (yyval.exprPtr) = new typeAST(2);}
#line 1540 "grammar.cpp"
    break;

  case 11: /* type_specifier: SHORT  */
#line 110 "grammar.y"
                { (yyval.exprPtr) = new typeAST(3);}
#line 1546 "grammar.cpp"
    break;

  case 12: /* type_specifier: INT  */
#line 111 "grammar.y"
              { (yyval.exprPtr) = new typeAST(4);}
#line 1552 "grammar.cpp"
    break;

  case 13: /* type_specifier: LONG  */
#line 112 "grammar.y"
               { (yyval.exprPtr) = new typeAST(5);}
#line 1558 "grammar.cpp"
    break;

  case 14: /* type_specifier: FLOAT  */
#line 113 "grammar.y"
                { (yyval.exprPtr) = new typeAST(6);}
#line 1564 "grammar.cpp"
    break;

  case 15: /* type_specifier: DOUBLE  */
#line 114 "grammar.y"
                 { (yyval.exprPtr) = new typeAST(7);}
#line 1570 "grammar.cpp"
    break;

  case 16: /* declarator: direct_declarator  */
#line 119 "grammar.y"
                        { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new declarator("declarator", 1, children);
	}
#line 1580 "grammar.cpp"
    break;

  case 17: /* direct_declarator: IDENTIFIER  */
#line 129 "grammar.y"
                     { 
		exprAST* id = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(id);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 1, children);
	}
#line 1592 "grammar.cpp"
    break;

  case 18: /* direct_declarator: '(' declarator ')'  */
#line 136 "grammar.y"
                             { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 2, children);
	}
#line 1606 "grammar.cpp"
    break;

  case 19: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 145 "grammar.y"
                                                        { 
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back((yyvsp[-3].exprPtr));
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 3, children);
	}
#line 1621 "grammar.cpp"
    break;

  case 20: /* direct_declarator: direct_declarator '[' ']'  */
#line 155 "grammar.y"
                                    { 
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 4, children);
	}
#line 1635 "grammar.cpp"
    break;

  case 21: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 164 "grammar.y"
                                                        { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[-3].exprPtr));
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 5, children);
	}
#line 1650 "grammar.cpp"
    break;

  case 22: /* direct_declarator: direct_declarator '(' ')'  */
#line 174 "grammar.y"
                                    { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new nonleafAST("direct_declarator", 6, children);
	}
#line 1664 "grammar.cpp"
    break;

  case 23: /* constant_expression: conditional_expression  */
#line 188 "grammar.y"
                                 { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new constant_expression("constant_expression", 1, children);
	}
#line 1674 "grammar.cpp"
    break;

  case 24: /* conditional_expression: logical_or_expression  */
#line 198 "grammar.y"
                                {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new conditional_expression("conditional_expression", 1, children);
	}
#line 1684 "grammar.cpp"
    break;

  case 25: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 203 "grammar.y"
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
#line 1700 "grammar.cpp"
    break;

  case 26: /* logical_or_expression: logical_and_expression  */
#line 219 "grammar.y"
                                 {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new logical_or_expression("logical_or_expression", 1, children);
	}
#line 1710 "grammar.cpp"
    break;

  case 27: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 224 "grammar.y"
                                                             {
		exprAST* orOp = new operatorAST("||");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(orOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new logical_or_expression("logical_or_expression", 2, children);
	}
#line 1723 "grammar.cpp"
    break;

  case 28: /* logical_and_expression: inclusive_or_expression  */
#line 237 "grammar.y"
                                  {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new logical_and_expression("logical_and_expression", 1, children);
	}
#line 1733 "grammar.cpp"
    break;

  case 29: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 242 "grammar.y"
                                                                {
		exprAST* andOp = new operatorAST("&&");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(andOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new logical_and_expression("logical_and_expression", 2, children);
	}
#line 1746 "grammar.cpp"
    break;

  case 30: /* inclusive_or_expression: exclusive_or_expression  */
#line 255 "grammar.y"
                                  {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new inclusive_or_expression("inclusive_or_expression", 1, children);
	}
#line 1756 "grammar.cpp"
    break;

  case 31: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 260 "grammar.y"
                                                              {
		exprAST* orOp = new operatorAST("|");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(orOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new inclusive_or_expression("inclusive_or_expression", 2, children);
	}
#line 1769 "grammar.cpp"
    break;

  case 32: /* exclusive_or_expression: and_expression  */
#line 273 "grammar.y"
                         { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new exclusive_or_expression("exclusive_or_expression", 1, children);
	}
#line 1779 "grammar.cpp"
    break;

  case 33: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 278 "grammar.y"
                                                     {
		exprAST* xorOp = new operatorAST("^");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(xorOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new exclusive_or_expression("exclusive_or_expression", 2, children);
	}
#line 1792 "grammar.cpp"
    break;

  case 34: /* and_expression: equality_expression  */
#line 291 "grammar.y"
                              {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new and_expression("and_expression", 1, children);
	}
#line 1802 "grammar.cpp"
    break;

  case 35: /* and_expression: and_expression '&' equality_expression  */
#line 296 "grammar.y"
                                                 {
		exprAST* andOp = new operatorAST("&");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(andOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new and_expression("and_expression", 2, children);
	}
#line 1815 "grammar.cpp"
    break;

  case 36: /* equality_expression: relational_expression  */
#line 309 "grammar.y"
                                { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new equality_expression("equality_expression", 1, children);
	}
#line 1825 "grammar.cpp"
    break;

  case 37: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 314 "grammar.y"
                                                          {
		exprAST* eqOp = new operatorAST("==");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(eqOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new equality_expression("equality_expression", 2, children);
	}
#line 1838 "grammar.cpp"
    break;

  case 38: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 322 "grammar.y"
                                                          {
		exprAST* neOp = new operatorAST("!=");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(neOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new equality_expression("equality_expression", 3, children);
	}
#line 1851 "grammar.cpp"
    break;

  case 39: /* relational_expression: shift_expression  */
#line 335 "grammar.y"
                           { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 1, children);
	}
#line 1861 "grammar.cpp"
    break;

  case 40: /* relational_expression: relational_expression '<' shift_expression  */
#line 340 "grammar.y"
                                                     {
		exprAST* lessOp = new operatorAST("<");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(lessOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 2, children);
	}
#line 1874 "grammar.cpp"
    break;

  case 41: /* relational_expression: relational_expression '>' shift_expression  */
#line 348 "grammar.y"
                                                     {
		exprAST* greaterOp = new operatorAST(">");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(greaterOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 3, children);
	}
#line 1887 "grammar.cpp"
    break;

  case 42: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 356 "grammar.y"
                                                       {
		exprAST* lessEqualOp = new operatorAST("<=");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(lessEqualOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 4, children);
	}
#line 1900 "grammar.cpp"
    break;

  case 43: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 364 "grammar.y"
                                                       {
		exprAST* greaterEqualOp = new operatorAST(">=");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(greaterEqualOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new relational_expression("relational_expression", 5, children);
	}
#line 1913 "grammar.cpp"
    break;

  case 44: /* shift_expression: additive_expression  */
#line 377 "grammar.y"
                              {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new shift_expression("shift_expression", 1, children);
	}
#line 1923 "grammar.cpp"
    break;

  case 45: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 382 "grammar.y"
                                                       {
		exprAST* leftOp = new operatorAST("<<");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(leftOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new shift_expression("shift_expression", 2, children);
	}
#line 1936 "grammar.cpp"
    break;

  case 46: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 390 "grammar.y"
                                                        {
		exprAST* rightOp = new operatorAST(">>");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(rightOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new shift_expression("shift_expression", 3, children);
	}
#line 1949 "grammar.cpp"
    break;

  case 47: /* additive_expression: multiplicative_expression  */
#line 403 "grammar.y"
                                    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new additive_expression("additive_expression", 1, children);
	}
#line 1959 "grammar.cpp"
    break;

  case 48: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 408 "grammar.y"
                                                            {
		exprAST* addOp = new operatorAST("+");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(addOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new additive_expression("additive_expression", 2, children);
	}
#line 1972 "grammar.cpp"
    break;

  case 49: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 416 "grammar.y"
                                                            {
		exprAST* subOp = new operatorAST("-");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(subOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new additive_expression("additive_expression", 3, children);
	}
#line 1985 "grammar.cpp"
    break;

  case 50: /* multiplicative_expression: cast_expression  */
#line 429 "grammar.y"
                          { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 1, children);
	}
#line 1995 "grammar.cpp"
    break;

  case 51: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 434 "grammar.y"
                                                        {
		exprAST* mulOp = new operatorAST("*");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(mulOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 2, children);
	}
#line 2008 "grammar.cpp"
    break;

  case 52: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 442 "grammar.y"
                                                        {
		exprAST* divOp = new operatorAST("/");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(divOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 3, children);
	}
#line 2021 "grammar.cpp"
    break;

  case 53: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 450 "grammar.y"
                                                        {
		exprAST* modOp = new operatorAST("%");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(modOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new multiplicative_expression("multiplicative_expression", 4, children);
	}
#line 2034 "grammar.cpp"
    break;

  case 54: /* cast_expression: unary_expression  */
#line 463 "grammar.y"
                           { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new cast_expression("cast_expression", 1, children);
	}
#line 2044 "grammar.cpp"
    break;

  case 55: /* cast_expression: '(' type_name ')' cast_expression  */
#line 468 "grammar.y"
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
#line 2059 "grammar.cpp"
    break;

  case 56: /* type_name: type_specifier  */
#line 483 "grammar.y"
                         { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new type_name("type_name", 1, children);
	}
#line 2069 "grammar.cpp"
    break;

  case 57: /* expression: assignment_expression  */
#line 493 "grammar.y"
                                { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new expression("expression", 1, children);
	}
#line 2079 "grammar.cpp"
    break;

  case 58: /* expression: expression ',' assignment_expression  */
#line 498 "grammar.y"
                                               {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new expression("expression", 2, children);
	}
#line 2092 "grammar.cpp"
    break;

  case 59: /* assignment_expression: conditional_expression  */
#line 511 "grammar.y"
                                 { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new assignment_expression("assignment_expression", 1, children);
	}
#line 2102 "grammar.cpp"
    break;

  case 60: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 516 "grammar.y"
                                                                     { 
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new assignment_expression("assignment_expression", 2, children);
	}
#line 2114 "grammar.cpp"
    break;

  case 61: /* unary_expression: postfix_expression  */
#line 528 "grammar.y"
                             { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 1, children);
	}
#line 2124 "grammar.cpp"
    break;

  case 62: /* unary_expression: INC_OP unary_expression  */
#line 533 "grammar.y"
                                  {
		exprAST* incOp = new operatorAST("++");
		vector<exprAST*> children;
		children.push_back(incOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 2, children);
	}
#line 2136 "grammar.cpp"
    break;

  case 63: /* unary_expression: DEC_OP unary_expression  */
#line 540 "grammar.y"
                                  {
		exprAST* decOp = new operatorAST("--");
		vector<exprAST*> children;
		children.push_back(decOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 3, children);
	}
#line 2148 "grammar.cpp"
    break;

  case 64: /* unary_expression: unary_operator cast_expression  */
#line 547 "grammar.y"
                                         { 
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 4, children);
	}
#line 2159 "grammar.cpp"
    break;

  case 65: /* unary_expression: SIZEOF unary_expression  */
#line 553 "grammar.y"
                                  {
		exprAST* sizeOf = new keywordAST("sizeof");
		vector<exprAST*> children;
		children.push_back(sizeOf);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new unary_expression("unary_expression", 5, children);
	}
#line 2171 "grammar.cpp"
    break;

  case 66: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 560 "grammar.y"
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
#line 2187 "grammar.cpp"
    break;

  case 67: /* postfix_expression: primary_expression  */
#line 576 "grammar.y"
                             { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 1, children);
	}
#line 2197 "grammar.cpp"
    break;

  case 68: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 581 "grammar.y"
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
#line 2212 "grammar.cpp"
    break;

  case 69: /* postfix_expression: postfix_expression '(' ')'  */
#line 591 "grammar.y"
                                     {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 3, children);
	}
#line 2226 "grammar.cpp"
    break;

  case 70: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 600 "grammar.y"
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
#line 2241 "grammar.cpp"
    break;

  case 71: /* postfix_expression: postfix_expression INC_OP  */
#line 610 "grammar.y"
                                    {
		exprAST* incOp = new operatorAST("++");
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(incOp);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 5, children);
	}
#line 2253 "grammar.cpp"
    break;

  case 72: /* postfix_expression: postfix_expression DEC_OP  */
#line 617 "grammar.y"
                                    {
		exprAST* decOp = new operatorAST("--");
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(decOp);
		(yyval.exprPtr) = new postfix_expression("postfix_expression", 6, children);
	}
#line 2265 "grammar.cpp"
    break;

  case 73: /* primary_expression: IDENTIFIER  */
#line 630 "grammar.y"
                     {
		exprAST* identifier = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(identifier);
		(yyval.exprPtr) = new primary_expression("primary_expression", 1, children);
	}
#line 2277 "grammar.cpp"
    break;

  case 74: /* primary_expression: CONSTANT  */
#line 637 "grammar.y"
                   {
		exprAST* constant = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(constant);
		(yyval.exprPtr) = new primary_expression("primary_expression", 2, children);
	}
#line 2289 "grammar.cpp"
    break;

  case 75: /* primary_expression: STRING_LITERAL  */
#line 644 "grammar.y"
                         {
		exprAST* str = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(str);
		(yyval.exprPtr) = new primary_expression("primary_expression", 3, children);
	}
#line 2301 "grammar.cpp"
    break;

  case 76: /* primary_expression: '(' expression ')'  */
#line 651 "grammar.y"
                             {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new primary_expression("primary_expression", 4, children);
	}
#line 2315 "grammar.cpp"
    break;

  case 77: /* argument_expression_list: assignment_expression  */
#line 665 "grammar.y"
                                { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new argument_expression_list("argument_expression_list", 1, children);
	}
#line 2325 "grammar.cpp"
    break;

  case 78: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 670 "grammar.y"
                                                             {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new argument_expression_list("argument_expression_list", 2, children);
	}
#line 2338 "grammar.cpp"
    break;

  case 79: /* unary_operator: '&'  */
#line 683 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("&"); }
#line 2344 "grammar.cpp"
    break;

  case 80: /* unary_operator: '*'  */
#line 684 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("*"); }
#line 2350 "grammar.cpp"
    break;

  case 81: /* unary_operator: '+'  */
#line 685 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("+"); }
#line 2356 "grammar.cpp"
    break;

  case 82: /* unary_operator: '-'  */
#line 686 "grammar.y"
              {	(yyval.exprPtr) = new operatorAST("-"); }
#line 2362 "grammar.cpp"
    break;

  case 83: /* unary_operator: '~'  */
#line 687 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("~"); }
#line 2368 "grammar.cpp"
    break;

  case 84: /* unary_operator: '!'  */
#line 688 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("!"); }
#line 2374 "grammar.cpp"
    break;

  case 85: /* assignment_operator: '='  */
#line 694 "grammar.y"
              { (yyval.exprPtr) = new operatorAST("="); }
#line 2380 "grammar.cpp"
    break;

  case 86: /* assignment_operator: MUL_ASSIGN  */
#line 695 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("*="); }
#line 2386 "grammar.cpp"
    break;

  case 87: /* assignment_operator: DIV_ASSIGN  */
#line 696 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("/="); }
#line 2392 "grammar.cpp"
    break;

  case 88: /* assignment_operator: MOD_ASSIGN  */
#line 697 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("%="); }
#line 2398 "grammar.cpp"
    break;

  case 89: /* assignment_operator: ADD_ASSIGN  */
#line 698 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("+="); }
#line 2404 "grammar.cpp"
    break;

  case 90: /* assignment_operator: SUB_ASSIGN  */
#line 699 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("-="); }
#line 2410 "grammar.cpp"
    break;

  case 91: /* assignment_operator: LEFT_ASSIGN  */
#line 700 "grammar.y"
                      { (yyval.exprPtr) = new operatorAST("<<="); }
#line 2416 "grammar.cpp"
    break;

  case 92: /* assignment_operator: RIGHT_ASSIGN  */
#line 701 "grammar.y"
                       { (yyval.exprPtr) = new operatorAST(">>="); }
#line 2422 "grammar.cpp"
    break;

  case 93: /* assignment_operator: AND_ASSIGN  */
#line 702 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("&="); }
#line 2428 "grammar.cpp"
    break;

  case 94: /* assignment_operator: XOR_ASSIGN  */
#line 703 "grammar.y"
                     { (yyval.exprPtr) = new operatorAST("^="); }
#line 2434 "grammar.cpp"
    break;

  case 95: /* assignment_operator: OR_ASSIGN  */
#line 704 "grammar.y"
                    { (yyval.exprPtr) = new operatorAST("|="); }
#line 2440 "grammar.cpp"
    break;

  case 96: /* parameter_type_list: parameter_list  */
#line 710 "grammar.y"
                         { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new parameter_type_list("parameter_type_list", 1, children);
	}
#line 2450 "grammar.cpp"
    break;

  case 97: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 715 "grammar.y"
                                      {
		exprAST* comma = new punctuationAST(",");
		exprAST* ellipsis = new keywordAST("...");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(comma);
		children.push_back(ellipsis);
		(yyval.exprPtr) = new parameter_type_list("parameter_type_list", 2, children);
	}
#line 2464 "grammar.cpp"
    break;

  case 98: /* parameter_list: parameter_declaration  */
#line 729 "grammar.y"
                                { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new parameter_list("parameter_list", 1, children);
	}
#line 2474 "grammar.cpp"
    break;

  case 99: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 734 "grammar.y"
                                                   {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new parameter_list("parameter_list", 2, children);
	}
#line 2487 "grammar.cpp"
    break;

  case 100: /* parameter_declaration: declaration_specifiers declarator  */
#line 747 "grammar.y"
                                           { 
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new parameter_declaration("parameter_declaration", 1, children);
	}
#line 2498 "grammar.cpp"
    break;

  case 101: /* compound_statement: '{' '}'  */
#line 758 "grammar.y"
                  { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 1, children);
	}
#line 2511 "grammar.cpp"
    break;

  case 102: /* compound_statement: '{' statement_list '}'  */
#line 766 "grammar.y"
                                 { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 2, children);
	}
#line 2525 "grammar.cpp"
    break;

  case 103: /* compound_statement: '{' declaration_list '}'  */
#line 775 "grammar.y"
                                   { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(right);
		(yyval.exprPtr) = new compound_statement("compound_statement", 3, children);
	}
#line 2539 "grammar.cpp"
    break;

  case 104: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 784 "grammar.y"
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
#line 2554 "grammar.cpp"
    break;

  case 105: /* statement_list: statement  */
#line 799 "grammar.y"
                    { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement_list("statement_list", 1, children);
	}
#line 2564 "grammar.cpp"
    break;

  case 106: /* statement_list: statement_list statement  */
#line 804 "grammar.y"
                                   { 
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement_list("statement_list", 2, children);
	}
#line 2575 "grammar.cpp"
    break;

  case 107: /* declaration_list: declaration  */
#line 815 "grammar.y"
                      {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new declaration_list("declaration_list", 1, children);
	}
#line 2585 "grammar.cpp"
    break;

  case 108: /* declaration_list: declaration_list declaration  */
#line 820 "grammar.y"
                                       {
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new declaration_list("declaration_list", 2, children);
	}
#line 2596 "grammar.cpp"
    break;

  case 109: /* statement: compound_statement  */
#line 831 "grammar.y"
                             { 
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement("statement", 1, children);
	}
#line 2606 "grammar.cpp"
    break;

  case 110: /* statement: expression_statement  */
#line 836 "grammar.y"
                               {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement("statement", 2, children);
	}
#line 2616 "grammar.cpp"
    break;

  case 111: /* statement: selection_statement  */
#line 841 "grammar.y"
                              {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement("statement", 3, children);
	}
#line 2626 "grammar.cpp"
    break;

  case 112: /* statement: iteration_statement  */
#line 846 "grammar.y"
                              {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement("statement", 4, children);
	}
#line 2636 "grammar.cpp"
    break;

  case 113: /* statement: jump_statement  */
#line 851 "grammar.y"
                         {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new statement("statement", 5, children);
	}
#line 2646 "grammar.cpp"
    break;

  case 114: /* expression_statement: ';'  */
#line 861 "grammar.y"
              { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(semiColon);
		(yyval.exprPtr) = new expression_statement("expression_statement", 1, children);
	}
#line 2657 "grammar.cpp"
    break;

  case 115: /* expression_statement: expression ';'  */
#line 867 "grammar.y"
                         { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(semiColon);
		(yyval.exprPtr) = new expression_statement("expression_statement", 2, children);
	}
#line 2669 "grammar.cpp"
    break;

  case 116: /* selection_statement: IF '(' expression ')' statement  */
#line 879 "grammar.y"
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
#line 2686 "grammar.cpp"
    break;

  case 117: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 891 "grammar.y"
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
#line 2706 "grammar.cpp"
    break;

  case 118: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 911 "grammar.y"
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
#line 2723 "grammar.cpp"
    break;

  case 119: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 923 "grammar.y"
                                                    { 
		exprAST* oneDO = new keywordAST("do");
		exprAST* oneWHILE = new keywordAST("while");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneDO);
		children.push_back((yyvsp[-5].exprPtr));
		children.push_back(oneWHILE);
		children.push_back(left);
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(right);
		children.push_back(semiColon);
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 2, children);
	}
#line 2744 "grammar.cpp"
    break;

  case 120: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 939 "grammar.y"
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
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 3, children);
	}
#line 2762 "grammar.cpp"
    break;

  case 121: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 952 "grammar.y"
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
#line 2781 "grammar.cpp"
    break;

  case 122: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 966 "grammar.y"
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
		(yyval.exprPtr) = new iteration_statement("iteration_statement", 5, children);
	}
#line 2800 "grammar.cpp"
    break;

  case 123: /* jump_statement: CONTINUE ';'  */
#line 985 "grammar.y"
                       { 
		exprAST* oneCONTINUE = new keywordAST("continue");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneCONTINUE);
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 1, children);
	}
#line 2813 "grammar.cpp"
    break;

  case 124: /* jump_statement: BREAK ';'  */
#line 993 "grammar.y"
                    { 
		exprAST* oneBREAK = new keywordAST("break");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneBREAK);
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 2, children);
	}
#line 2826 "grammar.cpp"
    break;

  case 125: /* jump_statement: RETURN ';'  */
#line 1001 "grammar.y"
                     { 
		exprAST* oneRETURN = new keywordAST("return");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneRETURN);
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 3, children);
	}
#line 2839 "grammar.cpp"
    break;

  case 126: /* jump_statement: RETURN expression ';'  */
#line 1009 "grammar.y"
                                { 
		exprAST* oneRETURN = new keywordAST("return");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneRETURN);
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(semiColon);
		(yyval.exprPtr) = new jump_statement("jump_statement", 4, children);
	}
#line 2853 "grammar.cpp"
    break;

  case 127: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 1023 "grammar.y"
                                                      { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back((yyvsp[-1].exprPtr));
		children.push_back(semiColon);
		(yyval.exprPtr) = new declaration("declaration", 1, children);
	}
#line 2866 "grammar.cpp"
    break;

  case 128: /* init_declarator_list: init_declarator  */
#line 1036 "grammar.y"
                          {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new init_declarator_list("init_declarator_list", 1, children);
	}
#line 2876 "grammar.cpp"
    break;

  case 129: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 1041 "grammar.y"
                                                  {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(comma);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new init_declarator_list("init_declarator_list", 2, children);
	}
#line 2889 "grammar.cpp"
    break;

  case 130: /* init_declarator: declarator  */
#line 1053 "grammar.y"
                     {
		vector<exprAST*> children;
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new init_declarator("init_declarator", 1, children);
	}
#line 2899 "grammar.cpp"
    break;

  case 131: /* init_declarator: declarator '=' assignment_expression  */
#line 1058 "grammar.y"
                                               {
		exprAST* eqOp = new operatorAST("=");
		vector<exprAST*> children;
		children.push_back((yyvsp[-2].exprPtr));
		children.push_back(eqOp);
		children.push_back((yyvsp[0].exprPtr));
		(yyval.exprPtr) = new init_declarator("init_declarator", 2, children);
	}
#line 2912 "grammar.cpp"
    break;


#line 2916 "grammar.cpp"

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

#line 1068 "grammar.y"



void yyerror(char const *s){
    printf("Error Information\n");
    printf("%s at %s\n",s,yytext);
	return ;
}


