import random

class Tacka:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def __repr__(self):
        return f"({round(self.x, 1)}, {round(self.y, 1)})"

class Pravougaonik:
    def __init__(self, tacka1, tacka2):
        self.tacka1 = tacka1
        self.tacka2 = tacka2
        
    def __repr__(self):
        if self.je_kvadrat():
            return f"Kvadrat({self.tacka1}, {self.tacka2})"
        return f"Pravougaonik({self.tacka1}, {self.tacka2})"
    
    def je_kvadrat(self):
        if abs(self.tacka1.x - self.tacka2.x) == abs(self.tacka1.y - self.tacka2.y):
            return True
        else:
            return False
    
    def povrsina(self):
        duzina = abs(self.tacka1.x - self.tacka2.x)
        sirina = abs(self.tacka1.y - self.tacka2.y)
        return duzina * sirina

# Generisanje 100 pravougaonika sa nasumičnim tačkama
pravougaonici = []
for _ in range(100):
    x1, y1 = random.uniform(0, 100), random.uniform(0, 100)
    x2, y2 = random.uniform(0, 100), random.uniform(0, 100)
    tacka1 = Tacka(x1, y1)
    tacka2 = Tacka(x2, y2)
    pravougaonici.append(Pravougaonik(tacka1, tacka2))

# Pronalaženje i ispisivanje površine kvadrata
kvadrati = [pravougaonik for pravougaonik in pravougaonici if pravougaonik.je_kvadrat()]
if kvadrati:
    for kvadrat, _ in kvadrati, range(len(kvadrati)):
        print(f"Kvadrat {_ + 1}: {kvadrat}")
else:
    # Generisanje 10 nasumičnih kvadrata (izgenerisati samo jednu tačku)
    print("Nema kvadrata.\nGenerisani nasumični kvadrati:")
    for _ in range(10):
        x, y = random.uniform(0, 100), random.uniform(0, 100)
        tacka1 = Tacka(x, y)
        tacka2 = Tacka(x + random.uniform(1, 10), y + random.uniform(1, 10))  # Nasumična dužina i širina
        kvadrat = Pravougaonik(tacka1, tacka2)
        print(f"Kvadrat {_ + 1}: {kvadrat}")