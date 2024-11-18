#include "Entite.h"

class Guerrier : public Entite {
private:
public:
    Guerrier(int PV,int attaque);
    ~Guerrier();
    void Afficher() const;
    int attaquer(Entite* cible);
    int defendre(int degats);
};