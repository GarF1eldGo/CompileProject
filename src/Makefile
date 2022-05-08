cc = g++ -std=c++11
cpp = main.cpp ast.cpp grammar.cpp

# json 相关库
prefix=/usr/local/Cellar/jsoncpp/1.9.4_1
libdir=${prefix}/lib
includedir=${prefix}/include

libs = -L${libdir} -ljsoncpp
cflags = -I${includedir}


tempTest:
	bison -d -o grammar.cpp grammar.y
	flex -o define.cpp define.l
	${cc} ${libs} ${cflags} ${cpp} -o yaccTest -w 