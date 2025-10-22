#include <iostream>

void vypisPole(int pole[], int velikost) {
    for (int i = 0; i < velikost; i++) {
        std::cout << pole[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Implementace algoritmu Insertion Sort.
 */
void insertionSort(int pole[], int velikost) {
    // Začínáme od druhého prvku (index 1)
    for (int i = 1; i < velikost; i++) {
        int klic = pole[i]; // Prvek, který chceme zařadit
        int j = i - 1;

        // Posouváme prvky v seřazené části, které jsou větší než klíč,
        // doprava, abychom uvolnili místo.
        while (j >= 0 && pole[j] > klic) {
            pole[j + 1] = pole[j];
            j = j - 1;
        }
        // Vložíme klíč na správné volné místo
        pole[j + 1] = klic;
    }
}

int main() {
    int data[] = {12, 11, 13, 5, 6};
    int velikost = sizeof(data) / sizeof(data[0]);

    std::cout << "Puvodni pole: ";
    vypisPole(data, velikost);
    insertionSort(data, velikost);
    std::cout << "Serazene pole (Insertion Sort): ";
    vypisPole(data, velikost);
    return 0;
}