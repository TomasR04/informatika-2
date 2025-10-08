# **Výuka C++ a Pythonu \- Úvodní hodina**

## **1\. Cíle předmětu**

V rámci tohoto předmětu se společně ponoříme do světa programování ve dvou silných a široce používaných jazycích: C++ a Python. Cílem je:

* **Naučit se přemýšlet jako programátor:** Osvojit si algoritmické myšlení a principy řešení problémů.  
* **Zvládnout základy C++:** Porozumět nízkoúrovňovým konceptům, správě paměti a vytvářet výkonné aplikace.  
* **Zvládnout základy Pythonu:** Naučit se rychle vyvíjet, skriptovat a využívat jeho rozsáhlý ekosystém knihoven.  
* **Získat praktické dovednosti:** Veškerou teorii si vyzkoušet na praktických úkolech a projektech.  
* **Osvojit si moderní nástroje:** Pracovat s verzovacím systémem Git a kontejnerizací pomocí Dockeru pro efektivní vývoj.

Po absolvování kurzu byste měli být schopni samostatně navrhnout a implementovat funkční aplikace v obou jazycích.

## **2\. Organizační informace**

* **Způsob zakončení:** Zápočet bude udělen za aktivní účast a především za odevzdání a prezentaci projektů.  
* **Hodnocení:**  
  * **Projekty:** 64 bodů (možnost jednoho velkého nebo více menších).  
  * **Domácí úkoly:** 36 bodů. Úkoly budou zadávány přes [GitHub repozitář](https://github.com/TomasRacil/Informatika-2-ukoly-2025.git) a odevzdání bude probíhat formou **Pull Requestů**, které budou kontrolovány automatizovanými testy.
  * **Bonusové body:** Za aktivity jako Advent of Code, rychlé a správné odevzdání úkolů a další.  
  * Pro udělení zápočtu je potřeba získat **minimálně 60 bodů**. Body nad 60 se přenáší jako bonus ke zkoušce.  
* **Zkouška:** 
  * Skládá se z praktické algoritmické úlohy a ústní části. Maximální počet bodů je 100.
  * Bonusové body ze semestru (vše nad 60) se přičítají k výsledku zkoušky. Příklad: Student se 100 body ze semestru má 40 bonusových bodů, ke splnění zkoušky na E mu tedy stačí získat 11 bodů.
  * **Klasifikace zkoušky:**
    * A: > 90 bodů
    * B: > 80 bodů
    * C: > 70 bodů
    * D: > 60 bodů
    * E: > 50 bodů
* **Materiály:** Veškeré podklady, zadání a příklady budou dostupné v tomto GitHub repozitáři.

## **3\. Harmonogram předmětu**

Aktuální a detailní plán výuky je dostupný online v [**této tabulce**](https://docs.google.com/spreadsheets/d/1F9X9y3-JuW-Zs4RoUwL-ehhlAPP2YMKr1AgtnVKkm-8/edit?usp=sharing).

*Poznámka: Harmonogram je orientační a může dojít k drobným úpravám v průběhu semestru.*

## **4\. Úvod do C++ a Pythonu**

### **Proč zrovna tyto dva jazyky?**

Kombinace C++ a Pythonu pokrývá obrovské spektrum programátorských úloh. Zatímco C++ exceluje ve výkonu a kontrole nad hardwarem, Python nabízí neuvěřitelnou rychlost vývoje a jednoduchost.

#### **C++**

* **Charakteristika:** Kompilovaný jazyk, extrémní rychlost, efektivita, plná kontrola nad hardwarem a správou paměti.  
* **Kdy ho použít:**  
  * Aplikace kritické na výkon (hry, grafické editory, vědecké výpočty).  
  * Systémové programování (operační systémy, ovladače).  
  * Vestavěné systémy (Embedded systémy, IoT).  
  * Síťové programování.  
* **Nevýhody:** Složitější syntaxe, strmější křivka učení.
```cpp
#include <iostream>

int main() {  
    std::cout << "Hello, C++ World!";  
    return 0;  
}
```
#### **Python**

* **Charakteristika:** Interpretovaný jazyk, velmi jednoduchá a čitelná syntaxe, obrovské množství knihoven.  
* **Kdy ho použít:**  
  * Rychlý vývoj a prototypování.  
  * Webový vývoj (backend).  
  * Analýza dat, strojové učení a umělá inteligence.  
  * Skriptování a automatizace úloh.  
* **Nevýhody:** Nižší výkon v porovnání s C++.
```python
print('Hello, Python world!')
```

## **5\. Nástroje a prostředí**

Pro tento kurz budeme používat moderní a standardní nástroje, které vám usnadní práci a připraví vás na praxi.

* **Primární nástroje:**  
  * **Git & GitHub:** Pro verzování a sdílení kódu.  
  * **Docker & Docker Compose:** Pro správu vývojového prostředí.  
  * **VS Code:** Doporučený editor s rozšířeními pro C++ a Python.

### **Spuštění vývojového prostředí (Dev Container)**

Celý repozitář je připraven jako **Dev Container**. To znamená, že nemusíte nic složitě instalovat na svůj počítač. Stačí mít **Docker Desktop** a **VS Code** s rozšířením **"Dev Containers"**.

**Postup spuštění:**

1. **Otevřete složku projektu ve VS Code.**  
2. VS Code automaticky detekuje konfiguraci a v pravém dolním rohu zobrazí notifikaci s tlačítkem **"Reopen in Container"**. Klikněte na něj.  
3. Počkejte, až se kontejner sestaví a spustí. VS Code se k němu automaticky připojí.  
4. Nyní můžete otevřít terminál přímo ve VS Code (Terminal \-\> New Terminal). Tento terminál již běží uvnitř kontejneru a máte v něm k dispozici kompilátor pro C++ (g++), interpret Pythonu (python3) a všechny ostatní potřebné nástroje.

## **6\. Motivační příklad**

Abychom viděli rozdíly mezi jazyky v praxi, podívejte se na jednoduchý [**motivační příklad**](./motivacni-priklad/README.md), který řeší stejnou úlohu (načtení a součet čísel ze souboru) jednou v C++ a jednou v Pythonu.

## **7\. Co dál?**

* **Test znalostí:** Prosím, vyplňte krátký [úvodní test znalostí](https://forms.gle/tdazKRPRFetKRVc46). Je anonymní a slouží pouze pro mou představu o vašich dosavadních zkušenostech.  
* **Nastavení prostředí:** Ujistěte se, že máte nainstalovaný Docker a VS Code s rozšířením "Dev Containers".  
* **Příprava na příští hodinu:** Podíváme se na základní syntaxi jazyka C++, proměnné, datové typy a první jednoduché programy.