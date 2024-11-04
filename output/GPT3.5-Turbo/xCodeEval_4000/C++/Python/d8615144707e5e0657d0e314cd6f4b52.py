class Bitset:
    def __init__(self):
        self.n = (N + 31) // 32
        self.data = [0] * self.n

    def set(self):
        for i in range(self.n):
            self.data[i] = 0xFFFFFFFF

    def set(self, pos):
        self.data[pos >> 5] |= 1 << (pos & 31)

    def reset(self):
        for i in range(self.n):
            self.data[i] = 0

    def reset(self, pos):
        self.data[pos >> 5] &= ~(1 << (pos & 31))

    def flip(self, pos):
        self.data[pos >> 5] ^= 1 << (pos & 31)

    def test(self, pos):
        return (self.data[pos >> 5] >> (pos & 31)) & 1

    def __ior__(self, other):
        for i in range(self.n):
            self.data[i] |= other.data[i]
        return self

    def __or__(self, other):
        res = Bitset()
        for i in range(self.n):
            res.data[i] = self.data[i] | other.data[i]
        return res

    def __iand__(self, other):
        for i in range(self.n):
            self.data[i] &= other.data[i]
        return self

    def __and__(self, other):
        res = Bitset()
        for i in range(self.n):
            res.data[i] = self.data[i] & other.data[i]
        return res

    def __ixor__(self, other):
        for i in range(self.n):
            self.data[i] ^= other.data[i]
        return self

    def __xor__(self, other):
        res = Bitset()
        for i in range(self.n):
            res.data[i] = self.data[i] ^ other.data[i]
        return res

    def __lshift__(self, shift):
        full = shift >> 5
        if full >= self.n:
            self.reset()
            return self
        if full:
            self.data[full:] = self.data[:-full]
            self.data[:full] = [0] * full

        shift &= 31
        if shift:
            for i in range(self.n - 1, 0, -1):
                self.data[i] = (self.data[i] << shift) | (self.data[i - 1] >> (32 - shift))
            self.data[0] <<= shift

        return self

    def __rshift__(self, shift):
        full = shift >> 5
        if full >= self.n:
            self.reset()
            return self
        if full:
            self.data[:-full] = self.data[full:]
            self.data[-full:] = [0] * full

        shift &= 31
        if shift:
            u = (1 << shift) - 1
            for i in range(self.n - 1):
                self.data[i] = (self.data[i] >> shift) | ((self.data[i + 1] & u) << (32 - shift))
            self.data[-1] >>= shift

        return self

    def count(self):
        ans = 0
        for i in range(self.n):
            ans += bin(self.data[i]).count('1')
        return ans

    def none(self):
        for i in range(self.n):
            if self.data[i] != 0:
                return False
        return True

    def any(self):
        return not self.none()

    def ctz(self):
        for i in range(self.n):
            if self.data[i] != 0:
                return bin(self.data[i]).count('0')
        return 32

    def clz(self):
        for i in range(self.n - 1, -1, -1):
            if self.data[i] != 0:
                return bin(self.data[i]).rindex('1')
        return 32

    def __eq__(self, other):
        for i in range(self.n):
            if self.data[i] != other.data[i]:
                return False
        return True

    def __lt__(self, other):
        for i in range(self.n):
            if self.data[i] != other.data[i]:
                return self.data[i] < other.data[i]
        return False

    def __gt__(self, other):
        for i in range(self.n):
            if self.data[i] != other.data[i]:
                return self.data[i] > other.data[i]
        return False

    def __le__(self, other):
        return not self.__gt__(other)

    def __ge__(self, other):
        return not self.__lt__(other)

    def __ne__(self, other):
        return not self.__eq__(other)


