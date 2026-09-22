#include "Bibliotheque.h"
#include "Document.h"
#include "Livre.h"
#include "Roman.h"
#include "Magazine.h"
#include <iostream>
#include<vector>
using namespace std;

Bibliotheque::Bibliotheque(){

}
Bibliotheque::~Bibliotheque(){
    documents.clear();
}

void Bibliotheque::ajouterDocument(){
    cout << "Quel type de document voulez-vous ajouter ? " << endl;
    cout << "1. Roman" << endl;
    cout << "2. Magazine" << endl;
    cout << "3. Livre" << endl;
    cout << "0. Pour Annuler" << endl;
    int type;
    string titre = "";
    string auteur = "";
    string genre = "";
    int numero = 0;
    int annee;
    cin >> type;
    if(type == 0){
        cout << "Au revoir Bonne journée" << endl;
        return;
    }
    cout << "Titre: ";
    cin >> titre;
    cout << endl;
    cout << "Auteur: ";
    cin >> auteur;
    cout << endl;
    cout << "Annee: ";
    cin >> annee;
    cout << endl;
    switch(type){
        case 1:{
                cout << "Genre: ";
                cin >> genre;
                cout << endl;
                Roman *roman = new Roman(titre,auteur,annee,genre);
                this->documents.push_back(roman); 
                break;
        }   
        case 2:{     
                cout << "Numero: ";
                cin >> numero;
                cout << endl;
                Magazine *magazine = new Magazine(titre,auteur,annee,numero);
                this->documents.push_back(magazine);
                break;
        }
        case 3:{
                Livre *livre = new Livre(titre,auteur,annee);
                this->documents.push_back(livre);
                break;
        }
    } 
    cout << "Le document a été ajouté avec succéss" << endl;
}
void Bibliotheque::supprimerDocument(string titre){
    Document *doc = chercher(titre);
    int pos = trouverPosition(titre);
    if(doc == NULL || pos == -1){
        cout << "Aucun document ne correspond" << endl;
        exit;
    }
    documents.erase(documents.begin() + pos);
    cout << "le document a été supprimé avec succès " << endl;
}
void Bibliotheque::afficherDocuments(){
    if(documents.empty()){
        cout << "Aucun document est disponible" << endl;
    }
    for(Document *doc : this->documents ){
        doc->afficher();
    }
}
Document* Bibliotheque::chercher(string titre){
    for(Document *doc: this->documents){
        if(doc->getTitre() == titre){
            return doc;
        }
    }
    cout << "Aucun document trouvé" << endl;
    return NULL;
}

Document *Bibliotheque::chercher(int annee){
    for(Document *doc : this->documents){
        if(doc -> getAnnee() == annee){
            cout << "Le livre a été trouver " << endl;
            return doc;
        }
    }
    cout << "Aucun document n'a pas été trouvé : " << endl;
    return NULL;
}
int Bibliotheque::trouverPosition(string titre){
    for(int i = 0 ; i < documents.size(); i++){
        if(documents[i]->getTitre() == titre){
            return i;
        }
    }
    return -1;
}
void Bibliotheque::emprunter(string titre){
   Document *doc = chercher(titre);
   if(doc == NULL){
    cout << "Aucun document est disponible" << endl;
    exit;
   }
   doc->emprunter();
}
void Bibliotheque::rendre(string titre){
    Document *doc = chercher(titre);
    doc -> rendre();
    cout << "Le livre a été rendu avec succèss" << endl;
}
void Bibliotheque::sauvegarder(Document *doc){

}
void Bibliotheque::charger(){

}

void Bibliotheque::menu(){
    cout << "================ Bibliothèque =================" << endl;
    cout << endl;
    cout << "1. Ajouter un document" << endl;
    cout << endl;
    cout << "2. Afficher" << endl;
    cout << endl;
    cout << "3. Chercher" << endl;
    cout << endl;
    cout << "4. Emprunter" << endl;
    cout << endl;
    cout << "5. Rendre" << endl;
    cout << endl;
    cout << "6. Supprimer" << endl;
    cout << endl;
    cout << "7. Sauvegarder" << endl;
    cout << endl;
    cout << "8.Charger" << endl;
    cout << endl;
    cout << "0. Quitter" << endl;
    cout << endl;
    cout << "Votre choix : " << endl;
    int choix;
    cin >> choix;
    while(choix != 0){
        switch(choix){
            case 1 : {
                ajouterDocument();
                break;
            }
            case 2 : {
                afficherDocuments();
                break;
            }
            case 3 : {
                string titre;
                cout << "Veuillez saisir le titre: ";
                cin >> titre;
                cout << endl;
                chercher(titre);
                break;
            }
            case 4 : {
                string titre;
                cout << "Veuillez saisir le titre: ";
                cin >> titre;
                cout << endl;
                emprunter(titre);
                break;
            }
            case 5 : {
                string titre;
                cout << "Veuillez saisir le titre: ";
                cin >> titre;
                cout << endl;
                rendre(titre);
                break;
            }
            case 6 : {
                string titre;
                cout << "Veuillez saisir le titre: ";
                cin >> titre;
                cout << endl;
                supprimerDocument(titre);
                break;
            }
            case 7 : {
                sauvegarder(NULL);
                break;
            }
            case 8 : break;
            default : cout << "Choix invalide "<<endl;
        }
        cout << "votre choix: " << endl;
        cin >> choix;
    }
}