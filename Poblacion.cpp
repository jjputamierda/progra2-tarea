#include "Poblacion.h"

Poblacion::Celda::Celda(Criatura * elemento){
   anterior = 0;
   siguiente = 0;
   if(elemento){
      this->elemento = elemento->clonar();   
   }
   else {
	  this->elemento=elemento; 
   }
}
Poblacion::Celda::~Celda(){ 
  if(siguiente){
	  delete siguiente;
  }
  if(elemento){
	delete elemento;
  }
}

Poblacion::Iterador::Iterador(){
	actual = 0;
}

Poblacion::Iterador::Iterador(Celda * actual){
	this->actual = actual;
}

/*
** @Funcion: realiza un preincremento a la posicion del iterador en la lista Poblacion
** @Param: este metodo no requiere ningun parametro
** @Return: retorna un objeto Iterador, por referencia, colocado en la posicion siguiente a la que tenia originalmente 
*/
Poblacion::Iterador & Poblacion::Iterador::operator++(){
	if(actual){
		actual = actual->siguiente;
	}
    return *this;
}

/*
** @Funcion: crea un nuevo objeto Iterador en la posicion actual y le realiza un posincremento a la poisicion del iterador en la lista Poblacion
** @Param:  recibe un valor entero para diferencar su firma del metodo operator++()
** @Return: retorna un objeto iterador, por copia, colocado en la posicion original que se tenia al inicio del metodo
*/
Poblacion::Iterador Poblacion::Iterador::operator++(int noSeUsa){
	Iterador viejo(actual);
    ++(*this);
	return viejo;
}

/*
** @Funcion: determina si el iterador que invoca el metodo apunta a una celda con el mismo elemento que la celda actual a la que apunta un iterador recibido 
** por referencia
** @Param: recibe un objeto Iterador por referencia, para compararlo con el Iterador que invoca el metodo
** @Return: retorna un 1 si los elementos de sus celdas actuales son iguales y un 0 en caso contrario
*/
int Poblacion::Iterador::operator==(const Poblacion::Iterador & otro){
	return this->actual == otro.actual;
}

/*
** @Funcion: determina si el iterador que invoca el metodo apunta a una celda con un elemento distinto a la celda actual a la que apunta un iterador recibido
** por referencia
** @Param: recibe un objeto iterador por referencia, para compararlo con el Iterador que invoca el metodo
** @Return: retorna un 1 si los elementos de sus celdas actuales son diferentes y un 0 en caso contrario
*/
int Poblacion::Iterador::operator!=(const Poblacion::Iterador & otro){
	return this->actual != otro.actual;	
}

/*
** @Funcion: permite desreferenciar el objeto Iterador para acceder al elemento que se encuentra en la celda a la cual apunta
** @Param: este metodo no requiere ningun parametro
** @Return: retorna un puntero a un objeto criatura, por referencia
*/
Criatura * & Poblacion::Iterador::operator*(){
	return actual->elemento;
}

/*
** @Funcion: crea una poblacion exactamente igual a la poblacion que invoca el metodo, sin enmaranar la memoria
** @Param: este metodo no requiere ningun parametro
** @Return: retora un puntero a un objeto poblacion, que es una copia exacta de la poblacion que invoca el metodo
*/
Poblacion * Poblacion::clonar(){
	Poblacion * nuevaPtr = new Poblacion();	   
	Poblacion::Iterador fin = nuevaPtr->end();
    for( Poblacion::Iterador i = this->begin(); i != this->end(); ++i){
         nuevaPtr->insertar(fin,*i);
	}
	return nuevaPtr;
}


Poblacion::Poblacion(){
	primera = 0;
	ultima = 0;
}

Poblacion::~Poblacion(){
   if(primera){
      delete primera;	   
   }
}

/*
** @Funcion: crea un iterador colocado en la primera celda de la lista poblacion
** @Param: este metodo no requiere ningun parametro
** @Return: retorna un objeto iterador colocado al inicio de la lista
*/
Poblacion::Iterador Poblacion::begin(){
	Iterador iterador(primera);
	return iterador;
}

/*
** @Funcion: crea un iterador colocado al final de la lista poblacion
** @Param: este metodo no requiere ningun parametro
** @Return: devuelve un iterador colocado al final de la  lista
*/
Poblacion::Iterador Poblacion::end(){
	Iterador iterador;
	return iterador;
}

/*
** @Funcion: inserta una criatura en una celda determinada por un iterador, todo recibido por parametro
** @Param: recibe un objeto iterador, por referencia, para saber donde debe insertar la nueva celda, y un puntero a objeto Criatura para guardarlo dentro de
** esa celda
** @Return: este metodo no retorna ningun valor
*/
void Poblacion::insertar(Poblacion::Iterador & iterador, Criatura * valor){
	Celda * nueva = new Celda( valor );
	if(iterador==begin()){
	    if(!primera){
			primera = nueva;
			ultima = nueva;
		}
        else {
			nueva->siguiente = primera;
			primera->anterior = nueva;
			primera = nueva;
		}		
	}
	else {
		if(iterador==end()){
			nueva->anterior=ultima;
			ultima->siguiente = nueva;
			ultima = nueva;
		}
		else {
			nueva->anterior = iterador.actual->anterior;
			nueva->siguiente = iterador.actual;
			nueva->anterior->siguiente = nueva;
			nueva->siguiente->anterior = nueva;
			// iterador.actual->anterior = nueva;			
		}	
	}
}

/*
** @Funcion: imprime el contenido de una celda en un flujo de salida recibido como parametro
** @Param: recibe un flujo de salida, por referencia
** @Return: retorna ese mismo flujo de salida con los datos listos para ser impresos
*/
ostream& Poblacion::imprimir( ostream& salida ){
   Poblacion::Iterador inicioIterator = begin();
   Poblacion::Iterador finalIterator = end();
   
   for(Poblacion::Iterador it = inicioIterator; it!= finalIterator; ++it){
      salida << *it;
      salida << " ";
   } 
   
   return salida;
}


















