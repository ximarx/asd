#include "lib/lista/ListaSeq.h"
#include "lib/albero/BinAlberoCur.h"
#include <iostream>

using namespace std;

typedef ListaSeq Lista;
typedef BinAlberoCur Albero;

/**
 *     crea una lista costituita dai seguenti elementi: 4, 7, 9, 10, 13, 14, 15;
 */
Lista caricaElementi () {
	
	Lista lista = Lista();
	tipoelem el[7] = {4,7,9,10,13,14,15};
	
	for ( int i = 1; i < 8 ; i++ ) {
		lista.insLista(el[i-1], lista.pos(i));
	}
	
	
	return lista;
}

/**
 * int lunghezza (Lista l, pos inizio, pos fine) – restituisce la lunghezza della sottolista l' di l
 * costituita dagli elementi ordinati compresi tra le posizioni inizio e fine della lista l;
 */
int lunghezza(Lista lista, posizione start, posizione end) {
	
	int i = 0;
	posizione p = start;
	while ( p != end ) {
		p = lista.succLista(p);
		i++;
	}
	return i;
}

/**
 * pos salta (Lista l, pos inizio, int k) – restituisce la posizione dell'elemento della lista l
 * ottenuta saltando k elementi a partire dalla posizione inizio;
 */
posizione salta(Lista lista, posizione start, int k) {
	
	posizione p = start;
	for ( int i = 0; i < k;  i++ ) {
		p = lista.succLista(p);
	} 
	return p;
}

/**
 * pos mediano (Lista l, pos inizio, pos fine) – restituisce la posizione dell'elemento
 * mediano della lista l; (suggerimento: utilizzare le funzioni/metodi lunghezza e salta);
 */
posizione mediano(Lista lista, posizione start, posizione end) {
	
	int lunghezzaSottolista = lunghezza( lista, start, end);
	lunghezzaSottolista = lunghezzaSottolista / 2;
	return salta(lista, start, lunghezzaSottolista);
} 


/**
 * Lista creaSottoLista(Lista l, pos inizio, pos fine) – restituisce la sottolista l' di l costituita
 * dagli elementi compresi tra le posizioni inizio e fine della lista l;
 */
Lista creaSottoLista(Lista lista, posizione inizio, posizione fine) {
	
	Lista nuovaLista = Lista();
	posizione current = inizio;
	int i = 1;
	tipoelem letto;
	while ( current != fine ) {
		lista.leggiLista(letto, current);
		nuovaLista.insLista(letto, nuovaLista.pos(i));
		current = lista.succLista(current);
		i++;
	}
	return nuovaLista;
}

void stampaLista(Lista lista) {

	tipoelem letto;
	
	posizione p = lista.primoLista();
	while ( !lista.fineLista(p) ) {
		lista.leggiLista(letto, p);
		cout << letto << " ";	
		p = lista.succLista(p);
	}
	
}

/**
 * Riempie ricorsivamente un sotto-albero in base all'elemento
 * da inserire
 * [FUNZIONE_PRIVATA]
 */
void private_riempiAlbero(Lista lista, int lunghezzaLista, Albero &t, nodoBin nodoRiferimento) {
	
	tipoelem elemento;
	posizione p;
	nodoBin nuovoRiferimentoSx, nuovoRiferimentoDx;
	Lista listaSx, listaDx;
	int lSottolistaSx, lSottolistaDx;
	
	// 1: calcola il mediano e lo scrive nel nodo di riferimento
	p = mediano(lista,lista.primoLista(), lista.pos(lunghezzaLista));
	lista.leggiLista(elemento, p);
	t.scriviNodo(nodoRiferimento, elemento);
	// :1
	// 2: calcola la sottolista sinistra in base al mediano
	listaSx = creaSottoLista(lista, lista.primoLista(), p);
	lSottolistaSx = lunghezza(lista, lista.primoLista(), p);
	// 2.1: controlla che abbia senso avviare una ricorsione
	if ( lSottolistaSx > 0 ) {
		t.insFiglioSx(nodoRiferimento);
		nuovoRiferimentoSx = t.figlioSx(nodoRiferimento);
		// 2.1.1 Se la lista ha 1 solo elemento, allora è una foglia
		if ( lSottolistaSx == 1 ) {
			listaSx.leggiLista(elemento, listaSx.primoLista());
			t.scriviNodo(nuovoRiferimentoSx, elemento);
		// :2.1.1
		// 2.1.2 Se la lista ha piu di un elemento allora avvia la ricorsione
		} else {
			private_riempiAlbero(listaSx, lSottolistaSx, t, nuovoRiferimentoSx);
		}
		// :2.1.2
	}
	// :2.1
	// 3: calcola la sottolista destra analogamente a quella sinistra
	listaDx = creaSottoLista(lista, lista.succLista(p), salta(lista, lista.primoLista(), lunghezzaLista));
	lSottolistaDx = lunghezzaLista / 2;
	if ( lSottolistaDx > 0 ) {		
		t.insFiglioDx(nodoRiferimento);
		nuovoRiferimentoDx = t.figlioDx(nodoRiferimento);
		if ( lSottolistaDx == 1 ) {
			listaDx.leggiLista(elemento, listaDx.primoLista());
			t.scriviNodo(nuovoRiferimentoDx, elemento);
		} else {
			private_riempiAlbero(listaDx, lSottolistaDx, t, nuovoRiferimentoDx );
		}
	}
	// :3
	return;
}

/**
 * Albero caricaAlberoBinario(Lista l) – costruisce un albero binario di ricerca utilizzando gli
 * elementi presenti nella lista ordinata;
 * Algoritmo per caricare l'albero binario:
 * T = caricaAlberoBinario(partizione sinistra di L rispetto a mediano(L))
 * U = caricaAlberoBinario(partizione destra di L rispetto a mediano(L))
 * T' = costrBinAlbero(T,U) in cui la radice u di T' è mediano(L)
 */
Albero caricaAlberoBinario(Lista lista) {
	
	nodoBin radice = 0;
	int lunghezzaLista = 0;
	Albero albero = Albero();
	posizione ultimo = lista.primoLista();
	
	while ( !lista.fineLista(ultimo) ) {
		ultimo = lista.succLista(ultimo);
	}
	
	radice = 0;
	albero.insBinRadice(radice);
	
	lunghezzaLista = lunghezza(lista, lista.primoLista(), ultimo);
	
	private_riempiAlbero(lista, lunghezzaLista, albero, radice);
	
	return albero;
	
}

// routine temporanea per la visualizzazione dell'albero
void stampaBinAlbero(nodoBin p, Albero &t){
	if (p != NIL){
      tipoelem a;
      t.leggiNodo(p, a);
    	cout << "(" << a;
		if (!t.sxVuoto(p)){
			stampaBinAlbero(t.figlioSx(p), t);
		} else cout << "()";
		if (!t.dxVuoto(p)){
			stampaBinAlbero(t.figlioDx(p), t);
		} else cout << "()";
		cout << ")";
	}
}

int main(int argc, char **argv) {
	
	ListaSeq lista = caricaElementi();
	
	cout << "Lista inserita: ";
	stampaLista(lista);	
	cout << endl;
	
	Albero albero = caricaAlberoBinario(lista);
	
	stampaBinAlbero(albero.binRadice(), albero);
	
}
