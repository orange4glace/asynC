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
  FunctionDefinitionNode *function_definition;
  ParameterDeclarationNode *parameter_declaration;
  TypeNameNode *type_name;

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
    argument_expression_list constant_expression async_expression
    variable_capture_list variable_capture
%type <statement> statement expression_statement compound_statement selection_statement iteration_statement for_statement
    return_statement print_statement
%type <function_definition> function_definition
%type <parameter_declaration> parameter_declaration_list parameter_declaration
%type <type_name> type_name
%type <node> compound_statement_body abstract_declarator direct_abstract_declarator


%error-verbose

%token STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID ASYNC
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN PRINT

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
  | async_expression
  {
    $$ = $1;
  }
  ;

async_expression
  : '[' ']' compound_statement
  {
    $$ = new AsyncExpressionNode(nullptr, static_cast<CompoundStatementNode*>($3));
  }
  | '[' variable_capture_list ']' compound_statement
  {
    $$ = new AsyncExpressionNode($2, static_cast<CompoundStatementNode*>($4));
  }
  ;

variable_capture_list
  : variable_capture
  {
    $$ = $1;
  }
  | variable_capture ',' variable_capture_list
  {
    $1->next = $3;
    $$ = $1;
  }
  ;

variable_capture
  : IDENTIFIER
  {
    $$ = new IdentifierExpressionNode(
        new IdentifierNode(yylval.id));
  }
  ;

postfix_expression
  : primary_expression
  { $$ = $1; }
  | postfix_expression '[' expression ']'
  { $$ = new ArrayExpressionNode($1, $3); }
  | postfix_expression '(' argument_expression_list ')'
  { $$ = new FunctionCallExpressionNode($1, $3); }
  | postfix_expression '(' ')'
  { $$ = new FunctionCallExpressionNode($1, nullptr); }
  ;

argument_expression_list
  : assignment_expression
  {
    $$ = $1;
  }
  | assignment_expression ',' argument_expression_list
  {
    $1->next = $3;
    $$ = $1;
  }
  ;

unary_expression
  : postfix_expression
  { $$ = $1; }
  | INC_OP unary_expression
  { $$ = new UnaryExpressionNode(Operator::INCREMENT, $2); }
  | DEC_OP unary_expression
  { $$ = new UnaryExpressionNode(Operator::DECREMENT, $2); }
//| unary_operator cast_expression
  ;

unary_operator
  : '&'
  | '*'
  | '+'
  | '-'
  | '~'
  | '!'
  ;

cast_expression
  : unary_expression
  {
    $$ = $1;
  }
  | '(' type_name ')' cast_expression
  {
    $$ = new CastExpressionNode($2, $4);
  }
  ;

multiplicative_expression
  : cast_expression
  {
    $$ = $1;
  }
  | multiplicative_expression '*' cast_expression
  {
    $$ = new BinaryExpressionNode(Operator::MULTIPLICATION, $1, $3);
  }
  | multiplicative_expression '/' cast_expression
  {
    $$ = new BinaryExpressionNode(Operator::DIVISION, $1, $3);
  }
  | multiplicative_expression '%' cast_expression
  {
    $$ = new BinaryExpressionNode(Operator::MODULAR, $1, $3);
  }
  ;

additive_expression
  : multiplicative_expression
  {
    $$ = $1;
  }
  | additive_expression '+' multiplicative_expression
  {
    $$ = new BinaryExpressionNode(Operator::ADDITION, $1, $3);
  }
  | additive_expression '-' multiplicative_expression
  {
    $$ = new BinaryExpressionNode(Operator::SUBTRACTION, $1, $3);
  }
  ;

shift_expression
  : additive_expression
  {
    $$ = $1;
  }
  | shift_expression LEFT_OP additive_expression
  {
    $$ = new BinaryExpressionNode(Operator::LEFT_SHIFT, $1, $3);
  }
  | shift_expression RIGHT_OP additive_expression
  {
    $$ = new BinaryExpressionNode(Operator::RIGHT_SHIFT, $1, $3);
  }
  ;

