#include <cstdlib>
#include <iostream>
#include "BinAlbero.h"
#include "CodaPtr.h"

/*
Implementare la struttura dati Albero binario di ricerca in cui ogni nodo contiene un
intervallo chiuso (coppia ordinata di numeri reali [t1, t2], con t1.t2). Possiamo rappresentare
un intervallo [t1, t2] come un oggetto i, con i campi low[i] = t1 (estremo inferiore) e high[i] = t2
(estremo superiore). Per ogni nodo x dell'albero la chiave di x e l'estremo inferiore, low[x],
dell'intervallo. Realizzare i seguenti operatori:
                 
. Cerca-Intervallo(T: albero-bin, i: intervallo): nodo
trova un nodo nell'albero T il cui intervallo si sovrappone all'intervallo i (due intervalli
a e b si sovrappongono se low[a].high[b] e low[b].high[a])

. Min-Intervallo(T: albero-bin, i: real): nodo
trova il nodo x nell'albero T il cui intervallo contiene il numero i ed ha la minima
ampiezza (high[x]-low[x]) fra tutti gli intervalli che contengono i

. Max(T: albero-bin, n: nodo): real
restituisce un valore che e il massimo tra tutti gli estremi degli intervalli memorizzati
nel sottoalbero con radice in n
*/



using namespace std;

void riempiBinAlbero(tipoelem a, nodoBin n, BinAlbero &t){
   if (n != NULL){
      tipoelem b;
      t.leggiNodo(n, b);
      if (a.low < b.low){
         if (t.sxVuoto(n)){
            t.insFiglioSx(n);
            t.scriviNodo(t.figlioSx(n), a);
         } else riempiBinAlbero(a, t.figlioSx(n), t);
      } else if (a.low > b.low){
         if (t.dxVuoto(n)){
            t.insFiglioDx(n);
            t.scriviNodo(t.figlioDx(n), a);            
         } else riempiBinAlbero(a, t.figlioDx(n), t);
      } else cout << "Elemento esistente: [" << a.low <<","<<a.high<<"]"<<endl;      
   } else {
      n = new NodoBinPtr();
      t.insBinRadice(n);
      t.scriviNodo(t.binRadice(), a);
   }
}

void stampaBinAlbero(nodoBin p, BinAlbero &t){
	if (p != NULL){
      tipoelem a;
      t.leggiNodo(p, a);
    	cout << "(" << "["<<a.low<<","<<a.high<<"]";
		if (!t.sxVuoto(p)){
			stampaBinAlbero(t.figlioSx(p), t);
		} else cout << "()";
		if (!t.dxVuoto(p)){
			stampaBinAlbero(t.figlioDx(p), t);
		} else cout << "()";
		cout << ")";
	}
}

nodoBin cerca (float inf, float sup, nodoBin p, BinAlbero t){
	nodoBin temp;
	tipoelem b;
	tipoelem a; 
	cout << "Muoio 2" << endl;
    if (p != NULL){
	      cout << "Muoio 3" << endl;
	      t.leggiNodo(p, a);
	      cout << "Muoio 4" << endl;
	      if (a.low==inf && a.high==sup){
	      		cout << "Muoio 5" << endl;
	                     return (p);
	      } else {
	      	cout << "Muoio 6" << endl;
			if (!t.sxVuoto(p)){
				cout << "Muoio 7" << endl;
				temp=cerca(inf, sup,t.figlioSx(p), t);
				cout << "Muoio 8" << endl;
				if (temp!=NULL) {
					cout << "Muoio 9" << endl;
				    return temp;
				}
			}
			cout << "Muoio 10" << endl;
			if (!t.dxVuoto(p)){
				cout << "Muoio 11" << endl;
				temp=cerca(inf, sup,t.figlioDx(p), t);
				cout << "Muoio 12" << endl;
				if (temp != NULL){
					cout << "Muoio 13" << endl;
					//cout << "Controllo: " << temp->getEtichetta().low << endl;
				    //t.leggiNodo(temp,b);
		      		//cout << b.low << " BRUTTTTTOOO BASTARDO" << endl;
				    //float h= b.high;
				    //float c= b.low;
	                //return temp;
	                return NULL;
	            }
			}
			cout << "Muoio 14" << endl;
			return NULL;
		}
	} else {
		 return NULL;
    }
}

