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
    bool EliminarCuadrito(int pos);
    Cuadrito *BuscarCuadrito(int pos);
    vector<string> RandomCuadrito(vector <int> ale);
    int CargarInventario();
    int ContarCuadritoes();
    vector<Cuadrito*>getCuadritos();

};

#endif // Inventario_H
