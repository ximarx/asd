/*
Implementare la struttura dati "Matrice" definita dalle seguenti specifiche:
Tipi:
     ● MATRICE: famiglia dei vettori bidimensionali A(i,j) di elementi di tipo intero,
         con 1 ≤ i ≤ N, 1 ≤ j ≤ M, 1 ≤ N,M ≤ MAXDIM (costante intera fissata a priori)
     ● DIMENSIONE: sottoinsieme dei numeri naturali compresi fra 1 e MAXDIM
     ● REAL: insieme dei numeri reali
     ● BOOLEAN: insieme dei valori di verità
Operatori:
     ● CREAMATRICE (R,C: DIMENSIONE) → M: MATRICE
         Post: M = A(i,j), 1≤ i ≤ R, 1 ≤ j ≤ C ∧ ∀i,j : A(i,j) = 0
         (matrice RxC con tutti gli elementi nulli)
     ● MOLTIPLICAZIONESCALARE( A : MATRICE, c : REAL) → S : Matrice
         Pre: A = A(i,j), 1 ≤ i ≤ L, 1 ≤ j ≤ M
         Post: S = S(i,j), 1 ≤ i ≤ L, 1 ≤ j ≤ M ∧ ∀i,j : S(i,j) = c * A(i,j)
     ● TRASPOSTA ( M : Matrice ) → S : Matrice
         Pre: A = A(i,j), 1 ≤ i ≤ L, 1 ≤ j ≤ M
         Post: S = S(j,i), 1 ≤ i ≤ L, 1 ≤ j ≤ M ∧ ∀i,j : S(i,j) = A(j,i)
     ● DETERMINANTE( A : MATRICE ) → d : REAL
         Pre: A = A(i,j), 1 ≤ i ≤ L, 1 ≤ j ≤ L        (matrice quadrata)
         Post: d = determinante della matrice A ottenuto con un qualsiasi metodo o con
         lo sviluppo di Laplace                                 dove ogni Ci,j rappresenta il complemento algebrico
         della coppia (i,j), cioè Ci,j è data da ( - 1)i + j per il determinante della matrice di ordine n-1, ottenuta
         dalla A eliminando la riga i-esima e la colonna j-esima.
         ANTISIMMETRICA ( A : MATRICE) → B: BOOLEAN
     ●
         Pre: A = A(i,j), 1 ≤ i ≤ L, 1 ≤ j ≤ M
         Post: B = true se e solo se AT = - A (matrice che coincide con la sua trasposta cambiata di segno)
oltre a due operatori ACQUISISCI e STAMPA che, rispettivamente, acquisiscono da tastiera e stampano a
video il contenuto di una matrice.
Realizzare un programma (main) che consenta di testare gli operatori implementati.

*/


#include "main.h"
#include "matrice.h"
#include <math.h>

