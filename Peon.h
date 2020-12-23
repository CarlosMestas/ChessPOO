#ifndef PEON_H
#define PEON_H

#include "Pieza.h"
class Peon: public Pieza
{
public:
    Peon(QString team,QGraphicsItem *parent = nullptr);
    //Agregar imagenes
    void setImagen();
    //Agregar movimientos
    void movimientos();
};

#endif // PEON_H
