#include "AmbienteMochila.h"
#include<ctime>
#include<climits>
#include<fstream>
AmbienteMochila::AmbienteMochila(){
	this->setNombre("CriaturaMochila");
    
    string archivo;


    cout<<"Cual es el nombre del archivo que contine las piedras?"<<endl;
    cin>>archivo;
    cout<<"Cual es el la unidad de peso?"<<endl;
    cin>>this->uPeso; 
    cout<<"Cual es el la unidad del dinero?"<<endl;
    cin>>this->uDinero;
    ifstream entrada(archivo);
    char buffer[100]; 
    ListaP lp;  
    ListaP::Iterador i = lp.begin(); 
    while(!entrada.eof()){
    entrada.getline(buffer,100);
    //Piedra p;
    //p.imprimir(cout,u,m);
    Piedra * p2 = new Piedra (buffer);
    //cout << "Se imprime la piedra : " << endl;
    //p2->imprimir(cout,u,m);
    lp.insertar(i,p2);

    //lp.imprimir(cout,u,m);

    }
    cout<<"Cual es el tope de peso de la mochila?"<<endl;
    i = lp.end();
    double temporal = 0.0;
    cin>>temporal;
    Piedra p = * (*i);
    /*
    while(temporal<p.getPeso()){
    	cout<<"ESTE TOPE NO ES VALIDO, INTRODUZCA UN TOPE MAYOR, DE LO CONTRARIO NO SE PUEDE PROSEGUIR"<<endl;
    }
    */
    this->tope = temporal;
    lp.imprimir(cout,uPeso,uDinero);
    cout<<"Lista ordenada"<<endl;
    lp.quickSort();
    lp.imprimir(cout,uPeso,uDinero);
    this->lp = & lp;
//cout<<"l2"<<endl;
//lp.quickSort();
//lp.imprimir(cout,u,m);
    int size = lp.getSize();
//ListaP::Iterador * i2 = new ListaP::Iterador ();
//ListaP l2(lp,i2);
//l2.quickSort();
//l2.imprimir(cout,u,m);
    cout<<size<<endl;
/*
for(int w = 0; w<1;w++){
	i = lp.begin();
    CriaturaMochila c(size, lp);
    c.setuP(u);
    c.setuD(m);
    c.setLP(lp);
    //cout<<"LISTA PRUEBA"<<endl;
    //lp.imprimir(cout,u,m);
    cout<<"Esta es la CriaturaMochila "<<w<<endl;
    c.imprimir(cout);
    //lp.imprimir(cout,u,m);
    //dynamic_cast< CriaturaEntera * >( criaturaPtr )
    Criatura * c2 = c.inverso();
    c2 = dynamic_cast< CriaturaMochila * >( c2 );
    //c.setuP(u);
    //c.setuD(m);
    c2->imprimir(cout);
    c.mutar();
    c.imprimir(cout);

}
*/
}
double AmbienteMochila::evaluar(Criatura * ptr){
    CriaturaMochila * c = dynamic_cast< CriaturaMochila * >( ptr );
	double calificacion = 0;
	if(c){
	   if(c->getPeso()>this->tope){
             calificacion =0;
	   }
	   else{
            calificacion = c->getPrecio()/this->lp->getPrecio();
	   }
	}
	// 1 es el mejor
	// 0 es el peor
	// El que esta mas cerca de 0 es el mejor en este ambiente...
	return calificacion;
}
double AmbienteMochila::getTope(){
    return this->tope;
}
AmbienteMochila & AmbienteMochila::setTope(double tope){
   this->tope = tope;
   return *this;
}
AmbienteMochila & AmbienteMochila::setuDinero(string uDinero){
	this->uDinero = uDinero;
    return *this;
}
AmbienteMochila & AmbienteMochila::setuPeso(string uPeso){
	this->uPeso = uPeso;
    return *this;
}      
     
string AmbienteMochila::getuDinero(){
    return this->uDinero;
}
string AmbienteMochila::getuPeso(){
	return this->uPeso;
}
ListaP & AmbienteMochila::getLp(){
	return *(this->lp);
}
AmbienteMochila::~AmbienteMochila(){
	if(lp){
		delete lp;
	}
}
Poblacion * AmbienteMochila::crearPoblacionInicial(){
	//int aleatorio = 0;
	
	
    //Criatura * inversa;
    Poblacion * poblacionPtr = new Poblacion();
    Poblacion::Iterador fin = poblacionPtr->end();

	for(int i=0; i< this->cantidadCriaturas; ++i){
	   //aleatorio = (int) (rand() * INT_MAX) + 1;
	   CriaturaMochila proto(*lp);
	   
	   //proto.setValor(aleatorio);
	   poblacionPtr->insertar( fin , &proto );
       //inversa = proto.inverso();
	   //poblacionPtr->insertar( fin , inversa );
       //delete inversa;	   
	}
	
	return poblacionPtr;
}