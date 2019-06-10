#include<fstream>
#include "Piedra.h"
#include "ListaP.h"
#include<string>
#include "CriaturaMochila.h"

using namespace std;

int main(int argc, char * * argv){
static std::random_device rd;  
static std::mt19937_64 rng(rd());

string u = argv[2];
string m = argv[3];
/*
char buffer [100];
*/

ifstream entrada(argv[1]);
char buffer[100]; 


       /*
       char * buffer = new char [100];
       */

ListaP lp;  

ListaP::Iterador i = lp.begin() ; 


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
lp.imprimir(cout,u,m);
cout<<"Lista ordenada"<<endl;
lp.quickSort();
lp.imprimir(cout,u,m);
//cout<<"l2"<<endl;
//lp.quickSort();
//lp.imprimir(cout,u,m);
int size = lp.getSize();
//ListaP::Iterador * i2 = new ListaP::Iterador ();
//ListaP l2(lp,i2);
//l2.quickSort();
//l2.imprimir(cout,u,m);
cout<<size<<endl;
double precio = lp.getPrecio();
cout<<precio<<endl;
for(int w = 0; w<1;w++){
	i = lp.begin();
    CriaturaMochila c(lp);
    c.setuP(u);
    c.setuD(m);
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

return 0;
}