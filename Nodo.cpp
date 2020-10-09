#include "Nodo.h"
Nodo::Nodo(){}
Nodo::Nodo(int valor):
Valor{valor}
{
    std::cout<<"nuevo valor"<<std::endl;
}
void Nodo::Agregar(int valor)
{
    if(Simbolo=='x')
    {
        this->Valor=valor;
    }else
    {
        /*
        if(Izquierda().)
        {

        }*/
    }
}
void Nodo::Agregar(char simbolo)
{
    this->Simbolo=simbolo;
}
