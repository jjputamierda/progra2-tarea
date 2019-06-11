//DragonDaenerys.cpp
#include "DragonDaenerys.h"
#include <ctime>
#include <climits>
#include <stdlib.h>
#define RANDMAX 5

DragonDaenerys::DragonDaenerys(){
	this->fuego = 0;
	this->angulo = 0;
	this->size = 0;
}

DragonDaenerys::DragonDaenerys(double fuego, double angulo, double size){
	this->fuego = fuego;
	this->angulo = angulo;
	this->size = size;
}

DragonDaenerys & DragonDaenerys::setFuego(double fuego){
	this->fuego = fuego;
	return *this;
}

DragonDaenerys & DragonDaenerys::setAngulo(double angulo){
	this->angulo = angulo;
	return *this;
}

DragonDaenerys & DragonDaenerys::setSize(double size){
	this->size = size;
	return *this;
}

double DragonDaenerys::getFuego(){
	return fuego;
}

double DragonDaenerys::getAngulo(){
	return angulo;
}

double DragonDaenerys::getSize(){
	return size;
}

/*
** @Funcion: recibe dos valores double, determina cual esta mas cerca de 60 y devuelve el valor del mas cercano a 60. Si ambos estan
** a la misma distancia absoluta de 60, devuelve el numero menor
** @Param: recibe dos valores double para determinar cual esta mas cerca de 60
** @Retorno: devuelve el valor del numero mas cercano a 60. En caso de empate, devuelve el numero menor
*/
double DragonDaenerys::masCercanoA60(double primero, double segundo){ 
	double primeroAbs = 0; //Valor absoluto del primero
	double segundoAbs = 0;
	double retorno = 0;
	if(primero > 60){
		primeroAbs = primero - 60;
	}
	else{
		primeroAbs = 60 - primero;
	}
	if(segundo > 60){
		segundoAbs = segundo - 60;
	}
	else{
		segundoAbs = 60 - segundo;
	}
	retorno = primero;
	if(primeroAbs > segundoAbs){
		retorno = segundo;
	}
	return retorno;
}

/*
** @Funcion: recibe un angulo y lo acerca a 60, sumandole o restandole un 1 entero. Si el angulo recibido necesita menos de 1 para
** ser 60, automaticamente es convertido en 60. Ej: si se recibe un 59.3, se devuelve un 60
** @Param: recibe un valor double, que es el angulo a acercar a 60
** @Retorno: retorna un valor mas cercano a 60, a partir del angulo recibido
*/
double DragonDaenerys::acercarA60(double angulo){
	double retorno = angulo;
	if(angulo != 60 ){ //Solo se acercara si es distinto de 60
		if(angulo >= 61){ //Si el angulo es mayor que 60 en por lo menos 1 unidad
			--retorno; //Se le resta 1 para acercarlo a 60
		}
		if(angulo <= 59){ //Si el angulo es menor que 60 en por lo menos 1 unidad
			++retorno;
		}
		if(angulo > 59 && angulo < 61){ //Si el angulo esta entre 59 < x < 61
			retorno = 60;
		}
	}
	return retorno;
}

//Forma de cruzarlos:  
//size:    promedio de los padres  +2
//fuego:   promedio de los padres  +1
//angulo:  hereda el angulo de los padres que este mas cerca de 60 y le agrega o quita una unidad para acercarlo aun mas a 60
/*
** @Funcion: recibe un puntero a una Criatura y la cruza con la Criatura que invoca al metodo, para generar otra Criatura con valores cercanos al promedio de 
** sus padres
** @Param: recibe un puntero a objeto Criatura, que sera cruzada con la criatura que invoca el metodo 
** @Return: devuelve un puntero a un vector de punteros de Criatura, con 2 espacios; el primero con el hijo de ambas Criaturas padres y el segundo espacio 
** con un 0 para indicar que termina el vector 
*/
Criatura ** DragonDaenerys::cruzar( Criatura * ptr){
	Criatura * * hijo = 0;
	if(ptr){
  	   DragonDaenerys * otroDragon = dynamic_cast< DragonDaenerys *>(ptr);	
       hijo = new Criatura * [2]; // Solo tiene un hijo promedio
       double hFuego = (this->fuego + otroDragon->fuego)/2 + 1; //hFuego = fuego del dragon hijo
       double hAngulo = masCercanoA60(this->angulo, otroDragon ->angulo);
       hAngulo = otroDragon->acercarA60(hAngulo);
      // double hAngulo = (this->angulo) //PENDIENTE
       double hSize =  (this->size + otroDragon->size)/2 +2;   //hSize = size del dragon hijo
       if(hFuego > 25){
   			 hFuego = 25;
	   }
	   if(hSize > 100){
 			hSize = 100;
	   }
	   hijo[0] = new DragonDaenerys( hFuego, hAngulo, hSize );
       hijo[1]=0; // El ultimo puntero es nulo
	}
	return hijo;
}

