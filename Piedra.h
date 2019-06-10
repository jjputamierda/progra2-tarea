#ifndef PIEDRA
#define PIEDRA
#include<iostream>
#include<string>
using namespace std;
class Piedra {
   
   private:
      double peso;
      double precio;
	  
   public:
     Piedra();   
     Piedra(char *);
	  Piedra &  setPeso(double);
     Piedra & setPrecio(double);
     double getPeso();
     double getPrecio();
    Piedra & operator=(const Piedra &);
    int operator>(const Piedra &);
    // ~Piedra();
	  
      // Recibe: Un puntero a una criatura para cruzarla con la actual
      // Efectua: Retorna un vector terminado en 0 con los hijos
      //Criatura ** cruzar( Criatura * ptr);
	  
      //Criatura * inverso();	  
	  
      //void mutar();
      
      ostream& imprimir(ostream&,string,string);
      
      
      //Criatura * clonar();
     
	  //int operator==(Criatura *);


};




#endif