#include "DragonBasico.h"
#include "Poblacion.h"
#include <stdlib.h>

DragonBasico::DragonBasico(){
	this->setNombre("DragonBasico");
}

/*
** @Funcion: a partir de una poblacion inicial de Criaturas DragonDaenerys, las cruza, elimina y muta hasta obtener una poblacion con Criaturas ideales, es decir,
** con valores iguales a los valores ideales que se han especificado para estas criaturas. Los 30 mas aptos de cada generacion automaticamente son incluidos 
** en la generacion siguiente. Los espacios restantes se generan al cruzar criaturas de la generacion actual, cada pareja teniendo 2 hijos exactamente iguales, 
** que son incluidos en la generacion siguiente si sus padres son aptos para esto.
** @Param: recibe un puntero a un objeto Poblacion con la lista de criaturas iniciales, es decir, la Generacion Ideal
** @Return: devuelve un puntero a un objeto Poblacion con la lista de criaturas resultantes tras el proceso de evolucion, es decir, una Poblacion Perfecta
*/
Poblacion *  DragonBasico::evolucionar( Poblacion * inicial){
	Poblacion * generacionActual = inicial;
	if(ambientePtr){
		generacionActual = inicial->clonar();
		int padre;
		int madre;
		Poblacion * generacionSiguiente;
		int cantidadGeneraciones = 0;
		int contador = 0;
		int poblacionPerfecta = 0;
		Criatura * criaturas[ambientePtr->getCantidadCriaturas()];
		double puntaje[ambientePtr->getCantidadCriaturas()];
		while(cantidadGeneraciones++ < 80 && !poblacionPerfecta){
			generacionSiguiente = new Poblacion();
			contador = 0;
			for(Poblacion::Iterador generacionActualItr = generacionActual->begin(); generacionActualItr != generacionActual->end(); ++generacionActualItr){
				if(*generacionActualItr){
					puntaje[contador] = ambientePtr->evaluar(*generacionActualItr);
					criaturas[contador++] = *generacionActualItr;
				}
			}
			double tempPuntaje;
			Criatura * tempCriatura;
			for (int l = 0; l < contador - 1; ++l){
				for (int m = 0; m < contador - 1 - l; ++m){
					if (puntaje[m] < puntaje[m + 1]){
						tempPuntaje = puntaje[m];
						tempCriatura = criaturas[m];
						puntaje[m] = puntaje[m + 1];
						criaturas[m] = criaturas[m + 1];
						puntaje[m + 1] = tempPuntaje;
						criaturas[m + 1] = tempCriatura;
					}
				}
			}	
			poblacionPerfecta = puntaje[0] == 2500;
			int posTreinta = (int)(0.3 * contador);
			int cantidadSeleccionados = 0;
			Poblacion::Iterador fin = generacionSiguiente->end();
			for (int j = 0; j < posTreinta; ++j){
				generacionSiguiente->insertar(fin, criaturas[j]);
				cantidadSeleccionados++;
			}		
			while (cantidadSeleccionados < ambientePtr->getCantidadCriaturas() ){
				int padresOK = 0;
				int cortePadre;
				int corteMadre;
				int w = 0;
				int w2=0;
				Criatura **hijo = 0;
				while (!padresOK){
					padre = (int)(((double)rand() / RAND_MAX) * contador);
					madre = (int)(((double)rand() / RAND_MAX) * contador);
					cortePadre = (int)(((double)rand() / RAND_MAX) * contador);
					corteMadre = (int)(((double)rand() / RAND_MAX) * contador);
					padresOK = padre != madre && padre <= cortePadre && madre <= corteMadre;
				}
				hijo = criaturas[padre]->cruzar(criaturas[madre]);
				while (hijo[w] && cantidadSeleccionados < ambientePtr->getCantidadCriaturas()){
					generacionSiguiente->insertar(fin, hijo[w]);
					if(cantidadSeleccionados < ambientePtr->getCantidadCriaturas()){
						generacionSiguiente->insertar(fin, hijo[w]->clonar());
						cantidadSeleccionados++;
					}
					cantidadSeleccionados++;
					++w;
				}
				w2=0;
				while (hijo[w2]) {
					delete hijo[w2];
					++w2;
				}				
				delete[] hijo;
			}
			int corteMutuacion = PROBABILIDAD_MUTUACION;
			int probabilidad =  (int) (((double)rand() / RAND_MAX) * 100);
			cout << "Probabilidad de mutuacion: " << probabilidad << endl;
			if(probabilidad <= corteMutuacion){
				int criaturaAMutar = (int) (((double)rand() / RAND_MAX) * contador);
				criaturas[criaturaAMutar]->mutar();
				std::cout << "La criatura numero " << criaturaAMutar + 1 << " ha mutado!" << std::endl;
			}
			cout << endl;
			cout << "TESTING.. GENERACION ACTUAL" << endl;
			cout << " " << generacionSiguiente << endl;
			delete generacionActual;
			generacionActual = generacionSiguiente;
			cout << "Termina generacion " << cantidadGeneraciones << endl;
		}
	}
	return generacionActual;
}
