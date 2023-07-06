#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::wybierzOpcjeZMenu() {
    while (true) {
        if (!uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()) {
            char wybor = menu.wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                uzytkownikMenedzer.rejestracjaUzytkownika();
                break;
            case '2':
                uzytkownikMenedzer.logowanieUzytkownika();
                if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() > 0) {
                    adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
                }
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            char wybor = menu.wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                adresatMenedzer->dodajAdresata();
                break;
            case '2':
                adresatMenedzer->wyszukajAdresatowPoImieniu();
                break;
            case '3':
                adresatMenedzer->wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                adresatMenedzer->wyswietlWszystkichAdresatow();
                break;
            case '5':
                adresatMenedzer->usunAdresata();
                break;
            case '6':
                adresatMenedzer->edytujAdresata();
                break;
            case '7':
                uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                uzytkownikMenedzer.wylogujUzytkownika();
                delete adresatMenedzer;
                adresatMenedzer = NULL;
                break;
            }
        }
    }
    return;
}








