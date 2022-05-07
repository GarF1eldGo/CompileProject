CC = g++
OBJECT = main.o ast.o grammar.o define.o
CPP = main.cpp ast.cpp grammar.cpp


# build:
# 	@echo "Building..."
# 	bison -d -o grammar.cpp grammar.y
# 	flex -o define.cpp define.l
# 	$(CC) $(CPP) -o main


tempTest:
	bison -d -o grammar.cpp grammar.y
	flex -o define.cpp define.l
	g++ ast.cpp grammar.cpp main.cpp -o yaccTest