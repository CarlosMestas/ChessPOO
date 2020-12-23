#ifndef ALFIL_H
#define ALFIL_H


#include "Pieza.h"

class Alfil:public Pieza
{
public:
    //Equipo, item padre
    Alfil(QString team,QGraphicsItem *parent = nullptr);


    //Imagen y Movimientos
    void SetImagen();

    void Movimientos();

};

#endif // ALFIL_H
