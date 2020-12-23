#include "Casilla.h"


Casilla::Casilla(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    //Creando la casilla 100x100 sin pieza
    this->setRect(0,0,100,100);
    this->SetHasPieza(false);
    //Para pintar toda la casilla
    pincel.setStyle(Qt::SolidPattern);
    //Color inicial ninguno
    this->SetColor("NONE");
    //La Pieza actual que contiene a la casilla, ninguno
    PiezaActual=nullptr;

}
Casilla::~Casilla()
{
    delete this;
}

void Casilla::SetColor(QColor color)
{
    pincel.setColor(color);
    this->setBrush(pincel);
   /* brush.setColor(color);
    this->setBrush()*/
}

void Casilla::setPieza(Pieza* pieza)
{
    //Ubicacion de la pieza respecto al padre (Casilla)

    pieza->setPos(x()+50-pieza->pixmap().width()/2,y()+50-pieza->pixmap().width()/2);
    //pieza->setPos(100,100);
    pieza->SetCasillaActual(this);

   // this->SetHasPieza(true,pieza);
    PiezaActual=pieza;
}

void Casilla::SetHasPieza(bool valor, Pieza *pieza)
{

}

void Casilla::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

bool Casilla::GetTienePieza()
{
 return true;
}
