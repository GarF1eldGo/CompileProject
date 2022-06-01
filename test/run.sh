#!/bin/bash
cd ../ && make
cd test
../src/Mini-C-Compiler < $1/main.c > $1/main.ll
llvm-as-13 -o $1/main.bc $1/main.ll
opt-13 -enable-new-pm=0 -load ../src/DeadBlock/deadblock.so --deadblock < $1/main.bc > $1/main-optimized-branch.bc 
llvm-dis-13 $1/main-optimized-branch.bc -o $1/main-optimized-branch.ll
llc-13 $1/main.bc -relocation-model=pic -o $1/main.s
llc-13 $1/main-optimized-branch.bc -relocation-model=pic -o $1/main-optimized-branch.s
g++ $1/main.s -o $1/main
g++ $1/main-optimized-branch.s -o $1/main-optimized-branch