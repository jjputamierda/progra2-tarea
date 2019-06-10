#ifndef AMBIENTE_MOCHILA
#define AMBIENTE_MOCHILA
#include "CriaturaMochila.h"//Hay que hacer
#include "Poblacion.h"
#include "Ambiente.h"
class AmbienteMochila : public Ambiente {
	private:
		double tope;
	    string uDinero;
	    string uPeso;
	    ListaP * lp;
	public:
	  AmbienteMochila();
      ~AmbienteMochila();
      double evaluar(Criatura *);
      Poblacion * crearPoblacionInicial();	  	  
      double getTope();
      AmbienteMochila & setTope(double);
      AmbienteMochila & setuDinero(string);
      AmbienteMochila & setuPeso(string);
      string getuPeso();
      string getuDinero();
      ListaP & getLp();

};

#endif