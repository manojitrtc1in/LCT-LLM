import sys
from functools import lru_cache

sys.setrecursionlimit(200000)

USUAL_MOD = 1000000007
fftmod = 998244353

def powmod(x, n, m):
    res = 1
    x %= m
    while n:
        if n & 1:
            res = res * x % m
        x = x * x % m
        n //= 2
    return res

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def cnk(n, k, fact, revFact):
    return fact[n] * revFact[k] % fftmod * revFact[n - k] % fftmod

def solve():
    global a
    fact = [1] * (200001)
    revFact = [1] * (202021)

    for i in range(1, 200001):
        fact[i] = fact[i - 1] * i % fftmod

    revFact[200000] = powmod(fact[200000], fftmod - 2, fftmod)
    for i in range(199999, -1, -1):
        revFact[i] = revFact[i + 1] * (i + 1) % fftmod

    n, k = read_ints()
    a = read_ints() + [0]  # Append a[0] at the end

    cnt = sum(a[i] != a[i + 1] for i in range(n))

    if k == 1 or n == 1:
        print(0)
        return

    ans = 0
    freeChoices = k - 2
    for i in range(cnt // 2 + 1):
        cur = (cnk(cnt, i, fact, revFact) * cnk(cnt - i, i, fact, revFact) % fftmod *
                powmod(freeChoices, cnt - 2 * i, fftmod) % fftmod *
                powmod(k, n - cnt, fftmod) % fftmod)
        ans += cur

    ans %= fftmod
    tot = powmod(k, n, fftmod) - ans
    if tot < 0:
        tot += fftmod

    print(tot * powmod(2, fftmod - 2, fftmod) % fftmod)

if __name__ == "__main__":
    solve()
