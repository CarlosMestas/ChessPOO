#ifndef TABLERO_H
#define TABLERO_H

#include <QGraphicsRectItem>
#include "Pieza.h"



class Tablero
{
public:
    //Constructor, item padre
    Tablero();
    void DibujarCasillas(int x,int y);

    //Añadir al arreglo de piezas
    void ArmarBlancas();
    void ArmarNegras();

    //Agrega piezas al tablero
    void AgregarPiezas();
private:

    //Piezas
    QList <Pieza *> blancas;
    QList <Pieza *> negras;

};

#endif // TABLERO_H
