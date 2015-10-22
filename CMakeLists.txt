cmake_minimum_required(VERSION 3.2)
project(Sudoku)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Sudoku ${SOURCE_FILES} sudoku/SudokuGrid.h sudoku/SudokuGrid.cpp sudoku/SudokuCell.h sudoku/SudokuCell.cpp sudoku/SudokuMove.h sudoku/SudokuMove.cpp sudoku/utils/Tokenizer.h sudoku/utils/Tokenizer.cpp)