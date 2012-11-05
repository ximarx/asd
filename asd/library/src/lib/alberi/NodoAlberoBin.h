#ifndef NODOALBEROBIN_H_
#define NODOALBEROBIN_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"

template <class T>
class NodoAlberoBin : public Nodo<T> {
	public:
		NodoAlberoBin();
		NodoAlberoBin(T);
		NodoAlberoBin<T>* getParent();
		NodoAlberoBin<T>* getSx();
		NodoAlberoBin<T>* getDx();
		void setParent(NodoAlberoBin<T>*);
		void setSx(NodoAlberoBin<T>*);
		void setDx(NodoAlberoBin<T>*);
	private:
		NodoAlberoBin<T>* parent;
		NodoAlberoBin<T>* sx;
		NodoAlberoBin<T>* dx;
};

template <class T>
NodoAlberoBin<T>::NodoAlberoBin() : Nodo<T>::Nodo() {
	parent = NULL;
	sx = NULL;
	dx = NULL;
};

template <class T>
NodoAlberoBin<T>::NodoAlberoBin(T newValue) : Nodo<T>::Nodo(newValue) {
	parent = NULL;
	sx = NULL;
	dx = NULL;
};


template <class T>
NodoAlberoBin<T>* NodoAlberoBin<T>::getParent() {
	return parent;
};

template <class T>
void NodoAlberoBin<T>::setParent(NodoAlberoBin<T>* newParent) {
	parent = newParent;
};

template <class T>
NodoAlberoBin<T>* NodoAlberoBin<T>::getSx() {
	return sx;
};

template <class T>
void NodoAlberoBin<T>::setSx(NodoAlberoBin<T>* newSx) {
	sx = newSx;
};

template <class T>
NodoAlberoBin<T>* NodoAlberoBin<T>::getDx() {
	return dx;
};

template <class T>
void NodoAlberoBin<T>::setDx(NodoAlberoBin<T>* newDx) {
	dx = newDx;
};

#endif /*NODOALBEROBIN_H_*/
