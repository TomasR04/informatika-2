#include <iostream>
#include <string>

// 1. Definice struktury
// Definuje nový datový typ 'Student'.
struct Student {
    std::string jmeno;
    std::string prijmeni;
    int id;
    double prumer;
};

// 2. Funkce, která přijímá strukturu HODNOTOU (by value)
// Vytvoří se kopie celé struktury 's'.
void vypisStudenta(Student s) {
    std::cout << "--- Informace o studentovi (kopie) ---" << std::endl;
    std::cout << "ID:      " << s.id << std::endl;
    std::cout << "Jméno:   " << s.jmeno << " " << s.prijmeni << std::endl;
    std::cout << "Průměr:  " << s.prumer << std::endl;
    
    // Změna v této funkci ovlivní pouze lokální kopii
    s.jmeno = "ZMENENO";
    std::cout << "Jméno uvnitř funkce: " << s.jmeno << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

// 3. Funkce, která přijímá strukturu REFERENCÍ (by reference)
// Pracuje přímo s originálem. Je to efektivnější (nekopíruje se)
// a umožňuje měnit původní data.
void zmenPrumer(Student& s, double novyPrumer) {
    std::cout << "\nZmena prumeru (reference)..." << std::endl;
    s.prumer = novyPrumer;
}

// 4. Funkce, která přijímá strukturu UKAZATELEM (by pointer)
// Toto je základ pro dynamické datové struktury (spojové seznamy atd.)
// Místo tečky '.' se pro přístup ke členům používá šipka '->'
void zmenId(Student* pStudent, int noveId) {
    std::cout << "\nZmena ID (ukazatel)..." << std::endl;
    if (pStudent != nullptr) { // Vždy je dobré kontrolovat, zda ukazatel není null
        pStudent->id = noveId;
        // Ekvivalentní (ale méně čitelný) zápis:
        // (*pStudent).id = noveId;
    }
}


int main() {
    // Vytvoření instance (proměnné) typu Student
    Student s1;
    
    // Přístup ke členům a jejich nastavení pomocí tečkové notace
    s1.jmeno = "Petr";
    s1.prijmeni = "Vesely";
    s1.id = 101;
    s1.prumer = 2.1;

    // Předání hodnotou (funkce dostane kopii)
    vypisStudenta(s1);
    std::cout << "Jmeno v main() po volani funkce: " << s1.jmeno << " (zustalo puvodni)" << std::endl;

    // Předání referencí (funkce mění originál)
    zmenPrumer(s1, 1.8);
    std::cout << "Novy prumer v main(): " << s1.prumer << std::endl;

    // Předání ukazatelem (funkce také mění originál)
    zmenId(&s1, 102); // Funkci předáme ADRESU proměnné s1
    std::cout << "Nove ID v main(): " << s1.id << std::endl;
    
    std::cout << "\n--- Finalni stav s1 ---" << std::endl;
    vypisStudenta(s1);

    return 0;
}
