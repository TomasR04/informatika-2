#include <iostream>

/**
 * @brief Spočítá faktoriál čísla 'n' pomocí rekurze.
 */
long long factorial(int n) {
    // 1. Základní případ (Base Case)
    // Faktoriál 0 (a pro jistotu i 1) je 1.
    if (n <= 1) {
        return 1;
    }
    // 2. Rekurzivní krok
    // n! = n * (n-1)!
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int cislo = 5;
    std::cout << "Faktorial z " << cislo << " je: " << factorial(cislo) << std::endl; // 120

    cislo = 0;
    std::cout << "Faktorial z " << cislo << " je: " << factorial(cislo) << std::endl; // 1

    cislo = 10;
    std::cout << "Faktorial z " << cislo << " je: " << factorial(cislo) << std::endl; // 3628800

    return 0;
}