#include "Chambre.h"
#include <iostream>

Chambre::Chambre(){

}
Chambre::Chambre(int numero,double prixNuit){
    _numero = numero;
    _prixNuit = prixNuit;
}
Chambre::~Chambre(){
    cout << "desConstructeur chambre" << endl;
}
int Chambre::getNumero() const{
    return _numero;
}
double Chambre::getPrixNuit() const{
    return _prixNuit;
}
bool Chambre::estOccupee() const{
    return _occupee;
}
void Chambre::reverser(){
    if(_occupee){
        cout << "La Chambre est deja occuppe" << endl;
        return ;
    }
    _occupee  = true;
}
void Chambre::liberer(){
    _occupee = false;
}