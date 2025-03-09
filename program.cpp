#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <algorithm>
#include <cctype>
#include "class.hpp"

using namespace std;

int main() {
    
    Okna_dialogowe oknaDialogowe;
    oknaDialogowe.rozpoczecie_gry();

    string imie, nazwisko;

    cout << "Podaj swoje imie: ";
    cin >> imie;
    cout << "Podaj swoje nazwisko: ";
    cin >> nazwisko;

    Student pracus(imie, nazwisko, "Pracus", 1, 10, 100, 15, 0 );
    Student imprezowicz(imie, nazwisko, "Imprezowicz", 1, 10, 100, 15, 0 );
    Student obibok(imie, nazwisko, "Obibok", 1, 10, 125, 15, 0 );

    int wybor;
    Student *gracz = nullptr;

    cout << endl << "Wybierz profil studenta: " << endl;
    cout << "1. Pracus:         |  przecietny 35 latek pracujacy na grubie i studiujacy" << endl; 
    cout << "2. Imprezowicz:    |  osoba ktora lubi sie napic ma duzo szczescia ale malo rozumu" << endl; 
    cout << "3. Obibok:         |  osoba pokroju  slynnego Filemona" << endl; 
    cout << "Twoj wybor: " << endl;
    cin >> wybor;

    switch(wybor) {
        case 1:
            gracz = &pracus;
            break;
        case 2:
            gracz = &imprezowicz;
            break;
        case 3:
            gracz = &obibok;
            break;
        default:
            cout << "Nieprawidłowy wybór. Domyślnie Obibok." << endl; 
            gracz = &obibok;
    }




    cout << endl << "Twoj profil: ";
    gracz->wyswietlanieDanych(); 
        
    int dzien;
    string koniec_dnia;

    // tu zaczyna sie petla do ...while ktora odpowiada za zdobywanie expa i statystyk, oraz awans na nastepny semestr , w przyszlosci dodac trzeba egzamin na koniec semestru 
    // oraz mozliwosc odpadniecia ze studiow gdy np: stres bedzie za wysoki albo skonczy sie energia.
do {  

    cout << endl << "Co dzisiaj bedziemy robic? " << endl;
    cout << "1. Uczyc sie ? " << endl;
    cout << "2. Imprezka? " << endl;
    cout << "3. Odpoczynek? " << endl;

    cin >> dzien;
    
    srand(time(0));

    switch(dzien) {

        case 1:
            gracz->uczeSie();
            oknaDialogowe.minigierka();
            break;
        case 2:
            gracz->imprezuj();
            oknaDialogowe.minigierka();
            break;
        case 3:
            gracz->odpoczywaj();
            oknaDialogowe.minigierka();
            break;
        default:
            std::cout << "Nie ma juz teraz odwrotu" << std::endl;
    }
    
    
    gracz->wyswietlanieDanych();
    gracz->sprawdzAwans();
    cout << R"(  -----------------           Nastepny dzien: wcisnij "t"           ---------------------)" << endl;
    cin >> koniec_dnia;

} while (koniec_dnia == "t" );

    oknaDialogowe.zakonczenie_gry();
    system("pause"); // zebys sie automatycznie nie zamykal program , czeka na wcisniecie klawisza
    
    
    


    //oknaDialogowe.informacje_klasy();

    // oknaDialogowe.wyborKlasy();

    //Gry zagrajmy;  
    //zagrajmy.wylosujGre();           // idzie do pliku gry.cpp  losuje jedna z 4 gier i uruchamia 

    return 0;
}