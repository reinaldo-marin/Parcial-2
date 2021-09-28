#include "cuadrito.h"
int Cuadrito::getpos() const
{
    return pos;
}
int Cuadrito::getred() const
{
    return red;
}
int Cuadrito::getgreen() const
{
    return green;
}
int Cuadrito::getblue() const
{
    return blue;
}

Cuadrito::Cuadrito()
{

}

Cuadrito::Cuadrito(int pos, int red, int green, int blue)
{
    this->pos=pos;
    this->red=red;
    this->green=green;
    this->blue=blue;
}
