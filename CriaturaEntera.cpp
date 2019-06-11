#include "CriaturaEntera.h"
#include<ctime>
#include<climits>
#include <stdlib.h>


CriaturaEntera::CriaturaEntera(){
	this->valor = 0;
}
CriaturaEntera::CriaturaEntera(int valor){
	this->valor = valor;
}

CriaturaEntera & CriaturaEntera::setValor(int valor){
	this->valor = valor;
	return *this;
}
	 
int CriaturaEntera::getValor(){
	return valor;
}

/*
** @Funcion: imprime los valores de una CriaturaEntera en el flujo de salida recibido como parametro
** @Param: recibe un flujo de salida donde colocar los datos de la Criatura
** @Return: retorna ese mismo flujo de salida con los datos listos para imprimir 
*/	 
ostream& CriaturaEntera::imprimir(ostream& salida){
   salida << valor;
   return salida;   
}

/*
** @Funcion: crea una Criatura con los mismos valores que la Criatura que invoca el metodo, sin enmaranar la memoria
** @Param: este metodo no requiere ningun parametro
** @Return: retorna un puntero a un objeto Criatura, con los mismos valores de la Criatura que invoca el metodo 
*/
Criatura * CriaturaEntera::clonar(){
	CriaturaEntera * nuevaPtr = new CriaturaEntera(valor);
	return nuevaPtr;
}

/*
** @Funcion: metodo sobrecargado que determina si los valores de 2 CriaturasEnteras son iguales
** @Param: recibe un puntero a un objeto Criatura
** @Return: devuelve un 1 si los valores de las CriaturasEnteras son iguales y un 0 en caso contrario o si el puntero recibido no corresponde a una CriaturaEntera
*/
int CriaturaEntera::operator==(Criatura * criaturaPtr){
	
	CriaturaEntera * criaturaEnteraPtr = dynamic_cast< CriaturaEntera * >( criaturaPtr );
	
	return criaturaEnteraPtr && criaturaEnteraPtr->valor == this->valor;
}

/*
** @Funcion: recibe un puntero a una Criatura y la cruza con la Criatura que invoca al metodo, para generar otra Criatura con valores cercanos al promedio de 
** sus padres
** @Param: recibe un puntero a objeto Criatura, que sera cruzada con la criatura que invoca el metodo 
** @Return: devuelve un puntero a un vector de punteros de Criatura, con 2 espacios; el primero con el hijo de ambas Criaturas padres y el segundo espacio 
** con un 0 para indicar que termina el vector 
*/
Criatura ** CriaturaEntera::cruzar( Criatura * ptr){
	Criatura * * hijo = 0;
	if(ptr){
  	   CriaturaEntera * enteraPtr = dynamic_cast< CriaturaEntera *>(ptr);	
       hijo = new Criatura * [2]; // Solo tiene un hijo promedio
	   hijo[0] = new CriaturaEntera( (this->valor + enteraPtr->valor )/2 );
       hijo[1]=0; // El ultimo puntero es nulo
	}
	return hijo;
}

/*
** @Funcion: crea una Criatura con los valores inversos a los de la Criatura que invoca el metodo
** @Param: este metodo no necesita ningun parametro
** @Return: retorna un puntero a un objeto Criatura, que tendra los valores inversos a la Criatura que invoco al metodo
*/
Criatura * CriaturaEntera::inverso(){
	return new CriaturaEntera((valor>0)? (INT_MAX - valor) : (INT_MAX + valor));	
}	  

/*
** @Funcion: determina un numero aleatorio que, dependiendo de su valor, es sumado o restado al valor de la criatura que muta
** @Param: este metodo no requiere ningun parametro
** @Return: este metodo no retorna ningun valor
*/ 
void CriaturaEntera::mutar(){
	int mutacion = (int)(rand()*INT_MAX);
	if(rand()>0.5){
       valor+= mutacion;
	}
	else {
       valor-= mutacion;		
	}
}

