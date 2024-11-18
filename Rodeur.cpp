#include "Rodeur.h"

Rodeur::Rodeur(int pv, int atk)
        : Entite(pv, atk), compteur(0) {}

Rodeur::~Rodeur() {
    cout << "Rodeur détruit." << endl;
}

void Rodeur::Afficher() const {
    cout << "Rodeur | PV: " << PV << " | Attaque: " << attaque << " | Compteur: " << compteur << endl;
}

int Rodeur::attaquer(Entite* cible) {
    compteur++;
    cout << "Rodeur attaque furtivement !" << endl;
    return cible->defendre(attaque + compteur); // Augmentation progressive de l'attaque
}

int Rodeur::defendre(int degats) {
    Entite::PV -= max(0, degats - armure.valeur);
    if (PV < 0) PV = 0;
    return PV;
}
