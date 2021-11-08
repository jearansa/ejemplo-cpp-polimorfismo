//Fichero "Asal.h"

#include <string>

#ifndef ASAL_H
#define ASAL_H 1

using namespace std;

class Asal{
  //Atributos de instancia
  private:
           string nombre;
           long dni;
           double salarioBase;
  public:
           //Constructor; atenci�n, no hay constructor sin par�metros
           Asal (string, long, double);
           //M�todos de instancia:
           string getNombre ();
           void setNombre (string);
           long getDni ();
           void setDni (long);
           // Importante; el modificador de uso "virtual" es el que hace que el
           // m�todo se enlace en tiempo de ejecuci�n, y se comporte de modo
           // polimorfo
           // Dos notas sobre el uso de "virtual":
           // 1. Una vez hemos declarado un m�todo como "virtual", el mismo
           // siempre ser� enlazado de forma din�mica, en todas sus subclases;
           // en nuestro caso, tanto sobre objetos declarados como EmplProd
           // como sobre ejemplos EmplDistr
           // Por tanto, podr�amos a�adir "virtual" al m�todo
           // "getSalario(): double" en EmplProd.h y EmplDistr.h, pero ser�a
           // redundante
           // 2. Por seguridad, podr�amos declarar todos los m�todos de todas
           // las clases como "virtual", y eso nos asegurar�a que se enlazaran
           // de manera din�mica, pero eso ralentizar�a tambi�n la velocidad de
           // ejecuci�n de los programas, no es recomendable:
          virtual double getSalario ();
};

#endif
