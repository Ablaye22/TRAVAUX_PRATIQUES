#include"Document.h"
#include<iostream>
using namespace std;
Document::Document(){

}
Document::Document(string titre):titre(titre){

}
string Document::getTitre(){
    return this->titre;
}
void Document::setTitre(string titre){
    this->titre = titre;
}