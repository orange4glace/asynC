%{  
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

%}

%union {
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

  StatementNode *statement;
}

%error-verbose

%token <num> CONSTANT
%token <id> IDENTIFIER
%type <declaration_node> declaration
%type <init_declarator> init_declarator_list init_declarator
%type <type_specifier> type_specifier
%type <initializer> initializer
%type <declarator> declarator
%type <direct_declarator> direct_declarator
%type <expression> primary_expression postfix_expression unary_expression
    cast_expression multiplicative_expression additive_expression
    shift_expression relational_expression equality_expression and_expression
    exclusive_or_expression inclusive_or_expression logical_and_expression
    logical_or_expression conditional_expression expression assignment_expression
%type <statement> statement expression_statement compound_statement
%type <node> compound_statement_body


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
    $$ = new IdentifierExpressionNode(
        new IdentifierNode(yylval.id));
  }
  | CONSTANT
  {
    $$ = new ConstantExpressionNode(yylval.num);
  }
  | STRING_LITERAL
  {
    $$ = new StringExpressionNode();
  }
  | '(' expression ')'
  {
    $$ = $2;
  }
  ;

postfix_expression
  : primary_expression
  {
    $$ = $1;
  }
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
//: unary_expression
  : postfix_expression
  {
    $$ = $1;
  }
//| '(' ')' cast_expression
  ;

multiplicative_expression
  : cast_expression
  {
    $$ = $1;
  }
  | multiplicative_expression '*' cast_expression
  {
    $$ = new AdditionExpressionNode($1, $3);
  }
  | multiplicative_expression '/' cast_expression
  {
    $$ = new AdditionExpressionNode($1, $3);
  }
  | multiplicative_expression '%' cast_expression
  {
    $$ = new AdditionExpressionNode($1, $3);
  }
  ;

additive_expression
  : multiplicative_expression
  {
    $$ = $1;
  }
  | additive_expression '+' multiplicative_expression
  {
    $$ = new AdditionExpressionNode($1, $3);
  }
  | additive_expression '-' multiplicative_expression
  {
    $$ = new SubtractionExpressionNode($1, $3);
  }
  ;

shift_expression
  : additive_expression
  {
    $$ = $1;
  }
  | shift_expression LEFT_OP additive_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  | shift_expression RIGHT_OP additive_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  ;

relational_expression
  : shift_expression
  {
    $$ = $1;
  }
  | relational_expression '<' shift_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  | relational_expression '>' shift_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  | relational_expression LE_OP shift_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  | relational_expression GE_OP shift_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  ;

equality_expression
  : relational_expression
  {
    $$ = $1;
  }
  | equality_expression EQ_OP relational_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  | equality_expression NE_OP relational_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  ;

and_expression
  : equality_expression
  {
    $$ = $1;
  }
  | and_expression '&' equality_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  ;

exclusive_or_expression
  : and_expression
  {
    $$ = $1;
  }
  | exclusive_or_expression '^' and_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  ;

inclusive_or_expression
  : exclusive_or_expression
  {
    $$ = $1;
  }
  | inclusive_or_expression '|' exclusive_or_expression
  {
    $$ = new InclusiveORExpressionNode($1, $3);
  }
  ;

logical_and_expression
  : inclusive_or_expression
  {
    $$ = $1;
  }
  | logical_and_expression AND_OP inclusive_or_expression
  {
    $$ = new LogicalANDExpressionNode($1, $3);
  }
  ;

logical_or_expression
  : logical_and_expression
  {
    $$ = $1;
  }
  | logical_or_expression OR_OP logical_and_expression
  {
    $$ = new LogicalORExpressionNode($1, $3);
  }
  ;

conditional_expression
  : logical_or_expression
  {
    $$ = $1;
  }
  | logical_or_expression '?' expression ':' conditional_expression
  {
    $$ = new ConditionalExpressionNode($1, $3, $5);
  }
  ;

assignment_expression
//: conditional_expression
  : additive_expression
  {
    $$ = $1;
  }
  | unary_expression assignment_operator assignment_expression
  {
    $$ = new AssignmentExpressionNode($1, $3);
  }
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
    cout << "HAS NEXT\n";
    $1->next = $3;
    $$ = $3;
  }
  ;

init_declarator
  : declarator
  {
    $$ = new InitDeclaratorNode($1);
  }
  | declarator '=' initializer
  {
    $$ = new InitDeclaratorNode($1, $3);
  }
  ;

type_specifier
  : VOID
  {
    $$ = new TypeSpecifierNode(Type::VOID);
  }
  | INT
  {
    $$ = new TypeSpecifierNode(Type::INTEGER);
  }
  ;

declarator
  : direct_declarator
  {
    $$ = new DeclaratorNode($1);
  }
  ;

direct_declarator
  : IDENTIFIER
  {
    $$ = new DirectDeclaratorNode(new IdentifierNode(yylval.id));
  }
  ;

initializer
  : assignment_expression
  {
    $$ = new InitializerNode($1);
  }
  ;

statement
  : compound_statement
  {
    $$ = $1;
  }
  | expression_statement
  {
    $$ = $1;
  }
  ;

expression_statement
//: ';'
  : expression ';'
  {
    $$ = $1;
  }
  ;

function_definition
  : type_specifier declarator '(' parameter_declaration_list ')' compound_statement
  {
    $$ = new FunctionDefinitionNode($1, $2, $4, $6);
  }
  | type_specifier declarator '(' ')' compound_statement
  {
    $$ = new FunctionDefinitionNode($1, $2, nullptr, $5);
  }
  ;

parameter_declaration_list
  : parameter_declaration
  {
    $$ = $1;
  }
  | parameter_declaration ',' parameter_declaration_list
  {
    $$ = $1;
    $1->next = $2;
  }
  ;

parameter_declaration
  : type_specifier declarator
  {
    $$ = new ParameterDeclarationNode($1, $2);
  }
  ;

compound_statement
  : '{' '}'
  {
    $$ = new CompoundStatementNode(nullptr);
  }
  | '{' compound_statement_body '}'
  {
    $$ = new CompoundStatementNode($2);
  }
  ;

compound_statement_body
  : declaration
  {
    $$ = $1;
  }
  | compound_statement_body declaration
  {
    $1->next = $2;
    $$ = $1;
  }
  ;

external_declaration 
  : declaration
  {
    $1->Print();
    visitor->Visit($1);
  }
  | function_definition
  ;

translation_unit
  : external_declaration
  | translation_unit external_declaration
  ;

%%


main() {
  init_ast();
  yyparse();
  // root->Print();
}

void yyerror(char * s)
{
  fprintf(stderr, "line %d: %s\n", line_num, s);
}
