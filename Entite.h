// Entite.h
#pragma once

#include <iostream>
#include <string>
#include "Arme.h"
#include "Armure.h"
using namespace std;

class Entite {
protected:
    int PV;
    int PVmax;
    int attaque;
    Armure armure;  // Attribut armure en private
    Arme arme;      // Attribut arme en private
public:
    Entite(int pv, int atk);  // Constructeur
    ~Entite();                // Destructeur
    void afficher() const;
    int defendre(int atk);
    int attaquer(Entite* cible);
    void changerArmure(string nom, int atk);
    void changerArme(string nom, int atk);
};
