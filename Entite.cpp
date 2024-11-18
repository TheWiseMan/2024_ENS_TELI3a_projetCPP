// Entite.cpp
#include "Entite.h"
using namespace std;

// Constructeur de Entite
Entite::Entite(int pv, int atk): PV(pv), PVmax(pv), attaque(atk), armure(), arme() {
}

// Destructeur de Entite
Entite::~Entite() {
    cout << "Entité détruite" << endl;
}

void Entite::afficher() const{
    cout<<"PV"<<Entite::PV<<endl;
    cout<<"atk"<<Entite::attaque<<endl;
}
int Entite::defendre(int atk){
    Entite::PV=Entite::PV-atk;
    return PV;
};
int Entite::attaquer(Entite* cible) {
        cout << "Attaque par défaut : " << attaque << " dégâts infligés !" << endl;
        return cible->defendre(attaque);
}
void Entite::changerArmure(string nom, int atk){
    armure.nom=nom;
    armure.valeur=atk;

}
void Entite::changerArme(string nom, int atk){
    arme.nom=nom;
    arme.degats=atk;
}