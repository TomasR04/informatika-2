#include <iostream> // Pro vstup a vystup
#include <string> // Pro použití datového typu string.
#include <limits> // Pro zjištění minimálních a maximálních hodnot datových typů.

int main() {
    // Nastavení české lokalizace pro správné zobrazení diakritiky v konzoli (může záviset na systému)
    // setlocale(LC_ALL, "cs_CZ.UTF-8");

    std::cout << "--- PREHLED DATOVYCH TYPU, VELIKOSTI A LIMITU ---" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    // --- CELOCISELNE TYPY (INTEGERS) ---
    std::cout << "Celociselne typy:" << std::endl;

    // short (2 bajty)
    std::cout << "  short: " << sizeof(short) << " bajty, rozsah od "
              << std::numeric_limits<short>::min() << " do "
              << std::numeric_limits<short>::max() << std::endl;

    // unsigned short (2 bajty)
    std::cout << "  unsigned short: " << sizeof(unsigned short) << " bajty, rozsah od "
              << std::numeric_limits<unsigned short>::min() << " do "
              << std::numeric_limits<unsigned short>::max() << std::endl;

    // int (typicky 4 bajty)
    std::cout << "  int: " << sizeof(int) << " bajty, rozsah od "
              << std::numeric_limits<int>::min() << " do "
              << std::numeric_limits<int>::max() << std::endl;

    // unsigned int (typicky 4 bajty)
    std::cout << "  unsigned int: " << sizeof(unsigned int) << " bajty, rozsah od "
              << std::numeric_limits<unsigned int>::min() << " do "
              << std::numeric_limits<unsigned int>::max() << std::endl;

    // long long (8 bajtů)
    std::cout << "  long long: " << sizeof(long long) << " bajtu, rozsah od "
              << std::numeric_limits<long long>::min() << " do "
              << std::numeric_limits<long long>::max() << std::endl;

    // unsigned long long (8 bajtů)
    std::cout << "  unsigned long long: " << sizeof(unsigned long long) << " bajtu, rozsah od "
              << std::numeric_limits<unsigned long long>::min() << " do "
              << std::numeric_limits<unsigned long long>::max() << std::endl;

    std::cout << "------------------------------------------------" << std::endl;


    // --- DESETINNE TYPY (FLOATING-POINT) ---
    std::cout << "Desetinne typy:" << std::endl;

    // float (4 bajty) - menší přesnost
    float cena = 19.99f; // 'f' na konci říká, že jde o float literál
    std::cout << "  float: " << sizeof(float) << " bajty, priklad: " << cena << std::endl;
    std::cout << "    rozsah od " << std::numeric_limits<float>::lowest()
              << " do " << std::numeric_limits<float>::max() << std::endl;


    // double (8 bajtů) - větší (standardní) přesnost
    double pi = 3.1415926535;
    std::cout << "  double: " << sizeof(double) << " bajtu, priklad: " << pi << std::endl;
    std::cout << "    rozsah od " << std::numeric_limits<double>::lowest()
              << " do " << std::numeric_limits<double>::max() << std::endl;

    std::cout << "------------------------------------------------" << std::endl;

    // --- OSTATNI ZAKLADNI TYPY ---
    std::cout << "Ostatni zakladni typy:" << std::endl;

    // char (1 bajt)
    char pismeno = 'A';
    std::cout << "  char: " << sizeof(char) << " bajt, priklad: " << pismeno << std::endl;
    
    // bool (1 bajt)
    bool jePravda = true;
    std::cout << "  bool: " << sizeof(bool) << " bajt, priklad: " << jePravda << " (true)" << std::endl;

    // std::string (velikost je variabilní)
    std::string pozdrav = "Ahoj svete!";
    std::cout << "  string: velikost objektu je " << sizeof(std::string) << " bajtu, ale text samotny je jinde v pameti." << std::endl;
    std::cout << "    priklad: " << pozdrav << std::endl;
    
    std::cout << "------------------------------------------------" << std::endl;

    // Návratová hodnota 0 značí, že program proběhl úspěšně.
    return 0;
}