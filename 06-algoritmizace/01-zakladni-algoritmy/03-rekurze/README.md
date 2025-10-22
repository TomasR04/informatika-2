# 03 - Rekurze

Rekurze je programovací technika, při které **funkce volá sama sebe**, aby vyřešila menší část stejného problému. Je to alternativa k iteraci (cyklům) a pro mnoho algoritmů (Quick Sort, Merge Sort, prohledávání stromů) je to nejpřirozenější způsob implementace.

Každá rekurzivní funkce musí mít dvě klíčové části:

1.  **Základní případ (Base Case):** Podmínka, která rekurzi **ukončí**. Bez ní by funkce volala sama sebe donekonečna a program by spadl (chyba "Stack Overflow" - přetečení zásobníku).
2.  **Rekurzivní krok (Recursive Step):** Místo, kde funkce volá sama sebe, ale s "menším" nebo "jednodušším" vstupem, který se postupně **blíží základnímu případu**.

## Příklad 1: Faktoriál

Matematická definice faktoriálu ($n!$) je přirozeně rekurzivní:
* $0! = 1$ **(Základní případ)**
* $n! = n \cdot (n-1)!$ **(Rekurzivní krok)**

Volání `faktorial(4)` se rozpadne takto:
1.  `faktorial(4)` -> 4 * `faktorial(3)`
2.  `faktorial(3)` -> 3 * `faktorial(2)`
3.  `faktorial(2)` -> 2 * `faktorial(1)`
4.  `faktorial(1)` -> 1 * `faktorial(0)`
5.  `faktorial(0)` -> vrátí 1 (Base Case)
6.  Zpětné násobení: 1 * 1 * 2 * 3 * 4 = 24

## Příklad 2: Fibonacciho posloupnost

Čísla v posloupnosti, kde každé další číslo je součtem dvou předchozích: 0, 1, 1, 2, 3, 5, 8, 13, ...

* $fib(0) = 0$ **(Základní případ 1)**
* $fib(1) = 1$ **(Základní případ 2)**
* $fib(n) = fib(n-1) + fib(n-2)$ **(Rekurzivní krok)**

Tato implementace je sice elegantní, ale **extrémně neefektivní** (exponenciální složitost), protože stejné hodnoty počítá mnohokrát dokola. Je to ale perfektní ukázka rekurzivního myšlení.