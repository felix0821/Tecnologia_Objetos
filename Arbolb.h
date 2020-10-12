#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>
#include <cstdlib>
class ArbolB
{
public:
    //Constructor
    ArbolB();
    //Estructura nodo
    struct Nodo{
        int Valor{0};
        char Simbolo{'~'};
        struct Nodo *Izquierda,*Derecha;
    };
    typedef struct Nodo *Arbol;
    //Metodos de mi arbol
    void SetNodo(int valor);
    void SetNodo(char simbolo);
    Arbol GetNodo();

    void VerArbol(Arbol arbol, int n);

    //Destructor
    ~ArbolB()
    {
        std::cout<<"Finalizar"<<std::endl;
    }
    //Metodos propios del Nodo
    Arbol InsertarNumero(int valor)
    {   //Los numeros son siempre hojas
         Arbol nuevoNodo = new(struct Nodo);
         nuevoNodo->Valor = valor;
         nuevoNodo->Izquierda = NULL;
         nuevoNodo->Derecha = NULL;
         return nuevoNodo;
    }
    //Este metodo recibe el contenido de arbol, el puntero
    //y un caracter para realizar la rotacion.
    Arbol RotacionIzquierda(Arbol &nodo,Arbol puntero,char signo)
    {   //Los simbolos siempre rotan hacia la izquierda
        Arbol nuevoNodo=new(struct Nodo);
        nuevoNodo->Valor = 0;
        nuevoNodo->Simbolo = signo;
        nuevoNodo->Izquierda = nodo;
        nuevoNodo->Derecha = NULL;
        puntero=nuevoNodo;
        return puntero;
    }

private:
    Arbol arbol = NULL;
    void SetNodo(Arbol &nodo,int valor);
    void SetNodo(Arbol &nodo,char simbolo);
};

#endif // ARBOLB_H
