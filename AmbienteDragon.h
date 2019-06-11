#ifndef AMBIENTE_DRAGON
#define AMBIENTE_DRAGON
#include "DragonDaenerys.cpp"
#include "Poblacion.h"
#include "Ambiente.h"
class AmbienteDragon : public Ambiente {
	public:
	  AmbienteDragon();
      double evaluar(Criatura *);
      Poblacion * crearPoblacionInicial();	  	  
};

#endif
