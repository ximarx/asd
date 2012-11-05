#ifndef TESTINSIEMELDIS_CPP_
#define TESTINSIEMELDIS_CPP_

#include "../common/stdInclude.h"
#include "InsiemeLDis.h"

void TestInsiemeLDis() {

	InsiemeLDis<int> A = InsiemeLDis<int>();
	InsiemeLDis<int> B = InsiemeLDis<int>();
	
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
	
	cout << endl;
	
	InsiemeLDis<int> C = A.unione(B);
	
	for ( int i = 0; i < 100; i++ ) {
		if ( C.appartiene(i) ) {
			cout << i << " appartiene" << endl;
		}
	}

	cout << endl;

	InsiemeLDis<int> D = C.intersezione(B);

	for ( int i = 0; i < 100; i++ ) {
		if ( D.appartiene(i) ) {
			cout << i << " appartiene" << endl;
		}
	}

	cout << endl;

	InsiemeLDis<int> E = C.differenza(B);

	for ( int i = 0; i < 100; i++ ) {
		if ( E.appartiene(i) ) {
			cout << i << " appartiene" << endl;
		}
	}
	
	
}


#endif /*TESTINSIEMELDIS_CPP_*/
