#include "Casilla.h"
#include "Game.h"
#include <QDebug>
#include "Rey.h"
#include <iostream>
#include "Pieza.h"
#include "Peon.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Rey.h"
#include "Torre.h"
#include "Dama.h"
#include <QMessageBox>

extern Game *game;
Casilla::Casilla(QGraphicsItem *parent):QGraphicsRectItem(parent)
{

    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);//
    setZValue(-1);//
    setHasPieza(false);
    setPiezaColor("NONE");
    currentPiece = nullptr;
}

Casilla::~Casilla()
{
    delete this;
}

void Casilla::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

        //Deseleccion
        if(currentPiece == game->pieceToMove && currentPiece){

            currentPiece->mousePressEvent(event);
            return;
        }

        //Si esta seleccionado
        if(game->pieceToMove){

            //Si es del mismo equipo
            if(this->getPiezaColor() == game->pieceToMove->getSide())
                return;
            //Remover pieza consumida
            QList <Casilla *> movLoc = game->pieceToMove->moveLocation();
            //Asegurarse de que se puede mover
            int check = 0;
            for(size_t i = 0, n = static_cast<size_t>(movLoc.size()); i < n;i++) {
                if(movLoc[static_cast<int>(i)] == this) {
                    check++;

                }
            }
            // Si no esta entonces 0
            if(check == 0)
                return;
            //Cambiar color a por deceto
             game->pieceToMove->decolor();
             //Para cambiar el primer movimiento a false, con true se puede
             //moverse 2 veces el peon o hacer enroque
             game->pieceToMove->firstMove = false;
             //Si se consume una pieza
            if(this->getHasPieza()){
                this->currentPiece->setIsPlaced(false);
                this->currentPiece->setCurrentBox(nullptr);
                game->placeInDeadPlace(this->currentPiece);
                game->isDead=true;
            }


            //Cambiando la posicion y caja del peon
            game->pieceToMove->getCurrentBox()->setHasPieza(false);
            game->pieceToMove->getCurrentBox()->currentPiece = nullptr;
            game->pieceToMove->getCurrentBox()->resetOriginalColor();
            placePiece(game->pieceToMove);

            int ff = game->pieceToMove->getCurrentBox()->colLoc;
            int gg = game->pieceToMove->getCurrentBox()->rowLoc;

           //LOG

            if(game->isDead){

                if(game->pieceToMove->getSide()=="WHITE"){
                    if(typeid(*(game->pieceToMove))==typeid(Caballo)){
                        game->logb=game->logb+game->conversor("Cx",ff,gg,game->contb)+" ";
                    }else if(typeid(*(game->pieceToMove))==typeid(Alfil)){
                        game->logb=game->logb+game->conversor("Ax",ff,gg,game->contb)+" ";
                    }else if(typeid(*(game->pieceToMove))==typeid(Rey)){
                        game->logb=game->logb+game->conversor("Rx",ff,gg,game->contb)+" ";
                    }else if(typeid(*(game->pieceToMove))==typeid(Dama)){
                        game->logb=game->logb+game->conversor("Dx",ff,gg,game->contb)+" ";
                    }else if(typeid(*(game->pieceToMove))==typeid(Torre)){
                        game->logb=game->logb+game->conversor("Tx",ff,gg,game->contb)+" ";
                    }else{
                        game->logb=game->logb+game->conversor("x",ff,gg,game->contb)+" ";

                    }
                    game->logblancas->setPlainText(game->logb);
                    game->contb++;

                }else{
                    if(typeid(*(game->pieceToMove))==typeid(Caballo)){
                        game->logn=game->logn+game->conversor("Cx",ff,gg,game->contn)+" ";
                    }else if(typeid(*(game->pieceToMove))==typeid(Alfil)){
                        game->logn=game->logn+game->conversor("Ax",ff,gg,game->contn)+" ";
                    }else if(typeid(*(game->pieceToMove))==typeid(Rey)){
                        game->logn=game->logn+game->conversor("Rx",ff,gg,game->contn)+" ";
                    }else if(typeid(*(game->pieceToMove))==typeid(Dama)){
                        game->logn=game->logn+game->conversor("Dx",ff,gg,game->contn)+" ";
                    }else if(typeid(*(game->pieceToMove))==typeid(Torre)){
                        game->logn=game->logn+game->conversor("Tx",ff,gg,game->contn)+" ";
                    }else{
                        game->logn=game->logn+game->conversor("x",ff,gg,game->contn)+" ";
                    }
                    game->lognegras->setPlainText(game->logn);
                    game->contn++;
                }


            }
            else{


            if(game->pieceToMove->getSide()=="WHITE"){
                if(typeid(*(game->pieceToMove))==typeid(Caballo)){
                    game->logb=game->logb+game->conversor("C",ff,gg,game->contb)+" ";
                }else if(typeid(*(game->pieceToMove))==typeid(Alfil)){
                    game->logb=game->logb+game->conversor("A",ff,gg,game->contb)+" ";
                }else if(typeid(*(game->pieceToMove))==typeid(Rey)){
                    game->logb=game->logb+game->conversor("R",ff,gg,game->contb)+" ";
                }else if(typeid(*(game->pieceToMove))==typeid(Dama)){
                    game->logb=game->logb+game->conversor("D",ff,gg,game->contb)+" ";
                }else if(typeid(*(game->pieceToMove))==typeid(Torre)){
                    game->logb=game->logb+game->conversor("T",ff,gg,game->contb)+" ";
                }else{
                    game->logb=game->logb+game->conversor("",ff,gg,game->contb)+" ";

                }
                game->logblancas->setPlainText(game->logb);
                game->contb++;

            }else{
                if(typeid(*(game->pieceToMove))==typeid(Caballo)){
                    game->logn=game->logn+game->conversor("C",ff,gg,game->contn)+" ";
                }else if(typeid(*(game->pieceToMove))==typeid(Alfil)){
                    game->logn=game->logn+game->conversor("A",ff,gg,game->contn)+" ";
                }else if(typeid(*(game->pieceToMove))==typeid(Rey)){
                    game->logn=game->logn+game->conversor("R",ff,gg,game->contn)+" ";
                }else if(typeid(*(game->pieceToMove))==typeid(Dama)){
                    game->logn=game->logn+game->conversor("D",ff,gg,game->contn)+" ";
                }else if(typeid(*(game->pieceToMove))==typeid(Torre)){
                    game->logn=game->logn+game->conversor("T",ff,gg,game->contn)+" ";
                }else{
                    game->logn=game->logn+game->conversor("",ff,gg,game->contn)+" ";
                }
                game->lognegras->setPlainText(game->logn);
                game->contn++;
            }
            }

            game->isDead=false;

            game->pieceToMove = nullptr;
            //
            game->changeTurn();
            checkForCheck();
        }
        //Seleccionar la pieza movida
        else if(this->getHasPieza())
        {
            this->currentPiece->mousePressEvent(event);
        }
}

