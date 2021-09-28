#include "listacuadritos.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;
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

bool Inventario::EliminarCuadrito(int pos)
{
    int posi=-1;
    for(unsigned i=0; i<Cuadritos.size(); i++)
       {
        if(Cuadritos[i]->getpos()==pos)
            posi=i;
    }
    if(posi>0)
    {
        Cuadritos.erase(Cuadritos.begin()+posi);
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


