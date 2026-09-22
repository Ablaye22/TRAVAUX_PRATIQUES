#include <iostream>
#include <limits>
#include "Banque.h"
#include "CompteCourante.h"
#include "CompteEpargne.h"
#include "Compte.h"
Banque::Banque(std::string nom){
    this->nomBanque = nom;
}
Banque::~Banque(){
   for(Compte *compte: comptes){
    delete compte;
   }
   comptes.clear();
}
std::string Banque::getNomBanque(){
    return nomBanque;
}
void Banque::setNomBanque(std::string nom){
    this->nomBanque = nom;
}


void Banque::ajouterCompte(){
    std::string numero,titulaire;
    int choix;
    std::cout << "Quel type de compte Voulez-vous Ouvrir: " << std::endl;
    std::cout << "1. Compte Courant" << std::endl;
    std::cout << "2. Compte Epargne" << std::endl;
    std::cin >> choix;
    if(choix == 1){
        std::cout << "Saisir Numero: " << std::endl;
        std::cin >> numero;
        std::cout << "Saisir Nom Titulaire: " << std::endl;
        std::cin >> titulaire;
        comptes.push_back(new CompteCourante(numero,titulaire));
    }else if(choix == 2){
        std::cout << "Saisir Numero: " << std::endl;
        std::cin >> numero;
        std::cout << "Saisir Nom Titulaire: " << std::endl;
        std::cin >> titulaire;
        comptes.push_back(new CompteEpargne(numero,titulaire));
    }else{
        std::cout << "Saisit invalide : " << std::endl;
    }
}
void Banque::afficherComptes(){
    if(comptes.empty()) {
        std::cout << "Aucun Compte n'est disponible: " << std::endl;
        return ;
    }
    for(Compte *compte: comptes){
        compte->afficher();
    }
}
Compte *Banque::chercher(std::string numero){
    for(Compte *compte: comptes){
        if(compte->getNumero() == numero){
            return compte;
        }
    }
    return NULL;
}
void Banque::chercher(){
    std::string nom;
    std::cout << "Nom du titulaire: " << std::endl;
    std::cin >> nom;
    for(Compte *compte : comptes){
        if(compte->getTitulaire() == nom){
            compte->afficher();
        }
    } 
    std::cout << "Aucun Compte n'a été trouver: "  << std::endl;
}
int Banque::trouverPosition(std::string numero){
    for(int i = 0 ; i < comptes.size(); i++){
        if(comptes[i]->getNumero() == numero){
            return i;
        }
    }
    return -1;
}
void Banque::supprimerCompte(){
    std::string numero;
    std::cout << "Numero: " << std::endl;
    std::cin >> numero;
    int pos = trouverPosition(numero);
    if(pos != -1){
        delete comptes[pos];
        comptes.erase(comptes.begin() + pos);
    }
    else{
        std::cout << "Aucun compte ne correspond "<< std::endl;
    }

}
void Banque::deposer(){
    std::string numero;
    double montant;
    std::cout << "Numero: " << std::endl;
    std::cin >> numero;
    std::cout << "Montant : " << std::endl;
    std::cin >> montant;
    Compte * compte = chercher(numero);
    compte->deposer(montant);
}
void Banque::retirer(){
    std::string numero;
    double montant;
    std::cout << "Numero: " << std::endl;
    std::cin >> numero;
    std::cout << "Montant : " << std::endl;
    std::cin >> montant;
    Compte *compte = chercher(numero);
    compte->retirer(montant);
}
void Banque::appliquerInterets(){
    std::string numero;
    std::cout << "Numero: " << std::endl;
    std::cin >> numero;
    Compte *compte = chercher(numero);
    if(compte == NULL){
        std::cout << "Aucun compte n'a ete trouver" << std::endl;
        return;
    }
    std::cout << "Je vais completer ici plutard" << std::endl;
}
void Banque::menu(){
    std::cout << "=============================" << std::endl;
    std::cout << "===BANQUE"<<nomBanque<< "===" << std::endl;
    std::cout << "=============================" << std::endl;

    std::cout << "1. Ajouter un compte" << std::endl;
    std::cout << "2. Afficher les comptes" << std::endl;
    std::cout << "3. Rechercher un compte" << std::endl;
    std::cout << "4. Déposer de l'argent" << std::endl;
    std::cout << "5. Retirer de l'argent" << std::endl;
    std::cout << "6. Appliquer les intérêts" << std::endl;
    std::cout << "7. Supprimer un compte" << std::endl;
    std::cout << "0. Quitter" << std::endl;
    std::cout << "Votre choix :" << std::endl;
    int choix;
    std::cin >> choix;
    executer(choix);
}
void Banque::executer(int choix){
    switch(choix){
        case 1 : {
            ajouterCompte(); 
            break;
        }
        case 2 : {
            afficherComptes();
            break;
        }
        case 3 : {
            chercher();
            break;
        }
        case 4 : {
            deposer();
            break;
        }
        case 5 : {
            retirer();
            break;
        }
        case 6 : {
            appliquerInterets();
            break;
        }
        case 7 : {
            supprimerCompte();
            break;
        }
        case 0 : {
            std::cout << "Vous voulez quitter : Au revoir " << std::endl;
            break;
        }
        default: {
            std::cout << "Entrer invalide : Au revoir " << std::endl;
        }
    }
    if(choix != 0)
    menu();
}