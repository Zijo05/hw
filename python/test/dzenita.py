"""
Kazemo da su brojevi a i b prosti blizanci ukoliko njihova apsolutna razlika je 2. 
Primjer takvih brojeva jesu (3, 5), (5, 7), (11, 13), … Reći ćemo da je (3, 5) prvi blizanci, (5, 7) drugi blizanci itd. 
Napisati Python3 program koji će od korisnika tražiti prirodan broj n, te napraviti listu od n prostih blizanaca i ispisati ih redom u konzoli.
"""
from math import sqrt

def je_prost(broj):
    if broj < 1:
        return False
    else:
        for i in range(2, int(sqrt(broj)) + 1):
            if (broj % i == 0):
                return False
    return True

def prosti_blizanci(n):
    lista_prostih_blizanaca = list()
    brojac = 0
    broj = 2
    while brojac < n:
        if je_prost(broj) and je_prost(broj + 2):
            lista_prostih_blizanaca.append((broj, broj + 2))
            brojac += 1
        broj += 1
    return lista_prostih_blizanaca
        
unos = int(input("Unesite n: "))

for par_prostih_blizanaca in prosti_blizanci(unos):
    print(par_prostih_blizanaca)