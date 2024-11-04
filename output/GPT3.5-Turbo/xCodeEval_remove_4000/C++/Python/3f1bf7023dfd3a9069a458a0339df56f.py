class Bitset:
    def __init__(self, N):
        self.N = N
        self.n = (N + 31) // 32
        self.data = [0] * self.n

    def set(self):
        for i in range(self.n):
            self.data[i] = 0xFFFFFFFF

    def set_bit(self, pos):
        self.data[pos >> 5] |= 1 << (pos & 31)

    def reset(self):
        for i in range(self.n):
            self.data[i] = 0

    def reset_bit(self, pos):
        self.data[pos >> 5] &= ~(1 << (pos & 31))

    def flip_bit(self, pos):
        self.data[pos >> 5] ^= 1 << (pos & 31)

    def test_bit(self, pos):
        return (self.data[pos >> 5] >> (pos & 31)) & 1

    def operator_or(self, other):
        res = Bitset(self.N)
        for i in range(self.n):
            res.data[i] = self.data[i] | other.data[i]
        return res

    def operator_and(self, other):
        res = Bitset(self.N)
        for i in range(self.n):
            res.data[i] = self.data[i] & other.data[i]
        return res

    def operator_xor(self, other):
        res = Bitset(self.N)
        for i in range(self.n):
            res.data[i] = self.data[i] ^ other.data[i]
        return res

    def operator_lshift(self, shift):
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

    def operator_rshift(self, shift):
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
        return sum(bin(x).count('1') for x in self.data)

    def none(self):
        return all(x == 0 for x in self.data)

    def any(self):
        return any(x != 0 for x in self.data)

    def ctz(self):
        for i, x in enumerate(self.data):
            if x != 0:
                return i * 32 + bin(x).count('0')
        return self.N

    def clz(self):
        for i in range(self.n - 1, -1, -1):
            if self.data[i] != 0:
                return (self.n - i - 1) * 32 + bin(self.data[i]).count('0')
        return self.N

    def __eq__(self, other):
        return self.data == other.data

    def __lt__(self, other):
        return self.data < other.data

    def __gt__(self, other):
        return self.data > other.data

    def __le__(self, other):
        return self.data <= other.data

    def __ge__(self, other):
        return self.data >= other.data

    def __ne__(self, other):
        return self.data != other.data


class IG:
    def __init__(self, n):
        self.n = n
        self.good = [Bitset(1004) for _ in range(2004)]
        self.bad = [Bitset(1004) for _ in range(2004)]
        self.bv = [False] * 2004

    @staticmethod
    def get_num(a):
        if a > 0:
            return a - 1
        a = -a
        return n + a - 1

    @staticmethod
    def neg(a):
        if a < n:
            return a + n
        return a - n

    def add_implication(self, a, b):
        a = self.get_num(a)
        b = self.get_num(b)
        if b < n:
            self.good[a].set_bit(b)
        else:
            self.bad[a].set_bit(b - n)

    def add(self, a, b):
        self.add_implication(-a, b)
        self.add_implication(-b, a)

    def transitive_closure(self):
        for i in range(2 * n):
            if i < n:
                self.good[i].set_bit(i)
            else:
                self.bad[i].set_bit(i - n)

        for mid in range(2 * n):
            for i in range(2 * n):
                if mid < n:
                    if self.good[i].test_bit(mid):
                        self.good[i] |= self.good[mid]
                        self.bad[i] |= self.bad[mid]
                else:
                    if self.bad[i].test_bit(mid - n):
                        self.good[i] |= self.good[mid]
                        self.bad[i] |= self.bad[mid]

        for i in range(n):
            if self.bad[i].test_bit(i) and self.good[i + n].test_bit(i):
                return False

        return True

    def has_solution(self):
        for i in range(n):
            if self.bad[i].test_bit(i) and self.good[i + n].test_bit(i):
                return False
        return True

    def select(self, v):
        t = v
        if self.num[v] == 0:
            t += n
        if self.bv[t]:
            return False
        k = 0
        sof = [0] * 1004
        sof[k] = v
        ok = True
        for i in range(n):
            if self.good[t].test_bit(i):
                if self.num[i] == 0:
                    ok = False
                    break
                if self.num[i] == -1:
                    self.num[i] = 1
                    k += 1
                    sof[k] = i
            if self.bad[t].test_bit(i):
                if self.num[i] == 1:
                    ok = False
                    break
                if self.num[i] == -1:
                    self.num[i] = 0
                    k += 1
                    sof[k] = i

        if not ok:
            for i in range(k + 1):
                self.num[sof[i]] = -1
            return False
        return True

    def print_solution_and_die(self, f1, f2):
        self.num = [-1] * 1004
        if f1 != -1:
            if f1 < n:
                self.num[f1] = 1
            else:
                f1 -= n
                self.num[f1] = 0
            self.select(f1)
        if f2 != -1:
            if self.num[f2 < n ? f2 : f2 - n] == -1:
                if f2 < n:
                    self.num[f2] = 1
                else:
                    f2 -= n
                    self.num[f2] = 0
                self.select(f2)
        for i in range(n):
            if self.num[i] == -1:
                self.num[i] = 0
                if not self.select(i):
                    self.num[i] = 1
                    self.select(i)
        for i in range(n):
            if i:
                print(" ", end="")
            print(self.num[i], end="")
        print()
        exit(0)


def solve(cl1, cl2, g1, g2, m1, m2):
    used = [[False] * 2002 for _ in range(2002)]
    for i in range(m1):
        v1 = IG.get_num(cl1[i][0])
        v2 = IG.get_num(cl1[i][1])
        v1 = IG.neg(v1)
        v2 = IG.neg(v2)
        if v1 > v2:
            v1, v2 = v2, v1
        if used[v1][v2]:
            continue
        used[v1][v2] = True
        if g2.bv[v1] or g2.bv[v2]:
            continue
        if g2.check_bad(v1, v2):
            continue
        g2.print_solution_and_die(v1, v2)


n, m1, m2 = map(int, input().split())
cl1 = []
cl2 = []
g1 = IG(n)
g2 = IG(n)
for _ in range(m1):
    a, b = map(int, input().split())
    cl1.append((a, b))
    g1.add(a, b)
for _ in range(m2):
    a, b = map(int, input().split())
    cl2.append((a, b))
    g2.add(a, b)
g1.transitive_closure()
g2.transitive_closure()
r1 = g1.has_solution()
r2 = g2.has_solution()
if not r1 and not r2:
    print("SIMILAR")
    exit(0)
if not r1:
    g2.print_solution_and_die(-1, -1)
if not r2:
    g1.print_solution_and_die(-1, -1)
solve(cl1, cl2, g1, g2, m1, m2)
solve(cl2, cl1, g2, g1, m2, m1)
print("SIMILAR")
