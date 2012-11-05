#define ASDLIBRARY_DEBUG_ON true
#include "../common/stdInclude.h"
#include "AlberoN.h"


template <class T>
void stampa(AlberoN<T> albero, typename AlberoN<T>::NodoAlbero nodo) {
	cout << albero.leggiNodo(nodo);
	if ( !albero.foglia(nodo) ) {
		AlberoN<int>::NodoAlbero figlio = albero.primoFiglio(nodo);
		while ( !albero.ultimoFratello(figlio) ) {
			 cout << "(";
			 stampa(albero, figlio);
			 cout << ")";
			 figlio = albero.succFratello(figlio);
		}
	} else cout << "()";
};

template <class T>
void previsita(AlberoN<T> albero, typename AlberoN<T>::NodoAlbero nodo) {
	cout << albero.leggiNodo(nodo) << " ";
	if ( !albero.foglia(nodo) ) {
		AlberoN<int>::NodoAlbero figlio = albero.primoFiglio(nodo);
		while ( !albero.ultimoFratello(figlio) ) {
			 previsita(albero, figlio);
			 figlio = albero.succFratello(figlio);
		}
	}
};

template <class T>
void postvisita(AlberoN<T> albero, typename AlberoN<T>::NodoAlbero nodo) {
	if ( !albero.foglia(nodo) ) {
		AlberoN<int>::NodoAlbero figlio = albero.primoFiglio(nodo);
		while ( !albero.ultimoFratello(figlio) ) {
			 postvisita(albero, figlio);
			 figlio = albero.succFratello(figlio);
		}
	}
	cout << albero.leggiNodo(nodo) << " ";
};

template <class T>
void invisita(AlberoN<T> albero, typename AlberoN<T>::NodoAlbero nodo) {
	if ( !albero.foglia(nodo) ) {
		AlberoN<int>::NodoAlbero figlio = albero.primoFiglio(nodo);
		invisita(albero, figlio);
		cout << albero.leggiNodo(nodo) << " ";
		figlio = albero.succFratello(figlio);
		while ( !albero.ultimoFratello(figlio) ) {
			invisita(albero, figlio);
			figlio = albero.succFratello(figlio);
		}
	} else {
		cout << albero.leggiNodo(nodo) << " ";
	}
};

#include "../code/CodaPtr.h"
template <class T>
void ampiezza(AlberoN<T> albero, typename AlberoN<T>::NodoAlbero nodo) {
	CodaPtr<typename AlberoN<T>::NodoAlbero> coda;
	typename AlberoN<T>::NodoAlbero nodoLetto, nodoFiglio;
	coda.creaCoda();
	coda.inCoda(nodo);
	while ( !coda.codaVuota() ) {
		nodoLetto = coda.leggiCoda();
		nodoFiglio = albero.primoFiglio(nodoLetto);
		while ( !albero.ultimoFratello(nodoFiglio) ) {
			coda.inCoda(nodoFiglio);
			nodoFiglio = albero.succFratello(nodoFiglio);
		}
		cout << albero.leggiNodo(nodoLetto) << " ";
		coda.fuoriCoda();
	}
};

template <class T>
typename AlberoN<T>::NodoAlbero ricerca(T valore, AlberoN<T> albero, typename AlberoN<T>::NodoAlbero nodo) {
	typename AlberoN<T>::NodoAlbero nodoTrovato = NULL;
	if ( albero.leggiNodo(nodo) == valore ) {
		nodoTrovato = nodo;
	} else {
		if ( !albero.foglia(nodo) ) {
			AlberoN<int>::NodoAlbero figlio = albero.primoFiglio(nodo);
			while ( !albero.ultimoFratello(figlio) && nodoTrovato == NULL ) {
				 nodoTrovato = ricerca<T>(valore, albero, figlio);
				 figlio = albero.succFratello(figlio);
			}
		}
	}
	return nodoTrovato;
};

template <class T>
int altezza(AlberoN<T> albero, typename AlberoN<T>::NodoAlbero nodo ) {
	int massimo = 1, valoreCorrente = 0;
	if ( albero.alberoVuoto() ) {
		return 0;
	} else {
		typename AlberoN<T>::NodoAlbero figlioCorrente;
		figlioCorrente = albero.primoFiglio(nodo);
		while ( !albero.ultimoFratello(figlioCorrente) ) {
			valoreCorrente = 1 + altezza(albero, figlioCorrente);
			massimo = (valoreCorrente > massimo ? valoreCorrente : massimo);
			figlioCorrente = albero.succFratello(figlioCorrente);  
		}
		return massimo;
	}
};

template <class T>
int profondita(AlberoN<T> albero, typename AlberoN<T>::NodoAlbero nodo) {
	int i = 0;
	while ( nodo != albero.radice() ) {
		i++;
		if ( (nodo = albero.padre(nodo)) == NULL ) throw INT_MAX; 
	}
	return i;
}

void EsempioAlberiAlgoritmiVisita() {
	AlberoN<int> albero;
	albero.creaAlbero();
	int valoreIndicato;
	cout << "Indicare il valore della radice: ";
	cin >> valoreIndicato;
	AlberoN<int>::NodoAlbero radice = albero.insRadice(valoreIndicato);
	for ( int i = 0; i < 5; i++ ) {
		cout << "Indicare il valore da inserire nell'albero: ";
		cin >> valoreIndicato;
		albero.insFiglio(valoreIndicato, radice);
	}
	stampa(albero, albero.radice()); cout << endl;
	cout << "Pre-visita: "; previsita(albero, albero.radice()); cout << endl;
	cout << "Post-visita: "; postvisita(albero, albero.radice()); cout << endl;
	cout << "In-visita: "; invisita(albero, albero.radice()); cout << endl;
	cout << "Ampiezza: "; ampiezza(albero, albero.radice()); cout << endl;
	cout << "Trovato: " << albero.leggiNodo(ricerca(3, albero, albero.radice())) << endl;
	cout << "Altezza: " << altezza(albero, albero.primoFiglio(albero.radice())) << endl;
	cout << "Profondita: " << profondita(albero, albero.primoFiglio(albero.radice())) << endl;
};

void EsempioAlberiAlberoN() {
	AlberoN<int> albero;
	albero.creaAlbero();
	int valoreIndicato;
	cout << "Indicare il valore della radice: ";
	cin >> valoreIndicato;
	AlberoN<int>::NodoAlbero radice = albero.insRadice(valoreIndicato);
	for ( int i = 0; i < 5; i++ ) {
		cout << "Indicare il valore da inserire nell'albero: ";
		cin >> valoreIndicato;
		albero.insFiglio(valoreIndicato, radice);
	}
	stampa(albero, albero.radice());
}
