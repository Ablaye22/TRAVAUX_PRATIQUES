#include "Fichier.h"
#include "Dossier.h"
#include <iostream>
using namespace std;
Fichier::Fichier(string nom,Dossier* parent,string contenu,string extension):Element(nom,parent){
    _contenu = contenu;
    _extension = extension;
}
Fichier::Fichier():Element(){
    _contenu = "";
    _extension = "";
}
Fichier::~Fichier(){

}
string Fichier::getContenu() const{
    return _contenu;
}
string Fichier::getExtension() const{
    return _extension;
}
void Fichier::afficher(int profondeur) const{
    cout << _nom << "." << _extension << endl; 
}
size_t Fichier::taille() const{
    return _contenu.size();
}
void Fichier::ecrire(const string &text){
    _contenu = text;
}