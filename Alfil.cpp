#include "Alfil.h"


Alfil::Alfil(QString team, QGraphicsItem *parent):Pieza(team,parent)
{
    setImagen();
}

void Alfil::setImagen()
{
    if(Equipo=="blancas"){
        this->setPixmap(QPixmap(":/ima/Imagenes/alfilblanco.png"));
    }else{
        this->setPixmap(QPixmap(":/ima/Imagenes/alfilnegro.png"));
    }
}

void Alfil::movimientos()
{

}
