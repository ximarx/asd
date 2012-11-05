#ifndef NODOCODAPTR_H_
#define NODOCODAPTR_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"

template <class T>
class NodoCodaPtr : public Nodo<T> {
	public:
		NodoCodaPtr();
		NodoCodaPtr(T);
		NodoCodaPtr<T>* getSuccessivo();
		void setSuccessivo(NodoCodaPtr<T>*);
	private:
		NodoCodaPtr<T>* successivo;
};

template <class T>
NodoCodaPtr<T>::NodoCodaPtr() : Nodo<T>::Nodo() {
	successivo = NULL;
};

template <class T>
NodoCodaPtr<T>::NodoCodaPtr(T newValue) : Nodo<T>::Nodo(newValue) {
	successivo = NULL;
};


template <class T>
NodoCodaPtr<T>* NodoCodaPtr<T>::getSuccessivo() {
	return successivo;
};

template <class T>
void NodoCodaPtr<T>::setSuccessivo(NodoCodaPtr<T>* newSuccessivo) {
	successivo = newSuccessivo;
};

#endif /*NODOCODAPTR_H_*/
