class KapacitaNaplnenaError(Exception):
    pass

class StudentJizKurzNavstevujeError(Exception):
    pass


class Kurz:
    def __init__(self, kod, nazev, kapacita):
        self.kod = kod
        self.nazev = nazev
        self.kapacita = kapacita
        self.__studenti = []

    def pridej_studenta(self, student):
        if len(self.__studenti) >= self.kapacita:
            raise KapacitaNaplnenaError(f"Kapacita kurzu {self.kod} je naplněna!")
        if student in self.__studenti:
            raise StudentJizKurzNavstevujeError(f"   -> Info: Student {student.jmeno} už je v kurzu zapsán.")
            # print(f"   -> Info: Student {student.jmeno} už je v kurzu zapsán.")
            # return
        self.__studenti.append(student)

    def __len__(self):
        return len(self.__studenti)

    def __str__(self):
        return f"{self.kod}: {self.nazev} [{len(self)}/{self.kapacita}]"


class Student:
    def __init__(self, jmeno, osobni_cislo):
        self.jmeno = jmeno
        self.osobni_cislo = osobni_cislo
        self.__znamky = {}
        self.__zapsane_kurzy = []

    def zapis_kurz(self, kurz):
        print(f"Zapisuji studenta {self.jmeno} do {kurz.kod}...", end=" ")
        
        try:
            kurz.pridej_studenta(self)
            
            self.__zapsane_kurzy.append(kurz)
            print("OK")
            
        except KapacitaNaplnenaError as e:
            print(f"CHYBA: {e}")
        except StudentJizKurzNavstevujeError as e:
            print(f"CHYBA: {e}")

    def udel_znamku(self, kurz, znamka):
        if kurz not in self.__zapsane_kurzy:
            print(f"Chyba: Student {self.jmeno} nenavštěvuje kurz {kurz.kod}, nelze udělit známku.")
            return
        if not (1 <= znamka <= 5):
            print(f"Chyba: Známka {znamka} není v intervalu 1-5.")
            return

        self.__znamky[kurz.kod] = znamka

    @property
    def studijni_prumer(self):
        if not self.__znamky:
            return 0.0
        
        hodnoty_znamek = self.__znamky.values()
        return sum(hodnoty_znamek) / len(hodnoty_znamek)
        
    def __str__(self):
        return (f"Student: {self.jmeno} ({self.osobni_cislo}), "
                f"Průměr: {self.studijni_prumer:.1f}, "
                f"Zapsáno kurzů: {len(self.__zapsane_kurzy)}")


if __name__ == "__main__":
    python_kurz = Kurz("IT101", "Programování v Pythonu", kapacita=2)
    java_kurz = Kurz("IT102", "Java pro začátečníky", kapacita=10)

    s1 = Student("Novák", 12345)
    s2 = Student("Svoboda", 67890)
    s3 = Student("Dvořák", 11111)

    s1.zapis_kurz(python_kurz)
    s1.zapis_kurz(python_kurz)
    s2.zapis_kurz(python_kurz)
    s3.zapis_kurz(python_kurz) 
    

    s1.udel_znamku(python_kurz, 1)
    s2.udel_znamku(python_kurz, 3)
    s3.udel_znamku(python_kurz, 1)
    s1.udel_znamku(python_kurz, 8)
    s1.udel_znamku(java_kurz, 1)

    print(s1)
    print(s2)
    print(s3)
    
    print(f"\nStav kurzu: {python_kurz}")
    print(f"\nStav kurzu: {java_kurz}")
    