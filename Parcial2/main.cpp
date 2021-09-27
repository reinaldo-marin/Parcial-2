 #include <iostream>
#include <QImage>
#include <fstream>
#include <listacuadritos.h>
#include <cuadrito.h>
using namespace std;

vector<int> llenar (int inix, int iniy, int endx, int endy)
{
    string filename = "imagen.jpg";
    QImage im(filename.c_str() );
    QImage img2 = im.scaled(700, 600);
    Cuadrito *cuadrito;
    Inventario miInventario;
    vector<int> prom = {0,0,0};
    int contador = 0;
    int aumento = iniy;
    for(inix;inix<endx;inix++)
    {
        for(iniy;iniy<endy;iniy++)
        {
            int red = img2.pixelColor(inix,iniy).red();
            int green = img2.pixelColor(inix,iniy).green();
            int blue = img2.pixelColor(inix,iniy).blue();
            if(img2.pixelColor(inix,iniy).red() == 255)
            {
                red = 254;
            }
            if(img2.pixelColor(inix,iniy).green() == 255)
            {
                green = 254;
            }
            if(img2.pixelColor(inix,iniy).blue() == 255)
            {
                blue = 254;
            }
            cuadrito = new Cuadrito(contador,red,green,blue);
            if(miInventario.AgregarCuadrito(cuadrito))
            {
                cout<<"";
            }
            else
            {
                cout<<"Error"<<endl;
            }
            contador++;
        }
        iniy = aumento;
    }
    int i, repite = 1, mayorRepite = -999;
    cout<<"tamano:"<<miInventario.ContarCuadritoes()<<endl;
    for(i=0; i<miInventario.ContarCuadritoes()-1;i++)
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
                if (miInventario.getCuadritos()[i]->getred() == 255)
                {
                   prom[0] = 254;
                }
                else
                {
                    prom[0] = miInventario.getCuadritos()[i]->getred();
                }
                if (miInventario.getCuadritos()[i]->getgreen() == 255)
                {
                   prom[1] = 254;
                }
                else
                {
                    prom[1] = miInventario.getCuadritos()[i]->getgreen();
                }
                if (miInventario.getCuadritos()[i]->getblue() == 255)
                {
                   prom[2] = 254;
                }
                else
                {
                    prom[2] = miInventario.getCuadritos()[i]->getblue();
                }

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
    archivo << "// C++ code"<<endl;
    archivo << "//"<<endl;
    archivo << "#include <Adafruit_NeoPixel.h>"<<endl;
    archivo<<"Adafruit_NeoPixel leds0 (15,2,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"Adafruit_NeoPixel leds1 (15,3,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"Adafruit_NeoPixel leds2 (15,4,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"Adafruit_NeoPixel leds3 (15,5,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"Adafruit_NeoPixel leds4 (15,6,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"Adafruit_NeoPixel leds5 (15,7,NEO_GRB + NEO_KHZ800);"<<endl;
    archivo<<"void setup()"<<endl;
    archivo<<"{"<<endl;
    for(int i = 0; i<=5;i++)
    {
       archivo<<"  leds"<<i<<".begin();"<<endl;
       for (int z = 1; z<=13;z+=2)
       {
         archivo<<"  for (int i ="<<z<<"; i < "<<z+2<<"; i++)"<<endl;
         archivo<<"  {"<<endl;
         cout<<"endx:"<<endx<<endl;
         cout<<"endy:"<<endy<<endl;
         prom = llenar (inix,iniy,endx,endy);
         archivo<<"   leds"<<i<<".setPixelColor(i,"<<prom[0]<<","<<prom[1]<<","<<prom[2]<<");"<<endl;
         archivo<<"  }"<<endl;
         archivo<<"  leds"<<i<<".show();"<<endl;
         if(endx<700)
         {
             inix += 100;
             endx += 100;

         }
         else
         {
             break;
         }

       }
       inix = 0;
       endx = 100;
       if(endy<=600 and iniy <=500)
       {
           iniy += 100;
           endy += 100;

       }
       else
       {
           break;
       }


    }
    archivo<<"}"<<endl;
    archivo<<"void loop(){}"<<endl;


    return 0;
}
