#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "class.hpp"

using namespace std;

bool Gry::jednoreki() {
    srand(time(0));

    string symbole[3] = {"++++", "----", "????"};  
    int slot1 = rand() % 3;
    int slot2 = rand() % 3;
    int slot3 = rand() % 3;

    cout << "Jednoreki bandyta!" << endl;
    cout << "[" << symbole[slot1] << "] [" << symbole[slot2] << "] [" << symbole[slot3] << "]" << endl;

    if (slot1 == slot2 && slot2 == slot3) {
        cout << "Jackpot! Wygrales!" << endl; 
        return true;  
    } else {
        cout << "Sprobuj ponownie!" << endl;
        return false;
    }
}
    
bool Gry::kamienPapierNozyce() {
    string opcje[3] = {"Kamien", "Papier", "Nozyce"};
    int wybor_gracza, wybor_komputera;

    wybor_komputera = rand() % 3;

    cout << "Zagraj w Kamien, Papier, Nozyce!" << endl;
    cout << "1. Kamien" << endl << "2. Papier" << endl << "3. Nozyce" << endl;
    
    cout << "Twoj wybor: ";
    cin >> wybor_gracza;
    wybor_gracza--; 

    if (wybor_gracza < 0 || wybor_gracza > 2) {
        cout << "Nieprawidlowy wybor! Wybierz 1, 2 lub 3." << endl;
        return false;
    }

    cout << "Twoj wybor: " << opcje[wybor_gracza] << endl;
    cout << "Komputer wybral: " << opcje[wybor_komputera] << endl;


    if (wybor_gracza == wybor_komputera) {
        cout << "Obaj wybraliscie to samo - remis!" << endl;
        return false;
    } else if ((wybor_gracza == 0 && wybor_komputera == 2)) {
        cout << "Kamien tępi nożyce - wygrales!" << endl;
        return true;
    } else if ((wybor_gracza == 1 && wybor_komputera == 0)) {
        cout << "Papier owija kamien - wygrales!" << endl;
        return true;
    } else if ((wybor_gracza == 2 && wybor_komputera == 1)) {
        cout << "Nozyce przecinaja papier - wygrales!" << endl;
        return true;
    } else {
        cout << "Przegrales!" << endl;
        return false;
    }
}

bool Gry::zgadnijLiczbe() {
    srand(time(0));
    int wybrana_liczba;
    int wylosowana_liczba = ((rand() % 1000) + 1);
    int licznik_prob = 0;

    cout << "----Witaj w grze! Musisz odgadnac liczbe od 1 do 1000----" << endl;

    while (true) {
        cout << "Wpisz liczbe: ";
        cin >> wybrana_liczba;
        licznik_prob++;

        if (wybrana_liczba > wylosowana_liczba) {
            cout << "Szukaj mniejszej..." << endl;
        } else if (wybrana_liczba < wylosowana_liczba) {
            cout << "szukaj wiekszej..." << endl;
        } else {
            cout << "----Trafiony zatopiony !!!----" << endl;
            cout << "Licznik prob: " << licznik_prob << endl; 
            return true;
        }
    }
}

bool Gry::orzelReszka() {
    srand(time(0));
    int wybor, rzut;
    
    cout << "----- Orzel czy Reszka -----" << endl;
    
    while (true) {
        cout << "Wybierz:" << endl;
        cout << "1 - Orzel" << endl;
        cout << "2 - Reszka" << endl;
        cout << "3 - Zakoncz" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if (wybor == 3) {
            cout << "KONIEC GRY" << endl;
            return false;
        }
        
        if (wybor != 1 && wybor != 2) {
            cout << "Niepoprawny wybor, sprobuj ponownie!" << endl;
            continue;
        }
        
        rzut = rand() % 2 + 1;
        cout << "Komputer wylosowal: " << (rzut == 1 ? "Orzel" : "Reszka") << endl;
        
        if (wybor == rzut) {
            cout << "Gratulacje! Wygrales!" << endl;
            return true; 
        } else {
            cout << "Niestety, przegrales." << endl;
            return false;
        }
    }
}

// Losujemy gre 

void Gry::wylosujGre() {
    srand(time(0));  
    int losowaGra = rand() % 4 + 1;  

    switch (losowaGra) {
        case 1:
            cout << "Losujemy... Orzel czy Reszka!" << endl;
            orzelReszka();
            break;
        case 2:
            cout << "Losujemy... Zgadywanie Liczby!" << endl;
            zgadnijLiczbe();
            break;
        case 3:
            cout << "Losujemy... Kamień, Papier, Nożyce!" << endl;
            kamienPapierNozyce();
            break;
        case 4:
            cout << "Losujemy... Jednoręki Bandyta!" << endl;
            jednoreki();
            break;
        default:
            cout << "Błąd losowania!" << endl;
    }
}
