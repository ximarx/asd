#define ASDLIBRARY_DEBUG_ON true
#include "../common/stdInclude.h"
#include "GrafoMatAd.h"

void EsempioGrafiGrafoMatAd() {
	GrafoMatAd<string, 4> grafo;
	GrafoMatAd<string, 4>::NodoGrafo nuovoNodo, nodoArrivo;
	string valoreIndicato;
	grafo.creaGrafo();
	for ( int i = 0; i < 4; i++ ) {
		cout << "Indica l'id del nodo: ";
		cin >> nuovoNodo;
		cout << "Indica il nome del computer: ";
		cin >> valoreIndicato;
		try {
			grafo.insNodo(valoreIndicato, nuovoNodo);
		} catch (int e) {
			cerr << "Id già esistente" << endl;
			i--;
		}
	}
	bool continuare = true;
	while ( continuare ) {
		cout << "Id computer di partenza: ";
		cin >> nuovoNodo;
		cout << "Id computer di arrivo: ";
		cin >> nodoArrivo;
		try {
			grafo.insArco(nuovoNodo, nodoArrivo);
		} catch ( int e) {
			cerr << "Arco già esistente" << endl;
		}
		cout << "Continuare? (S/N) ";
		cin >> valoreIndicato;
		if ( valoreIndicato != "S" )
			continuare = false;
	}
	cout << "Indicare l'id di cui si vogliono gli adiacenti: ";
	cin >> nuovoNodo;
	if ( grafo.esisteNodo(nuovoNodo) ) {
		GrafoMatAd<string, 4>::ListaAdiacenti lista = grafo.adiacenti(nuovoNodo);
		GrafoMatAd<string, 4>::ListaAdiacenti::posizione current = lista.primoLista();
		cout << "Adiacenti: ";
		while ( !lista.fineLista(current) ) {
			cout << grafo.getLabel(lista.leggiLista(current)) << " ";
			current = lista.succLista(current);
		}
		cout << endl;
	} else 
		cerr << "Id non esistente" << endl;
}
