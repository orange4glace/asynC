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
        lex.yy.c yacc.tab.c ^
        -L D:\cpplib\GnuWin32\lib -o lex -lfl
lex.exe