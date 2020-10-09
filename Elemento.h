#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <cinttypes>
#include <iostream>
#include <memory>

class Elemento
{
public:
    //Constructores
    Elemento();
    Elemento(int32_t numeroActual, uint16_t signoActual);
    Elemento(int32_t numeroActual);

    //Metodos
    void SetNumeroActual(int32_t numeroActual);
    void SetSignoActual(uint16_t signoActual);

    int32_t GetNumeroActual()const;
    uint16_t GetSignoActual()const;


    //Destructor
    //~Elemento(){std::cout<<"Destroyed"<<std::endl;}

    //Atributos
private:
    int32_t NumeroActual{0};
    uint16_t SignoActual{0};
};

#endif // ELEMENTO_H
