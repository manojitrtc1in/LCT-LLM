import math

def divsieve(n):
    K = 1 if n == 1 else int(math.pow(n, 2/3))
    primes = sieveEratosthenes(int(math.sqrt(n)))
    qs = []
    dfs1(n, 0, K, qs, primes)
    return None

ct = 0

def dfs1(n, prev, K, qs, primes):
    global ct
    if n < K:
        qs.append((n << 32) | prev)
        if len(qs) % 100000 == 0:
            print(len(qs))
        ct += 1
        if ct % 1000000 == 0:
            print(ct)
    else:
        u = binarySearch(primes, int(math.sqrt(n)))
        if u < 0:
            u = -u - 2
        for i in range(u, -1, -1):
            dfs1(n // primes[i], i, K, qs, primes)

def sieveEratosthenes(n):
    if n <= 32:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
        for i in range(len(primes)):
            if n < primes[i]:
                return primes[:i]
        return primes

    u = n + 32
    lu = math.log(u)
    ret = [0] * int(u / lu + u / lu / lu * 1.5)
    ret[0] = 2
    pos = 1

    isnp = [0] * ((n + 1) // 32 // 2 + 1)
    sup = (n + 1) // 32 // 2 + 1

    tprimes = [3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
    for tp in tprimes:
        ret[pos] = tp
        pos += 1
        ptn = [0] * tp
        for i in range((tp - 3) // 2, tp << 5, tp):
            ptn[i >> 5] |= 1 << (i & 31)
        for j in range(0, sup, tp):
            for i in range(tp):
                if i + j < sup:
                    isnp[j + i] |= ptn[i]

    magic = [0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14]
    h = n // 2
    for i in range(sup):
        j = ~isnp[i]
        while j != 0:
            pp = (i << 5) | magic[(j & -j) * 0x076be629 >> 27]
            p = 2 * pp + 3
            if p > n:
                break
            ret[pos] = p
            pos += 1
            if p * p > n:
                continue
            q = (p * p - 3) // 2
            while q <= h:
                isnp[q >> 5] |= 1 << q
                q += p

    return ret[:pos]

primes = sieveEratosthenes(1000000)

def solve():
    n = nl()
    ans = 0
    ml = MeisselLehmer2(n)
    for i in range(len(primes)):
        plus = ml.pi(n // primes[i]) - (i + 1)
        if plus <= 0:
            break
        ans += plus

    for p in primes:
        if p * p * p <= n:
            ans += 1
        else:
            break
    print(ans)

class MeisselLehmer2:
    def __init__(self, n):
        assert n >= 4
        self.picache = {}
        self.phicache = {}
        s = int(math.sqrt(n)) * B
        self.cachelimit = s
        self.primes = sieveEratosthenes(s)
        self.xcums = [0] * ((s >> 6) + 1)
        self.isp = [0] * ((s >> 6) + 1)
        for p in self.primes:
            self.isp[p >> 6] |= 1 << p
        for i in range(len(self.xcums) - 1):
            self.xcums[i + 1] = self.xcums[i] + bin(self.isp[i]).count('1')
        self.cumps = []
        b = [True]
        length = 1
        for i in range(M):
            length *= FP[i]
            c = [False] * length
            for j in range(FP[i]):
                c[j * len(b):(j + 1) * len(b)] = b
            for k in range(0, length, FP[i]):
                c[k] = False
            cumps.append([0] * (length + 1))
            for j in range(length):
                cumps[i][j + 1] = cumps[i][j] + (1 if c[j] else 0)
            FP[i] = length
            b = c

    def sqrt(self, n):
        i = max(0, int(math.sqrt(n)) - 2)
        while i * i <= n:
            i += 1
        return i - 1

    def cbrt(self, n):
        i = max(0, int(math.cbrt(n)) - 2)
        while i * i * i <= n:
            i += 1
        return i - 1

    def pi(self, x):
        if x <= self.cachelimit:
            ix = int(x)
            return self.xcums[ix >> 6] + bin(self.isp[ix >> 6] << ~ix).count('1')
        if x in self.picache:
            return self.picache[x]
        A = self.pi(self.sqrt(self.sqrt(x)))
        ret = A + self.phi(x, A) - self.P2(x, A) - self.P3(x, A) - 1
        self.picache[x] = ret
        return ret

    def phi(self, x, A):
        if A > 0 and A - 1 < M:
            return self.cumps[A - 1][FP[A - 1]] * (x // FP[A - 1]) + self.cumps[A - 1][int(x % FP[A - 1] + 1)]
        if A > 0 and x <= primes[A - 1] * primes[A - 1]:
            return self.pi(x) - A + 1
        code = (x << 13) | A
        if code in self.phicache:
            return self.phicache[code]
        ret = x
        for i in range(A - 1, -1, -1):
            ret -= self.phi(x // primes[i], i)
        if cachePhi:
            self.phicache[code] = ret
        return ret

    def P2(self, x, A):
        B = self.pi(self.sqrt(x))
        ret = 0
        for i in range(A, B):
            ret += self.pi(x // primes[i])
        ret -= (B - A) * (B + A - 1) // 2
        return ret

    def P3(self, x, A):
        C = self.pi(self.cbrt(x))
        ret = 0
        for i in range(A, C):
            xi = x // primes[i]
            B = self.pi(self.sqrt(xi))
            for j in range(i, B):
                ret += self.pi(xi // primes[j]) - j
        return ret

def nl():
    return int(input())

def run():
    solve()

run()
