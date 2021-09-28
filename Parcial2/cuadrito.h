#ifndef CUADRITO_H
#define CUADRITO_H
#include <string>
#include <vector>
#include <string>
using namespace  std;
class Cuadrito
{
   //atributos
   int pos;
   int red;
   int green;
   int blue;

    //Metodos
public:
    Cuadrito();
    Cuadrito(int pos);
    Cuadrito(int pos,int red, int green, int blue);
    int getpos() const;
    int getred() const;
    int getgreen() const;
    int getblue () const;


};
#endif // CuadritoES_H
