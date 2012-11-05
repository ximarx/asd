/**


Coda coda := creaCoda()
tipoElem valoreIndicato;
integer i := 0
while i != 6
	visualizza "Indicare l'elemento da inserire: "
	valoreIndicato := leggi da tastiera  
	coda.inCoda(valoreIndicato)
	i := i + 1
endwhile

i := 0;
while i != 4
	visualizza coda.leggiCoda()
	visualizza " "
	coda.fuoriCoda()
endwhile


*/

#include "../common/stdInclude.h"
#include "CodaPtr.h"

void EsempioCodeCodaPtr() {

	CodaPtr<int> coda;
	coda.creaCoda();
	int valoreIndicato;
	// acquisizione
	for ( int i = 0; i < 6; i++ ) {
		cout << "Indicare l'elemento da inserire: ";
		cin >> valoreIndicato;
		coda.inCoda(valoreIndicato);
	}
	// stampa
	for ( int i = 0; i < 4; i++ ) {
		cout << coda.leggiCoda() << " ";
		coda.fuoriCoda();
	}
	
}


#include "../common/stdInclude.h"
#include "CodaVet.h"

void EsempioCodeCodaVet() {

	CodaPtr<int> coda;
	coda.creaCoda();
	int valoreIndicato;
	// acquisizione
	for ( int i = 0; i < 6; i++ ) {
		cout << "Indicare l'elemento da inserire: ";
		cin >> valoreIndicato;
		coda.inCoda(valoreIndicato);
	}
	// stampa
	for ( int i = 0; i < 4; i++ ) {
		cout << coda.leggiCoda() << " ";
		coda.fuoriCoda();
	}
	
}

template <class T>
CodaPtr<T> acquisizioneCoda(int QueueLength) {
	CodaPtr<T> coda;
	coda.creaCoda();
	T valoreIndicato;
	for ( int i = 0; i < QueueLength; i++ ) {
		cout << "Indicare l'elemento da inserire: ";
		cin >> valoreIndicato;
		coda.inCoda(valoreIndicato);
	}
	return coda;
};


template <class T>
void stampa(CodaPtr<T> coda ) {
	while ( !coda.codaVuota() ) {
		cout << coda.leggiCoda() << " ";
		coda.fuoriCoda();
	}
};

template <class T>
CodaPtr<T> copia(CodaPtr<T> coda) {
	CodaPtr<T> copiaCoda, codaAppoggio;
	while ( !coda.codaVuota() ) {
		copiaCoda.inCoda(coda.leggiCoda());
		codaAppoggio.inCoda(coda.leggiCoda());
		coda.fuoriCoda();
	}
	while ( !codaAppoggio.codaVuota() ) {
		coda.inCoda(codaAppoggio.leggiCoda());
		codaAppoggio.fuoriCoda();
	}
	return copiaCoda;
};

template <class T>
bool ricerca(CodaPtr<T> coda, T valore) {
	while ( !coda.codaVuota() ) {
		if ( coda.leggiCoda() == valore ) return true;
		coda.fuoriCoda();
	}
	return false;
};
