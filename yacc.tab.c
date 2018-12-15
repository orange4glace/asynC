
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
     PRINT = 317
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
#line 214 "yacc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 226 "yacc.tab.c"

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,     2,     2,     2,    75,    68,     2,
      63,    64,    69,    70,    67,    71,     2,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    83,
      76,    82,    77,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    79,    85,    72,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    19,    24,
      26,    30,    32,    34,    39,    44,    46,    50,    52,    55,
      58,    60,    65,    67,    71,    75,    79,    81,    85,    89,
      91,    95,    99,   101,   105,   109,   113,   117,   119,   123,
     127,   129,   133,   135,   137,   141,   145,   147,   151,   153,
     157,   159,   161,   163,   165,   167,   169,   174,   177,   179,
     180,   182,   184,   186,   188,   190,   192,   194,   196,   199,
     206,   212,   214,   218,   221,   224,   228,   230,   232,   235,
     238,   244,   252,   258,   262,   266,   268,   270,   272
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
     126,     0,    -1,     4,    -1,     3,    -1,     5,    -1,    63,
     102,    64,    -1,    88,    -1,    65,    66,   119,    -1,    65,
      89,    66,   119,    -1,    90,    -1,    90,    67,    89,    -1,
       4,    -1,    87,    -1,    91,    65,   102,    66,    -1,    91,
      63,    92,    64,    -1,   100,    -1,   100,    67,    92,    -1,
      91,    -1,     8,    93,    -1,     9,    93,    -1,    93,    -1,
      63,   109,    64,    94,    -1,    94,    -1,    95,    69,    94,
      -1,    95,    74,    94,    -1,    95,    75,    94,    -1,    95,
      -1,    96,    70,    95,    -1,    96,    71,    95,    -1,    96,
      -1,    97,    10,    96,    -1,    97,    11,    96,    -1,    97,
      -1,    98,    76,    97,    -1,    98,    77,    97,    -1,    98,
      12,    97,    -1,    98,    13,    97,    -1,    98,    -1,    99,
      14,    98,    -1,    99,    15,    98,    -1,    99,    -1,    93,
     101,   100,    -1,    82,    -1,   100,    -1,   102,    67,   100,
      -1,   106,   104,    83,    -1,   105,    -1,   105,    67,   104,
      -1,   107,    -1,   107,    82,   113,    -1,    44,    -1,    36,
      -1,    40,    -1,    45,    -1,   108,    -1,     4,    -1,   108,
      65,   112,    66,    -1,   106,   110,    -1,   111,    -1,    -1,
       3,    -1,   100,    -1,   119,    -1,   122,    -1,   121,    -1,
     123,    -1,   124,    -1,   115,    -1,   102,    83,    -1,   106,
     107,    63,   117,    64,   119,    -1,   106,   107,    63,    64,
     119,    -1,   118,    -1,   118,    67,   117,    -1,   106,   107,
      -1,    84,    85,    -1,    84,   120,    85,    -1,   103,    -1,
     114,    -1,   103,   120,    -1,   114,   120,    -1,    52,    63,
     102,    64,   114,    -1,    52,    63,   102,    64,   114,    53,
     114,    -1,    55,    63,   102,    64,   114,    -1,    61,   102,
      83,    -1,    62,   102,    83,    -1,   103,    -1,   116,    -1,
     125,    -1,   126,   125,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    89,    93,    97,   101,   108,   112,   119,
     123,   131,   139,   141,   143,   148,   152,   160,   162,   164,
     179,   183,   190,   194,   198,   202,   209,   213,   217,   224,
     228,   232,   239,   243,   247,   251,   255,   262,   266,   270,
     344,   348,   355,   359,   360,   364,   371,   375,   384,   388,
     395,   399,   403,   407,   414,   421,   425,   434,   443,   452,
     458,   464,   471,   472,   473,   474,   475,   476,   481,   488,
     492,   499,   503,   511,   518,   522,   529,   533,   537,   542,
     550,   554,   560,   566,   573,   579,   585,   594,   595
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
  "CONTINUE", "BREAK", "RETURN", "PRINT", "'('", "')'", "'['", "']'",
  "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "async_expression", "variable_capture_list",
  "variable_capture", "postfix_expression", "argument_expression_list",
  "unary_expression", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "assignment_expression", "assignment_operator",
  "expression", "declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "direct_declarator", "type_name",
  "abstract_declarator", "direct_abstract_declarator",
  "constant_expression", "initializer", "statement",
  "expression_statement", "function_definition",
  "parameter_declaration_list", "parameter_declaration",
  "compound_statement", "compound_statement_body", "selection_statement",
  "iteration_statement", "return_statement", "print_statement",
  "external_declaration", "translation_unit", 0
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
     315,   316,   317,    40,    41,    91,    93,    44,    38,    42,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63,    58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    90,    91,    91,    91,    92,    92,    93,    93,    93,
      94,    94,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    98,    98,    98,    98,    98,    99,    99,    99,
     100,   100,   101,   102,   102,   103,   104,   104,   105,   105,
     106,   106,   106,   106,   107,   108,   108,   109,   110,   111,
     112,   113,   114,   114,   114,   114,   114,   114,   115,   116,
     116,   117,   117,   118,   119,   119,   120,   120,   120,   120,
     121,   121,   122,   123,   124,   125,   125,   126,   126
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     3,     4,     1,
       3,     1,     1,     4,     4,     1,     3,     1,     2,     2,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     1,     3,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     2,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     6,
       5,     1,     3,     2,     2,     3,     1,     1,     2,     2,
       5,     7,     5,     3,     3,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    51,    52,    50,    53,    85,     0,    86,    87,     0,
      55,     0,    46,    48,    54,     1,    88,    45,     0,     0,
       0,     0,    47,    48,     0,     0,     0,    71,     3,     2,
       4,     0,     0,     0,     0,    12,     6,    17,    20,    22,
      26,    29,    32,    37,    40,    61,    49,    60,     0,     0,
      70,    73,     0,     0,     0,    18,    19,    43,     0,    59,
       0,    11,     0,     0,     9,     0,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,     0,     0,     0,    74,     0,    76,
       0,    77,    67,    62,     0,    64,    63,    65,    66,    69,
      72,     5,     0,    57,    58,     0,     7,     0,     0,     0,
      15,     0,    41,    20,    23,    24,    25,    27,    28,    30,
      31,    35,    36,    33,    34,    38,    39,     0,     0,     0,
       0,    68,    78,    79,    75,    44,    21,     8,    10,    14,
       0,    13,     0,     0,    83,    84,    16,     0,     0,    80,
      82,     0,    81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    35,    36,    63,    64,    37,   109,    38,    39,    40,
      41,    42,    43,    44,    57,    68,    88,    89,    11,    12,
      90,    23,    14,    60,   103,   104,    48,    46,    91,    92,
       7,    26,    27,    93,    94,    95,    96,    97,    98,     8,
       9
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int16 yypact[] =
{
      62,   -92,   -92,   -92,   -92,   -92,     8,   -92,   -92,    19,
     -92,   -65,   -42,   -59,   -34,   -92,   -92,   -92,     8,   -12,
     173,    36,   -92,     1,   -18,     8,    -2,     3,   -92,   -92,
     -92,   180,   180,   166,    -1,   -92,   -92,   -16,    17,   -92,
     -31,    48,   112,     4,   111,   -92,   -92,   -92,    20,     6,
     -92,   -92,   -18,    62,   173,   -92,   -92,   -92,    12,   -92,
      39,   -92,   -18,    45,    60,   173,   173,   -92,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   -92,    52,    66,   173,   173,   -92,   -54,    69,
       8,    69,   -92,   -92,    50,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   173,   -92,   -92,   173,   -92,   -18,   129,    80,
      81,    71,   -92,   -92,   -92,   -92,   -92,   -31,   -31,    48,
      48,   112,   112,   112,   112,     4,     4,   173,   173,   -47,
     -46,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     173,   -92,    33,    37,   -92,   -92,   -92,    84,    84,   114,
     -92,    84,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   -92,    44,   -92,   -92,    46,    85,   -64,    78,
      98,    64,    99,   -92,   -20,   -92,   -32,    26,   169,   -92,
      75,     2,   -92,   -92,   -92,   -92,   -92,   -92,   -91,   -92,
     -92,   138,   -92,   -22,    21,   -92,   -92,   -92,   -92,   183,
     -92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      45,    58,    50,    61,    19,   114,   115,   116,    13,    28,
      29,    30,    10,   102,    31,    32,    76,    77,    17,    15,
     102,   102,    58,    20,     1,    18,     5,    51,     2,   131,
      99,    21,     3,     4,   111,     5,   144,   145,    69,    47,
     106,   136,     1,    70,    71,   110,     2,    65,   112,    66,
       3,     4,    24,   129,   130,     1,   149,   150,    83,     2,
     152,    84,    52,     3,     4,    62,    49,    85,    86,    33,
      53,    34,    28,    29,    30,     6,   101,    31,    32,   102,
      78,    79,   135,    20,     6,   137,    82,    28,    29,    30,
      49,    87,    31,    32,    25,   142,   143,   147,     1,    67,
     102,   148,     2,   105,   102,     1,     3,     4,    59,     2,
     132,   107,   133,     3,     4,   127,    55,    56,    72,    73,
     110,    83,    74,    75,    84,    80,    81,   108,    25,   128,
      85,    86,    33,    61,    34,   134,    83,   141,   102,    84,
     121,   122,   123,   124,   139,    85,    86,    33,   140,    34,
     117,   118,   138,    49,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   151,    49,    28,
      29,    30,   119,   120,    31,    32,    28,    29,    30,   125,
     126,    31,    32,    28,    29,    30,   146,    22,    31,    32,
     113,   100,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     2,     0,     0,     0,
       3,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,    34,     0,     0,     0,     0,    33,     0,    34,     0,
       0,     0,     0,    54,     0,    34
};

