#define ASDLIBRARY_DEBUG_ON true

#include "../common/stdInclude.h"
#include "AlberoBin.h"

template <class T>
void inserisciInAlbero(T valore, AlberoBin<T> &albero, typename AlberoBin<T>::NodoAlbero nodo) {
	if ( albero.alberoVuoto() ) {
		albero.insRadice(valore);
	} else {
		if ( valore < albero.leggiNodo(nodo) ) {
			if ( albero.sxVuoto(nodo) ) {
				albero.scriviNodo(valore, albero.insFiglioSx(nodo));
			} else {
				inserisciInAlbero(valore, albero, albero.figlioSx(nodo));
			}
		} else if ( valore > albero.leggiNodo(nodo) ) {
			if ( albero.dxVuoto(nodo) ) {
				albero.scriviNodo(valore, albero.insFiglioDx(nodo));
			} else {
				inserisciInAlbero(valore, albero, albero.figlioDx(nodo));
			}
		}
	}
};

template <class T>
AlberoBin<T> acquisizioneOrdinata(int numElem) {
	AlberoBin<T> albero();
	T valoreInserito;
	for ( int i = 0; i < numElem; i++ ) {
		cout << "Indicare l'elemento da inserire: ";
		cin >> valoreInserito;
		inserisciInAlbero(valoreInserito, albero, albero.radice());
	}
	return albero;
};



template <class T>
void previsita(AlberoBin<T> albero, typename AlberoBin<T>::NodoAlbero nodo ) {
	cout << albero.leggiNodo(nodo) << " ";
	if ( !albero.sxVuoto(nodo) )
		previsita<T>(albero, albero.figlioSx(nodo));
	if ( !albero.dxVuoto(nodo) )
		previsita<T>(albero, albero.figlioDx(nodo));
};

template <class T>
void invisita(AlberoBin<T> albero, typename AlberoBin<T>::NodoAlbero nodo ) {
	if ( !albero.sxVuoto(nodo) )
		invisita<T>(albero, albero.figlioSx(nodo));
	cout << albero.leggiNodo(nodo) << " ";
	if ( !albero.dxVuoto(nodo) )
		invisita<T>(albero, albero.figlioDx(nodo));
};

template <class T>
void postvisita(AlberoBin<T> albero, typename AlberoBin<T>::NodoAlbero nodo ) {
	if ( !albero.sxVuoto(nodo) )
		postvisita<T>(albero, albero.figlioSx(nodo));
	if ( !albero.dxVuoto(nodo) )
		postvisita<T>(albero, albero.figlioDx(nodo));
	cout << albero.leggiNodo(nodo) << " ";
};

template <class T>
void stampa(AlberoBin<int> albero, AlberoBin<int>::NodoAlbero nodo) {
	cout << albero.leggiNodo(nodo) << "(";
	if ( !albero.sxVuoto(nodo) ) stampa<T>(albero, albero.figlioSx(nodo));
	cout << ")(";
	if ( !albero.dxVuoto(nodo) ) stampa<T>(albero, albero.figlioDx(nodo));
	cout << ")";
	if ( nodo == albero.radice() ) cout << endl;
};


template <class T>
typename AlberoBin<T>::NodoAlbero ricerca(T valore, AlberoBin<T> albero, typename AlberoBin<T>::NodoAlbero nodo) {
	typename AlberoBin<T>::NodoAlbero nodoTemp = NULL;
	if ( albero.leggiNodo(nodo) == valore ) {
		nodoTemp = nodo;
	} else {
		if ( !albero.sxVuoto(nodo) ) {
			nodoTemp = ricerca<T>(valore, albero, albero.figlioSx(nodo));
		}
		if ( !albero.dxVuoto(nodo) && nodoTemp == NULL ) {
			nodoTemp = ricerca<T>(valore, albero, albero.figlioDx(nodo));
		}
	}
	return nodoTemp;
}


#include "../code/CodaPtr.h"
template <class T>
void ampiezza(AlberoBin<T> albero, typename AlberoBin<T>::NodoAlbero nodo ) {
	CodaPtr<typename AlberoBin<T>::NodoAlbero> coda;
	typename AlberoBin<T>::NodoAlbero nodoLetto;
	coda.creaCoda();
	coda.inCoda(nodo);
	while ( !coda.codaVuota() ) {
		nodoLetto = coda.leggiCoda();
		if ( !albero.sxVuoto(nodoLetto) )
			coda.inCoda(albero.figlioSx(nodoLetto));
		if ( !albero.dxVuoto(nodoLetto) )
			coda.inCoda(albero.figlioDx(nodoLetto));
		cout << albero.leggiNodo(nodoLetto) << " ";
		coda.fuoriCoda();
	}
};

void EsempioAlberiAlgoritmiDiVisita() {
	AlberoBin<int> albero;
	albero.insRadice(1);
	albero.scriviNodo(2, albero.insFiglioSx(albero.radice()));
	albero.scriviNodo(3, albero.insFiglioDx(albero.radice()));
	stampa<int>(albero, albero.radice());
	cout << "Pre-visita: ";
	previsita<int>(albero, albero.radice());
	cout << endl;
	cout << "Post-visita: ";
	postvisita<int>(albero, albero.radice());
	cout << endl;
	cout << "In-visita: ";
	invisita<int>(albero, albero.radice());
	cout << endl;
	cout << "Ampiezza: ";
	ampiezza<int>(albero, albero.radice());
	cout << endl;	
};

template <class T>
int altezza(AlberoBin<T> albero, typename AlberoBin<T>::NodoAlbero nodo ) {
	int risSx = 0, risDx = 0;
	if ( albero.alberoVuoto() ) {
		return 0;
	} else {
		if ( !albero.sxVuoto(nodo) )
			risSx = 1 + altezza(albero, albero.figlioSx(nodo));
		if ( !albero.dxVuoto(nodo) )
			risDx = 1 + altezza(albero, albero.figlioDx(nodo));
		return (risSx >= risDx ? risSx : risDx);
	}
};

template <class T>
int profondita(AlberoBin<T> albero, typename AlberoBin<T>::NodoAlbero nodo) {
	int i = 0;
	while ( nodo != albero.radice() ) {
		i++;
		if ( (nodo = albero.padre(nodo)) == NULL ) throw INT_MAX; 
	}
	return i;
};


