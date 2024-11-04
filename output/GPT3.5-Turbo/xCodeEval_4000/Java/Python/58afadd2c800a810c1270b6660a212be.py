import math
import sys
from collections import defaultdict

class F3:
    def __init__(self):
        self.INPUT = "100000000000"
        self.isp = []
        self.xcums = []
        self.primes = []
        self.cumps = []
        self.picache = defaultdict(int)
        self.phicache = defaultdict(int)
        self.cachePhi = False
        self.scale = 1 << 2
        self.rscale = 1 << 1
        self.mask = self.scale - 1
        self.size = 0
        self.allocated = [0] * self.scale
        self.keys = [0] * self.scale

    def sieveEratosthenes(self, n):
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
                j &= j - 1
                pp = (i << 5) | (magic[(j & -j) * 0x076be629 >> 27])
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

    def sqrt(self, n):
        i = max(0, int(math.sqrt(n)) - 2)
        while i * i <= n:
            i += 1
        return i - 1

    def cbrt(self, n):
        i = max(0, int(math.pow(n, 1/3)) - 2)
        while i * i * i <= n:
            i += 1
        return i - 1

    def pi(self, x):
        if x <= self.cachelimit:
            return self.xcums[x >> 6] + bin(self.isp[x >> 6] << ~x).count("1")

        if x in self.picache:
            return self.picache[x]

        A = self.pi(self.sqrt(self.sqrt(x)))
        ret = A + self.phi(x, A) - self.P2(x, A) - self.P3(x, A) - 1
        self.picache[x] = ret
        return ret

    def phi(self, x, A):
        if A > 0 and A - 1 < len(self.primes):
            return self.cumps[A - 1][self.primes[A - 1]] * (x // self.primes[A - 1]) + self.cumps[A - 1][x % self.primes[A - 1] + 1]
        if A > 0 and x <= self.primes[A - 1] * self.primes[A - 1]:
            return self.pi(x) - A + 1

        ret = x
        for i in range(A - 1, -1, -1):
            ret -= self.phi(x // self.primes[i], i)
        return ret

    def P2(self, x, A):
        B = self.pi(self.sqrt(x))
        ret = 0
        for i in range(A, B):
            ret += self.pi(x // self.primes[i])
        ret -= (B - A) * (B + A - 1) // 2
        return ret

    def P3(self, x, A):
        C = self.pi(self.cbrt(x))
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
        ml = self.MeisselLehmer2(n // 2)
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

    class MeisselLehmer2:
        def __init__(self, n):
            self.primes = []
            self.xcums = []
            self.isp = []
            self.cachelimit = 0
            self.picache = defaultdict(int)
            self.phicache = defaultdict(int)
            self.cachePhi = False
            self.cumps = []
            self.FP = [2, 3, 5, 7, 11, 13, 17, 19]
            self.M = len(self.FP)
            self.B = 100

            self.primelist(n)

        def primelist(self, n):
            assert n >= 4

            self.picache = defaultdict(int)
            self.phicache = defaultdict(int)

            s = int(math.sqrt(n)) * self.B

            self.cachelimit = s
            self.primes = self.sieveEratosthenes(s)
            self.xcums = [0] * ((s >> 6) + 1)
            self.isp = [0] * ((s >> 6) + 1)
            for p in self.primes:
                self.isp[p >> 6] |= 1 << p
            for i in range(len(self.xcums) - 1):
                self.xcums[i + 1] = self.xcums[i] + bin(self.isp[i] << ~i).count("1")

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

        def cbrt(self, n):
            i = max(0, int(math.pow(n, 1/3)) - 2)
            while i * i * i <= n:
                i += 1
            return i - 1

        def pi(self, x):
            if x <= self.cachelimit:
                return self.xcums[x >> 6] + bin(self.isp[x >> 6] << ~x).count("1")

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

            ret = x
            for i in range(A - 1, -1, -1):
                ret -= self.phi(x // self.primes[i], i)
            return ret

        def P2(self, x, A):
            B = self.pi(self.sqrt(x))
            ret = 0
            for i in range(A, B):
                ret += self.pi(x // self.primes[i])
            ret -= (B - A) * (B + A - 1) // 2
            return ret

        def P3(self, x, A):
            C = self.pi(self.cbrt(x))
            ret = 0
            for i in range(A, C):
                xi = x // self.primes[i]
                B = self.pi(self.sqrt(xi))
                for j in range(i, B):
                    ret += self.pi(xi // self.primes[j]) - j
            return ret

        def sieveEratosthenes(self, n):
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
                    j &= j - 1
                    pp = (i << 5) | (magic[(j & -j) * 0x076be629 >> 27])
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

    def run(self):
        self.is = sys.stdin
        self.out = sys.stdout

        s = int(round(time.time() * 1000))
        self.solve()
        self.out.flush()
        print(time.time() * 1000 - s, "ms")

    def main(self):
        self.run()

    def readByte(self):
        b = sys.stdin.read(1)
        if not b:
            return -1
        return ord(b)

    def isSpaceChar(self, c):
        return not (c >= 33 and c <= 126)

    def skip(self):
        b = self.readByte()
        while b != -1 and self.isSpaceChar(b):
            b = self.readByte()
        return b

    def nd(self):
        return float(self.ns())

    def nc(self):
        return chr(self.skip())

    def ns(self):
        b = self.skip()
        sb = []
        while not self.isSpaceChar(b):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)

    def ns(self, n):
        buf = [""] * n
        b = self.skip()
        p = 0
        while p < n and not self.isSpaceChar(b):
            buf[p] = chr(b)
            p += 1
            b = self.readByte()
        return buf if n == p else buf[:p]

    def nm(self, n, m):
        map = []
        for i in range(n):
            map.append(self.ns(m))
        return map

    def na(self, n):
        a = []
        for i in range(n):
            a.append(self.ni())
        return a

    def ni(self):
        num = 0
        b = self.readByte()
        minus = False
        while b != -1 and not ((b >= ord("0") and b <= ord("9")) or b == ord("-")):
            b = self.readByte()
        if b == ord("-"):
            minus = True
            b = self.readByte()

        while True:
            if b >= ord("0") and b <= ord("9"):
                num = num * 10 + (b - ord("0"))
            else:
                return -num if minus else num
            b = self.readByte()

    def nl(self):
        num = 0
        b = self.readByte()
        minus = False
        while b != -1 and not ((b >= ord("0") and b <= ord("9")) or b == ord("-")):
            b = self.readByte()
        if b == ord("-"):
            minus = True
            b = self.readByte()

        while True:
            if b >= ord("0") and b <= ord("9"):
                num = num * 10 + (b - ord("0"))
            else:
                return -num if minus else num
            b = self.readByte()

if __name__ == "__main__":
    F3().main()
