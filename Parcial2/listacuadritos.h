#ifndef Inventario_H
#define Inventario_H
#include <cuadrito.h>
#include <vector>
#include <fstream>

class Inventario
{
    vector<Cuadrito*>Cuadritos;

public:
    Inventario();
    bool AgregarCuadrito(Cuadrito *Cuadrito);
    Cuadrito *BuscarCuadrito(int pos);
    int ContarCuadritoes();
    vector<Cuadrito*>getCuadritos();

};

#endif // Inventario_H
