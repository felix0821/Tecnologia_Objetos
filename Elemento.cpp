#include "Elemento.h"
//Construcotres
Elemento::Elemento()
{
    //std::cout<<"Vacio"<<std::endl;
}
Elemento::Elemento(int32_t numeroActual, uint16_t signoActual):
    NumeroActual{numeroActual},SignoActual{signoActual}
{
    std::cout<<"Numero y signo"<<std::endl;
}
Elemento::Elemento(int32_t numeroActual):
    NumeroActual{numeroActual}
{
    std::cout<<"Solo numero"<<std::endl;
}
//Metodos
void Elemento::SetNumeroActual(int32_t numeroActual)
{
    this->NumeroActual=numeroActual;
}
void Elemento::SetSignoActual(uint16_t signoActual)
{
    this->SignoActual=signoActual;
}
int32_t Elemento::GetNumeroActual()const
{
    return NumeroActual;
}
uint16_t Elemento::GetSignoActual()const
{
    return SignoActual;
}
