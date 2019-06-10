#include "ListaP.h"
using namespace std;
ListaP::Celda::Celda(Piedra * elemento){
   anterior = 0;
   siguiente = 0;
   
   
   if(elemento){
      this->elemento = elemento;  
      
   }
   
}

ListaP::Celda::~Celda(){ 
  if(siguiente){
	  delete siguiente;
  }
  if(elemento){
	delete elemento;
  }
}


ostream & ListaP::Celda::imprimir( ostream & salida,string s,string r){
	
	this->elemento->imprimir(salida,s,r);
	if(siguiente){
		
			siguiente->imprimir(salida,s,r);
		
		
	}
	return salida;
}
ostream & ListaP::Celda::imprimir( ostream & salida,string s,string r,int * v,int i){
	if(v[i]==1){
		this->elemento->imprimir(salida,s,r);
	    //salida<<"i ="<<i<<endl;
	} 
	i++;
	if(siguiente){
		   salida<<i<<endl;
			siguiente->imprimir(salida,s,r,v,i);
		
		
	}
	return salida;
}
ListaP::Iterador::Iterador(){
	actual = 0;
}

ListaP::Iterador::Iterador(Celda * actual){
	this->actual = actual;
}
ListaP::Iterador &  ListaP::Iterador::getI(){
    return *this;
}
ListaP::Iterador & ListaP::Iterador::operator++(){
	if(actual){
		actual = actual->siguiente;
	}
    return *this;
}
/*
ListaP::Iterador & ListaP::Iterador::operator=(const Iterador & i){
	this->actual = i.actual;
	return * this;
}
*/
ListaP::Iterador ListaP::Iterador::operator++(int noSeUsa){
	Iterador viejo(actual);
    ++(*this);
	return viejo;
}

int ListaP::Iterador::operator==(const Iterador & otro){
	return this->actual == otro.actual;
}


int ListaP::Iterador::operator!=(const Iterador & otro){
	return this->actual != otro.actual;	
}
Piedra * & ListaP::Iterador::operator*(){
	return actual->elemento;
}

ListaP::ListaP(){
	primera = 0;
	ultima = 0;
    mayor =0;
    this->size =0;
    this->precio = 0;
    
}

ListaP::~ListaP(){
   if(primera){
      delete primera;	   
   }
   
}

const ListaP::Iterador ListaP::begin(){
	Iterador iterador(primera);
	return iterador;
}
const ListaP::Iterador ListaP::end(){
	Iterador iterador;
	return iterador;
}
ListaP & ListaP::swap (  Piedra * a,  Piedra * b ){ 
	Piedra  t; t.setPrecio(a->getPrecio());  t.setPeso(a->getPeso());   
	a->setPrecio(b->getPrecio());  a->setPeso(b->getPeso());
    b->setPrecio(t.getPrecio());  b->setPeso(t.getPeso());
	//(a) = (b); (b) = t; 
    return *this;
}  
  
// A utility function to find 
// last node of linked list  

  
/* Considers last element as pivot,  
places the pivot element at its  
correct position in sorted array,  
and places all smaller (smaller than  
pivot) to left of pivot and all greater 
elements to right of pivot */
/*
Celda * ListaP::Celda::partition(Celda *l, Celda*h)  
{  
    // set pivot as h element  
    double x = h->elemento->getPrecio();  
  
    // similar to i = l-1 for array implementation  
    Celda *i = l->anterior;  
  
    // Similar to "for (int j = l; j <= h- 1; j++)"  
    for (Celda *j = l; j != h; j = j->siguiente)  
    {  
        if (j->elemento->getPrecio() <= x)  
        {  
            // Similar to i++ for array  
            i = (i == NULL)? l : i->siguiente;  
  
            swap(&(i->elemento), &(j->elemento));  
        }  
    }  
    i = (i == NULL)? l : i->siguiente; // Similar to i++  
    swap(&(i->elemento), &(h->elemento));  
    return i;  
}  
*/ 
/* A recursive implementation  
of quicksort for linked list */
ListaP & ListaP::quickSort(Celda* l, Celda *h)  
{  
    if (h != NULL && l != h && l != h->siguiente)  
    {  
        double x = h->elemento->getPrecio();  
  
    // similar to i = l-1 for array implementation  
    Celda *i = l->anterior;  
  
    // Similar to "for (int j = l; j <= h- 1; j++)"  
    for (Celda *j = l; j != h; j = j->siguiente)  
    {  
        if (j->elemento->getPrecio() > x)  
        {  
            // Similar to i++ for array  
            i = (i == NULL)? l : i->siguiente;  
  
            swap( (i->elemento),  (j->elemento)); 

        }  
    }  
    
    i = (i == NULL)? l : i->siguiente; // Similar to i++  
    swap((i->elemento), (h->elemento));  
    
         
        quickSort(l, i->anterior);  
        quickSort(i->siguiente, h);  
    }  
return *this;
}  
  
// The main function to sort a linked list. 
// It mainly calls _quickSort()  
ListaP & ListaP::quickSort()  
{  
    // Find last node  
      
  
    // Call the recursive QuickSort  
    quickSort(primera, ultima);  
    return *this;
}
double ListaP::getSize(){
   return this->size;
}
ostream & ListaP::imprimir( ostream & salida,string s, string r){

if(primera){
   primera->imprimir(salida,s,r);
	}
return salida;
}
ostream & ListaP::imprimir( ostream & salida,string s, string r,int * v,int i){

if(primera){
   primera->imprimir(salida,s,r,v,i);
	}
return salida;
}
double ListaP::getPrecio(){
	return this->precio;
}
      
void ListaP::insertar(ListaP::Iterador & iterador, Piedra * valor){
	Celda * nueva = new Celda( valor );
	if(iterador==begin()){
	    if(!primera){
			primera = nueva;
			ultima = nueva;
		    this->precio = this->precio + valor->getPrecio();
		    this->size++;
		}
        else {
			
			nueva->siguiente = primera;
			primera->anterior = nueva;
			primera = nueva;
		    this->precio = this->precio + valor->getPrecio();
		    this->size++;
		}		
	}
	else {
		if(iterador==end()){
			
			nueva->anterior=ultima;
			ultima->siguiente = nueva;
			ultima = nueva;
		    this->precio = this->precio + valor->getPrecio();
		    this->size++;
		}
		else {
			
			nueva->anterior = iterador.actual->anterior;
			nueva->siguiente = iterador.actual;
			nueva->anterior->siguiente = nueva;
			nueva->siguiente->anterior = nueva;
			this->precio = this->precio + valor->getPrecio();
			this->size++;
			// iterador.actual->anterior = nueva;			
		}	
	}
}