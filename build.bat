echo off
set arg1=%1
shift
del lex.exe
del lex.yy.c
del yacc.tab.c
del yacc.tab.h
bison -d yacc.y
flex lex.l
g++ -I. ast/ast.cc ^
        ast/expression/expression.cpp ^
        ast/statement/statement.cpp ^
        ast/parser/visitor.cpp ^
        ast/type/type.cc ^
        lex.yy.c yacc.tab.c ^
        -L %arg1% -o lex -lfl
lex.exe