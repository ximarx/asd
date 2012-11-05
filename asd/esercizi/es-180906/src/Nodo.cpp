#include <iostream>
#include <cstdlib>
#include "Nodo.h"

Nodo::Nodo(){
   etichetta.high = 0;
   etichetta.low=0;
};

Nodo::Nodo(tipoelem a){
   etichetta = a;
};

Nodo::~Nodo(){};

tipoelem Nodo::getEtichetta(){
   return etichetta;
};

void Nodo::setEtichetta(tipoelem a){
   etichetta.low = a.low;     
   etichetta.high = a.high;
};
