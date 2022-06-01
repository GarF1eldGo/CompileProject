CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

PROJECT(Mini-C-Compiler)

INCLUDE_DIRECTORIES(
  /usr/include/jsoncpp
  /usr/include/llvm-13
  /usr/include/llvm-c-13
)
find_package(LLVM REQUIRED CONFIG)

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
include_directories(${LLVM_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

ADD_SUBDIRECTORY(src)


