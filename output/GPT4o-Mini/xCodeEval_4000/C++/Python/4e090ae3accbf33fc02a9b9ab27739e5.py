import sys
import math

MS = 60
pw = [0] * MS

pr = [2, 7, 61]

def count():
    pw[0] = 1
    for c in range(1, MS):
        pw[c] = pw[c - 1] * 2

def square(x):
    return x * x

def bigmod(b, p, m):
    if p == 0:
        return 1
    elif p % 2 == 0:
        return square(bigmod(b, p // 2, m)) % m
    else:
        return (b % m) * bigmod(b, p - 1, m) % m

def mr(n):
    if (n % 2 == 0 and n != 2) or n == 1:
        return True
    s = 0
    d = n - 1
    while d > 1 and d % 2 == 0:
        s += 1
        d //= 2
    for c in range(3):
        if pr[c] < n:
            if bigmod(pr[c], d, n) != 1:
                l = 0
                for r in range(s):
                    if (bigmod(pr[c], pw[r] * d, n) + 1) % n:
                        l += 1
                    else:
                        break
                if l == s:
                    return True
    return False

def sqr(x):
    return x * x

def ok(x):
    if x == 1:
        return False
    if mr(x):
        return False
    v = int(math.sqrt(x))
    for i in range(1, v + 1):
        j = sqr(i)
        if x > j and sqr(math.sqrt(x - j)) + j == x:
            return True
    return False

def main():
    count()
    
    t = [0] * 3001
    for i in range(1, 3001):
        t[i] += t[i - 1]
    
    l, r = map(int, sys.stdin.readline().split())
    res = 0
    
    while l % 100000 and l <= r:
        res += ok(l)
        l += 1
    
    while r % 100000 and l <= r:
        res += ok(r)
        r -= 1
    
    if l <= r:
        res += t[r // 100000] - t[l // 100000]
    
    print(res)

if __name__ == "__main__":
    main()
