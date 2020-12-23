#include "Caballo.h"
#include "Game.h"
extern Game *game;

Caballo::Caballo(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
}

void Caballo::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/caballoblanco.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/caballonegro.png"));
}



void Caballo::Movimientos()
{
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    int i ,j;
    QString team  = this->getSide();

    //8 lugares a los que un caballo se puede mover

    //Superior izquiera
    i = row - 2;
    j = col - 1;
    if(i >=0 && j>=0 && (game->collection[i][j]->getPiezaColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPieza())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //Superior derecha
    i = row - 2;
    j = col + 1;
    if(i >=0 && j<=7 && (game->collection[i][j]->getPiezaColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPieza())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //Inferior izquierda
    i = row + 2;
    j = col - 1;
    if(i <= 7 && j>=0 && (game->collection[i][j]->getPiezaColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPieza())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //Inferior derecha
    i = row + 2;
    j = col + 1;
    if(i <=7 && j<=7 && (game->collection[i][j]->getPiezaColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPieza())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //Superior izquierda
    i = row - 1;
    j = col - 2;
    if(i >=0 && j>=0 && (game->collection[i][j]->getPiezaColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPieza())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //Inferior izquierda
    i = row + 1;
    j = col - 2;
    if(i <=7 && j>=0 && (game->collection[i][j]->getPiezaColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPieza())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //Superior derecha
    i = row - 1;
    j = col + 2;
    if(i >=0 && j<=7 && (game->collection[i][j]->getPiezaColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPieza())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //Inferior derecha
    i = row + 1;
    j = col +  2;
    if(i <=7 && j<=7 && (game->collection[i][j]->getPiezaColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPieza())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }



}


