#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include "SudokuCell.h"
#include "SudokuGrid.h"
#include <QString>
int main(int argc, char *argv[])
{
    SudokuGrid grid;
    QTextStream cout(stdout);
    cout << grid.getQtGridString()<< endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
