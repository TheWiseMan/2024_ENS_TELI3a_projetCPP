#include "Entite.h"

class Monstre : public Entite {
private:
    string nom;
public:
    Monstre(string nom,int PV,int attaque);
    ~Monstre();
    void Afficher() const;
    int attaquer(Entite* cible);
    int defendre(int degats);
};