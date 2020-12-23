#ifndef TABLERO_H
#define TABLERO_H

#include <QGraphicsRectItem>
#include "Pieza.h"
class Tablero
{
public:
    Tablero();

    //Dibujar las casillas
    void DibujarCasillas(int x, int y);

    //Colocar las piezas en el tablero
    void ArmarNegras();
    void ArmarBlancas();

    //Agregar piezas
    void addPieza();
    void reset();
private:
    //Lista de piezas negras y piezas blancas
    QList <Pieza *> white;
    QList <Pieza *> black;



};
#endif // TABLERO_H
