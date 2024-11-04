import sys
import random
from collections import defaultdict
from bisect import bisect_left, bisect_right

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = 3.141592653589793

N = 100 * 1000 + 13

n = 0
a = [None] * N

def read():
    global n
    n = int(sys.stdin.readline().strip())
    for i in range(n):
        x = list(map(int, sys.stdin.readline().strip().split()))
        if x[0] == 1:
            a[i] = (1, x[1], x[2])
        elif x[0] == 2:
            a[i] = (2, x[1])
        else:
            a[i] = (3, x[1], x[2], x[3])

vals = []

class Node:
    def __init__(self, s=0, length=0):
        self.s = s
        self.sum = s * length
        self.minsum = s * length if s < 0 else 0

t = [Node() for _ in range(4 * N)]

def merge(a, b):
    c = Node()
    c.sum = a.sum + b.sum
    c.minsum = min(a.minsum, a.sum + b.minsum)
    return c

def build(v, l, r):
    if l == r - 1:
        if l == 0:
            t[v] = Node(0, INF + 1)
        else:
            t[v] = Node(0, 0)
        return
    m = (l + r) // 2
    build(v * 2, l, m)
    build(v * 2 + 1, m, r)
    t[v] = merge(t[v * 2], t[v * 2 + 1])

def upd(v, l, r, pos, val):
    if l == r - 1:
        t[v] = Node(val[0], val[1])
        return
    m = (l + r) // 2
    if pos < m:
        upd(v * 2, l, m, pos, val)
    else:
        upd(v * 2 + 1, m, r, pos, val)
    t[v] = merge(t[v * 2], t[v * 2 + 1])

val = [0] * N
length = [0] * N

def ask(v, l, r, L, R, x):
    if L >= R:
        return 2 * INF
    if l == L and r == R:
        if t[v].minsum + x > 0:
            x += t[v].sum
            return 2 * INF

        while l < r - 1:
            m = (l + r) // 2
            if t[v * 2].minsum + x <= 0:
                r = m
                v = v * 2
            else:
                x += t[v * 2].sum
                l = m
                v = v * 2 + 1
        if x == 0:
            return vals[l]

        assert t[v].minsum + x <= 0
        assert t[v].s < 0
        res = vals[l] + (x / -t[v].s)
        x = 0
        return res
    m = (l + r) // 2
    tmp = ask(v * 2, l, m, L, min(m, R), x)
    if x == 0:
        return tmp
    assert x > 0
    return ask(v * 2 + 1, m, r, max(m, L), R, x)

def solve():
    global vals
    vals.clear()
    for i in range(n):
        if a[i][0] == 1:
            vals.append(a[i][1])
    vals.append(0)
    vals.append(INF + 1)
    vals = sorted(set(vals))
    cur = set()
    build(1, 0, len(vals))

    val[0] = 0
    length[0] = INF + 1

    cur.add(0)
    cur.add(len(vals) - 1)

    for i in range(n):
        if a[i][0] == 1:
            pos = bisect_left(vals, a[i][1])
            pos2 = next(iter(cur))
            val[pos] = a[i][2]
            pos2 = cur.remove(pos2) if pos2 in cur else pos2
            length[pos2] = vals[pos] - vals[pos2]
            upd(1, 0, len(vals), pos2, (val[pos2], length[pos2]))
            cur.add(pos)
        elif a[i][0] == 2:
            pos = bisect_left(vals, a[i][1])
            pos2 = next(iter(cur))
            val[pos2] = length[pos2] = 0
            upd(1, 0, len(vals), pos2, (val[pos2], length[pos2]))
            pos2 = cur.remove(pos2)
            l = vals[pos2]
            pos2 = next(iter(cur))
            l -= vals[pos2]
            length[pos2] = l
            upd(1, 0, len(vals), pos2, (val[pos2], length[pos2]))
        else:
            l = bisect_left(vals, a[i][1])
            lit = next(iter(cur))
            r = a[i][2]
            x = a[i][3]
            if x == 0:
                print(f"{a[i][1]:.15f}")
                continue

            res = ask(1, 0, len(vals), lit, len(vals), x)
            if x == 0 and res < r + EPS:
                print(f"{res:.15f}")
            else:
                print("-1")

if __name__ == "__main__":
    while read():
        solve()
