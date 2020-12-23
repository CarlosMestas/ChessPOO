#include "Torre.h"


Torre::Torre(QString team, QGraphicsItem *parent) : Pieza(team,parent)
{
    setImagen();
}

void Torre::setImagen()
{
    if(Equipo=="blancas"){
        this->setPixmap(QPixmap(":/ima/Imagenes/torreblanco.png"));
    }else{
        this->setPixmap(QPixmap(":/ima/Imagenes/torrenegra.png"));
    }
}

void Torre::movimientos()
{

}
