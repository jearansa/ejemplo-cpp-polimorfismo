
#ifndef EMPLDISTR_H
#define EMPLDISTR_H 1

#include "Asal.h"

// En la cabecera se debe declarar la herencia,
// y el tipo de la misma (public, private o nada):
class EmplDistr: public Asal{
  // Atributos de instancia
  private:
           string region;
  public:
         // Constructor
         EmplDistr(string, long, double, string);
         // Métodos de instancia:
         string getRegion ();
         void setRegion (string);
         // Aquellos métodos que vayan a redefinirse de la clase base
         // deben ser incluidos en la declaración de las clases hijas
         double getSalario ();
};

#endif
