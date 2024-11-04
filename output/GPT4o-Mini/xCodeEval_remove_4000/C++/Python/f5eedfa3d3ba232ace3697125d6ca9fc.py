import sys
from collections import defaultdict

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def powmod(x, n, m):
    r = 1
    x %= m
    while n:
        if n & 1:
            r = r * x % m
        x = x * x % m
        n //= 2
    return r

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def cnk(n, k, fact, revFact, fftmod):
    return fact[n] * revFact[k] % fftmod * revFact[n - k] % fftmod

def solve():
    fftmod = 1000000007
    N = 200000
    fact = [1] * (N + 1)
    revFact = [1] * (N + 1)

    for i in range(1, N + 1):
        fact[i] = fact[i - 1] * i % fftmod

    revFact[N] = powmod(fact[N], fftmod - 2, fftmod)
    for i in range(N - 1, -1, -1):
        revFact[i] = revFact[i + 1] * (i + 1) % fftmod

    n, k = read_ints()
    a = read_ints()
    a.append(a[0])
    
    cnt = sum(a[i] != a[i + 1] for i in range(n))
    
    if k == 1 or n == 1:
        print(0)
        return

    ans = 0
    freeChoices = k - 2
    for i in range(cnt // 2 + 1):
        cur = (cnk(cnt, i, fact, revFact, fftmod) * 
                cnk(cnt - i, i, fact, revFact, fftmod) % fftmod * 
                powmod(freeChoices, cnt - 2 * i, fftmod) % fftmod * 
                powmod(k, n - cnt, fftmod) % fftmod)
        ans += cur

    ans %= fftmod
    tot = powmod(k, n, fftmod) - ans
    if tot < 0:
        tot += fftmod
    print(tot * powmod(2, fftmod - 2, fftmod) % fftmod)

if __name__ == "__main__":
    sys.stdin = open("input.txt", "r")
    solve()
