#include"Roman.h"
#include<iostream>
using namespace std;

Roman::Roman():Livre(){

}
Roman::Roman(string titre,string auteur,int annee,string genre):Livre(titre,auteur,annee),genre(genre){
}
void Roman::afficher(){
    Livre::afficher();
    cout << "Genre: " << this->genre << endl;
}