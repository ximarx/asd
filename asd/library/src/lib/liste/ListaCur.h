#ifndef LISTACUR_H_
#define LISTACUR_H_

#include "../common/stdInclude.h"
#include "NodoListaCur.h"

template <class T, int DIM = 100>
class ListaCur {
	public:
		typedef int posizione;
		
		ListaCur();
		~ListaCur();
		
		void creaLista();
		bool listaVuota();
		bool fineLista(posizione);
		
		T leggiLista(posizione);
		void scriviLista(T, posizione);
		void insLista(T, posizione);
		void cancLista(posizione);
		
		posizione primoLista();
		posizione succLista(posizione);
		posizione precLista(posizione);
		
	private:
		NodoListaCur<T> spazio[DIM];
		posizione primo;
		posizione listaLibera;
		int lunghezza;
		
		static const int NIL = -1;
		
		void sposta(posizione &, posizione &); 
	
};


template <class T, int DIM>
ListaCur<T, DIM>::ListaCur() {
	creaLista();
};

template <class T, int DIM>
ListaCur<T, DIM>::~ListaCur() {};

template <class T, int DIM>
void ListaCur<T, DIM>::creaLista() {
	primo=NIL;
	lunghezza=0;
	listaLibera=0;
	for (int i=0; i<(DIM-1); i++) {
		spazio[i].setSuccessivo(i+1);
	}
	spazio[DIM-1].setSuccessivo(NIL);
};

template <class T, int DIM>
bool ListaCur<T, DIM>::listaVuota() {
	return (lunghezza==0);
};

template <class T, int DIM>
T ListaCur<T, DIM>::leggiLista(posizione p) {
	if ((lunghezza>0)&&(p!=NIL)) {
		return (spazio[p].getValue());
	}
};

template <class T, int DIM>
void ListaCur<T, DIM>::scriviLista(T elem, posizione p) {
	if ((lunghezza>0)&&(p!=NIL)) {
		spazio[p].setValue(elem);
	}
};

template <class T, int DIM>
int ListaCur<T, DIM>::primoLista() {
	return (primo);
};

template <class T, int DIM>
int ListaCur<T, DIM>::succLista(posizione p) {
	if ( p != NIL ) {
		return (spazio[p].getSuccessivo());
	} else {
		return NIL;
	}
};

template <class T, int DIM>
int ListaCur<T, DIM>::precLista(posizione p) {
	posizione temp=primo;
	while (spazio[temp].getSuccessivo() != p) {
		temp=spazio[temp].getSuccessivo();
	}
	return (temp);
};

template <class T, int DIM>
bool ListaCur<T, DIM>::fineLista(posizione p) {
	return (p==NIL);
};

template <class T, int DIM>
void ListaCur<T, DIM>::insLista(T elem, posizione p) {
	if (listaLibera != NIL) {
		if (p == primo) {
			sposta(listaLibera, p);
			spazio[p].setValue(elem);
			primo=p;
		} else {
			posizione q = precLista(p);  // ultimo lista (p==NIL)
			sposta(listaLibera, p);
			spazio[p].setValue(elem);
			spazio[q].setSuccessivo(p);
		}
		lunghezza++;
	}
};

template <class T, int DIM>
void ListaCur<T, DIM>::cancLista(posizione p) {
	if ((lunghezza > 0)&&(p != NIL)) {
		if (p != primo) {
			spazio[precLista(p)].setSuccessivo(spazio[p].getSuccessivo());
		}
		sposta(p, listaLibera);
		lunghezza--;
	} 
};

template <class T, int DIM>
void ListaCur<T, DIM>::sposta(posizione &h, posizione &k) {
	posizione temp = spazio[h].getSuccessivo();
	spazio[h].setSuccessivo(k);
	k=h;
	h=temp;
};


#endif /*LISTACUR_H_*/
