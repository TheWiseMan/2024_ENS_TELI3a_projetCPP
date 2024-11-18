#include "Guerrier.h"

Guerrier::Guerrier(int pv, int atk)
        : Entite(pv, atk) {}

Guerrier::~Guerrier() {
    cout << "Guerrier détruit." << endl;
}

void Guerrier::Afficher() const {
    cout << "Guerrier | PV: " << PV << " | Attaque: " << attaque << endl;
}

int Guerrier::attaquer(Entite* cible) {
    cout << "Guerrier attaque avec force !" << endl;
    return cible->defendre(attaque + 5); // Bonus d'attaque
}

int Guerrier::defendre(int degats) {
    PV -= max(0, degats - armure.valeur - 3); // Bonus défensif
    if (PV < 0) PV = 0;
    return PV;
}
