#include <iostream>
#include "CriaturaMochila.h"
using namespace std;
CriaturaMochila::CriaturaMochila(){
      this->peso = 0.0;
      this->precio = 0.0;
      this->piedras = new int[1];
	  this->piedras[1]=0;
      this->size = 0;
      
}   

CriaturaMochila::CriaturaMochila(CriaturaMochila & otra){
	//dynamic_cast< CriaturaMochila * >(otra);
	this->peso = otra.peso;
	this->precio = otra.precio;
	this->size = otra.size;
	//ListaP lp = *otra.getLP;
	setLP(otra.getLP());
	this->piedras = new int [this->size];
	for(int i = 0;i<size;i++){
		this->piedras[i]=otra.piedras[i];
	} 
}
CriaturaMochila::CriaturaMochila(ListaP & lp){
     static random_device rd;  
     static mt19937_64 rng(rd());
     if(size){
     this->size  = lp.getSize();
     this->piedras = new int [size];
     for(int i = 0; i<size;i++) {
     uniform_int_distribution<int> distribution(0, 1);
		this->piedras [i]=distribution(rng);
		//j[k]= rand() % 2;
	    cout<<this->piedras[i]<<endl;
       
     }  
     
     this->peso = 0.0;
     this->precio = 0.0;
     this->calificacion = 0.0;
     this->lp = &lp;
     setPrecio(lp);
     setPeso(lp);
     }
     
}
	/*
	CriaturaMochila::~CriaturaMochila(){
		if(piedras){
			delete [] piedras;
		}
	}
	*/
	string CriaturaMochila::getuP(){
        return this->uP;
     } 
	 string CriaturaMochila::getuD(){
        return this->uD;
     } 
	 double CriaturaMochila::getPeso(){
        return this->peso;
     } 
     
     double CriaturaMochila::getPrecio(){
        return this->precio;
     }
     int CriaturaMochila::getPosP(int pos){
          int i = -1;
          if(pos<size && pos >=0){
          	i = this->piedras[pos];
          }
          return i;
     }
     int * CriaturaMochila::getP(){
     	return this->piedras;
     }
     
     int CriaturaMochila::getSize(){
            return this->size;
     }
      ListaP & CriaturaMochila::getLP(){
      	return *(this->lp);
      }
      CriaturaMochila & CriaturaMochila::setuP(string uP){
        this->uP =  uP;
      	return *this;
      };
      CriaturaMochila & CriaturaMochila::setuD(string uD){
        this->uD =  uD;
      	return *this;
      };
      CriaturaMochila & CriaturaMochila::setLP(ListaP & lp){
        this->lp = & lp;
      	return *this;
      };
      CriaturaMochila & CriaturaMochila::setPeso( ListaP & lp){
           this->peso =0;
           ListaP::Iterador j = lp.begin();
           for(int i = 0; i<size;i++){
            
            if(this->piedras[i]==1){
           	/*
           	Piedra * p = *j;
           	this->peso=this->peso + p->getPeso();
            */
            Piedra p = * (*j);
            this->peso=this->peso + p.getPeso();
           }
           j++;
           }
      return *this;
      }
      CriaturaMochila & CriaturaMochila::setPrecio(ListaP &lp){
            this->precio = 0;
            ListaP::Iterador j = lp.begin();
           
            for(int i = 0; i<size;i++){
            if(this->piedras[i]==1){
           	/*
           	Piedra * p = *j;
           	
           	this->precio=this->precio + p->getPrecio();
           */
            Piedra p = * (*j);
           	
           	this->precio=this->precio + p.getPrecio();	
           }
           j++;
           }
      return *this;

      }

      CriaturaMochila & CriaturaMochila::setPosP(int pos,int v){
            if(pos<size && pos >=0&&(v==0||v==1)){
          	this->piedras[pos] = v;
          }
      return *this;
      }
      
      
      CriaturaMochila & CriaturaMochila::setSize(int s){
        this->size = s;
        return * this;
      }
      // Recibe: Un puntero a una criatura para cruzarla con la actual
      // Efectua: Retorna un vector terminado en 0 con los hijos
      Criatura ** CriaturaMochila::cruzar( Criatura * ptr){
             Criatura * * hijo = 0;
	   
	   if(ptr){
  	   CriaturaMochila * Ptr = dynamic_cast< CriaturaMochila *>(ptr);	
       hijo = new Criatura * [2]; // Solo tiene un hijo promedio
	   CriaturaMochila * nueva = new CriaturaMochila(*this);
	   static random_device rd;  
       static mt19937_64 rng(rd());
	   for(int i = 0; i<nueva->size;i++){
	   	uniform_int_distribution<int> distribution(0, 1);
	   	if(distribution(rng)==1){
	   		nueva->piedras[i]=this->piedras[i];
	   	}
	        else{
             nueva->piedras[i]=Ptr->piedras[i];
	        }
	   }
	  nueva->setPrecio(nueva->getLP());
      nueva->setPeso(nueva->getLP());
	   hijo[0] = nueva;
       hijo[1]=0; // El ultimo puntero es nulo
	}
	
	return hijo;
     }
	  
      Criatura * CriaturaMochila::inverso(){
      //dynamic_cast< CriaturaEntera * >( criaturaPtr )
      CriaturaMochila * nueva = new CriaturaMochila(*this);
      
      for(int i =0;i<size;i++){
      	if(this->piedras[i]==1){
      		nueva->piedras[i]=0;
      	}
        else{
        	if(this->piedras[i]==0)
        	nueva->piedras[i]=1;
        }
      }
      //return new CriaturaMochila();
       //return new CriaturaEntera((valor>0)? (INT_MAX - valor) : (INT_MAX + valor));
      nueva->setPrecio(nueva->getLP());
      nueva->setPeso(nueva->getLP());
      return nueva;
      }	  
	  
      void CriaturaMochila::mutar(){
      
       if(size==1){
           if(this->piedras[0]==1){
       		this->piedras[0]=0;
       	    }
            else{
        	this->piedras[0]=1;
           }
       }
       else{
       	int c = 0;
       	for(int i = 0;i<size;i++){
           if(c==2){
           	c = 0;
           	if(this->piedras[i]==1){
       		this->piedras[i]=0;
       	    }
            else{
        	this->piedras[i]=1;
           }
           }
           c++;
       	
       	}
       
       }
      this->setPrecio(this->getLP());
      this->setPeso(this->getLP());
      }
      
      ostream& CriaturaMochila::imprimir(ostream& salida){
         salida<<"PESO TOTAL "<<getPeso()<<this->uP<<" PRECIO TOTAL "<<getPrecio()<<this->uD<<endl;
         /*
         getLP().imprimir(salida,getuP(),getuD(),getP(),0);
         cout<<"Aqui esta la MOCHILA : " << precio << endl;
         getLP().imprimir(salida,getuP(),getuD(),getP(),0);
         cout<<"Aqui esta la MOCHILA 2: " << precio << endl;
         getLP().imprimir(salida,getuP(),getuD(),getP(),0);
         */
         return salida;
      }
      
      Criatura * CriaturaMochila::clonar(){
       CriaturaMochila * nueva = new CriaturaMochila(getLP());
       return nueva;
      }
     
	  int CriaturaMochila::operator==(Criatura * ptr){
	  	CriaturaMochila * enteraPtr = dynamic_cast< CriaturaMochila *>(ptr);
	  	
	  	int i=1;
	  	for(int i = 0; i<size; i++){
	  		if(this->piedras[i]!=enteraPtr->piedras[i]){
	  			i = 0;
	  		}
	  	}
	  	return i; 
	  }

      CriaturaMochila::~CriaturaMochila(){
      	if(piedras){
      		delete [] piedras;
      	}
        if(lp){
        	delete lp;
        }
      }
