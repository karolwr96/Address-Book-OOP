#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "MetodyPomocnicze.h"

using namespace std;

class Menu {
public:
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    static char wybierzOpcjeZMenuEdycja();
};

#endif
