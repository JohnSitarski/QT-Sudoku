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
    SudokuCell.cpp \
    SudokuGrid.cpp \
    SudokuMove.cpp \
    utils/Tokenizer.cpp \
    widgets/SudokuCellWidget.cpp \
    utils/qssgenerator.cpp \
    widgets/SudokuBoard.cpp \
    widgets/QStateButton.cpp

HEADERS  += \
    SudokuCell.h \
    SudokuGrid.h \
    SudokuMove.h \
    utils/Tokenizer.h \
    widgets/SudokuCellWidget.h \
    utils/qssgenerator.h \
    widgets/SudokuBoard.h \
    widgets/QStateButton.h

FORMS    += mainwindow.ui

CONFIG +=console
