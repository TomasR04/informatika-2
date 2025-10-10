#include <iostream> // Pro vstup a vystup
#include <string> // Pro pouziti tridy std::string
#include <vector> // Pro pouziti kontejneru std::vector (moderni alternativa k C-style polim)

// Funkce pro tisk prvku jednorozmerneho pole int
void tiskniPole(int pole[], int velikost) {
    for (int i = 0; i < velikost; ++i) {
        std::cout << pole[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // --- 1. Jednorozmerna pole ---
    std::cout << "--- 1. Jednorozmerna pole (C-style) ---" << std::endl;
    int cisla[5] = {10, 20, 30, 40, 50};

    // Pristup k prvkum pomoci indexu (cislovani od 0)
    std::cout << "Prvni prvek (index 0): " << cisla[0] << std::endl;
    std::cout << "Treti prvek (index 2): " << cisla[2] << std::endl;

    // Zmena hodnoty prvku
    cisla[0] = 11;
    std::cout << "Prvni prvek po zmene: " << cisla[0] << std::endl;

    // Vypis pole pomoci cyklu
    std::cout << "Vypis celeho pole: ";
    int velikost = sizeof(cisla) / sizeof(cisla[0]);
    tiskniPole(cisla, velikost);

    // --- 2. Retezce (C-style) ---
    std::cout << "\n--- 2. Retezce (C-style) ---" << std::endl;
    char pozdrav[] = "Ahoj svete!";
    std::cout << pozdrav << std::endl;
    // Zmena pismene v retezci
    pozdrav[0] = 'a';
    std::cout << "Po zmene: " << pozdrav << std::endl;

    // --- 3. std::string (doporuceny zpusob) ---
    std::cout << "\n--- 3. std::string (doporuceny zpusob) ---" << std::endl;
    std::string jmeno = "Petr";
    std::string prijmeni = "Svoboda";

    // Spojovani retezcu (konkatenace)
    std::string celeJmeno = jmeno + " " + prijmeni;
    std::cout << "Cele jmeno: " << celeJmeno << std::endl;

    // Metody tridy string
    std::cout << "Delka jmena '" << jmeno << "': " << jmeno.length() << " znaku." << std::endl;
    std::cout << "Treti pismeno jmena: " << jmeno[2] << std::endl; // pristup jako u pole

    // --- 4. std::vector (moderni a flexibilni pole) ---
    std::cout << "\n--- 4. std::vector (moderni alternativa k polim) ---" << std::endl;
    std::vector<int> data = {1, 2, 3, 4};
    std::cout << "Pocatecni vektor: ";
    for (int prvek : data) { // Range-based for loop - pohodlnejsi vypis
        std::cout << prvek << " ";
    }
    std::cout << std::endl;

    // Vektor muze menit svou velikost za behu programu
    data.push_back(5); // Pridani prvku na konec
    std::cout << "Vektor po pridani prvku: ";
    for (int prvek : data) {
        std::cout << prvek << " ";
    }
    std::cout << std::endl;
    std::cout << "Aktualni velikost vektoru: " << data.size() << std::endl;

    // --- 5. Vicerozmerna pole (matice) ---
    std::cout << "\n--- 5. Vicerozmerna pole (matice 2x3) ---" << std::endl;
    int matice[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    // Vypis matice pomoci vnorerenych cyklu
    for (int i = 0; i < 2; ++i) { // Prochazeni radku
        for (int j = 0; j < 3; ++j) { // Prochazeni sloupcu
            std::cout << matice[i][j] << "\t"; // \t je tabulator pro zarovnani
        }
        std::cout << std::endl; // Novy radek po kazdem radku matice
    }

    return 0;
}

