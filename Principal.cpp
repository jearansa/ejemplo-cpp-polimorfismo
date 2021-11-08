

#include <iostream>
#include <typeinfo>

#include "Asal.h"
#include "EmplProd.h"
#include "EmplDistr.h"

void muestraSalarioObjeto (Asal a);

void muestraSalarioPuntero (Asal * a);

Asal * devuelvePuntero ();

using namespace std;

int main (){

 // Como hemos dicho, los cambios para obtener polimorfismo son:
 // 1. El uso del modificador "virtual" en los métodos que se vayan a redefinir;
 //    lo puedes comprobar en "Asal.h", en el método "getSalario(): double"
 // 2. El uso de memoria dinámica en los objetos que llamen a los métodos
 //    que han sido redefinidos, en este caso, "getSalario(): double"

 // Veamos ahora lo que sucede al interrogar a los objetos sobre el tipo
 // al que pertenecen en tiempo de ejecución; compáralo con lo
 // que sucedía en las transparencias de la Sección 3.1, antes de que
 // incluyéramos el modificador "virtual":

 Asal a1 ("Juan Abad", 12345678, 1200);
 cout << typeid(a1).name() << endl; // Obtendríamos como resultado Asal;

 // El operador "sizeof (type)", "sizeof (variable)", "sizeof (object)"
 // nos da información sobre el tamaño de una clase, objeto o variable en memoria
 // Más información en http://en.wikipedia.org/wiki/Sizeof
 // Observar que está muy relacionado con gestión explícita de memoria (malloc...)
 // y por tanto nosotros lo omitiremos
 // cout << "El tamaño del objeto a1 en memoria es " << sizeof (a1) << endl;

 Asal * pa1 = new EmplProd ("Juan Mota", 55333222, 1200, "noche");
 cout << typeid(pa1).name() << endl;  // Obtendríamos como resultado PAsal
 cout << typeid(*pa1).name() << endl; // Obtendríamos como resultado EmplProd
 cout << typeid(&pa1).name() << endl; // Obtendríamos como resultado PPAsal

 EmplProd * pa2 = new EmplProd ("Juan Mota", 55333222, 1200, "noche");
 EmplDistr * pa3 = new EmplDistr ("Antonio Camino", 55333666, 1200, "Granada");
 cout << typeid(*pa3).name() << endl; // Obtendríamos como resultado EmplDistr
 Asal * pa4 = new EmplDistr ("Antonio Camino", 55333666, 1200, "Granada");
 cout << typeid(*pa4).name() << endl; // Obtendríamos como resultado EmplDistr

 // Sección 3.2.1 Polimorfismo de métodos trabajando con objetos

 // Intenta averiguar a qué versión del método "getSalario(): double" se
 // invocará en cada una de las siguientes sentencias, y por qué

 a1.getSalario();        // La de la clase Asal;

 pa1->getSalario();      // La de la clase EmplProd;
 (*pa1).getSalario();    // De nuevo la de EmplProd;
 pa2->getSalario();      // La de EmplProd;

 // Hacemos ahora asignaciones de objetos y punteros:

 // pa2 = pa1;          // Fallo de compilación, pa2 está declarado de un subtipo de pa1
 pa1 = pa4;
 pa1->getSalario();     // Ahora pa1 invoca al de EmplDistr
 (*pa1).getSalario();   // De nuevo invocamos al de EmplDistr
 a1 = (*pa1);           // Al objeto a1 le asignamos el objeto "*pa1";
                        // actúa el constructor de copia,
                        // "copiamos" (*pa1) en un objeto "Asal"
 (&a1)->getSalario();   // Si intentamos recuperar la referencia,
                        // a1 sigue perteneciendo a la clase Asal
                        // No conseguimos polimorfismo
 EmplDistr ed ("Antonio Camino", 55333666, 1600, "Granada");
 pa1 = &ed;             // Al puntero le asignamos la referencia de "ed"
 pa1->getSalario();     // Ahora sí invocamos a la de EmplDistr

 // Sección 3.2.2 Polimorfismo de métodos trabajando sobre estructuras de datos

 // Veamos qué sucede ahora al trabajar con arrays:

 Asal v [5] = {a1, *pa1, *pa2, *pa3, *pa4};
 v[0].getSalario();      // Llamaremos a la versión de "getSalario(): double" de la
                         // clase que está declarado el array, en este caso "Asal"

 v[1].getSalario();      // De nuevo la versión de "Asal"
 v[4].getSalario();      // De nuevo la versión de "Asal"

 // Sin embargo, si el array es de punteros, de nuevo las llamadas a métodos
 // se enlazarán de forma dinámica:

 Asal * w [5] = {&a1, pa1, pa2, pa3, pa4};

 w[0]->getSalario();       // Llamaremos a la versión de la clase que está construido
                           // el objeto a1, o el puntero a objeto, en este caso "Asal"

 w[2]->getSalario();       // Llamaremos a "getSalario(): double" de "EmplProd"
 w[1]->getSalario();       // Llamaremos a "getSalario(): double" de "EmplDistr"
 w[4]->getSalario();       // Llamaremos a "getSalario(): double" de "EmplDistr"

 // Sección 3.2.3 Polimorfismo de métodos trabajando sobre funciones auxiliares

 // Veamos lo que sucede ahora cuando invocamos a métodos auxiliares

 muestraSalarioObjeto (a1);   // No conseguiremos comportamiento polimorfo

 muestraSalarioObjeto (*pa1); // Aquí tampoco, llamará a los métodos en "Asal"

 muestraSalarioPuntero (pa1); // Aquí obtenemos polimorfismo,
                              // invocaremos a "getSalario()" de "EmplDistr"

 muestraSalarioPuntero (pa2); // Aquí también obtenemos polimorfismo,
                              // llamamos a "getSalario(): double" de "EmplProd"

 return 0;
}

// En el siguiente método, al trabajar con los parámetros con objetos,
// el enlazado de nuevo se hace de forma estática; siempre serán invocadas
// las definiciones de los métodos de la clase Asal, independientemente
// del tipo de objeto que pasemos a la función.

// Si recuerdas cuando hablábamos del paso por valor, el objeto que pasamos
// como parámetro se "copia" en un parámetro local al método, de tipo "Asal",
// y se "pierde" la información del tipo del parámetro pasado; por eso
// se pierde también la posibilidad de recuperar el comportamiento polimorfo:

void muestraSalarioObjeto (Asal a){
     cout << "El salario de " << a.getNombre() << " es " << a.getSalario() << endl;
}

// En el siguiente método, como los parámetros son punteros, las llamadas a los
// métodos correspondientes sí que se harñan de manera polimorfa, enlazando
// las llamadas con los métodos en tiempo de ejecución, y por tanto obteniendo
// polimorfismo.

// En el caso del paso de punteros, tal y como veíamos en el paso de parámetros
// en C++, se envían las direcciones de memoria; en tiempo de ejecución,
// se puede comprobar el tipo de objeto al que apunta dicho puntero,
// y llamar a la definición del método de la clase correspondiente a ese tipo

void muestraSalarioPuntero (Asal * a){
     cout << "El salario de " << a->getNombre() << " es " << a->getSalario() << endl;
}
