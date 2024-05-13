#pragma once

#include "anyag.h"
#include <iostream>


class Legkor
{
private:
    std::vector<Anyag *> anyagok; //rétegek
    std::string viszonyok;  //időjárási viszonyok
    Legkor() = default; //konstuktor
    
public:
    Anyag* GetAnyag(int o) {return anyagok[o];};

    static Legkor *GetPeldany();
    void FirstAdd(Anyag *a); //réteg felvétele
    void Add(Anyag *a); //réteg felvétele
    void SetViszonyok(std::string v); //viszonyok beállítása

    void Szimulacio(); //időjárás szimulációja
    bool Vege(); //Végig nézi a rétegeket, hogy mind a 3 anyag megtalálható-e. Ha nem false-al tér vissza.(mikor áll le a szimuláció!)

    void Reagalas(char ido);  //mi reagál az adott időjárási viszonyban, az mivé alakul át és mekkor százalékban
    void RetegRendezes();   //Létre jött-e új réteg vagy vékonyá vált-e?

    ~Legkor(); //destruktor
};

