 #include <iostream>
#include <QImage>
#include <fstream>
#include <listacuadritos.h>
#include <cuadrito.h>
using namespace std;

vector<int> llenar (int inix, int iniy, int endx, int endy)
{
    string filename = "../AppImagenes/images/imagen.jpg";
    QImage im(filename.c_str() );
    QImage img2 = im.scaled(700, 500, Qt::KeepAspectRatio);
    Cuadrito *cuadrito;
    Inventario miInventario;
    vector<int> prom;
    int contador = 0;
    for(inix;inix<=endx;inix++)
    {
        for(iniy;iniy<=endy;iniy++)
        {
            cuadrito = new Cuadrito(contador,im.pixelColor(inix,iniy).red(),im.pixelColor(inix,iniy).green(),im.pixelColor(inix,iniy).blue());
            if(miInventario.AgregarCuadrito(cuadrito))
            {
                cout<<"Cargando imagen..."<<endl;
            }
            contador++;
        }
    }
    int i, repite = 1, mayorRepite = -999;
    for(i=0; i<miInventario.ContarCuadritoes();i++)
    {
        if(miInventario.getCuadritos()[i]->getred()==miInventario.getCuadritos()[i+1]->getred() and miInventario.getCuadritos()[i]->getgreen()==miInventario.getCuadritos()[i+1]->getgreen() and miInventario.getCuadritos()[i]->getblue()==miInventario.getCuadritos()[i+1]->getblue())
        {
          repite++;
        }
        else
        {
            if (repite > mayorRepite)
            {
                mayorRepite = repite;
                prom[0] = miInventario.getCuadritos()[i]->getred();
                prom[1] = miInventario.getCuadritos()[i]->getgreen();
                prom[2] = miInventario.getCuadritos()[i]->getblue();
            }
            repite = 1;
        }
    }
    if (repite > mayorRepite)
    {
        mayorRepite = repite;
        prom[0] = miInventario.getCuadritos()[i]->getred();
        prom[1] = miInventario.getCuadritos()[i]->getgreen();
        prom[2] = miInventario.getCuadritos()[i]->getblue();
    }
    return prom;

}
int main()
{
    vector<int> prom;
    string nombreArchivo = "ordenes.txt";
    ofstream archivo;
    int inix = 0;
    int iniy = 0;
    int endx = 100;
    int endy = 100;
    // Abrimos el archivo
    archivo.open(nombreArchivo.c_str(), fstream::out);
    archivo << "#include <Adafruit_NeoPixel.h"<<endl;
    archivo<<"Adafruit_NeoPixel leds0 (15,2,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"Adafruit_NeoPixel leds2 (15,3,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"Adafruit_NeoPixel leds3 (15,4,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"Adafruit_NeoPixel leds4 (15,5,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"Adafruit_NeoPixel leds5 (15,6,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"void setup();"<<endl;
    archivo<<"{"<<endl;
    for(int i = 0; i<=5;i++)
    {
       archivo<<"  leds"<<i<<".begin();"<<endl;
       for (int z = 1; z<=12;z+=2)
       {
         archivo<<"  for (int i ="<<z<<"; i < "<<z+2<<"; i++)"<<endl;
         archivo<<"  {"<<endl;
         prom = llenar (inix,iniy,endx,endy);
         archivo<<"   leds.setPixelColor(i,"<<prom[0]<<","<<prom[1]<<","<<prom[2]<<");"<<endl;
         archivo<<"  }"<<endl;
         archivo<<"  leds"<<i<<".show();"<<endl;
       }

    }
    vector<int> square = llenar (0, 0, 100, 100);
    archivo << "cuph";
    archivo << endl;


    return 0;
}
