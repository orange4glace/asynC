
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yacc.y"
  
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include <list>
#include "ast/ast.h"
#include "ast/parser/visitor.h"

using namespace std;

int line_num = 1;

int yylex();
void yyerror(char * s);



/* Line 189 of yacc.c  */
#line 92 "yacc.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONSTANT = 258,
     IDENTIFIER = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     CHAR = 289,
     SHORT = 290,
     INT = 291,
     LONG = 292,
     SIGNED = 293,
     UNSIGNED = 294,
     FLOAT = 295,
     DOUBLE = 296,
     CONST = 297,
     VOLATILE = 298,
     VOID = 299,
     ASYNC = 300,
     STRUCT = 301,
     UNION = 302,
     ENUM = 303,
     ELLIPSIS = 304,
     CASE = 305,
     DEFAULT = 306,
     IF = 307,
     ELSE = 308,
     SWITCH = 309,
     WHILE = 310,
     DO = 311,
     FOR = 312,
     GOTO = 313,
     CONTINUE = 314,
     BREAK = 315,
     RETURN = 316,
     PRINT = 317,
     NEW = 318,
     RUN = 319,
     JOIN = 320
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 19 "yacc.y"

  int num;
  char* id;

  Node* node;

  DeclarationNode *declaration_node;
  InitDeclaratorNode *init_declarator;
  TypeSpecifierNode *type_specifier;
  InitializerNode *initializer;
  DeclaratorNode *declarator;
  IdentifierNode *identifier;
  DirectDeclaratorNode *direct_declarator;
  ExpressionNode *expression;
  AssignmentExpressionNode *assignment_expression;
  FunctionDefinitionNode *function_definition;
  ParameterDeclarationNode *parameter_declaration;
  TypeNameNode *type_name;

  StatementNode *statement;



