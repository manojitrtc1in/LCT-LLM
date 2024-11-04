import sys
from collections import defaultdict
from itertools import combinations

mod = 10**9 + 7

def powe(b, e):
    r = 1
    while e:
        if e & 1:
            r = r * b % mod
        b = b * b % mod
        e >>= 1
    return r

def admul(a, b, c):
    a[0] = (a[0] + b * c) % mod

def go(n):
    p = [[0] * n for _ in range(n)]
    i100 = powe(100, mod - 2)
    
    for i in range(n):
        for j in range(n):
            x = int(sys.stdin.readline().strip())
            p[i][j] = x * i100 % mod

    x = defaultdict(int)
    init = [0] * (1 << n)
    x[tuple(init)] = 1

    for turn in range(n):
        newx = defaultdict(int)
        for s in range(1 << n):
            mul = 1
            for i in range(n):
                if s >> i & 1:
                    mul = mul * p[i][turn] % mod
                else:
                    mul = mul * (1 - p[i][turn]) % mod
            
            for c in list(x.items()):
                state, count = c
                new_state = list(state)
                for k in range(1 << n):
                    if (k & s) and new_state[k] < bin(k).count('1'):
                        new_state[k] += 1
                
                add = True
                for k in range(1 << n):
                    if new_state[k] + (n - turn - 1) < bin(k).count('1'):
                        add = False
                
                if add:
                    admul(newx[tuple(new_state)], mul, count)
        
        x = newx

    fin = [bin(i).count('1') for i in range(1 << n)]
    ans = x[tuple(fin)]
    ans %= mod
    if ans < 0:
        ans += mod
    print(ans)

def main():
    n = int(sys.stdin.readline().strip())
    if n == 1:
        go(1)
    elif n == 2:
        go(2)
    elif n == 3:
        go(3)
    elif n == 4:
        go(4)
    elif n == 5:
        go(5)
    elif n == 6:
        go(6)

if __name__ == "__main__":
    main()
