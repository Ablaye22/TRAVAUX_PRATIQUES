#include "Suite.h"
#include <iostream>

Suite::Suite():Chambre(){

}
Suite::Suite(int numero,double prixNuit,double surface):Chambre(numero,prixNuit){
    _surface = surface;
}
Suite::~Suite(){

}
void Suite::afficher() const{
    cout << "Suite" << endl;
    cout << "Numero : "<< _numero << endl;
    cout << "Prix : " << _prixNuit << endl;
    cout << "Surface : " << _surface << "m²"<<endl;
    cout << "Occupee : " << _occupee  << endl;
}