relational_expression
  : shift_expression
  {
    $$ = $1;
  }
  | relational_expression '<' shift_expression
  {
    $$ = new BinaryExpressionNode(Operator::LESS, $1, $3);
  }
  | relational_expression '>' shift_expression
  {
    $$ = new BinaryExpressionNode(Operator::GREATER, $1, $3);
  }
  | relational_expression LE_OP shift_expression
  {
    $$ = new BinaryExpressionNode(Operator::LESS_EQUAL, $1, $3);
  }
  | relational_expression GE_OP shift_expression
  {
    $$ = new BinaryExpressionNode(Operator::GREATER_EQUAL, $1, $3);
  }
  ;

equality_expression
  : relational_expression
  {
    $$ = $1;
  }
  | equality_expression EQ_OP relational_expression
  {
    $$ = new BinaryExpressionNode(Operator::EQUAL, $1, $3);
  }
  | equality_expression NE_OP relational_expression
  {
    $$ = new BinaryExpressionNode(Operator::NOT_EQUAL, $1, $3);
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
  : equality_expression
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
  | FLOAT
  {
    $$ = new TypeSpecifierNode(Type::FLOAT);
  }
  | ASYNC
  {
    $$ = new TypeSpecifierNode(Type::ASYNC);
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
  | direct_declarator '[' constant_expression ']'
  {
    // Todo : Only 1-dimensional array is allowed
    $$ = $1;
    $1->array_constant = static_cast<ConstantExpressionNode*>($3);
  }
  ;

type_name
  : type_specifier abstract_declarator
  {
    $$ = new TypeNameNode(
        static_cast<TypeSpecifierNode*>($1),
        static_cast<AbstractDeclaratorNode*>($2));
  }
  ;

abstract_declarator
  : direct_abstract_declarator
  {
    $$ = new AbstractDeclaratorNode(
      static_cast<DirectAbstractDeclaratorNode*>($1));
  }
  ;

direct_abstract_declarator
  :
  {
    $$ = new DirectAbstractDeclaratorNode();
  }
  ;

constant_expression
  : CONSTANT
  {
    $$ = new ConstantExpressionNode(yylval.num);
  }

initializer
  : assignment_expression
  {
    $$ = new InitializerNode($1);
  }
  ;

statement
  : compound_statement { $$ = $1; }
  | iteration_statement { $$ = $1; }
  | for_statement { $$ = $1; }
  | selection_statement { $$ = $1; }
  | return_statement { $$ = $1; }
  | print_statement { $$ = $1; }
  | expression_statement { $$ = $1; }
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
    $$ = new FunctionDefinitionNode($1, $2, $4, static_cast<CompoundStatementNode*>($6));
  }
  | type_specifier declarator '(' ')' compound_statement
  {
    $$ = new FunctionDefinitionNode($1, $2, nullptr, static_cast<CompoundStatementNode*>($5));
  }
  ;

parameter_declaration_list
  : parameter_declaration
  {
    $$ = $1;
  }
  | parameter_declaration ',' parameter_declaration_list
  {
    $1->next = $3;
    $$ = $1;
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
  | statement
  {
    $$ = $1;
  }
  | declaration compound_statement_body
  {
    $1->next = $2;
    $$ = $1;
  }
  | statement compound_statement_body
  {
    $1->next = $2;
    $$ = $1;
  }
  ;

selection_statement
  : IF '(' expression ')' statement
  {
    $$ = new SelectionStatementNode($3, $5);
  }
  | IF '(' expression ')' statement ELSE statement {
    $$ = new SelectionStatementNode($3, $5, $7);
  }
  ;

iteration_statement
  : WHILE '(' expression ')' statement
  {
    $$ = new IterationStatementNode($3, $5);
  }

for_statement
  : FOR '(' declaration expression_statement expression ')' statement
  { $$ = new ForStatementNode($3, $4, $5, $7); }
  ;

return_statement
  : RETURN expression ';'
  {
    $$ = new ReturnStatementNode($2);
  }
  | RETURN ';'
  {
    $$ = new ReturnStatementNode();
  }
  ;

print_statement
  : PRINT expression ';'
  {
    $$ = new PrintStatementNode($2);
  }

external_declaration 
  : declaration
  {
    $1->Print();
    visitor->Visit($1);
    symbol_table->PrintCode();
  }
  | function_definition
  {
    $1->Print();
    visitor->Visit($1);
    symbol_table->PrintCode();
  }
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
