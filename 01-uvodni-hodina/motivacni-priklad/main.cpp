#include <iostream>  
#include <fstream>  
#include <string>  
#include <vector>  
#include <cctype>

int main() {  
    std::ifstream soubor("input.txt");  
    if (!soubor.is_open()) {  
        std::cerr << "Chyba: Soubor 'input.txt' se nepodarilo otevrit." << std::endl;  
        return 1;  
    }

    int celkovy_soucet = 0;  
    std::string radek;

    while (std::getline(soubor, radek)) {  
        char prvni_cislice = '0';  
        char posledni_cislice = '0';

        // Najdi prvni cislici  
        for (char znak : radek) {  
            if (isdigit(znak)) {  
                prvni_cislice = znak;  
                break;  
            }  
        }

        // Najdi posledni cislici (iterace od konce)  
        for (int i = radek.length() - 1; i >= 0; --i) {  
            if (isdigit(radek[i])) {  
                posledni_cislice = radek[i];  
                break;  
            }  
        }

        if (prvni_cislice != '0') {  
            int hodnota = (prvni_cislice - '0') * 10 + (posledni_cislice - '0');  
            celkovy_soucet += hodnota;  
        }  
    }

    soubor.close();  
    std::cout << "Celkovy soucet v C++ je: " << celkovy_soucet << std::endl;

    return 0;  
}