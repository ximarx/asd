#ifndef LISTAPTR_H_
#define LISTAPTR_H_

#include "../common/stdInclude.h"
#include "NodoListaPtr.h"

template <class T>
class ListaPtr {
	public:
		typedef NodoListaPtr<T>* posizione; 
		ListaPtr();
		~ListaPtr();
		void creaLista();
		posizione primoLista();
		posizione succLista(posizione );
		posizione precLista(posizione );
		bool fineLista(posizione );
		posizione pos(int);
		bool listaVuota();
		T leggiLista(posizione );
		void scriviLista(T, posizione );
		void insLista(T, posizione );
		void cancLista(posizione ); 
	private:
		posizione primo;
};

template <class T>
ListaPtr<T>::ListaPtr() {
	creaLista();
};

template <class T>
ListaPtr<T>::~ListaPtr() {};

template <class T>
void ListaPtr<T>::creaLista() {
	primo = NULL;
};

template <class T>
NodoListaPtr<T>* ListaPtr<T>::primoLista() {
	return primo;
};

template <class T>
NodoListaPtr<T>* ListaPtr<T>::succLista(posizione pos) {
	posizione nextP = NULL;
	if ( !fineLista(pos) ) { 
		nextP = pos->getSuccessivo();
	}
	return nextP;
};

template <class T>
NodoListaPtr<T>* ListaPtr<T>::precLista(posizione pos) {
	posizione precP = NULL;
	if ( primo != pos && !fineLista(pos) ) {
		precP = pos->getPrecedente();
	}
	return precP;
};

template <class T>
bool ListaPtr<T>::fineLista(posizione pos) {
	return ( pos == NULL );
};

template <class T>
NodoListaPtr<T>* ListaPtr<T>::pos(int index) {
	posizione pos = primoLista();
	int i = 1;
	while (!fineLista(pos) && i < index) {
		pos = succLista(pos);
		i++;
	}
	return pos;
};

template <class T>
bool ListaPtr<T>::listaVuota() {
	return ( primo == NULL );
};

template <class T>
T ListaPtr<T>::leggiLista(posizione pos) {
	T ritorno;
	if ( pos != NULL ) {
		ritorno = pos->getValue();
	} else {
		__DEBUG("ListaPtr::leggiLista(): POS e' NULL");
	}
	return ritorno;
};

template <class T>
void ListaPtr<T>::scriviLista(T newValue, posizione pos) {
	if ( !fineLista(pos) ) {
		pos->setValue(newValue);
	} else {
		__DEBUG("ListaPtr::scriviLista(): POS e' NULL");
	}
};

template <class T>
void ListaPtr<T>::insLista(T newValue, posizione pos) {
	posizione nuovoPos = new NodoListaPtr<T>(newValue);
	if ( fineLista(pos) ) {
		if ( listaVuota() ) {
			primo = nuovoPos;
		} else {
			posizione ultimo = primoLista();
			while ( !fineLista(succLista(ultimo)) ) {
				ultimo = succLista(ultimo);
			}
			ultimo->setSuccessivo(nuovoPos);
			nuovoPos->setPrecedente(ultimo);
		}
	} else {
		if ( pos == primo ) {
			nuovoPos->setSuccessivo(primo);
			primo->setPrecedente(nuovoPos);
			primo = nuovoPos;
		} else {
			nuovoPos->setSuccessivo(pos);
			nuovoPos->setPrecedente(precLista(pos));
			precLista(pos)->setSuccessivo(nuovoPos);
			pos->setPrecedente(nuovoPos);
		}
	}
};

template <class T>
void ListaPtr<T>::cancLista(posizione pos) {
	if ( listaVuota() ) {
		__DEBUG("ListaPtr::cancLista(): listaVuota = TRUE");
	} else if ( fineLista(pos) ) {
		__DEBUG("ListaPtr::cancLista(): POS e' NULL");
	} else {
		if ( primo == pos ) {
			succLista(pos)->setPrecedente(NULL);
			primo = succLista(pos);
			pos->setSuccessivo(NULL);
			pos->setPrecedente(NULL);
		} else if ( fineLista(succLista(pos)) ) {
			precLista(pos)->setSuccessivo(NULL);
			pos->setPrecedente(NULL);
		} else {
			succLista(pos)->setPrecedente(precLista(pos));
			precLista(pos)->setSuccessivo(succLista(pos));
			pos->setSuccessivo(NULL);
			pos->setPrecedente(NULL);
		}
	}
}


#endif /*LISTAPTR_H_*/
