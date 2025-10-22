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
 * @brief Implementace algoritmu Bubble Sort.
 */
void bubbleSort(int pole[], int velikost) {
    for (int i = 0; i < velikost - 1; i++) {
        bool prohozeno = false; // Optimalizace: pokud v průchodu nic neprohodíme, je hotovo
        for (int j = 0; j < velikost - i - 1; j++) {
            if (pole[j] > pole[j + 1]) {
                prohod(&pole[j], &pole[j + 1]);
                prohozeno = true;
            }
        }
        if (!prohozeno) {
            break; // Již seřazeno
        }
    }
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int velikost = sizeof(data) / sizeof(data[0]);

    std::cout << "Puvodni pole: ";
    vypisPole(data, velikost);
    bubbleSort(data, velikost);
    std::cout << "Serazene pole (Bubble Sort): ";
    vypisPole(data, velikost);
    return 0;
}