/* Line 214 of yacc.c  */
#line 217 "yacc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 229 "yacc.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   346

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    78,    72,     2,
      66,    67,    71,    73,    70,    74,     2,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,    86,
      79,    85,    80,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    87,    82,    88,    75,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    19,    24,
      26,    30,    32,    34,    39,    44,    48,    51,    54,    56,
      60,    62,    65,    68,    71,    74,    76,    78,    83,    88,
      94,    96,   100,   104,   108,   110,   114,   118,   120,   124,
     128,   130,   134,   138,   142,   146,   148,   152,   156,   158,
     162,   164,   166,   170,   174,   176,   180,   182,   186,   188,
     190,   192,   194,   197,   199,   201,   206,   208,   211,   214,
     216,   218,   221,   225,   227,   229,   231,   233,   235,   237,
     239,   241,   243,   245,   248,   255,   261,   263,   267,   270,
     273,   277,   279,   281,   284,   287,   293,   301,   307,   315,
     319,   322,   326,   330,   334,   336,   338,   340
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     133,     0,    -1,     4,    -1,     3,    -1,     5,    -1,    66,
     106,    67,    -1,    91,    -1,    68,    69,   124,    -1,    68,
      92,    69,   124,    -1,    93,    -1,    93,    70,    92,    -1,
       4,    -1,    90,    -1,    94,    68,   106,    69,    -1,    94,
      66,    95,    67,    -1,    94,    66,    67,    -1,    94,     8,
      -1,    94,     9,    -1,   104,    -1,   104,    70,    95,    -1,
      94,    -1,     8,    96,    -1,     9,    96,    -1,    71,    97,
      -1,    72,    97,    -1,    98,    -1,    96,    -1,    66,   114,
      67,    97,    -1,    63,   110,    66,    67,    -1,    63,   110,
     115,    66,    67,    -1,    97,    -1,    99,    71,    97,    -1,
      99,    77,    97,    -1,    99,    78,    97,    -1,    99,    -1,
     100,    73,    99,    -1,   100,    74,    99,    -1,   100,    -1,
     101,    10,   100,    -1,   101,    11,   100,    -1,   101,    -1,
     102,    79,   101,    -1,   102,    80,   101,    -1,   102,    12,
     101,    -1,   102,    13,   101,    -1,   102,    -1,   103,    14,
     102,    -1,   103,    15,   102,    -1,   103,    -1,    96,   105,
     104,    -1,    85,    -1,   104,    -1,   106,    70,   104,    -1,
     110,   108,    86,    -1,   109,    -1,   109,    70,   108,    -1,
     111,    -1,   111,    85,   118,    -1,    44,    -1,    36,    -1,
      40,    -1,    45,    -1,   113,   112,    -1,   112,    -1,     4,
      -1,   112,    68,   117,    69,    -1,    71,    -1,    71,   113,
      -1,   110,   115,    -1,   113,    -1,   116,    -1,   113,   116,
      -1,    68,   117,    69,    -1,     3,    -1,   104,    -1,   124,
      -1,   127,    -1,   128,    -1,   126,    -1,   129,    -1,   131,
      -1,   130,    -1,   120,    -1,   106,    86,    -1,   110,   111,
      66,   122,    67,   124,    -1,   110,   111,    66,    67,   124,
      -1,   123,    -1,   123,    70,   122,    -1,   110,   111,    -1,
      87,    88,    -1,    87,   125,    88,    -1,   107,    -1,   119,
      -1,   107,   125,    -1,   119,   125,    -1,    52,    66,   106,
      67,   119,    -1,    52,    66,   106,    67,   119,    53,   119,
      -1,    55,    66,   106,    67,   119,    -1,    57,    66,   107,
     120,   106,    67,   119,    -1,    61,   106,    86,    -1,    61,
      86,    -1,    64,   106,    86,    -1,    65,   106,    86,    -1,
      62,   106,    86,    -1,   107,    -1,   121,    -1,   132,    -1,
     133,   132,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    89,    93,    97,   101,   108,   112,   119,
     123,   131,   139,   141,   143,   145,   147,   149,   154,   158,
     166,   168,   170,   172,   174,   176,   190,   194,   201,   203,
     210,   214,   218,   222,   229,   233,   237,   244,   248,   252,
     259,   263,   267,   271,   275,   282,   286,   290,   364,   368,
     375,   379,   380,   384,   391,   395,   404,   408,   415,   419,
     423,   427,   434,   439,   446,   450,   459,   463,   471,   480,
     486,   492,   502,   509,   515,   522,   523,   524,   525,   526,
     527,   528,   529,   534,   541,   545,   552,   556,   564,   571,
     575,   582,   586,   590,   595,   603,   607,   613,   619,   624,
     628,   635,   639,   646,   652,   658,   667,   668
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANT", "IDENTIFIER",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "ASYNC", "STRUCT", "UNION", "ENUM", "ELLIPSIS",
  "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "PRINT", "NEW", "RUN", "JOIN", "'('",
  "')'", "'['", "']'", "','", "'*'", "'&'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'",
  "'{'", "'}'", "$accept", "primary_expression", "async_expression",
  "variable_capture_list", "variable_capture", "postfix_expression",
  "argument_expression_list", "unary_expression", "cast_expression",
  "new_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "assignment_expression", "assignment_operator", "expression",
  "declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "direct_declarator", "pointer",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "constant_expression", "initializer", "statement",
  "expression_statement", "function_definition",
  "parameter_declaration_list", "parameter_declaration",
  "compound_statement", "compound_statement_body", "selection_statement",
  "iteration_statement", "for_statement", "return_statement",
  "async_statement", "print_statement", "external_declaration",
  "translation_unit", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    40,    41,    91,    93,
      44,    42,    38,    43,    45,   126,    33,    47,    37,    60,
      62,    94,   124,    63,    58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    90,    90,    90,    90,    91,    91,    92,
      92,    93,    94,    94,    94,    94,    94,    94,    95,    95,
      96,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      99,    99,    99,    99,   100,   100,   100,   101,   101,   101,
     102,   102,   102,   102,   102,   103,   103,   103,   104,   104,
     105,   106,   106,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   115,
     115,   115,   116,   117,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   121,   121,   122,   122,   123,   124,
     124,   125,   125,   125,   125,   126,   126,   127,   128,   129,
     129,   130,   130,   131,   132,   132,   133,   133
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     3,     4,     1,
       3,     1,     1,     4,     4,     3,     2,     2,     1,     3,
       1,     2,     2,     2,     2,     1,     1,     4,     4,     5,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     1,     3,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     4,     1,     2,     2,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     6,     5,     1,     3,     2,     2,
       3,     1,     1,     2,     2,     5,     7,     5,     7,     3,
       2,     3,     3,     3,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    59,    60,    58,    61,   104,     0,   105,   106,     0,
      64,    66,     0,    54,    56,    63,     0,     1,   107,    67,
      53,     0,     0,     0,     0,    62,    55,    56,     0,     0,
       0,    86,     3,     2,     4,     0,     0,     0,     0,     0,
       0,     0,    12,     6,    20,    26,    30,    25,    34,    37,
      40,    45,    48,    74,    57,    73,     0,     0,    85,    88,
       0,     0,     0,    21,    22,     0,    51,     0,     0,     0,
      11,     0,     0,     9,    26,    23,    24,    16,    17,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,    89,     0,    91,     0,    92,    82,
      75,     0,    78,    76,    77,    79,    81,    80,    84,    87,
       0,     0,    69,     0,    70,     5,     0,    68,     0,     7,
       0,     0,    15,     0,    18,     0,    49,    31,    32,    33,
      35,    36,    38,    39,    43,    44,    41,    42,    46,    47,
       0,     0,     0,   100,     0,     0,     0,     0,    83,    93,
      94,    90,    28,     0,    71,     0,    52,    27,     8,    10,
      14,     0,    13,     0,     0,     0,    99,   103,   101,   102,
      72,    29,    19,     0,     0,     0,    95,    97,     0,     0,
       0,    96,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    42,    43,    72,    73,    44,   133,    45,    46,    47,
      48,    49,    50,    51,    52,    66,    82,   105,   106,    12,
      13,   107,    27,    15,    16,    69,   123,   124,    56,    54,
     108,   109,     7,    30,    31,   110,   111,   112,   113,   114,
     115,   116,   117,     8,     9
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
      86,   -58,   -58,   -58,   -58,   -58,    -2,   -58,   -58,    89,
     -58,   -25,    12,    33,   -45,    37,   128,   -58,   -58,   -58,
     -58,    -2,   -28,   264,   163,    37,   -58,    90,    84,    -2,
     117,   112,   -58,   -58,   -58,   274,   274,    86,   257,     1,
     264,   264,   -58,   -58,    44,   100,   -58,   -58,    50,   -51,
      31,     6,    99,   -58,   -58,   -58,   119,   115,   -58,   -58,
      84,    86,   264,   -58,   -58,   -10,   -58,   -57,    -9,   127,
     -58,    84,   130,   131,   -58,   -58,   -58,   -58,   -58,    29,
     264,   -58,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   -58,   134,   138,   140,
     160,   264,   264,   264,   -58,   -55,   153,    -2,   153,   -58,
     -58,   121,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     144,   163,   139,   146,   -58,   -58,   264,   -58,   264,   -58,
      84,   209,   -58,   155,   150,    75,   -58,   -58,   -58,   -58,
      50,    50,   -51,   -51,    31,    31,    31,    31,     6,     6,
     264,   264,    86,   -58,   -42,   -15,    21,    23,   -58,   -58,
     -58,   -58,   -58,   158,   -58,   162,   -58,   -58,   -58,   -58,
     -58,   264,   -58,   -56,    32,   264,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   187,   187,   264,   177,   -58,    76,   187,
     187,   -58,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -58,   102,   -58,   -58,    63,   -11,   -34,   -58,
      61,    65,    47,    79,   -58,   -22,   -58,   -35,     0,   214,
     -58,    26,    14,   220,    43,   -58,   169,   116,   120,   -58,
     -48,    68,   -58,   184,   -58,   -24,   -18,   -58,   -58,   -58,
     -58,   -58,   -58,   238,   -58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       5,    53,    10,    67,    58,    70,    75,    76,     1,     5,
     125,   183,     2,   126,   126,   126,     3,     4,    90,    91,
      14,    22,    86,    87,    63,    64,     6,    67,   126,    74,
      74,   158,    32,    33,    34,     6,   118,    35,    36,    28,
      23,    88,    89,    59,   176,   135,    11,   129,    29,   137,
     138,   139,    77,    78,    19,   126,   120,   134,   121,   121,
     136,    11,    11,    65,    68,   154,   155,   156,   157,    11,
      71,   177,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    92,    93,    29,   159,    17,
     160,   126,    37,   126,   167,    38,   132,    39,    20,   184,
      40,    41,   126,    21,   166,    24,   168,   178,   122,   179,
      79,   122,    80,    94,    95,   173,   174,    74,    32,    33,
      34,    83,     1,    35,    36,     1,     2,    84,    85,     2,
       3,     4,    10,     3,     4,   186,   187,   144,   145,   146,
     147,   191,   192,   190,   172,   126,   126,   140,   141,   134,
     188,     1,   175,   142,   143,     2,    32,    33,    34,     3,
       4,    35,    36,    32,    33,    34,    55,    97,    35,    36,
      98,    57,    99,   148,   149,    23,   100,   101,    37,   102,
     103,    38,    61,    39,    60,    81,    40,    41,    96,     1,
      32,    33,    34,     2,   128,    35,    36,     3,     4,   130,
     150,   131,    57,   104,   151,    97,   152,   121,    98,   161,
      99,   162,   165,    70,   100,   101,    37,   102,   103,    38,
     171,    39,   170,    37,    40,    41,    38,   180,    39,   181,
     189,    40,    41,   169,   182,    26,    25,   127,   164,    97,
      57,   163,    98,   185,    99,   119,   153,    18,   100,   101,
      37,   102,   103,    38,     0,    39,     0,     0,    40,    41,
      32,    33,    34,     0,     0,    35,    36,    32,    33,    34,
       0,     0,    35,    36,    57,     0,     0,    32,    33,    34,
       0,     0,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     2,     0,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,    38,     0,    39,     0,    37,    40,    41,
      38,     0,    39,     0,     0,    40,    41,    37,     0,     0,
      62,     0,    39,     0,     0,    40,    41
};

