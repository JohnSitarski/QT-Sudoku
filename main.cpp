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
    // QSS borders
    std::string LEFT  = "border-left : 2px solid black; ",RIGHT = "border-right : 2px solid black; ",

            BOTTOM="border-bottom : 2px solid black; ",TOP="border-top : 2px solid black; ";
    QTextStream cout(stdout);
    std::map<int,std::string> borderMap;
    int topBorders[18] = {27,28,29,30,31,32,33,34,35,54,55,56,57,58,59,60,61,62};


    for (int index = 0;index<18;index++){
        std::map<int,std::string>::const_iterator it = borderMap.find(topBorders[index]);
        if (it == borderMap.end()){
            borderMap.insert(std::pair<int,std::string>(topBorders[index],TOP));
        }
    }

    int rightBorders[18] = {2,11,20,5,14,23,29,38,47,56,
                            65,74,32,41,50,59,68,77};

    for (int index = 0;index<18;index++){
        std::map<int,std::string>::const_iterator it = borderMap.find(rightBorders[index]);
        if (it == borderMap.end()){
            borderMap.insert(std::pair<int,std::string>(rightBorders[index],RIGHT));
        }else{
            std::string border = it->second+RIGHT;
            borderMap.at(rightBorders[index]) = border;
        }
    }


    int bottomBorders[18] = {18,19,20,21,22,23,24,25,26,45,46,47,48,49,50,51,52,53};

    for (int index = 0;index<18;index++){
        std::map<int,std::string>::const_iterator it = borderMap.find(bottomBorders[index]);
        if (it == borderMap.end()){
            borderMap.insert(std::pair<int,std::string>(bottomBorders[index],BOTTOM));
        }else{
            std::string border = it->second+BOTTOM;
            borderMap.at(bottomBorders[index]) = border;
        }
    }


    int leftBorders[18] = {3,12,21,30,39,48,57,66,75,6,15,24,33,42,51,60,69,78};

    for (int index = 0;index<18;index++){
        std::map<int,std::string>::const_iterator it = borderMap.find(leftBorders[index]);
        if (it == borderMap.end()){
            borderMap.insert(std::pair<int,std::string>(leftBorders[index],LEFT));
        }else{
            std::string border = it->second+LEFT;

            borderMap.at(leftBorders[index]) = border;
        }
    }





    SudokuGrid grid;

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
        SudokuCellWidget *label = new SudokuCellWidget(i,&grid);
     //   label->setNum(i);
        label->setBackgroundColor("white");
        gridLayout->addWidget(label,location[0],location[1]);

        std::map<int,std::string>::iterator it;
        it = borderMap.find(i);
        if (it != borderMap.end()){
            cout << "SETTING BORDER: " << i << "   " << QString::fromStdString(borderMap.at(i)) << endl;
            label->setBorder(borderMap.at(i));
        }
    }

    window->setLayout(gridLayout);

    window->show();
    return app.exec();
}
