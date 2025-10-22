# 02 - Vyhledávací algoritmy

Jak najít hodnotu v kolekci dat? Efektivita hledání kriticky závisí na tom, zda jsou data seřazená.

## 2.1 Lineární vyhledávání: Složitost $O(n)$

Nejjednodušší způsob. Prostě projdeme celé pole prvek po prvku od začátku do konce a porovnáme každý prvek s hledanou hodnotou.

* **Výhoda:** Funguje na jakýchkoliv (i neseřazených) datech.
* **Nevýhoda:** V nejhorším případě (když prvek v poli není) musíme projít celé pole. Pro 1 miliardu prvků provedeme 1 miliardu porovnání.
* **Návratová hodnota:** Typicky vrací *index* nalezeného prvku, nebo speciální hodnotu (např. `-1`), pokud prvek nebyl nalezen.

## 2.2 Binární vyhledávání: Složitost $O(\log n)$

Extrémně efektivní algoritmus, který má ale jednu klíčovou **podmínku: data musí být seřazená.**

Princip "půlení intervalu":
1.  Vezmeme seřazené pole a nastavíme hranice `left = 0` a `right = velikost - 1`.
2.  Podíváme se na prvek uprostřed intervalu (`middle = (left + right) / 2`).
3.  **Shoda:** Pokud je `pole[middle]` prvek, který hledáme, máme hotovo (vrátíme `middle`).
4.  **Hledaný prvek je menší:** Pokud je náš cíl *menší* než `pole[middle]`, víme jistě, že musí být v levé polovině. Zahodíme pravou polovinu posunutím hranice: `right = middle - 1`.
5.  **Hledaný prvek je větší:** Pokud je náš cíl *větší* než `pole[middle]`, musí být v pravé polovině. Zahodíme levou polovinu: `left = middle + 1`.
6.  Opakujeme kroky 2-5, dokud `left <= right`. Pokud se intervaly překříží (`left > right`), prvek v poli není (vrátíme `-1`).

* **Výhoda:** Neuvěřitelně rychlé. Pro 1 miliardu prvků provedeme maximálně $\approx 30$ porovnání.
* **Nevýhoda:** Vyžaduje seřazená data.