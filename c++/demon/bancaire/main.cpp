#include <iostream>
#include "Banque.h"
#include "Compte.h"
#include "CompteEpargne.h"
#include "CompteCourante.h"

using namespace std;


using namespace std;

int main(){
    Banque * banque = new Banque("BNP Paribas");
    banque->menu();
    delete banque;
    return 0;
}