import math
import sys

class F3:
    def __init__(self):
        self.INPUT = ""
        self.isp = []
        self.xcums = []
        self.primes = []
        self.magic = []
        self.id3 = []
        self.id7 = None
        self.picache = None
        self.id1 = None
        self.cumps = []
        self.FP = []
        self.M = 0
        self.B = 0
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

        for tp in self.id3:
            ret[pos] = tp
            pos += 1
            ptn = [0] * tp
            for i in range((tp - 3) // 2, tp << 5, tp):
                ptn[i >> 5] |= 1 << (i & 31)
            for j in range(0, sup, tp):
                for i in range(tp):
                    if i + j < sup:
                        isnp[j + i] |= ptn[i]

        h = n // 2
        for i in range(sup):
            for j in range(~isnp[i] & -isnp[i]):
                pp = i << 5 | self.magic[(j * 0x076be629) >> 27]
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
        if n <= 10:
            if n >= 6:
                ans += 1
            if n >= 8:
                ans += 1
            if n >= 10:
                ans += 1
            print(ans)
            return

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

    class id7:
        def __init__(self, n):
            self.primes = []
            self.xcums = []
            self.isp = []
            self.cachelimit = 0
            self.picache = None
            self.id1 = None
            self.cachePhi = False
            self.cumps = []
            self.FP = []
            self.M = 0
            self.B = 0

            assert n >= 4

            self.picache = self.id4()
            self.id1 = self.id4()

            s = int(math.sqrt(n)) * self.B

            self.cachelimit = s
            self.primes = self.id0(s)
            self.xcums = [0] * ((s >> 6) + 1)
            self.isp = [0] * ((s >> 6) + 1)
            for p in self.primes:
                self.isp[p >> 6] |= 1 << p
            for i in range(len(self.xcums) - 1):
                self.xcums[i + 1] = self.xcums[i] + bin(self.isp[i]).count('1')

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
            i = max(0, int(math.id6(n)) - 2)
            while i * i * i <= n:
                i += 1
            return i - 1

        def pi(self, x):
            if x <= self.cachelimit:
                ix = int(x)
                return self.xcums[ix >> 6] + bin(self.isp[ix >> 6] << ~ix).count('1')

            if self.picache.containsKey(x):
                return self.picache.get(x)

            A = self.pi(self.sqrt(self.sqrt(x)))
            ret = A + self.phi(x, A) - self.P2(x, A) - self.P3(x, A) - 1
            self.picache.put(x, ret)
            return ret

        def phi(self, x, A):
            if 0 < A - 1 < self.M:
                return self.cumps[A - 1][self.FP[A - 1]] * (x // self.FP[A - 1]) + self.cumps[A - 1][int(x % self.FP[A - 1] + 1)]
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
            C = self.pi(self.id6(x))
            ret = 0
            for i in range(A, C):
                xi = x // self.primes[i]
                B = self.pi(self.sqrt(xi))
                for j in range(i, B):
                    ret += self.pi(xi // self.primes[j]) - j
            return ret

        class id4:
            def __init__(self):
                self.keys = []
                self.allocated = []
                self.scale = 1 << 2
                self.rscale = 1 << 1
                self.mask = self.scale - 1
                self.size = 0

                self.allocated = [0] * self.scale
                self.keys = [0] * self.scale

            def containsKey(self, x):
                pos = self.h(x) & self.mask
                while self.allocated[pos] != 0:
                    if x == self.keys[pos]:
                        return True
                    pos = (pos + 1) & self.mask
                return False

            def get(self, x):
                pos = self.h(x) & self.mask
                while self.allocated[pos] != 0:
                    if x == self.keys[pos]:
                        return self.allocated[pos]
                    pos = (pos + 1) & self.mask
                return 0

            def put(self, x, v):
                pos = self.h(x) & self.mask
                while self.allocated[pos] != 0:
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

            def inc(self, x, v):
                pos = self.h(x) & self.mask
                while self.allocated[pos] != 0:
                    if x == self.keys[pos]:
                        self.allocated[pos] += v
                        return self.allocated[pos]
                    pos = (pos + 1) & self.mask
                if self.size == self.rscale:
                    self.id5(x, v)
                else:
                    self.keys[pos] = x
                    self.allocated[pos] = v
                self.size += 1
                return v

            def remove(self, x):
                pos = self.h(x) & self.mask
                while self.allocated[pos] != 0:
                    if x == self.keys[pos]:
                        self.size -= 1

                        last = pos
                        pos = (pos + 1) & self.mask
                        while self.allocated[pos] != 0:
                            lh = self.h(self.keys[pos]) & self.mask

                            if lh <= last < pos or pos < lh <= last or last < pos < lh:
                                self.keys[last] = self.keys[pos]
                                self.allocated[last] = self.allocated[pos]
                                last = pos
                            pos = (pos + 1) & self.mask
                        self.keys[last] = 0
                        self.allocated[last] = 0

                        return True
                    pos = (pos + 1) & self.mask
                return False

            def id5(self, x, v):
                nscale = self.scale << 1
                nrscale = self.rscale << 1
                nmask = nscale - 1
                nallocated = [0] * nscale
                nkeys = [0] * nscale
                for i in self.next(0):
                    y = self.keys[i]
                    pos = self.h(y) & nmask
                    while nallocated[pos] != 0:
                        pos = (pos + 1) & nmask
                    nkeys[pos] = y
                    nallocated[pos] = self.allocated[i]

                pos = self.h(x) & nmask
                while nallocated[pos] != 0:
                    pos = (pos + 1) & nmask
                nkeys[pos] = x
                nallocated[pos] = v

                self.allocated = nallocated
                self.keys = nkeys
                self.scale = nscale
                self.rscale = nrscale
                self.mask = nmask

            def next(self, itr):
                while itr < self.scale and self.allocated[itr] == 0:
                    itr += 1
                return itr

            def h(self, x):
                x ^= x >> 33
                x *= 0xff51afd7ed558ccd
                x ^= x >> 33
                x *= 0xc4ceb9fe1a85ec53
                x ^= x >> 33
                return int(x)

            def __str__(self):
                sb = []
                for i in self.next(0):
                    sb.append(",")
                    sb.append(str(self.keys[i]) + ":" + str(self.allocated[i]))
                return "" if len(sb) == 0 else sb[1:]

    def run(self):
        self.is = sys.stdin
        self.out = sys.stdout

        self.solve()
        self.out.flush()

    def main(self):
        self.run()

    def readByte(self):
        c = sys.stdin.read(1)
        return -1 if not c else ord(c)

    def id2(self, c):
        return not (33 <= c <= 126)

    def skip(self):
        b = self.readByte()
        while b != -1 and not self.id2(b):
            b = self.readByte()
        return b

    def nd(self):
        return float(self.ns())

    def nc(self):
        return chr(self.skip())

    def ns(self):
        b = self.skip()
        sb = []
        while not self.id2(b):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)

    def ns(self, n):
        buf = [0] * n
        b = self.skip()
        p = 0
        while p < n and not self.id2(b):
            buf[p] = chr(b)
            p += 1
            b = self.readByte()
        return buf if n == p else buf[:p]

    def nm(self, n, m):
        return [self.ns(m) for _ in range(n)]

    def na(self, n):
        return [int(x) for x in self.ns().split()]

    def ni(self):
        num = 0
        b = self.readByte()
        minus = False
        while b != -1 and not (48 <= b <= 57 or b == 45):
            b = self.readByte()
        if b == 45:
            minus = True
            b = self.readByte()

        while 48 <= b <= 57:
            num = num * 10 + (b - 48)
            b = self.readByte()
        return -num if minus else num

    def nl(self):
        num = 0
        b = self.readByte()
        minus = False
        while b != -1 and not (48 <= b <= 57 or b == 45):
            b = self.readByte()
        if b == 45:
            minus = True
            b = self.readByte()

        while 48 <= b <= 57:
            num = num * 10 + (b - 48)
            b = self.readByte()
        return -num if minus else num

    def tr(self, *o):
        if not self.oj:
            print(*o)

if __name__ == "__main__":
    F3().main()
