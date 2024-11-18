// Arme.cpp
#include "Arme.h"

// Constructeur de Arme
Arme::Arme(string n, int v) {
    nom = n;
    valeur = v;
}

// Destructeur de Arme
Arme::~Arme() {
    cout << "Arme détruite" << endl;
}
