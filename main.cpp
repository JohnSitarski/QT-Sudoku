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
int main(int argc, char *argv[])
{
    std::string LEFT  = "border-left : 2px solid black;",RIGHT = "border-right : 2px solid black;",BOTTOM="border-bottom : 2px solid black;",TOP="border-top : 2px solid black;";

    std::map<int,std::string> borderMap;
    borderMap.insert(std::pair<int,std::string>(2,RIGHT));
        borderMap.insert(std::pair<int,std::string>(3,LEFT));
    borderMap.insert(std::pair<int,std::string>(11,RIGHT));
     borderMap.insert(std::pair<int,std::string>(18,BOTTOM));
        borderMap.insert(std::pair<int,std::string>(19,BOTTOM));
    borderMap.insert(std::pair<int,std::string>(20,RIGHT+BOTTOM));




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
    for (int i  = 0;i<81;i++){
        int* location = grid.getCellLocation(i);
        SudokuCellWidget *label = new SudokuCellWidget(&grid);
        label->setNum(i);
        label->setBackgroundColor("white");
        gridLayout->addWidget(label,location[0],location[1]);

        std::map<int,std::string>::iterator it;
it = borderMap.find(i);
if (it != borderMap.end()){
    label->setBorder(borderMap.at(i));
}
    }

    window->setLayout(gridLayout);

    window->show();
    return app.exec();
}
