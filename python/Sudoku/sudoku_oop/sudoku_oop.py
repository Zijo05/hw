from random import shuffle as izmijesaj, randint as nasumican_broj
from os import system as konzola

class Sudoku:
    def __init__(self, empty=False):
        self.ploca = [[0] * 9 for _ in range(9)]
        if not empty:
            self.popuni_sudoku()
            
    
    def __repr__(self):
        izlazni_string = " -----------------------------\n"
        for red in range(9):
            izlazni_string += "|"
            for kolona in range(9):
                izlazni_string += f" {self.ploca[red][kolona]} "
                if (kolona + 1) % 3 == 0:
                    izlazni_string += "|"
            izlazni_string += "\n"
            if (red + 1) % 3 == 0:
                izlazni_string += " -----------------------------\n"
        return izlazni_string

    def validan_unos(self, red, kolona, broj):
        if broj in self.ploca[red] or broj in [self.ploca[_][kolona] for _ in range(9)]:
            return False
        
        x_pocetak = (red // 3) * 3
        y_pocetak = (kolona // 3) * 3
        for x in range(3):
            for y in range(3):
                if self.ploca[x_pocetak + x][y_pocetak + y] == broj:
                    return False
        return True
    
    def popuni_sudoku(self):
        for red in range(9):
            for kolona in range(9):
                if self.ploca[red][kolona] == 0:
                    lista_unosa = [_ for _ in range(1, 10)]
                    izmijesaj(lista_unosa)
                    for broj in lista_unosa:
                        if self.validan_unos(red, kolona, broj):
                            self.ploca[red][kolona] = broj
                            if self.popuni_sudoku():
                                return True
                            self.ploca[red][kolona] = 0 # Backtrack if the current placement is invalid
                    return False
        return True                    
    
    def sudoku_igraca_ploca(self):
        igraca_ploca = Sudoku(True)
        counter = 0
        while counter < 30:
            nasumican_red = nasumican_broj(0, 8)
            nasumicna_kolona = nasumican_broj(0, 8)
            if igraca_ploca.ploca[nasumican_red][nasumicna_kolona] == 0:
                igraca_ploca.ploca[nasumican_red][nasumicna_kolona] = self.ploca[nasumican_red][nasumicna_kolona]
                counter += 1
        return igraca_ploca
    
    def igraj_sudoku(self):
        igraca_ploca = self.sudoku_igraca_ploca()
        while 0 in [broj for red in igraca_ploca.ploca for broj in red]:
            print(igraca_ploca)
            try: 
                x = int(input("Za izlaz stisnite Ctrl+C\nUnesi red: "))
                y = int(input("Unesi kolonu: "))
                unos = int(input("Unesi broj: "))
                if self.ploca[x - 1][y - 1] == unos:
                    igraca_ploca.ploca[x - 1][y - 1] = unos
                    konzola("cls")
                elif unos > 9 or unos < 1:
                    konzola("cls")
                    print("Moguće je unositi samo brojeve od 1 do 9!")
                else:
                    konzola("cls")
                    print("Pogriješili ste u prethodnom unosu!")
            except ValueError:
                konzola("cls")
                print("Unos treba biti cijeli broj!")
            except IndexError:
                konzola("cls")
                print("Nepostojeći red/kolona! \nPostoji 9 redova/kolona")
            except KeyboardInterrupt:
                konzola("cls")
                print("Vaš sudoku: ")
                print(igraca_ploca)
                print("\nRiješen sudoku: ")
                print(self)
                exit()
                
        return self