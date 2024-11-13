//
// Created by ad on 13/11/24.
//
#include "Arme.h"
Arme::Arme(string n, int v){
    Arme::nom=n;
    Arme::valeur=v;}
Arme::~Arme() {
    cout << "Entité détruite" << endl;
}