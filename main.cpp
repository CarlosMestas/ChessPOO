#include <iostream>
#include "Game.h"
#include <QApplication>
using namespace std;

Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game=new Game();
    game->show();
    game->DibujarTablero();
    game->DibujarLetrasYNumeros();


    return a.exec();
}
