# 03 - Pokročilé C++

Tato sekce se věnuje pokročilým konceptům jazyka C++. Poté, co jsme v sekci [02 - Základy C++](../02-zaklady-cpp/README.md) zvládli syntaxi, proměnné, podmínky, cykly a funkce, se nyní ponoříme hlouběji do témat, která dělají C++ tak silným (a někdy i složitým) jazykem.

Zaměříme se na dvě klíčové oblasti:
1.  **Přímá správa paměti:** Naučíme se pracovat s ukazateli a dynamicky alokovat paměť. To nám umožní vytvářet efektivní a flexibilní datové struktury.
2.  **Objektově orientované programování (OOP):** Osvojíme si principy zapouzdření, dědičnosti a polymorfismu pro návrh modulárních a znovupoužitelných aplikací.

Nakonec se podíváme na moderní prvky C++, jako jsou šablony, výjimky a standardní knihovna (STL).

## Témata

| Pořadí | Téma | Popis |
| :--- | :--- | :--- |
| 01 | [Úvod do ukazatelů](./01-uvod-do-ukazatelu/) | Co je ukazatel, operátor adresy (`&`) a dereference (`*`), ukazatele a pole. |
| 02 | [Dynamická alokace paměti](./02-dynamicka-alokace-pameti/) | Stack vs. Heap, operátory `new` a `delete`/`delete[]`, alokace polí, úniky paměti (memory leaks). |
| 03 | [Ukazatele a funkce](./03-ukazatele-a-funkce/) | Rozdíl pass-by-value vs. pass-by-pointer, předávání polí (array decay), návrat ukazatele z funkce (včetně rizik). |
| 04 | [Dynamické datové struktury](./04-dynamicke-datove-sturktury/) | Úvod do spojových seznamů (implementace uzlu, vkládání, mazání, procházení). |
| 05 | `Úvod do OOP` | Principy (zapouzdření, dědičnost, polymorfismus), třídy a objekty. |
| 06 | `Konstruktory a destruktory` | Role konstruktoru, typy (defaultní, parametrický), přetěžování, destruktor. |
| 07 | `Dědičnost` | Odvozené třídy, překrývání metod, viditelnost (public, private, protected). |
| 08 | `Polymorfismus` | Virtuální metody, abstraktní třídy, dynamické vázání. |
| 09 | `Přetěžování operátorů` | Přetížení aritmetických, relačních a dalších operátorů pro vlastní třídy. |
| 10 | `Šablony (Templates)` | Funkční šablony, třídní šablony, obecné programování. |
| 11 | `Statické členy` | Statické atributy a metody, jejich využití. |
| 12 | `Výjimky (Exceptions)` | Zpracování chyb pomocí `try`, `catch` a `throw`. |
| 13 | `Úvod do STL` | Základní kontejnery (`vector`, `list`, `map`), iterátory a algoritmy. |