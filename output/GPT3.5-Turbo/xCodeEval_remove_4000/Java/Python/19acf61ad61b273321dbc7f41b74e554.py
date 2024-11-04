import sys
import math
from collections import defaultdict

def roundS(result, scale):
    fmt = "%%.%df" % scale
    return fmt % result

def unique(a):
    p = 1
    for i in range(1, len(a)):
        if a[i] != a[i - 1]:
            a[p] = a[i]
            p += 1
    return a[:p]

def bigger(a, key):
    lo = 0
    hi = len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] > key:
            hi = mid
        else:
            lo = mid + 1
    return lo

def addEdge(u, v, w):
    to.append(v)
    ne.append(h[u])
    h[u] = m

def add(u, v, ww):
    to.append(u)
    w.append(ww)
    ne.append(h[v])
    h[v] = cc

    to.append(v)
    w.append(ww)
    ne.append(h[u])
    h[u] = cc

class S:
    def __init__(self, l, r):
        self.l = l
        self.r = r
        self.miss = 0
        self.cnt = 0
        self.c = 0

def init11(f):
    global o, a
    o = f
    length = len(o)
    a = [None] * (length * 4)
    build1(1, 0, length - 1)

def build1(num, l, r):
    cur = S(l, r)
    if l == r:
        cur.c = o[l]
        a[num] = cur
        return
    else:
        m = (l + r) // 2
        le = num << 1
        ri = le | 1
        build1(le, l, m)
        build1(ri, m + 1, r)
        a[num] = cur
        pushup(num, le, ri)

def query1(num, l, r):
    if a[num].l >= l and a[num].r <= r:
        return a[num].c
    else:
        m = (a[num].l + a[num].r) // 2
        le = num << 1
        ri = le | 1

        mi = -1

        if r > m:
            res = query1(ri, l, r)
            mi = max(mi, res)

        if l <= m:
            res = query1(le, l, r)
            mi = max(mi, res)

        return mi

def pushup(num, le, ri):
    a[num].c = max(a[le].c, a[ri].c)

def dfs(n, li):
    sz = len(li)
    if sz >= rr or sz >= 11:
        return
    v = li[-1]
    if v == n:
        global cao, rr
        cao = li.copy()
        rr = sz
        return
    res = li[::-1]
    for u in res:
        for vv in res:
            if u + vv > v and u + vv <= n:
                li.append(u + vv)
                dfs(n, li)
                li.pop()
            elif u + vv > n:
                break

def mul(a, b, p):
    res = 0
    base = a
    while b > 0:
        if b & 1:
            res = (res + base) % p
        base = (base + base) % p
        b >>= 1
    return res

def mod_pow(k, n, p):
    res = 1
    temp = k % p
    while n != 0:
        if n & 1:
            res = mul(res, temp, p)
        temp = mul(temp, temp, p)
        n >>= 1
    return res % p

def gen(x):
    while True:
        f = random.randint(0, x - 1)
        if f >= 1 and f <= x - 1:
            return f

def id1(x):
    if x == 1:
        return False
    if x == 2:
        return True
    if x == 3:
        return True
    if x & 1 == 0:
        return False
    y = x % 6
    if y == 1 or y == 5:
        ck = x - 1
        while ck & 1 == 0:
            ck >>= 1
        as_ = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
        for i in range(len(as_)):
            a = as_[i]
            ck1 = ck
            a = mod_pow(a, ck1, x)
            while ck1 < x:
                y = mod_pow(a, 2, x)
                if y == 1 and a != 1 and a != x - 1:
                    return False
                a = y
                ck1 <<= 1
            if a != 1:
                return False
        return True
    else:
        return False

def inv(a, MOD):
    return a == 1 and 1 or (MOD - MOD // a) * inv(MOD % a, MOD) % MOD

def C(n, m, MOD):
    if m + m > n:
        m = n - m
    up = 1
    down = 1
    for i in range(m):
        up = up * (n - i) % MOD
        down = down * (i + 1) % MOD
    return up * inv(down, MOD) % MOD

def id3(a, b):
    if b == 0:
        return [1, 0, a]
    r = id3(b, a % b)
    return [r[1], r[0] - (a // b) * r[1], r[2]]

def id2(m, r):
    res = id3(m[0], m[1])
    rm = r[1] - r[0]
    if rm % res[2] == 0:
        pass

def go(i, c, cl):
    cl[i] = c
    j = h[i]
    while j != -1:
        v = to[j]
        if cl[v] == 0:
            go(v, -c, cl)
        j = ne[j]

def solve():
    t = ni()
    dp = [0] * 1000001
    for _ in range(t):
        n = ni()
        k = ni()
        d = ni()
        a = na(n)
        g = 0
        for j in range(d):
            if dp[a[j]] == 0:
                g += 1
            dp[a[j]] += 1
        all_ = g
        for j in range(d, n):
            dp[a[j - d]] -= 1
            if dp[a[j - d]] == 0:
                g -= 1
            if dp[a[j]] == 0:
                g += 1
            dp[a[j]] += 1
            all_ = min(all_, g)
        println(all_)
        for j in range(d):
            dp[a[n - j - 1]] -= 1

# Read input
def main():
    global rr, cao, to, ne, h, m, cc, o, a
    rr = 100
    cao = []
    to = []
    ne = []
    h = []
    m = 0
    cc = 0
    o = []
    a = []
    for _ in range(1000001):
        dp.append(0)
    for _ in range(1000001):
        h.append(-1)
    for _ in range(1000001):
        fa.append(0)
    for _ in range(1000001):
        sz.append(0)
    for _ in range(1000001):
        w.append(0)
    for _ in range(1000001):
        clr.append(0)
    for _ in range(1000001):
        qr.append([])
    for _ in range(1000001):
        qs.append([])
    for _ in range(1000001):
        a.append(S(0, 0))
    for _ in range(1000001):
        o.append(0)

    solve()

# Input Reader
def read():
    return sys.stdin.readline().strip()

def ni():
    return int(read())

def na(n):
    return list(map(int, read().split()))

def nl():
    return int(read())

def ns():
    return read()

def main():
    main()

if __name__ == '__main__':
    main()
