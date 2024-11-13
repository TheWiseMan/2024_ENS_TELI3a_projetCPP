#include "Armure.h"

Armure::Armure(string n, int v){
    Armure::nom=n;
    Armure::valeur=v;}
Armure::~Armure() {
    cout << "Armure détruite" << endl;
}