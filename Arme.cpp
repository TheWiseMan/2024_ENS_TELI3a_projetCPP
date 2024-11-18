// Arme.cpp
#include "Arme.h"

// Constructeur de Arme
Arme::Arme(string n, int v) {
    nom = n;
    degats = v;
}

// Destructeur de Arme
Arme::~Arme() {
    cout << "Arme détruite" << endl;
}
Arme::Arme(){
    nom="Pas d'arme";
    degats=0;
}