static const yytype_int16 yycheck[] =
{
       0,    23,     4,    38,    28,     4,    40,    41,    36,     9,
      67,    67,    40,    70,    70,    70,    44,    45,    12,    13,
       6,    66,    73,    74,    35,    36,     0,    62,    70,    40,
      41,    86,     3,     4,     5,     9,    60,     8,     9,    67,
      85,    10,    11,    29,    86,    80,    71,    71,    22,    83,
      84,    85,     8,     9,    11,    70,    66,    79,    68,    68,
      82,    71,    71,    37,    38,   100,   101,   102,   103,    71,
      69,    86,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    79,    80,    61,   106,     0,
     108,    70,    63,    70,   128,    66,    67,    68,    86,    67,
      71,    72,    70,    70,   126,    68,   130,    86,    65,    86,
      66,    68,    68,    14,    15,   150,   151,   128,     3,     4,
       5,    71,    36,     8,     9,    36,    40,    77,    78,    40,
      44,    45,     4,    44,    45,   183,   184,    90,    91,    92,
      93,   189,   190,    67,    69,    70,    70,    86,    87,   171,
     185,    36,   152,    88,    89,    40,     3,     4,     5,    44,
      45,     8,     9,     3,     4,     5,     3,    52,     8,     9,
      55,    87,    57,    94,    95,    85,    61,    62,    63,    64,
      65,    66,    70,    68,    67,    85,    71,    72,    69,    36,
       3,     4,     5,    40,    67,     8,     9,    44,    45,    69,
      66,    70,    87,    88,    66,    52,    66,    68,    55,    88,
      57,    67,    66,     4,    61,    62,    63,    64,    65,    66,
      70,    68,    67,    63,    71,    72,    66,    69,    68,    67,
      53,    71,    72,   131,   171,    21,    16,    68,   122,    52,
      87,   121,    55,   175,    57,    61,    86,     9,    61,    62,
      63,    64,    65,    66,    -1,    68,    -1,    -1,    71,    72,
       3,     4,     5,    -1,    -1,     8,     9,     3,     4,     5,
      -1,    -1,     8,     9,    87,    -1,    -1,     3,     4,     5,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    66,    -1,    68,    -1,    63,    71,    72,
      66,    -1,    68,    -1,    -1,    71,    72,    63,    -1,    -1,
      66,    -1,    68,    -1,    -1,    71,    72
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    40,    44,    45,   107,   110,   121,   132,   133,
       4,    71,   108,   109,   111,   112,   113,     0,   132,   113,
      86,    70,    66,    85,    68,   112,   108,   111,    67,   110,
     122,   123,     3,     4,     5,     8,     9,    63,    66,    68,
      71,    72,    90,    91,    94,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   118,     3,   117,    87,   124,   111,
      67,    70,    66,    96,    96,   110,   104,   106,   110,   114,
       4,    69,    92,    93,    96,    97,    97,     8,     9,    66,
      68,    85,   105,    71,    77,    78,    73,    74,    10,    11,
      12,    13,    79,    80,    14,    15,    69,    52,    55,    57,
      61,    62,    64,    65,    88,   106,   107,   110,   119,   120,
     124,   125,   126,   127,   128,   129,   130,   131,   124,   122,
      66,    68,   113,   115,   116,    67,    70,   115,    67,   124,
      69,    70,    67,    95,   104,   106,   104,    97,    97,    97,
      99,    99,   100,   100,   101,   101,   101,   101,   102,   102,
      66,    66,    66,    86,   106,   106,   106,   106,    86,   125,
     125,    88,    67,   117,   116,    66,   104,    97,   124,    92,
      67,    70,    69,   106,   106,   107,    86,    86,    86,    86,
      69,    67,    95,    67,    67,   120,   119,   119,   106,    53,
      67,   119,   119
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 85 "yacc.y"
    {
    (yyval.expression) = new IdentifierExpressionNode(
        new IdentifierNode(yylval.id));
  ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 90 "yacc.y"
    {
    (yyval.expression) = new ConstantExpressionNode(yylval.num);
  ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 94 "yacc.y"
    {
    (yyval.expression) = new StringExpressionNode();
  ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 98 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(2) - (3)].expression);
  ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 102 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 109 "yacc.y"
    {
    (yyval.expression) = new AsyncExpressionNode(nullptr, static_cast<CompoundStatementNode*>((yyvsp[(3) - (3)].statement)));
  ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 113 "yacc.y"
    {
    (yyval.expression) = new AsyncExpressionNode((yyvsp[(2) - (4)].expression), static_cast<CompoundStatementNode*>((yyvsp[(4) - (4)].statement)));
  ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 120 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 124 "yacc.y"
    {
    (yyvsp[(1) - (3)].expression)->next = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = (yyvsp[(1) - (3)].expression);
  ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 132 "yacc.y"
    {
    (yyval.expression) = new IdentifierExpressionNode(
        new IdentifierNode(yylval.id));
  ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 140 "yacc.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 142 "yacc.y"
    { (yyval.expression) = new ArrayExpressionNode((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression)); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 144 "yacc.y"
    { (yyval.expression) = new FunctionCallExpressionNode((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 146 "yacc.y"
    { (yyval.expression) = new FunctionCallExpressionNode((yyvsp[(1) - (3)].expression), nullptr); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 148 "yacc.y"
    { (yyval.expression) = new UnaryExpressionNode(Operator::POSTFIX_INCREMENT, (yyvsp[(1) - (2)].expression)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 150 "yacc.y"
    { (yyval.expression) = new UnaryExpressionNode(Operator::POSTFIX_DECREMENT, (yyvsp[(1) - (2)].expression)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 155 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 159 "yacc.y"
    {
    (yyvsp[(1) - (3)].expression)->next = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = (yyvsp[(1) - (3)].expression);
  ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 167 "yacc.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 169 "yacc.y"
    { (yyval.expression) = new UnaryExpressionNode(Operator::INCREMENT, (yyvsp[(2) - (2)].expression)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 171 "yacc.y"
    { (yyval.expression) = new UnaryExpressionNode(Operator::DECREMENT, (yyvsp[(2) - (2)].expression)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 173 "yacc.y"
    { (yyval.expression) = new DereferenceExpressionNode((yyvsp[(2) - (2)].expression)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 175 "yacc.y"
    { (yyval.expression) = new UnaryExpressionNode(Operator::REFERENCE, (yyvsp[(2) - (2)].expression)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 177 "yacc.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 191 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 195 "yacc.y"
    {
    (yyval.expression) = new CastExpressionNode((yyvsp[(2) - (4)].type_name), (yyvsp[(4) - (4)].expression));
  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 202 "yacc.y"
    { (yyval.expression) = new NewExpressionNode(static_cast<TypeSpecifierNode*>((yyvsp[(2) - (4)].type_specifier)), nullptr); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 204 "yacc.y"
    { (yyval.expression) = new NewExpressionNode(
        static_cast<TypeSpecifierNode*>((yyvsp[(2) - (5)].type_specifier)),
        static_cast<AbstractDeclaratorNode*>((yyvsp[(3) - (5)].node))); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 211 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 215 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::MULTIPLICATION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 219 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::DIVISION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 223 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::MODULAR, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 230 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 234 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::ADDITION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 238 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::SUBTRACTION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 245 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 249 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::LEFT_SHIFT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 253 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::RIGHT_SHIFT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 260 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 264 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::LESS, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 268 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::GREATER, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 272 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::LESS_EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 276 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::GREATER_EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 283 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 287 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 291 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::NOT_EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 365 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 369 "yacc.y"
    {
    (yyval.expression) = new AssignmentExpressionNode((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 385 "yacc.y"
    {
    (yyval.declaration_node) = new DeclarationNode((yyvsp[(1) - (3)].type_specifier), (yyvsp[(2) - (3)].init_declarator));
  ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 392 "yacc.y"
    {
    (yyval.init_declarator) = (yyvsp[(1) - (1)].init_declarator);
  ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 396 "yacc.y"
    {
    cout << "HAS NEXT\n";
    (yyvsp[(1) - (3)].init_declarator)->next = (yyvsp[(3) - (3)].init_declarator);
    (yyval.init_declarator) = (yyvsp[(3) - (3)].init_declarator);
  ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 405 "yacc.y"
    {
    (yyval.init_declarator) = new InitDeclaratorNode((yyvsp[(1) - (1)].declarator));
  ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 409 "yacc.y"
    {
    (yyval.init_declarator) = new InitDeclaratorNode((yyvsp[(1) - (3)].declarator), (yyvsp[(3) - (3)].initializer));
  ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 416 "yacc.y"
    {
    (yyval.type_specifier) = new TypeSpecifierNode(Type::VOID);
  ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 420 "yacc.y"
    {
    (yyval.type_specifier) = new TypeSpecifierNode(Type::INTEGER);
  ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 424 "yacc.y"
    {
    (yyval.type_specifier) = new TypeSpecifierNode(Type::FLOAT);
  ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 428 "yacc.y"
    {
    (yyval.type_specifier) = new TypeSpecifierNode(Type::ASYNC);
  ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 435 "yacc.y"
    {
    (yyval.declarator) = new DeclaratorNode((yyvsp[(2) - (2)].direct_declarator));
    (yyval.declarator)->pointer = static_cast<PointerNode*>((yyvsp[(1) - (2)].node));
  ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 440 "yacc.y"
    {
    (yyval.declarator) = new DeclaratorNode((yyvsp[(1) - (1)].direct_declarator));
  ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 447 "yacc.y"
    {
    (yyval.direct_declarator) = new DirectDeclaratorNode(new IdentifierNode(yylval.id));
  ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 451 "yacc.y"
    {
    // Todo : Only 1-dimensional array is allowed
    (yyval.direct_declarator) = (yyvsp[(1) - (4)].direct_declarator);
    (yyvsp[(1) - (4)].direct_declarator)->array_constant = static_cast<ConstantExpressionNode*>((yyvsp[(3) - (4)].expression));
  ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 460 "yacc.y"
    {
    (yyval.node) = new PointerNode();
  ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 464 "yacc.y"
    {
    (yyval.node) = new PointerNode();
    (yyval.node)->next = (yyvsp[(2) - (2)].node);
  ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 472 "yacc.y"
    {
    (yyval.type_name) = new TypeNameNode(
        static_cast<TypeSpecifierNode*>((yyvsp[(1) - (2)].type_specifier)),
        static_cast<AbstractDeclaratorNode*>((yyvsp[(2) - (2)].node)));
  ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 481 "yacc.y"
    { 
    AbstractDeclaratorNode *node = new AbstractDeclaratorNode();
    node->pointer = static_cast<PointerNode*>((yyvsp[(1) - (1)].node));
    (yyval.node) = node;
  ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 487 "yacc.y"
    {
    AbstractDeclaratorNode *node = new AbstractDeclaratorNode();
    node->direct_abstract_declarator = static_cast<DirectAbstractDeclaratorNode*>((yyvsp[(1) - (1)].node));
    (yyval.node) = node;
  ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 493 "yacc.y"
    {
    AbstractDeclaratorNode *node = new AbstractDeclaratorNode();
    node->pointer = static_cast<PointerNode*>((yyvsp[(1) - (2)].node));
    node->direct_abstract_declarator = static_cast<DirectAbstractDeclaratorNode*>((yyvsp[(2) - (2)].node));
    (yyval.node) = node;
  ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 503 "yacc.y"
    {
    (yyval.node) = new DirectAbstractDeclaratorNode();
  ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 510 "yacc.y"
    {
    (yyval.expression) = new ConstantExpressionNode(yylval.num);
  ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 516 "yacc.y"
    {
    (yyval.initializer) = new InitializerNode((yyvsp[(1) - (1)].expression));
  ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 522 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 523 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 524 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 525 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 526 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 527 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 528 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 529 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 535 "yacc.y"
    {
    (yyval.statement) = (yyvsp[(1) - (2)].expression);
  ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 542 "yacc.y"
    {
    (yyval.function_definition) = new FunctionDefinitionNode((yyvsp[(1) - (6)].type_specifier), (yyvsp[(2) - (6)].declarator), (yyvsp[(4) - (6)].parameter_declaration), static_cast<CompoundStatementNode*>((yyvsp[(6) - (6)].statement)));
  ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 546 "yacc.y"
    {
    (yyval.function_definition) = new FunctionDefinitionNode((yyvsp[(1) - (5)].type_specifier), (yyvsp[(2) - (5)].declarator), nullptr, static_cast<CompoundStatementNode*>((yyvsp[(5) - (5)].statement)));
  ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 553 "yacc.y"
    {
    (yyval.parameter_declaration) = (yyvsp[(1) - (1)].parameter_declaration);
  ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 557 "yacc.y"
    {
    (yyvsp[(1) - (3)].parameter_declaration)->next = (yyvsp[(3) - (3)].parameter_declaration);
    (yyval.parameter_declaration) = (yyvsp[(1) - (3)].parameter_declaration);
  ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 565 "yacc.y"
    {
    (yyval.parameter_declaration) = new ParameterDeclarationNode((yyvsp[(1) - (2)].type_specifier), (yyvsp[(2) - (2)].declarator));
  ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 572 "yacc.y"
    {
    (yyval.statement) = new CompoundStatementNode(nullptr);
  ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 576 "yacc.y"
    {
    (yyval.statement) = new CompoundStatementNode((yyvsp[(2) - (3)].node));
  ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 583 "yacc.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].declaration_node);
  ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 587 "yacc.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].statement);
  ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 591 "yacc.y"
    {
    (yyvsp[(1) - (2)].declaration_node)->next = (yyvsp[(2) - (2)].node);
    (yyval.node) = (yyvsp[(1) - (2)].declaration_node);
  ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 596 "yacc.y"
    {
    (yyvsp[(1) - (2)].statement)->next = (yyvsp[(2) - (2)].node);
    (yyval.node) = (yyvsp[(1) - (2)].statement);
  ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 604 "yacc.y"
    {
    (yyval.statement) = new SelectionStatementNode((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement));
  ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 607 "yacc.y"
    {
    (yyval.statement) = new SelectionStatementNode((yyvsp[(3) - (7)].expression), (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement));
  ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 614 "yacc.y"
    {
    (yyval.statement) = new IterationStatementNode((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement));
  ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 620 "yacc.y"
    { (yyval.statement) = new ForStatementNode((yyvsp[(3) - (7)].declaration_node), (yyvsp[(4) - (7)].statement), (yyvsp[(5) - (7)].expression), (yyvsp[(7) - (7)].statement)); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 625 "yacc.y"
    {
    (yyval.statement) = new ReturnStatementNode((yyvsp[(2) - (3)].expression));
  ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 629 "yacc.y"
    {
    (yyval.statement) = new ReturnStatementNode();
  ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 636 "yacc.y"
    {
    (yyval.statement) = new RunStatementNode((yyvsp[(2) - (3)].expression));
  ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 640 "yacc.y"
    {
    (yyval.statement) = new JoinStatementNode((yyvsp[(2) - (3)].expression));
  ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 647 "yacc.y"
    {
    (yyval.statement) = new PrintStatementNode((yyvsp[(2) - (3)].expression));
  ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 653 "yacc.y"
    {
    (yyvsp[(1) - (1)].declaration_node)->Print();
    visitor->Visit((yyvsp[(1) - (1)].declaration_node));
    symbol_table->PrintCode();
  ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 659 "yacc.y"
    {
    (yyvsp[(1) - (1)].function_definition)->Print();
    visitor->Visit((yyvsp[(1) - (1)].function_definition));
    symbol_table->PrintCode();
  ;}
    break;



/* Line 1455 of yacc.c  */
#line 2545 "yacc.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 671 "yacc.y"



main() {
  init_ast();
  yyparse();
  // root->Print();
}

void yyerror(char * s)
{
  fprintf(stderr, "line %d: %s\n", line_num, s);
}

