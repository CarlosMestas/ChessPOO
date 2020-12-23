#ifndef BOTON_H
#define BOTON_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>


class Boton:public QObject, public QGraphicsRectItem
{
     Q_OBJECT
public:

    Boton(QString name, QGraphicsItem * parent = nullptr);

    //public methods

    //events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem *text;
};
#endif // BOTON_H
