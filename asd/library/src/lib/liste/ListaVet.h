#ifndef LISTAVET_H_
#define LISTAVET_H_


#include "../common/stdInclude.h"
#include "../common/Nodo.h"

template <class T, int DIM = 100>
class ListaVet {
	public:
		// typedef per posizione
		// controllare se da esterno e' valido:
		// ListaVet<T,DIM>::posizione
		typedef int posizione;
	
		ListaVet();  // costruttore
		~ListaVet();  // distruttore
		
		// operatori
		void creaLista();
		bool listaVuota();
		T leggiLista(posizione);
		void scriviLista(T, posizione);
		posizione primoLista();
		posizione succLista(posizione);
		posizione precLista(posizione);
		bool fineLista(posizione);
		void insLista(T, posizione);
		void cancLista(posizione);
		
	private:
		Nodo<T> lista[DIM];
		int lunghezza;
};


template <class T, int DIM>
ListaVet<T,DIM>::ListaVet() {
	creaLista();
};

template <class T, int DIM>
ListaVet<T,DIM>::~ListaVet() {};

template <class T, int DIM>
void ListaVet<T,DIM>::creaLista() {
	lunghezza = 0;
};

template <class T, int DIM>
bool ListaVet<T,DIM>::listaVuota() {
	return (lunghezza == 0);
};

template <class T, int DIM>
T ListaVet<T,DIM>::leggiLista(posizione pos) {
	if ( listaVuota() ) {
		__DEBUG("ListaVet::leggiLista(): listaVuota() e' TRUE");
		throw 0;
	} else if ( fineLista(pos) ) {
		__DEBUG("ListaVet::leggiLista(): POS e' fineLista");
		throw INT_MAX;
	} else {
		return lista[pos - 1].getValue();
	}
};

template <class T, int DIM>
void ListaVet<T,DIM>::scriviLista(T newValue, posizione pos) {
	if ( listaVuota() ) {
		__DEBUG("ListaVet::scriviLista(): listaVuota() e' TRUE");
	} else if ( fineLista(pos) ) {
		__DEBUG("ListaVet::scriviLista(): POS e' fineLista()");
	} else if ( pos < primoLista() ) {
		__DEBUG("ListaVet::scriviLista(): POS < primoLista()");
	} else {
		lista[pos-1].setValue(newValue);
	}
};

template <class T, int DIM>
int ListaVet<T,DIM>::primoLista() {
	return 1;
};

template <class T, int DIM>
int ListaVet<T,DIM>::succLista(posizione pos) {
	if ( !fineLista(pos) ) {
		return pos + 1;
	} else {
		return pos;
	}
};

template <class T, int DIM>
int ListaVet<T,DIM>::precLista(posizione pos) {
	if ( pos > primoLista() ) {
		return pos - 1;
	} else {
		return primoLista();
	}
}

template <class T, int DIM>
bool ListaVet<T, DIM>::fineLista(posizione pos) {
	if ( lunghezza == pos - 1) {
		return true;
	} else if ( lunghezza < pos - 1 ) {
		__DEBUG("ListaVet::fineLista(): POS > lunghezza");
		return true;
	} else {
		return false;
	}
}

template <class T, int DIM>
void ListaVet<T, DIM>::insLista(T newValue, posizione pos) {
	if ( lunghezza >= DIM ) {
		__DEBUG("ListaVet::insLista(): dimensione massima raggiunta");
		throw INT_MAX;
	} else if ( pos < primoLista() || pos > lunghezza + 1 ) {
		__DEBUG("ListaVet::insLista(): POS < primoLista() || POS > lunghezza");
		throw 0;
	} else {
		for ( int i = lunghezza; i >= pos; i-- ) {
			lista[i] = lista[i-1];
		}
		lista[pos-1] = Nodo<T>(newValue);
		lunghezza++;
	}
}

template <class T, int DIM>
void ListaVet<T, DIM>::cancLista(posizione pos) {
	if ( listaVuota() ) {
		__DEBUG("ListaVet::cancLista(): listaVuota e' TRUE");
		throw 0;
	} else if ( pos > lunghezza || pos < primoLista() ) {
		__DEBUG("ListaVet::cancLista(): POS non valida ");
		throw INT_MAX;
	} else {
		posizione pp = precLista(pos);
		while ( !fineLista(succLista(pp)) ) {
			scriviLista(leggiLista(succLista(pp)), pp);
			pp = succLista(pp); 
		}
		lunghezza--;
	}
}

#endif /*LISTAVET_H_*/
