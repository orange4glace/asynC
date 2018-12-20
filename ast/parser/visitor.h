#ifndef VISITOR_H_
#define VISITOR_H_

#include "ast/ast.h"
#include "ast/parser/symbol_table.h"
#include "ast/statement/statement_include.h"
#include "ast/expression/expression_include.h"
#include "ast/type/type.h"
#include "ast/type/type_value.h"
#include "ast/type/type_value_factory.h"
#include "ast/type/identifier.h"
#include "ast/type/function.h"
#include "ast/type/function_parameter.h"
#include "ast/declaration.h"
#include "ast/declarator.h"
#include "ast/abstract_declarator.h"
#include "ast/direct_declarator.h"
#include "ast/direct_abstract_declarator.h"
#include "ast/identifier.h"
#include "ast/init_declarator.h"
#include "ast/initializer.h"
#include "ast/node.h"
#include "ast/type_specifier.h"
#include "ast/type_name.h"
#include "ast/pointer.h"
#include "ast/function_definition.h"
#include "ast/parameter_declaration.h"
#include "ast/operator.h"

struct Visitor {
  TypeSpecifierNode *type_specifier;

  ExpressionNode *expression;
  Identifier *identifier;
  TypeValue *type_value;
  TypeValue *type_value2;
  StatementNode* statement;

  Visitor() {
    type_specifier = nullptr;
    identifier = nullptr;
    expression = nullptr;
    type_value = nullptr;
  }

  void Visit(DeclarationNode *node) {
    indent();
    cout << "(DeclarationNode)\n";
    ii();
    node->type_specifier->Accept(this);
    node->init_declarator->Accept(this);
    di();
  }

  void Visit(TypeSpecifierNode *node) {
    indent();
    cout << "(TypeSpecifier) " << static_cast<int>(node->type) << "\n";
    ii();
    type_specifier = node;
    type_value = TypeValueFactory::Create(node->type);
    di();
  }

  void Visit(InitDeclaratorNode *node) {
    indent();
    cout << "(InitDeclarator)\n";
    ii();

    node->declarator->Accept(this);
    // Now we have an complete typevalue and identifier
    Identifier *declarator_identifier = identifier;
    TypeValue *declarator_type_value = type_value2;
    // Check is array
    TypeValue *array_constant = type_value;
    if (array_constant) {
      assert(array_constant->type() == Type::INTEGER);
      int size = (static_cast<Integer*>(array_constant))->value;
      declarator_type_value = new Array(declarator_type_value, size);
    }

    // TODO : COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY
    symbol_table->PushStackFrameBack(declarator_type_value);
    if (!node->initializer) {
      symbol_table->AddSymbol(declarator_identifier, declarator_type_value);
      indent();
      cout << "(InitDeclarator) AddSymbol " << declarator_identifier->id << " " << *declarator_type_value << "\n";
      return;
    }
    node->initializer->Accept(this);
    TypeValue* initializer_type_value = type_value;
    type_value = declarator_type_value->ExecuteOperator(Operator::ASSIGNMENT, initializer_type_value);
    symbol_table->AddSymbol(declarator_identifier, type_value);
    indent();
    cout << "(InitDeclarator) AddSymbol " << declarator_identifier->id << " " << *type_value << "\n";
    di();
  }

  void Visit(DeclaratorNode *node) {
    Node *pointer = node->pointer;
    while (pointer) {
      pointer->Accept(this);
      pointer = pointer->next;
    }
    type_value2 = type_value;
    type_value = nullptr;
    node->direct_declarator->Accept(this);
  }

  void Visit(DirectDeclaratorNode *node) {
    node->identifier->Accept(this);
    if (node->array_constant)
      node->array_constant->Accept(this);
  }

  void Visit(AbstractDeclaratorNode *node) {
    Node *pointer = node->pointer;
    while (pointer) {
      pointer->Accept(this);
      pointer = pointer->next;
    }
    type_value2 = type_value;
    type_value = nullptr;
    if (node->direct_abstract_declarator)
      node->direct_abstract_declarator->Accept(this);
  }

  void Visit(PointerNode *node) {
    type_value = new Pointer(type_value);
  }

  void Visit(IdentifierNode *node) {
    indent();
    cout << "(Identifier) " << node->id << "\n";
    identifier = new Identifier(node);
  }

  void Visit(InitializerNode *node) {
    node->expression->Accept(this);
  }

