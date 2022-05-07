CC = gcc
OBJECT = main.o ast.o grammar.o define.o
CPP = main.cpp ast.cpp grammar.cpp define.cpp


build:
	@echo "Building..."
	bison -d -o grammar.cpp grammar.y
	flex -o define.cpp define.l
	$(CC) $(CPP) -o main