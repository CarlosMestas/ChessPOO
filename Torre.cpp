#include "Torre.h"
#include "Game.h"

extern Game *game;
Torre::Torre(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
}


void Torre::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/torreblanco.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/torrenegra.png"));
}

void Torre::Movimientos()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSide();
    //Arriba

     for(int i = row-1,j = col; i >= 0 ; i--) {
       if(game->collection[i][j]->getPiezaColor() == team ) {
           break;
       }
       else
       {
           location.append(game->collection[i][j]);
           if(boxSetting(location.last()))
               break;
        }
    }

     //Abajo

      for(int i = row+1,j = col; i <= 7 ; i++) {
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

      //Izquierda

       for(int i = row,j = col-1; j >= 0 ; j--) {
         if(game->collection[i][j]->getPiezaColor() == team ) {
             break;
         }
         else
         {
             location.append(game->collection[i][j]);
             if(boxSetting(location.last()))
                break;
         }
        }
       //Derecha

        for(int i = row,j = col+1; j <= 7 ; j++)
        {
              if(game->collection[i][j]->getPiezaColor() == team ) {
                  break;
              }
              else
              {
                  location.append(game->collection[i][j]);
                  if(boxSetting(location.last()))
                      break;
               }

       }


}


