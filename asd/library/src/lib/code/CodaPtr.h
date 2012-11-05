#ifndef CODAPTR_H_
#define CODAPTR_H_

#include "../common/stdInclude.h"
#include "NodoCodaPtr.h"

template <class T>
class CodaPtr {
	public:
		CodaPtr();
		~CodaPtr();
		void creaCoda();
		bool codaVuota();
		void inCoda(T);
		void fuoriCoda();
		T leggiCoda();
	private:
		typedef NodoCodaPtr<T> cellaCoda;
		cellaCoda* testa;
		cellaCoda* fondo;
	
};

template <class T>
CodaPtr<T>::CodaPtr() {
	creaCoda();
};

template <class T>
CodaPtr<T>::~CodaPtr() {};

template <class T>
void CodaPtr<T>::creaCoda() {
	testa = fondo = NULL;
	
};

template <class T>
bool CodaPtr<T>::codaVuota() {
	return ( testa == NULL );
};

template <class T>
void CodaPtr<T>::inCoda(T newValue) {
	if ( codaVuota() ) {
		testa = fondo = new cellaCoda(newValue);
	} else {
		cellaCoda* nuovoFondo = new cellaCoda(newValue);
		fondo->setSuccessivo(nuovoFondo);
		fondo = nuovoFondo;
	}
};

template <class T>
void CodaPtr<T>::fuoriCoda() {
	if ( codaVuota() ) {
		__DEBUG("CodaPtr::fuoriCoda(): codaVuota() == TRUE");
	} else {
		testa = testa->getSuccessivo();
	}
};

template <class T>
T CodaPtr<T>::leggiCoda() {
	if ( codaVuota() ) {
		__DEBUG("CodaPtr::leggiCoda(): codaVuota() == TRUE");
		throw 0;
	} else {
		return testa->getValue();
	}
};

#endif /*CODAPTR_H_*/
