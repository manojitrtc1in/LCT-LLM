import math

mod = 10**9 + 7
error = 2e-6
PI = math.acos(-1)

def MOD(x, m=mod):
    y = x % m
    return y if y >= 0 else y + m

inf = 10**9
infl = 1061109567
nmax = 1000 + 10

n, p = map(int, input().split())
if p == 0:
    print(bin(n).count('1'))
    exit(0)

if p > 0:
    for i in range(1, 36):
        n -= p
        if n < 0:
            print(-1)
            exit(0)
        if bin(n).count('1') <= i and bin(n).count('1') != 0:
            if bin(n).count('1') == 1 and i > math.log2(n) + 1:
                print(-1)
                exit(0)
            print(i)
            exit(0)
    print(-1)
    exit(0)

if p < 0:
    for i in range(1, 36):
        n += -p
        if n < 0:
            continue
        if bin(n).count('1') <= i and bin(n).count('1') != 0:
            if bin(n).count('1') == 1 and i > math.log2(n) + 1:
                print(-1)
                exit(0)
            print(i)
            exit(0)
    print(-1)
    exit(0)
