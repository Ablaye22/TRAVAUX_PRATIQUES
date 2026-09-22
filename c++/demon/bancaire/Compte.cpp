#include "Compte.h"
#include <iostream>

Compte::Compte(){
    this->numero = "";
    this->titulaire = "";
    this->solde = 0.0;
}
Compte::Compte(std::string numero, std::string titulaire){
    this->numero = numero;
    this->titulaire = titulaire;
    this->solde = 0.0;
}


Compte::~Compte(){
}

std::string Compte::getNumero(){
    return numero;
}
std::string Compte::getTitulaire(){
    return titulaire;
}
double Compte::getSolde(){
    return solde;
}
void Compte::deposer(double montant){
    if(montant < 0){
        std::cout << "Impossible de deposer un montant negatif: " << std::endl;
        return ;
    }
    solde += montant;
}