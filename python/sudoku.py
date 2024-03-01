from random import randint

ploca = list()

for i in range(9):
    ploca.append(list())
    for j in range(9):
        valid = False
        while not valid:  
            #newlist = [expression for item in iterable if condition == True]
            num = (randint(1, 9)) 
            if num not in ploca[i] and num not in [ploca[_][j] for _ in range(i)]:
                ploca[i].append(num)
                valid = True
       
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
        