#ifndef LISTAP
#define LISTAP
#include "Piedra.h"
class ListaP  {
   class Celda;
   private:
      Celda * primera;
	  Celda * ultima;
      Celda * mayor;
      int size;
      double precio;
   class Celda {
      public:
         Piedra * elemento;
	     Celda * anterior;
	     Celda * siguiente;
	     Celda( Piedra *);
		 ~Celda();
         ostream & imprimir( ostream &,string,string);
         ostream & imprimir( ostream & ,string,string,int * ,int );    
   
   };
   
   public:
      
	  class Iterador {
		 friend class ListaP; // Para solo la lista pueda acceder a los campos de la celda mediante el puntero actual
	     private:
		    Celda * actual;
	     public:
            Iterador();
            Iterador(Celda *);
            Iterador & operator++();
            Iterador operator++(int);
            int operator==(const Iterador &);
            int operator!=(const Iterador &);
	         //Iterador & operator=(const Iterador &);
            Iterador & getI();
           Piedra * & operator*();
	  };
	  
	  ListaP();
	  ~ListaP();
	  
     const Iterador begin();
	  const Iterador end();
	  void insertar(Iterador &,Piedra*);
      ostream & imprimir( ostream &,string,string);
      ostream & imprimir( ostream & salida,string s, string r,int *,int);
      double getPrecio();
      ListaP & setPrecio (double);
      ListaP & swap ( Piedra * , Piedra * );
      ListaP & quickSort(Celda* l, Celda *h);
      ListaP & quickSort();
      double getSize();
      
};
#endif