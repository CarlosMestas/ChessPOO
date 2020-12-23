#include "Alfil.h"
#include <QDebug>
#include "Game.h"
extern Game *game;

Alfil::Alfil(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
}

void Alfil::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/alfilblanco.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/alfilnegro.png"));
}


void Alfil::Movimientos()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSide();


    //Superior izquiero

     for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) {
       if(game->collection[i][j]->getPiezaColor() == team ) {
           break;

       }
       else
       {
           location.append(game->collection[i][j]);
           if(boxSetting(location.last()) ){
               break;
           }
       }
    }

     //Superior derecha

      for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++) {
        if(game->collection[i][j]->getPiezaColor() == team ) {
            break;

        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
     }

      //Inferior derecha

       for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++) {
         if(game->collection[i][j]->getPiezaColor() == team ) {
             break;

         }
         else
         {
             location.append(game->collection[i][j]);
             if(boxSetting(location.last())){
                 break;
             }
         }
      }

       //Inferior izquierda

        for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
          if(game->collection[i][j]->getPiezaColor() == team ) {
              break;

          }
          else
          {
              location.append(game->collection[i][j]);
              if(boxSetting(location.last())){
                  break;
              }

          }
       }

}
