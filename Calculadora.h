#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <cinttypes>
#include <iostream>
#include <memory>
class Calculadora
{
public:
    //Constructores
    Calculadora();

    void SetCadena(std::string cadena);
    std::string GetCadena();



private:
    std::string cadena;
};

#endif // CALCULADORA_H
