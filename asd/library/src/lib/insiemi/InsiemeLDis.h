#ifndef INSIEMELDIS_H_
#define INSIEMELDIS_H_

#include "../common/stdInclude.h"
#include "NodoInsiemeLDis.h"

template <class T>
class InsiemeLDis {
	public:
		InsiemeLDis();
		~InsiemeLDis();
		void creaInsieme();
		bool insiemeVuoto();
		bool appartiene(T);
		void inserisci(T);
		void cancella(T);
		InsiemeLDis<T> unione(InsiemeLDis<T>);
		InsiemeLDis<T> intersezione(InsiemeLDis<T>);
		InsiemeLDis<T> differenza(InsiemeLDis<T>);
		T leggi();
		void mostraInsieme();
		int cardinalita();
	private:
		typedef NodoInsiemeLDis<T> componenteInsieme;
		componenteInsieme* primoInsieme;
};

template <class T>
InsiemeLDis<T>::InsiemeLDis() {
	creaInsieme();
};

template <class T>
InsiemeLDis<T>::~InsiemeLDis() {};

template <class T>
void InsiemeLDis<T>::creaInsieme() {
	primoInsieme = NULL;
};

template <class T>
bool InsiemeLDis<T>::insiemeVuoto() {
	return (primoInsieme == NULL );
};

template <class T>
bool InsiemeLDis<T>::appartiene(T value) {
	componenteInsieme* corrente = primoInsieme;
	while ( corrente != NULL ) {
		if ( corrente->getValue() == value  ) {
			return true;
		}
		corrente = corrente->getSuccessivo();
	}
	return false;
};

template <class T>
void InsiemeLDis<T>::inserisci(T newValue) {
	if ( insiemeVuoto() || !appartiene(newValue) ) {
		componenteInsieme* nuovoPrimo = new componenteInsieme(newValue);
		nuovoPrimo->setSuccessivo(primoInsieme);
		primoInsieme = nuovoPrimo;
	}
};

template <class T>
void InsiemeLDis<T>::cancella(T value) {
	if ( !insiemeVuoto() && appartiene(value) ) {
		if ( primoInsieme->getValue() == value ) {
			primoInsieme = primoInsieme->getSuccessivo();
		} else {
			componenteInsieme* corrente = primoInsieme;
			while ( corrente->getSuccessivo()->getValue() != value ) {
				corrente = corrente->getSuccessivo();
			}
			corrente->setSuccessivo( corrente->getSuccessivo()->getSuccessivo() );
		}  
	} else {
		__DEBUG("InsiemeLDis::cancella(): value non appartiene");
	}
};

template <class T>
InsiemeLDis<T> InsiemeLDis<T>::unione(InsiemeLDis<T> A) {
	
	InsiemeLDis<T> C = A;
	if (  !insiemeVuoto() ) {
		componenteInsieme* corrente = primoInsieme;
		while ( corrente != NULL ) {
			C.inserisci(corrente->getValue());
			corrente = corrente->getSuccessivo();
		}
	}
	return C;
};

template <class T>
InsiemeLDis<T> InsiemeLDis<T>::intersezione(InsiemeLDis<T> A) {
	
	InsiemeLDis<T> C;
	C.creaInsieme();
	
	if ( !insiemeVuoto() ) {
		componenteInsieme* corrente = primoInsieme;
		while ( corrente != NULL ) {
			if ( A.appartiene(corrente->getValue()) ) {
				C.inserisci(corrente->getValue());
			}
			corrente = corrente->getSuccessivo();
		}
	}
	return C;
};


template <class T>
InsiemeLDis<T> InsiemeLDis<T>::differenza(InsiemeLDis<T> A) {
	
	InsiemeLDis<T> C;
	C.creaInsieme();
	
	if ( !insiemeVuoto() ) {
		componenteInsieme* corrente = primoInsieme;
		while ( corrente != NULL ) {
			if ( !A.appartiene(corrente->getValue()) ) {
				C.inserisci(corrente->getValue());
			}
			corrente = corrente->getSuccessivo();
		}
	}
	return C;
};

template <class T>
T InsiemeLDis<T>::leggi() {
	T ritorno;
	if ( !insiemeVuoto() ) {
		ritorno = primoInsieme->getValue();
	}
	return ritorno;
}

template <class T>
void InsiemeLDis<T>::mostraInsieme() {
	bool primo = true;
	cout << "{ ";
	componenteInsieme* corrente = primoInsieme;
	while ( corrente != NULL ) {
		if ( !primo ) {
			cout << "- ";
		} else {
			primo = false;
		}
		cout << corrente->getValue() << " ";
		corrente = corrente->getSuccessivo();
	}
	cout << "}" << endl;
}


template <class T>
int InsiemeLDis<T>::cardinalita() {
	int i = 0;
	componenteInsieme* corrente = primoInsieme;
	while ( corrente != NULL ) {
		corrente = corrente->getSuccessivo();
		i++;
	}
	return i;
}


#endif /*INSIEMELDIS_H_*/
