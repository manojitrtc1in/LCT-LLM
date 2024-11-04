import sys
import array

class Bitset:
    def __init__(self, N):
        self.n = (N + 31) // 32
        self.data = array.array('I', [0] * self.n)

    def set(self):
        for i in range(self.n):
            self.data[i] = 0xFFFFFFFF

    def set_pos(self, pos):
        self.data[pos >> 5] |= 1 << (pos & 31)

    def reset(self):
        for i in range(self.n):
            self.data[i] = 0

    def reset_pos(self, pos):
        self.data[pos >> 5] &= ~(1 << (pos & 31))

    def flip(self, pos):
        self.data[pos >> 5] ^= 1 << (pos & 31)

    def test(self, pos):
        return (self.data[pos >> 5] >> (pos & 31)) & 1

    def __ior__(self, other):
        for i in range(self.n):
            self.data[i] |= other.data[i]
        return self

    def __and__(self, other):
        res = Bitset(self.n * 32)
        for i in range(self.n):
            res.data[i] = self.data[i] & other.data[i]
        return res

    def __or__(self, other):
        res = Bitset(self.n * 32)
        for i in range(self.n):
            res.data[i] = self.data[i] | other.data[i]
        return res

    def __xor__(self, other):
        res = Bitset(self.n * 32)
        for i in range(self.n):
            res.data[i] = self.data[i] ^ other.data[i]
        return res

    def count(self):
        return sum(bin(x).count('1') for x in self.data)

    def any(self):
        return any(x != 0 for x in self.data)

    def none(self):
        return all(x == 0 for x in self.data)

    def __eq__(self, other):
        return self.data == other.data

class IG:
    def __init__(self):
        self.good = [Bitset(1004) for _ in range(2004)]
        self.bad = [Bitset(1004) for _ in range(2004)]
        self.bv = [False] * 2004

    @staticmethod
    def get_num(a, n):
        if a > 0:
            return a - 1
        a = -a
        return n + a - 1

    @staticmethod
    def neg(a, n):
        if a < n:
            return a + n
        return a - n

    def add_implication(self, a, b, n):
        a = self.get_num(a, n)
        b = self.get_num(b, n)
        if b < n:
            self.good[a].set_pos(b)
        else:
            self.bad[a].set_pos(b - n)

    def add(self, a, b, n):
        self.add_implication(-a, b, n)
        self.add_implication(-b, a, n)

    def transitive_closure(self, n):
        for i in range(2 * n):
            if i < n:
                self.good[i].set()
            else:
                self.bad[i].set()

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

        for i in range(2 * n):
            if i < n:
                if self.bad[i].test(i):
                    self.bv[i] = True
            else:
                if self.good[i].test(i - n):
                    self.bv[i] = True

        for i in range(2 * n):
            for j in range(2 * n):
                if not self.bv[j]:
                    continue
                if j < n:
                    if self.good[i].test(j):
                        self.bv[i] = True
                else:
                    if self.bad[i].test(j - n):
                        self.bv[i] = True

    def has_solution(self, n):
        for i in range(n):
            if self.bad[i].test(i) and self.good[i + n].test(i):
                return False
        return True

    def select(self, v, n):
        t = v
        if self.num[v] == 0:
            t += n
        if self.bv[t]:
            return False
        k = 0
        self.sof[k] = v
        k += 1
        ok = True
        for i in range(n):
            if self.good[t].test(i):
                if self.num[i] == 0:
                    ok = False
                    break
                if self.num[i] == -1:
                    self.num[i] = 1
                    self.sof[k] = i
                    k += 1
            if self.bad[t].test(i):
                if self.num[i] == 1:
                    ok = False
                    break
                if self.num[i] == -1:
                    self.num[i] = 0
                    self.sof[k] = i
                    k += 1

        if not ok:
            for i in range(k):
                self.num[self.sof[i]] = -1
            return False
        return True

    def print_solution_and_die(self, f1, f2, n):
        self.num = [-1] * 1004
        if f1 != -1:
            if f1 < n:
                self.num[f1] = 1
            else:
                f1 -= n
                self.num[f1] = 0
            self.select(f1, n)
        if f2 != -1:
            if self.num[f2 < n ? f2 : f2 - n] == -1:
                if f2 < n:
                    self.num[f2] = 1
                else:
                    f2 -= n
                    self.num[f2] = 0
                self.select(f2, n)
        for i in range(n):
            if self.num[i] != -1:
                continue
            self.num[i] = 0
            if not self.select(i, n):
                self.num[i] = 1
                self.select(i, n)
        print(" ".join(map(str, self.num)))
        sys.exit(0)

    def check_bad(self, v1, v2):
        t = (self.good[v1] | self.good[v2]) & (self.bad[v1] | self.bad[v2])
        return t.any()

def next_int():
    return int(sys.stdin.readline().strip())

def solve(cl1, cl2, g1, g2, m1, m2):
    used = [[False] * 2002 for _ in range(2002)]
    for i in range(m1):
        v1 = IG.get_num(cl1[i][0], n)
        v2 = IG.get_num(cl1[i][1], n)
        v1 = IG.neg(v1, n)
        v2 = IG.neg(v2, n)
        if v1 > v2:
            v1, v2 = v2, v1
        if used[v1][v2]:
            continue
        used[v1][v2] = True

        if g2.bv[v1] or g2.bv[v2]:
            continue
        if g2.check_bad(v1, v2):
            continue
        g2.print_solution_and_die(v1, v2, n)

n = next_int()
m1 = next_int()
m2 = next_int()
g1 = IG()
g2 = IG()
cl1 = [None] * m1
cl2 = [None] * m2

for i in range(m1):
    a = next_int()
    b = next_int()
    cl1[i] = (a, b)
    g1.add(a, b, n)

for i in range(m2):
    a = next_int()
    b = next_int()
    cl2[i] = (a, b)
    g2.add(a, b, n)

g1.transitive_closure(n)
g2.transitive_closure(n)

r1 = g1.has_solution(n)
r2 = g2.has_solution(n)
if not r1 and not r2:
    print("SIMILAR")
    sys.exit(0)
if not r1:
    g2.print_solution_and_die(-1, -1, n)
if not r2:
    g1.print_solution_and_die(-1, -1, n)

solve(cl1, cl2, g1, g2, m1, m2)
solve(cl2, cl1, g2, g1, m2, m1)
print("SIMILAR")
