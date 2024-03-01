from random import randint

ploca = list()

for i in range(9):
    ploca.append(list())
    for j in range(9):
        ploca[i].append(randint(1, 9))
        
for i in range(9):
    print(ploca[i])
    
print(" -----------------------------")        
for i in range(9):
    print("|",end="")
    for j in range(9):
        print(f" {ploca[i][j]} ", end="")
        if (j + 1) % 3 == 0:
            print("|",end="")
    print()
    if (i + 1) % 3 == 0:
        print(" -----------------------------")
        
        
        
print([ploca[_][2] for _ in range(9)])