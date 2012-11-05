#ifndef NODOPILAPTR_H_
#define NODOPILAPTR_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"

template <class T>
class NodoPilaPtr : public Nodo<T> {
	public:
		NodoPilaPtr();
		NodoPilaPtr(T);
		~NodoPilaPtr();
		void setSuccessivo(NodoPilaPtr<T> *);
		NodoPilaPtr<T>* getSuccessivo();
	private:
		NodoPilaPtr<T>* successivo;
	
};

template <class T>
NodoPilaPtr<T>::NodoPilaPtr() : Nodo<T>::Nodo() {
	successivo = NULL;
};

template <class T>
NodoPilaPtr<T>::NodoPilaPtr(T newValue) : Nodo<T>::Nodo(newValue) {
	successivo = NULL;
};

template <class T>
NodoPilaPtr<T>* NodoPilaPtr<T>::getSuccessivo() {
	return successivo;
};

template <class T>
void NodoPilaPtr<T>::setSuccessivo(NodoPilaPtr<T>* newSuccessivo) {
	successivo = newSuccessivo;
};

#endif /*NODOPILAPTR_H_*/
