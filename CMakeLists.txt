cmake_minimum_required(VERSION 3.0.0)
project(Ex1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Ex1 
src/main.cpp 
src/Interpreter.cpp 
src/Value.cpp 
src/Div.cpp 
src/Variable.cpp 
src/Plus.cpp 
src/Minus.cpp 
src/Mul.cpp 
src/UMinus.cpp 
src/UPlus.cpp 
src/UnariOperator.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_INCLUDE_PATH ./inc)
include(CPack)
