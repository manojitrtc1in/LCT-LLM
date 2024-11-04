import sys
from collections import deque
from heapq import heappop, heappush
from math import gcd, log2
from itertools import accumulate

MOD = 1000000007
INF = 1 << 61

def extgcd(a, b):
    if a < b:
        return extgcd(b, a)
    if b > 0:
        g, x, y = extgcd(b, a % b)
        return g, y - (a // b) * x, x
    else:
        return a, 1, 0

def divisor(n):
    ret = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            ret.append(i)
            if i * i != n:
                ret.append(n // i)
    ret.sort()
    return ret

def prime_factorization(n):
    ret = []
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            count = 0
            while n % i == 0:
                n //= i
                count += 1
            ret.append((i, count))
    if n != 1:
        ret.append((n, 1))
    return ret

def mod_pow(x, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % mod
        x = x * x % mod
        n >>= 1
    return res

def mod_inv(x, mod):
    return mod_pow(x, mod - 2, mod)

def main():
    input = sys.stdin.read
    data = input().split()
    
    m = int(data[0])
    h1, a1, x1, y1 = map(int, data[1:5])
    
    t = [h1]
    used = [0] * m
    used[h1] = 1
    
    while True:
        tmp = (t[-1] * x1 + y1) % m
        t.append(tmp)
        if used[tmp]:
            break
        used[tmp] = 1
    
    used = [0] * m
    h2, a2, x2, y2 = map(int, data[5:9])
    used[h2] = 1
    s = [h2]
    
    while True:
        tmp = (s[-1] * x2 + y2) % m
        s.append(tmp)
        if used[tmp]:
            break
        used[tmp] = 1
    
    l1 = -1
    l2 = -1
    mn1 = INF
    mn2 = INF
    now = 0
    
    while True:
        if t[-1] == t[now]:
            l1 = len(t) - now - 1
        if t[now] == a1:
            mn1 = now
            break
        now += 1
        if now == len(t):
            break
    
    now = 0
    while True:
        if s[-1] == s[now]:
            l2 = len(s) - now - 1
        if s[now] == a2:
            mn2 = now
            break
        now += 1
        if now == len(s):
            break
    
    def calc():
        if mn1 != INF and mn2 != INF:
            if mn1 == mn2:
                return mn1
            if mn1 > mn2 and l2 == -1:
                return -1
            if mn1 < mn2 and l1 == -1:
                return -1
            if l1 == -1:
                if (mn1 - mn2) % l2 == 0:
                    return mn1
                else:
                    return -1
            if l2 == -1:
                if (mn2 - mn1) % l1 == 0:
                    return mn2
                else:
                    return -1
            if l1 == l2:
                if abs(mn1 - mn2) % l1 == 0:
                    return max(mn1, mn2)
                else:
                    return -1
            if mn2 > mn1 and (mn2 - mn1) % l1 == 0:
                return mn2
            if mn1 > mn2 and (mn1 - mn2) % l2 == 0:
                return mn1
            
            if abs(mn2 - mn1) % abs(gcd(l1, l2)) != 0:
                return -1
            
            x, y = 0, 0
            g = extgcd(l1, l2)
            x *= (mn2 - mn1) // g[0]
            y *= (mn2 - mn1) // g[0]
            mn = INF
            
            while x * l1 + mn1 < max(mn1, mn2):
                x += l2 // g[0]
            
            mn = x * l1 + mn1
            
            while True:
                x -= l2 // g[0]
                if x * l1 + mn1 >= max(mn1, mn2):
                    mn = min(mn, x * l1 + mn1)
                else:
                    break
            
            return mn
        else:
            return -1
    
    print(calc())

if __name__ == "__main__":
    main()
