#include "Caballo.h"

Caballo::Caballo(QString team, QGraphicsItem *parent):Pieza(team,parent)
{
    setImagen();
}

void Caballo::setImagen()
{
    if(Equipo=="blancas"){
        this->setPixmap(QPixmap(":/ima/Imagenes/caballoblanco.png"));
    }else{
        this->setPixmap(QPixmap(":/ima/Imagenes/caballonegro.png"));
    }
}

void Caballo::movimientos()
{

}

