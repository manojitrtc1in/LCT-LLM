from math import gcd
from functools import lru_cache

mod = int(1e9 + 7)

def umax(a, b):
    return max(a, b)

def umin(a, b):
    return min(a, b)

def abs_val(a):
    return abs(a)

def lcm(a, b):
    return a // gcd(a, b) * b

def modpow(a, n, temp):
    res = 1
    y = a
    while n > 0:
        if n & 1:
            res = (res * y) % temp
        y = (y * y) % temp
        n //= 2
    return res % temp

def ison(mask, pos):
    return (mask & (1 << pos))

def cbit(n):
    k = 0
    while n:
        n &= (n - 1)
        k += 1
    return k

def nbit(n):
    k = 0
    while n:
        n //= 2
        k += 1
    return k

def sgn(x):
    return (x < 0) * -1 + (x > 0)

eps = 1e-7
pi = acos(-1.0)

def inc(x, y):
    x += y
    if x >= mod:
        x -= mod
    return x

def dec(x, y):
    x -= y
    if x < 0:
        x += mod
    return x

def chmax(x, y):
    return max(x, y)

def mulm(x, y):
    x *= y
    if x >= mod:
        x -= mod
    return x

def xo(i):
    if (i & 3) == 0:
        return i
    if (i & 3) == 1:
        return 1
    if (i & 3) == 2:
        return i + 1
    return 0

@lru_cache(None)
def solve(ind, ti, st, f, pd):
    if ind == n:
        return int(st > 0 and f == pd)
    
    res = 0
    if ti:
        for i in range(num[ind]):
            if i == 0:
                res += solve(ind + 1, 0, st, f, i)
            if i > 0:
                if st == 0:
                    res += solve(ind + 1, 0, 1, i, i)
                else:
                    res += solve(ind + 1, 0, st, f, i)
        if num[ind] == 0:
            res += solve(ind + 1, 1, st, f, 0)
        else:
            if st == 0:
                res += solve(ind + 1, 1, 1, num[ind], num[ind])
            else:
                res += solve(ind + 1, 1, st, f, num[ind])
    else:
        for i in range(10):
            if i == 0:
                res += solve(ind + 1, 0, st, f, i)
            if i > 0:
                if st == 0:
                    res += solve(ind + 1, 0, 1, i, i)
                else:
                    res += solve(ind + 1, 0, st, f, i)
    return res

l, r = map(int, input().split())
num = []
while r:
    num.append(r % 10)
    r //= 10
num.reverse()
n = len(num)
ans = 0

ans = solve(0, 1, 0, 0, 0)

num.clear()
k = l
while l:
    num.append(l % 10)
    l //= 10
num.reverse()
n = len(num)
ans -= solve(0, 1, 0, 0, 0)

num.clear()
while k:
    num.append(k % 10)
    k //= 10
ans += (num[0] == num[-1])

print(ans)
