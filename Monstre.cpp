#include "Monstre.h"
Monstre::~Monstre(){
    cout<<"Bye Monstre"<<endl;
}
Monstre::Monstre(string nom,int pv,int attaque): Entite(pv,attaque),nom(nom){
}
void Monstre::Afficher() const {
    cout << "Monstre: " << nom << " | PV: " << PV << " | Attaque: " << attaque << endl;
}

int Monstre::attaquer(Entite* cible) {
    cout << nom << " attaque !" << endl;
    return cible->defendre(attaque);
}

int Monstre::defendre(int degats) {
    PV -= max(0, degats);
    if (PV < 0) PV = 0;
    return PV;
}