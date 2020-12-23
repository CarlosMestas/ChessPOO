#ifndef TIEMPO_H
#define TIEMPO_H


#include <string>
class Tiempo
{
    //Tiempo en 5min
    unsigned minutos{5};
    unsigned segundos{0};
public:
    Tiempo(unsigned minutos, unsigned segundos):minutos{minutos},segundos{segundos}{};
    Tiempo();
    void restar(){
        if(segundos==0){
            minutos--;
            segundos=60;
        }
        segundos--;
    }
    //Imprimir los datos
    std::string imprimir(){
        if(segundos<10){
            return std::to_string(minutos)+":0"+std::to_string(segundos);
        }
        return std::to_string(minutos)+":"+std::to_string(segundos);
    }
    void iszero(){
        if(minutos==0){

        }
    }

};

#endif // TIEMPO_H