void preVisita (nodoBin p, BinAlbero t, CodaPtr &c, float input)
{
	if (p != NULL){
      tipoelem a;
      t.leggiNodo(p, a);
      if (a.low<=input && a.high>=input)
           {
            cout <<"da in serire in coda ["<< a.low<<","<<a.high<<"]"<<endl;
            c.inCoda(a);
            cout<< "elemento k dopo " << a.low<<endl;              
           }
		if (!t.sxVuoto(p)){
			preVisita(t.figlioSx(p), t,c,input);
		        }
		if (!t.dxVuoto(p)){
			preVisita(t.figlioDx(p), t,c,input);
	        	}
         }
}

/*
void ampiezzaBin(nodoBin p, BinAlbero &t){
   	CodaPtr q;
   	q.inCoda(p);
   	while (!q.codaVuota()){
      	q.leggiCoda(p);
      	tipoelem a;
      	t.leggiNodo(p,a);
		cout << a << " ";
		q.fuoriCoda();
    	if (!t.sxVuoto(p)){
			q.inCoda(t.figlioSx(p));
		}
		if (!t.dxVuoto(p)){
			q.inCoda(t.figlioDx(p));
		}
   }
}

bool trovaParola(tipoelem &a, nodoBin n, BinAlbero &t, int &i, nodoBin &pota){
   if (n != NULL){
      tipoelem b;
      t.leggiNodo(n, b);
      if (a < b){
         if (!t.sxVuoto(n)) 
            return (false || trovaParola(a, t.figlioSx(n), t, ++i, pota));
         else return false;
      } else if (a > b){
         if (!t.dxVuoto(n))
            return (false || trovaParola(a, t.figlioDx(n), t, ++i, pota));
         else return false;
      } else {
         pota = n;
         return true;
      }      
   } else return false;
}
*/
void inserisciBinAlbero(BinAlbero &t){
   char risp = 's';int i=1;
   tipoelem a;
   while ((risp == 's') || (risp == 'S')){
      cout << "Inserisci " <<i<< " elemento, estremo inferiore: ";
      cin >> a.low;
      cout << "Inserisci " <<i<< " elemento, estremo superiore: ";
      cin >> a.high;
      i++;
      riempiBinAlbero(a, t.binRadice(), t);
      do{
         cout << "Altro? (S/N) ";
         cin >> risp;
      }
      while (!((risp == 's') || (risp == 'S') || (risp == 'N') || (risp == 'n')));
   }
}

void CercaIntervallo (nodoBin p, nodoBin input, BinAlbero h, CodaPtr &aux)
{  
    if (p != NULL)
      {
      tipoelem a; 
      h.leggiNodo(p, a);
      
      if ((input->getEtichetta().low <=p->getEtichetta().high) && (p->getEtichetta().low <= input->getEtichetta().high))//low[a]<=high[b] e low[b]<=high[a]
        { 
         cout <<"sono in incoda"<<endl;
         aux.inCoda(a);
         cout <<"ho incodato"<<endl;                                     
        //return (p);
        }
   
		if (!h.sxVuoto(p)){
            CercaIntervallo(h.figlioSx(p),input, h,aux);
           }
		if (!h.dxVuoto(p)){
            CercaIntervallo(h.figlioDx(p),input, h,aux);
	    	}   
          }
      
      //else return p;
}

void ampiezza (CodaPtr q, nodoBin &l)
{
     tipoelem a,x;
     float k,min;
     q.leggiCoda(a);
     min = a.high - a.low;
     x=a;
     q.fuoriCoda();
     while (!q.codaVuota()) {
           q.leggiCoda(a);
           k = a.high - a.low;
           if (k<min)
           {
               min=k;
               x=a;
           }
           q.fuoriCoda();
     }
     l->setEtichetta(x);
//cout << "Nodo = " << "[" << x.low << "," << x.high << "]" << endl;
}

nodoBin MinIntervallo(BinAlbero t, float i)
{
            CodaPtr nodi= CodaPtr();
            nodoBin k= new NodoBinPtr();
            //tipoelem a;
            preVisita(t.binRadice(),t,nodi,i);
            ampiezza (nodi,k);
            return k; 
}
   
