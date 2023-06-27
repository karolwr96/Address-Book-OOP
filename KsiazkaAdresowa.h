#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "Menu.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    Menu menu;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami) {
        wybierzOpcjeZMenu();
    };
    void wybierzOpcjeZMenu();

};

#endif
