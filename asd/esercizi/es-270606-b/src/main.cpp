/*
Dato il tipo di dato astratto Grafo orientato realizzato con matrici di adiacenza in cui i nodi sono
etichettati con valori nell'isieme {RED. BLUE}, realizzare almeno due delle seguenti funzioni
(oltre a quelle di inserimento e stampa):
        REDGraph: restituisce il sottografo G' di G in cui tutti i nodi sono etichettati RED
    •
        BLUEGraph: restituisce il sottografo G' di G in cui tutti i nodi sono etichettati BLUE
    •
        Suggerimento: implementare l'operatore SUBGraph che restituisce il sottografo G' di G in
        cui tutti i nodi sono etichettati con valore x
        ACICLICO: stabilisce se un grafo G è aciclico
    •
        Suggerimento: utilizzare l'operatore ADIACENTI
        RBGraph: dato un grafo Red-Blue G determina il numero di nodi rispettivamente con
    •
        etichetta RED ed il numero di nodi con etichetta BLUE, e il numero di archi entranti
        rispettivamente nei nodi con etichetta RED e con etichetta BLUE
*/


#include "main.h"
#include "GrafoMatAdExt.h"
#include "CodaPtr.h"

typedef GrafoMatAdExt<string> Grafo;
typedef lpcell<int> * posizione;

Grafo SUBGraph( Grafo &g, string value ) {

	Grafo newG;
	
	
	newG.creaGrafo();
	for ( Nodo i = 0; i < MAXNODI; i++) {
		//cout<<"sono nel primo for!!!!!!!!!!"<<endl;
		if ( g.esisteNodo(i) ) {
			//cout<<"che faccio entro?"<<endl;
			if ( g.getLabel(i) == value ) {
				newG.insNodo(value, i);
				ListaPtr<Nodo> lAdiacenti;
				g.adiacenti(i, lAdiacenti);
				lpcell<Nodo> *nodo = lAdiacenti.primoLista();
				//cout<<"sto' per entrare"<<endl;
				while ( !lAdiacenti.fineLista(nodo) ) {
					if ( g.getLabel(lAdiacenti.leggiLista(nodo)) == value ) {
						//cout<<"sono dentro!!!!!!!!!!"<<endl;
						newG.insNodo(value, nodo->valore);
						newG.insArco(i, nodo->valore);
					}
					nodo = lAdiacenti.succLista(nodo); 
				}
			} 
		}
	}
	return newG;
}

GrafoMatAdExt<string> REDGraph( GrafoMatAdExt<string> &g ) {
	return SUBGraph(g, "red");
}

GrafoMatAdExt<string> BLUEGraph( GrafoMatAdExt<string> &g ) {
	return SUBGraph(g, "blu");
}



//???????????????????????


bool copiaCoda(CodaPtr<Nodo> &q, CodaPtr<Nodo> &r) {
     if (!q.codaVuota()) {
        CodaPtr<Nodo> s;
        Nodo a;
        while (!q.codaVuota()) {
           a=q.leggiCoda();
           r.inCoda(a);
           s.inCoda(a);
           q.fuoriCoda();
        }
        while (!s.codaVuota()) {
           a=s.leggiCoda();
           q.inCoda(a);
           s.fuoriCoda();
        }
        return true;
     } else return false;
};


bool ricercaCoda(Nodo a, CodaPtr<Nodo> &q) {
     bool trovato = false;
     if (!q.codaVuota()) {
        CodaPtr<Nodo> r; //appoggio per q
        copiaCoda(q, r);
        Nodo b;
        while (!(r.codaVuota() || trovato)) {
           b=r.leggiCoda();
           if (b == a)
              trovato = true;
           else
              r.fuoriCoda();
        }
     }
     return trovato;
};



