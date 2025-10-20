#include <iostream>

// --- Definice funkcí pro demonstraci (viz bod 7) ---

/**
 * @brief Funkce přebírá argument HODNOTOU (by value).
 * Vytvoří se lokální kopie proměnné 'x'.
 * Jakákoli změna 'x' ovlivní POUZE tuto kopii.
 */
void nezmeniHodnotu(int x) {
    x = 100;
    std::cout << "   -> Hodnota 'x' uvnitr funkce nezmeniHodnotu(): " << x << std::endl;
}

/**
 * @brief Funkce přebírá argument UKAZATELEM (by pointer).
 * Funkce dostane ADRESU v paměti.
 * Pomocí dereference (*) můžeme měnit PŮVODNÍ hodnotu na této adrese.
 */
void zmeniHodnotu(int* pX) {
    *pX = 100; // *pX znamená "hodnota na adrese pX"
    std::cout << "   -> Hodnota '*pX' uvnitr funkce zmeniHodnotu(): " << *pX << std::endl;
}


int main() {
    std::cout << "--- 1. Deklarace a operátor adresy (&) ---" << std::endl;
    int cislo = 42;
    int* pCislo; // Deklarace ukazatele na int

    pCislo = &cislo; // Přiřazení adresy proměnné 'cislo' do ukazatele 'pCislo'

    std::cout << "Hodnota proměnné 'cislo': " << cislo << std::endl;
    std::cout << "Adresa proměnné 'cislo' (&cislo): " << &cislo << std::endl;
    std::cout << "Hodnota ukazatele 'pCislo' (adresa, kterou drží): " << pCislo << std::endl;
    std::cout << "Adresa samotného ukazatele 'pCislo' (&pCislo): " << &pCislo << std::endl;

    std::cout << "\n--- 2. Operátor dereference (*) ---" << std::endl;
    // Pomocí * se dostaneme na hodnotu, na kterou ukazatel ukazuje
    int hodnotaZUkazatele = *pCislo;
    std::cout << "Hodnota získaná přes dereferenci (*pCislo): " << hodnotaZUkazatele << std::endl;

    std::cout << "\n--- 3. Změna hodnoty přes ukazatel ---" << std::endl;
    std::cout << "Původní hodnota 'cislo': " << cislo << std::endl;
    *pCislo = 100; // Jdeme na adresu a změníme hodnotu na ní
    std::cout << "Nová hodnota 'cislo' po změně přes ukazatel: " << cislo << std::endl;
    std::cout << "Hodnota *pCislo je nyní také: " << *pCislo << std::endl;

    std::cout << "\n--- 4. Ukazatele a pole ---" << std::endl;
    int pole[4] = {10, 20, 30, 40};
    int* pPole = pole; // Název pole je ukazatelem na jeho první prvek

    std::cout << "Adresa pole (pole): " << pole << std::endl;
    std::cout << "Adresa prvního prvku (&pole[0]): " << &pole[0] << std::endl;
    std::cout << "Hodnota pPole: " << pPole << std::endl;

    std::cout << "První prvek přes pPole (*pPole): " << *pPole << std::endl;
    std::cout << "První prvek přes pole (pole[0]): " << pole[0] << std::endl;

    std::cout << "\n--- 5. Aritmetika s ukazateli (procházení pole) ---" << std::endl;
    // pPole ukazuje na pole[0]
    std::cout << "pole[0] = " << *pPole << std::endl;

    // Posuneme ukazatel na další prvek
    pPole++;
    // pPole nyní ukazuje na pole[1]
    std::cout << "pole[1] = " << *pPole << std::endl;

    // Ekvivalentní zápisy pro pole[2]
    std::cout << "pole[2] (přes index): " << pole[2] << std::endl;
    std::cout << "pole[2] (přes aritmetiku): " << *(pole + 2) << std::endl;

    std::cout << "\n--- 6. Nulový ukazatel (nullptr) ---" << std::endl;
    int* pBezpecnyUkazatel = nullptr; // Inicializace na bezpečnou "nulovou" adresu

    std::cout << "Hodnota pBezpecnyUkazatel: " << pBezpecnyUkazatel << std::endl;

    if (pBezpecnyUkazatel == nullptr) {
        std::cout << "Ukazatel nikam neukazuje." << std::endl;
    }
    // Pokus o dereferenci nullptr by vedl k pádu programu!
    // *pBezpecnyUkazatel = 10; // TOTO BY ZPUSOBILO CHYBU (Segmentation fault)


    std::cout << "\n--- 7. Ukazatele a Funkce (Předání hodnotou vs. ukazatelem) ---" << std::endl;
    int mojeCislo = 5;
    std::cout << "Původní 'mojeCislo' před voláním funkcí: " << mojeCislo << std::endl;

    // A) Předání HODNOTOU
    nezmeniHodnotu(mojeCislo);
    std::cout << "'mojeCislo' po volání nezmeniHodnotu(mojeCislo): " << mojeCislo << " (nezměněno)" << std::endl;

    // B) Předání UKAZATELEM (ADRESOU)
    zmeniHodnotu(&mojeCislo); // Funkci předáme ADRESU
    std::cout << "'mojeCislo' po volání zmeniHodnotu(&mojeCislo): " << mojeCislo << " (ZMENENO!)" << std::endl;


    std::cout << "\n--- 8. Void ukazatel (void*) ---" << std::endl;
    int vek = 30;
    double prumer = 1.75;
    void* pObecny; // Obecný ukazatel

    // Může ukazovat na int
    pObecny = &vek;
    std::cout << "pObecny ukazuje na adresu: " << pObecny << std::endl;
    // Musíme ho přetypovat zpět na int*, abychom ho mohli použít
    int* pIntVek = static_cast<int*>(pObecny);
    std::cout << "Hodnota veku (pres void*): " << *pIntVek << std::endl;

    // Může ukazovat i na double
    pObecny = &prumer;
    std::cout << "pObecny nyní ukazuje na adresu: " << pObecny << std::endl;
    // Musíme ho přetypovat na double*
    double* pDoublePrumer = static_cast<double*>(pObecny);
    std::cout << "Hodnota prumeru (pres void*): " << *pDoublePrumer << std::endl;


    return 0;
}
