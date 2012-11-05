
#ifndef MATRICE_H
#define MATRICE_H


#include "ListaVet.h"


template <class T>
class Matrice {
	
	public:
		Matrice();
		Matrice(int, int);
		~Matrice();
		void creaMatrice(int, int);
		void setCella(int, int, T);
		T getCella(int, int);
		int getRows();
		int getCols();
	private:
		posizione getPositionFromXY(int, int);
		ListaVet<T> elements;
		int rows;
		int cols;
	
};


template <class T>
Matrice<T>::Matrice() {
	creaMatrice(0, 0);
};


template <class T>
Matrice<T>::Matrice(int rows, int cols) {
	creaMatrice(rows, cols);
};

template <class T>
Matrice<T>::~Matrice() {
	// definire meglio come distruggere la lista
	//elements = NULL;
	rows = 0;
	cols = 0;
};

template <class T>
void Matrice<T>::creaMatrice(int rows, int cols) {
	int maxElem;
	posizione p;
	
	if ( MAXLUNG >= (rows * cols) ) {
		this->rows = rows;
		this->cols = cols;
		elements = ListaVet<T>();
		maxElem = rows * cols;
		p = elements.primoLista(); 
		for ( int i = 0; i < maxElem; i++ ) {
			elements.insLista(0, p);
			// non so se funziona cosi....!!!
			p = elements.succLista(p);
		}
	} else {
		//cout << "NO NO... troppo grande per me, io sono piccolo e nero!!!" << endl;
		throw MAXLUNG;
	}
};

template <class T>
posizione Matrice<T>::getPositionFromXY(int row, int col) {
	posizione p;
	int x,y;

	if ( row < 1 || col < 1 ) {
		cout << "Row e Col devono essere almeno = 1!!!" << endl;
		throw 1;
	}
	
	p = elements.primoLista();
	y = getCols() * (row - 1); 
	x = col - 1;
	
	for ( int i = 0; i < y; i++ ) {
		p = elements.succLista(p);
	}
	for ( int i = 0; i < x; i++) {
		p = elements.succLista(p);
	}
	return p;
};

template <class T>
void Matrice<T>::setCella(int row, int col, T value) {
	posizione p = getPositionFromXY(row, col);
	elements.scriviLista(value, p);
};

template <class T>
T Matrice<T>::getCella(int row, int col) {
	posizione p = getPositionFromXY(row, col);
	return elements.leggiLista(p);
};

template <class T>
int Matrice<T>::getRows() {
	return rows;
};

template <class T>
int Matrice<T>::getCols() {
	return cols;
};

#endif
