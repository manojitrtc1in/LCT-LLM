import sys
from typing import List, Tuple
from math import acos
from bisect import bisect_left
from itertools import accumulate

def read() -> Tuple[int, List[Tuple[int, int, int, int]]]:
    n = int(input())
    a = []
    for _ in range(n):
        x = list(map(int, input().split()))
        if x[0] == 1:
            a.append((x[0], x[1], x[2], 0))
        elif x[0] == 2:
            a.append((x[0], x[1], 0, 0))
        else:
            a.append((x[0], x[1], x[2], x[3]))
    return n, a

def solve() -> None:
    vals = []
    for i in range(n):
        if a[i][0] == 1:
            vals.append(a[i][1])
    vals.append(0)
    vals.append(INF + 1)
    vals.sort()
    vals = list(set(vals))
    cur = set()
    build(1, 0, len(vals))
    val = [0] * len(vals)
    length = [INF + 1] * len(vals)
    cur.add(0)
    cur.add(len(vals) - 1)
    for i in range(n):
        if a[i][0] == 1:
            pos = bisect_left(vals, a[i][1])
            pos2 = cur.bisect_left(pos)
            val[pos] = a[i][2]
            pos2 -= 1
            length[pos2] = vals[pos] - vals[pos2]
            upd(1, 0, len(vals), pos2, (val[pos2], length[pos2]))
            pos2 += 1
            length[pos] = vals[pos2] - vals[pos]
            upd(1, 0, len(vals), pos, (val[pos], length[pos]))
            cur.add(pos)
        elif a[i][0] == 2:
            pos = bisect_left(vals, a[i][1])
            pos2 = cur.bisect_left(pos)
            val[pos2] = length[pos2] = 0
            upd(1, 0, len(vals), pos2, (val[pos2], length[pos2]))
            pos2 = cur.erase(pos2)
            l = vals[pos2]
            pos2 -= 1
            l -= vals[pos2]
            length[pos2] = l
            upd(1, 0, len(vals), pos2, (val[pos2], length[pos2]))
        else:
            l = bisect_left(vals, a[i][1])
            lit = cur.bisect_left(l)
            r = a[i][2]
            x = a[i][3]
            if x == 0:
                print(a[i][1])
                continue
            res = ask(1, 0, len(vals), lit, len(vals), x)
            if x == 0 and res < r + EPS:
                print(res)
            else:
                print(-1)

def build(v: int, l: int, r: int) -> None:
    if l == r - 1:
        if l == 0:
            t[v] = (0, INF + 1)
        else:
            t[v] = (0, 0)
        return
    m = (l + r) // 2
    build(v * 2, l, m)
    build(v * 2 + 1, m, r)
    t[v] = merge(t[v * 2], t[v * 2 + 1])

def merge(a: Tuple[int, int], b: Tuple[int, int]) -> Tuple[int, int]:
    c = (0, 0)
    c[0] = a[0] + b[0]
    c[1] = min(a[1], a[0] + b[1])
    return c

def upd(v: int, l: int, r: int, pos: int, val: Tuple[int, int]) -> None:
    if l == r - 1:
        t[v] = val
        return
    m = (l + r) // 2
    if pos < m:
        upd(v * 2, l, m, pos, val)
    else:
        upd(v * 2 + 1, m, r, pos, val)
    t[v] = merge(t[v * 2], t[v * 2 + 1])

def ask(v: int, l: int, r: int, L: int, R: int, x: int) -> float:
    if L >= R:
        return 2 * INF
    if l == L and r == R:
        if t[v][1] + x > 0:
            x += t[v][0]
            return 2 * INF
        while l < r - 1:
            m = (l + r) // 2
            if t[v * 2][1] + x <= 0:
                r = m
                v = v * 2
            else:
                x += t[v * 2][0]
                l = m
                v = v * 2 + 1
        if x == 0:
            return vals[l]
        assert t[v][1] + x <= 0
        assert t[v][0] < 0
        res = vals[l] + (x / -t[v][0])
        x = 0
        return res
    m = (l + r) // 2
    tmp = ask(v * 2, l, m, L, min(m, R), x)
    if x == 0:
        return tmp
    assert x > 0
    return ask(v * 2 + 1, m, r, max(m, L), R, x)

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = acos(-1.0)
N = 100 * 1000 + 13
EPS = 1e-15

n, a = read()
t = [(0, 0)] * (4 * N)
solve()
