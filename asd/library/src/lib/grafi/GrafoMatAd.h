#ifndef GRAFOMATAD_H
#define GRAFOMATAD_H

#include "../common/stdInclude.h"
#include "../liste/ListaPtr.h"
#include "NodoGrafoMatAd.h"

template <class T, int DIM>
class GrafoMatAd {
	public:
		typedef int NodoGrafo;
		typedef ListaPtr<NodoGrafo> ListaAdiacenti;
		GrafoMatAd();
		~GrafoMatAd();
		void creaGrafo();
		bool grafoVuoto();
		bool esisteNodo(NodoGrafo);
		bool esisteArco(NodoGrafo, NodoGrafo);
		void insNodo(T, NodoGrafo);
		void insArco(NodoGrafo, NodoGrafo);
		void cancNodo(NodoGrafo);
		void cancArco(NodoGrafo, NodoGrafo);
		ListaPtr<NodoGrafo> adiacenti(NodoGrafo);
		bool getVisitato(NodoGrafo);
		void setVisitato(bool, NodoGrafo);
		T getLabel(NodoGrafo);
		void setLabel(T, NodoGrafo);
		int getArchi(NodoGrafo);
		void azzeraVisitato();
		int numNodi();
	private:
		NodoGrafoMatAd<T> nodi[DIM];
		bool grafo[DIM][DIM];
};

template <class T, int DIM>
GrafoMatAd<T, DIM>::GrafoMatAd() {
     creaGrafo();
};

template <class T, int DIM>
GrafoMatAd<T, DIM>::~GrafoMatAd() { };

template <class T, int DIM>	
void GrafoMatAd<T, DIM>::creaGrafo() {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++)
			grafo[i][j] = false;
	}
};

template <class T, int DIM>
bool GrafoMatAd<T, DIM>::grafoVuoto() {
	for ( int i = 0; i < DIM; i++ ) {
		if ( nodi[i].getEsiste() )
			return false;
	}
	return true;
};

template <class T, int DIM>
bool GrafoMatAd<T, DIM>::esisteNodo(NodoGrafo i) {
     return (nodi[i].getEsiste() == true);
};

template <class T, int DIM>
bool GrafoMatAd<T, DIM>::esisteArco(NodoGrafo i, NodoGrafo j) {
     return (grafo[i][j] == true);
};

template <class T, int DIM>
void GrafoMatAd<T, DIM>::insNodo(T a, NodoGrafo i) {
	if ( !nodi[i].getEsiste() ) {
		nodi[i].setEsiste(true);
		nodi[i].setValue(a);
	} else {
		__DEBUG("GrafoMatAd::insNodo(): il nodo esiste");
		throw 1;
	}
};

template <class T, int DIM>
void GrafoMatAd<T, DIM>::insArco(NodoGrafo i, NodoGrafo j) {
	if ( !grafo[i][j] ) {
		grafo[i][j] = true;
		nodi[i].setArchi(nodi[i].getArchi() + 1);
		nodi[j].setArchi(nodi[j].getArchi() + 1);
	} else {
		__DEBUG("GrafoMatAd::insArco(): l'arco esiste");
		throw 1;
	}
};

template <class T, int DIM>
void GrafoMatAd<T, DIM>::cancNodo(NodoGrafo i) {
	if ( nodi[i].getEsiste() ) {
		nodi[i].setEsiste(false);
	} else {
		__DEBUG("GrafoMatAd::cancNodo(): il nodo non esiste");
		throw 0;
	}
};

template <class T, int DIM>
void GrafoMatAd<T, DIM>::cancArco(NodoGrafo i, NodoGrafo j) {
	if ( grafo[i][j] ) {
		grafo[i][j] = false;
	} else {
		__DEBUG("GrafoMatAd::cancArco(): l'arco non esiste");
		throw 0;
	}
};

template <class T, int DIM>
ListaPtr< typename GrafoMatAd<T,DIM>::NodoGrafo> GrafoMatAd<T, DIM>::adiacenti(NodoGrafo i) {
	ListaPtr<NodoGrafo> lista;
	lista.creaLista();
	for ( int j = 0; j < DIM; j++ )
		if ( grafo[i][j] )
			lista.insLista(j, lista.primoLista());
	return lista;
};

template <class T, int DIM>
bool GrafoMatAd<T, DIM>::getVisitato(NodoGrafo i) {
	return nodi[i].getVisitato();
};

template <class T, int DIM>
void GrafoMatAd<T, DIM>::setVisitato(bool b, NodoGrafo i) {
	nodi[i].setVisitato(b);
};

template <class T, int DIM>
T GrafoMatAd<T, DIM>::getLabel(NodoGrafo i) {
	if ( esisteNodo(i) ) {
		return nodi[i].getValue();
	} else {
		__DEBUG("GrafoMatAd::getLabel(): esisteNodo() = FALSE");
		throw 0;
	}
};

template <class T, int DIM>
void GrafoMatAd<T, DIM>::setLabel(T k, NodoGrafo i) {
	if ( esisteNodo(i) ) {
		nodi[i].getValue(k);
	} else {
		__DEBUG("GrafoMatAd::setLabel(): esisteNodo() = FALSE");
		throw 0;
	}
};

template <class T, int DIM>
int GrafoMatAd<T, DIM>::getArchi(NodoGrafo i){
	if ( esisteNodo(i) ) {
		return nodi[i].getArchi();
	} else {
		__DEBUG("GrafoMatAd::getArchi(): esisteNodo() = FALSE");
		throw 0;
	}
};

template <class T, int DIM>
void GrafoMatAd<T, DIM>::azzeraVisitato() {
	for (int i = 0; i < DIM; i++)
		nodi[i].setVisitato(false);
};

template <class T, int DIM>
int GrafoMatAd<T, DIM>::numNodi() {
	int count=0;
	for (int i=0; i<DIM; i++) {
		if (nodi[i].getEsiste())
			count++;
	}
	return count;
};

#endif
