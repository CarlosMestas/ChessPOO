#ifndef PIEZA_H
#define PIEZA_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

#include "Casilla.h"

class Casilla;
class Pieza :public QGraphicsPixmapItem
{
public:
    //Constructor, Nombre del Equipo y el item padre.
    Pieza(QString team = "",QGraphicsItem *parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    virtual void movimientos() = 0;
    virtual void setImagen() = 0;

    void SetCasillaActual(Casilla* casilla);
    Casilla* GetCasillaActual();


    bool PrimerMovimiento;

protected:
    Casilla* CasillaActual;
    QString Equipo;
    bool EstaEnCasilla;



};

#endif // PIEZA_H
