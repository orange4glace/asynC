del lex.exe
del lex.yy.c
del yacc.tab.c
del yacc.tab.h
bison -d yacc.y
flex lex.l
g++ lex.yy.c yacc.tab.c ast/ast.cc -L C:/cpp-dev/lib -o lex -lfl
lex.exe