#ifndef TESTLISTAVET_CPP_
#define TESTLISTAVET_CPP_

#include "../common/stdInclude.h"
#include "ListaVet.h"

bool TestListaVet() {
	
	bool testRiuscito = true;
	int risultatiValidi = 0;
	int risultatiFalliti = 0;
	string nomeFunzione;
	
	cout << endl;
	cout << "-------------------------" << endl;
	cout << "- Test unit: ListaVet.h " << endl;
	cout << "-------------------------" << endl;
	cout << endl;
	
	
	ListaVet<int, 10> lista;
	
	try {
		nomeFunzione = "creaLista()";
		lista.creaLista();
		risultatiValidi++;
		cout << "Test " << nomeFunzione << " riuscito" << endl;
	} catch (int i) {
		cout << "Test " << nomeFunzione << " fallito" << endl;
		testRiuscito = false;
		risultatiFalliti++;
	}

	nomeFunzione = "listaVuota() {con lista vuota}";
	if ( lista.listaVuota() ) {
		cout << "Test " << nomeFunzione << " riuscito" << endl;
		risultatiValidi++;
	} else {
		cout << "Test " << nomeFunzione << " fallito" << endl;
		testRiuscito = false;
		risultatiFalliti++;
	}
	
	nomeFunzione = "primoLista() {con lista vuota}";
	if ( lista.primoLista() == 1 ) {
		cout << "Test " << nomeFunzione << " riuscito" << endl;
		risultatiValidi++;
	} else {
		cout << "Test " << nomeFunzione << " fallito" << endl;
		testRiuscito = false;
		risultatiFalliti++;
	}

	
	
	
	cout << endl;
	cout << "##########################" << endl;
	cout << "# Esito: " << ( testRiuscito ?  "RIUSCITO" : "FALLITO" ) << endl;
	cout << "#     riusciti: " << risultatiValidi << endl;
	cout << "#     falliti: " << risultatiFalliti << endl;
	cout << "##########################" << endl;
	cout << endl;
	return testRiuscito;
	
};


void testAlternativo() {

	ListaVet<int, 10> lista;
	lista.creaLista();
	
	ListaVet<int, 10>::posizione p;
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
		lista.insLista(100 * 100, p);
	}
	
	lista.scriviLista(1, lista.primoLista());
	lista.scriviLista(INT_MAX, p);
	lista.scriviLista(INT_MAX / 2, p / 2);


	p = lista.primoLista();
	while ( !lista.fineLista(p) ) {
		cout << "Elemento " << p << " - valore: " << lista.leggiLista(p) << endl;
		p = lista.succLista(p);
	}

	
} 

#endif
