// Entite.cpp
#include "Entite.h"
using namespace std;

// Constructeur de Entite
Entite::Entite(int pv, int atk): PV(pv), PVmax(pv), attaque(atk), armure("Aucune", 0), arme("Aucune", 0) {
}

// Destructeur de Entite
Entite::~Entite() {
    cout << "Entité détruite" << endl;
}

void Entite::afficher(){
    cout<<"PV"<<Entite::PV<<endl;
    cout<<"atk"<<Entite::attaque<<endl;
}
int Entite::défendre(int atk){
    return Entite::PV-atk;
};



void Entite::changerArmure(string nom, int atk){
    armure.nom=nom;
    armure.valeur=atk;

}
void Entite::changerArme(string nom, int atk){
    arme.nom=nom;
    arme.valeur=atk;
}