  void Visit(AssignmentExpressionNode *node) {
    indent();
    cout << "(Assignment)\n";
    ii();
    type_value = nullptr;
    if (node->exp) {
      node->exp->Accept(this);
      indent();
      cout << *type_value << endl;
      return;
    }
    node->rhs->Accept(this);
    TypeValue *rhs = type_value;
    node->lhs->Accept(this);
    TypeValue *lhs = type_value;
    lhs->ExecuteOperator(Operator::ASSIGNMENT, rhs);
    type_value = lhs;
    indent();
    cout << *type_value << endl;
    di();
  }

  void Visit(IdentifierExpressionNode *node) {
    node->identifier->Accept(this);
    type_value = symbol_table->GetSymbol(identifier);
    assert_type_value(type_value);
  }
  
  void Visit(ArrayExpressionNode *node) {
    type_value = nullptr;
    node->expression->Accept(this);
    TypeValue *lhs = type_value;
    node->index->Accept(this);
    TypeValue *rhs = type_value;
    type_value = lhs->ExecuteOperator(Operator::SUBSCRIPT, rhs);
  }
  
  void Visit(CastExpressionNode *node) {
    node->type_name->Accept(this);
    TypeValue *cast_type = type_value2;
    node->expression->Accept(this);
    TypeValue *castee = type_value;
    type_value = castee->ExecuteOperator(Operator::CAST, cast_type);
  }
  
  void Visit(TypeNameNode *node) {
    node->type_specifier->Accept(this);
    node->abstract_declarator->Accept(this);
    // result
    // type_value2 : target TypeValue
  }

  void Visit(NewExpressionNode *node) {
    node->type_specifier->Accept(this);
    type_value2 = type_value;
    if (node->abstract_declarator) node->abstract_declarator->Accept(this);
    TypeValue *content = type_value2;
    Pointer *pointer = new Pointer(content);
    pointer->created_by_new = true;
    symbol_table->Malloc();
    symbol_table->PushStackFrameBack(pointer);
    type_value = pointer;
  }

  void Visit(DereferenceExpressionNode *node) {
    node->expression->Accept(this);
    TypeValue *rhs = type_value;
    assert_type(rhs, Type::POINTER);
    Pointer *pointer = static_cast<Pointer*>(rhs);
    TypeValue *dereferenced = pointer->content_type_value->Clone();
    dereferenced->refffffff = true;
    
    symbol_table->AppendInstruction("ss", "push", pointer->GetIndirectAddress());
    dereferenced->local_symbol_table = symbol_table;
    dereferenced->stack_frame_offset = ++symbol_table->stack_frame_size;
    type_value = dereferenced;
  }

  void Visit(BinaryExpressionNode *node) {
    type_value = nullptr;
    node->rhs->Accept(this);
    TypeValue *rhs = type_value;
    node->lhs->Accept(this);
    TypeValue *lhs = type_value;
    type_value = lhs->ExecuteOperator(node->op, rhs);
  }

  void Visit(UnaryExpressionNode *node) {
    type_value = nullptr;
    node->lhs->Accept(this);
    TypeValue *lhs = type_value;
    type_value = lhs->ExecuteOperator(node->op);
  }

  void Visit(ConstantExpressionNode *node) {
    type_value = node->type_value;
    Integer *integer = static_cast<Integer*>(type_value);
    symbol_table->PushStackFrameBack(type_value);
    symbol_table->AppendInstruction("ssd", "mov", "(esp)", integer->value);
  }

  void Visit(AsyncExpressionNode *node) {
    Async *async = new Async();

    symbol_table->PushStackFrameBack(async);
    symbol_table->AppendInstruction("s", "thread");
    symbol_table->AppendInstruction("sss", "mov", async->GetIndirectAddress(), "eax");

    /* push captures */
    Node *vcap = node->variable_capture_list;
    vector<Identifier*> variable_capture_identifier_list;
    while (vcap) {
      vcap->Accept(this);
      async->variable_capture_list.push_back(type_value);
      variable_capture_identifier_list.push_back(identifier);
      symbol_table->AppendInstruction("sss", "pusht", async->GetIndirectAddress(), type_value->GetIndirectAddress());
      vcap = vcap->next;
    }

    symbol_table->AppendInstruction("ssd", "mov", async->GetIndirectAddress(1), root_symbol_table->instruction_size);

    // save current symbol table
    // since async is an isolated scope
    SymbolTable *saved = symbol_table;

    root_symbol_table->Push();
    symbol_table->AppendLabel("s", string("async_start" + std::to_string(node->id) + ":").c_str());

    /* capture symbol table */
    int pdecl_offset = 1;
    for (int i = async->variable_capture_list.size() - 1; i >= 0; i --) {
      Identifier *capture_identifier = variable_capture_identifier_list[i];
      TypeValue *capture_type_value = async->variable_capture_list[i];
      TypeValue *cloned = capture_type_value->Clone();
      cloned->local_symbol_table = symbol_table;
      cloned->stack_frame_offset = -pdecl_offset++;
      symbol_table->AddSymbol(capture_identifier, cloned);
      cout << "[Capture] " << capture_identifier->id << " " << TypeToString(cloned->type()) << endl;
    }

    symbol_table->SaveBasePointer();
    node->compound_statement->Accept(this);
    symbol_table->AppendInstruction("ss", "jmp", "__end");
    symbol_table->Pop();

    symbol_table = saved; // restore

    type_value = async;
  }

