#include "GameScreen.h"

GameScreen::GameScreen()
{
}

QWidget* GameScreen::makeGridWidget(std::string importKey){
    QWidget* widget = new QWidget;
    QGridLayout* layout = new QGridLayout;

   QGridLayout* cellLayout = new QGridLayout;
       layout->addItem(cellLayout,0,1);
    return widget;

}
