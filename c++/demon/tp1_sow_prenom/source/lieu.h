#include<iostream> 
#define nb_Ville_max  50
using namespace std;

 #ifndef LIEU_H
 #define LIEU_H

 extern int compteur;

enum connectionType_t{TRAIN,BATEAU,ALL};

struct Connexion {
    string destination;
    connectionType_t transport;
    Connexion *suivant;
};
struct Ville{
    string nom;
    Connexion *connexions;
};

extern Ville Carte[nb_Ville_max];
int trouver_index_ville(string l);
void ajouter_connexion(string l1, string l2,connectionType_t type,bool premiere_fois = true);
void init();
void print_connexions();
bool estAccessible(connectionType_t ,string l1,string l2);
long distance(connectionType_t mt, string l1, string l2);


 #endif
