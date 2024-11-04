import sys
import math
from collections import defaultdict

class F3:
    def __init__(self):
        self.primes = self.id0(400000)

    @staticmethod
    def id0(n):
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
            for j in range(~isnp[i], 0, j & (j - 1)):
                pp = (i << 5) | magic[(j & -j) * 0x076be629 >> 27]
                p = 2 * pp + 3
                if p > n:
                    break
                ret[pos] = p
                pos += 1
                if p * p > n:
                    continue
                for q in range((p * p - 3) // 2, h + 1, p):
                    isnp[q >> 5] |= 1 << q

        return ret[:pos]

    def solve(self):
        n = self.nl()
        ans = 0
        ml = id7(n // 2)
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
        self.solve()

    def nl(self):
        return int(sys.stdin.readline().strip())

class id7:
    def __init__(self, n):
        assert n >= 4
        self.picache = id4()
        self.id1 = id4()
        s = int(math.sqrt(n)) * 100
        self.cachelimit = s
        self.primes = F3.id0(s)
        self.xcums = [0] * ((s >> 6) + 1)
        self.isp = [0] * ((s >> 6) + 1)
        for p in self.primes:
            self.isp[p >> 6] |= 1 << p
        for i in range(len(self.xcums) - 1):
            self.xcums[i + 1] = self.xcums[i] + bin(self.isp[i]).count('1')

        self.FP = [2, 3, 5, 7, 11, 13, 17, 19]
        self.M = len(self.FP)
        self.cumps = [[] for _ in range(self.M)]
        b = [True]
        length = 1
        for i in range(self.M):
            length *= self.FP[i]
            c = [False] * length
            for j in range(self.FP[i]):
                c[j * len(b):(j + 1) * len(b)] = b
            for k in range(0, length, self.FP[i]):
                c[k] = False
            self.cumps[i] = [0] * (length + 1)
            for j in range(length):
                self.cumps[i][j + 1] = self.cumps[i][j] + (1 if c[j] else 0)
            self.FP[i] = length
            b = c

    def pi(self, x):
        if x <= self.cachelimit:
            ix = int(x)
            return self.xcums[ix >> 6] + bin(self.isp[ix >> 6] << ~ix).count('1')

        if self.picache.containsKey(x):
            return self.picache.get(x)

        A = int(self.pi(math.sqrt(math.sqrt(x))))
        ret = A + self.phi(x, A) - self.P2(x, A) - self.P3(x, A) - 1
        self.picache.put(x, ret)
        return ret

    def phi(self, x, A):
        if A > 0 and A - 1 < self.M:
            return self.cumps[A - 1][self.FP[A - 1]] * (x // self.FP[A - 1]) + self.cumps[A - 1][int(x % self.FP[A - 1] + 1)]
        if A > 0 and x <= self.primes[A - 1] * self.primes[A - 1]:
            return self.pi(x) - A + 1
        code = (x << 13) | A
        if self.id1.containsKey(code):
            return self.id1.get(code)

        ret = x
        for i in range(A - 1, -1, -1):
            ret -= self.phi(x // self.primes[i], i)

        return ret

    def P2(self, x, A):
        B = int(self.pi(math.sqrt(x)))
        ret = 0
        for i in range(A, B):
            ret += self.pi(x // self.primes[i])
        ret -= (B - A) * (B + A - 1) // 2
        return ret

    def P3(self, x, A):
        C = int(self.pi(self.id6(x)))
        ret = 0
        for i in range(A, C):
            xi = x // self.primes[i]
            B = int(self.pi(math.sqrt(xi)))
            for j in range(i, B):
                ret += self.pi(xi // self.primes[j]) - j
        return ret

    @staticmethod
    def id6(n):
        i = max(0, int(n ** (1/3)) - 2)
        while i * i * i <= n:
            i += 1
        return i - 1

class id4:
    def __init__(self):
        self.keys = [0] * (1 << 2)
        self.allocated = [0] * (1 << 2)
        self.scale = 1 << 2
        self.rscale = 1 << 1
        self.mask = self.scale - 1
        self.size = 0
        self.NG = 0

    def containsKey(self, x):
        pos = self.h(x) & self.mask
        while self.allocated[pos] != self.NG:
            if x == self.keys[pos]:
                return True
            pos = (pos + 1) & self.mask
        return False

    def get(self, x):
        pos = self.h(x) & self.mask
        while self.allocated[pos] != self.NG:
            if x == self.keys[pos]:
                return self.allocated[pos]
            pos = (pos + 1) & self.mask
        return self.NG

    def put(self, x, v):
        pos = self.h(x) & self.mask
        while self.allocated[pos] != self.NG:
            if x == self.keys[pos]:
                oldval = self.allocated[pos]
                self.allocated[pos] = v
                return oldval
            pos = (pos + 1) & self.mask
        if self.size == self.rscale:
            self.id5(x, v)
        else:
            self.keys[pos] = x
            self.allocated[pos] = v
        self.size += 1
        return 0

    def id5(self, x, v):
        nscale = self.scale << 1
        nrscale = self.rscale << 1
        nmask = nscale - 1
        nallocated = [0] * nscale
        nkeys = [0] * nscale
        for i in range(self.next(0), self.scale):
            y = self.keys[i]
            pos = self.h(y) & nmask
            while nallocated[pos] != self.NG:
                pos = (pos + 1) & nmask
            nkeys[pos] = y
            nallocated[pos] = self.allocated[i]
        pos = self.h(x) & nmask
        while nallocated[pos] != self.NG:
            pos = (pos + 1) & nmask
        nkeys[pos] = x
        nallocated[pos] = v
        self.allocated = nallocated
        self.keys = nkeys
        self.scale = nscale
        self.rscale = nrscale
        self.mask = nmask

    def next(self, itr):
        while itr < self.scale and self.allocated[itr] == self.NG:
            itr += 1
        return itr

    def h(self, x):
        x ^= x >> 33
        x *= 0xff51afd7ed558ccd
        x ^= x >> 33
        x *= 0xc4ceb9fe1a85ec53
        x ^= x >> 33
        return int(x)

if __name__ == "__main__":
    F3().run()
