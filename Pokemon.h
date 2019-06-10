#ifndef POKEMON
#define POKEMON
#include "Criatura.h"
class Pokemon: public Criatura {
   friend class AmbienteEntero;
   private:
      double ataque;
      double defensa;
      double obey;
	  
   public:
    Pokemon();   
    Pokemon(double,double,double);
	  Pokemon & setAtaque(double);
     Pokemon & setDefensa(double);
     Pokemon & setObey(double);
	  double getAtaque();
     double getDefensa();
     double getObey();
    

      // Recibe: Un puntero a una criatura para cruzarla con la actual
      // Efectua: Retorna un vector terminado en 0 con los hijos
      Criatura ** cruzar( Criatura * ptr);
	  
      Criatura * inverso();	  
	  
      void mutar();
      
      ostream& imprimir(ostream&);
      
      Criatura * clonar();
     
	  int operator==(Criatura *);


};




#endif