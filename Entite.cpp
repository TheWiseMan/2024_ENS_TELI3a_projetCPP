//
// Created by ad on 13/11/24.
//
// Entite.cpp
#include "Entite.h"
using namespace std;

// Constructeur de Entite
Entite::Entite(int pv, int atk) {
    Entite::PV=pv;
    Entite::PVmax=pv;
    Entite::attaque=atk;}

// Destructeur virtuel de Entite
Entite::~Entite() {
    cout << "Entité détruite" << endl;
}

// Méthode pour changer l'armure
void Entite::changerArmure(const string& nom, int valeur) {
    cout << "Changement d'armure en " << nom << " avec valeur " << valeur << endl;
}

// Méthode pour changer l'arme
void Entite::changerArme(const string& nom, int valeur) {
    cout << "Changement d'arme en " << nom << " avec valeur " << valeur << endl;
}
