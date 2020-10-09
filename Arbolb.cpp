#include "Arbolb.h"

ArbolB::ArbolB(){}
//Metodo que agrega simbolos.
void ArbolB::Agregar(Arbol &nodo,char simbolo)
{   //Los simbolos tienen que estar precedidos por numeros.
    if(nodo==NULL)
    {   //Mensaje
        std::cout << "Error de operacion"<<std::endl;
    }
    else
    {   //Verificamos los simbolos.
        if(simbolo=='+')
        {   //El simbolo 'x' hace referencia a un numero.
            if(nodo->Simbolo=='x'||nodo->Simbolo=='*')
            {//La suma hara rotaciones con numeros y multiplicaciones.
                std::cout << "\t\t rotacion suma"<<std::endl;
                nodo=RotacionIzquierda(nodo,nodo,simbolo);
            }//Se envia el simbolo al siguiente nodo a la derecha.
            else Agregar(nodo->Derecha,simbolo);
//LAS MULTIPLICACIONES TIENEN PRIORIDAD Y NO PUEDEN SER SEPARADAS.
        }
        if(simbolo=='*')
        {   //El simbolo 'x' hace referencia a un numero.
            if(nodo->Simbolo=='x')
            {//La multiplicacion solo hara rotaciones con numeros.
                std::cout << "\t\t rotacion multiplicacion"<<std::endl;
                nodo=RotacionIzquierda(nodo,nodo,simbolo);
            }//Se envia el simbolo al siguiente nodo a la derecha.
            else Agregar(nodo->Derecha,simbolo);
        }
    }
}
//Metodo de agrega nuemeros.
void ArbolB::Agregar(Arbol &nodo, int valor)
{   //Se verifica si el nodo es vacio
     if(nodo==NULL)
     {//Los numeros se almacenan en nodo vacios
         std::cout << "\t\t Insertando numero"<<std::endl;
         nodo = InsertarNumero(valor);
     }//Los numeros se envian hasta hallar un nodo vacio
     else if(nodo->Izquierda==NULL)
          Agregar(nodo->Izquierda, valor);
     else Agregar(nodo->Derecha, valor);
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
    if(arbol->Simbolo=='x')
    {//Imprimir numero si es nodo hoja
        std::cout<< arbol->Valor <<std::endl;
    }//Imprimir simbolo si es nodo padre
    else std::cout<< arbol->Simbolo <<std::endl;
    //Recorriendo el arbol hacia la izquierda
     VerArbol(arbol->Izquierda, n+1);
}
void ArbolB::Inicializar()
{   //Inicializando un arbol con valor nulo
    ArbolB::Arbol arbol = NULL;
    //Insertamos valores a nuestro arbol
    std::cout << "Se insertan valores: 12+4*12"<<std::endl;
    ArbolB::Agregar( arbol, 12);
    ArbolB::Agregar( arbol, '*');
    ArbolB::Agregar( arbol, 4);
    ArbolB::Agregar( arbol, '+');
    ArbolB::Agregar( arbol, 12);
    /*ArbolB::Agregar( arbol, '*');
    ArbolB::Agregar( arbol, 90);
    ArbolB::Agregar( arbol, '*');
    ArbolB::Agregar( arbol, 2);*/
    //Imprimir el contenido de nuestro arbol
    std::cout << "---Mostrando mi arbol---"<<std::endl;
    VerArbol( arbol, 0);
}



/*void ArbolB::Agregar(Arbol &nodo, int x)
{
     if(nodo==NULL)
     {
           nodo = InsertarNumero(x);
     }
     else if(x < nodo->Valor)
          Agregar(nodo->Izquierda, x);
     else if(x > nodo->Valor)
          Agregar(nodo->Derecha, x);
}*/
