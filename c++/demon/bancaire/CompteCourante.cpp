#include "CompteCourante.h"
#include <iostream>

CompteCourante::CompteCourante(std::string numero,std::string titulaire):Compte(numero,titulaire){
    this->decouvertAutorise = 0.0;
}
CompteCourante::CompteCourante():Compte(){
    this->decouvertAutorise = 0.0;
}
CompteCourante::~CompteCourante(){

}
void CompteCourante::afficher(){
    std::cout << "Numero : " << numero << std::endl;
    std::cout << "Titulaire: " << titulaire << std::endl;
    std::cout << "Solde : "  << solde << " €" << std::endl;
    std::cout << "Découvert autorisé : " << decouvertAutorise << std::endl;
}
void CompteCourante::retirer(double montant){
    if(solde - montant >= -decouvertAutorise){
        if(solde >= montant){
            solde -= montant;
        }else{
            decouvertAutorise  -= (montant - solde);
        }
        std::cout << "Vous avez retire: " << montant << std::endl;
    }
    else{
        std::cout << "compte insufisant :" << std::endl;
    }
}