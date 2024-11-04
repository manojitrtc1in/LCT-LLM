from collections import defaultdict
from fractions import Fraction
import sys
import math
import itertools

def setIO(filename=""):
    if filename:
        sys.stdin = open(filename + ".in", "r")
        sys.stdout = open(filename + ".out", "w")
    sys.stdin = open(0)
    sys.stdout = open(1)
    sys.setrecursionlimit(10**6)

class Pipe:
    def __init__(self, x, v, p):
        self.x = x
        self.v = v
        self.p = p

class Event:
    def __init__(self, i, d, t):
        self.i = i
        self.d = d
        self.t = t

def main():
    setIO()

    N = int(input())
    pipes = [Pipe(*map(int, input().split())) for _ in range(N)]

    LL, RR, RL = 0, 1, 2
    evs = []

    for i in range(N - 1):
        dx = pipes[i + 1].x - pipes[i].x
        dv = pipes[i + 1].v - pipes[i].v

        evs.append(Event(i, RL, Fraction(dx, pipes[i + 1].v + pipes[i].v)))

        if dv > 0:
            evs.append(Event(i, LL, Fraction(dx, dv)))
        if dv < 0:
            evs.append(Event(i, RR, Fraction(dx, -dv)))

    evs.sort(key=lambda e: e.t)

    class Node:
        def __init__(self):
            self.p = [0] * 4
            self.noLL = False
            self.noRR = False
            self.noRL = False
            self.none = True

    def combine(a, b):
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

    class SegmentTree:
        def __init__(self, size, id, combine):
            self.SZ = size
            self.id = id
            self.combine = combine
            self.table = [id] * (2 * size)

        def id1(self, create):
            for i in range(self.SZ):
                self.table[self.SZ + i] = create(i)
            for i in range(self.SZ - 1, 0, -1):
                self.table[i] = self.combine(self.table[2 * i], self.table[2 * i + 1])

        def replace(self, i, v):
            self.table[i + self.SZ] = v
            for i in range(i // 2, 0, -1):
                self.table[i] = self.combine(self.table[2 * i], self.table[2 * i + 1])

        def query(self, i, j):
            left = self.id
            right = self.id
            for i, j in zip(range(i + self.SZ, j + self.SZ), range(j + self.SZ)):
                if i & 1:
                    left = self.combine(left, self.table[i])
                    i += 1
                if j & 1:
                    right = self.combine(self.table[j - 1], right)
                    j -= 1
            return self.combine(left, right)

    st = SegmentTree(N, Node(), combine)
    st.id1(lambda i: Node())

    ans = Fraction(0)
    prob = Fraction(1)

    for e in evs:
        c = st.table[e.i]
        if e.d == LL:
            c.noLL = True
        elif e.d == RR:
            c.noRR = True
        elif e.d == RL:
            c.noRL = True
        st.replace(e.i, c)

        u = st.query(0, st.SZ)
        PROB = sum(u.p)
        ans += (prob - PROB) * e.t.n * Fraction(1, e.t.d)
        prob = PROB

    print(ans)

if __name__ == "__main__":
    main()
