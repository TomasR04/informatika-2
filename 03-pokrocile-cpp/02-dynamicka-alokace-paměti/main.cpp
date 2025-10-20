#include <iostream>
#include <new> // Pro std::bad_alloc

int main() {
    // --- 1. Alokace a uvolnění JEDNOHO prvku ---
    std::cout << "--- 1. Alokace a uvolneni jednoho prvku ---" << std::endl;
    int* pCislo = nullptr;

    try {
        pCislo = new int; // Alokujeme paměť pro jeden int na haldě
        std::cout << "Pamet pro int alokovana na adrese: " << pCislo << std::endl;

        *pCislo = 123; // Zapíšeme hodnotu do alokované paměti
        std::cout << "Hodnota na alokovane adrese: " << *pCislo << std::endl;

        delete pCislo; // UVOLNÍME paměť
        std::cout << "Pamet pro int uvolnena." << std::endl;
        pCislo = nullptr; // Nastavíme ukazatel na null, aby neukazoval na neplatnou paměť

        // POZOR: Přístup k paměti po delete je chyba!
        // if (pCislo != nullptr) {
        //     std::cout << *pCislo; // Toto by mohlo spadnout nebo vypsat nesmysl
        // }

    } catch (const std::bad_alloc& e) {
        std::cerr << "Chyba alokace pameti: " << e.what() << std::endl;
    }


    // --- 2. Alokace a uvolnění POLE ---
    std::cout << "\n--- 2. Alokace a uvolneni pole ---" << std::endl;
    int velikost = 5;
    int* pPole = nullptr;

    try {
        pPole = new int[velikost]; // Alokujeme paměť pro pole 5 intů
        std::cout << "Pamet pro pole " << velikost << " int alokovana na adrese: " << pPole << std::endl;

        // Naplníme pole hodnotami
        for (int i = 0; i < velikost; ++i) {
            pPole[i] = (i + 1) * 10;
        }

        // Vypíšeme pole
        std::cout << "Obsah dynamickeho pole: ";
        for (int i = 0; i < velikost; ++i) {
            std::cout << pPole[i] << " ";
        }
        std::cout << std::endl;

        delete[] pPole; // UVOLNÍME paměť alokovanou pro POLE
        std::cout << "Pamet pro pole uvolnena." << std::endl;
        pPole = nullptr;

    } catch (const std::bad_alloc& e) {
        std::cerr << "Chyba alokace pameti pro pole: " << e.what() << std::endl;
    }


    // --- 3. Ukázka ÚNIKU PAMĚTI (Memory Leak) ---
    std::cout << "\n--- 3. Demonstrace uniku pameti (nedelejte to!) ---" << std::endl;
    for (int i = 0; i < 3; ++i) {
        int* pUnik = new int(i);
        std::cout << "Alokovano " << *pUnik << " na adrese " << pUnik << std::endl;
        // CHYBA: Zapomněli jsme 'delete pUnik;'
        // Ukazatel pUnik zanikne na konci cyklu, ale paměť zůstane alokovaná
    }
    std::cout << "Cyklus skoncil. 3 bloky pameti zustaly alokovane (memory leak)." << std::endl;


    // --- 4. Nebezpečí - Dvojité uvolnění (Double Free) ---
    std::cout << "\n--- 4. Demonstrace dvojiteho uvolneni (nedelejte to!) ---" << std::endl;
    int* pNebezpecny = new int(99);
    std::cout << "Alokovano " << *pNebezpecny << " na " << pNebezpecny << std::endl;
    delete pNebezpecny;
    std::cout << "Pamet uvolnena poprve." << std::endl;
    // pNebezpecny = nullptr; // TOTO by zabránilo chybě níže
    // delete pNebezpecny; // CHYBA: Pokus o uvolnění již uvolněné paměti. Může (a často i způsobí) pád programu.
    std::cout << "!!! Pokud program nespadl pri druhem delete, meli jsme stesti !!!" << std::endl;


    return 0;
}
