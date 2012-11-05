#ifndef PILAPTR_H_
#define PILAPTR_H_

#include "../common/stdInclude.h"
#include "NodoPilaPtr.h"

template <class T>
class PilaPtr {
	public:
		PilaPtr();
		~PilaPtr();
		void creaPila();
		bool pilaVuota();
		void inPila(T);
		T leggiPila();
		void fuoriPila();
	private:
		typedef NodoPilaPtr<T> cellaPila;
		cellaPila* pila; 
};

template <class T>
PilaPtr<T>::PilaPtr() {
	creaPila();
}

template <class T>
PilaPtr<T>::~PilaPtr() {
	pila = NULL;
}

template <class T>
void PilaPtr<T>::creaPila() {
	pila = NULL;
}

template <class T>
bool PilaPtr<T>::pilaVuota() {
	return (pila == NULL);
}

template <class T>
void PilaPtr<T>::inPila(T newValue) {
	cellaPila* nuovaCella = new cellaPila(newValue);
	nuovaCella->setSuccessivo(pila);
	pila = nuovaCella;
}

template <class T>
T PilaPtr<T>::leggiPila() {
	if ( pilaVuota() ) {
		__DEBUG("PilaPtr::leggiPila(): pilaVuota() == TRUE");
		throw 0;
	} else {
		return pila->getValue();
	}
}

template <class T>
void PilaPtr<T>::fuoriPila() {
	if ( pilaVuota() ) {
		__DEBUG("PilaPtr::fuoriPila(): pilaVuota() == TRUE");
	} else {
		pila = pila->getSuccessivo();
	}
}


#endif /*PILAPTR_H_*/
