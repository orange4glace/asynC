# Build instructions

## Prerequisite
- Windows 7+
- g++
- flex & bison

## To build
$./build.bat (flex&bison library path)

ex) ./build.bat d:/cpplib/GnuWin32/lib

# Run

$./lex.exe
$(Input your code)

# Run a generated code on VM

## Prerequisite

- [TinyVM for asynC](https://github.com/orange4glace/tinyvm)

## To run
$./tinyvm.exe (your code)