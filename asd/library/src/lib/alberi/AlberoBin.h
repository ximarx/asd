#ifndef ALBEROBIN_H_
#define ALBEROBIN_H_

#include "../common/stdInclude.h"
#include "NodoAlberoBin.h"

template <class T>
class AlberoBin {
	public:
		typedef NodoAlberoBin<T>* NodoAlbero;
		AlberoBin();
		~AlberoBin();
		void creaAlberoBin();
		bool alberoVuoto();
		NodoAlbero radice() const;
		NodoAlbero padre(NodoAlbero) const;
		NodoAlbero figlioSx(NodoAlbero) const;
		NodoAlbero figlioDx(NodoAlbero) const;
		bool sxVuoto(NodoAlbero) const;
		bool dxVuoto(NodoAlbero) const;
		T leggiNodo(NodoAlbero) const;
		void scriviNodo(T, NodoAlbero);
		NodoAlbero insRadice(T);
		NodoAlbero insFiglioSx(NodoAlbero);
		NodoAlbero insFiglioDx(NodoAlbero);
		void cancSottoAlbero(NodoAlbero);
		void constrAlbero(NodoAlbero, NodoAlbero);
	private:
		NodoAlbero root;
};

template <class T>
AlberoBin<T>::AlberoBin() {
	creaAlberoBin();
};

template <class T>
AlberoBin<T>::~AlberoBin() {};

template <class T>
void AlberoBin<T>::creaAlberoBin() {
	root = NULL;
};

template <class T>
bool AlberoBin<T>::alberoVuoto() {
	return (root == NULL);
};

template <class T>
NodoAlberoBin<T>* AlberoBin<T>::radice() const {
	return root;
};

template <class T>
NodoAlberoBin<T>* AlberoBin<T>::padre(NodoAlbero nodo) const {
	if ( nodo->getParent() == NULL ) {
		__DEBUG("AlberoBin::padre(): Parent = NULL");
	}
	return nodo->getParent();
};

template <class T>
NodoAlberoBin<T>* AlberoBin<T>::figlioSx(NodoAlbero nodo) const {
	if ( nodo->getSx() == NULL ) {
		__DEBUG("AlberoBin::figlioSx(): Sx = NULL");
	}
	return nodo->getSx();
};

template <class T>
NodoAlberoBin<T>* AlberoBin<T>::figlioDx(NodoAlbero nodo) const {
	if ( nodo->getDx() == NULL ) {
		__DEBUG("AlberoBin::figlioDx(): Dx = NULL");
	}
	return nodo->getDx();
};

template <class T>
bool AlberoBin<T>::sxVuoto(NodoAlbero nodo) const {
	return (nodo->getSx() == NULL);
};

template <class T>
bool AlberoBin<T>::dxVuoto(NodoAlbero nodo) const {
	return (nodo->getDx() == NULL);
};

template <class T>
T AlberoBin<T>::leggiNodo(NodoAlbero nodo) const {
	if ( nodo == NULL ) {
		__DEBUG("AlberoBin::leggiNodo(): nodo = NULL");
		throw 0;
	} else {
		return nodo->getValue();
	}
};

template <class T>
void AlberoBin<T>::scriviNodo(T newValue, NodoAlbero nodo) {
	if ( nodo == NULL ) {
		__DEBUG("AlberoBin::scriviNodo(): nodo = NULL");
		throw 0;
	} else {
		nodo->setValue(newValue);
	}
};

template <class T>
NodoAlberoBin<T>* AlberoBin<T>::insRadice(T newValue) {
	if ( !alberoVuoto() ) {
		__DEBUG("AlberoBin::insRadice(): alberoVuoto = FALSE");
		throw INT_MAX;
	} else {
		NodoAlbero newRadice = new NodoAlberoBin<T>(newValue);
		root = newRadice;
		return root;
	}
};

template <class T>
NodoAlberoBin<T>* AlberoBin<T>::insFiglioSx(NodoAlbero nodo) {
	if ( nodo == NULL ) {
		__DEBUG("AlberoBin::insFiglioSx(): nodo = NULL");
		throw 0;
	} else {
		NodoAlbero newSx = new NodoAlberoBin<T>();
		nodo->setSx(newSx);
		newSx->setParent(nodo);
		return newSx;
	}
};

template <class T>
NodoAlberoBin<T>* AlberoBin<T>::insFiglioDx(NodoAlbero nodo) {
	if ( nodo == NULL ) {
		__DEBUG("AlberoBin::insFiglioDx(): nodo = NULL");
		throw 0;
	} else {
		NodoAlbero newDx = new NodoAlberoBin<T>();
		nodo->setDx(newDx);
		newDx->setParent(nodo);
		return newDx;
	}
};

template <class T>
void AlberoBin<T>::cancSottoAlbero(NodoAlbero nodo) {
	if ( nodo == NULL ) {
		__DEBUG("AlberoBin::insFiglioDx(): nodo = NULL");
		throw 0;
	} else if ( alberoVuoto() ) {
		__DEBUG("AlberoBin::insFiglioDx(): alberoVuoto() = TRUE");
		throw 0;
	} else {
		if ( !sxVuoto(nodo) ) {
			cancSottoAlbero(figlioSx(nodo));
		}
		if ( !dxVuoto(nodo) ) {
			cancSottoAlbero(figlioDx(nodo));
		}
		if ( nodo != root ) {
			if ( figlioSx(padre(nodo)) == nodo ) {
				padre(nodo)->setSx(NULL);
			}
			if ( figlioDx(padre(nodo)) == nodo ) {
				padre(nodo)->setDx(NULL);
			}
		} else {
			root = NULL;
		}
	}
};

template <class T>
void AlberoBin<T>::constrAlbero(NodoAlbero SASx, NodoAlbero SADx) {
	root = new NodoAlberoBin<T>();
	root->setSx(SASx);
	root->setDx(SADx);
};

#endif /*ALBEROBIN_H_*/
