#include "Arbolb.h"

ArbolB::ArbolB()
{
    std::cout << "Arbol creado"<<std::endl;
}
//Metodo que agrega simbolos.
void ArbolB::SetNodo(char simbolo)
{
    SetNodo(arbol,simbolo);
}
void ArbolB::SetNodo(Arbol &nodo,char simbolo)
{   //Los simbolos tienen que estar precedidos por numeros.
    if(nodo==NULL)
    {   //Mensaje
        std::cout << "Error de operacion"<<std::endl;
    }
    else
    {   //Verificamos los simbolos.
        if(simbolo=='+')
        {   //El simbolo '~' hace referencia a un numero.
            if(nodo->Simbolo=='~'||nodo->Simbolo=='*')
            {//La suma hara rotaciones con numeros y multiplicaciones.
                std::cout << "\t\t rotacion suma"<<std::endl;
                nodo=RotacionIzquierda(nodo,nodo,simbolo);
            }//Se envia el simbolo al siguiente nodo a la derecha.
            else SetNodo(nodo->Derecha,simbolo);
//LAS MULTIPLICACIONES TIENEN PRIORIDAD Y NO PUEDEN SER SEPARADAS.
        }
        if(simbolo=='*')
        {   //El simbolo '~' hace referencia a un numero.
            if(nodo->Simbolo=='~')
            {//La multiplicacion solo hara rotaciones con numeros.
                std::cout << "\t\t rotacion multiplicacion"<<std::endl;
                nodo=RotacionIzquierda(nodo,nodo,simbolo);
            }//Se envia el simbolo al siguiente nodo a la derecha.
            else SetNodo(nodo->Derecha,simbolo);
        }
    }
}
//Metodo de agrega nuemeros.
void ArbolB::SetNodo(int valor)
{
    ArbolB::SetNodo(arbol, valor);
}
void ArbolB::SetNodo(Arbol &nodo, int valor)
{   //Se verifica si el nodo es vacio
     if(nodo==NULL)
     {//Los numeros se almacenan en nodo vacios
         std::cout << "\t\t Insertando numero"<<std::endl;
         nodo = InsertarNumero(valor);
     }//Los numeros se envian hasta hallar un nodo vacio
     else if(nodo->Izquierda==NULL)
          SetNodo(nodo->Izquierda, valor);
     else SetNodo(nodo->Derecha, valor);
}
//Metodo que grafica al arbol
//Este metodo recibe al arbol y el espacio inicial que es 0
void ArbolB::VerArbol(Arbol arbol, int n)
{   //El arbol retorna cuando esta vacio
    if(arbol==NULL)
        return;
    //Recorriendo el arbol hacia la derecha
    VerArbol(arbol->Derecha, n+1);
    //Imprimiendo espacios
    for(int i=0; i<n; i++)
        std::cout<<"   ";
    //Verificando tipo de nodo
    if(arbol->Simbolo=='~')
    {//Imprimir numero si es nodo hoja
        std::cout<< arbol->Valor <<std::endl;
    }//Imprimir simbolo si es nodo padre
    else std::cout<< arbol->Simbolo <<std::endl;
    //Recorriendo el arbol hacia la izquierda
     VerArbol(arbol->Izquierda, n+1);
}

ArbolB::Arbol ArbolB::GetNodo()
{
    return arbol;
}