  void Visit(FunctionCallExpressionNode *node) {
    node->identifier->Accept(this);
    assert_type(type_value, Type::FUNCTION);
    Function *function = dynamic_cast<Function*>(type_value);
    TypeValue *return_type_value = function->return_type_value->Clone();
    assert(return_type_value);
    vector<TypeValue*> arg_list;
    Node *arg = node->argument_expression_list;
    while (arg) {
      arg->Accept(this);
      arg_list.push_back(type_value);
      arg = arg->next;
    }
    for (auto& arg : arg_list)
      symbol_table->PushStackFrameBack(arg);
    symbol_table->PushStackFrameBack(return_type_value);
    symbol_table->AppendInstruction("ss", "call", function->identifier->id.c_str());
    type_value = return_type_value;
  }

  void Visit(RunStatementNode *node) {
    node->expression->Accept(this);
    assert_type(type_value, Type::ASYNC);
    Async *async = static_cast<Async*>(type_value);
    symbol_table->AppendInstruction("sss", "run", async->GetIndirectAddress(), "# run thread");
  }

  void Visit(JoinStatementNode *node) {
    node->expression->Accept(this);
    assert_type(type_value, Type::ASYNC);
    Async *async = static_cast<Async*>(type_value);
    symbol_table->AppendInstruction("sss", "join", async->GetIndirectAddress(), "# join thread");
  }

  void Visit(FunctionDefinitionNode *node) {
    Function* function = new Function();
    node->type_specifier->Accept(this);
    TypeValue *return_type = function->return_type_value = type_value;
    node->declarator->Accept(this);
    Identifier *function_identifier = function->identifier = identifier;
    Node *pdecl = node->parameter_declaration_list;
    symbol_table->AddSymbol(function_identifier, function);

    // label
    symbol_table->Push("Function " + function_identifier->id);
    symbol_table->AppendLabel("s", string(function_identifier->id + ":").c_str());
    symbol_table->SaveBasePointer();

    // return value
    Identifier *return_identifier = new Identifier("return");
    symbol_table->AddSymbol(return_identifier, return_type);
    return_type->local_symbol_table = symbol_table;
    return_type->stack_frame_offset = -2;
    
    int pdecl_offset = 2;
    // count parameters
    while (pdecl) {
      pdecl = pdecl->next;
      pdecl_offset++;
    }
    pdecl = node->parameter_declaration_list;
    while (pdecl) {
      pdecl->Accept(this);
      Identifier *fn_parameter_identifier = identifier;
      TypeValue *fn_parameter_type_value = type_value2;
      FunctionParameter *fn_parameter =
          new FunctionParameter(fn_parameter_identifier, fn_parameter_type_value);
      fn_parameter_type_value->local_symbol_table = symbol_table;
      fn_parameter_type_value->stack_frame_offset = -pdecl_offset--;
      symbol_table->AddSymbol(fn_parameter_identifier, fn_parameter_type_value);
      function->parameters.push_back(fn_parameter);
      pdecl = pdecl->next;
    }
    
    node->compound_statement->Accept(this);
    CompoundStatementNode *function_compound_statement 
        = static_cast<CompoundStatementNode*>(statement);

    symbol_table->ClearStackFrame();
    symbol_table->RestoreBasePointer();
    symbol_table->Pop();
  }

  void Visit(ParameterDeclarationNode *node) {
    node->type_specifier->Accept(this);
    node->declarator->Accept(this);
  }

  void Visit(ReturnStatementNode *node) {
    if (node->expression) {
      node->expression->Accept(this);
      TypeValue *return_value = type_value;
      TypeValue *return_value_address = symbol_table->GetSymbol(new Identifier("return"));
      assert(return_value_address);
      symbol_table->AppendInstruction("ssss", "mov",
          return_value_address->GetIndirectAddress(), return_value->GetIndirectAddress(),
          "# set return value");
    }
    cout << "Find Function table " << endl;
    SymbolTable *return_symbol_table = symbol_table->GetLocalSymbolTable(new Identifier("return"));
    SymbolTable *target_symbol_table = symbol_table;
    while (target_symbol_table != return_symbol_table) {
      cout << "jump " << endl;
      target_symbol_table->ClearStackFrame();
      target_symbol_table->RestoreBasePointer();
      target_symbol_table = target_symbol_table->parent;
    }
    return_symbol_table->FunctionReturn();
  }

