#ifndef AST_H_
#define AST_H_

extern int indent_count;
extern void indent();
extern void ii();
extern void di();
extern void init_ast();

extern int global_id;

#define assert_type(TYPE_VALUE, TYPE) \
  if ((TYPE_VALUE)->type() != TYPE) { \
    cout << "Type assertion failed! expected => " << \
      TypeToString((TYPE_VALUE)->type()) << ", got => " \
      << TypeToString(TYPE); \
    assert(false); \
  }

#endif