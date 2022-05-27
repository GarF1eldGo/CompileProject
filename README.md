# CompileProject
使用的文法规则为：[Grammar.txt](https://github.com/GarF1eldGo/CompileProject/blob/main/grammar.txt)<br/>
该文法规则主要参考了[ANSI C Yacc grammar](https://www.lysator.liu.se/c/ANSI-C-grammar-y.html)
<br/><br/><br/>


# How to build up
1.在项目的根目录输入下列指令：
```
cmake
```
</br>

2.cmake成功后，输入下列指令：
```
cmake --build
```
</br>

3.上述指令成功后，会在`src`目录下生成`Mini-C-Compiler`，为了生成IR，可以输入下列指令：
```
./src/Mini-C-Compiler < ./src/test.c > ./src/main.ll
```
该指令的作用是将`./src/test.c`作为输入代码传递给`Mini-C-Compiler`,然后将`Mini-C-Compiler`的输出放入`./src/main.ll`文件中，该文件中存储了IR信息。</br></br>
4.将IR转换为Bytecode，可以输入下列指令：
```
llvm-as -o ./src/main ./src/main.ll
```
</br>

5.将Bytecode转换为汇编代码，可以输入下列指令：
```
llc ./src/main -o ./test/main.s
```
</br>

6.将汇编转换为exe，可以输入下列指令：
```
g++ ./test/main.s -o ./test/main.exe
```
这样就可以运行`main.exe`了。
</br>





