#ifndef PILAVET_H_
#define PILAVET_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"

template <class T, int DIM>
class PilaVet {
	public:
		PilaVet();
		~PilaVet();
		void creaPila();
		bool pilaVuota();
		T leggiPila();
		void fuoriPila();
		void inPila(T);
	private:
		Nodo<T> pila[DIM];
		int testa;
};


template <class T, int DIM>
PilaVet<T, DIM>::PilaVet() {
	creaPila();
};

template <class T, int DIM>
PilaVet<T, DIM>::~PilaVet() {};

template <class T, int DIM>
void PilaVet<T, DIM>::creaPila() {
	testa = 0;
};

template <class T, int DIM>
bool PilaVet<T, DIM>::pilaVuota() {
	return (testa == 0);
};

template <class T, int DIM>
T PilaVet<T, DIM>::leggiPila() {
	if ( !pilaVuota() ) {
		return pila[testa -1].getValue();
	} 
};

template <class T, int DIM>
void PilaVet<T, DIM>::fuoriPila() {
	if ( !pilaVuota() ) {
		testa--;
	}
};

template <class T, int DIM>
void PilaVet<T, DIM>::inPila(T newValue) {
	if ( testa == DIM ) {
		__DEBUG("PilaVet::inPila(): Pila piena");
		throw INT_MAX;
	} else {
		pila[testa].setValue(newValue);
		testa++;
	}
};

#endif /*PILAVET_H_*/
