#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include <QWidget>
#include <QStackedLayout>
#include <QGridLayout>

class GameScreen : QWidget
{

    Q_OBJECT

private:
    QStackedLayout *stackedWidget = new QStackedLayout;



    void showMenu();
    void showGame();
public:

    ~GameScreen(){

    }

    GameScreen();



};

#endif // GAMESCREEN_H
