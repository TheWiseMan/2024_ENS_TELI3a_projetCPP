#include <iostream>
using namespace std;

class Entite{
private:
    int PV,PVmax;
    int attaque;
public:
    Entite(int pv, int atk);    ~Entite();

    void Afficher();

    int attaquer(Entite* cible);
    int défendre(int degats);
    void changerArmure(string Armure, int defense);
    void changerArme(string Arme, int degat);
};