class IG:
    def __init__(self):
        self.good = [Bitset() for _ in range(2004)]
        self.bad = [Bitset() for _ in range(2004)]
        self.bv = [False] * 2004

    @staticmethod
    def getNum(a):
        if a > 0:
            return a - 1
        a = -a
        return n + a - 1

    @staticmethod
    def neg(a):
        if a < n:
            return a + n
        return a - n

    def addImplication(self, a, b):
        a = self.getNum(a)
        b = self.getNum(b)
        if b < n:
            self.good[a].set(b)
        else:
            self.bad[a].set(b - n)

    def add(self, a, b):
        self.addImplication(-a, b)
        self.addImplication(-b, a)

    def transitiveClosure(self):
        for i in range(2 * n):
            if i < n:
                self.good[i].set(i)
            else:
                self.bad[i].set(i - n)
        for mid in range(2 * n):
            for i in range(2 * n):
                ok = False
                if mid < n:
                    if self.good[i].test(mid):
                        ok = True
                else:
                    if self.bad[i].test(mid - n):
                        ok = True
                if ok:
                    self.good[i] |= self.good[mid]
                    self.bad[i] |= self.bad[mid]

        for i in range(n):
            if self.bad[i].test(i) and self.good[i + n].test(i):
                return False
        return True

    def hasSolution(self):
        for i in range(n):
            if self.bad[i].test(i) and self.good[i + n].test(i):
                return False
        return True

    def select(self, v):
        t = v
        if num[v] == 0:
            t += n
        if self.bv[t]:
            return False
        k = 0
        sof = [0] * 1004
        sof[k] = v
        ok = True
        for i in range(n):
            if self.good[t].test(i):
                if num[i] == 0:
                    ok = False
                    break
                if num[i] == -1:
                    num[i] = 1
                    k += 1
                    sof[k] = i
            if self.bad[t].test(i):
                if num[i] == 1:
                    ok = False
                    break
                if num[i] == -1:
                    num[i] = 0
                    k += 1
                    sof[k] = i

        if not ok:
            for i in range(k + 1):
                num[sof[i]] = -1
            return False
        return True

    def printSolutionAndDie(self, f1, f2):
        num = [-1] * 1004
        if f1 != -1:
            if f1 < n:
                num[f1] = 1
            else:
                f1 -= n
                num[f1] = 0
            self.select(f1)
        if f2 != -1:
            if num[f2 < n ? f2 : f2 - n] == -1:
                if f2 < n:
                    num[f2] = 1
                else:
                    f2 -= n
                    num[f2] = 0
                self.select(f2)
        for i in range(n):
            if num[i] == -1:
                num[i] = 0
                if not self.select(i):
                    num[i] = 1
                    self.select(i)
        for i in range(n):
            if i:
                print(" ", end="")
            print(num[i], end="")
        print()
        exit(0)


def solve(cl1, cl2, g1, g2, m1, m2):
    used = [[False] * 2002 for _ in range(2002)]
    for i in range(m1):
        v1 = IG.getNum(cl1[i][0])
        v2 = IG.getNum(cl1[i][1])
        v1 = IG.neg(v1)
        v2 = IG.neg(v2)
        if v1 > v2:
            v1, v2 = v2, v1
        if used[v1][v2]:
            continue
        used[v1][v2] = True

        if g2.bv[v1] or g2.bv[v2]:
            continue
        if g2.checkBad(v1, v2):
            continue
        g2.printSolutionAndDie(v1, v2)


n, m1, m2 = map(int, input().split())
cl1 = []
cl2 = []
g1 = IG()
g2 = IG()
for _ in range(m1):
    a, b = map(int, input().split())
    cl1.append((a, b))
    g1.add(a, b)
for _ in range(m2):
    a, b = map(int, input().split())
    cl2.append((a, b))
    g2.add(a, b)
g1.transitiveClosure()
g2.transitiveClosure()

r1 = g1.hasSolution()
r2 = g2.hasSolution()
if not r1 and not r2:
    print("SIMILAR")
    exit(0)
if not r1:
    g2.printSolutionAndDie(-1, -1)
if not r2:
    g1.printSolutionAndDie(-1, -1)
solve(cl1, cl2, g1, g2, m1, m2)
solve(cl2, cl1, g2, g1, m2, m1)
print("SIMILAR")
