#ifndef TESTCODAPTR_CPP_
#define TESTCODAPTR_CPP_

#include "../common/stdInclude.h"
#include "CodaPtr.h"

void TestCodaPtr() {

	CodaPtr<int> coda = CodaPtr<int>();
	
	for ( int i = 0; i < 10; i++ ) {
		coda.inCoda(i);
	}
	
	for ( int i = 0; i < 4; i++ )
		coda.fuoriCoda();
		
	coda.inCoda(213);
	coda.inCoda(2432);
	
	coda.fuoriCoda();
	
	coda.inCoda(213);
	//coda.inCoda(5464);
	
	//coda.inCoda(INT_MAX);
	
	while ( !coda.codaVuota() ) {
		cout << "Elemento: " << coda.leggiCoda() << endl;
		coda.fuoriCoda();
	}
	
}


#endif /*TESTCODAPTR_CPP_*/
