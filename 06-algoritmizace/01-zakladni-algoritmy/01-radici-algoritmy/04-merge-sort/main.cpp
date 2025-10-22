#include <iostream>

void vypisPole(int pole[], int velikost) {
    for (int i = 0; i < velikost; i++) {
        std::cout << pole[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Pomocná funkce pro slévání (merge) dvou seřazených podpolí.
 * První podpole je pole[left...middle]
 * Druhé podpole je pole[middle+1...right]
 */
void merge(int pole[], int left, int middle, int right) {
    int velikostL = middle - left + 1;
    int velikostP = right - middle;

    // Vytvoříme dočasná pole pro kopie
    // V reálné C++ aplikaci bychom použili std::vector
    // Zde alokujeme na zásobníku (rizikové pro velká pole)
    // Pro velká pole by byl nutný 'new int[]' a 'delete[]'
    int L[velikostL];
    int P[velikostP];

    // Zkopírujeme data do dočasných polí
    for (int i = 0; i < velikostL; i++)
        L[i] = pole[left + i];
    for (int j = 0; j < velikostP; j++)
        P[j] = pole[middle + 1 + j];

    // Indexy pro slévání
    int i = 0; // Index pro levé pole
    int j = 0; // Index pro pravé pole
    int k = left; // Index pro hlavní (slévané) pole

    // Slévání zpět do pole[]
    while (i < velikostL && j < velikostP) {
        if (L[i] <= P[j]) {
            pole[k] = L[i];
            i++;
        } else {
            pole[k] = P[j];
            j++;
        }
        k++;
    }

    // Zkopírování zbývajících prvků z L[], pokud nějaké zbyly
    while (i < velikostL) {
        pole[k] = L[i];
        i++;
        k++;
    }

    // Zkopírování zbývajících prvků z P[], pokud nějaké zbyly
    while (j < velikostP) {
        pole[k] = P[j];
        j++;
        k++;
    }
}

/**
 * @brief Hlavní funkce algoritmu Merge Sort (rekurzivní).
 */
void mergeSort(int pole[], int left, int right) {
    if (left < right) {
        // Najdeme střed
        int middle = left + (right - left) / 2;

        // 1. Rozděl: Rekurzivně seřadíme obě poloviny
        mergeSort(pole, left, middle);
        mergeSort(pole, middle + 1, right);

        // 2. Panuj: Sloučíme (merge) seřazené poloviny
        merge(pole, left, middle, right);
    }
}

int main() {
    int data[] = {12, 11, 13, 5, 6, 7};
    int velikost = sizeof(data) / sizeof(data[0]);

    std::cout << "Puvodni pole: ";
    vypisPole(data, velikost);
    
    // Voláme mergeSort pro celé pole (od indexu 0 do velikost - 1)
    mergeSort(data, 0, velikost - 1);
    
    std::cout << "Serazene pole (Merge Sort): ";
    vypisPole(data, velikost);
    return 0;
}