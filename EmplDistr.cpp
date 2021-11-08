
#include <cstring>
#include "EmplDistr.h"

// Atenci�n a la cabecera del constructor de la clase Derivada;
// Siempre debe contener una llamada al constructor de la clase Base;
// Si la clase Base contiene un constructor sin par�metros, y no ponemos nada,
// C++ internamente llamar� al mismo.
// Si no hay constructor sin par�metros y no invocamos a alguno de los otros
// constructores, obtendremos un error de compilaci�n

EmplDistr::EmplDistr(string n, long d, double sb, string r):Asal (n, d, sb){
          this->region = r;
}

string EmplDistr::getRegion (){
     return this->region;
}

void EmplDistr::setRegion (string nr){
     this->region = nr;
}

// Sintaxis para invocar a un m�todo de la clase Base;
// NombreClase::nombreMetodo ()
// Observa que si omitimos el nombre de la clase Base el programa compila,
// pero entrar� en un bcle infinito

double EmplDistr::getSalario (){
       return this->Asal::getSalario() * (1 + 0.10);
}
