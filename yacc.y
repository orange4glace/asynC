%{  
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include <list>
#include "ast/ast.h"

using namespace std;

int line_num = 1;

int yylex();
void yyerror(char * s);

%}

%union {
  int num;
  char* id;
  DeclarationNode *declaration_node;
  InitDeclaratorNode *init_declarator;
  TypeSpecifierNode *type_specifier;
  InitializerNode *initializer;
  ExpressionNode *expression;
}

%error-verbose

%token <num> CONSTANT
%token <id> IDENTIFIER
%type <declaration_node> declaration
%type <init_declarator> init_declarator_list init_declarator
%type <type_specifier> type_specifier
%type <initializer> initializer

%error-verbose

%token STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
  : IDENTIFIER
  {

  }
  | CONSTANT
  | STRING_LITERAL
  | '(' expression ')'
  ;

postfix_expression
  : primary_expression
  ;

unary_expression
  : postfix_expression
  | INC_OP unary_expression
  | DEC_OP unary_expression
  | unary_opertaor cast_expression
  ;

unary_opertaor
  : '&'
  | '*'
  | '+'
  | '-'
  | '~'
  | '!'
  ;

cast_expression
  : unary_expression
  | '(' ')' cast_expression
  ;

multiplicative_expression
  : cast_expression
  | multiplicative_expression '*' cast_expression
  | multiplicative_expression '/' cast_expression
  | multiplicative_expression '%' cast_expression
  ;

additive_expression
  : multiplicative_expression
  | additive_expression '+' multiplicative_expression
  | additive_expression '-' multiplicative_expression
  ;

shift_expression
  : additive_expression
  | shift_expression LEFT_OP additive_expression
  | shift_expression RIGHT_OP additive_expression
  ;

relational_expression
  : shift_expression
  | relational_expression '<' shift_expression
  | relational_expression '>' shift_expression
  | relational_expression LE_OP shift_expression
  | relational_expression GE_OP shift_expression
  ;

equality_expression
  : relational_expression
  | equality_expression EQ_OP relational_expression
  | equality_expression NE_OP relational_expression
  ;

and_expression
  : equality_expression
  | and_expression '&' equality_expression
  ;

exclusive_or_expression
  : and_expression
  | exclusive_or_expression '^' and_expression
  ;

inclusive_or_expression
  : exclusive_or_expression
  | inclusive_or_expression '|' exclusive_or_expression
  ;

logical_and_expression
  : inclusive_or_expression
  | logical_and_expression AND_OP inclusive_or_expression
  ;

logical_or_expression
  : logical_and_expression
  | logical_or_expression OR_OP logical_and_expression
  ;

conditional_expression
  : logical_or_expression
  | logical_or_expression '?' expression ':' conditional_expression
  ;

assignment_expression
  : conditional_expression
  | unary_expression assignment_operator assignment_expression
  ;

assignment_operator
  : '='
  ;

expression
  : assignment_expression
  | expression ',' assignment_expression
  ;

declaration
  : type_specifier init_declarator_list ';'
  {
    $$ = new DeclarationNode($1, $2);
  }
  ;

init_declarator_list
  : init_declarator
  {
    $$ = $1;
  }
  | init_declarator ',' init_declarator_list
  {
    $1->next = $3;
    $$ = $3;
  }
  ;

init_declarator
  : declarator
  {
    $$ = new InitDeclaratorNode();
  }
  | declarator '=' initializer
  {
    $$ = new InitDeclaratorNode($3);
  }
  ;

type_specifier
  : VOID
  {
    $$ = new TypeSpecifierNode("void");
  }
  | INT
  {
    $$ = new TypeSpecifierNode("int");
  }
  ;

declarator
  : direct_declarator
  ;

direct_declarator
  : IDENTIFIER
  ;

initializer
  : assignment_expression
  {
    $$ = new InitializerNode(nullptr);
  }
  ;

external_declaration 
  : declaration
  {
    $1->Print();
  }
  ;

translation_unit
  : external_declaration
  | translation_unit external_declaration
  ;

%%


main() {
  yyparse();
  // root->Print();
}

void yyerror(char * s)
{
  fprintf(stderr, "line %d: %s\n", line_num, s);
}
