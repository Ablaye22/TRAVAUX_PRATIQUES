#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
using namespace std;

class Client{
    string _nom;
    string _prenom;
    string _telephone;
public:
    Client(string nom,string prenom,string telephone);
    Client();
    ~Client();
    Client &operator=(Client &obj);
    Client& Client(Client &obj);
    string getNom() const;
    string getPrenom() const;
    string getTelephone() const;
    void afficher() const;
};
#endif