# 02 - Dynamická alokace paměti

Dosud jsme pracovali s proměnnými a poli, jejichž velikost byla pevně daná v době kompilace. Kam se tyto proměnné ukládají a jak funguje správa paměti v typickém C++ programu? Existují dvě hlavní oblasti paměti, které náš program využívá: **Zásobník (Stack)** a **Halda (Heap)**.

## **Zásobník (Stack)**

* **Co to je:** Oblast paměti, která funguje na principu LIFO (Last-In, First-Out) – jako hromádka talířů. Když zavoláte funkci, na vrchol zásobníku se "položí" její data (lokální proměnné, parametry, návratová adresa). Když funkce skončí, její data se ze zásobníku "odstraní".
* **Použití:** Lokální proměnné (deklarované uvnitř funkcí nebo bloků `{}`), parametry funkcí.
* **Správa:** **Automatická.** Kompilátor přesně ví, kdy proměnná vzniká a kdy zaniká, a zařídí uvolnění paměti.
* **Rychlost:** Alokace a dealokace je **velmi rychlá** (jde v podstatě jen o posun ukazatele na vrchol zásobníku).
* **Velikost:** **Omezená** (typicky v řádu jednotek megabajtů). Pokud se pokusíte na zásobník uložit příliš mnoho dat (např. obrovské lokální pole nebo příliš hluboká rekurze), dojde k **přetečení zásobníku (Stack Overflow)** a pádu programu.
* **Příklad:**
    ```cpp
    void mojeFunkce() {
        int x = 10;          // 'x' je na zásobníku
        char buffer[100];    // 'buffer' je na zásobníku
    } // Na konci funkce se paměť pro 'x' a 'buffer' automaticky uvolní
    ```

## **Halda (Heap)**

* **Co to je:** Velká, méně organizovaná oblast paměti, kterou má program k dispozici pro data, jejichž životnost nebo velikost není známa v době kompilace.
* **Použití:** Data, která potřebujeme vytvořit za běhu programu (např. pole, jehož velikost zadá uživatel), nebo data, která mají existovat déle než funkce, ve které byla vytvořena.
* **Správa:** **Manuální!** Programátor musí explicitně požádat o paměť pomocí operátoru `new` a **musí ji také explicitně uvolnit** pomocí operátoru `delete` nebo `delete[]`.
* **Rychlost:** Alokace a dealokace je **pomalejší** než na zásobníku. Systém musí najít dostatečně velký volný blok paměti.
* **Velikost:** **Velká**, omezena prakticky jen dostupnou operační pamětí (RAM) a limity operačního systému.
* **Fragmentace:** Opakovanou alokací a dealokací různě velkých bloků může dojít k fragmentaci haldy (vznikne mnoho malých volných mezer, které nelze využít pro větší alokaci).
* **Příklad:**
    ```cpp
    int* pDynamickeCislo = new int; // Alokuje místo pro int na haldě
    // ... práce s *pDynamickeCislo ...
    delete pDynamickeCislo;        // Manuální uvolnění paměti
    ```

## **Operátory `new` a `delete`**

C++ poskytuje dva klíčové operátory pro manuální správu paměti na haldě:

### **`new` – Alokace paměti**

Operátor `new` požádá operační systém o blok paměti na haldě o velikosti potřebné pro daný datový typ. Pokud je alokace úspěšná, `new` vrátí **ukazatel** na začátek alokovaného bloku. Pokud se alokace nezdaří (nedostatek paměti), `new` standardně vyhodí výjimku (`std::bad_alloc`).

```cpp
// Alokace jednoho celého čísla na haldě
int* pInt = new int;
*pInt = 10; // Uložíme hodnotu do alokované paměti

// Alokace jednoho čísla s inicializací
double* pDouble = new double(3.14);

// Alokace pole 50 celých čísel na haldě
int velikost = 50;
int* pPole = new int[velikost];
pPole[0] = 1; // Práce s dynamickým polem je stejná jako se statickým
pPole[49] = 100;
```

### **`delete` – Uvolnění paměti**

Jakmile paměť alokovanou pomocí `new` již nepotřebujeme, **MUSÍME** ji uvolnit pomocí operátoru `delete` (pro jednotlivé proměnné) nebo `delete[]` (pro pole). Tím řekneme systému, že tuto paměť může znovu použít.

```cpp
// Uvolnění paměti pro jedno číslo
delete pInt;
pInt = nullptr; // Dobrá praxe: Nastavit ukazatel na nullptr po delete

delete pDouble;
pDouble = nullptr;

// Uvolnění paměti pro pole
delete[] pPole;
pPole = nullptr;
```

**Kriticky důležité:**

  * Na každý `new` musí existovat právě jeden odpovídající `delete`.
  * Na každý `new typ[]` musí existovat právě jeden odpovídající `delete[]`.
  * **Nikdy** nepoužívejte `delete` na paměť, která nebyla alokována pomocí `new`.
  * **Nikdy** nepoužívejte `delete` na stejnou paměť dvakrát.
  * **Nikdy** nepoužívejte paměť *po* jejím uvolnění (`delete`).

## **Úniky paměti (Memory Leaks)**

Pokud alokujeme paměť pomocí `new` a **zapomeneme** ji uvolnit pomocí `delete`/`delete[]`, tato paměť zůstane obsazená, i když k ní už nemáme přístup (např. ztratíme ukazatel). Tomuto se říká **únik paměti (memory leak)**.

Opakované úniky paměti mohou vést k tomu, že program spotřebuje veškerou dostupnou paměť a spadne, nebo zpomalí celý systém.

```cpp
void funkceSUnikem() {
    int* pData = new int[1000];
    // ... nějaká práce s pData ...
    // CHYBA: Chybí delete[] pData;
} // pData zanikne, ale alokovaná paměť zůstává obsazená!

int main() {
    for (int i = 0; i < 100000; ++i) {
        funkceSUnikem(); // Každé volání "ztratí" 1000 * sizeof(int) bajtů
    }
    return 0; // Program může spotřebovat hodně paměti
}
```

### **Prevence úniků paměti**

  * **Disciplína:** Vždy párovat `new` s `delete` / `new[]` s `delete[]`.
  * **RAII (Resource Acquisition Is Initialization):** Moderní C++ technika, kde se o správu zdroje (např. paměti) stará objekt (třída). Zdroj se alokuje v konstruktoru a automaticky uvolňuje v destruktoru. Toto je princip **chytrých ukazatelů** (`std::unique_ptr`, `std::shared_ptr`), které jsou preferovaným způsobem správy dynamické paměti v moderním C++. *(Zmíníme se o nich později)*.
