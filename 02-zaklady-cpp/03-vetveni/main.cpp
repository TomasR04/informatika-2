#include <iostream> // Pro vstup a vystup

int main() {
    // --- 1. Vetveni: if / else if / else ---
    std::cout << "--- 1. Vetveni: if / else if / else ---" << std::endl;
    int vek;
    std::cout << "Zadej svuj vek: ";
    std::cin >> vek;

    if (vek < 0) {
        std::cout << "Vek nemuze byt zaporny!" << std::endl;
    } else if (vek < 18) {
        std::cout << "Nejsi plnolety." << std::endl;
    } else if (vek == 18) {
        std::cout << "Gratuluji, prave jsi dosahl plnoletosti!" << std::endl;
    } else if (vek > 120) {
        std::cout << "To je neuveritelny vek!" << std::endl;
    } else {
        std::cout << "Jsi plnolety." << std::endl;
    }

    // --- 2. Vetveni: switch ---
    std::cout << "\n--- 2. Vetveni: switch ---" << std::endl;
    int den = 4;
    switch (den) {
        case 1:
            std::cout << "Pondeli" << std::endl;
            break;
        case 2:
            std::cout << "Utery" << std::endl;
            break;
        case 3:
            std::cout << "Streda" << std::endl;
            break;
        case 4:
            std::cout << "Ctvrtek" << std::endl;
            break;
        case 5:
            std::cout << "Patek" << std::endl;
            break;
        case 6:
        case 7: // Ukázka "propadávání" pro více hodnot
            std::cout << "Vikend" << std::endl;
            break;
        default:
            std::cout << "Neplatny den" << std::endl;
            break;
    }

    // --- 3. Zpracovani vyjimek: try-catch ---
    std::cout << "\n--- 3. Zpracovani vyjimek: try-catch ---" << std::endl;
    
    double delenec = 10.0;
    double delitel = 0.0;

    try {
        // Blok kódu, ve kterém může nastat chyba.
        std::cout << "Pokousim se delit cislem: " << delitel << std::endl;
        if (delitel == 0) {
            // Pokud nastane chyba (delitel je 0), "vyhodime" vyjimku.
            // Program okamzite preskoci do bloku catch.
            throw std::runtime_error("Chyba: Deleni nulou neni povoleno!");
        }
        
        // Tento kod se provede, jen pokud vyjimka nenastala.
        double vysledek = delenec / delitel;
        std::cout << "Vysledek je: " << vysledek << std::endl;

    } catch (const std::runtime_error& e) {
        // Tento blok "chyti" vyhozenou vyjimku a zpracuje ji.
        // Program nespadne, ale vypise chybovou hlasku.
        // std::cerr je proud pro chybovy vystup.
        std::cerr << "Operace se nezdarila. Duvod: " << e.what() << std::endl;
    }

    // --- 4. Vice catch bloku a obecne zachyceni chyby ---
    std::cout << "\n--- 4. Vice bloku catch a obecne zachyceni chyby ---" << std::endl;
    try {
        // Zde umyslne vyhodime vyjimku jineho typu - cele cislo.
        // To nebude zachyceno prvnim 'catch', ktery ocekava std::runtime_error.
        std::cout << "Vyhazuji vyjimku typu 'int'..." << std::endl;
        throw 42; 
    }
    catch (const std::runtime_error& e) {
        // Tento blok bude preskocen, protoze typ vyjimky neodpovida.
        std::cerr << "Zachycena std::runtime_error: " << e.what() << std::endl;
    }
    catch (...) {
        // Blok se tremi teckami (...) zachyti JAKOUKOLIV vyjimku,
        // ktera nebyla zachycena predchozimi 'catch' bloky.
        // Je to "posledni zachrana", ale nezname typ ani obsah chyby.
        std::cerr << "Zachycena neznamy typ vyjimky!" << std::endl;
    }

    std::cout << "Program pokracuje dal i po zachyceni chyby..." << std::endl;

    return 0;
}

