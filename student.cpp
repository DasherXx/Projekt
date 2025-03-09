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
    stres += 10;
    zdobadzXp(40); 
    
}

void Student::imprezuj() {
    cout << imie << " " << nazwisko << " Imprezuje..." << endl;
    Sleep(2000); 
    cout << "... ";
    Sleep(2000); 
    cout << "... ";
    Sleep(2000); 
    cout << "..." << endl;
    wiedza -= 25;
    energia -= 30;
    stres -= 25;
    zdobadzXp(40);
}

void Student::odpoczywaj() {
    cout << imie << " " << nazwisko << " Odpoczywa..." << endl;
    Sleep(2000); 
    cout << "... ";
    Sleep(2000); 
    cout << "... ";
    Sleep(2000); 
    cout << "..." << endl;
    // Dodac 25% szans na minigierke zwiekszajaca statystyki :P 
    energia += 25;
    stres -= 10;
    zdobadzXp(20);
}

void Student::zdobadzXp(int xp) {
    punktyDoswiadczenia += xp;
    cout << imie << " " << nazwisko << " Zdobyl: " << xp << "pkt doswiadczenia(xp)" << endl << endl;
    sprawdzAwans();

}
bool Student::sprawdzAwans() {
    int wymaganyXP = semestr * 100; 
    
    if(punktyDoswiadczenia >= wymaganyXP) {
        semestr++;
        wiedza += 20;
        energia = 100;
        stres = 0; 
        cout << "Gratulacje!!!" << imie << " " << nazwisko << " Awansował na semest: " << semestr << endl;
        return true;
    }
    return false;
}