void max(nodoBin p, BinAlbero t, float y[],int &count){
	if (p != NULL){
      tipoelem a;
      t.leggiNodo(p, a);
    	y[count]=a.high;
    	count++;
    	
		if (!t.sxVuoto(p)){
			max(t.figlioSx(p), t,y,count);
		}
		if (!t.dxVuoto(p)){
			max(t.figlioDx(p), t,y,count);
		}
	}
}
 
 
int main(int argc, char *argv[])
{
   BinAlbero t; 
   CodaPtr uno = CodaPtr();
   //tipoelem a;
   //float inf;
   //float sup;
   //nodoBin j= new NodoBinPtr(a);
   //int i = 0;
   //char risp;
   cout << "Inserimento ordinato dell'albero binario T:" << endl;
   inserisciBinAlbero(t);
   cout << endl << "Stampa dell'albero appena inserito:" << endl << "T: ";
   stampaBinAlbero(t.binRadice(), t);
   cout <<endl;
   
   //primo punto completo
   
/*   cout << "estremo inferiore per l'intervallo da ricercare: ";
   cin>>a.low;
   cout << "estremo superiore per l'intervallo da ricercare: ";
   cin>>a.high;
   j->setEtichetta(a);
   cout <<"il nodo da ricercare �: [" << j->getEtichetta().<<" low, "<< j->getEtichetta().high<<"]"<<endl;
   
   
   nodoBin result;
   
   CercaIntervallo(t.binRadice(),j,t,uno);
   while (!uno.codaVuota()){
         tipoelem x;
         uno.leggiCoda(x);
         nodoBin temp= new NodoBinPtr(x);
         cout << "il nodo che si sovrappone con altri �: ["<< temp->getEtichetta().low<<","<< temp->getEtichetta().high<<"]"<<endl;
         uno.fuoriCoda();
   }
      
   // secondo punto completo

   float num;
   cout <<"inserisci il numero da trovare: ";
   cin >> num;
   nodoBin due= new NodoBinPtr();
   due=MinIntervallo(t,num);  
   cout <<"il nodo trovato �: [" << due->getEtichetta().low<<" , "<<due->getEtichetta().high<<"]"<<endl;
*/
   
   // terzo punto
   tipoelem rad;int h=0; float s[10];
   float sotto;
   float sopra;
   cout <<"quale deve essere io nodo radice del nuovo sottoalbero? inserisci l'estremo inferiore: ";
   cin >> sotto;
   cout <<"quale deve essere io nodo radice del nuovo sottoalbero? inserisci l'estremo superiore: ";
   cin >> sopra;
   
   nodoBin tem;
   tem = cerca(sotto,sopra,t.binRadice(),t);
   cout << "Muoio 1" << endl;
   //cout <<"l'etichetta DI TEM "<<tem->getEtichetta().low<< " "<<tem->getEtichetta().high<<endl;
   if (tem!=NULL){
   	/*
   max(tem,t,s,h);
   cout <<" valore di h "<<h<<endl;
   float max=s[0];
   for (int j=1;j<h;j++){
       cout << s[j]<<endl;
       if (s[j]>max)
            max= s[j];
       else continue;
   }
   */
   cout <<"il massimo estremo superiore del sottoalbero e': " << /*max*/ " " <<endl;
   
}else {
      cout <<"non ho trovato un cazzo e ho saaltato l'operazione"<<endl;}
        
/* cout << endl << endl << "Visite:" << endl << "preVisita -> T: ";
   preVisita(t.binRadice(), t);
   cout << endl << "postVisita -> T: ";
   postVisita(t.binRadice(), t);
   cout << endl << "inVisita -> T: ";
   inVisita(t.binRadice(), t);
   cout << endl << "Ampiezza -> T: ";
   ampiezzaBin(t.binRadice(), t);
   cout << endl << endl << "Ricerca di una parola:" << endl << "Parola: ";
   cin >> a;
   if (trovaParola(a, t.binRadice(), t, i, pota)){
      cout << a << " trovata al livello " << i << endl;
      do{
         cout << endl << "Vuoi potare l'albero a partire da questa parola? (S/N) ";
         cin >> risp;
      } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
      if ((risp == 's') || (risp == 'S')){
         t.cancSottoBinAlbero(pota);
         cout << "Albero potato!" << endl << (!t.binAlberoVuoto()? "T: ": "Albero vuoto");
         stampaBinAlbero(t.binRadice(), t);
         cout << endl;
      }
   } else
      cout << a << " non trovata" << endl;*/

   system("PAUSE");
   return 0;
}

