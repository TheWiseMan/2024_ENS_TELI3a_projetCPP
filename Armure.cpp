#include "Armure.h"

Armure::Armure(string n, int v){
    Armure::nom=n;
    Armure::valeur=v;}
Armure::~Armure() {
    cout << "Armure détruite" << endl;
}
Armure::Armure(){
    nom="Pas d'armure";
    valeur=0;
}