#ifndef CRIATURAMOCHILA
#define CRIATURAMOCHILA
#include "Criatura.h"
#include "ListaP.h"
#include <string>
#include <random>
class CriaturaMochila: public Criatura {
   friend class AmbienteEntero;
   private:
      double peso;
      double precio;
      int * piedras;
	   double calificacion;
      int size;
      string uP;
      string uD;
      ListaP * lp;
   public:
      CriaturaMochila();   
      CriaturaMochila(CriaturaMochila &);
      CriaturaMochila(ListaP &);
	   ~CriaturaMochila();
	  
     double getPeso();
     double getPrecio();
     int getPosP(int);
     int getSize(); 
     int * getP();
     ListaP & getLP(); 
     string getuP(); 
     string getuD();
      CriaturaMochila & setPeso( ListaP &);
      CriaturaMochila & setPrecio( ListaP &);
      CriaturaMochila & setPosP(int,int);
      CriaturaMochila & setSize(int);
      CriaturaMochila & setLP(ListaP &);
      CriaturaMochila & setuP(string);
      CriaturaMochila & setuD(string);
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