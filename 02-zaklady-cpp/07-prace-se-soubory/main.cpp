#include <iostream>
#include <fstream> // Pro práci se soubory (ifstream, ofstream)
#include <string>  // Pro použití std::string
#include <vector>  // Pro použití std::vector

// Pomocná funkce pro výpis obsahu souboru, abychom se neopakovali
void vypisObsahSouboru(const std::string& nazevSouboru) {
    std::ifstream soubor(nazevSouboru);
    if (!soubor.is_open()) {
        std::cout << "Soubor '" << nazevSouboru << "' se nepodarilo otevrit pro cteni." << std::endl;
        return;
    }
    std::cout << "--- Obsah souboru: " << nazevSouboru << " ---" << std::endl;
    std::string radek;
    while (std::getline(soubor, radek)) {
        std::cout << radek << std::endl;
    }
    std::cout << "------------------------------------" << std::endl << std::endl;
    soubor.close();
}

int main() {
    const std::string nazevSouboru = "data.txt";

    // --- 1. ZÁPIS DO SOUBORU (PŘEPSÁNÍ) ---
    std::cout << "1. Zapisuji do souboru '" << nazevSouboru << "' (mod prepsani)..." << std::endl;
    std::ofstream zapisProud(nazevSouboru); // Ve výchozím módu soubor přepíše, pokud existuje
    if (zapisProud.is_open()) {
        zapisProud << "Prvni radek textu." << std::endl;
        zapisProud << "Na druhem radku jsou cisla: 10 20 30" << std::endl;
        zapisProud.close();
        std::cout << "Zapis uspesny." << std::endl;
    } else {
        std::cerr << "Chyba: Soubor se nepodarilo otevrit pro zapis!" << std::endl;
        return 1;
    }

    vypisObsahSouboru(nazevSouboru);


    // --- 2. ZÁPIS DO SOUBORU (PŘIDÁNÍ NA KONEC) ---
    std::cout << "2. Pridavam na konec souboru '" << nazevSouboru << "' (mod append)..." << std::endl;
    std::ofstream appendProud(nazevSouboru, std::ios::app); // std::ios::app zajistí přidání na konec
    if (appendProud.is_open()) {
        appendProud << "Tento radek byl pridan dodatecne." << std::endl;
        appendProud.close();
        std::cout << "Pridani uspesne." << std::endl;
    } else {
        std::cerr << "Chyba: Soubor se nepodarilo otevrit pro pridani!" << std::endl;
        return 1;
    }

    vypisObsahSouboru(nazevSouboru);


    // --- 3. ČTENÍ ZE SOUBORU ---
    std::cout << "3. Ctu data ze souboru a zpracovavam je..." << std::endl;
    std::ifstream cteniProud(nazevSouboru);
    if (cteniProud.is_open()) {
        std::string radek;
        int radekCislo = 1;
        while (std::getline(cteniProud, radek)) {
            std::cout << "   Nacten radek c." << radekCislo << ": '" << radek << "'" << std::endl;
            radekCislo++;
        }
        cteniProud.close();
    } else {
        std::cerr << "Chyba: Soubor se nepodarilo otevrit pro cteni!" << std::endl;
        return 1;
    }
    std::cout << std::endl;


    // --- 4. UKÁZKA KONTROLY CHYB ---
    std::cout << "4. Pokousim se otevrit neexistujici soubor..." << std::endl;
    std::ifstream chybnyProud("neexistuje.txt");
    if (!chybnyProud.is_open()) {
        std::cerr << "   Ocekavana chyba: Soubor 'neexistuje.txt' se nepodarilo otevrit." << std::endl;
    }

    return 0;
}
