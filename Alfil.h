#ifndef ALFIL_H
#define ALFIL_H
#include "Pieza.h"

class Alfil : public Pieza
{
public:
    //Constructor de Pieza
    Alfil(QString team,QGraphicsItem *parent = nullptr);
    //Agregar imagenes
    void setImagen();
    //Agregar movimientos
    void movimientos();
};

#endif // ALFIL_H
