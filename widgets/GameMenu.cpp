#include "GameMenu.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QFont>
GameMenu::GameMenu()
{
    QVBoxLayout *layout = new QVBoxLayout;
    QTextEdit* puzzleTextField = new QTextEdit();
    QPushButton* importButton = new QPushButton("Import",this);
    layout->addWidget(puzzleTextField);
    layout->addWidget(importButton);
    this->setLayout(layout);

}