  void Visit(CompoundStatementNode *node) {
    Node *node_list = node->node_list;
    while (node_list) {
      node_list->Accept(this);
      node_list = node_list->next;
    }
  }

  void Visit(IterationStatementNode *node) {
    symbol_table->SaveBasePointer();
    symbol_table->Push("Iteration");
    symbol_table->AppendLabel("ssd", string("loop_start" + std::to_string(node->id) + ":").c_str(), "# while", node->id);
    node->cond->Accept(this);
    symbol_table->AppendInstruction("ssd", "cmp", type_value->GetIndirectAddress(), 0);
    symbol_table->AppendInstruction("ss", "je", string("loop_end" + std::to_string(node->id)).c_str());
    node->stmt->Accept(this);
    symbol_table->ClearStackFrame();
    symbol_table->AppendInstruction("ss", "jmp", string("loop_start" + std::to_string(node->id)).c_str());
    symbol_table->AppendLabel("ssd", string("loop_end" + std::to_string(node->id) + ":").c_str(), "# end of while", node->id);
    symbol_table->RestoreBasePointer();
    symbol_table->Pop();
  }

  void Visit(ForStatementNode *node) {
    symbol_table->SaveBasePointer();
    symbol_table->Push(); // Initiailzer stack frame
    symbol_table->AppendCode("sd", "# for loop initiailzer", node->id);
    if (node->init_expression) node->init_expression->Accept(this);
    if (node->init_declaration) node->init_declaration->Accept(this);

    symbol_table->AppendLabel("ssd", string("loop_start" + std::to_string(node->id) + ":").c_str(), "# for", node->id);
    symbol_table->SaveBasePointer();
    symbol_table->Push(); // condition stack frame
    node->condition->Accept(this);
    symbol_table->AppendInstruction("ssd", "cmp", type_value->GetIndirectAddress(), 0);
    symbol_table->ClearStackFrame(); // clear condition stack frame
    symbol_table->RestoreBasePointer();
    symbol_table->Pop();
    symbol_table->AppendInstruction("ss", "je", string("loop_end" + std::to_string(node->id)).c_str());

    symbol_table->SaveBasePointer();
    symbol_table->Push(); // iterator & statement stack frame
    node->statement->Accept(this);
    node->iterator->Accept(this);
    symbol_table->ClearStackFrame(); // clear iterator & statement
    symbol_table->RestoreBasePointer();
    symbol_table->Pop();
    symbol_table->AppendInstruction("ss", "jmp", string("loop_start" + std::to_string(node->id)).c_str());
    symbol_table->AppendLabel("ssd", string("loop_end" + std::to_string(node->id) + ":").c_str(), "# end of for", node->id);

    symbol_table->ClearStackFrame(); // clear initializer
    symbol_table->RestoreBasePointer();
    symbol_table->Pop();
  }

  void Visit(SelectionStatementNode *node) {
    node->cond->Accept(this);
    symbol_table->AppendInstruction("ssdsd", "cmp", type_value->GetIndirectAddress(), 0, "# if", node->id);
    symbol_table->AppendInstruction("ss", "je", string("else_start" + std::to_string(node->id)).c_str());

    // if
    symbol_table->SaveBasePointer();
    symbol_table->Push("Selection If");
    node->stmt1->Accept(this);
    symbol_table->ClearStackFrame();
    symbol_table->RestoreBasePointer();
    symbol_table->Pop();
    symbol_table->AppendInstruction("ss", "jmp", string("if_end" + std::to_string(node->id)).c_str());
    
    // else
    symbol_table->AppendLabel("s", string("else_start" + std::to_string(node->id) + ":").c_str());
    symbol_table->SaveBasePointer();
    symbol_table->Push("Selection Else");
    if (node->stmt2) node->stmt2->Accept(this);
    symbol_table->ClearStackFrame();
    symbol_table->RestoreBasePointer();
    symbol_table->Pop();
    symbol_table->AppendLabel("ssd", string("if_end" + std::to_string(node->id) + ":").c_str(), "# end of if", node->id);
  }

  void Visit(PrintStatementNode *node) {
    node->expression->Accept(this);
    symbol_table->AppendInstruction("ss", "prn", type_value->GetIndirectAddress());
  }

  void Visit(InputStatementNode *node) {
    node->expression->Accept(this);
    symbol_table->AppendInstruction("ss", "inp", type_value->GetIndirectAddress());
  }

};

extern Visitor *visitor;

#endif