#include "Element.h"
#include <iostream>
using namespace std;

Element::Element(string nom,Dossier *parent){
    _nom = nom;
    _parent = parent;
}
Element::Element(){
    _nom = "";
    _parent = NULL;
}

Element::~Element(){

}
string Element::getNom() const{
    return _nom;
}
