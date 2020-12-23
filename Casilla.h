#ifndef CASILLA_H
#define CASILLA_H

#include "Pieza.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>


class Pieza;
class Casilla : public QGraphicsRectItem
{
public:
    //constructor, item pariente
    Casilla(QGraphicsItem *parent=nullptr);
    ~Casilla();

    //Poner color
    void SetColor(QColor color);
    //Coloca Pieza
    void setPieza(Pieza* pieza);

    void SetHasPieza(bool valor, Pieza* pieza=nullptr);


    //Mouse Press Casilla
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //Verificar si tiene Pieza
    bool GetTienePieza();

    //Pieza que contiene esta casilla
    Pieza* PiezaActual;

    //Ubicacion de la casilla
    int Fila;
    int Columna;

private:
    //Para pintar la casilla
    QBrush pincel;
    //Verificar contenido de la pieza
    bool TienePieza;
};

#endif // CASILLA_H
