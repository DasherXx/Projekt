#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "class.hpp"

using namespace std;

bool Egzaminy::trudny() {
    cout << "Egzamin......" << endl;
    
    /*srand(time(0)); 
    int szansa = rand() % 100; 
    if (szansa < 30) { // 30% szans na zdanie trudnego egzaminu
        cout << "Udalo Ci sie zdac trudny egzamin!" << endl;
        return true;
    } else {
        cout << "Niestety, nie zdales trudnego egzaminu." << endl;
        return false;
    }*/
}

bool Egzaminy::latwy() {
    cout << "Egzamin......" << endl;
    srand(time(0)); 
    int szansa = rand() % 100; 
    if (szansa < 70) { 
        cout << "Udalo Ci sie zdac latwy egzamin!" << endl;
        return true;
    } else {
        cout << "Niestety, nie zdales latwego egzaminu." << endl;
        return false;
    }
}
/*
int score = 0;
char answer;
cout >> "---- egzamin -----" << endl;

cout << "1. Jaki jest wynik dzialania 2 + 2?" << endl;
cout << "a) 3" << endl;
cout << "b) 4" << endl;
cout << "c) 5" << endl;
cout << "d) 6" << endl;
cout << "Twoja odpowiedz: ";
cin >> answer;

if(answer = 'b' || answer == 'B') {
    cout << "Dobra odpowiedz" << endl;
    score++;
} else {
    cout << "Zla odpowiedz, prawidlowa odpowiedz to: b) 4." << endl;
}


cout << "Koniec egzaminu, Twoj wynik to: " << score << endl;

*/