bool camminoAperto(Nodo u, GrafoMatAdExt<string> &g) {
     if ((!g.grafoVuoto() && g.esisteNodo(u))) {
        CodaPtr<Nodo> q;
        Nodo v;
        Nodo corrente;
        string k;
        q.inCoda(u);
        g.setVisitato(true, u);
        q.fuoriCoda();
        ListaPtr<Nodo> l;
        g.adiacenti(u, l);
        lpcell<Nodo> *p = l.primoLista();
        while (!l.fineLista(p)) {
           v=l.leggiLista(p);
           if (!(g.getVisitato(v) || ricercaCoda(v, q))) {
              q.inCoda(v);
           }
           p = l.succLista(p);
        }
        while (!q.codaVuota()) {
           corrente=q.leggiCoda();
           if (corrente==u)
              return false;
		   g.setVisitato(true, corrente);
		   q.fuoriCoda();
		   ListaPtr<Nodo> l;
           g.adiacenti(corrente, l);
           lpcell<Nodo> *p = l.primoLista();
           while (!l.fineLista(p)) {
              v=l.leggiLista(p);
             if (!(ricercaCoda(v, q))) {
                 q.inCoda(v);
              }
              p = l.succLista(p);
           }
        }
        cout << endl;
        //g.azzeraVisitato();
     } else cout << "grafo vuoto, oppure non esiste il nodo" << endl;
     return true;
};


bool aciclico(GrafoMatAdExt<string> &g) {
     for ( int i = 1; i < MAXNODI; i++ ) {
     	if ( g.esisteNodo(i) && !g.getVisitato(i) ) {
	     	if ( !camminoAperto(i,g) ) {
	     		return false;
	     	}
     	}
     }
     g.azzeraVisitato();
     return true;
};   


void stampa (Grafo &g) {
	
	for (int i=1; i<MAXNODI; i++)
	{
		if (g.esisteNodo(i))
		{
		cout<<"l'ID del nodo e'"<<i<<"il suo valore e'"<<g.getLabel(i)<<endl;
		}
	}
	for (int i=1; i<MAXNODI; i++)
	{
		if (g.esisteNodo(i))
		{
			ListaPtr<Nodo> lAdiacenti;
 			g.adiacenti(i,lAdiacenti);
			if(!lAdiacenti.listaVuota())
			{
				posizione k=lAdiacenti.primoLista();
				while(!lAdiacenti.fineLista(k)){
					cout<<"("<<i<<","<<k->valore<<")"<<endl;
					k=lAdiacenti.succLista(k);
					//lAdiacenti.cancLista(lAdiacenti.predLista(k));	
				}
			
			}
		}
	}	

	
}


//???????????????????????



int main(int argc, char **argv) {
	Grafo g;
	g.creaGrafo();
	char risp = 's';
     int i, j;
     string k;
     cout << endl << "Inserimento nodi:" << endl;
     cout << "-----------------" << endl;
     while ((risp == 's') || (risp =='S')) {
        do {
           cout << "Inserisci numero nodo: ";
           cin >> i;
        } while (!((i >= 0) && (i < MAXNODI) && (!g.esisteNodo(i))));
        do {
           cout << "Inserisci label per il nodo " << i << ": ('red' o 'blu') ";
           cin >> k;
        } while (!((k == "red")||(k == "blu")||(k=="RED")||(k=="BLU")));
        g.insNodo(k, i);
        do {
           cout << "Altro nodo? (S/N) ";
           cin >> risp;
        } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
     }
     risp = 's';
     cout << endl;
     cout << "Inserimento archi:" << endl;
     cout << "------------------" << endl;
     while ((risp == 's') || (risp =='S')) {
        do {
           cout << "Inserisci numero nodo di partenza: ";
           cin >> i;
        } while (!((i >= 0) && (i < MAXNODI) && (g.esisteNodo(i))));
        do {
           cout << "Inserisci numero nodo di arrivo: ";
           cin >> j;
        } while (!((j >= 0) && (j < MAXNODI) && (g.esisteNodo(j))));
        if (g.esisteArco(i, j))
           cout << "Arco (" << i << ", " << j << ") esistente" << endl;
        else
           g.insArco(i, j);
        do {
           cout << "Altro arco? (S/N) ";
           cin >> risp;
        } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
     }
     stampa(g);
     Grafo f=REDGraph(g);
     stampa(f);
     
     if (aciclico(g))
     {cout<<"sono aciclico!!"<<endl;}
     else
     {cout<<"sono una merda volevo essere aciclico...sono stato un incidente di percorso"<<endl;}
     
     
     cout<<"ciao da santa e francesco"<<endl;
     
	
	
}
