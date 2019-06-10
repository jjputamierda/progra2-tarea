#include "Piedra.h"
#include <iostream>
#include <stdlib.h>

Piedra::Piedra(){
	this->peso = 0;
    this->precio = 0;
}
Piedra::Piedra(char * linea ){
	this->peso = 0;
	this->precio=0;
	
	if(linea){
		
		int cpeso = 0;
		int i =0;
		while(linea[i]!='\0'){
			
			
			if(linea[i] != ' ' && cpeso == 0) 
			{
			 int posI=i;
             int posF=i-1;
             int posP = 0;
             double multi = 1;
             for(int k = i; linea[k]!=' ';k++){
             	if(linea[k]=='.'){
             		posP=k;
             	}
             	
             	posF++;
                
             }
			 i = posF;
			 
             if(posP!=0){
                 for(int h=posF; h>posP;h--){
                 	multi = multi * 0.1;
                    
                 }
                 }
			 for(int j=posF; j>=posI; j--){
                 if(linea[j]=='.'){
                  
                   
                 }
			      else{
			      
			      	char c = linea[j];
			      	double d = double (linea[j]-'0');
			      	this->peso=this->peso+d*multi;
                    multi = multi * 10;
			        
			      }
			 }
	
	cpeso = 1;		 
	}
    else{
        if(linea[i] != ' ' && cpeso == 1) 
			{
			 int posI=i;
             int posF=i-1;
             int posP = 0;
             double multi = 1;
             for(int k = i; linea[k]!='\0';k++){
             	if(linea[k]=='.'){
             		posP=k;
             	}
             	
             	posF++;
                
             }
			 i = posF;
			 
             if(posP!=0){
                 for(int h=posF; h>posP;h--){
                 	multi = multi * 0.1;
                    
                 }
                 }
			 for(int j=posF; j>=posI; j--){
                 if(linea[j]=='.'){
                   //multi = multi * 10;
                   
                 }
			      else{
			      
			      	char c = linea[j];
			      				      	double d = double (linea[j]-'0');
			      	
			      	this->precio=this->precio+d*multi;
                    multi = multi * 10;
			        
			        
			      }
			 }
	
	cpeso = 2;		 
	}
    }
i++;
}
}
}
Piedra & Piedra::setPrecio(double p){
	this->precio = p;
	return *this;
}
Piedra & Piedra::setPeso(double p){
	this->peso = p;
	return *this;
}	 
double Piedra::getPrecio(){
	return this->precio;
}
double Piedra::getPeso(){
	return this->peso;
}	 

ostream& Piedra::imprimir(ostream& salida,string peso,string precio){
   salida << this->peso <<" "<<peso<< " " <<this->precio<<" "<<precio<<endl;
   return salida;   
}

