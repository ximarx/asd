
#ifndef TESTLISTACUR_CPP_
#define TESTLISTACUR_CPP_

#include "../common/stdInclude.h"
#include "ListaCur.h"


void TestListaCur() {

	
	ListaCur<int, 10> lista = ListaCur<int, 10>();
	
	ListaCur<int, 10>::posizione p = lista.primoLista();
	
	p = lista.primoLista();
	
	for ( int i = 0; i < 10; i++ ) {
		lista.insLista(i * 100, p);
		p = lista.succLista(p);
	}
	
	try {
		// genera eccezione
		lista.insLista(100 * 100, p);
	} catch ( int e ) {
		// cattura overflow
		p = lista.precLista(p);
		lista.cancLista(p);
		lista.insLista(123 * 200, p);
	}
	
	lista.scriviLista(1, lista.primoLista());
	
	p = lista.primoLista();
	while ( !lista.fineLista(lista.succLista(p)) ) {
		p = lista.succLista(p);
	} 
	
	lista.scriviLista(INT_MAX, p );
	//lista.scriviLista(INT_MAX / 2, p / 2);

	p = lista.primoLista();
	while ( !lista.fineLista(p) ) {
		cout << "Elemento " << p << " - valore: " << lista.leggiLista(p) << endl;
		p = lista.succLista(p);
	}
	
}

#endif