static const yytype_int16 yycheck[] =
{
      20,    33,    24,     4,    63,    69,    70,    71,     6,     3,
       4,     5,     4,    67,     8,     9,    12,    13,    83,     0,
      67,    67,    54,    82,    36,    67,     0,    25,    40,    83,
      52,    65,    44,    45,    66,     9,    83,    83,    69,     3,
      62,   105,    36,    74,    75,    65,    40,    63,    68,    65,
      44,    45,    64,    85,    86,    36,   147,   148,    52,    40,
     151,    55,    64,    44,    45,    66,    84,    61,    62,    63,
      67,    65,     3,     4,     5,     0,    64,     8,     9,    67,
      76,    77,   102,    82,     9,   107,    66,     3,     4,     5,
      84,    85,     8,     9,    19,   127,   128,    64,    36,    82,
      67,    64,    40,    64,    67,    36,    44,    45,    33,    40,
      89,    66,    91,    44,    45,    63,    31,    32,    70,    71,
     140,    52,    10,    11,    55,    14,    15,    67,    53,    63,
      61,    62,    63,     4,    65,    85,    52,    66,    67,    55,
      76,    77,    78,    79,    64,    61,    62,    63,    67,    65,
      72,    73,   108,    84,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    53,    84,     3,
       4,     5,    74,    75,     8,     9,     3,     4,     5,    80,
      81,     8,     9,     3,     4,     5,   140,    18,     8,     9,
     105,    53,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    65,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      -1,    -1,    -1,    63,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    40,    44,    45,   103,   106,   116,   125,   126,
       4,   104,   105,   107,   108,     0,   125,    83,    67,    63,
      82,    65,   104,   107,    64,   106,   117,   118,     3,     4,
       5,     8,     9,    63,    65,    87,    88,    91,    93,    94,
      95,    96,    97,    98,    99,   100,   113,     3,   112,    84,
     119,   107,    64,    67,    63,    93,    93,   100,   102,   106,
     109,     4,    66,    89,    90,    63,    65,    82,   101,    69,
      74,    75,    70,    71,    10,    11,    12,    13,    76,    77,
      14,    15,    66,    52,    55,    61,    62,    85,   102,   103,
     106,   114,   115,   119,   120,   121,   122,   123,   124,   119,
     117,    64,    67,   110,   111,    64,   119,    66,    67,    92,
     100,   102,   100,    93,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    97,    98,    98,    63,    63,   102,
     102,    83,   120,   120,    85,   100,    94,   119,    89,    64,
      67,    66,   102,   102,    83,    83,    92,    64,    64,   114,
     114,    53,   114
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
#line 149 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 153 "yacc.y"
    {
    (yyvsp[(1) - (3)].expression)->next = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = (yyvsp[(1) - (3)].expression);
  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 161 "yacc.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 163 "yacc.y"
    { (yyval.expression) = new UnaryExpressionNode(Operator::INCREMENT, (yyvsp[(2) - (2)].expression)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 165 "yacc.y"
    { (yyval.expression) = new UnaryExpressionNode(Operator::DECREMENT, (yyvsp[(2) - (2)].expression)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 180 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 184 "yacc.y"
    {
    (yyval.expression) = new CastExpressionNode((yyvsp[(2) - (4)].type_name), (yyvsp[(4) - (4)].expression));
  ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 191 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 195 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::MULTIPLICATION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 199 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::DIVISION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 203 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::MODULAR, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 210 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 214 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::ADDITION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 218 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::SUBTRACTION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 225 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 229 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::LEFT_SHIFT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 233 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::RIGHT_SHIFT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 240 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 244 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::LESS, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 248 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::GREATER, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 252 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::LESS_EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 256 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::GREATER_EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 263 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 267 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 271 "yacc.y"
    {
    (yyval.expression) = new BinaryExpressionNode(Operator::NOT_EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 345 "yacc.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
  ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 349 "yacc.y"
    {
    (yyval.expression) = new AssignmentExpressionNode((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 365 "yacc.y"
    {
    (yyval.declaration_node) = new DeclarationNode((yyvsp[(1) - (3)].type_specifier), (yyvsp[(2) - (3)].init_declarator));
  ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 372 "yacc.y"
    {
    (yyval.init_declarator) = (yyvsp[(1) - (1)].init_declarator);
  ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 376 "yacc.y"
    {
    cout << "HAS NEXT\n";
    (yyvsp[(1) - (3)].init_declarator)->next = (yyvsp[(3) - (3)].init_declarator);
    (yyval.init_declarator) = (yyvsp[(3) - (3)].init_declarator);
  ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 385 "yacc.y"
    {
    (yyval.init_declarator) = new InitDeclaratorNode((yyvsp[(1) - (1)].declarator));
  ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 389 "yacc.y"
    {
    (yyval.init_declarator) = new InitDeclaratorNode((yyvsp[(1) - (3)].declarator), (yyvsp[(3) - (3)].initializer));
  ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 396 "yacc.y"
    {
    (yyval.type_specifier) = new TypeSpecifierNode(Type::VOID);
  ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 400 "yacc.y"
    {
    (yyval.type_specifier) = new TypeSpecifierNode(Type::INTEGER);
  ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 404 "yacc.y"
    {
    (yyval.type_specifier) = new TypeSpecifierNode(Type::FLOAT);
  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 408 "yacc.y"
    {
    (yyval.type_specifier) = new TypeSpecifierNode(Type::ASYNC);
  ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 415 "yacc.y"
    {
    (yyval.declarator) = new DeclaratorNode((yyvsp[(1) - (1)].direct_declarator));
  ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 422 "yacc.y"
    {
    (yyval.direct_declarator) = new DirectDeclaratorNode(new IdentifierNode(yylval.id));
  ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 426 "yacc.y"
    {
    // Todo : Only 1-dimensional array is allowed
    (yyval.direct_declarator) = (yyvsp[(1) - (4)].direct_declarator);
    (yyvsp[(1) - (4)].direct_declarator)->array_constant = static_cast<ConstantExpressionNode*>((yyvsp[(3) - (4)].expression));
  ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 435 "yacc.y"
    {
    (yyval.type_name) = new TypeNameNode(
        static_cast<TypeSpecifierNode*>((yyvsp[(1) - (2)].type_specifier)),
        static_cast<AbstractDeclaratorNode*>((yyvsp[(2) - (2)].node)));
  ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 444 "yacc.y"
    {
    (yyval.node) = new AbstractDeclaratorNode(
      static_cast<DirectAbstractDeclaratorNode*>((yyvsp[(1) - (1)].node)));
  ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 452 "yacc.y"
    {
    (yyval.node) = new DirectAbstractDeclaratorNode();
  ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 459 "yacc.y"
    {
    (yyval.expression) = new ConstantExpressionNode(yylval.num);
  ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 465 "yacc.y"
    {
    (yyval.initializer) = new InitializerNode((yyvsp[(1) - (1)].expression));
  ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 471 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 472 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 473 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 474 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 475 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 476 "yacc.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 482 "yacc.y"
    {
    (yyval.statement) = (yyvsp[(1) - (2)].expression);
  ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 489 "yacc.y"
    {
    (yyval.function_definition) = new FunctionDefinitionNode((yyvsp[(1) - (6)].type_specifier), (yyvsp[(2) - (6)].declarator), (yyvsp[(4) - (6)].parameter_declaration), static_cast<CompoundStatementNode*>((yyvsp[(6) - (6)].statement)));
  ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 493 "yacc.y"
    {
    (yyval.function_definition) = new FunctionDefinitionNode((yyvsp[(1) - (5)].type_specifier), (yyvsp[(2) - (5)].declarator), nullptr, static_cast<CompoundStatementNode*>((yyvsp[(5) - (5)].statement)));
  ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 500 "yacc.y"
    {
    (yyval.parameter_declaration) = (yyvsp[(1) - (1)].parameter_declaration);
  ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 504 "yacc.y"
    {
    (yyvsp[(1) - (3)].parameter_declaration)->next = (yyvsp[(3) - (3)].parameter_declaration);
    (yyval.parameter_declaration) = (yyvsp[(1) - (3)].parameter_declaration);
  ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 512 "yacc.y"
    {
    (yyval.parameter_declaration) = new ParameterDeclarationNode((yyvsp[(1) - (2)].type_specifier), (yyvsp[(2) - (2)].declarator));
  ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 519 "yacc.y"
    {
    (yyval.statement) = new CompoundStatementNode(nullptr);
  ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 523 "yacc.y"
    {
    (yyval.statement) = new CompoundStatementNode((yyvsp[(2) - (3)].node));
  ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 530 "yacc.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].declaration_node);
  ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 534 "yacc.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].statement);
  ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 538 "yacc.y"
    {
    (yyvsp[(1) - (2)].declaration_node)->next = (yyvsp[(2) - (2)].node);
    (yyval.node) = (yyvsp[(1) - (2)].declaration_node);
  ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 543 "yacc.y"
    {
    (yyvsp[(1) - (2)].statement)->next = (yyvsp[(2) - (2)].node);
    (yyval.node) = (yyvsp[(1) - (2)].statement);
  ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 551 "yacc.y"
    {
    (yyval.statement) = new SelectionStatementNode((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement));
  ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 554 "yacc.y"
    {
    (yyval.statement) = new SelectionStatementNode((yyvsp[(3) - (7)].expression), (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement));
  ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 561 "yacc.y"
    {
    (yyval.statement) = new IterationStatementNode((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement));
  ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 567 "yacc.y"
    {
    (yyval.statement) = new ReturnStatementNode((yyvsp[(2) - (3)].expression));
  ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 574 "yacc.y"
    {
    (yyval.statement) = new PrintStatementNode((yyvsp[(2) - (3)].expression));
  ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 580 "yacc.y"
    {
    (yyvsp[(1) - (1)].declaration_node)->Print();
    visitor->Visit((yyvsp[(1) - (1)].declaration_node));
    symbol_table->PrintCode();
  ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 586 "yacc.y"
    {
    (yyvsp[(1) - (1)].function_definition)->Print();
    visitor->Visit((yyvsp[(1) - (1)].function_definition));
    symbol_table->PrintCode();
  ;}
    break;



/* Line 1455 of yacc.c  */
#line 2333 "yacc.tab.c"
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
#line 598 "yacc.y"



main() {
  init_ast();
  yyparse();
  // root->Print();
}

void yyerror(char * s)
{
  fprintf(stderr, "line %d: %s\n", line_num, s);
}

