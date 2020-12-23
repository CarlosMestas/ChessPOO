#ifndef TORRE_H
#define TORRE_H

#include "Pieza.h"
class Torre: public Pieza
{
public:
    Torre(QString team,QGraphicsItem *parent = nullptr);
    //Agregar imagenes
    void setImagen();
    //Agregar movimientos
    void movimientos();
};

#endif // TORRE_H
