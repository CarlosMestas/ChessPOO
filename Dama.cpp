#include "Dama.h"
#include "Game.h"
extern Game *game;
Dama::Dama(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
}

void Dama::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/damablanca.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/damanegra.png"));
}


void Dama::Movimientos()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSide();
    //arriba

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

     //abajo

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

      //izquierda

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
       //derecha

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

        //superior izquierda

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

         //superior derecha

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

          //inferior derecha

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

           //inferior izquierda

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
