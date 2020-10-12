#include "Analizador.h"
#include "Arbolb.h"
Analizador::Analizador(){}
//Detecta el simbolo actual
int Analizador::simbolo(char n)
{
    //Si es algun numero retorna 1
    if(n=='0'||n=='1'||n=='2'||n=='3'||n=='4'||n=='5'||n=='6'||n=='7'||n=='8'||n=='9')return 1;
    //Si es un simbolo retorna 2 o 3
    if(n=='+')return 2;
    if(n=='*')return 3;
    return 0;
}
//Recibe como referencia el arbol y la cadena de textos
void Analizador::Procesador(ArbolB &arbol,std::string cadena)
{
    int marcador,indicador,longitud=cadena.length();
    bool cambio=true,almacenar=false,error=false;
    for(int i=0;i<longitud;i++)
    {//Recorre el texto
        //Usamos el metodo simbolo para identificar el caracter actual
        indicador=simbolo(cadena[i]);
        if(indicador==0)
        {//Caracter incorrecto
            std::cout<<"---se ingreso dato incorrecto!!!"<<std::endl;
            error=true;
            break;
        }
        if(indicador==1)
        {//El caracter es un numero
            if(cambio){cambio=false;marcador=i;} //Verificar variabilidad
            if(i<longitud-1&&simbolo(cadena[i+1])!=1)almacenar=true;
            if(i==longitud-1)almacenar=true; //Permitir almacenamiento
            if(almacenar){
                std::string extraer=cadena.substr(marcador,i+1);
                arbol.SetNodo(atoi(extraer.c_str()));
                //indice++;
                cambio=true;
                almacenar=false;
            }
        }
        if(indicador==2||indicador==3)
        {//El caracter es un simbolo
            if(i==0||i==longitud-1||simbolo(cadena[i-1])!=1)
            {
                std::cout<<"---error de simbolos!!!"<<std::endl;
                error=true;
                break;
            }else{
                arbol.SetNodo(cadena[i]);
            }
        }
    }
    if(error)
    {
        std::cout <<"La operacion estara incompleta o no funcionara!!!"<<std::endl;
    }
}


