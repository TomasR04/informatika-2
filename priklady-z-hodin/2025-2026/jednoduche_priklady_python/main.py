from os.path import join, dirname, realpath


def vypis_statistiku(cisla):
    print(
        f"Soucet cisel: {sum(cisla)}, nejvetsi cislo: {max(cisla)}, nejmensi cislo: {min(cisla)}")
    suda_cisla = [cislo for cislo in cisla if cislo % 2 == 0]
    print(
        f"Pocet sudych: {len(suda_cisla)}, pocet lichych: {len(cisla)-len(suda_cisla)}")
    print(f"Prumerna hodnota: {sum(cisla)/len(cisla)}")


def uloha_1():
    cisla = []
    while True:
        vstup = input("Zadejte cislo nebo stop: ")
        if vstup.lower() == "stop":
            break
        elif vstup.isdigit():
            cisla.append(int(vstup))
        else:
            print("Zadejete platnou hodnotu!")
    vypis_statistiku(cisla)


def spocitej_znaky(text: str):
    text = text.lower()
    return {k: text.count(k) for k in set(text) if k != " "}


def uloha_2():
    text = input("Zadej libovolny retezec: ")
    print(spocitej_znaky(text))


studenti = []


def pridej_studenta(jmeno, znamky):
    studenti.append({"jmeno": jmeno, "znamky": znamky})


def nejlepsi_student(seznam_studentu=studenti):
    seznam_studentu.sort(key=lambda s: sum(s["znamky"])/len(s["znamky"]))
    print(seznam_studentu)


def uloha_3():
    pridej_studenta("Jan", [1, 2, 3])
    pridej_studenta("Pepa", [2, 3, 3])
    pridej_studenta("Marketa", [1, 2, 1])
    nejlepsi_student()


def uloha_4():
    with open(join(dirname(realpath(__file__)), "system.log"), 'r') as f:
        errors = ""
        for line in f:
            if line.startswith("ERROR"):
                errors += line
    with open(join(dirname(realpath(__file__)), "errors_only.txt"), 'w') as f:
        f.write(errors)


def sifruj(text, posun):
    return "".join([
        chr(((ord(ch)+posun)-(97 if ch.islower() else 65)) %
            26+(97 if ch.islower() else 65))
        if 97 <= ord(ch.lower()) <= 122
        else ch
        for ch in text])


def uloha_5():
    print(sifruj("Ahoj zeme!", 1))


def main():
    uloha_1()
    uloha_2()
    uloha_3()
    uloha_4()
    uloha_5()


if __name__ == "__main__":
    main()
