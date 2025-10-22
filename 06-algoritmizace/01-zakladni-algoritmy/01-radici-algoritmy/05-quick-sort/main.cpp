#include <iostream>

void prohod(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void vypisPole(int pole[], int velikost) {
    for (int i = 0; i < velikost; i++) {
        std::cout << pole[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Pomocná funkce pro rozdělení (partition) pole kolem pivota.
 * @param pole Pole k rozdělení.
 * @param low Dolní index.
 * @param high Horní index (pivot).
 * @return Index, na který se pivot přesunul (finální pozice pivota).
 */
int partition(int pole[], int low, int high) {
    int pivot = pole[high]; // Bereme poslední prvek jako pivota
    int i = (low - 1); // Index menšího prvku

    for (int j = low; j <= high - 1; j++) {
        // Pokud je aktuální prvek menší než pivot
        if (pole[j] < pivot) {
            i++; // Posuneme index menšího prvku
            prohod(&pole[i], &pole[j]);
        }
    }
    // Umístíme pivota na správné místo (za poslední menší prvek)
    prohod(&pole[i + 1], &pole[high]);
    return (i + 1);
}

/**
 * @brief Hlavní funkce algoritmu Quick Sort (rekurzivní).
 */
void quickSort(int pole[], int low, int high) {
    if (low < high) {
        // pi je index, kde je pivot nyní na svém finálním místě
        int pi = partition(pole, low, high);

        // Rekurzivně seřadíme prvky před pivotem
        quickSort(pole, low, pi - 1);
        // Rekurzivně seřadíme prvky za pivotem
        quickSort(pole, pi + 1, high);
    }
}

int main() {
    int data[] = {10, 7, 8, 9, 1, 5};
    int velikost = sizeof(data) / sizeof(data[0]);

    std::cout << "Puvodni pole: ";
    vypisPole(data, velikost);

    // Voláme quickSort pro celé pole (od indexu 0 do velikost - 1)
    quickSort(data, 0, velikost - 1);

    std::cout << "Serazene pole (Quick Sort): ";
    vypisPole(data, velikost);
    return 0;
}