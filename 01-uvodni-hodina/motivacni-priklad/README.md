# **Motivační Příklad: Advent of Code**

Tento příklad demonstruje řešení jednoduché algoritmické úlohy v C++ a Pythonu. Cílem je ukázat rozdíly v syntaxi a přístupu a zároveň vás seznámit s **Advent of Code** a jednoduchostí spouštění kódu v našem připraveném vývojovém prostředí.

## **Co je Advent of Code?**

[Advent of Code](https://adventofcode.com/) je každoroční programátorská soutěž ve formě adventního kalendáře. Každý den od 1\. do 25\. prosince je zveřejněna nová, malá programátorská hádanka, která se skládá ze dvou částí. Je to skvělý způsob, jak si zábavnou formou procvičit algoritmické myšlení, naučit se nový jazyk nebo si zdokonalit ten stávající.

V prosinci budeme některé z těchto úloh řešit společně v rámci výuky a můžete za ně získat i bonusové body.

## [**Zadání (AoC 2023, Den 1\)**](https://adventofcode.com/2023/day/1)

Máme textový soubor input.txt. Na každém řádku je text, který obsahuje nějaké číslice. Naším úkolem je z každého řádku získat **první a poslední číslici**, spojit je do dvouciferného čísla a nakonec sečíst všechna tato dvouciferná čísla dohromady.

**Příklad souboru input.txt:**
```txt
1abc2  
pqr3stu8vwx  
a1b2c3d4e5f  
treb7uchet
```

**Logika zpracování:**

* 1abc2 \-\> první číslice je 1, poslední 2 \-\> 12  
* pqr3stu8vwx \-\> první číslice je 3, poslední 8 \-\> 38  
* a1b2c3d4e5f \-\> první číslice je 1, poslední 5 \-\> 15  
* treb7uchet \-\> první 7, poslední také 7 \-\> 77

**Výsledný součet:** 12 \+ 38 \+ 15 \+ 77 \= 142

## **Řešení v C++**

V C++ musíme explicitně iterovat přes řetězce, abychom našli číslice.

**Kód (day1.cpp):**

```cpp
#include <iostream>  
#include <fstream>  
#include <string>  
#include <vector>  
#include <cctype>

int main() {  
    std::ifstream soubor("input.txt");  
    if (!soubor.is_open()) {  
        std::cerr << "Chyba: Soubor 'input.txt' se nepodarilo otevrit." << std::endl;  
        return 1;  
    }

    int celkovy_soucet = 0;  
    std::string radek;

    while (std::getline(soubor, radek)) {  
        char prvni_cislice = '0';  
        char posledni_cislice = '0';

        // Najdi prvni cislici  
        for (char znak : radek) {  
            if (isdigit(znak)) {  
                prvni_cislice = znak;  
                break;  
            }  
        }

        // Najdi posledni cislici (iterace od konce)  
        for (int i = radek.length() - 1; i >= 0; --i) {  
            if (isdigit(radek[i])) {  
                posledni_cislice = radek[i];  
                break;  
            }  
        }

        if (prvni_cislice != '0') {  
            int hodnota = (prvni_cislice - '0') * 10 + (posledni_cislice - '0');  
            celkovy_soucet += hodnota;  
        }  
    }

    soubor.close();  
    std::cout << "Celkovy soucet v C++ je: " << celkovy_soucet << std::endl;

    return 0;  
}
```

**Kompilace a spuštění (v terminálu Dev Containeru):**

Nejjednodušší způsob je přímo ve VS Code:
1. Otevřete soubor day1.cpp.
2. Klikněte na ikonu "Play" v pravém horním rohu editoru. Tím se kód zkompiluje a spustí.

Alternativně můžete použít terminál:

```bash
g++ day1.cpp -o day1_cpp
./day1_cpp
```

**Výstup:**

```bash
Celkovy soucet v C++ je: 142
```

**Komentář:** Řešení v C++ je velmi explicitní. Ukazuje manuální práci se soubory, iteraci přes znaky a konverzi znaků na čísla. Je to rychlé, ale vyžaduje více řádků kódu.

## **Řešení v Pythonu**

Python umožňuje elegantnější a kratší řešení díky svým vestavěným funkcím pro práci s textem.

**Kód (day1.py):**

```python
from os.path import join, dirname, realpath

def main():  
    try:  
        with open(join(dirname(realpath(__file__)), "input.txt"), "r", encoding="utf_8") as soubor:  
            celkovy_soucet = 0  
            for radek in soubor:  
                cislice = [znak for znak in radek if znak.isdigit()]  
                  
                if cislice:  
                    hodnota = int(cislice[0] + cislice[-1])  
                    celkovy_soucet += hodnota  
              
            print(f"Celkovy soucet v Pythonu je: {celkovy_soucet}")

    except FileNotFoundError:  
        print("Chyba: Soubor 'input.txt' nebyl nalezen.")

if __name__ == "__main__":  
    main()
```

**Spuštění (v terminálu Dev Containeru):**

Nejjednodušší způsob je přímo ve VS Code:
1. Otevřete soubor day1.py.
2. Klikněte na ikonu "Play" v pravém horním rohu editoru.

Alternativně můžete použít terminál:

```bash
python3 day1.py
```

**Výstup:**

```bash
Celkovy soucet v Pythonu je: 142
```

**Komentář:** Python řešení je stručnější. "List comprehension" [znak for znak in radek if znak.isdigit()] efektivně vyfiltruje všechny číslice z řádku do seznamu, ze kterého pak snadno vezmeme první a poslední prvek.

## **Závěr**

Tento příklad dobře ilustruje filozofii obou jazyků a jednoduchost práce v Dev Containeru:

* **C++** vám dává plnou kontrolu a výkon, ale vyžaduje detailnější zápis.  
* **Python** se soustředí na rychlost vývoje a čitelnost, přičemž mnoho detailů schovává do vysokoúrovňových funkcí.  
* Díky připravenému **Dev Containeru** můžete snadno kompilovat C++ kód (g++) i spouštět Python skripty (python3) ve stejném terminálu bez nutnosti cokoliv instalovat na váš lokální počítač.