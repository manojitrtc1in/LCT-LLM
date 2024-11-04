import sys
from typing import List, Tuple
from math import acos
from random import seed, randint
from time import time

def read() -> Tuple[int, List[Tuple[Tuple[int, int], Tuple[int, int]]]]:
    n = int(input())
    a = []
    for _ in range(n):
        x = int(input())
        if x == 1:
            y, z = map(int, input().split())
            a.append(((x, y), (z,)))
        elif x == 2:
            y = int(input())
            a.append(((x, y), ()))
        elif x == 3:
            y, z, w = map(int, input().split())
            a.append(((x, y), (z, w)))
    return n, a

def solve(n: int, a: List[Tuple[Tuple[int, int], Tuple[int, int]]]):
    vals = []
    for x, _ in a:
        if x[0] == 1:
            vals.append(x[1])
    vals.append(0)
    vals.append(10**9 + 1)
    vals.sort()
    vals = list(set(vals))
    cur = set()
    build(1, 0, len(vals))
    val = [0] * len(vals)
    length = [10**9 + 1] * len(vals)
    cur.add(0)
    cur.add(len(vals) - 1)
    for x, y in a:
        if x[0] == 1:
            pos = vals.index(x[1])
            pos2 = cur.index(pos)
            val[pos] = y[0]
            pos2 -= 1
            length[pos2] = vals[pos] - vals[pos2]
            upd(1, 0, len(vals), pos2, (val[pos2], length[pos2]))
            pos2 += 1
            length[pos] = vals[pos2] - vals[pos]
            upd(1, 0, len(vals), pos, (val[pos], length[pos]))
            cur.add(pos)
        elif x[0] == 2:
            pos = vals.index(x[1])
            pos2 = cur.index(pos)
            val[pos2] = length[pos2] = 0
            upd(1, 0, len(vals), pos2, (val[pos2], length[pos2]))
            pos2 = cur.remove(pos2)
            l = vals[pos2]
            pos2 -= 1
            l -= vals[pos2]
            length[pos2] = l
            upd(1, 0, len(vals), pos2, (val[pos2], length[pos2]))
        else:
            l = vals.index(x[1])
            lit = cur.index(l)
            r = y[0]
            x = y[1]
            if x == 0:
                print(x)
                continue
            res = ask(1, 0, len(vals), lit, len(vals), x)
            if x == 0 and res < r + EPS:
                print(res)
            else:
                print(-1)

def build(v: int, l: int, r: int):
    if l == r - 1:
        if l == 0:
            t[v] = (0, 10**9 + 1)
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

def upd(v: int, l: int, r: int, pos: int, val: Tuple[int, int]):
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
        return 2 * 10**9
    if l == L and r == R:
        if t[v][1] + x > 0:
            x += t[v][0]
            return 2 * 10**9
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

def main():
    seed(time())
    tt = time()
    while True:
        try:
            n, a = read()
            solve(n, a)
        except EOFError:
            break
    print("TIME =", time() - tt, file=sys.stderr)
    tt = time()

if __name__ == "__main__":
    main()
