#ifndef NODOGRAFOMATAD_H_
#define NODOGRAFOMATAD_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"

template <class T>
class NodoGrafoMatAd : public Nodo<T> {
	public:
		NodoGrafoMatAd();
		NodoGrafoMatAd(T);
		int getArchi();
		void setArchi(int);
		bool getVisitato();
		void setVisitato(bool);
		bool getEsiste();
		void setEsiste(bool);
	private:
		int archi;
		bool visitato;
		bool esiste;
};

template <class T>
NodoGrafoMatAd<T>::NodoGrafoMatAd() : Nodo<T>::Nodo() {
	archi = 0;
	visitato = false;
	esiste = false;
};

template <class T>
NodoGrafoMatAd<T>::NodoGrafoMatAd(T newValue) : Nodo<T>::Nodo(newValue) {
	archi = 0;
	visitato = false;
	esiste = false;
};

template <class T>
int NodoGrafoMatAd<T>::getArchi() {
	return archi;
};

template <class T>
void NodoGrafoMatAd<T>::setArchi(int newArchi) {
	archi = newArchi;
}

template <class T>
bool NodoGrafoMatAd<T>::getVisitato() {
	return visitato;
};

template <class T>
void NodoGrafoMatAd<T>::setVisitato(bool newVisitato) {
	visitato = newVisitato;
}

template <class T>
bool NodoGrafoMatAd<T>::getEsiste() {
	return esiste;
};

template <class T>
void NodoGrafoMatAd<T>::setEsiste(bool newEsiste) {
	esiste = newEsiste;
}

#endif /*NODOGRAFOMATAD_H_*/
