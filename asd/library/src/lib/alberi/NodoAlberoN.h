#ifndef NODOALBERON_H_
#define NODOALBERON_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"

template <class T>
class NodoAlberoN : public Nodo<T> {
	public:
		NodoAlberoN();
		NodoAlberoN(T);
		NodoAlberoN<T>* getParent();
		NodoAlberoN<T>* getFirstChild();
		NodoAlberoN<T>* getNextBrother();
		void setParent(NodoAlberoN<T>*);
		void setFirstChild(NodoAlberoN<T>*);
		void setNextBrother(NodoAlberoN<T>*);
	private:
		NodoAlberoN<T>* parent;
		NodoAlberoN<T>* firstChild;
		NodoAlberoN<T>* nextBrother;
};

template <class T>
NodoAlberoN<T>::NodoAlberoN() : Nodo<T>::Nodo() {
	parent = NULL;
	firstChild = NULL;
	nextBrother = NULL;
};

template <class T>
NodoAlberoN<T>::NodoAlberoN(T newValue) : Nodo<T>::Nodo(newValue) {
	parent = NULL;
	firstChild = NULL;
	nextBrother = NULL;
};


template <class T>
NodoAlberoN<T>* NodoAlberoN<T>::getParent() {
	return parent;
};

template <class T>
void NodoAlberoN<T>::setParent(NodoAlberoN<T>* newParent) {
	parent = newParent;
};

template <class T>
NodoAlberoN<T>* NodoAlberoN<T>::getFirstChild() {
	return firstChild;
};

template <class T>
void NodoAlberoN<T>::setFirstChild(NodoAlberoN<T>* newFirstChild) {
	firstChild = newFirstChild;
};

template <class T>
NodoAlberoN<T>* NodoAlberoN<T>::getNextBrother() {
	return nextBrother;
};

template <class T>
void NodoAlberoN<T>::setNextBrother(NodoAlberoN<T>* newNextBrother) {
	nextBrother = newNextBrother;
};

#endif /*NODOALBERON_H_*/
