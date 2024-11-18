#include "Entite.h"

class Mage : public Entite {
private:
    int mana; // Spécifique au Mage

public:
    Mage(int pv, int atk, int mana);
    ~Mage();

    void Afficher() const;
    int attaquer(Entite* cible) ;
    int defendre(int degats);
};