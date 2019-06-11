#include "AmbienteDragon.h"
#include <ctime>
#include <climits>
#include <stdlib.h>
#include <iostream>
using namespace std;

AmbienteDragon::AmbienteDragon(){
	this->setCantidadCriaturas(100);
	this->setNombre("DragonDaenerys");
}

/*
** @Funcion: evalua una criatura DragonDaenerys para determinar que tan apta es de la siguiente forma: se multiplica el valor de su Fuego por el de su Size, 
** y se le resta la distancia que le falta al Angulo para ser el angulo ideal (60)
** @Param: recibe un puntero a Criatura
** @Return: retorna, si se puede, un valor double que indica que tan apta es la criatura
*/
double AmbienteDragon::evaluar(Criatura * ptr){
	//El puntaje ideal es 2500:
	// 25Fuego * 100Size = 2500, sin castigo porque angulo = 60
	//Es decir, el DragonDaenerys ideal tiene Fuego:25, Angulo:60, Size:100
	DragonDaenerys * dragon = dynamic_cast< DragonDaenerys * >( ptr );
	double castigo = 0; //Se le descontara al puntaje segun que tan alejado este el angulo del dragon del valor ideal (60)
	double puntuacion = 0;
	if(dragon){
	   puntuacion = (dragon->getSize()) * (dragon->getFuego());
	 //  cout << "Puntuacion = " << dragon->getSize() << "  *  " << dragon->getFuego() << endl;
	   	if(dragon->getAngulo() > 60){
	   	 	castigo = dragon->getAngulo() - 60;
		}
		if(dragon->getAngulo() < 60){
			castigo = 60 - dragon->getAngulo();
		}
	//	cout << "Castigo = " << castigo << endl;
 	    puntuacion -= castigo;			   
	}
	//El mas alto es el mejor en este ambiente
	return puntuacion;
}

/*
** @Funcion: crea una poblacion inicial de criaturas DragonDaenerys, del tamano especificado por el usuario. Genera cada criatura con valores aleatorios, pero
** siempre dentro de los rangos establecidos para cada atributo 
** @Param: este metodo no requiere ningun parametro
** @Return: retorna un puntero a un objeto poblacion, que es una lista con las criaturas iniciales creadas
*/
Poblacion * AmbienteDragon::crearPoblacionInicial(){
	double fuegoAleatorio = 0;
	double anguloAleatorio = 0;
	double sizeAleatorio = 0;
	DragonDaenerys proto;
	Criatura * inversa;
	Poblacion * poblacionPtr = new Poblacion();
	Poblacion::Iterador fin = poblacionPtr->end();
	for(int i = 0; i < cantidadCriaturas/2; ++i){
		fuegoAleatorio = (rand() % 25) + 1; //Valor aleatorio entre 1 y 25
		anguloAleatorio = (rand() % 180) + 1; //valor aleatorio entre 1 y 180
		sizeAleatorio = (rand() % 100) +1; //Valor aleatorio entre 1 y 100
		proto.setFuego(fuegoAleatorio);
		proto.setAngulo(anguloAleatorio);
		proto.setSize(sizeAleatorio); 
		poblacionPtr->insertar(fin, &proto);
		inversa = proto.inverso();
		poblacionPtr->insertar(fin, inversa);
		delete inversa;
	}
	return poblacionPtr;
}



