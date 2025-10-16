from os.path import join, dirname, realpath

def main():  
    try:  
        with open(join(dirname(realpath(__file__)), "input.txt"), "r", encoding="utf_8") as soubor:  
            celkovy_soucet = 0  
            for radek in soubor:  
                cislice = [znak for znak in radek if znak.isdigit()]  
                  
                if cislice:  
                    hodnota = int(cislice[0] + cislice[-1])  
                    celkovy_soucet += hodnota  
              
            print(f"Celkovy soucet v Pythonu je: {celkovy_soucet}")

    except FileNotFoundError:  
        print("Chyba: Soubor 'input.txt' nebyl nalezen.")

if __name__ == "__main__":  
    main()