template <class T>
void stampaMatrice( Matrice<T> &matrix) {
	
	int rows = matrix.getRows();
	int cols = matrix.getCols();
	
	cout << "---- STAMPA MATRICE (" << rows << "x" << cols << ") ----" << endl;
	
	float cv;
	
	for ( int i = 1; i <= rows; i++) {
		cout << " |";
		for ( int j = 1; j <= cols; j++) {
			cv = matrix.getCella(i, j);
			cout << " " << matrix.getCella(i, j) << " |";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
}

template <class T>
void riempiMatrice( Matrice<T> &matrix) {

	// Variabile per l'interfaccia TUI
	string kValue;
	int posValueR, posValueC;
	T mValue;
	
	int rows = matrix.getRows();
	int cols = matrix.getCols();
	
	stampaMatrice(matrix);
	
	do {
		cout << "Aggiungere un nuovo valore? (S/N) ";
		cin >> kValue;
	} while ( kValue != "s" && kValue != "S" && kValue != "n" && kValue != "N" && kValue != "a" );
	
	if ( kValue == "s" || kValue == "S" ) {
		// inserimento nuovo valore
		do {
			cout << "Inserire la riga dell'elemento (1-"<< rows << "): ";
			cin >> posValueR;
		} while ( posValueR < 1 || posValueR > rows );
		do {
			cout << "Inserire la colonna dell'elemento (1-"<< cols << "): ";
			cin >> posValueC;
		} while ( posValueC < 1 || posValueC > cols );
		
		cout << "Inserire il valore da assegnare: ";
		cin >> mValue;
		
		matrix.setCella(posValueR, posValueC, mValue);
		
		// avvia la ricorsione
		return riempiMatrice(matrix); 
		
	} else if ( kValue == "a" ) {
		// generazione finta di [1,2,3;4,5,6;7,8,9;--]
		if ( rows == cols ) {
			int superI = 1;
			for ( int i = 1; i <= rows; i++ ) {
				for ( int j = 1; j <= cols; j++) {
					matrix.setCella(i,j,superI++);
				}
			}
		} else return;
	} else {
		return;
	}
}

template <class T>
Matrice<T> moltiplicazioneScalare(Matrice<T> &matrix, float value) {
	
	int rows = matrix.getRows();
	int cols = matrix.getCols();
	
	Matrice<T> sMatrix = Matrice<T>(rows, cols);
	
	for ( int i = 1; i <= rows; i++) {
		for ( int j = 1; j <= cols; j++) {
			sMatrix.setCella(i,j,matrix.getCella(i,j) * value);
		}
	}
	return sMatrix;
}

template <class T>
Matrice<T> trasposta(Matrice<T> &matrix) {
	
	int rows = matrix.getRows();
	int cols = matrix.getCols();

	Matrice<T> tMatrix = Matrice<T>(cols, rows);
	
	for ( int i = 1; i <= rows; i++ ) {
		for ( int j = 1; j <= cols; j++ ) {
			tMatrix.setCella(j,i,matrix.getCella(i,j));
		}
	}
	
	return tMatrix;
}


template <class T>
Matrice<T> subMatrice(Matrice<T> &matrix, int row, int col) {
	
	Matrice<T> subMatrix = Matrice<T>(matrix.getRows() -1, matrix.getCols() -1);
	
	int newI, newJ;
	
	newI = 1;
	for ( int i = 1; i <= matrix.getRows(); i++ ) {
		newJ = 1;
		if ( i != row ) {
			for ( int j = 1; j <= matrix.getCols(); j++ ) {
				if ( j != col) {
					//cout << "Scrivo (" << i << "," << j << ") -> " << matrix.getCella(i,j) << " nella cella (" << newI << "," << newJ << ")" << endl;
					subMatrix.setCella(newI, newJ, matrix.getCella(i, j));
					// non incremento se la colonna è da saltare
					newJ++;
				}
			}
			// non incremento se la riga è da saltare
			newI++;
		}
	}
	return subMatrix;
	
} 


template <class T>
float determinante(Matrice<T> &matrix) {
	// la matrice deve essere quadrata... altrimenti non se ne fa nulla
	if ( matrix.getRows() == matrix.getCols() ) {
		if ( matrix.getRows() == 1 ) {
			return matrix.getCella(1,1);
		} else {
			float det = 0;
			for ( int j = 1; j <= matrix.getCols(); j++ ) {
				//T value = matrix.getCella(1, j);
				//float vv = (-1)^(1+j);
				Matrice<T> subMatrix = subMatrice(matrix, 1, j);
				float attualeDet = matrix.getCella(1,j) * pow(-1, 1+j) * determinante(subMatrix);
				det += attualeDet;
			}
			return det;
		}
		
	} else {
		cout << "Il determinante non è calcolabile!!" << endl;
		return 0;
	}	
}

template <class T>
bool isAntisimmetrica(Matrice<T> &matrix) {
	Matrice<T> tMatrix = trasposta(matrix);
	Matrice<T> sMatrix = moltiplicazioneScalare(matrix, -1);
	
	for ( int i = 1; i < tMatrix.getRows(); i++) {
		for ( int j = 1; j < tMatrix.getCols(); j++) {
			if ( tMatrix.getCella(i,j) != sMatrix.getCella(i,j) ) {
				return false;
			} 
		}
	}
	return true;
	
}

int main(int argc, char **argv) {
	
	int rows;
	int cols;
	Matrice<float> matrix;
	bool validInput = false; 
	
	while ( !validInput ) {
		try {
			cout << "Numero di righe della matrice: ";
			cin >> rows;
			cout << "Numero di colonne della matrice: ";
			cin >> cols;
			matrix = Matrice<float>(rows,cols);
			validInput = true;
		} catch (int e) {
			cout << "Il numero massimo di elementi contenibili dalla matrice e' " << e << endl;
			cout << "Il valori inseriti invece indicano " << rows * cols << endl; 
		}
	}
	
	riempiMatrice(matrix);
	stampaMatrice(matrix);

	//=========== Moltiplicazione scalare ============//
	float moltiplicatore;
	cout << "Inserire il moltiplicatore: ";
	cin >> moltiplicatore;
	
	cout << "========== Matrice Moltiplicata =========" << endl;
	Matrice<float> mMatrix = moltiplicazioneScalare(matrix, moltiplicatore);
	stampaMatrice(mMatrix);
	
	//=========== Trasposta =============//
	
	cout << "========== Matrice Trasposta =========" << endl;
	Matrice<float> tMatrix = trasposta(matrix);
	stampaMatrice(tMatrix);
	
	//=========== Determinante ===========//
	cout << "========== Determinante della matrice =========" << endl;
	stampaMatrice(matrix);
	cout << "Determinante = " << determinante(matrix) << endl;

	//=========== Antisimmetrica ===========//
	cout << "========== Controllo della antisimmetria ======" << endl;
	cout << "La matrice e' antisimmetrica? " << ( isAntisimmetrica(matrix) ? "Si" : "No" ) << endl;
	
}
