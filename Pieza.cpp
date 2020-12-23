#include "Pieza.h"
#include "Game.h"

#include <iostream>
/*Pieza::Pieza()
{

}*/
extern Game* game;
Pieza::Pieza(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    //blancas o negras
    Equipo=team;
    //
    EstaEnCasilla=true;
    //ENroque, peon 2 casillas.
    PrimerMovimiento=true;

}

void Pieza::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Seleccionar Pieza
    if(!game->PiezaAMover){
        game->PiezaAMover=this;
        game->PiezaAMover->GetCasillaActual()->SetColor(Qt::red);
        game->PiezaAMover->movimientos();
        std::cout<<"dsf";
    }


}

void Pieza::SetCasillaActual(Casilla *casilla)
{
    CasillaActual = casilla;
}

Casilla *Pieza::GetCasillaActual()
{
    return CasillaActual;
}
