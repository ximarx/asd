#ifndef TESTALBEROBIN_CPP_
#define TESTALBEROBIN_CPP_



#include "../common/stdInclude.h"
#include "AlberoBin.h"

void stampaAlberoBinInt(AlberoBin<int> albero, AlberoBin<int>::NodoAlbero nodo) {

	int value = albero.leggiNodo(nodo);
	cout << value << "(";
	if ( !albero.sxVuoto(nodo) ) {
		stampaAlberoBinInt(albero, albero.figlioSx(nodo));
	}
	cout << ")(";
	if ( !albero.dxVuoto(nodo) ) {
		stampaAlberoBinInt(albero, albero.figlioDx(nodo));
	}
	cout << ")";
	if ( nodo == albero.radice() ) {
		cout << endl;
	}

}

void TestAlberoBin(int argc, char **argv) {

	AlberoBin<int> albero;
	albero.creaAlberoBin();
	
	int i = 0;
	
	AlberoBin<int>::NodoAlbero radice = albero.insRadice(i++);

	AlberoBin<int>::NodoAlbero nodoGenerico = albero.insFiglioDx(radice);
	albero.scriviNodo(i++, nodoGenerico);

	nodoGenerico = albero.insFiglioSx(radice);
	albero.scriviNodo(i++, nodoGenerico);
	
	nodoGenerico = albero.insFiglioSx(nodoGenerico);
	albero.scriviNodo(i++, nodoGenerico);
	
	
	cout << "Inserimento ok" << endl;
	
	cout << "Stampa albero: " << endl;
	
	if ( !albero.alberoVuoto() ) stampaAlberoBinInt(albero, albero.radice());
	
	cout << "Fine stampa" << endl;

};


#endif /*TESTALBEROBIN_CPP_*/
