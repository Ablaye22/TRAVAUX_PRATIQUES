#include "lieu.h"
#include<iostream>
#include<stdlib.h> 
#include<string.h>

using namespace std;

int compteur = 0;
Ville Carte[nb_Ville_max];


void init(){
    Carte[compteur++] = {"Paris",nullptr};
    Carte[compteur++] = {"Rennes",nullptr};
    Carte[compteur++] = {"Bordeaux",nullptr};
    Carte[compteur++] = {"Calais",nullptr};
    Carte[compteur++] = {"Quimper",nullptr};
    Carte[compteur++] = {"Brest",nullptr};
    Carte[compteur++] = {"Plymouth",nullptr};
    Carte[compteur++] = {"Londres",nullptr};
    Carte[compteur++] = {"Portsmouth",nullptr};
    Carte[compteur++] = {"Douvres",nullptr};
    Carte[compteur++] = {"Edimbourg",nullptr};
    Carte[compteur++] = {"Le Havre",nullptr};


    ajouter_connexion("Rennes","Paris",TRAIN);
    ajouter_connexion("Paris","Bordeaux",TRAIN);
    ajouter_connexion("Paris","Calais",TRAIN);
    ajouter_connexion("Bordeaux","Quimper",TRAIN);
    ajouter_connexion("Quimper","Rennes",TRAIN);
    ajouter_connexion("Rennes","Brest",TRAIN);
    ajouter_connexion("Plymouth","Londres",TRAIN);
    ajouter_connexion("Londres","Portsmouth",TRAIN);
    ajouter_connexion("Londres","Douvres",TRAIN);
    ajouter_connexion("Londres","Edimbourg",TRAIN);
    ajouter_connexion("Plymouth","Brest",BATEAU);
    ajouter_connexion("Portsmouth","Le Havre",BATEAU);
    ajouter_connexion("Le Havre","Paris",BATEAU);
    ajouter_connexion("Douvres","Calais",BATEAU);
    ajouter_connexion("Brest","Bordeaux",BATEAU);
}
int trouver_index_ville(string l){
    for(int i = 0 ; i <  compteur ; i++ )
        if(Carte[i].nom == l)
            return i;
    return -1;
}
void ajouter_connexion(string l1, string l2,connectionType_t type,bool premiere_fois){
    int index = trouver_index_ville(l1);
    if(index == -1){
        cout << l1<< endl;
        cout << "Ville non trouver !" << endl;
        return;
    }
    if(Carte[index].connexions == nullptr){
        Carte[index].connexions = new Connexion;
        Carte[index].connexions->destination = l2;
        Carte[index].connexions->transport = type;
        Carte[index].connexions->suivant = nullptr;
    }
    else{
        Connexion *p = new Connexion;
        p->destination = l2;
        p-> transport = type;
        p->suivant = Carte[index].connexions;
        Carte[index].connexions = p;
    }
    if(premiere_fois)
        ajouter_connexion(l2,l1,type,false);
}
void print_connexions(){
    for(int i = 0 ; i  < compteur ; i++){
        cout << Carte[i].nom;
        Connexion *p = Carte[i].connexions;
        while(p != nullptr){
            cout << " --> ("<< p->destination<<",";
            if(p->transport == 0 )
                cout << "TRAIN)";
            else
                cout  << "BATEAU)";
            p = p->suivant;
        }
        cout << ""<<endl;
    }
}
bool estAccessible(connectionType_t transport,string l1,string l2){
    int index = trouver_index_ville(l1);
    if(index  == -1)
        return false;
    Connexion *p = Carte[index].connexions;
    while(p != nullptr){
        if(p->destination == l2 && p-> transport ==transport )
            return true;
        p = p->suivant;
    }
    return false;
}
long distance(connectionType_t mt, string l1, string l2){
    if(estAccessible(mt,l1,l2))
        return 1;
    Connexion *p = Carte[trouver_index_ville(l1)].connexions;
    while(p != nullptr){
        
    }
    if (p == nullptr)
        return nb_Ville_max;
    return 1 + estAccessible(mt,p->destination,l2);
}
void liberer_memoire(){
    Connexion *p,*q;
    for(int i = 0 ; i <compteur ; i++){
        p = Carte[i].connexions;
        while(p != nullptr){
            q = p->suivant;
            delete p;
            p = q;
        }
    }
}


int main(){
    init();
    print_connexions();
    liberer_memoire();
    return 0;
}

