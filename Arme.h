// Arme.h
#pragma once

#include <string>
#include <iostream>
using namespace std;

class Arme {
public:
    string nom;
    int degats;
    Arme();
    Arme(string n, int v); // Déclaration du constructeur
    ~Arme();               // Déclaration du destructeur
};
