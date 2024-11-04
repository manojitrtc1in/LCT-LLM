import math

n = int(input())

a = -1
b = -1

tttt = int(math.sqrt(n))

for i in range(1, tttt + 9):
    if n % i == 0:
        t = n // i
        zt = int(math.sqrt(t))
        
        for j in range(1, zt + 9):
            if t % j == 0:
                tt = t // j
                if tt >= 1:
                    ttt = (tt + 2) * (i + 1) * (j + 2)
                    
                    if a == -1:
                        a = ttt
                    else:
                        a = min(a, ttt)
                    
                    if b == -1:
                        b = ttt
                    else:
                        b = max(b, ttt)
        
        zz = i
        i = n // i
        
        t = n // i
        zt = int(math.sqrt(t))
        
        for j in range(1, zt + 9):
            if t % j == 0:
                tt = t // j
                if tt >= 1:
                    ttt = (tt + 2) * (i + 1) * (j + 2)
                    
                    if a == -1:
                        a = ttt
                    else:
                        a = min(a, ttt)
                    
                    if b == -1:
                        b = ttt
                    else:
                        b = max(b, ttt)
        
        i = zz

print(a - n, b - n)
