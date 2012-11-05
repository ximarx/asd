#ifndef NODODIZIONARIOHASHAPERTO_H_
#define NODODIZIONARIOHASHAPERTO_H_

#include "../common/stdInclude.h"
#include "../common/Nodo.h"

template <class K, class T>
class NodoDizionarioHashAperto : public Nodo<T> {
	public:
		NodoDizionarioHashAperto();
		NodoDizionarioHashAperto(K, T);
		NodoDizionarioHashAperto<K, T>* getSuccessivo();
		void setSuccessivo(NodoDizionarioHashAperto<K, T>*);
		K getKey();
		void setKey(K);
	private:
		NodoDizionarioHashAperto<K, T>* successivo;
		K key;
};

template <class K, class T>
NodoDizionarioHashAperto<K, T>::NodoDizionarioHashAperto() : Nodo<T>::Nodo() {
	successivo = NULL;
};

template <class K, class T>
NodoDizionarioHashAperto<K, T>::NodoDizionarioHashAperto(K newKey, T newValue) : Nodo<T>::Nodo(newValue) {
	successivo = NULL;
	key = newKey;
};


template <class K, class T>
NodoDizionarioHashAperto<K, T>* NodoDizionarioHashAperto<K, T>::getSuccessivo() {
	return successivo;
};

template <class K, class T>
void NodoDizionarioHashAperto<K, T>::setSuccessivo(NodoDizionarioHashAperto<K, T>* newSuccessivo) {
	successivo = newSuccessivo;
};


template <class K, class T>
K NodoDizionarioHashAperto<K, T>::getKey() {
	return key;
};

template <class K, class T>
void NodoDizionarioHashAperto<K, T>::setKey(K newKey) {
	key = newKey;
};

#endif /*NODODIZIONARIOHASHAPERTO_H_*/
