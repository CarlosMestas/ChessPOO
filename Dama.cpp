#include "Dama.h"


Dama::Dama(QString team, QGraphicsItem *parent):Pieza(team,parent)
{
    setImagen();
}
void Dama::setImagen()
{
    if(Equipo=="blancas"){
        this->setPixmap(QPixmap(":/ima/Imagenes/damablanca.png"));
    }else{
        this->setPixmap(QPixmap(":/ima/Imagenes/damanegra.png"));
    }
}

void Dama::movimientos()
{

}


