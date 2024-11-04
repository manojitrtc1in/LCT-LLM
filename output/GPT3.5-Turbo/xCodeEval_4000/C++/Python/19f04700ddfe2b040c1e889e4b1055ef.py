class Combinatorics:
    def __init__(self, MAXN, T):
        self.fact = [0] * (MAXN + 1)
        self.invFact = [0] * (MAXN + 1)
        self.T = T

    def init(self, N, P=None):
        self.fact[0] = 1
        for i in range(1, N + 1):
            self.fact[i] = self.fact[i - 1] * i
        if P is not None:
            self.invFact[N] = self.mulInvPrime(self.fact[N], P)
            for i in range(N - 1, -1, -1):
                self.invFact[i] = self.mulMod(self.invFact[i + 1], i + 1, P)

    def factorial(self, N):
        return self.fact[N]

    def invFactorial(self, N):
        return self.invFact[N]

    def permute(self, N, K, P=None):
        if P is None:
            return self.fact[N] // self.fact[N - K]
        else:
            return self.mulMod(self.fact[N], self.invFact[N - K], P)

    def choose(self, N, K, P=None):
        if P is None:
            return self.fact[N] // (self.fact[K] * self.fact[N - K])
        else:
            return self.mulMod(self.mulMod(self.fact[N], self.invFact[K], P), self.invFact[N - K], P)

    def multiChoose(self, N, K, P=None):
        if P is None:
            return self.choose(N + K - 1, K)
        else:
            return self.choose(N + K - 1, K, P)

    def mulMod(self, a, b, mod):
        return (a * b) % mod

    def powMod(self, base, pow, mod):
        x = 1
        while pow > 0:
            if pow & 1:
                x = self.mulMod(x, base, mod)
            base = self.mulMod(base, base, mod)
            pow >>= 1
        return x

    def mulInvPrime(self, i, p):
        return self.powMod(i, p - 2, p)


MOD = 998244353
MAXN = 2 * 10**5 + 5

N, K = map(int, input().split())
A = list(map(int, input().split()))
A.append(A[0])
if K == 1:
    print(0)
    exit()
comb = Combinatorics(MAXN, MOD)
comb.init(N)
cnt = sum(A[i] != A[i + 1] for i in range(N))
ans = 0
for i in range(cnt // 2 + 1):
    add = comb.choose(cnt, i) * comb.choose(cnt - i, i) % MOD
    add = add * comb.powMod(K, N - cnt, MOD) % MOD
    add = add * comb.powMod(K - 2, cnt - 2 * i, MOD) % MOD
    ans = (ans + add) % MOD
ans = (comb.powMod(K, N, MOD) - ans + MOD) % MOD
ans = comb.divModPrime(ans, 2, MOD)
print(ans)