void Casilla::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

void Casilla::placePiece(Pieza *piece)
{

    piece->setPos(x()+50- piece->pixmap().width()/2  ,y()+50-piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasPieza(true,piece);
    currentPiece = piece;


}

void Casilla::resetOriginalColor()
{
    setColor(originalColor);
}



void Casilla::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}

bool Casilla::getHasPieza()
{
    return hasPieza;
}

void Casilla::setHasPieza(bool value, Pieza *piece)
{
    hasPieza = value;
    if(value)
        setPiezaColor(piece->getSide());
    else
        setPiezaColor("NONE");
}

void Casilla::checkForCheck()
{
    int c = 0;
    QList <Pieza *> pList = game->alivePiece;
    for(size_t i = 0,n=static_cast<size_t>(pList.size()); i < n; i++ ) {

        Rey * p = dynamic_cast<Rey *> (pList[static_cast<int>(i)]);
        if(p){
            continue;
        }
        pList[static_cast<int>(i)]->Movimientos();
        pList[static_cast<int>(i)]->decolor();
        QList <Casilla *> bList = pList[static_cast<int>(i)]->moveLocation();
        for(size_t j = 0,n = static_cast<size_t>(bList.size()); j < n; j ++) {
            Rey * p = dynamic_cast<Rey *> (bList[static_cast<int>(j)]->currentPiece);
            if(p) {
                if(p->getSide() == pList[static_cast<int>(i)]->getSide())
                    continue;
                bList[static_cast<int>(j)]->setColor(Qt::blue);
                pList[static_cast<int>(i)]->getCurrentBox()->setColor(Qt::darkRed);
                if(!game->check->isVisible()){

                    game->check->setVisible(true);
                }

                else{
                    bList[static_cast<int>(j)]->resetOriginalColor();
                    pList[static_cast<int>(i)]->getCurrentBox()->resetOriginalColor();
                    game->gameOver();
                }
                c++;

            }
        }


    }
    if(!c){
        game->check->setVisible(false);
        for(size_t i = 0,n=static_cast<size_t>(pList.size()); i < n; i++ )
            pList[static_cast<int>(i)]->getCurrentBox()->resetOriginalColor();
    }
}

QString Casilla::getPiezaColor()
{
    return PiezaColor;
}

void Casilla::setPiezaColor(QString value)
{
    PiezaColor = value;
}
