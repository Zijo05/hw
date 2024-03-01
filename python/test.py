import random
import os

def generisi_jabuku(ploca, zmija):
    while True:
        x = random.randint(0, len(ploca) - 1)
        y = random.randint(0, len(ploca[0]) - 1)

        if [x, y] not in zmija:
            return [x, y]

def ispisi_plocu(ploca, zmija, jabuka):
    for i in range(len(zmija)):
        x = zmija[i]
        
        if i < len(zmija) - 1:
            ploca[x[0]][x[1]] = 'O'
        else:
            ploca[x[0]][x[1]] = 'X'

    ploca[jabuka[0]][jabuka[1]] = 'Q'

    for i in range(len(ploca)):
        for j in range(len(ploca[i])):
            print(ploca[i][j], end=" ")
        print()

    ploca[jabuka[0]][jabuka[1]] = ' '
    
    
    for x in zmija:
        ploca[x[0]][x[1]] = ' '
    


# shallow copy
def pomjeri_kursor(ploca, kursor, smjer, udaljenost, zmija, jabuka):
    if smjer == 'D':
        for _ in range(udaljenost):
            kursor[1] = (kursor[1] + 1) % len(ploca[0])
            zmija.append([kursor[0], kursor[1]])

            if kursor != jabuka:
                zmija.pop(0)
    elif smjer == 'A':
        for _ in range(udaljenost):
            kursor[1] = (kursor[1] - 1) % len(ploca[0])
            zmija.append([kursor[0], kursor[1]])

            if kursor != jabuka:
                zmija.pop(0)
    elif smjer == 'S':
        for _ in range(udaljenost):            
            kursor[0] = (kursor[0] + 1) % len(ploca)
            zmija.append([kursor[0], kursor[1]])

            if kursor != jabuka:
                zmija.pop(0)
    elif smjer == 'W':
        for _ in range(udaljenost):
            kursor[0] = (kursor[0] - 1) % len(ploca)
            zmija.append([kursor[0], kursor[1]])

            if kursor != jabuka:
                zmija.pop(0)

    return kursor == jabuka, kursor in zmija[:-1]

m, n = int(input("Unesite m: ")), int(input("Unesite n: "))

ploca = list()

for i in range(m):
    ploca.append(list())
    for j in range(n):
        ploca[i].append(" ")

zmija = [[0, 0], [0, 1], [0, 2], [0, 3], [0, 4], [0, 5]]
kursor = [0, 5]

ploca[kursor[0]][kursor[1]] = 'X'

jabuka = generisi_jabuku(ploca, zmija)

"""
D - Desno kretanje
A - Lijevo kretanje
W - Gore kretanje
S - Dolje kretanje
"""

smjer = 'D'
je_pojedena = False
je_gubitak = False
while smjer in ('W', 'A', 'S', 'D'):
    if je_pojedena:
        jabuka = generisi_jabuku(ploca, zmija)
    
    os.system("cls")
    ispisi_plocu(ploca, zmija, jabuka)
    
    novi_smjer = input("Unesite smjer: ").upper()

    if novi_smjer != '':
        if smjer == 'W' and novi_smjer in ('A', 'D'):
            smjer = novi_smjer
        elif smjer == 'S' and novi_smjer in ('A', 'D'):
            smjer = novi_smjer
        elif smjer == 'A' and novi_smjer in ('W', 'S'):
            smjer = novi_smjer
        elif smjer == 'D' and novi_smjer in ('W', 'S'):
            smjer = novi_smjer
    
    je_pojedena, je_gubitak = pomjeri_kursor(ploca, kursor, smjer, 1, zmija, jabuka)

    if je_gubitak:
        print("Izgubili ste igru!")
        break