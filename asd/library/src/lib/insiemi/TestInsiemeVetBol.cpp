#ifndef TESTINSIEMEVETBOL_CPP_
#define TESTINSIEMEVETBOL_CPP_

#include "../common/stdInclude.h"
#include "InsiemeVetBol.h"

void TestInsiemeVetBol() {
	
	InsiemeVetBol<int, 100> A = InsiemeVetBol<int, 100>();
	InsiemeVetBol<int, 100> B = InsiemeVetBol<int, 100>();
	
	for ( int i = 0; i < 10; i++ ) {
		A.inserisci(10 * i);
	} 

	for ( int i = 0; i < 10; i++ ) {
		B.inserisci(10 * i + 3);
	} 

	A.cancella(20);
	B.cancella(20+3);
	
	for ( int i = 0; i < 100; i++ ) {
		if ( A.appartiene(i) ) {
			cout << i << " appartiene" << endl;
		}
	}

	cout << endl;
	
	for ( int i = 0; i < 100; i++ ) {
		if ( B.appartiene(i) ) {
			cout << i << " appartiene" << endl;
		}
	}
	
	InsiemeVetBol<int, 100> C = A.unione(B);
	
	for ( int i = 0; i < 100; i++ ) {
		if ( C.appartiene(i) ) {
			cout << i << " appartiene" << endl;
		}
	}
		
	
}


#endif /*TESTINSIEMEVETBOL_CPP_*/
