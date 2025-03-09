#include <string>
#ifndef CLASS_HPP_
#define CLASS_HPP_

using namespace std;

class Okna_dialogowe {
    public:

        int infoKlasy;
        void informacje_klasy();
        char start_gry;
        void rozpoczecie_gry();
        void zakonczenie_gry();
        void komunikat();
        void wyborKlasy();
        char wyborPostacii;
        void minigierka();
        char wyborGracza;

};

class Student {
    public:

    string imie;
    string nazwisko;
    string profil;
    int semestr;
    int wiedza;
    int energia;
    int stres;
    int punktyDoswiadczenia;
    
    Student(std::string _imie, std::string _nazwisko, std::string _profil, int _semestr, int _wiedza, int _energia, int _stres, int _punktyDoswiadczenia);
    
    void pobieranieDanych();
    void wyswietlanieDanych();
    void uczeSie();
    void odpoczywaj();
    void imprezuj();
    void zdobadzXp(int xp);
    bool sprawdzAwans();
};

class Gry {      // metody klasy Gry sa w osobnym pliku gry.cpp
    public:
    void wylosujGre();
    bool jednoreki();
    bool kamienPapierNozyce();
    bool zgadnijLiczbe();
    bool orzelReszka();
};


#endif