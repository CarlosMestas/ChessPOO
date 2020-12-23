#include "Game.h"

Game::Game(QWidget *parent):QGraphicsView(parent)
{
    //Crear escena
    gameScene = new QGraphicsScene();
    //Tamaño de la escena
    gameScene->setSceneRect(0,0,1400,850);
    //Tamaño de la vista
    this->setFixedSize(1400,850);
    //Anular scroll vertical y horizontal
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //Agregar la escena a la vista
    this->setScene(gameScene);

    PiezaAMover=nullptr;




}
void Game::DibujarTablero()
{
       tablero = new Tablero();

       //Posicion del tablero 300,25
       tablero->DibujarCasillas(300,25);
       tablero->AgregarPiezas();

}

void Game::DibujarLetrasYNumeros()
{

    //int DistanciaCasilla=100;
    QString f[8] = {"A","B","C","D","E","F","G","H"};
    QString g[8] = {"1","2","3","4","5","6","7","8"};
    for(int i=0; i<8; ++i){

           QGraphicsTextItem *text = new QGraphicsTextItem();
           text->setDefaultTextColor(Qt::black);
           text->setFont(QFont("",18));
           text->setPlainText(g[i]);
           text->setPos(275,60+i*100);
           AgregarItem(text);

    }
    for(int i=0; i<8; ++i){

           QGraphicsTextItem *text = new QGraphicsTextItem();
           text->setDefaultTextColor(Qt::black);
           text->setFont(QFont("",18));
           text->setPlainText(g[i]);
           text->setPos(1105,60+i*100);
           AgregarItem(text);

    }
    for(int i=0; i<8; ++i){

           QGraphicsTextItem *text = new QGraphicsTextItem();
           text->setDefaultTextColor(Qt::black);
           text->setFont(QFont("",18));
           text->setPlainText(f[i]);
           text->setPos(335+i*100,-5);
           AgregarItem(text);

    }
    for(int i=0; i<8; ++i){

           QGraphicsTextItem *text = new QGraphicsTextItem();
           text->setDefaultTextColor(Qt::black);
           text->setFont(QFont("",18));
           text->setPlainText(f[i]);
           text->setPos(335+i*100,820);
           AgregarItem(text);

    }
}

//Agregar items al escenario
void Game::AgregarItem(QGraphicsItem *item)
{
    this->gameScene->addItem(item);
}