/*
** @Funcion: crea una Criatura con los valores inversos a los de la Criatura que invoca el metodo
** @Param: este metodo no necesita ningun parametro
** @Return: retorna un puntero a un objeto Criatura, que tendra los valores inversos a la Criatura que invoco al metodo
*/
Criatura * DragonDaenerys::inverso(){
	double nFuego = 25 - fuego; //Nuevo fuego
	double nAngulo = 180 - angulo;
	double nSize = 100 - size;
	if(nFuego < 1){
		nFuego = 1;
	}
	if(nAngulo < 1){
		nAngulo = 1;
	}
	if(nSize < 1){
		nSize = 1;
	}
	return new DragonDaenerys(nFuego, nAngulo, nSize);	
} 

/*
** @Funcion: determina un numero aleatorio entre 0 y 2, ademas de un numero de probabilidad (rand). Si este numero es mayor a 2.5, se le suma el numero aleatorio
** al Size de la criatura; caso contrario, se le resta
** @Param: este metodo no requiere ningun parametro
** @Return: este metodo no retorna ningun valor
*/
void DragonDaenerys::mutar(){
	int mutacion = (int)(rand()*RANDMAX)%2;
	if(rand()>2.5){
       size+= mutacion;
	}
	else {
       size-= mutacion;		
	}
	if(size > 100){ //Siempre se mantienen dentro de los valores especificados
		size = 100;
	}
	if(size < 1){
		size = 1;
	}
}

/*
** @Funcion: imprime los valores de una Criatura DragonDaenerys en el flujo de salida recibido como parametro
** @Param: recibe un flujo de salida donde colocar los datos de la Criatura
** @Return: retorna ese mismo flujo de salida con los datos listos para imprimir 
*/
ostream& DragonDaenerys::imprimir(ostream& salida){
	salida << "[Fuego: " << fuego << " Angulo: " << angulo << " Size: " << size << " ]  "  << endl;
	return salida;
}

/*
** @Funcion: crea una Criatura con los mismos valores que la Criatura que invoca el metodo, sin enmaranar la memoria
** @Param: este metodo no requiere ningun parametro
** @Return: retorna un puntero a un objeto Criatura, con los mismos valores de la Criatura que invoca el metodo 
*/
Criatura * DragonDaenerys::clonar(){
	DragonDaenerys * nuevaPtr = new DragonDaenerys(fuego, angulo, size);
	return nuevaPtr;
}

/*
** @Funcion: metodo sobrecargado que determina si los valores de 2 Criaturas DragonDaenerys son iguales
** @Param: recibe un puntero a un objeto Criatura
** @Return: devuelve un 1 si los valores de los DragonDaenerys son iguales y un 0 en caso contrario o si el puntero recibido no corresponde a un DragonDaenerys
*/
int DragonDaenerys::operator==(Criatura * otroDragon){
	DragonDaenerys * dragonDaenerysPtr = dynamic_cast< DragonDaenerys * >( otroDragon);
	
	return dragonDaenerysPtr && dragonDaenerysPtr->fuego == this->fuego   && dragonDaenerysPtr->angulo == this->angulo   && dragonDaenerysPtr->size == this->size;
}
