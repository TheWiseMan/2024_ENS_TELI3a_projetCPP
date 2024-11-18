#include "Mage.h"

Mage::Mage(int pv, int atk, int mana)
        : Entite(pv, atk), mana(mana) {}

Mage::~Mage() {
    cout << "Mage détruit." << endl;
}

void Mage::Afficher() const {
    cout << "Mage | PV: " << PV << " | Attaque: " << attaque << " | Mana: " << mana << endl;
}

int Mage::attaquer(Entite* cible) {
    if (mana >= 10) {
        mana -= 10;
        cout << "Mage lance un sort puissant !" << endl;
        return cible->defendre(attaque + 15); // Bonus d'attaque magique
    } else {
        cout << "Mana insuffisant. Attaque normale." << endl;
        return cible->defendre(attaque);
    }
}

int Mage::defendre(int degats) {
    PV -= max(0, degats - armure.valeur);
    if (PV < 0) PV = 0;
    return PV;
}
