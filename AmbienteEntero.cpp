#include "AmbienteEntero.h"
#include<ctime>
#include<climits>
AmbienteEntero::AmbienteEntero(){
	this->setCantidadCriaturas(100);
	this->setNombre("CriaturaEntera");
}

/*
** @Funcion: evalua una criaturaEntera para determinar que tan apta es
** @Param: recibe un puntero a objetos Criatura
** @Return: devuelve un valor que determina la aptitud de la criatura, siendo 1 el mejor y 0 el peor
*/
double AmbienteEntero::evaluar(Criatura * ptr){
    CriaturaEntera * ptrE = dynamic_cast< CriaturaEntera * >( ptr );
	double ajuste = 0;
	if(ptrE){
	   if(ptrE->getValor() < 0){
 	         ajuste = 1.0 + ((double) ptrE->getValor() / (double) INT_MAX);			   
	   }
	   else {
		   	 ajuste = 1.0 - ((double) ptrE->getValor() / (double) INT_MAX);	
	   }
	}
	// 1 es el mejor
	// 0 es el peor
	// El que esta mas cerca de 0 es el mejor en este ambiente...
	return ajuste;
}

/*
** @Funcion: crea una poblacion inicial de criaturas CriaturaEntera, del tamano especificado por el usuario. Genera cada criatura con valores aleatorios, pero
** siempre dentro de los rangos establecidos para cada atributo 
** @Param: este metodo no requiere ningun parametro
** @Return: retorna un puntero a un objeto poblacion, que es una lista con las criaturas iniciales creadas
*/
Poblacion * AmbienteEntero::crearPoblacionInicial(){
	int aleatorio = 0;
	CriaturaEntera proto;
	
    Criatura * inversa;
    Poblacion * poblacionPtr = new Poblacion();
    Poblacion::Iterador fin = poblacionPtr->end();

	for(int i=0; i< cantidadCriaturas/2 ; ++i){
	   aleatorio = (int) (rand() * INT_MAX) + 1;
	   proto.setValor(aleatorio);
	   poblacionPtr->insertar( fin , &proto );
       inversa = proto.inverso();
	   poblacionPtr->insertar( fin , inversa );
       delete inversa;	   
	}
	
	return poblacionPtr;
}	  	  
