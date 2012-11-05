#ifndef CODAVET_H_
#define CODAVET_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"

template <class T, int DIM>
class CodaVet {
	public:
		CodaVet();
		~CodaVet();
		void creaCoda();
		bool codaVuota();
		void inCoda(T);
		T leggiCoda();
		void fuoriCoda();
	private:
		Nodo<T> coda[DIM];
		int inizio;
		int fine;
		static const int NIL = -1;
};

template <class T, int DIM>
CodaVet<T, DIM>::CodaVet() {
	creaCoda();
};

template <class T, int DIM>
CodaVet<T, DIM>::~CodaVet() {};


template <class T, int DIM>
void CodaVet<T, DIM>::creaCoda() {
	inizio = NIL;
	fine = NIL;
};


template <class T, int DIM>
bool CodaVet<T, DIM>::codaVuota() {
	return ( inizio == NIL ); 
};


template <class T, int DIM>
void CodaVet<T, DIM>::inCoda(T newValue) {
	if ( ( (fine - inizio + 1) % DIM ) != 0  ) {
		fine = (fine + 1) % DIM;
		if ( inizio == NIL ) {
			inizio = fine;
		}
		coda[fine].setValue(newValue);
	} else {
		__DEBUG("CodaVet::inCoda(): Coda piena");
		throw INT_MAX;
	} 
};


template <class T, int DIM>
T CodaVet<T, DIM>::leggiCoda() {
	if ( codaVuota() ) {
		__DEBUG("CodaVet::leggiCoda(): codaVuota() == TRUE");
		throw 0; 
	} else {
		return coda[inizio].getValue();
	}
};


template <class T, int DIM>
void CodaVet<T, DIM>::fuoriCoda() {
	if ( codaVuota() ) {
		__DEBUG("CodaVet::fuoriCoda(): codaVuota() == TRUE");
		throw 0; 
	} else {
		if ( inizio == fine ) {
			inizio = fine = NIL;
		} else {
			inizio = (inizio + 1) % DIM;
		}
	}
};


#endif /*CODAVET_H_*/
