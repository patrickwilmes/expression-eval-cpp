cmake_minimum_required(VERSION 3.27)
project(expression_eval)

set(CMAKE_CXX_STANDARD 17)

add_executable(expression_eval main.cpp
        Tokenizer.h
        Tokenizer.cpp
        Eval.h
        Eval.cpp)
