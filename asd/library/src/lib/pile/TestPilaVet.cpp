
#ifndef TESTPILAVET_CPP_
#define TESTPILAVET_CPP_

#include "../common/stdInclude.h"
#include "PilaVet.h"

	
void TestPilaVet() {
	
	PilaVet<int, 10> pila = PilaVet<int,10>();
	
	for ( int i = 0; i < 10; i++ ) {
		pila.inPila(i);
	}
	
	try {
		pila.inPila(INT_MAX);
	} catch (int e) {
		pila.fuoriPila();
		pila.fuoriPila();
		pila.fuoriPila();
		pila.inPila(INT_MAX / 2);
	}
	
	
	while ( !pila.pilaVuota() ) {
		cout << "Valore inserito: " << pila.leggiPila() << endl;
		pila.fuoriPila();
	}
}
	
#endif
