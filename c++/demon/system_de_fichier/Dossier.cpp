#include "Dossier.h"
#include "Element.h"
#include <iostream>
using namespace std;

Dossier::Dossier():Element(){

}
Dossier::Dossier(string nom,Dossier *parent):Element(nom,parent){

}
Dossier::~Dossier(){

}
void Dossier::ajouter(Element *element){
    elements.push_back(element);
}
void Dossier::supprimer(const string& nom){
    for(int i = 0 ; i < elements.size() ; i ++){
        if(elements[0]->getNom() == nom){
            elements.erase(elements.begin() + i);
        }
    }
}
Element* Dossier::rechercher(const string &nom){
    for(Element *elem : elements){
        if(elem->getNom() == nom){
            return elem;
        }
    }
    return NULL;
}
void Dossier::afficher(int profondeur) const{
    for(Element *element : elements){
        cout << _nom << "/" << endl;
        element->afficher();
    }
}
size_t Dossier::taille() const{
   size_t taille = 0;
   for(Element *elem: elements){
        taille += elem->taille();
   }
   return taille;
}