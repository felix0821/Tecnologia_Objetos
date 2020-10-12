#include <iostream>
#include "Calculadora.h"

int main()
{//Se ingresa la operacion en forma de texto
    std::string operacion;
    std::cout << "Ingrese la suma: " << std::endl;
    getline(std::cin,operacion);
    Calculadora calculadora;
    //Insertamos la cadena de texto en calculadora
    calculadora.RealizarOperacion(operacion);
    return 0;
}
