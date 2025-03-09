#include <iostream>
#include "class.hpp"
#include <locale.h>
#include <algorithm>
#include <cctype>


void Okna_dialogowe::rozpoczecie_gry() {
    
    std::cout << R"(  -----------------           Witamy w grze           ---------------------)" << std::endl; //https://patorjk.com/software/taag/ strona do rysowania tagow
    std::cout << R"(       _______     ____  __ _    _ _            _______ ____  _____        )" << std::endl;
    std::cout << R"(      / ____\ \   / /  \/  | |  | | |        /\|__   __/ __ \|  __ \       )" << std::endl;
    std::cout << R"(     | (___  \ \_/ /| \  / | |  | | |       /  \  | | | |  | | |__) |      )" << std::endl;
    std::cout << R"(      \___ \  \   / | |\/| | |  | | |      / /\ \ | | | |  | |  _  /       )" << std::endl;
    std::cout << R"(      ____) |  | |  | |  | | |__| | |____ / ____ \| | | |__| | | \ \       )" << std::endl;
    std::cout << R"(     |_____/   |_|  |_|  |_|\____/|______/_/    \_\_|  \____/|_|  \_\      )" << std::endl;
    std::cout << R"(                                                                           )" << std::endl;
    std::cout << R"(                                                                           )" << std::endl;
    std::cout << R"(           _____ _______ _    _ _____  ______ _   _ _______                )" << std::endl;
    std::cout << R"(          / ____|__   __| |  | |  __ \|  ____| \ | |__   __|/\             )" << std::endl;
    std::cout << R"(         | (___    | |  | |  | | |  | | |__  |  \| |  | |  /  \            )" << std::endl;
    std::cout << R"(          \___ \   | |  | |  | | |  | |  __| | . ` |  | | / /\ \           )" << std::endl;
    std::cout << R"(          ____) |  | |  | |__| | |__| | |____| |\  |  | |/ ____ \          )" << std::endl;
    std::cout << R"(         |_____/   |_|   \____/|_____/|______|_| \_|  |_/_/    \_\         )" << std::endl << std::endl << std::endl;

    while(true){
    std::cout << "Czy chcesz rozpoczac gre ? (t/n): " << std::endl;
    std::cin >> start_gry;
    start_gry = std::tolower(start_gry);
    if (start_gry == 't') {
        std::cout << "--- Zapraszamy do gry ---" << std::endl;
        komunikat();
        break;
    } else if (start_gry == 'n') {
        std::cout << "--- Do zobaczenia ---" << std::endl;
        exit(0);
    }
}
}
void Okna_dialogowe::zakonczenie_gry() {
    std::cout << R"(  -----------------           Do zobaczenia           ---------------------)" << std::endl;

}


void Okna_dialogowe::komunikat(){
    std::cout<<"Podaj nam troche informacji o sobie: " << std::endl;
}

void Okna_dialogowe::informacje_klasy(){ //Trzeba dodac obsluge jedynie liczb bo sie program wypierdala jak to bedzie cos innego niz liczba
    std::cout<<"Dowiedz sie wiecej o profesjach: "<<std::endl;
    std::cout<<"1. Imprezowicz"<<std::endl;
    std::cout<<"2. Pracus"<<std::endl;
    std::cout<<"3. Obibok"<<std::endl;
    std::cout << "4. --- Wybierz postac ---" << std::endl;
    std::cout<<"5. Wyjdz z gry"<<std::endl;
    while(true){
    std::cin>>infoKlasy;
        switch (infoKlasy) {
            case 1:
                std::cout << "Imprezowicz - Osoba ktora lubi sie napic ma duzo szczescia ale malo rozumu"<<std::endl;
                break;
            case 2:
                std::cout << "Pracus - Przecietny 35 latek pracujacy na grubie i studiujacy"<<std::endl;
                break;
            case 3:
                std::cout << "Obibok - Osoba pokroju  slynnego Filemona, bi-seks "<<std::endl;
                break;
            case 4:
                wyborKlasy(); 
                return;
            case 5:
                exit(0); 
            default:
                std::cout << "Zly numer sprobuj ponownie." << std::endl;
                break;          
    }
}
}

void Okna_dialogowe::wyborKlasy(){
    std::cout<<"Czy chcesz wybrac postac ? (t/n)"<<std::endl;
    std::cin>>wyborPostacii;
    if (wyborPostacii == 't') {
        std::cout << "---  ---" << std::endl;
        return;

}
    else if (wyborPostacii == 'n') {
        informacje_klasy();
        return;
}
}
void Okna_dialogowe::minigierka() {
    char wyborGracza;  
    std::cout << "Czy chcesz zagrac minigre aby zwiekszyc statystyki?? (t/n)" << std::endl; 
    std::cin >> wyborGracza;

    if (wyborGracza == 't') {
        Gry gra;  
        gra.wylosujGre();  
        return;
    }
    else if (wyborGracza == 'n') {
        return;
    }
}