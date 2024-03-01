from random import shuffle as izmijesaj, randint as nasumican_broj
from os import system as konzola

def validan_unos(ploca, red, kolona, broj):
    
    if broj in ploca[red] or broj in [ploca[_][kolona] for _ in range(9)]:
        return False
    
    
    x_pocetak = (red // 3) * 3
    y_pocetak = (kolona // 3) * 3
    for x in range(3):
        for y in range(3):
            if ploca[x_pocetak + x][y_pocetak + y] == broj:
                return False
    
    return True

def popuni_sudoku(ploca):
    for red in range(9):
        for kolona in range(9):
            if ploca[red][kolona] == 0:
                lista_unosa = [_ for _ in range(1, 10)]
                izmijesaj(lista_unosa)
                for broj in lista_unosa:
                    if validan_unos(ploca, red, kolona, broj):
                        ploca[red][kolona] = broj
                        if popuni_sudoku(ploca):
                            return True
                        ploca[red][kolona] = 0 # Backtrack if the current placement is invalid
                return False
    return True
            
def sudoku_ploca():
    ploca = [[0] * 9 for _ in range(9)]
    popuni_sudoku(ploca)
    return ploca

def ispisi_plocu(board):
    print(" -----------------------------")
    for red in range(9):
        print("|", end="")
        for kolona in range(9):
            print(f" {board[red][kolona]} ", end="")
            if (kolona + 1) % 3 == 0:
                print("|", end="")
        print()
        if (red + 1) % 3 == 0:
            print(" -----------------------------")
            
def igraj_sudoku():
    rijesena_ploca = sudoku_ploca()
    igraca_ploca = [[0] * 9 for _ in range(9)]
    counter = 0
    while counter < 30:
        nasumican_red = nasumican_broj(0, 8)
        nasumicna_kolona = nasumican_broj(0, 8)
        if igraca_ploca[nasumican_red][nasumicna_kolona] == 0:
            igraca_ploca[nasumican_red][nasumicna_kolona] = rijesena_ploca[nasumican_red][nasumicna_kolona]
            counter += 1

    while 0 in [broj for red in igraca_ploca for broj in red]:
        ispisi_plocu(igraca_ploca)
        x = int(input("Unesi red: "))
        y = int(input("Unesi kolonu: "))
        unos = int(input("Unesi broj: "))
        if x > 9 or x < 1 or y > 9 or y < 1 or unos > 9 or unos < 1:
            konzola("cls")
            print("Pogriješili ste u prethodnom unosu!")
        elif rijesena_ploca[x - 1][y - 1] == unos:
            igraca_ploca[x - 1][y - 1] = unos
            konzola("cls")
        else:
            konzola("cls")
            print("Pogriješili ste u prethodnom unosu!")