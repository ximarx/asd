#ifndef INSIEMEVETBOL_H_
#define INSIEMEVETBOL_H_

template <class T, int DIM>
class InsiemeVetBol {
	public:
		InsiemeVetBol();
		~InsiemeVetBol();
		void creaInsieme();
		bool insiemeVuoto();
		bool appartiene(T );
		void inserisci(T );
		void cancella(T );
		InsiemeVetBol unione(InsiemeVetBol );
		InsiemeVetBol intersezione(InsiemeVetBol );
		InsiemeVetBol differenza(InsiemeVetBol );
	private:
		bool insieme[DIM];
};

template <class T, int DIM>
InsiemeVetBol<T, DIM>::InsiemeVetBol() {
	creaInsieme();
};

template <class T, int DIM>
InsiemeVetBol<T, DIM>::~InsiemeVetBol() {};

template <class T, int DIM>
void InsiemeVetBol<T, DIM>::creaInsieme() {
	for ( int i = 0; i < DIM; i++ ) {
		insieme[i] = false;
	}
};

template <class T, int DIM>
bool InsiemeVetBol<T, DIM>::insiemeVuoto() {
	for ( int i = 0; i < DIM; i++ ) {
		if ( insieme[i] ) {
			return false;
		}
	}
	return true;
};

template <class T, int DIM>
bool InsiemeVetBol<T, DIM>::appartiene(T value) {
	if ( value < 0 || value >= DIM ) {
		__DEBUG("InsiemeVetBol::appartiene(): value non valido");
		throw INT_MAX;
	} else {
		return insieme[value];
	}
};

template <class T, int DIM>
void InsiemeVetBol<T, DIM>::inserisci(T value) {
	if ( value < 0 || value >= DIM ) {
		__DEBUG("InsiemeVetBol::inserisci(): value non valido");
		throw INT_MAX;
	} else {
		insieme[value] = true;
	}
};


template <class T, int DIM>
void InsiemeVetBol<T, DIM>::cancella(T value) {
	if ( value < 0 || value >= DIM ) {
		__DEBUG("InsiemeVetBol::inserisci(): value non valido");
		throw INT_MAX;
	} else {
		insieme[value] = false;
	}
};

template <class T, int DIM>
InsiemeVetBol<T, DIM> InsiemeVetBol<T, DIM>::unione(InsiemeVetBol<T, DIM> A) {
	InsiemeVetBol<T, DIM> nuovoI = InsiemeVetBol<T, DIM>();
	for ( int i = 0; i < DIM; i++ ) {
		if ( A.appartiene(i) || appartiene(i) ) {
			nuovoI.inserisci(i);
		}
	}
	return nuovoI;
};


template <class T, int DIM>
InsiemeVetBol<T, DIM> InsiemeVetBol<T, DIM>::intersezione(InsiemeVetBol<T, DIM> A) {
	InsiemeVetBol<T, DIM> nuovoI = InsiemeVetBol<T, DIM>();
	for ( int i = 0; i < DIM; i++ ) {
		if ( A.appartiene(i) && appartiene(i) ) {
			nuovoI.inserisci(i);
		}
	}
	return nuovoI;
};


template <class T, int DIM>
InsiemeVetBol<T, DIM> InsiemeVetBol<T, DIM>::differenza(InsiemeVetBol<T, DIM> A) {
	InsiemeVetBol<T, DIM> nuovoI = InsiemeVetBol<T, DIM>();
	for ( int i = 0; i < DIM; i++ ) {
		if ( appartiene(i) && !A.appartiene(i) ) {
			nuovoI.inserisci(i);
		}
	}
	return nuovoI;
};


#endif /*INSIEMEVETBOL_H_*/
