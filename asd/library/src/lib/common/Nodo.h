#ifndef NODO_H_
#define NODO_H_

#include "stdInclude.h"

template <class T>
class Nodo {
	public:
		Nodo();
		Nodo(T);
		~Nodo();
		T getValue();
		void setValue(T);
	private:
		T value;
};

template <class T>
Nodo<T>::Nodo() {};

template <class T>
Nodo<T>::Nodo(T newValue) {
	Nodo();
	value = newValue;
};

template <class T>
Nodo<T>::~Nodo() {};

template <class T>
T Nodo<T>::getValue() {
	return value;
};

template <class T>
void Nodo<T>::setValue(T newValue) {
	value = newValue;
};

#endif /*NODO_H_*/
