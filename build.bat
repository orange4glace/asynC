del lex.exe
del lex.yy.c
del yacc.tab.c
del yacc.tab.h
bison -d yacc.y
flex lex.l
g++ -I. lex.yy.c yacc.tab.c ast/ast.cc -L D:\cpplib\GnuWin32\lib -o lex -lfl
lex.exe