#ifndef DAMA_H
#define DAMA_H

#include "Pieza.h"

class Dama: public Pieza
{
public:
    Dama(QString team,QGraphicsItem *parent = nullptr);
    //Agregar imagenes
    void setImagen();
    //Agregar movimientos
    void movimientos();
};

#endif // DAMA_H
