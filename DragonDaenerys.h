//Criatura: Dragones de Daenerys
#ifndef CRIATURAGOT
#define CRIATURAGOT
#include "Criatura.h"

class DragonDaenerys : public Criatura {
	friend class AmbienteDragones;
	private:
		double fuego;  // 1 - 25      Valor Ideal: 25    (El dragon puede escupir mas fuego)
		double size;   // 1 - 100     Valor Ideal: 100   (Mientras mas grande el dragon, mas fuego pueden lanzar)
		double angulo; // 1 - 180     Valor Ideal: 60    (Ese es el angulo exacto que necesita Daenerys para quemar King's Landing)
	public:
		DragonDaenerys();
		DragonDaenerys(double, double, double);
		DragonDaenerys & setFuego(double);
		DragonDaenerys & setSize(double);
		DragonDaenerys & setAngulo(double);
		double getFuego();
		double getSize();
		double getAngulo();
		double masCercanoA60(double, double); //Recibe dos angulos y determina cual esta mas cerca de 60
		double acercarA60(double); //Recibe un valor y lo retorna con una unidad mas o una unidad menos, para acercarlo a 60
		Criatura ** cruzar( Criatura * ptr);
        Criatura * inverso();	   
        void mutar();
        ostream& imprimir(ostream&);
        Criatura * clonar();
	    int operator==(Criatura *);
};
#endif
