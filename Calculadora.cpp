#include "Calculadora.h"
#include "Arbolb.h"
#include "Analizador.h"
Calculadora::Calculadora(){}
//Metodo que recibe la cadena de texto e invoca los demas metodos
void Calculadora::RealizarOperacion(std::string cadena)
{
    //Usamos el analizador para insertar datos al arbol
    Analiza.Procesador(Arbol,cadena);
    //Usamos el metodo de operacion para resolver
    Resultado=Operacion(Arbol.GetNodo());
    std::cout << "---Mostrando mi arbol---"<<std::endl;
    Arbol.VerArbol( Arbol.GetNodo(), 0);
    std::cout << "---Mostrando resultado---"<<std::endl;
    std::cout <<Resultado<<std::endl;
}

int Calculadora::Operacion(ArbolB::Arbol arbol)
{//Si el simbolo es un numero retornara el valor actual del nodo
    if(arbol->Simbolo=='~')
        return arbol->Valor;
    else{//Los nodos operan adquiriendo sus valores
        int resultado=0;
        //Operacion suma entre nodos
        if(arbol->Simbolo=='+')
            resultado=Operacion(arbol->Izquierda)+Operacion(arbol->Derecha);
        //Operacion multiplicacion entre nodos
        if(arbol->Simbolo=='*')
            resultado=Operacion(arbol->Izquierda)*Operacion(arbol->Derecha);
        return resultado;
    }
}
