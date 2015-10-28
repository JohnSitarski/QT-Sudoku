#-------------------------------------------------
#
# Project created by QtCreator 2015-10-27T15:42:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SudokuAssignment2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    SudokuCell.cpp \
    SudokuGrid.cpp \
    SudokuMove.cpp \
    utils/Tokenizer.cpp

HEADERS  += mainwindow.h \
    SudokuCell.h \
    SudokuGrid.h \
    SudokuMove.h \
    utils/Tokenizer.h

FORMS    += mainwindow.ui

CONFIG +=console
