#ifndef DAMA_H
#define DAMA_H


#include "Pieza.h"
class Dama:public Pieza
{
public:
    Dama(QString team,QGraphicsItem *parent = nullptr);
    void SetImagen();

    void Movimientos();

};

#endif // DAMA_H
