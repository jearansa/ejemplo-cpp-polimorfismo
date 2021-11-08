
#include <cstring>
#include "EmplDistr.h"

// Atención a la cabecera del constructor de la clase Derivada;
// Siempre debe contener una llamada al constructor de la clase Base;
// Si la clase Base contiene un constructor sin parámetros, y no ponemos nada,
// C++ internamente llamará al mismo.
// Si no hay constructor sin parámetros y no invocamos a alguno de los otros
// constructores, obtendremos un error de compilación

EmplDistr::EmplDistr(string n, long d, double sb, string r):Asal (n, d, sb){
          this->region = r;
}

string EmplDistr::getRegion (){
     return this->region;
}

void EmplDistr::setRegion (string nr){
     this->region = nr;
}

// Sintaxis para invocar a un método de la clase Base;
// NombreClase::nombreMetodo ()
// Observa que si omitimos el nombre de la clase Base el programa compila,
// pero entrará en un bcle infinito

double EmplDistr::getSalario (){
       return this->Asal::getSalario() * (1 + 0.10);
}
