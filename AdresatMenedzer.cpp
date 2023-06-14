#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    int modyfikowaneId = plikZAdresatami.pobierzIdOstatniegoAdresata();
    modyfikowaneId++;
    plikZAdresatami.dodajWartoscDoIdOstatniegoAdresata(modyfikowaneId);

    return;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;

    int ID = plikZAdresatami.pobierzIdOstatniegoAdresata();
    adresat.ustawId(++ID);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    string imie = MetodyPomocnicze::wczytajLinie();
    MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    string nazwisko = MetodyPomocnicze::wczytajLinie();
    MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    string numerTelefonu = MetodyPomocnicze::wczytajLinie();
    adresat.ustawNumerTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    string email = MetodyPomocnicze::wczytajLinie();
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    string adres = MetodyPomocnicze::wczytajLinie();
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int IDZALOGOWANEGOUZYTKOWNIKA) {
    idZalogowanegoUzytkownika = IDZALOGOWANEGOUZYTKOWNIKA;
}

void AdresatMenedzer::wyczyscVector() {
    adresaci.clear();
}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}
