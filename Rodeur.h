#include "Entite.h"

class Rodeur : public Entite {
private:
    int compteur; // Spécifique au Rodeur

public:
    Rodeur(int pv, int atk);
    ~Rodeur();

    void Afficher() const ;
    int attaquer(Entite* cible) ;
    int defendre(int degats) ;
};