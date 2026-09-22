#include "Client.h"
#include <iostream>
using namespace std;

Client::Client(){
    _nom = "";
    _prenom = "";
    _telephone = "";
}
Client::Client(string nom,string prenom,string telephone){
    _nom = nom;
    _prenom = prenom;
    _telephone = telephone;
}
Client::~Client(){

}
Client& Client::operator=(Client &obj){
    _nom = obj.getNom();
    _prenom = obj.getPrenom();
    _telephone = obj.getTelephone();
    return *this;
}
string Client::getNom() const{
    return _nom;
}
string Client::getPrenom() const{
    return _prenom;
}
string Client::getTelephone() const{
    return _telephone;
}

void Client::afficher() const{
    cout << "Nom : " << _nom << endl;
    cout << "Prenom : " << _prenom << endl;
    cout << "Telephone : " << _telephone << endl;
}
