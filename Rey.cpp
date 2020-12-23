#include "Rey.h"
#include "Game.h"
#include "Peon.h"
extern Game *game;
Rey::Rey(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
}

void Rey::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/reyblanco.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/reynegro.png"));
}


void Rey::Movimientos()
{

    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSide();

        if(col > 0 && row > 0 && !(game->collection[row-1][col-1]->getPiezaColor() == team)) {//up left
            location.append(game->collection[row-1][col-1]);
            game->collection[row-1][col-1]->setColor(Qt::darkRed);
            if(location.last()->getHasPieza()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col < 7 && row > 0 && !(game->collection[row-1][col+1]->getPiezaColor() == team)) { // up right
            location.append(game->collection[row-1][col+1]);
            game->collection[row-1][col+1]->setColor(Qt::darkRed);
            if(location.last()->getHasPieza()){
                location.last()->setColor(Qt::red);
            }
        }
        if(row>0 && !(game->collection[row-1][col]->getPiezaColor() == team)) {//up
            location.append(game->collection[row-1][col]);
            game->collection[row-1][col]->setColor(Qt::darkRed);
            if(location.last()->getHasPieza()){
                location.last()->setColor(Qt::red);
            }
        }
        if(row<7 && !(game->collection[row+1][col]->getPiezaColor() == team)) {//down
            location.append(game->collection[row+1][col]);
            game->collection[row+1][col]->setColor(Qt::darkRed);
            if(location.last()->getHasPieza()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col>0 && !(game->collection[row][col-1]->getPiezaColor() == team)) {// left
            location.append(game->collection[row][col-1]);
            game->collection[row][col-1]->setColor(Qt::darkRed);
            if(location.last()->getHasPieza()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col<7 && !(game->collection[row][col+1]->getPiezaColor() == team)) {//right
            location.append(game->collection[row][col+1]);
            game->collection[row][col+1]->setColor(Qt::darkRed);
            if(location.last()->getHasPieza()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col > 0 && row < 7  && !(game->collection[row+1][col-1]->getPiezaColor() == team)) {//down left
            location.append(game->collection[row+1][col-1]);
            game->collection[row+1][col-1]->setColor(Qt::darkRed);
            if(location.last()->getHasPieza()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col < 7 && row < 7 && !(game->collection[row+1][col+1]->getPiezaColor() == team)) {//down right
            location.append(game->collection[row+1][col+1]);
            game->collection[row+1][col+1]->setColor(Qt::darkRed);
            if(location.last()->getHasPieza()){
                location.last()->setColor(Qt::red);
            }
        }


            UbicacionDeRiesgo();


}
//Reconoce lugares no seguros
void Rey::UbicacionDeRiesgo() {
    QList <Pieza *> pList = game->alivePiece;
    for(size_t i = 0,n = static_cast<size_t>(pList.size()); i < n; i++) {

        if(pList[static_cast<int>(i)]->getSide() != this->getSide())
        {
            QList <Casilla *> bList = pList[static_cast<int>(i)]->moveLocation();

            for(size_t j = 0, n = static_cast<size_t>(bList.size()); j < n; j++) {
                Peon *c = dynamic_cast<Peon *> (pList[static_cast<int>(i)]) ;
                if(c)
                    continue;
                for(size_t k = 0, n = static_cast<size_t>(location.size()); k < n; k++) {
                   if(bList[static_cast<int>(j)] == location [static_cast<int>(k)]) {
                       location[static_cast<int>(k)]->setColor(Qt::blue);
                   }
                }
            }
        }
    }
}
