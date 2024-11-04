MOD = 998244353
MAXN = 2 * 10**5 + 5

class Combinatorics:
    def __init__(self):
        self.fact = [0] * MAXN
        self.invFact = [0] * MAXN

    def init(self, N, P=None):
        self.fact[0] = 1
        for i in range(1, N + 1):
            self.fact[i] = self.fact[i - 1] * i
        if P is not None:
            self.invFact[N] = self.id6(self.fact[N], P)
            for i in range(N - 1, -1, -1):
                self.invFact[i] = self.invFact[i + 1] * (i + 1) % P

    def factorial(self, N):
        return self.fact[N]

    def invFactorial(self, N):
        return self.invFact[N]

    def permute(self, N, K, P=None):
        if P is None:
            return self.fact[N] // self.fact[N - K]
        else:
            return self.fact[N] * self.invFact[N - K] % P

    def choose(self, N, K, P=None):
        if P is None:
            return self.fact[N] // (self.fact[K] * self.fact[N - K])
        else:
            return self.fact[N] * self.invFact[K] * self.invFact[N - K] % P

    def multiChoose(self, N, K, P=None):
        if P is None:
            return self.choose(N + K - 1, K)
        else:
            return self.choose(N + K - 1, K, P)

    def id6(self, i, p):
        return pow(i, p - 2, p)

def posMod(a, mod):
    ret = -mod < a < mod
    return a if ret else a % mod

def addMod(a, b, mod):
    ret = a + b
    return ret if ret < mod else ret - mod

def subMod(a, b, mod):
    ret = a - b
    return ret if ret >= 0 else ret + mod

def mulMod(a, b, mod):
    return a * b % mod

def powMod(base, pow, mod):
    x = 1
    while pow > 0:
        if pow & 1:
            x = mulMod(x, base, mod)
        base = mulMod(base, base, mod)
        pow >>= 1
    return x

def solve():
    comb = Combinatorics()
    comb.init(N, MOD)

    cnt = 0
    for i in range(N):
        if A[i] != A[i + 1]:
            cnt += 1

    ans = 0
    for i in range(cnt // 2 + 1):
        add = mulMod(comb.choose(cnt, i, MOD), comb.choose(cnt - i, i, MOD), MOD)
        add = mulMod(add, powMod(K, N - cnt, MOD), MOD)
        add = mulMod(add, powMod(K - 2, cnt - 2 * i, MOD), MOD)
        ans = addMod(ans, add, MOD)

    ans = subMod(powMod(K, N, MOD), ans, MOD)
    ans = powMod(ans, 2, MOD)
    print(ans)

if __name__ == "__main__":
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    A.append(A[0])
    if K == 1:
        print(0)
    else:
        solve()
