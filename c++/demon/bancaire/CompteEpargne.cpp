#include "CompteEpargne.h"
#include <iostream>

CompteEpargne::CompteEpargne(std::string numero,std::string titulaire):Compte(numero,titulaire){
    tauxInteret = 0.3;
}
CompteEpargne::CompteEpargne():Compte(){
    tauxInteret = 0.3;
}
CompteEpargne::~CompteEpargne(){
}
void CompteEpargne::appliquerInterets(){
    solde = solde + solde * tauxInteret / 100;
}
void CompteEpargne::afficher(){
    std::cout << "Numéro: " << numero << std::endl;
    std::cout << "Titulaire: " << titulaire << std::endl;
    std::cout << "Solde : " << solde << std::endl;
    std::cout << "Taux Interet: " << tauxInteret << std::endl;
}
void CompteEpargne::retirer(double montant){
    if(montant > solde ){
        std::cout << "Solde insuffiant : " << std::endl;
    }
    else{
        solde -= montant ;
        std::cout << "Vous avez retirez "  << montant << " €"<<std::endl;
    }

}