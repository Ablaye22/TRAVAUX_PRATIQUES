#include "ChambreDouble.h"
 #include <iostream>
 using namespace std;
ChambreDouble::ChambreDouble():Chambre(){

}
ChambreDouble::ChambreDouble(int numero,double prixNuit,int lits):Chambre(numero,prixNuit){
    _lits = lits;
}
ChambreDouble::~ChambreDouble(){

}
void ChambreDouble::afficher()const {
    cout << "Chambre double" << endl;
    cout << "Numero: " << _numero << endl;
    cout << "Prix : " << _prixNuit  << endl;
    cout << "Nombre de lits : " << _lits  << endl;
    cout << "Occupee : " << _occupee << endl;
}