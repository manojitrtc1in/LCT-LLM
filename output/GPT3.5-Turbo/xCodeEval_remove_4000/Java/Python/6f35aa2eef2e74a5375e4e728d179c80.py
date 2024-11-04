import math
import sys

class F3:
    def __init__(self):
        self.INPUT = ""
        self.isp = []
        self.xcums = []
        self.primes = []
        self.id1 = {}
        self.picache = {}
        self.cumps = []
        self.FP = [2, 3, 5, 7, 11, 13, 17, 19]
        self.M = len(self.FP)
        self.B = 100
        self.cachelimit = 0

    def id0(self, n):
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

        id3 = [3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
        for tp in id3:
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
                if j & -j:
                    pp = i << 5 | magic[(j & -j) * 0x076be629 >> 27]
                    p = 2 * pp + 3
                    if p > n:
                        break
                    ret[pos] = p
                    pos += 1
                    if p * p > n:
                        continue
                    for q in range((p * p - 3) // 2, h + 1, p):
                        isnp[q >> 5] |= 1 << q
                j &= j - 1

        return ret[:pos]

    def id7(self, n):
        assert n >= 4

        self.picache = {}
        self.id1 = {}

        s = int(math.sqrt(n) * self.B)

        self.cachelimit = s
        self.primes = self.id0(s)
        self.xcums = [0] * ((s >> 6) + 1)
        self.isp = [0] * ((s >> 6) + 1)
        for p in self.primes:
            self.isp[p >> 6] |= 1 << p
        for i in range(len(self.xcums) - 1):
            self.xcums[i + 1] = self.xcums[i] + bin(self.isp[i]).count("1")

        self.cumps = []
        b = [True]
        length = 1
        for i in range(self.M):
            length *= self.FP[i]
            c = [False] * length
            for j in range(self.FP[i]):
                c[j * len(b):(j + 1) * len(b)] = b
            for k in range(0, length, self.FP[i]):
                c[k] = False
            cumps = [0] * (length + 1)
            for j in range(length):
                cumps[j + 1] = cumps[j] + (1 if c[j] else 0)
            self.FP[i] = length
            b = c
            self.cumps.append(cumps)

    def sqrt(self, n):
        i = max(0, int(math.sqrt(n)) - 2)
        while i * i <= n:
            i += 1
        return i - 1

    def id6(self, n):
        i = max(0, int(math.pow(n, 1 / 3)) - 2)
        while i * i * i <= n:
            i += 1
        return i - 1

    def pi(self, x):
        if x <= self.cachelimit:
            ix = int(x)
            return self.xcums[ix >> 6] + bin(self.isp[ix >> 6] << ~ix).count("1")

        if x in self.picache:
            return self.picache[x]

        A = self.pi(self.sqrt(self.sqrt(x)))
        ret = A + self.phi(x, A) - self.P2(x, A) - self.P3(x, A) - 1
        self.picache[x] = ret
        return ret

    def phi(self, x, A):
        if A > 0 and A - 1 < self.M:
            return self.cumps[A - 1][self.FP[A - 1]] * (x // self.FP[A - 1]) + self.cumps[A - 1][x % self.FP[A - 1] + 1]
        if A > 0 and x <= self.primes[A - 1] * self.primes[A - 1]:
            return self.pi(x) - A + 1
        code = (x << 13) | A
        if code in self.id1:
            return self.id1[code]

        ret = x
        for i in range(A - 1, -1, -1):
            ret -= self.phi(x // self.primes[i], i)

        if self.cachePhi:
            self.id1[code] = ret
        return ret

    def P2(self, x, A):
        B = self.pi(self.sqrt(x))
        ret = 0
        for i in range(A, B):
            ret += self.pi(x // self.primes[i])
        ret -= (B - A) * (B + A - 1) // 2
        return ret

    def P3(self, x, A):
        C = self.pi(self.id6(x))
        ret = 0
        for i in range(A, C):
            xi = x // self.primes[i]
            B = self.pi(self.sqrt(xi))
            for j in range(i, B):
                ret += self.pi(xi // self.primes[j]) - j
        return ret

    def solve(self):
        n = self.nl()
        ans = 0
        ml = self.id7(n // 2)
        for i in range(len(self.primes)):
            plus = ml.pi(n // self.primes[i]) - (i + 1)
            if plus <= 0:
                break
            ans += plus

        for p in self.primes:
            if p * p * p <= n:
                ans += 1
            else:
                break
        print(ans)

    def run(self):
        self.is = sys.stdin
        self.out = sys.stdout

        s = int(round(time.time() * 1000))
        self.solve()
        self.out.flush()
        print(time.time() * 1000 - s, "ms")

if __name__ == "__main__":
    F3().run()
