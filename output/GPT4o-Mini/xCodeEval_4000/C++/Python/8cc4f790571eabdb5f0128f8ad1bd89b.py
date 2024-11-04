import sys
from fractions import Fraction
from collections import defaultdict
from itertools import accumulate

def setIO(s=""):
    if s:
        sys.stdin = open(s + ".in", "r")
        sys.stdout = open(s + ".out", "w")
    sys.stdin, sys.stdout = sys.stdin, sys.stdout

class ModNum:
    MOD = 998244353

    def __init__(self, v=0):
        self.v = v % self.MOD
        if self.v < 0:
            self.v += self.MOD

    def __int__(self):
        return self.v

    def __add__(self, other):
        return ModNum(self.v + other.v)

    def __sub__(self, other):
        return ModNum(self.v - other.v)

    def __mul__(self, other):
        return ModNum(self.v * other.v)

    def __truediv__(self, other):
        return self * other.inv()

    def inv(self):
        return pow(self.v, self.MOD - 2, self.MOD)

    @staticmethod
    def small_inv(n):
        return ModNum(factorial(n - 1) * inverse_factorial(n))

    @staticmethod
    def factorial(n):
        if n == 0:
            return ModNum(1)
        res = ModNum(1)
        for i in range(2, n + 1):
            res *= ModNum(i)
        return res

    @staticmethod
    def inverse_factorial(n):
        return ModNum(1) / ModNum.factorial(n)

class SegmentTree:
    def __init__(self, size, id_val, merge_func):
        self.SZ = size
        self.id = id_val
        self.merge = merge_func
        self.table = [id_val] * (2 * size)

    def set_leaves(self, create):
        for i in range(self.SZ):
            self.table[self.SZ + i] = create(i)
        for i in range(self.SZ - 1, 0, -1):
            self.table[i] = self.merge(self.table[2 * i], self.table[2 * i + 1])

    def replace(self, i, v):
        self.table[i + self.SZ] = v
        for i in range(i // 2, 0, -1):
            self.table[i] = self.merge(self.table[2 * i], self.table[2 * i + 1])

    def query(self, i, j):
        left = self.id
        right = self.id
        for i += self.SZ, j += self.SZ; i < j; i //= 2, j //= 2:
            if i & 1:
                left = self.merge(left, self.table[i])
                i += 1
            if j & 1:
                j -= 1
                right = self.merge(self.table[j], right)
        return self.merge(left, right)

def main():
    setIO()

    class Pipe:
        def __init__(self, x, v, p):
            self.x = x
            self.v = v
            self.p = p

    N = int(sys.stdin.readline().strip())
    pipes = [Pipe(*map(int, sys.stdin.readline().strip().split())) for _ in range(N)]

    events = []
    for i in range(N - 1):
        dx = pipes[i + 1].x - pipes[i].x
        dv = pipes[i + 1].v - pipes[i].v

        events.append((i, 'RL', Fraction(dx, pipes[i + 1].v + pipes[i].v)))

        if dv > 0:
            events.append((i, 'LL', Fraction(dx, dv)))
        if dv < 0:
            events.append((i, 'RR', Fraction(dx, -dv)))

    events.sort(key=lambda x: x[2])

    class Node:
        def __init__(self):
            self.p = [0] * 4
            self.noLL = self.noRR = self.noRL = False
            self.none = True

    def merge_nodes(a, b):
        if a.none:
            return b
        if b.none:
            return a
        r = b
        r.p = [0] * 4
        for i in range(4):
            for j in range(4):
                iF = i & 1
                iB = (i >> 1) & 1
                jF = j & 1
                jB = (j >> 1) & 1
                if a.noLL and not iB and not jF:
                    continue
                if a.noRR and iB and jF:
                    continue
                if a.noRL and iB and not jF:
                    continue
                r.p[iF + 2 * jB] += a.p[i] * b.p[j]
        return r

    st = SegmentTree(N, Node(), merge_nodes)
    st.set_leaves(lambda i: Node())

    for i in range(N):
        pR = ModNum(pipes[i].p) * ModNum.small_inv(100)
        node = Node()
        node.p = [1 - pR.v, 0, 0, pR.v]
        node.none = False
        st.table[st.SZ + i] = node

    ans = ModNum(0)
    prob = ModNum(1)

    for e in events:
        i, d, t = e
        c = st.table[st.SZ + i]
        if d == 'LL':
            c.noLL = True
        elif d == 'RR':
            c.noRR = True
        elif d == 'RL':
            c.noRL = True
        st.replace(i, c)

        u = st.query(0, st.SZ)
        PROB = sum(u.p)
        ans += (prob - PROB) * t.n * ModNum.small_inv(t.d)
        prob = PROB

    print(ans)

if __name__ == "__main__":
    main()
