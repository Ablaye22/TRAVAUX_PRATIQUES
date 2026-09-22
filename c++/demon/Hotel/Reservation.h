#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include "Client.h"
#include "Chambre.h"
using namespace std; 

class Reservation{
    Client _client;
    Chambre *_chambre;
    int _nuits;
public:
    Reservation();
    Reservation(Client client,Chambre *chambre,int nuits);
    ~Reservation();
    double calculerPrix() const;
};
#endif
