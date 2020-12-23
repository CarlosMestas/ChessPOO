#ifndef REY_H
#define REY_H


#include "Pieza.h"
class Rey:public Pieza
{
public:
    Rey(QString team,QGraphicsItem *parent = nullptr);
    void SetImagen();
    void UbicacionDeRiesgo();
    void Movimientos();

};

#endif // REY_H
