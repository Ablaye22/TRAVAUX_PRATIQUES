#include "ChambreSimple.h"
#include <iostream>

using namespace std;

ChambreSimple::ChambreSimple():Chambre(){
    
}
ChambreSimple::ChambreSimple(int numero,double prixNuit,int lit):Chambre(numero,prixNuit){
    _lit = lit;
}
ChambreSimple::~ChambreSimple(){
    cout << "desConstructeur Chambre Simple" << endl;
}
void ChambreSimple::afficher() const{
    cout << "Chambre Simple" << endl;
    cout << "Numero : " << _numero << endl;
    cout <<  "Prix : " << _prixNuit << endl;
    cout << "Nombre de lits : " << _lit << endl;
    cout << "Occupee : " << _occupee << endl;
}
