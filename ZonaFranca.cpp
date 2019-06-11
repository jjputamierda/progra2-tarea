#include "ZonaFranca.h"


ZonaFranca::ZonaFranca(){
	ambienteCounter = 0;
	algoritmoCounter = 0;
//	ambiente[ambienteCounter++] = new AmbienteEntero();
	ambiente[ambienteCounter++] = new AmbienteDragon();
  //  ambiente[ambienteCounter++] = new AmbienteMochila();
	// ambiente[ambienteCounter++] = new OTRO_AMBIENTE_MAS();
    // Y PUEDEN AGREGAR LINEAS MAS LINEA SIMILARES
    
//	algoritmo[algoritmoCounter++] = new GeneticoBasico();
	algoritmo[algoritmoCounter++] = new DragonBasico();
    //algoritmo[algoritmoCounter++] = new SuperGenetico();
    // 	algoritmo[algoritmoCounter++] = new Y_SOLO_ESTO_OTRO_PUEDEN_TOCAR();
    // O AGREGAR LINEAS SIMILARES
}

ZonaFranca::~ZonaFranca(){
  for(int i=0; i< ambienteCounter; ++i){
     delete ambiente[i];
  }
  for(int j=0; j< algoritmoCounter; ++j){
     delete algoritmo[j];
  }	  
}

/*
** @Funcion: crea un objeto Ambiente a partir de los datos suministrados por el usuario
** @Param: recibe un  a char que indica el nombre del ambiente que se desea construir, ademas de un valor entero que determina la cantidad de
** criatuas iniciales que se tendran en dicho ambiente
** @Return: retorna un puntero a un objeto de tipo Ambiente, especificamente del Ambiente deseado, con la cantidad de criaturas indicada 
*/
Ambiente * ZonaFranca::nuevoAmbiente(char * nombre, int cantidadCriaturas){
   Ambiente * seleccionado = 0;
   for(int i=0; !seleccionado && i < ambienteCounter; ++i){
	    if(ambiente[i] && ambiente[i]->esUsted(nombre)){
			seleccionado = ambiente[i];
			seleccionado->setCantidadCriaturas(cantidadCriaturas);
		}   
   }
   return seleccionado;
}

/*
** @Funcion: crea un objeto Algoritmo a partir de los datos suministrados por el usuario
** @Param: recibe un puntero a valores char que indica el nombre del ambiente que se desea construir
** @Return: retorna un puntero a un objeto de tipo algoritmo, especificamente del Algoritmo deseado
*/
Algoritmo * ZonaFranca::nuevoAlgoritmo(char * nombre){
   Algoritmo * seleccionado = 0;
   for(int i=0; !seleccionado && i < algoritmoCounter; ++i){
	    if(algoritmo[i] && algoritmo[i]->esUsted(nombre)){
			seleccionado = algoritmo[i];	
		}   
   }
   return seleccionado;
}
