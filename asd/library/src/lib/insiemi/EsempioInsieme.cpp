/*

Insieme insieme1 = creaInsieme()
Insieme insieme2 = creaInsieme()
tipoElem valoreIndicato;
integer i := 0
while i != 3
	visualizza "Indicare l'elemento da inserire (Insieme1): "
	valoreIndicato := leggi da tastiera
	insieme1.aggiungi(valoreIndicato)
	i := i + 1
endwhile
while i != 3
	visualizza "Indicare l'elemento da inserire (Insieme2): "
	valoreIndicato := leggi da tastiera
	insieme2.aggiungi(valoreIndicato)
	i := i + 1
endwhile
Insieme unione = insieme1.unione(insieme2)
Insieme intersezione = insieme1.intersezione(insieme2
Insieme differenza = insieme2.differenza(insieme2)
visualizza unione
visualizza intersezione
visualizza differenza

*/



#define ASDLIBRARY_DEBUG_ON true
#include "../common/stdInclude.h"
#include "InsiemeVetBol.h"

void EsempioInsiemiInsiemeVetBol() {
	InsiemeVetBol<int, 100> insieme1, insieme2;
	insieme1.creaInsieme();
	insieme2.creaInsieme();
	int valoreIndicato;
	for ( int i = 0; i < 3; i++ ) {
		cout << "Indicare l'elemento da inserire (Insieme1): ";
		cin >> valoreIndicato;
		insieme1.inserisci(valoreIndicato);
	}
	for ( int i = 0; i < 3; i++ ) {
		cout << "Indicare l'elemento da inserire (Insieme2): ";
		cin >> valoreIndicato;
		insieme2.inserisci(valoreIndicato);
	}
	InsiemeVetBol<int, 100> unione, intersezione, differenza;
	unione = insieme1.unione(insieme2);
	intersezione = insieme1.intersezione(insieme2);
	differenza = insieme1.differenza(insieme2);
	for ( int i = 0; i < 100; i++ )
		if ( unione.appartiene(i) ) cout << i << " ";
	cout << endl;
	for ( int i = 0; i < 100; i++ )
		if ( intersezione.appartiene(i) ) cout << i << " ";
	cout << endl;
	for ( int i = 0; i < 100; i++ )
		if ( differenza.appartiene(i) ) cout << i << " ";
	cout << endl;	
	
}

#include "InsiemeLDis.h"

void EsempioInsiemiInsiemeLDis() {
	InsiemeLDis<int> insieme1, insieme2;
	insieme1.creaInsieme();
	insieme2.creaInsieme();
	int valoreIndicato;
	for ( int i = 0; i < 3; i++ ) {
		cout << "Indicare l'elemento da inserire (Insieme1): ";
		cin >> valoreIndicato;
		insieme1.inserisci(valoreIndicato);
	}
	for ( int i = 0; i < 3; i++ ) {
		cout << "Indicare l'elemento da inserire (Insieme2): ";
		cin >> valoreIndicato;
		insieme2.inserisci(valoreIndicato);
	}
	InsiemeLDis<int> unione, intersezione, differenza;
	unione = insieme1.unione(insieme2);
	intersezione = insieme1.intersezione(insieme2);
	differenza = insieme1.differenza(insieme2);
	unione.mostraInsieme();
	intersezione.mostraInsieme();
	differenza.mostraInsieme();
}



