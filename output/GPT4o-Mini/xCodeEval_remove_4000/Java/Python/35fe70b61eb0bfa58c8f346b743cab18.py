import sys
from collections import defaultdict

mod = 998244353

def pre_fact(n):
    fact = [1] * (n + 1)
    rev_fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = (fact[i - 1] * i) % mod
    rev_fact[n] = pow(fact[n], mod - 2, mod)
    for i in range(n - 1, -1, -1):
        rev_fact[i] = (rev_fact[i + 1] * (i + 1)) % mod
    return fact, rev_fact

def cmb(a, b, fact, rev_fact):
    if a < b:
        return 0
    return (fact[a] * rev_fact[b] % mod) * rev_fact[a - b] % mod

def pow_mod(x, y):
    if y < 0:
        return 0
    if y == 0:
        return 1
    if y % 2 == 1:
        return (x * pow_mod(x, y - 1)) % mod
    root = pow_mod(x, y // 2)
    return (root * root) % mod

def solve():
    n = int(input())
    tmp = int(input())
    if n <= tmp:
        print(0)
        return
    k = tmp
    fact, rev_fact = pre_fact(400000)
    ans = 0
    si = 1
    t = cmb(n, n - k, fact, rev_fact)
    for i in range(n - k, 0, -1):
        ans += si * cmb(n - k, i, fact, rev_fact) * pow_mod(i, n) % mod
        ans %= mod
        si *= -1
    ans *= t
    ans %= mod
    if k != 0:
        ans *= 2
        ans %= mod
    print(ans)

if __name__ == "__main__":
    solve()
