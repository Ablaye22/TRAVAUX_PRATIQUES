#include<iostream>
#include "Magazine.h"
#include "Roman.h"
#include "Livre.h"
#include "Document.h"
#include "Bibliotheque.h"
using namespace std;


int main(){
    cout << "Bienvenu dans le Bibliotheque Edgar Morin" << endl;
    Bibliotheque *bu = new Bibliotheque();
    bu->menu();
    delete bu;
    return 0; 
    return 0;
}