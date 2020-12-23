#include "Tablero.h"
#include "Game.h"
#include "Peon.h"
#include "Caballo.h"
#include "Dama.h"
#include "Rey.h"
#include "Torre.h"
#include "Alfil.h"
extern Game* game;
Tablero::Tablero()
{
    ArmarBlancas();
    ArmarNegras();
}

void Tablero::DibujarCasillas(int x, int y)
{
    //Distancia de una casilla y otra, cada casilla es de 100x100
    int DistanciaCasilla=100;
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
           Casilla* casillas = new Casilla();

           game->ColeccionCasillas[i][j]=casillas;

           casillas->Fila=i;
           casillas->Columna=j;

           casillas->setPos(x+DistanciaCasilla*j,y+DistanciaCasilla*i);

           if((i+j)%2==0)
               casillas->SetColor(Qt::white);
           else
               casillas->SetColor("#6666ff");
           //Agregando a la escena
           game->AgregarItem(casillas);
        }
    }
}

void Tablero::ArmarBlancas()
{
    Pieza* pieza;
    //Agregar peones
    for(int i=0;i<8;++i){
        pieza= new Peon("blancas");
        blancas.append(pieza);
    }
    //Agregar torre
    pieza = new Torre("blancas");
    blancas.append(pieza);
    //Agregar caballo
    pieza = new Caballo("blancas");
    blancas.append(pieza);
    //Agregar alfil
    pieza = new Alfil("blancas");
    blancas.append(pieza);
    //Agregar Dama
    pieza = new Dama("blancas");
    blancas.append(pieza);
    //Agregar Rey
    pieza = new Rey("blancas");
    blancas.append(pieza);
    //Agregar alfil
    pieza = new Alfil("blancas");
    blancas.append(pieza);
    //Agregar caballo
    pieza = new Caballo("blancas");
    blancas.append(pieza);
    //Agregar torre
    pieza = new Torre("blancas");
    blancas.append(pieza);

}

void Tablero::ArmarNegras()
{
    Pieza* pieza;

    //Agregar torre
    pieza = new Torre("negras");
    negras.append(pieza);
    //Agregar caballo
    pieza = new Caballo("negras");
    negras.append(pieza);
    //Agregar alfil
    pieza = new Alfil("negras");
    negras.append(pieza);
    //Agregar Dama
    pieza = new Dama("negras");
    negras.append(pieza);
    //Agregar Rey
    pieza = new Rey("negras");
    negras.append(pieza);
    //Agregar alfil
    pieza = new Alfil("negras");
    negras.append(pieza);
    //Agregar caballo
    pieza = new Caballo("negras");
    negras.append(pieza);
    //Agregar torre
    pieza = new Torre("negras");
    negras.append(pieza);

    //Agregar peones
    for(int i=0;i<8;++i){
        pieza= new Peon("negras");
        negras.append(pieza);
    }
}

void Tablero::AgregarPiezas()
{
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            Casilla *casillas =game->ColeccionCasillas[i][j];
            //Colocando piezas negras
            if(i < 2) {
                static int k;
                //Modificando la ubicacion de las piezas
                casillas->setPieza(negras[k]);
                //Agregando a lista de piezas vivas
                game->PiezasVivas.append(negras[k]);
                //Agrando las piezas al escenario
                game->AgregarItem(negras[k++]);
            }
            //Colocando piezas blancas
            if(i > 5) {
                static int h;
                casillas->setPieza(blancas[h]);
                game->PiezasVivas.append(blancas[h]);
                game->AgregarItem(blancas[h++]);
            }

        }
    }
}
