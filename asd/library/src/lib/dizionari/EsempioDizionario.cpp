
#define ASDLIBRARY_DEBUG_ON true
#include "../common/stdInclude.h"
#include "DizionarioHashAperto.h"

void EsempioDizionariDizionarioHashAperto() {
	DizionarioHashAperto<string, string> dizionario;
	dizionario.creaDizionario();
	string chiave, valore;
	for ( int i = 0; i < 4; i++ ) {
		try {
			cout << "Indicare il termine: ";
			cin >> chiave;
			cout << "Indicare il contrario: ";
			cin >> valore;
			dizionario.inserisci(chiave, valore);
		} catch ( int e ) {
			cout << "Il termine esiste già!";
			i--;
		}
	}
	cout << "Indicare il termine di cui si vuole conoscere il contrario: ";
	cin >> chiave;
	
	if ( dizionario.appartiene(chiave) ) {
		cout << "Il contrario di " << chiave << " e' ";
		cout << dizionario.recupera(chiave) << endl;
	} else {
		cout << "Termine non in dizionario";
	}
	dizionario.stampa();
}
