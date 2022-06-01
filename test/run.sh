#!/bin/bash
cd ../ && make
cd test
../src/Mini-C-Compiler < $1/main.c > $1/main.ll
llvm-as-13 -o $1/main.bc $1/main.ll
opt-13 -enable-new-pm=0 -load ../src/DeadBlock/deadblock.so --deadblock < $1/main.bc > $1/main-optimized-branch.bc 
opt-13 -enable-new-pm=0 -load ../src/Obfuscate/obfuscate.so --obfstr < $1/main.bc > $1/main-obfuscate.bc 
llvm-dis-13 $1/main-optimized-branch.bc -o $1/main-optimized-branch.ll
llvm-dis-13 $1/main-obfuscate.bc -o $1/main-obfuscate.ll
llc-13 $1/main.bc -relocation-model=pic -o $1/main.s
llc-13 $1/main-optimized-branch.bc -relocation-model=pic -o $1/main-optimized-branch.s
llc-13 $1/main-obfuscate.bc -relocation-model=pic -o $1/main-obfuscate.s
g++ $1/main.s -o $1/main
g++ $1/main-optimized-branch.s -o $1/main-optimized-branch
llvm-link-13 ../lib/encrypt.ll $1/main-obfuscate.bc  -o $1/main-obfuscate-linked.bc 
clang $1/main-obfuscate-linked.bc  -g -o $1/main-obfuscate-linked
