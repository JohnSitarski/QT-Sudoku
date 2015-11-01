#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include <QWidget>
#include <QStackedLayout>
#include <QGridLayout>
#include "widgets/GameMenu.h"
class GameScreen : QWidget
{

    Q_OBJECT

private:
    QStackedLayout *stackedWidget = new QStackedLayout;

    QWidget* makeGridWidget(std::string importKey);

public:
    ~GameScreen(){

    }

    GameScreen();

};

#endif // GAMESCREEN_H
