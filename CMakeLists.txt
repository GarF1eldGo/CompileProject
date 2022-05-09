CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

PROJECT(Mini-C-Compiler)

INCLUDE_DIRECTORIES(
  /usr/include/jsoncpp
  /usr/include/llvm-13
  /usr/include/llvm-c-13
)

SET(CMAKE_EXPORT_COMPILE_COMMANDS 1)
ADD_SUBDIRECTORY(src)

