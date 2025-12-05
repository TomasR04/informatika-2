# **05 - Pokročilý Python**

Tato sekce vás posune od psaní jednoduchých skriptů k tvorbě **profesionálních, robustních a udržovatelných aplikací**.

Kromě **Objektově Orientovaného Programování (OOP)**, které je nezbytné pro větší projekty, se zaměříme i na nástroje pro **efektivitu kódu** (dekorátory), **bezpečnost** (správa chyb), **monitorování** (logování) a **správu prostředí**. Cílem je naučit se psát Python kód tak, jak se píše v reálné praxi.

## **Vývojové prostředí (DevContainer)**

Tento repozitář je nakonfigurován jako **DevContainer**. To znamená, že máte připravené kompletní prostředí pro vývoj bez nutnosti cokoliv instalovat do svého počítače.

**Co máte k dispozici:**

* **Python 3.x** - Interpret jazyka je již nainstalován.  
* **VS Code Extensions** - Doplňky pro Python, Jupyter Notebooky a lintery jsou aktivní.  
* **Terminál** - Příkazová řádka je integrovaná přímo v editoru.

## **Jak pracovat s materiály**

V každé složce naleznete tři typy souborů:

1. `README.md` - Teorie k danému tématu.  
2. `main.py` - Ukázkový skript.  
3. `teorie.ipynb` - Interaktivní sešit (Jupyter Notebook).

### **Možnost A: Spouštění Python skriptů (.py)**

Jelikož jste ve VS Code, máte dvě snadné možnosti:

1. **Tlačítko Play:** Otevřete soubor `main.py` a klikněte na ikonu "Play" v pravém horním rohu editoru. Kód se spustí v terminálu.  
2. **Terminál:** Otevřete terminál (zkratka `Ctrl + ;` nebo menu *Terminal -> New Terminal*) a napište:
   ```bash
   python cesta/k/souboru/main.py
   ```

### **Možnost B: Interaktivní sešity (.ipynb)**

Jupyter Notebooky umožňují spouštět kód po částech (buňkách) a vidět výsledek okamžitě pod nimi.

1. Otevřete soubor s koncovkou `.ipynb`.  
2. VS Code automaticky načte rozhraní pro notebooky (pokud se zeptá na "Kernel", zvolte **Python 3** nebo **Recommended**).  
3. Kliknutím na tlačitko spustit vlevo u každé buňky spustíte daný kus kódu.

## **Obsah sekce**

1. [Type Hinting (Typové anotace)](./01-typing/) 
2. [Úvod do tříd a objektů](./02-uvod-do-trid/)  
3. [Modifikátory přístupu a Vlastnosti](./03-modifikatory-pristupu-a-vlastnosti/)  
4. [Dědičnost](./04-dedicnost/)  
5. [Abstraktní třídy a Polymorfismus](./05-abstraktni-tridy/)  
6. [Magické metody](./06-magicke-metody/)

<!-- ### **Pokročilé techniky a nástroje**

6. [Type Hinting (Typové anotace)](./06-typing/)  
7. [Dekorátory](./07-dekoratory/)  
8. [Výjimky a Error Handling](./08-vyjimky/)  
9. [Logování](./09-logovani/)  
10. [Argumenty příkazové řádky (CLI)](./10-argumenty-prikazove-radky/)  
11. [Virtuální prostředí a správa balíčků](./11-prostredi-a-balicky/) -->