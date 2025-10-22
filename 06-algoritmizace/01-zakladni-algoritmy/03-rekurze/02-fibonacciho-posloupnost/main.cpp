#include <iostream>

/**
 * @brief Najde n-tý prvek Fibonacciho posloupnosti pomocí rekurze.
 */
int fibonacci(int n) {
    // 1. Základní případ (Base Case 1)
    if (n == 0) {
        return 0;
    }
    // 1. Základní případ (Base Case 2)
    if (n == 1) {
        return 1;
    }
    // 2. Rekurzivní krok
    // fib(n) = fib(n-1) + fib(n-2)
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 10;
    std::cout << "Prvnich " << n << " clenu Fibonacciho posloupnosti:" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;
    // Výstup: 0 1 1 2 3 5 8 13 21 34

    // Upozornění: Pro větší čísla (cca > 40) bude tento výpočet
    // kvůli své neefektivitě trvat VELMI dlouho.
    
    // int velke_n = 45;
    // std::cout << velke_n << "-ty clen je: " << fibonacci(velke_n) << std::endl; // Trvá...

    return 0;
}