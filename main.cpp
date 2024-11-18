#include "Arme.h"
#include "Armure.h"
#include "Entite.h"

int main() {
    Arme epee("Épée magique", 50);
    cout << "Nom de l'arme : " << epee.nom << ", Valeur : " << epee.valeur << endl;
    Armure fer("Maille fer", 50);
    cout << "Nom de l'armure : " << fer.nom << ", Valeur : " << fer.valeur << endl;
    Entite Monstre(100, 10);
    /*cout << "Nom de l'armure : " << Monstre.PV << ", Valeur : " << Monstre.attaque << endl;*/
    Monstre.afficher();
    Monstre.changerArme("épée",20);

}