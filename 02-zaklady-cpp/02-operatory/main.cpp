#include <iostream> // Pro vstup a vystup
#include <iomanip> // Pro použití std::boolalpha, které vypisuje 'true'/'false' místo 1/0

int main() {
    int a = 10;
    int b = 3;
    double c = 10.0;
    double d = 3.0;

    std::cout << "--- 1. Aritmeticke operatory ---" << std::endl;
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << "Celočíselné dělení: " << a << " / " << b << " = " << (a / b) << std::endl;
    std::cout << "Desetinné dělení: " << c << " / " << d << " = " << (c / d) << std::endl;
    std::cout << "Modulo (zbytek po deleni): " << a << " % " << b << " = " << (a % b) << std::endl;

    // Inkrementace a dekrementace
    int pocitadlo = 5;
    std::cout << "Pocitadlo: " << pocitadlo << std::endl;
    pocitadlo++; // Zvýšení o 1
    std::cout << "Po inkrementaci (++): " << pocitadlo << std::endl;
    pocitadlo--; // Snížení o 1
    std::cout << "Po dekrementaci (--): " << pocitadlo << std::endl;

    std::cout << "\n--- 2. Prirazovaci operatory ---" << std::endl;
    int x = 100;
    std::cout << "Pocatecni hodnota x = " << x << std::endl;
    x += 20; // x = x + 20
    std::cout << "Po x += 20; x = " << x << std::endl;
    x -= 50; // x = x - 50
    std::cout << "Po x -= 50; x = " << x << std::endl;
    x *= 2;  // x = x * 2
    std::cout << "Po x *= 2; x = " << x << std::endl;
    x /= 4;  // x = x / 4
    std::cout << "Po x /= 4; x = " << x << std::endl;

    std::cout << "\n--- 3. Relacni (porovnavaci) operatory ---" << std::endl;
    // std::boolalpha zajistí výpis 'true' nebo 'false' místo '1' nebo '0'
    std::cout << std::boolalpha;
    int val1 = 5;
    int val2 = 8;
    std::cout << "val1 = 5, val2 = 8" << std::endl;
    std::cout << "val1 == val2 : " << (val1 == val2) << std::endl;
    std::cout << "val1 != val2 : " << (val1 != val2) << std::endl;
    std::cout << "val1 > val2  : " << (val1 > val2) << std::endl;
    std::cout << "val1 < val2  : " << (val1 < val2) << std::endl;
    std::cout << "val1 >= 5    : " << (val1 >= 5) << std::endl;
    std::cout << "val2 <= 8    : " << (val2 <= 8) << std::endl;

    std::cout << "\n--- 4. Logicke operatory ---" << std::endl;
    bool jePlnolety = true;
    bool maVstupenku = false;
    bool jeVIP = true;
    std::cout << "Je plnolety: " << jePlnolety << ", ma vstupenku: " << maVstupenku << ", je VIP: " << jeVIP << std::endl;

    // Logický AND (&&) - platí, jen pokud platí obě podmínky
    std::cout << "Muze vstoupit na party (plnolety && ma vstupenku): "
              << (jePlnolety && maVstupenku) << std::endl;

    // Logický OR (||) - platí, pokud platí alespoň jedna podmínka
    std::cout << "Muze vstoupit do VIP zony (ma vstupenku || jeVIP): "
              << (maVstupenku || jeVIP) << std::endl;
    
    // Logická negace (!) - obrací hodnotu
    std::cout << "Neni plnolety (!jePlnolety): " << (!jePlnolety) << std::endl;

    std::cout << "\n--- 5. Priorita operatoru ---" << std::endl;
    int vysledek1 = 5 + 10 * 2; // Násobení má přednost
    int vysledek2 = (5 + 10) * 2; // Závorky mění prioritu
    std::cout << "5 + 10 * 2 = " << vysledek1 << std::endl;
    std::cout << "(5 + 10) * 2 = " << vysledek2 << std::endl;

    return 0;
}
