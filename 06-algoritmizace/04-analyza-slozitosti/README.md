# 04 - Analýza složitosti (Notace Big O)

Když píšeme program, nestačí, aby pouze "fungoval". Chceme také, aby byl **efektivní**. Analýza složitosti je způsob, jak měřit a popisovat, jak efektivní je náš kód, zejména jak se jeho výkon mění s rostoucím množstvím dat, která musí zpracovat.

K popisu této efektivity používáme notaci **Big O (Velké O)**.

## Co je notace Big O?

Notace Big O popisuje **růstovou tendenci** (growth rate) algoritmu. Neříká nám přesný čas v sekundách (to závisí na hardwaru, jazyku atd.), ale říká nám, jak se doba běhu (časová složitost) nebo využití paměti (prostorová složitost) změní, když se zvětší vstupní data (označovaná jako `n`).

Zaměřuje se na **nejhorší možný scénář (worst-case scenario)** a zjednodušuje chování tím, že ignoruje konstanty a méně významné členy.

  * Například algoritmus, který provede `5n + 10` operací, má složitost `O(n)`.
  * Algoritmus, který provede `2n^2 + 4n + 3` operací, má složitost `O(n^2)`.

Proč? Protože když je `n` velmi velké (např. 1 000 000), číslo `n^2` je tak obrovské, že ostatní části (`4n + 3`) jsou ve srovnání s ním zanedbatelné.

## Běžné časové složitosti

Zde jsou nejběžnější typy složitosti, seřazené od nejlepší (nejrychlejší) po nejhorší (nejpomalejší).

### O(1) - Konstantní složitost

Doba běhu je vždy stejná, bez ohledu na velikost vstupu (`n`).

  * **Příklad:** Přístup k prvku v poli pomocí indexu.
    ```cpp
    int prvek = pole[5]; // Vždy trvá stejně, ať má pole 10 nebo 10 milionů prvků
    ```

### O(log n) - Logaritmická složitost

Doba běhu roste velmi pomalu. Pokaždé, když zdvojnásobíme velikost vstupu, čas se zvýší jen o konstantní hodnotu. Typické pro algoritmy, které "půlí" problém.

  * **Analogie:** Hledání jména v telefonním seznamu. Otevřete ho uprostřed, zjistíte, zda je hledané jméno před nebo za, a zahodíte polovinu seznamu. Tento proces opakujete.
  * **Příklad:** Binární vyhledávání v seřazeném poli.

### O(n) - Lineární složitost

Doba běhu roste přímo úměrně velikosti vstupu. Pokud zdvojnásobíte `n`, zdvojnásobí se i čas.

  * **Analogie:** Hledání konkrétní stránky v knize tím, že ji listujete stránku po stránce od začátku.
  * **Příklad:** Procházení pole jedním cyklem, lineární vyhledávání.
    ```cpp
    int soucet = 0;
    for (int i = 0; i < n; i++) {
        soucet += pole[i];
    }
    ```

### O(n log n) - Lineárně-logaritmická složitost

Velmi efektivní složitost pro třídicí algoritmy. Je to "zlatý standard" pro třídění založené na porovnávání.

  * **Příklad:** Efektivní třídicí algoritmy jako Merge Sort nebo průměrný případ Quick Sortu.

### O(n²) - Kvadratická složitost

Doba běhu roste s druhou mocninou velikosti vstupu. Pokud zdvojnásobíte `n`, čas se zhruba zečtyřnásobí. Typické pro vnořené cykly, kde každý cyklus závisí na `n`.

  * **Analogie:** Porovnávání každé osoby v místnosti s každou další osobou.
  * **Příklad:** Jednoduché třídicí algoritmy jako Bubble Sort, Selection Sort nebo Insertion Sort.
    ```cpp
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // ... nějaká operace ...
        }
    }
    ```

### O(2ⁿ) - Exponenciální složitost

Algoritmus se stává extrémně pomalým i pro relativně malé hodnoty `n`. Často se vyskytuje u rekurzivních řešení, která řeší problém hrubou silou.

  * **Příklad:** Jednoduchá rekurzivní implementace Fibonacciho posloupnosti.

### O(n\!) - Faktoriální složitost

Nejhorší typ složitosti. Nejpomalejší ze všech. Doba běhu roste astronomicky rychle.

  * **Příklad:** Nalezení všech možných permutací seznamu, řešení problému obchodního cestujícího hrubou silou.

## Porovnání složitostí

Následující tabulka ukazuje, jak rychle roste počet operací pro různé složitosti v závislosti na počtu prvků `n`:

| Složitost | n = 10 | n = 20 | n = 100 |
| :--- | :--- | :--- | :--- |
| **O(1)** | 1 | 1 | 1 |
| **O(log n)** | \~3 | \~4 | \~7 |
| **O(n)** | 10 | 20 | 100 |
| **O(n log n)** | \~33 | \~86 | \~664 |
| **O(n²)** | 100 | 400 | 10 000 |
| **O(2ⁿ)** | 1 024 | \~1 milion | \~1.26 x 10³⁰ |
| **O(n\!)** | \~3.6 milionu | \~2.4 x 10¹⁸ | ...velmi velké číslo |

**Závěr:** Při návrhu algoritmu je klíčové snažit se o co nejnižší složitost (např. $O(n \log n)$ nebo $O(n)$) a vyhnout se, pokud je to možné, kvadratickým ($O(n^2)$) a zejména exponenciálním ($O(2^n)$) složitostem, které pro větší data "neškálují".