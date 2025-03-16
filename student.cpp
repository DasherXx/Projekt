#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include "class.hpp"


using namespace std;



void Student::pobieranieDanych() {
        
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
}
    
void Student::wyswietlanieDanych() {
        
    cout << endl << "imie: " << imie << std::endl;
    cout << "nazwisko: " << nazwisko << std::endl;
    cout << "profil: " << profil << std::endl;
    cout << "semestr: " << semestr << std::endl;
    cout << "wiedza: " << wiedza << std::endl;
    cout << "energia: " << energia << std::endl;
    cout << "stres: " << stres << std::endl;
    cout << "punkty doswiadczenia (XP): " << punktyDoswiadczenia << std::endl;
}

Student::Student(string _imie, string _nazwisko, string _profil, int _semestr, int _wiedza, int _energia, int _stres, int _punktyDoswiadczenia) {

    imie = _imie;
    nazwisko = _nazwisko;
    profil = _profil;
    semestr = _semestr;
    wiedza = _wiedza;
    energia = _energia;
    stres = _stres;
    punktyDoswiadczenia = _punktyDoswiadczenia;

}
void Student::uczeSie() {
    cout << imie << " " << nazwisko << " Uczy sie ... ";
    Sleep(2000); 
    cout << "... ";
    Sleep(2000); 
    cout << "... ";
    Sleep(2000);
    wiedza += 40;
    energia -= 20;
    stres += 15;
    zdobadzXp(40); 
    
}

void Student::imprezuj() {
    cout << imie << " " << nazwisko << " Imprezuje ... ";
    Sleep(2000); 
    cout << "... ";
    Sleep(2000); 
    cout << "... ";
    Sleep(2000); 
    cout << "..." << endl;
    wiedza -= 25;
    energia -= 30;
    stres += 50;
    zdobadzXp(40);
}

void Student::odpoczywaj() {
    cout << imie << " " << nazwisko << " Odpoczywa ... ";
    Sleep(2000); 
    cout << "... ";
    Sleep(2000); 
    cout << "... ";
    Sleep(2000); 
    cout << "..." << endl;
    energia += 25;
    stres -= 10;
    zdobadzXp(20);
}

void Student::zdobadzXp(int xp) {
    punktyDoswiadczenia += xp;
    cout << imie << " " << nazwisko << " Zdobyl: " << xp << "pkt doswiadczenia(xp)" << endl << endl;
    //sprawdzAwans();
    

}

bool Student::sprawdzAwans() {
    int wymaganyXP = semestr * 100; 
    int wymaganaWiedza = semestr * 75;

    Egzaminy egzamin;
    bool wynikEgzaminu = false;

    if(stres >= 40 && stres < 69) {
            Okna_dialogowe krytyczny;
            krytyczny.krytyczny();
            
    } else if(stres >= 70) {
            Okna_dialogowe choroszcza;
            choroszcza.choroszcza();
        while (true) {
            if (GetAsyncKeyState(VK_ESCAPE)) {
                exit(0);                               // Zamyka program po naciśnięciu ESC
            }
        }
    return false;
    }



    if (punktyDoswiadczenia >= wymaganyXP && wiedza < wymaganaWiedza) {
        cout << "Gratulacje!!! " << imie << " " << nazwisko << " zostajesz dopuszczony do zaliczenia semestru: " << semestr << endl;
        cout << "Twoja wiedza jest zbyt niska, egzamin bedzie trudny." << endl;
        wynikEgzaminu = egzamin.trudny();
    } 
    else if (punktyDoswiadczenia >= wymaganyXP && wiedza >= wymaganaWiedza) {
        cout << "Gratulacje!!! " << imie << " " << nazwisko << " zostajesz dopuszczony do zaliczenia semestru: " << semestr << endl;
        cout << "Twoja wiedza jest wystarczajaca, egzamin bedzie latwy." << endl;
        wynikEgzaminu = egzamin.latwy();
    } 
    else {
        cout << "Nie masz wystarczajacego doswiadczenia, aby podejsc do egzaminu." << endl;
        return false; 
    }

    if (wynikEgzaminu) {
        cout << "Egzamin zdany! Przechodzisz na kolejny semestr." << endl;
        semestr++;
        wiedza += 20;
        energia = 100;
        stres = 0;
    } else {
        cout << "Egzamin niezdany. Musisz sprobowac ponownie." << endl;
    }

    return wynikEgzaminu;
}
 

   //C:\Users\mkopt\Desktop\1111\projekt\moje\13.03