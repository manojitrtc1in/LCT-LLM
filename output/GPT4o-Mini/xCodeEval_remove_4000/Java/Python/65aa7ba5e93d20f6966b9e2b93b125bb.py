import sys
import math
from collections import defaultdict
from random import randint

MOD = int(1e9 + 7)

def main():
    test = 1
    while test > 0:
        solve()
        test -= 1

def solve():
    s = input().strip()
    t = input().strip()
    n = len(s)
    m = len(t)
    pre = [0] * m
    suf = [0] * m
    
    j = 0
    for i in range(m):
        while s[j] != t[i]:
            j += 1
        pre[i] = j
        j += 1
    
    j = n - 1
    for i in range(m - 1, -1, -1):
        while s[j] != t[i]:
            j -= 1
        suf[i] = j
        j -= 1
    
    ans = max(suf[0], n - 1 - pre[m - 1])
    for i in range(m - 1):
        ans = max(ans, suf[i + 1] - 1 - pre[i])
    
    print(ans)

def max_right(x, a):
    l = -1
    r = len(a)
    while r - l > 1:
        m = l + (r - l) // 2
        if a[m] <= x:
            l = m
        else:
            r = m
    return l + 1

def min_left(x, a):
    l = -1
    r = len(a)
    while r - l > 1:
        m = l + (r - l) // 2
        if a[m] < x:
            l = m
        else:
            r = m
    return r + 1

def lower_bound(key, a):
    s = 0
    e = len(a) - 1
    if e == -1:
        return 0
    ans = -1
    while s <= e:
        m = s + (e - s) // 2
        if a[m] >= key:
            ans = m
            e = m - 1
        else:
            s = m + 1
    return ans if ans != -1 else s

def upper_bound(key, a):
    s = 0
    e = len(a) - 1
    if e == -1:
        return 0
    ans = -1
    while s <= e:
        m = s + (e - s) // 2
        if a[m] > key:
            ans = m
            e = m - 1
        else:
            s = m + 1
    return ans if ans != -1 else s

def mul(a, b):
    return (a % MOD) * (b % MOD) % MOD

def add(a, b):
    return (a % MOD + b % MOD) % MOD

def sub(a, b):
    return (a % MOD - b % MOD) % MOD

def prime_factors(n):
    arr = []
    if n % 2 == 0:
        arr.append(2)
    while n % 2 == 0:
        n //= 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        flag = 0
        while n % i == 0:
            n //= i
            flag = 1
        if flag == 1:
            arr.append(i)
    if n > 2:
        arr.append(n)
    return arr

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, int(math.sqrt(n)) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    return True

def fast_expo(x, n):
    if n == 0:
        return 1
    if n % 2 == 0:
        return fast_expo((x * x) % MOD, n // 2) % MOD
    return (x % MOD * fast_expo((x * x) % MOD, (n - 1) // 2)) % MOD

def modinv(x):
    return fast_expo(x, MOD - 2)

def modpow(a, b):
    if b == 0:
        return 1
    x = modpow(a, b // 2)
    x = (x * x) % MOD
    if b % 2 == 1:
        return (x * a) % MOD
    return x

if __name__ == "__main__":
    main()
