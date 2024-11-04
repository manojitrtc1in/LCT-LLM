import sys
import random
from collections import defaultdict
from itertools import accumulate

class Modular:
    def __init__(self, value=0, mod=998244353):
        self.value = value % mod
        self.mod = mod

    def __add__(self, other):
        return Modular(self.value + other.value, self.mod)

    def __sub__(self, other):
        return Modular(self.value - other.value, self.mod)

    def __mul__(self, other):
        return Modular(self.value * other.value, self.mod)

    def __truediv__(self, other):
        return self * Modular(pow(other.value, self.mod - 2, self.mod), self.mod)

    def __eq__(self, other):
        return self.value == other.value

    def __lt__(self, other):
        return self.value < other.value

    def __int__(self):
        return self.value

    def __repr__(self):
        return str(self.value)

def can(n):
    global it
    if n == 1:
        return True

    x = n // 2
    y = (n + 1) // 2
    if not can(x) or not can(y):
        return False

    p0 = nxt[it][0]
    p1 = nxt[it][1]
    if p0 == len(s) or ind[p0] + x - 1 >= len(o[0]):
        p0 = len(s)
    else:
        p0 = o[0][ind[p0] + x - 1]
    
    if p1 == len(s) or ind[p1] + y - 1 >= len(o[1]):
        p1 = len(s)
    else:
        p1 = o[1][ind[p1] + y - 1]
    
    p0 = min(p0, p1)
    if p0 == len(s):
        return False
    
    it = p0 + 1
    return True

def gen(l, r):
    global it
    if l == r:
        return
    
    m = (l + r - 1) // 2
    gen(l, m)
    gen(m + 1, r)
    a, b, c = l, m + 1, l
    while a <= m and b <= r:
        if s[it] == '0':
            mas[c] = id[a]
            a += 1
        else:
            mas[c] = id[b]
            b += 1
        c += 1
        it += 1
    
    while a <= m:
        mas[c] = id[a]
        a += 1
        c += 1
    while b <= r:
        mas[c] = id[b]
        b += 1
        c += 1
    
    for i in range(l, r + 1):
        id[i] = mas[i]

def go(n, cert):
    global it
    it = 0
    if not cert:
        return can(n)
    
    it = 0
    can(n)
    assert it == len(s)

    it = 0
    id[:] = range(n)
    gen(0, n - 1)
    assert it == len(s)
    p = [0] * n
    for i in range(n):
        p[id[i]] = i
    print(n)
    print(' '.join(str(i + 1) for i in p))
    sys.exit(0)

maxn = 100100
s = ""
o = [[], []]
ind = []
nxt = []
it = 0
id = [0] * maxn
mas = [0] * maxn

def solve():
    global s, it, o, ind, nxt
    for i in range(2, maxn):
        x = i // 2
        y = i - x
        len[i] = (len[x][0] + len[y][0] + x, len[x][1] + len[y][1] + x + y - 1)
        for t in range(2):
            seg[i][t] = seg[x][t] + seg[y][t]
        seg[i][0] += x
        seg[i][1] += y

    s = input().strip()
    counter = [0, 0]
    nxt = [[0, 0] for _ in range(len(s) + 1)]
    ind = [0] * len(s)
    for i in range(len(s)):
        c = int(s[i])
        counter[c] += 1
        ind[i] = len(o[c])
        o[c].append(i)
    
    nxt[len(s)][0] = nxt[len(s)][1] = len(s)
    for i in range(len(s) - 1, -1, -1):
        for t in range(2):
            nxt[i][t] = nxt[i + 1][t]
        nxt[i][int(s[i])] = i
    
    l, r = 0, 100010
    while r - l > 1:
        m = (l + r) // 2
        if go(m, False):
            l = m
        else:
            r = m
    go(l, True)

if __name__ == "__main__":
    input = sys.stdin.read
    data = input().splitlines()
    sys.stdin = open("../a.in", "r")
    sys.stdout = open("../a.out", "w")
    
    solve()
