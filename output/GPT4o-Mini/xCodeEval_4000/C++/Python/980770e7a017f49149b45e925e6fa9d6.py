import math

def check_min(a, b):
    if b < a:
        return b
    return a

def check_max(a, b):
    if b > a:
        return b
    return a

n = int(input())

a = -1
b = -1

tttt = int(math.sqrt(n))

for i in range(1, tttt + 10):
    if n % i == 0:
        t = n // i
        zt = int(math.sqrt(t))

        for j in range(1, zt + 10):
            if t % j == 0:
                tt = t // j
                if tt >= 1:
                    ttt = (tt + 2) * (i + 1) * (j + 2)

                    if a == -1:
                        a = ttt
                    else:
                        a = check_min(a, ttt)

                    if b == -1:
                        b = ttt
                    else:
                        b = check_max(b, ttt)

        zz = i
        i = n // i

        t = n // i
        zt = int(math.sqrt(t))

        for j in range(1, zt + 10):
            if t % j == 0:
                tt = t // j
                if tt >= 1:
                    ttt = (tt + 2) * (i + 1) * (j + 2)

                    if a == -1:
                        a = ttt
                    else:
                        a = check_min(a, ttt)

                    if b == -1:
                        b = ttt
                    else:
                        b = check_max(b, ttt)

        i = zz

print(a - n, b - n)
