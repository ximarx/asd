#ifndef DIZIONARIOHASHAPERTO_H_
#define DIZIONARIOHASHAPERTO_H_

#include "../common/stdInclude.h"
#include "../liste/ListaPtr.h"
#include "../liste/NodoListaPtr.h"
#include "NodoDizionarioHashAperto.h"

template <class K, class T, int DIM = 100>
class DizionarioHashAperto {
	public:
		DizionarioHashAperto();
		~DizionarioHashAperto();
		void creaDizionario();
		bool appartiene(K);
		void inserisci(K, T);
		void cancella(K);
		T recupera(K);
		void aggiorna(K, T);
		// metodi aggiunti interni
		void stampa();
		DizionarioHashAperto<K, T, DIM> copiaDizionario();
		//DizionarioHashAperto<K, T, DIM> operator=(DizionarioHashAperto<K, T, DIM>&);
	private:
		typedef NodoDizionarioHashAperto<K, T> NodoDizionario;
		typedef ListaPtr<NodoDizionario> listaTrabocco;
		typedef typename listaTrabocco::posizione posizioneListaTrabocco;
		int hashFunction(string);
		listaTrabocco dizionario[DIM];
};

template <class K, class T, int DIM>
DizionarioHashAperto<K, T, DIM>::DizionarioHashAperto() {
	creaDizionario();
};

template <class K, class T, int DIM>
DizionarioHashAperto<K, T, DIM>::~DizionarioHashAperto() {
	
	posizioneListaTrabocco corrente;
	
	for ( int i = 0; i < DIM; i++ ) {
		corrente = dizionario[i].primoLista();
		while ( !dizionario[i].fineLista(corrente) ) {
			dizionario[i].cancLista(corrente);
			corrente = dizionario[i].primoLista();
		}
	}
};

template <class K, class T, int DIM>
void DizionarioHashAperto<K, T, DIM>::creaDizionario() {
	for ( int i = 0; i < DIM; i++ ) {
		dizionario[i].creaLista();
	}
};

template <class K, class T, int DIM>
bool DizionarioHashAperto<K, T, DIM>::appartiene(K key) {
	int index = hashFunction(key);
	posizioneListaTrabocco corrente = dizionario[index].primoLista();
	while ( !dizionario[index].fineLista(corrente) ) {
		if ( dizionario[index].leggiLista(corrente).getKey() == key ) {
			return true;
		} 
	}
	return false;
};


template <class K, class T, int DIM>
void DizionarioHashAperto<K, T, DIM>::inserisci(K newKey, T newValue) {
	if ( !appartiene(newKey) ) {
		int index = hashFunction(newKey);
		NodoDizionario nuovoNodo = NodoDizionario(newKey, newValue);
		dizionario[index].insLista(nuovoNodo, dizionario[index].primoLista());
	} else {
		__DEBUG("DizionarioHashAperto::inserisci(): chiave gia' esistente");
		throw INT_MAX;
	}
};


template <class K, class T, int DIM>
void DizionarioHashAperto<K, T, DIM>::cancella(K key) {
	int index = hashFunction(key);
	posizioneListaTrabocco corrente = dizionario[index].primoLista();
	while ( !dizionario[index].fineLista(corrente) ) {
		if ( dizionario[index].leggiLista(corrente).getKey() == key ) {
			dizionario[index].cancLista(corrente);
			return;
		}
	}
	__DEBUG("DizionarioHashAperto::cancella(): chiave non trovata");
};

template <class K, class T, int DIM>
T DizionarioHashAperto<K, T, DIM>::recupera(K key) {
	int index = hashFunction(key);
	posizioneListaTrabocco corrente = dizionario[index].primoLista();
	while ( !dizionario[index].fineLista(corrente) ) {
		if ( dizionario[index].leggiLista(corrente).getKey() == key ) {
			return dizionario[index].leggiLista(corrente).getValue();
		}
	}
	__DEBUG("DizionarioHashAperto::recupera(): chiave non trovata");
	throw 0;
};

template <class K, class T, int DIM>
void DizionarioHashAperto<K, T, DIM>::aggiorna(K key, T newValue) {
	int index = hashFunction(key);
	posizioneListaTrabocco corrente = dizionario[index].primoLista();
	while ( !dizionario[index].fineLista(corrente) ) {
		if ( dizionario[index].leggiLista(corrente).getKey() == key ) {
			dizionario[index].leggiLista(corrente).setValue(newValue);
			return;
		}
	}
	__DEBUG("DizionarioHashAperto::aggiorna(): chiave non trovata");
	throw 0;
};

template <class K, class T, int DIM>
void DizionarioHashAperto<K, T, DIM>::stampa() {
	for ( int i = 0; i < DIM; i++ ) {
		if ( !dizionario[i].listaVuota() ) {
			posizioneListaTrabocco corrente = dizionario[i].primoLista();
			while ( !dizionario[i].fineLista(corrente) ) {
				NodoDizionario nodo = dizionario[i].leggiLista(corrente);
				cout << "Chiave: " << nodo.getKey() << " - ";
				cout << "Valore: " << nodo.getValue() << endl;
				corrente = dizionario[i].succLista(corrente);
			}
		}
	}
};

template <class K, class T, int DIM>
DizionarioHashAperto<K, T, DIM> DizionarioHashAperto<K, T, DIM>::copiaDizionario() {

	DizionarioHashAperto<K, T, DIM> nuovoD;
	nuovoD.creaDizionario();

	for ( int i = 0; i < DIM; i++ ) {
		if ( !dizionario[i].listaVuota() ) {
			posizioneListaTrabocco corrente = dizionario[i].primoLista();
			while ( !dizionario[i].fineLista(corrente) ) {
				NodoDizionario nodo = dizionario[i].leggiLista(corrente);
				nuovoD.inserisci(nodo.getKey(), nodo.getValue());
				corrente = dizionario[i].succLista(corrente);
			}
		}
	}
	return nuovoD;
};

template <class K, class T, int DIM>
int DizionarioHashAperto<K, T, DIM>::hashFunction(string keyString) {
     unsigned temp=0;
     for(int i=0; keyString[i]!='\0'; i++)
        temp = ((unsigned) keyString[i]) + (31*temp);
     return temp % DIM;
};

#endif /*DIZIONARIOHASHAPERTO_H_*/
