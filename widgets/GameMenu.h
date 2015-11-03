#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QFont>
#include <QFileDialog>
#include "widgets/GameScreen.h"
#include <QTextStream>

class GameMenu : public QWidget
{
    Q_OBJECT
private:
        QString filePath;
        QString fileFilter = "Text file (*.txt)";
        QPushButton* importButton = new QPushButton("Import Game",this);
        GameScreen* screenPointer;
public:

    ~GameMenu(){

    }


    GameMenu(GameScreen* screenPointer);





public slots:
    void onImportClicked();

};

#endif // GAMEMENU_H
