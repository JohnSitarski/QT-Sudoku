#include "GameMenu.h"

GameMenu::GameMenu(GameScreen* gs)
{

    this->screenPointer = screenPointer;
    QVBoxLayout *layout = new QVBoxLayout;
    QTextEdit* puzzleTextField = new QTextEdit();

    layout->addWidget(puzzleTextField);
    layout->addWidget(importButton);
    this->setLayout(layout);
    QObject::connect(importButton,SIGNAL(clicked()),this,SLOT(onImportClicked()));
}

void GameMenu::onImportClicked(){

}
