#include"Magazine.h"
#include<iostream> 

Magazine::Magazine():Livre(){

}
Magazine::Magazine(string titre,string auteur,int annee,int numero):Livre(titre,auteur,annee),numero(numero){

}
void Magazine::afficher(){
    cout << "Numéro: " << this->numero << endl;
    Livre::afficher();
}