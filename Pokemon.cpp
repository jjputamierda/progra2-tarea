#include <iostream>
#include "Pokemon.h"
#include <math.h>
using namespace std;
Pokemon::Pokemon(){
  this->ataque =0.0;
  this->defensa =0.0;
  this->obey =0.0; 
}   
    Pokemon::Pokemon(double a,double d ,double o){
      this->ataque =a;
      this->defensa =d;
      this->obey =o; 
    }
	  Pokemon & Pokemon::setAtaque(double a){
      this->ataque =a;
      return *this;
    }
     Pokemon & Pokemon::setDefensa(double d){
       this->defensa =d;
      return *this;
     }
     Pokemon & Pokemon::setObey(double o){
        this->obey =o;
        return *this;
     }
	   double  Pokemon::getAtaque(){
       return this->ataque;
     }
     double  Pokemon::getDefensa(){
       return this->defensa;
     }
     double  Pokemon::getObey(){
       return this->obey;
     }  
    

      // Recibe: Un puntero a una criatura para cruzarla con la actual
      // Efectua: Retorna un vector terminado en 0 con los hijos
      Criatura ** Pokemon::cruzar( Criatura * ptr){
         Criatura * * hijo = 0;
         if(ptr){
       Pokemon * turtwig = dynamic_cast< Pokemon *>(ptr); 
       hijo = new Criatura * [2]; // Solo tiene un hijo promedio
       hijo[0] = new Pokemon( (this->ataque + turtwig->ataque )/2,(this->defensa + turtwig->defensa )/2,(this->obey + turtwig->obey )/2 );
       hijo[1]=0; // El ultimo puntero es nulo
  }
    
     /*
     if(ptr){
       CriaturaEntera * enteraPtr = dynamic_cast< CriaturaEntera *>(ptr); 
       hijo = new Criatura * [2]; // Solo tiene un hijo promedio
     hijo[0] = new CriaturaEntera( (this->valor + enteraPtr->valor )/2 );
       hijo[1]=0; // El ultimo puntero es nulo
      }
      */
      return hijo;
      }
	  
      Criatura * Pokemon::inverso(){
        return new Pokemon((this->ataque - 100.0)*-1,(this->defensa - 100.0)*-1,(this->obey - 100.0)*-1);
        
      }	  
	  
      void Pokemon::mutar(){
        if(this->ataque>=99.0){
          this->ataque = ceil(this->ataque);
        }
        else{
          this->ataque =this->ataque + 1.0;
        }
        if(this->defensa>=99.0){
          this->defensa = ceil(this->defensa);
        }
        else{
          this->defensa =this->defensa + 1.0;
        }
        if(this->obey>=2.0){
          this->obey = floor(this->obey);
        }
        else{
          this->obey =this->obey - 1.0;
        }
      }
      
      ostream& Pokemon::imprimir(ostream& salida){
        salida<<"ATAQUE: "<<this->ataque<<" DEFENSA "<<this->defensa<<" OBEDIENCIA "<<this->obey<<endl;
      return salida;
      }
      
      Criatura * Pokemon::clonar(){
        return new Pokemon(this->ataque,this->defensa,this->obey);
      }
     
	  int Pokemon::operator==(Criatura * c){
      int i = 0;
      return i;
    }