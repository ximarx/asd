#ifndef NODOLISTAPTR_H_
#define NODOLISTAPTR_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"


template <class T>
class NodoListaPtr : public Nodo<T> {
	public:
		NodoListaPtr();
		NodoListaPtr(T);
		NodoListaPtr<T>* getSuccessivo();
		NodoListaPtr<T>* getPrecedente();
		void setSuccessivo(NodoListaPtr<T>*);
		void setPrecedente(NodoListaPtr<T>*);
	private:
		NodoListaPtr<T>* successivo;
		NodoListaPtr<T>* precedente;
};

template <class T>
NodoListaPtr<T>::NodoListaPtr() : Nodo<T>::Nodo() {
	successivo = NULL;
	precedente = NULL;
};

template <class T>
NodoListaPtr<T>::NodoListaPtr(T newValue) : Nodo<T>::Nodo(newValue) {
	successivo = NULL;
	precedente = NULL;
};

template <class T>
NodoListaPtr<T>* NodoListaPtr<T>::getSuccessivo() {
	return successivo;
};

template <class T>
void NodoListaPtr<T>::setSuccessivo(NodoListaPtr<T>* newSuccessivo) {
	successivo = newSuccessivo;
};

template <class T>
NodoListaPtr<T>* NodoListaPtr<T>::getPrecedente() {
	return successivo;
};

template <class T>
void NodoListaPtr<T>::setPrecedente(NodoListaPtr<T>* newPrecedente) {
	precedente = newPrecedente;
};

#endif /*NODOLISTAPTR_H_*/
