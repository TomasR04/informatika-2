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
 * @brief Implementace algoritmu Selection Sort.
 */
void selectionSort(int pole[], int velikost) {
    for (int i = 0; i < velikost - 1; i++) {
        // Najdeme index nejmenšího prvku ve zbývající části
        int min_idx = i;
        for (int j = i + 1; j < velikost; j++) {
            if (pole[j] < pole[min_idx]) {
                min_idx = j;
            }
        }
        // Prohodíme ho s prvním prvkem neseřazené části
        if (min_idx != i) {
             prohod(&pole[min_idx], &pole[i]);
        }
    }
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int velikost = sizeof(data) / sizeof(data[0]);

    std::cout << "Puvodni pole: ";
    vypisPole(data, velikost);
    selectionSort(data, velikost);
    std::cout << "Serazene pole (Selection Sort): ";
    vypisPole(data, velikost);
    return 0;
}