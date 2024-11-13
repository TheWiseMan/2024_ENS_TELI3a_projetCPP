#include <iostream>
using namespace std;
#include"Arme.h"
#include"Armure.h"
#pragma once

class Entite{
private:
    int PV,PVmax;
    int attaque;
    Armure armure;  // Attribut arme
    Arme arme;  // Attribut arme
public:
    Entite(int pv, int atk);
    ~Entite();

    void Afficher();

    int attaquer(Entite* cible);
    int défendre(int degats);
    void changerArmure(string Armure, int defense);
    void changerArme(string Arme, int degat);
};