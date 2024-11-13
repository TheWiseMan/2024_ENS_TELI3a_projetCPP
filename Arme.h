//
// Created by ad on 13/11/24.
//
#include <iostream>
using namespace std;
#pragma once

class Arme {
public:
    string nom;
    int valeur;
    ~Arme();
    Arme(string n, int v);
};