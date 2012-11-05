#ifndef NODOINSIEMELDIS_H_
#define NODOINSIEMELDIS_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"

template <class T>
class NodoInsiemeLDis : public Nodo<T> {
	public:
		NodoInsiemeLDis();
		NodoInsiemeLDis(T);
		NodoInsiemeLDis<T>* getSuccessivo();
		void setSuccessivo(NodoInsiemeLDis<T>*);
	private:
		NodoInsiemeLDis<T>* successivo;
};

template <class T>
NodoInsiemeLDis<T>::NodoInsiemeLDis() : Nodo<T>::Nodo() {
	successivo = NULL;
};

template <class T>
NodoInsiemeLDis<T>::NodoInsiemeLDis(T newValue) : Nodo<T>::Nodo(newValue) {
	successivo = NULL;
};

template <class T>
NodoInsiemeLDis<T>* NodoInsiemeLDis<T>::getSuccessivo() {
	return successivo;
};

template <class T>
void NodoInsiemeLDis<T>::setSuccessivo(NodoInsiemeLDis<T>* newSuccessivo) {
	successivo = newSuccessivo;
};

#endif /*NodoInsiemeLDis_H_*/
