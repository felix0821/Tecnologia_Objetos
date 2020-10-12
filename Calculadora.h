#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <cinttypes>
#include <iostream>
#include <memory>
#include "Arbolb.h"
#include "Analizador.h"
class Calculadora
{
public:
    //Constructores
    Calculadora();
    //Metodos de la calculadora
    int GetResultado();
    int Operacion(ArbolB::Arbol arbol);
    void RealizarOperacion(std::string cadena);

private:
    //La calculadora contiene arbol y analizador
    int Resultado;
    ArbolB Arbol;
    Analizador Analiza;
};

#endif // CALCULADORA_H
