#include "listacuadritos.h"
#include <vector>
Inventario::Inventario()
{

}

bool Inventario::AgregarCuadrito(Cuadrito *Cuadrito)
{
    if(BuscarCuadrito(Cuadrito->getpos())==nullptr)
    {
        Cuadritos.push_back(Cuadrito);
        return true;
    }
    else
        return false;
}


Cuadrito *Inventario::BuscarCuadrito(int pos)
{
    for(unsigned i=0; i<Cuadritos.size(); i++)
   {
       if(Cuadritos[i]->getpos()==pos)
       {
           return Cuadritos[i];
       }
    }
    return nullptr;
}

vector<Cuadrito *> Inventario::getCuadritos()
{
    return Cuadritos;
}
int Inventario::ContarCuadritoes()
{
    unsigned i = 0;
    for(i=0; i<Cuadritos.size(); i++)
   {

   }
    return i;
}


