#include "Peon.h"
#include "Game.h"
#include <QDebug>
#include <typeinfo>
#include "Rey.h"
#include "Dama.h"
extern Game * game;
Peon::Peon(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
    firstMove = true;
}

void Peon::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/peonblanco.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/peonnegro.png"));
}



void Peon::Movimientos()
{
    location.clear();

    int row = this->getCurrentBox()->rowLoc;

    int col = this->getCurrentBox()->colLoc;
    if(this->getSide() == "WHITE")  {


        if(col > 0 && row > 0 && game->collection[row-1][col-1]->getPiezaColor() == "BLACK") {
            location.append(game->collection[row-1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row > 0 && game->collection[row-1][col+1]->getPiezaColor() == "BLACK") {
            location.append(game->collection[row-1][col+1]);
            boxSetting(location.last());
        }
        if(row>0 && (!game->collection[row-1][col]->getHasPieza())) {
            location.append(game->collection[row-1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row-2][col]->getHasPieza()){
                location.append(game->collection[row-2][col]);
                boxSetting(location.last());
            }
        }

    }
    else{
        if(col > 0 && row < 7 && game->collection[row+1][col-1]->getPiezaColor() == "WHITE") {//left
            location.append(game->collection[row+1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row <  7 && game->collection[row+1][col+1]->getPiezaColor() == "WHITE") {//right
            location.append(game->collection[row+1][col+1]);
            boxSetting(location.last());
        }
        if(row<7 && (!game->collection[row+1][col]->getHasPieza())) {
            location.append(game->collection[row+1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row+2][col]->getHasPieza()){
                location.append(game->collection[row+2][col]);
                boxSetting(location.last());
            }

        }

    }

}


