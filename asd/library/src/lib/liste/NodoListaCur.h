#ifndef NODOLISTACUR_H_
#define NODOLISTACUR_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"


template <class T>
class NodoListaCur : public Nodo<T> {
	public:
		NodoListaCur();
		NodoListaCur(T);
		int getSuccessivo();
		void setSuccessivo(int);
	private:
		int successivo;
};

template <class T>
NodoListaCur<T>::NodoListaCur() : Nodo<T>::Nodo() {
	successivo = -1;
};

template <class T>
NodoListaCur<T>::NodoListaCur(T newValue) : Nodo<T>::Nodo(newValue) {
	successivo = -1;
};


template <class T>
int NodoListaCur<T>::getSuccessivo() {
	return successivo;
};

template <class T>
void NodoListaCur<T>::setSuccessivo(int newSuccessivo) {
	successivo = newSuccessivo;
};


#endif /*NODOLISTACUR_H_*/
