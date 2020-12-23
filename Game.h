#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include "Tablero.h"
#include "Pieza.h"
#include "Tiempo.h"
class Game:public QGraphicsView
{
    Q_OBJECT
public:
    //Padre de la vista
    Game(QWidget *parent = nullptr);


    //Dibujar rectangulos
    //Para la ubicacion de las piezas muertas
    void drawDeadHolder(int x, int y, QColor color);
    //Para la ubicacion de letras y numeros
    void DibujarRectangulos(int x, int y, QColor color);


    void drawTablero();
    //Dibujar las letras y numeros
    void DibujarLetrasYNumeros();
    //Despliega piezas blancas y negras consumidas
    void displayDeadWhite();
    void displayDeadBlack();
    //Coloca una pieza en un lugar consumido
    void placeInDeadPlace(Pieza *piece);

    //Agrega items y remueve items de la escena
    void AgregarItem(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    //Para usar con el mousepress
    Pieza *pieceToMove;

    //El turno (blancas o negrsa)
    QString getTurn() ;
    void setTurn( QString value);
    //cambia el turno de juego
    void changeTurn();


    //arreglo de casillas
    Casilla *collection[8][8];
    //revisar el jaque
    QGraphicsTextItem *check;
    //arreglo de piezas vivas
    QList <Pieza *> alivePiece;
    //menu principal
    void displayMainMenu();
    //derrota de uno de los equipos
    void gameOver();
    //remueve todo del escenario
    void removeAll();

    //convierte un x,y a un log, ejem 0,0 -> a1
    QString conversor(QString r,int x, int y, int& c);

    //Control del log

    QString logb = "LOG BLANCAS\n";
    QString logn = "LOG NEGRAS\n";
    QGraphicsTextItem* logblancas;
    QGraphicsTextItem* lognegras;
    int contb=0;
    int contn=0;
    bool isDead=false;

public slots:
    //comenzar el juego sin cronometro
    void start();
    //comenzaar el juego con cronometro
    void comenzarcronometro();
    //activar cronometro
    void cronometro();
private:
    //Escena del game
    QGraphicsScene *gameScene;
    //pizas blancas y negras consumidas
    QList <Pieza *> whiteDead;
    QList <Pieza *> blackDead;
    //Ubicacion para las piezas consumidas
    QGraphicsRectItem * deadHolder;
    //Turno
    QString turn;
    //Tablero
    Tablero *chess;
    QList <QGraphicsItem *> listG;
    //Cronometro
    QGraphicsTextItem * cronometroblancas;
    QGraphicsTextItem * cronometronegras;
    Tiempo* cron;
    Tiempo* cron2;

};

#endif // GAME_H
