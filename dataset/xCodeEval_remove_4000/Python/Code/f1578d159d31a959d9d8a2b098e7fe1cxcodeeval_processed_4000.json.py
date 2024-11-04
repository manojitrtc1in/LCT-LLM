import math






























t = int(input())
for t in range(t):
    n = int(input())
    piles = list(map(int, input().split()))
    if(n % 2 == 1):
        print("Mike")
        continue
    else:
        id0 = 10**9
        joeMin = 10**9
        for i in range(n):
            if(i%2 == 0):
                id0 = min(id0, piles[i])
            else:
                joeMin = min(joeMin, piles[i])
        if(id0 > joeMin):
            print("Mike")
        elif(joeMin < id0):
            print("Joe")
        else:
            if(piles.index(id0) % 2 == 0):
                print("Joe")
            else:
                print("Mike")

