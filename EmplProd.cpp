
#include <cstring>
#include "EmplProd.h"

EmplProd::EmplProd(string n, long d, double sb, string t): Asal(n, d, sb){
     this->turno = t;
}

string EmplProd::getTurno (){
     return this->turno;
}

void EmplProd::setTurno (string nt){
     this->turno = nt;
}

double EmplProd::getSalario (){
       return this->Asal::getSalario() * (1 + 0.15);
}
