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
    filePath = QFileDialog::getOpenFileName(this,tr("Select Saved Game"),QDir::homePath(),fileFilter);
    if (filePath.length()>0){
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
         std::string readIn ;
        for (int i = 0;i<2;i++) {
            QString line = in.readLine();

            std::string readIn = line.toUtf8().constData();
        }

        //screenPointer->importGrid(readIn);
    }
}
