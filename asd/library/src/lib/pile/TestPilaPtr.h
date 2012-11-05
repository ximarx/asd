
#ifndef TESTPILAPTR_CPP_
#define TESTPILAPTR_CPP_

#include "../common/stdInclude.h"
#include "PilaPtr.h"

void TestPilaPtr() {

	PilaPtr<int> pila = PilaPtr<int>();
	
	for ( int i = 0; i < 10; i++ ) {
		pila.inPila(i);
	}
	
	try {
		pila.inPila(INT_MAX);
		pila.fuoriPila();
		pila.fuoriPila();
		pila.fuoriPila();
		pila.inPila(INT_MAX / 2);
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