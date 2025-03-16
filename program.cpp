#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <algorithm>
#include <cctype>
#include "class.hpp"

using namespace std;

int main() {
    
    //Okna_dialogowe oknaDialogowe;
    
    //oknaDialogowe.rozpoczecie_gry();

    Okna_dialogowe oknaDialogowe;
    oknaDialogowe.menu();

    string imie, nazwisko;

    cout << "Podaj swoje imie: ";
    cin >> imie;
    cout << "Podaj swoje nazwisko: ";
    cin >> nazwisko;

    Student pracus(imie, nazwisko, "Pracus", 1, 15, 100, 15, 0 );
    Student imprezowicz(imie, nazwisko, "Imprezowicz", 1, 5, 100, -15, 0 );
    Student obibok(imie, nazwisko, "Obibok", 1, 0, 125, 0, 0 );

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

        
    int dzien;
    string koniec_dnia;

    // Główna pętla gry ..... 
do {  
    cout << endl << "Twoj profil: ";
    gracz->wyswietlanieDanych();
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
            if(Gry::jednoreki) {
                gracz->wiedza += 10;
            }else if(Gry::orzelReszka) {
                gracz->wiedza += 10;
            }else if(Gry::kamienPapierNozyce) {
                gracz->wiedza +=10;
            }else if(Gry::zgadnijLiczbe) {
                gracz->wiedza += 10;
            }
            break;
        case 2:
            gracz->imprezuj();
            oknaDialogowe.minigierka();
            if(Gry::jednoreki) {
                gracz->wiedza += 10;
            }else if(Gry::orzelReszka) {
                gracz->wiedza += 10;
            }else if(Gry::kamienPapierNozyce) {
                gracz->wiedza +=10;
            }else if(Gry::zgadnijLiczbe) {
                gracz->wiedza += 10;
            }
            
            break;
        case 3:
            gracz->odpoczywaj();
            oknaDialogowe.minigierka();
            if(Gry::jednoreki) {
                gracz->wiedza += 10;
            }else if(Gry::orzelReszka) {
                gracz->wiedza += 10;
            }else if(Gry::kamienPapierNozyce) {
                gracz->wiedza +=10;
            }else if(Gry::zgadnijLiczbe) {
                gracz->wiedza += 10;
            }
            break;
        default:
            std::cout << "Nie ma juz teraz odwrotu" << std::endl;
    }

    gracz->sprawdzAwans();
    gracz->wyswietlanieDanych();
    cout << endl << R"(  -----------------           Nastepny dzien: wcisnij "t"           ---------------------)" << endl;
    cin >> koniec_dnia;
    system("cls");

} while (koniec_dnia == "t" );

    oknaDialogowe.zakonczenie_gry();
    system("pause"); // zebys sie automatycznie nie zamykal program , czeka na wcisniecie klawisza
    
    
    


    //oknaDialogowe.informacje_klasy();

    // oknaDialogowe.wyborKlasy();

    //Gry zagrajmy;  
    //zagrajmy.wylosujGre();           // idzie do pliku gry.cpp  losuje jedna z 4 gier i uruchamia 

    return 0;
}


//C:\Users\mkopt\Desktop\1111\projekt\moje      g++ -o program program.cpp gry.cpp okna_dialogowe.cpp student.cpp egzaminy.cpp