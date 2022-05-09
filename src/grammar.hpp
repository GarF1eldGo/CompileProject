/* A Bison parser, made by GNU Bison 3.7.6.  */

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

#ifndef YY_YY_GRAMMAR_HPP_INCLUDED
# define YY_YY_GRAMMAR_HPP_INCLUDED
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    CONSTANT = 259,                /* CONSTANT  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    SIZEOF = 261,                  /* SIZEOF  */
    INC_OP = 262,                  /* INC_OP  */
    DEC_OP = 263,                  /* DEC_OP  */
    LEFT_OP = 264,                 /* LEFT_OP  */
    RIGHT_OP = 265,                /* RIGHT_OP  */
    LE_OP = 266,                   /* LE_OP  */
    GE_OP = 267,                   /* GE_OP  */
    EQ_OP = 268,                   /* EQ_OP  */
    NE_OP = 269,                   /* NE_OP  */
    AND_OP = 270,                  /* AND_OP  */
    OR_OP = 271,                   /* OR_OP  */
    MUL_ASSIGN = 272,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 273,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 274,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 275,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 276,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 277,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 278,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 279,              /* AND_ASSIGN  */
    XOR_ASSIGN = 280,              /* XOR_ASSIGN  */
    OR_ASSIGN = 281,               /* OR_ASSIGN  */
    CHAR = 282,                    /* CHAR  */
    SHORT = 283,                   /* SHORT  */
    INT = 284,                     /* INT  */
    LONG = 285,                    /* LONG  */
    FLOAT = 286,                   /* FLOAT  */
    DOUBLE = 287,                  /* DOUBLE  */
    VOID = 288,                    /* VOID  */
    ELLIPSIS = 289,                /* ELLIPSIS  */
    IF = 290,                      /* IF  */
    ELSE = 291,                    /* ELSE  */
    WHILE = 292,                   /* WHILE  */
    DO = 293,                      /* DO  */
    FOR = 294,                     /* FOR  */
    CONTINUE = 295,                /* CONTINUE  */
    BREAK = 296,                   /* BREAK  */
    RETURN = 297                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "grammar.y"

	class exprAST* exprPtr;

#line 110 "grammar.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_HPP_INCLUDED  */
