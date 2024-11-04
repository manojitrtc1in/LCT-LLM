from math import sqrt

MOD = 1000000007
INF = 0x7fffffff
PI = 3.141592653589793
EPS = 1e-12
OO = 1e15

def check_min(a, b):
    if b < a:
        return b
    return a

def check_max(a, b):
    if b > a:
        return b
    return a

def count_bits(x):
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1)
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2)
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4)
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8)
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16)
    return x

def low_bit(x):
    return x & -x

def high_bit(x):
    p = low_bit(x)
    while p != x:
        x -= p
        p = low_bit(x)
    return p

n = int(input())

a = -1
b = -1

tttt = int(sqrt(n))

for i in range(1, tttt + 10):
    if n % i == 0:
        t = n // i
        zt = int(sqrt(t))

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
        zt = int(sqrt(t))

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
