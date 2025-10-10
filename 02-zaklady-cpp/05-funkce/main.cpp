#include <iostream>
#include <string>

// --- Deklarace funkci (prototypy) ---
// Deklarace umožňují volat funkce ještě před jejich definicí v kódu.
// Kompilátor díky nim ví, jaké mají parametry a návratový typ.

// 1. Funkce bez parametru a bez navratove hodnoty
void pozdrav();

// 2. Funkce s parametry, ale bez navratove hodnoty
void predstavSe(std::string jmeno, int vek);

// 3. Funkce s parametry a s navratovou hodnotou
int secti(int a, int b);

// 4. Pretizena funkce 'secti' pro desetina cisla
double secti(double a, double b);

// 5. Rekurzivni funkce pro vypocet faktorialu
long long faktorial(int n);


// --- Hlavni funkce programu ---
int main() {
    std::cout << "--- 1. Volani funkce bez parametru ---" << std::endl;
    pozdrav(); // Jednoduche zavolani funkce

    std::cout << "\n--- 2. Volani funkce s parametry ---" << std::endl;
    predstavSe("Tomas", 30); // Predame hodnoty jako argumenty

    std::cout << "\n--- 3. Volani funkce s navratovou hodnotou ---" << std::endl;
    int cislo1 = 15;
    int cislo2 = 7;
    // Návratovou hodnotu z funkce si ulozime do promenne 'vysledek'
    int vysledek = secti(cislo1, cislo2);
    std::cout << "Soucet cisel " << cislo1 << " a " << cislo2 << " je: " << vysledek << std::endl;
    // Funkci muzeme volat i primo ve vypisu
    std::cout << "Soucet cisel 100 a 200 je: " << secti(100, 200) << std::endl;

    std::cout << "\n--- 4. Pretizeni funkci (Function Overloading) ---" << std::endl;
    // Kompilator si sam vybere spravnou verzi funkce podle typu argumentu
    std::cout << "Volam secti(5, 10): " << secti(5, 10) << std::endl;
    std::cout << "Volam secti(3.14, 2.71): " << secti(3.14, 2.71) << std::endl;
    
    std::cout << "\n--- 5. Rekurzivni funkce ---" << std::endl;
    int n = 5;
    std::cout << "Faktorial cisla " << n << " je: " << faktorial(n) << std::endl;


    return 0; // Konec programu
}


// --- Definice funkci ---
// Zde je implementace (tělo) funkcí, které byly deklarovány výše.

void pozdrav() {
    std::cout << "Ahoj, vitej ve svete funkci!" << std::endl;
}

void predstavSe(std::string jmeno, int vek) {
    std::cout << "Jmenuji se " << jmeno << " a je mi " << vek << " let." << std::endl;
}

int secti(int a, int b) {
    return a + b; // Klicove slovo 'return' vrati vysledek vypoctu
}

double secti(double a, double b) {
    return a + b;
}

long long faktorial(int n) {
    // Rekurzivní funkce volá sama sebe
    // Musí mít ukončovací podmínku, aby nedošlo k nekonečné smyčce
    if (n <= 1) {
        return 1; // Ukoncovaci podminka: faktorial z 0 nebo 1 je 1
    } else {
        return n * faktorial(n - 1); // Rekurzivni volani
    }
}

