#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer {
    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    PlikZAdresatami plikZAdresatami;

public :
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {
    };
    void dodajAdresata();
    Adresat podajDaneNowegoAdresata();
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    void ustawIdZalogowanegoUzytkownika(int IDZALOGOWANEGOUZYTKOWNIKA);
    void wyczyscVector();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};

#endif
