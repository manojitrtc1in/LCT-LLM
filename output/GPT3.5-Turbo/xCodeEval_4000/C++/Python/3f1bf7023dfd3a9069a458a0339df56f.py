class Bitset:
    def __init__(self, N):
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

    def __or__(self, other):
        res = Bitset(len(self.data) * 32)
        for i in range(self.n):
            res.data[i] = self.data[i] | other.data[i]
        return res

    def __and__(self, other):
        res = Bitset(len(self.data) * 32)
        for i in range(self.n):
            res.data[i] = self.data[i] & other.data[i]
        return res

    def __xor__(self, other):
        res = Bitset(len(self.data) * 32)
        for i in range(self.n):
            res.data[i] = self.data[i] ^ other.data[i]
        return res

    def __lshift__(self, shift):
        res = Bitset(len(self.data) * 32)
        full = shift >> 5
        if full >= self.n:
            return res
        if full:
            res.data[full:] = self.data[:-full]
            res.data[:full] = [0] * full

        shift &= 31
        if shift:
            for i in range(len(res.data) - 1, 0, -1):
                res.data[i] = (res.data[i] << shift) | (res.data[i - 1] >> (32 - shift))
            res.data[0] <<= shift

        return res

    def __rshift__(self, shift):
        res = Bitset(len(self.data) * 32)
        full = shift >> 5
        if full >= self.n:
            return res
        if full:
            res.data[:-full] = self.data[full:]
            res.data[-full:] = [0] * full

        shift &= 31
        if shift:
            for i in range(len(res.data) - 1):
                res.data[i] = (res.data[i] >> shift) | (res.data[i + 1] << (32 - shift))
            res.data[-1] >>= shift

        return res

    def count(self):
        count = 0
        for i in range(self.n):
            count += bin(self.data[i]).count('1')
        return count

    def none(self):
        for i in range(self.n):
            if self.data[i] != 0:
                return False
        return True

    def any(self):
        for i in range(self.n):
            if self.data[i] != 0:
                return True
        return False

    def __eq__(self, other):
        return self.data == other.data

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
    def __init__(self, n):
        self.good = [Bitset(2 * n) for _ in range(2 * n)]
        self.bad = [Bitset(2 * n) for _ in range(2 * n)]
        self.bv = [False] * (2 * n)

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
            self.good[a].set_bit(b)
        else:
            self.bad[a].set_bit(b - n)

    def add(self, a, b, n):
        self.add_implication(-a, b, n)
        self.add_implication(-b, a, n)

    def transitive_closure(self, n):
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

        for i in range(2 * n):
            if i < n:
                if self.bad[i].test_bit(i) and self.good[i + n].test_bit(i):
                    return False
            else:
                if self.good[i].test_bit(i - n) and self.bad[i - n].test_bit(i):
                    return False

        return True

    def has_solution(self, n):
        return self.transitive_closure(n)

    def select(self, v, n):
        t = v
        if num[v] == 0:
            t += n
        if self.bv[t]:
            return False
        k = 0
        sof = [0] * n
        sof[k] = v
        ok = True
        for i in range(n):
            if self.good[t].test_bit(i):
                if num[i] == 0:
                    ok = False
                    break
                if num[i] == -1:
                    num[i] = 1
                    k += 1
                    sof[k] = i
            if self.bad[t].test_bit(i):
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

    def print_solution_and_die(self, f1, f2, n):
        num = [-1] * n
        if f1 != -1:
            if f1 < n:
                num[f1] = 1
            else:
                f1 -= n
                num[f1] = 0
            self.select(f1, n)
        if f2 != -1:
            if num[f2 < n ? f2 : f2 - n] == -1:
                if f2 < n:
                    num[f2] = 1
                else:
                    f2 -= n
                    num[f2] = 0
                self.select(f2, n)
        for i in range(n):
            if num[i] == -1:
                num[i] = 0
                if not self.select(i, n):
                    num[i] = 1
                    self.select(i, n)
        return num


def solve(cl1, cl2, g1, g2, m1, m2, n):
    used = [[False] * (2 * n) for _ in range(2 * n)]
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


n, m1, m2 = map(int, input().split())
cl1 = []
cl2 = []
for _ in range(m1):
    a, b = map(int, input().split())
    cl1.append((a, b))
for _ in range(m2):
    a, b = map(int, input().split())
    cl2.append((a, b))

g1 = IG(n)
g2 = IG(n)

for a, b in cl1:
    g1.add(a, b, n)
for a, b in cl2:
    g2.add(a, b, n)

g1.transitive_closure(n)
g2.transitive_closure(n)

r1 = g1.has_solution(n)
r2 = g2.has_solution(n)

if not r1 and not r2:
    print("SIMILAR")
    exit(0)
if not r1:
    g2.print_solution_and_die(-1, -1, n)
if not r2:
    g1.print_solution_and_die(-1, -1, n)

solve(cl1, cl2, g1, g2, m1, m2, n)
solve(cl2, cl1, g2, g1, m2, m1, n)

print("SIMILAR")
