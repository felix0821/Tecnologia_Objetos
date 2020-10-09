#ifndef NODO_H
#define NODO_H
#include <cinttypes>
#include <iostream>
#include <memory>

class Nodo
{
public:
    Nodo();
    Nodo(int valor);
    void Agregar(int valor);
    void Agregar(char simbolo);
private:
    int Valor{0};
    char Simbolo{'x'};
    Nodo Izquierda();
    Nodo Derecha();
};

#endif // NODO_H
