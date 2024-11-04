import sys
from collections import defaultdict

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
            self.fact[i] = self.mul_mod(self.fact[i - 1], i, P)
        self.inv_fact[N] = self.mul_inv_prime(self.fact[N], P)
        for i in range(N - 1, -1, -1):
            self.inv_fact[i] = self.mul_mod(self.inv_fact[i + 1], i + 1, P)

    def factorial(self, N):
        return self.fact[N]

    def inv_factorial(self, N):
        return self.inv_fact[N]

    def choose(self, N, K, P):
        return self.mul_mod(self.mul_mod(self.fact[N], self.inv_fact[K], P), self.inv_fact[N - K], P)

    def mul_mod(self, a, b, mod):
        return (a * b) % mod

    def pow_mod(self, base, exp, mod):
        result = 1
        while exp > 0:
            if exp % 2 == 1:
                result = self.mul_mod(result, base, mod)
            base = self.mul_mod(base, base, mod)
            exp //= 2
        return result

    def mul_inv_prime(self, i, p):
        return self.pow_mod(i, p - 2, p)

    def div_mod_prime(self, i, j, p):
        return self.mul_mod(i, self.mul_inv_prime(j, p), p)

def read_ints():
    return list(map(int, sys.stdin.readline().split()))

def main():
    N, K = read_ints()
    A = [0] + read_ints()  # 1-indexed
    A.append(A[N])  # A[0] = A[N]

    if K == 1:
        print(0)
        return

    comb = Combinatorics(MAXN)
    comb.init(N, MOD)

    cnt = sum(1 for i in range(N) if A[i] != A[i + 1])
    ans = 0

    for i in range(cnt // 2 + 1):
        add = comb.choose(cnt, i, MOD) * comb.choose(cnt - i, i, MOD) % MOD
        add = add * comb.pow_mod(K, N - cnt, MOD) % MOD
        add = add * comb.pow_mod(K - 2, cnt - 2 * i, MOD) % MOD
        ans = (ans + add) % MOD

    ans = (comb.pow_mod(K, N, MOD) - ans + MOD) % MOD
    ans = comb.div_mod_prime(ans, 2, MOD)
    print(ans)

if __name__ == "__main__":
    main()
