#include <iostream>

/**
 * @brief Hledá hodnotu 'cil' v SEŘAZENÉM poli 'pole'.
 * @param pole Prohledávané pole (musí být seřazené!).
 * @param velikost Počet prvků v poli.
 * @param cil Hledaná hodnota.
 * @return Index prvku 'cil', nebo -1, pokud není nalezen.
 */
int binarySearch(int pole[], int velikost, int cil) {
    int left = 0;
    int right = velikost - 1;

    while (left <= right) {
        // (left + right) / 2 může přetéct, pokud jsou čísla velká
        // Bezpečnější způsob je:
        int middle = left + (right - left) / 2;

        // 1. Shoda
        if (pole[middle] == cil) {
            return middle; // Nalezeno!
        }

        // 2. Cíl je v pravé polovině
        if (pole[middle] < cil) {
            left = middle + 1;
        } 
        // 3. Cíl je v levé polovině
        else {
            right = middle - 1;
        }
    }

    return -1; // Nenalezeno, intervaly se překřížily
}

int main() {
    // POZOR: Data musí být seřazená!
    int data[] = {1, 3, 4, 5, 8, 12, 42, 55, 67, 89, 101};
    int velikost = sizeof(data) / sizeof(data[0]);

    int cil1 = 42;
    int cil2 = 99;

    std::cout << "Data: {1, 3, 4, 5, 8, 12, 42, 55, 67, 89, 101}" << std::endl;

    // Hledání prvku, který tam je
    int vysledek1 = binarySearch(data, velikost, cil1);
    if (vysledek1 != -1) {
        std::cout << "Hodnota " << cil1 << " nalezena na indexu: " << vysledek1 << std::endl;
    } else {
        std::cout << "Hodnota " << cil1 << " nenalezena." << std::endl;
    }

    // Hledání prvku, který tam není
    int vysledek2 = binarySearch(data, velikost, cil2);
    if (vysledek2 != -1) {
        std::cout << "Hodnota " << cil2 << " nalezena na indexu: " << vysledek2 << std::endl;
    } else {
        std::cout << "Hodnota " << cil2 << " nenalezena." << std::endl;
    }

    return 0;
}