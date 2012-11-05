#ifndef TESTCODAVET_CPP_
#define TESTCODAVET_CPP_

#include "../common/stdInclude.h"
#include "CodaVet.h"

void TestCodaVet() {
	
	CodaVet<int, 10> coda = CodaVet<int, 10>();
	
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
	
};


#endif /*TESTCODAVET_CPP_*/
