#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "Tablero.h"

class Game : public QGraphicsView
{
public:
    //constructor, widget parent
    Game(QWidget *parent = nullptr);
    void DibujarTablero();
    void DibujarLetrasYNumeros();

    //Agrega items a la escena
    void AgregarItem(QGraphicsItem *item);

    Pieza* PiezaAMover;

    Casilla* ColeccionCasillas[8][8];

    QList <Pieza *> PiezasVivas;

private:

    QGraphicsScene *gameScene;
    Tablero* tablero;

};

#endif // GAME_H
