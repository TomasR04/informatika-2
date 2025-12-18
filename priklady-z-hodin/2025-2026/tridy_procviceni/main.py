'''from os import dirname, join, realpath'''
import functools as f

class Polozka:
    def __init__(self, nazev:str, cena:int, mnozstvi:int):
        self.nazev = nazev 
        self.cena = cena
        self.mnozstvi = mnozstvi
        pass 
    def __str__(self):
        return f"{self.nazev}: {self.cena} Kč ({self.mnozstvi} ks)" 
    def __repr__(self):
        # Polozka('Jablko', 25.5, 100)
        return f"Polozka({self.nazev!r}, {self.cena!r}, {self.mnozstvi!r})"
    def __eq__(self, to_compare):
        if (self.nazev != to_compare.nazev):
            return False 
        if (self.cena != to_compare.cena):
            return False 
        
        return True 
    def __add__(self, other_item):
        if (self != other_item):
            raise ValueError("Nelze sčítat různé zboží!")
        
        print(f"Sčítám položky: {self} + {other_item}")
        return Polozka(self.nazev, self.cena, self.mnozstvi + other_item.mnozstvi)

def loguj_volani(metoda):
    @f.wraps(metoda)
    def wrapper(*args, **kwargs):
        
        argumenty = args[1:]
        zprava = f"[LOG] Volana metoda '{metoda.__name__}' s argumenty: {argumenty}"

        print(zprava)

        with open("log.txt", "a", encoding="utf-8") as f:
            f.write(zprava + "\n")

        return metoda(*args, **kwargs)
    return wrapper





class Sklad:
    def __init__(self):
        self.data:list[Polozka] = []
    def __len__(self):
        return sum(polozka.mnozstvi for polozka in self.data)
    def __getitem__(self, index):
        for polozka in self.data:
            if polozka.nazev == index:
                return polozka
        raise KeyError(f"Položka '{index}' nebyla nalezena ve skladu.")

    def pridej_polozku(self, polozka):
        for i, existujici_polozka in enumerate(self.data):
            if existujici_polozka == polozka:
                self.data[i] = existujici_polozka + polozka
                return
        self.data.append(polozka)

    

    def odeber_polozku(self,nazev, pocet):
        for polozka in self.data:
            if polozka.nazev == nazev:
                if polozka.mnozstvi < pocet:
                    raise ValueError("Není dostatek položek na skladě!")
                polozka.mnozstvi -= pocet
                return
    
        return





def main():
    # 1. Vytvoření položek
    jablka = Polozka("Jablko", 10, 50)
    dalsi_jablka = Polozka("Jablko", 10, 20)
    hrušky = Polozka("Hruška", 15, 30)

    print(f"Test sčítání: {jablka + dalsi_jablka}")  # Mělo by vypsat Jablko s množstvím 70

    # 2. Práce se skladem
    sklad = Sklad()
    sklad.pridej_polozku(jablka)
    print(f"Položka ve skladu: {sklad['Jablko']}")
    sklad.pridej_polozku(dalsi_jablka) # Log: Volána metoda pridej...
    print(f"Celkem kusů na skladu: {len(sklad)}")
    sklad.pridej_polozku(hrušky)       # Log: Volána metoda pridej...
    for item in sklad.data:
        print(item)
    
    print(f"Položka ve skladu: {sklad['Hruška']}")
    
    print(f"Celkem kusů na skladu: {len(sklad)}")

    # 3. Uložení a načtení
    '''sklad.uloz_do_csv("sklad_data.csv")
    print("Uloženo.")

    novy_sklad = Sklad.nacti_z_csv("sklad_data.csv")
    print(f"Načteno {len(novy_sklad)} kusů zboží z nového skladu.")'''
if __name__ == "__main__":
    main()