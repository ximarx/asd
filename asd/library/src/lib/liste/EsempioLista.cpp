
/*

Lista lista := creaLista()
tipoElem valoreIndicato
integer i := 0
Posizione doveInserire := lista.primoLista()
while i != 10
	visualizza "Indicare l'elemento da inserire"
	valoreIndicato := leggi da tastiera
	lista.insLista(valoreIndicato, doveInserire)
	doveInserire := lista.succLista(doveInserire)
	i := i + 1
endwhile

Posizione daVisualizzare := lista.primoLista()
while lista.fineLista(daVisualizzare) = true
	visualizza lista.leggiLista(daVisualizzare)
	daVisualizzare := lista.succLista(daVisualizzare)
endwhile

Lista dispari := creaLista()
Posizione daControllare := lista.primoLista()
while lista.fineLista(daControllare) = true
	tipoElem letto := leggiLista(daControllare)
	if letto % 2 = 0 // % : divisione in modulo
		doveInserire := dispari.primoLista()
		dispari.insLista( letto, doveInserire)
	endif
	daControllare := lista.succLista(daVisualizzare)
endwhile


Posizione daVisualizzare := dispari.primoLista()
while dispari.fineLista(daVisualizzare) = true
	visualizza dispari.leggiLista(daVisualizzare)
	daVisualizzare := dispari.succLista(daVisualizzare)
endwhile


*/

#include "../common/stdInclude.h"
#include "ListaVet.h"


template <class T, int DIM>
ListaVet<T, DIM> acquisizione() {
	typedef ListaVet<T, DIM> Lista;
	typedef typename ListaVet<T, DIM>::posizione Posizione;
	
	Lista lista;
	Posizione corrente;
	T valore;
	
	lista.creaLista();
	corrente = lista.primoLista();
	for ( int i = 0; i < DIM; i++ ) {
		cout << "Indicare l'elemento da inserire in lista: ";
		cin >> valore;
		lista.insLista(valore, corrente);
		corrente = lista.succLista(corrente);
	}
	return lista;
};

template <class T, int DIM>
void stampa(ListaVet<T, DIM> lista) {
	typename ListaVet<T, DIM>::posizione corrente = lista.primoLista();
	while ( !lista.fineLista(corrente) ) {
		cout << lista.leggiLista(corrente) << " "; 
	}
	cout << endl;
};

template <class T, int DIM>
typename ListaVet<T, DIM>::posizione ricerca(ListaVet<T, DIM> lista, T valore) {
	typename ListaVet<T, DIM>::posizione corrente = lista.primoLista();
	while ( !lista.fineLista(corrente) ) {
		if ( lista.leggiLista(corrente) == valore ) {
			return corrente;
		} 
	}
	throw 0;
};



void EsempioListeListaVet() {
	
	ListaVet<int, 10> lista;
	lista.creaLista();
	// creazione lista
	int valoreIndicato;
	ListaVet<int, 10>::posizione doveInserire = lista.primoLista();
	for ( int i = 0; i < 10; i++ ) {
		cout << "Numero da aggiungere alla lista: ";
		cin >> valoreIndicato;
		lista.insLista(valoreIndicato, doveInserire);
		doveInserire = lista.succLista(doveInserire);
		
	}
	// visualizzazione lista
	ListaVet<int, 10>::posizione daVisualizzare = lista.primoLista();
	while ( !lista.fineLista(daVisualizzare) ) {
		cout << lista.leggiLista(daVisualizzare) << " ";
		daVisualizzare = lista.succLista(daVisualizzare);
	}
	cout << endl;
	// lista dispari
	int letto;
	ListaVet<int, 10> dispari;
	dispari.creaLista();
	ListaVet<int, 10>::posizione daControllare = lista.primoLista();
	while ( !lista.fineLista(daControllare) ) {
		letto = lista.leggiLista(daControllare);
		if ( letto % 2 != 0 ) {
			dispari.insLista(letto, dispari.primoLista());
		}
		daControllare = lista.succLista(daControllare);
	}
	// visualizzazione dispari
	daVisualizzare = dispari.primoLista();
	while ( !dispari.fineLista(daVisualizzare) ) {
		cout << dispari.leggiLista(daVisualizzare) << " ";
		daVisualizzare = dispari.succLista(daVisualizzare);
	}
	cout << endl;
	
	
}
