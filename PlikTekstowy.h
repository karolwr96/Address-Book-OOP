#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {
public:
    bool czyPlikJestPusty(fstream &plikTekstowy);
};

#endif
