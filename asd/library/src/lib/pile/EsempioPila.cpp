


/***
Pila pila := creaPila()
tipoElem valoreIndicato;
integer i := 0
while i != 5
	visualizza "Indicare l'elemento da inserire: "
	valoreIndicato := leggi da tastiera  
	pila.inPila(valoreIndicato)
	i := i + 1
endwhile

while pila.pilaVuota != true
	if pila.leggiPila() % 2 = 0
		visualizza pila.leggiPila()
		visualizza " "
	endif
	pila.fuoriPila()
endwhile
*/

#include "../common/stdInclude.h"
#include "PilaVet.h"

void EsempioPilePilaVet() {
	PilaVet<int, 5> pila;
	pila.creaPila();
	int valoreIndicato;
	for ( int i = 0; i < 5; i++ ) {
		cout << "Indicare l'elemento da inserire: ";
		cin >> valoreIndicato;
		pila.inPila(valoreIndicato);
	}
	while ( !pila.pilaVuota() ) {
		if ( (pila.leggiPila() % 2) == 0 ) {
			cout << pila.leggiPila() << " ";
		}
		pila.fuoriPila();
	}
	cout << endl;
}

#include "PilaPtr.h"

template <class T>
PilaPtr<T> acquisizionePila(int stackLength) {
	PilaPtr<T> pila;
	pila.creaPila();
	T valore;
	for ( int i = 0; i < stackLength; i++ ) {
		cout << "Indicare l'elemento da inserire: ";
		cin >> valore;
		pila.inPila(valore); 
	}
	return pila;
}

template <class T>
void stampa(PilaPtr<T> pila) {
	while ( !pila.pilaVuota() ) {
		cout << pila.leggiPila() << " ";
		pila.fuoriPila();
	}
	cout << endl;
}


template <class T>
PilaPtr<T> copia(PilaPtr<T> pila) {
	PilaPtr<T> copiaPila, pilaAppoggio;
	while ( !pila.pilaVuota() ) {
		pilaAppoggio.inPila(pila.leggiPila());
		pila.fuoriPila();
	}
	while ( !pilaAppoggio.pilaVuota() ) {
		pila.inPila(pilaAppoggio.leggiPila());
		copiaPila.inPila(pila.leggiPila());		
		pilaAppoggio.fuoriPila();
	}
	return copiaPila;
};
