#include "Livre.h"
#include<iostream>
using namespace std;


Livre::Livre(){

}
Livre::Livre(string titre,string auteur,int annee): Document(titre),auteur(auteur),annee(annee),disponible(true){
  
}

ostream& Livre::operator<<(Livre &obj){
    obj.afficher();
    return cout;
}

string Livre::getAuteur(){
    return this->auteur;
}
int Livre::getAnnee(){
    return this->annee;
}
bool Livre::estDisponible(){
    return this->disponible;
}
void Livre::setAuteur(string auteur){
    this->auteur = auteur;
}
void Livre::setAnnee(int annee){
    this->annee = annee;
}
void Livre::afficher(){
    cout << "Titre : " << this->titre << endl;
    cout << "Auteur : " << this->auteur << endl;
    cout << "Annee : " << this->annee << endl;
    cout << "Disponible : " ;
    if(this-> disponible == true ){ 
        cout << "oui" ;
     }
     else{ 
        cout << "non";
      }
       cout<< endl;
}

void Livre::emprunter(){
    if(this->disponible){
        this->disponible = false;
        cout << "Le livre est pret pour etre emprunter" << endl;
        exit;
    }
    cout << "Le livre est indisponible" << endl;
}
void Livre::rendre(){
    cout << "Le livre est bien rendu : Merci" << endl;
    this->disponible = true;
}