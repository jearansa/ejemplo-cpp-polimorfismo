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
           //Constructor; atención, no hay constructor sin parámetros
           Asal (string, long, double);
           //Métodos de instancia:
           string getNombre ();
           void setNombre (string);
           long getDni ();
           void setDni (long);
           // Importante; el modificador de uso "virtual" es el que hace que el
           // método se enlace en tiempo de ejecución, y se comporte de modo
           // polimorfo
           // Dos notas sobre el uso de "virtual":
           // 1. Una vez hemos declarado un método como "virtual", el mismo
           // siempre será enlazado de forma dinámica, en todas sus subclases;
           // en nuestro caso, tanto sobre objetos declarados como EmplProd
           // como sobre ejemplos EmplDistr
           // Por tanto, podríamos añadir "virtual" al método
           // "getSalario(): double" en EmplProd.h y EmplDistr.h, pero sería
           // redundante
           // 2. Por seguridad, podríamos declarar todos los métodos de todas
           // las clases como "virtual", y eso nos aseguraría que se enlazaran
           // de manera dinámica, pero eso ralentizaría también la velocidad de
           // ejecución de los programas, no es recomendable:
          virtual double getSalario ();
};

#endif
