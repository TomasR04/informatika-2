#include <iostream> // Pro vstup a vystup


int main() {
    // --- 1. Cykly: for ---
    std::cout << "--- 1. Cykly: for ---" << std::endl;
    std::cout << "Vypis cisel od 1 do 5:" << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << "  - Cislo: " << i << std::endl;
    }

    // --- 2. Cykly: while ---
    std::cout << "\n--- 2. Cykly: while ---" << std::endl;
    int soucet = 0;
    int cislo;
    std::cout << "Scitej cisla, dokud nezadas 0." << std::endl;
    std::cout << "Zadej cislo (0 pro konec): ";
    std::cin >> cislo;
    while (cislo != 0) {
        soucet += cislo;
        std::cout << "Zadej dalsi cislo (0 pro konec): ";
        std::cin >> cislo;
    }
    std::cout << "Celkovy soucet zadanych cisel je: " << soucet << std::endl;

    // --- 3. Cykly: do-while ---
    std::cout << "\n--- 3. Cykly: do-while ---" << std::endl;
    char volba;
    do {
        // Tento blok se provede minimalne jednou
        std::cout << "\n--- Menu ---" << std::endl;
        std::cout << "a) Zobrazit zpravu" << std::endl;
        std::cout << "q) Konec" << std::endl;
        std::cout << "Tvoje volba: ";
        std::cin >> volba;

        if (volba == 'a') {
            std::cout << "Zprava: C++ je super!" << std::endl;
        }
    } while (volba != 'q');
    std::cout << "Program ukoncen." << std::endl;

    // --- 4. Rizeni cyklu: break a continue ---
    std::cout << "\n--- 4. Rizeni cyklu: break a continue ---" << std::endl;
    std::cout << "Hledame prvni cislo delitelne 7 mezi 1 a 20:" << std::endl;
    for (int i = 1; i <= 20; i++) {
        if (i % 7 == 0) {
            std::cout << "Nalezeno! Je to cislo " << i << "." << std::endl;
            break; // Okamzite ukonci 'for' cyklus
        }
    }

    std::cout << "\nVypisujeme pouze licha cisla od 1 do 10:" << std::endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) { // Pokud je cislo sude...
            continue; // ...preskoc zbytek iterace a pokracuj dalsi
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

