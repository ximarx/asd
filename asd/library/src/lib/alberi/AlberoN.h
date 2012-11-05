#ifndef ALBERON_H_
#define ALBERON_H_

#include "../common/stdInclude.h"
#include "NodoAlberoN.h"

template <class T>
class AlberoN {
	public:
		typedef NodoAlberoN<T>* NodoAlbero;
		AlberoN();
		~AlberoN();
		void creaAlbero();
		bool alberoVuoto();
		NodoAlbero radice();
		NodoAlbero padre(NodoAlbero);
		NodoAlbero primoFiglio(NodoAlbero) const;
		NodoAlbero succFratello(NodoAlbero) const;
		bool ultimoFratello(NodoAlbero) const;
		bool foglia(NodoAlbero) const;
		T leggiNodo(NodoAlbero) const;
		void scriviNodo(T, NodoAlbero);
		NodoAlbero insRadice(T);
		NodoAlbero insFiglio(T, NodoAlbero);
		NodoAlbero insFiglio(T, NodoAlbero, NodoAlbero);
		void cancSottoAlbero(NodoAlbero);
		void insSottoAlbero(NodoAlbero, AlberoN<T> & );
		void insSottoAlbero(NodoAlbero, NodoAlbero, AlberoN<T> & );
	private:
		NodoAlbero root;
};

template <class T>
AlberoN<T>::AlberoN() {
	creaAlbero();
};

template <class T>
AlberoN<T>::~AlberoN() {};

template <class T>
void AlberoN<T>::creaAlbero() {
	root = NULL;
};

template <class T>
bool AlberoN<T>::alberoVuoto() {
	return (root == NULL);
};

template <class T>
typename AlberoN<T>::NodoAlbero AlberoN<T>::radice() {
	if ( !alberoVuoto() ) {
		return root;
	} else {
		__DEBUG("AlberoN::radice(): alberoVuoto() = TRUE");
		return NULL;
	}
};

template <class T>
typename AlberoN<T>::NodoAlbero AlberoN<T>::padre(NodoAlbero nodo) {
	if ( nodo == radice() ) {
		__DEBUG("AlberoN::padre(): nodo non ha padre");
		throw 0;
	} else {
		return nodo->getParent();
	}
};

template <class T>
typename AlberoN<T>::NodoAlbero AlberoN<T>::primoFiglio(NodoAlbero nodo) const {
	if ( nodo == NULL ) {
		__DEBUG("AlberoN::primoFiglio(): nodo = NULL");
		throw 0;
	} else {
		return nodo->getFirstChild();
	}
};

template <class T>
typename AlberoN<T>::NodoAlbero AlberoN<T>::succFratello(NodoAlbero nodo) const {
	if ( ultimoFratello(nodo) ) {
		return NULL;
	} else {
		return nodo->getNextBrother();
	}
}; 

template <class T>
bool AlberoN<T>::ultimoFratello(NodoAlbero nodo) const {
	return ( nodo == NULL );
};

template <class T>
bool AlberoN<T>::foglia(NodoAlbero nodo) const {
	return (primoFiglio(nodo) == NULL);
};

template <class T>
T AlberoN<T>::leggiNodo(NodoAlbero nodo) const {
	return nodo->getValue();
};

template <class T>
void AlberoN<T>::scriviNodo(T valore, NodoAlbero nodo ) {
	if ( nodo != NULL  ) {
		nodo->setValue(valore);
	} else {
		__DEBUG("AlberoN::scriviNodo(): nodo = NULL");
		throw 0;
	}
};

template <class T>
typename AlberoN<T>::NodoAlbero AlberoN<T>::insRadice(T valore) {
	if ( alberoVuoto() ) {
		root = new NodoAlberoN<T>(valore);
		return root;
	} else {
		__DEBUG("AlberoN::insRadice(): alberoVuoto = FALSE");
		throw INT_MAX;
	}
};

template <class T>
typename AlberoN<T>::NodoAlbero AlberoN<T>::insFiglio(T value, NodoAlbero padre, NodoAlbero fratello) {
	if ( padre != NULL ) {
		NodoAlbero nuovoNodo = new NodoAlberoN<T>(value);
		nuovoNodo->setParent(padre);
		NodoAlbero temp;
		if ( !foglia(padre) ) {
			temp = primoFiglio(padre);
			while ( succFratello(temp) != fratello || !ultimoFratello(succFratello(temp)) )
				temp = succFratello(temp);
			temp->setNextBrother(nuovoNodo);
			nuovoNodo->setNextBrother(fratello);
		} else {
			padre->setFirstChild(nuovoNodo);
		}
		return nuovoNodo;
	} else {
		__DEBUG("AlberoN::insFiglio(): padre = NULL");
		throw 0;
	}
};

template <class T>
typename AlberoN<T>::NodoAlbero AlberoN<T>::insFiglio(T value, NodoAlbero padre) {
	return insFiglio(value, padre, NULL);
};

template <class T>
void AlberoN<T>::cancSottoAlbero(NodoAlbero padre) {
	if ( padre == radice() ) {
		root = NULL;
	} else {
		NodoAlbero padrePadre = padre(padre);
		NodoAlbero figlioPadre = primoFiglio(padrePadre);
		if ( figlioPadre != padre ) {
			while ( succFratello(figlioPadre) != padre ) {
				figlioPadre = succFratello(figlioPadre);
			}
			figlioPadre->setNextBrother(succFratello(padre));
		} else {
			padrePadre->setFirstChild(succFratello(padre));
		}
	}
};

template <class T>
void AlberoN<T>::insSottoAlbero(NodoAlbero padre, AlberoN<T> &albero) {
	insSottoAlbero(padre, NULL, albero); 
};

template <class T>
void AlberoN<T>::insSottoAlbero(NodoAlbero padre, NodoAlbero fratello, AlberoN<T> &albero) {
	if ( !alberoVuoto() ) {
		if ( padre != NULL ) {
			NodoAlbero temp;
			if ( !foglia(padre) ) {
				temp = primoFiglio(padre);
				while ( succFratello(temp) != fratello || !ultimoFratello(succFratello(temp)) )
					temp = succFratello(temp);
				temp->setNextBrother(albero.radice());
				albero.radice()->setNextBrother(fratello);
			} else {
				padre->setFirstChild(albero.radice());
			}
		} else {
			__DEBUG("AlberoN::insSottoAlbero(): padre = NULL");
			throw 0;
		}
	} else {
		root = albero.radice();
	}
};

#endif /*ALBERON_H_*/
