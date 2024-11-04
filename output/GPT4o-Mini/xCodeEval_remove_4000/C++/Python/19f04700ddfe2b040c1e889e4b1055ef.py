import sys
import random
from collections import defaultdict
from math import isqrt

MOD = 998244353
MAXN = 200005

class Combinatorics:
    def __init__(self, max_n):
        self.fact = [0] * (max_n + 1)
        self.inv_fact = [0] * (max_n + 1)

    def init(self, N, P):
        assert N < P
        self.fact[0] = 1
        for i in range(1, N + 1):
            self.fact[i] = self.fact[i - 1] * i % P
        self.inv_fact[N] = pow(self.fact[N], P - 2, P)
        for i in range(N - 1, -1, -1):
            self.inv_fact[i] = self.inv_fact[i + 1] * (i + 1) % P

    def factorial(self, N):
        return self.fact[N]

    def inv_factorial(self, N):
        return self.inv_fact[N]

    def choose(self, N, K, P):
        return self.fact[N] * self.inv_fact[K] % P * self.inv_fact[N - K] % P

def read_ints():
    return list(map(int, sys.stdin.readline().split()))

def write(value):
    sys.stdout.write(str(value) + '\n')

def main():
    N, K = read_ints()
    A = [0] + read_ints()  # 1-indexed
    A.append(A[N])  # A[0] = A[N]

    if K == 1:
        write(0)
        return

    comb = Combinatorics(MAXN)
    comb.init(N, MOD)

    cnt = sum(A[i] != A[i + 1] for i in range(N))
    ans = 0

    for i in range(cnt // 2 + 1):
        add = comb.choose(cnt, i, MOD) * comb.choose(cnt - i, i, MOD) % MOD
        add = add * pow(K, N - cnt, MOD) % MOD
        add = add * pow(K - 2, cnt - 2 * i, MOD) % MOD
        ans = (ans + add) % MOD

    ans = (pow(K, N, MOD) - ans + MOD) % MOD
    ans = ans * pow(2, MOD - 2, MOD) % MOD
    write(ans)

if __name__ == "__main__":
    main()
