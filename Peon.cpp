#include "Peon.h"



Peon::Peon(QString team, QGraphicsItem *parent):Pieza(team,parent)
{
    setImagen();
}

void Peon::setImagen()
{
    if(Equipo=="blancas"){
        this->setPixmap(QPixmap(":/ima/Imagenes/peonblanco.png"));
    }else{
        this->setPixmap(QPixmap(":/ima/Imagenes/peonnegro.png"));
    }
}

void Peon::movimientos()
{

}
