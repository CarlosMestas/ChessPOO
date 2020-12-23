#include "Rey.h"

Rey::Rey(QString team, QGraphicsItem *parent):Pieza(team,parent)
{
    setImagen();
}

void Rey::setImagen()
{
    if(Equipo=="blancas"){
        this->setPixmap(QPixmap(":/ima/Imagenes/reyblanco.png"));
    }else{
        this->setPixmap(QPixmap(":/ima/Imagenes/reynegro.png"));
    }
}

void Rey::movimientos()
{

}
