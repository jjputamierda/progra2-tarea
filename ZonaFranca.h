#ifndef ZONA_FRANCA
#define ZONA_FRANCA
#define MAX_AMBIENTES 100
#define MAX_ALGORITMOS 100
#include "Ambiente.h"
#include "Algoritmo.h"

#include "GeneticoBasico.h"
#include "GeneticoSuertudo.h"
#include "GeneticoHitler.h"
// AQUI DEBEN AGREGAR SUS .H DE LOS ALGORITMOS


#include "AmbienteEntero.h"
#include "AmbienteMochila.h"
#include "AmbientePokemon.h"
// AQUI DEBEN AGREGAR SUS .H DE LOS AMBIENTES


class ZonaFranca {   
   private:
      Ambiente * ambiente[MAX_AMBIENTES];
	  Algoritmo * algoritmo[MAX_ALGORITMOS];
	  int ambienteCounter;
	  int algoritmoCounter;
	  
   public:
      ZonaFranca();
	  ~ZonaFranca();
	  
      Ambiente * nuevoAmbiente(char *,int);
	  
      Algoritmo * nuevoAlgoritmo(char * );
	    
};
#endif