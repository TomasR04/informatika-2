#include <iostream>

/**
 * @brief Hledá hodnotu 'cil' v poli 'pole' o dané velikosti.
 * @param pole Prohledávané pole.
 * @param velikost Počet prvků v poli.
 * @param cil Hledaná hodnota.
 * @return Index prvního výskytu 'cil', nebo -1, pokud není nalezen.
 */
int linearSearch(int pole[], int velikost, int cil) {
    for (int i = 0; i < velikost; i++) {
        if (pole[i] == cil) {
            return i; // Nalezeno! Vracíme index.
        }
    }
    return -1; // Nenalezeno.
}

int main() {
    int data[] = {4, 1, 8, 3, 42, 12, 5};
    int velikost = sizeof(data) / sizeof(data[0]);

    int cil1 = 42;
    int cil2 = 99;

    std::cout << "Data: {4, 1, 8, 3, 42, 12, 5}" << std::endl;

    // Hledání prvku, který tam je
    int vysledek1 = linearSearch(data, velikost, cil1);
    if (vysledek1 != -1) {
        std::cout << "Hodnota " << cil1 << " nalezena na indexu: " << vysledek1 << std::endl;
    } else {
        std::cout << "Hodnota " << cil1 << " nenalezena." << std::endl;
    }

    // Hledání prvku, který tam není
    int vysledek2 = linearSearch(data, velikost, cil2);
    if (vysledek2 != -1) {
        std::cout << "Hodnota " << cil2 << " nalezena na indexu: " << vysledek2 << std::endl;
    } else {
        std::cout << "Hodnota " << cil2 << " nenalezena." << std::endl;
    }

    return 0;
}