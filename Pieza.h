#ifndef PIEZA_H
#define PIEZA_H


#include <QGraphicsPixmapItem>
#include "Casilla.h"
#include <QGraphicsSceneMouseEvent>

class Casilla;
class Pieza:public QGraphicsPixmapItem
{
public:
    //Equipo y padre
    Pieza(QString team = "",QGraphicsItem *parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //Renocer casilla padre
    void setCurrentBox(Casilla *box);
    Casilla *getCurrentBox() ;

    //Reconocer la ubicacion del equipo
    QString getSide() ;
    void setSide( QString value);

    //Si esta en una casilla
    bool getIsPlaced() ;
    void setIsPlaced(bool value);

    QList <Casilla *> moveLocation();

    //Virtual puros, colocar una imagen, y reconocer movimientos
    virtual void Movimientos() = 0;
    virtual void SetImagen() = 0;

    void decolor();

    //Primer movimiento para enroque, y el movimiento de los peones
    bool firstMove;

    bool boxSetting(Casilla *box);
protected:
    //Casilla actual
    Casilla *currentBox;
    //Equipo
    QString side;
    //Si se encuentra en una casilla
    bool isPlaced;
    //Ubicacion
    QList <Casilla *> location;

};

#endif // PIEZA_H
