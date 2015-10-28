#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include <QString>
#include <QGridLayout>
#include <QLabel>
#include "SudokuCell.h"
#include "SudokuGrid.h"
#include "widgets/SudokuCellWidget.h"

int main(int argc, char *argv[])
{
    SudokuGrid grid;
    QTextStream cout(stdout);
    cout << grid.getQtGridString()<< endl;
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->setGeometry(200,200,500,500);
    window->setStyleSheet("QWidget{background-color:'black';}");
    window->setWindowTitle("Sudoku Game");
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setHorizontalSpacing(1);
    gridLayout->setVerticalSpacing(1);
    for (int i  = 0;i<9;i++){
        for (int r =0;r<9;r++){
    SudokuCellWidget *label = new SudokuCellWidget(NULL);
    label->setNum(i);

    label->setBackgroundColor("white");
    gridLayout->addWidget(label,r,i);
    }
    }
    window->setLayout(gridLayout);

    window->show();
    return app.exec();
}
