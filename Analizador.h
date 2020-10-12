#ifndef ANALIZADOR_H
#define ANALIZADOR_H
#include <iostream>
#include <cstdlib>
#include "Arbolb.h"
class Analizador
{
public:
    Analizador();
    //Metodos de mi analizador
    void Procesador(ArbolB &arbol,std::string cadena);
private:
    //Metodos propios de mi analizador
    int simbolo(char n);
    int indice;
};

#endif // ANALIZADOR_H
