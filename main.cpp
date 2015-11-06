#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include <QString>
#include <QGridLayout>
#include <QLabel>
#include "SudokuCell.h"
#include "SudokuGrid.h"
#include "widgets/SudokuCellWidget.h"
#include "map"
#include "widgets/GameMenu.h"
#include "widgets/GameScreen.h"
#include "widgets/SudokuBoard.h"

/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/
int main(int argc, char *argv[])
{
    // QSS borders

    QTextStream cout(stdout);

    SudokuGrid grid;

    cout << grid.getQtGridString()<< endl;
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->setGeometry(200,200,500,500);

    window->setWindowTitle("Sudoku Game");
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setHorizontalSpacing(1);
    gridLayout->setVerticalSpacing(1);
    gridLayout->addWidget(new SudokuBoard(),0,0);


    window->setLayout(gridLayout);

    window->show();
    return app.exec();
}
