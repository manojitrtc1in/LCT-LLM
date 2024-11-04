from math import sqrt, log2, ceil
from collections import defaultdict
from cmath import inf

eps = 1e-9
MOD = int(1e9 + 7)

def id6(x, y):
    return abs(x - y) < eps

def inrange(x, t):
    return 0 <= x < t

def inrange_list(xs, t):
    return all(0 <= x < t for x in xs)

def id5(x):
    ret = 0
    x -= 1
    while x > 0:
        ret += 1
        x >>= 1
    return ret

def rndf(x):
    return int(x + (0.5 if x >= 0 else -0.5))

def id2(x):
    m = int(sqrt(x))
    return m + (0 if m * m <= x else -1)

def id8(x):
    m = int(sqrt(x))
    return m + (1 if x > m * m else 0)

def rnddiv(a, b):
    return a // b + (1 if a % b * 2 >= b else 0)

def ceildiv(a, b):
    return a // b + (0 if a % b == 0 else 1)

def gcd(m, n):
    return m if n == 0 else gcd(n, m % n)

def lcm(m, n):
    return m * n // gcd(m, n)

class SegTree:
    def __init__(self, n, init):
        self.n = n
        self.N = 2 ** ceil(log2(n))
        self.base = self.N - 1
        self.nodes = [init] * (self.base + self.N)

    def left_of(self, index):
        return -1 if index >= self.base else index * 2 + 1

    def right_of(self, index):
        return -1 if index >= self.base else index * 2 + 2

    def parent_of(self, index):
        return -1 if index == 0 else (index - 1) // 2

    def update_rec(self, s, t, l, r, index, v):
        if s == l and t == r:
            self.nodes[index] = v
        else:
            mid = (l + r) // 2
            index_l = self.left_of(index)
            index_r = self.right_of(index)
            if s < mid < t:
                self.update_rec(s, mid, l, mid, index_l, v)
                self.update_rec(mid, t, mid, r, index_r, v)
            elif s < mid:
                self.update_rec(s, t, l, mid, index_l, v)
            elif mid < t:
                self.update_rec(s, t, mid, r, index_r, v)
            self.nodes[index] = self.nodes[index_l] + self.nodes[index_r]

    def add_rec(self, s, t, l, r, index):
        if s == l and t == r:
            return self.nodes[index]
        else:
            mid = (l + r) // 2
            index_l = self.left_of(index)
            index_r = self.right_of(index)
            v0 = 0
            v1 = 0
            if s < mid < t:
                v0 = self.add_rec(s, mid, l, mid, index_l)
                v1 = self.add_rec(mid, t, mid, r, index_r)
            elif s < mid:
                v0 = self.add_rec(s, t, l, mid, index_l)
            elif mid < t:
                v1 = self.add_rec(s, t, mid, r, index_r)
            return v0 + v1

    def update(self, k, v):
        self.update_rec(k, k + 1, 0, self.N, 0, v)

    def sum(self, s, t):
        return self.add_rec(s, t, 0, self.N, 0)

def id4(l, r, v, evalfunc):
    if r - l == 1:
        return l if evalfunc(l, v) else l - 1
    m = (l + r) // 2
    return id4(m, r, v, evalfunc) if evalfunc(m, v) else id4(l, m, v, evalfunc)

class bsargv_t:
    def __init__(self, st, s, sum):
        self.st = st
        self.s = s
        self.sum = sum

def evalfunc(val, v):
    buf = v.st.sum(v.s, val + 1)
    return buf <= v.sum / 2

class modll:
    def __init__(self, init=0):
        self.val = self.modify(init)

    def modify(self, x):
        ret = x % MOD
        return ret + MOD if ret < 0 else ret

    def inv(self, x):
        if x == 0:
            return 1 / x
        elif x == 1:
            return 1
        else:
            return self.modify(self.inv(MOD % x) * self.modify(-MOD // x))

    def __add__(self, x):
        return modll(self.modify(self.val + x.val))

    def __sub__(self, x):
        return modll(self.modify(self.val - x.val))

    def __mul__(self, x):
        return modll(self.modify(self.val * x.val))

    def __truediv__(self, x):
        return modll(self.modify(self.val * self.inv(x.val)))

    def __eq__(self, x):
        return self.val == x.val

    def __ne__(self, x):
        return self.val != x.val

    def get_val(self):
        return self.val

facts = []

def id7(n):
    if not facts:
        facts.append(modll(1))
    for i in range(len(facts), n + 1):
        facts.append(modll(facts[-1].val * i))

ifacts = []
invs = []

def id1(n):
    if not invs:
        invs.append(modll(0))
        invs.append(modll(1))
    for i in range(len(invs), n + 1):
        invs.append(invs[MOD % i] * modll(MOD - MOD // i))

def id0(n):
    id1(n)
    if not ifacts:
        ifacts.append(modll(1))
    for i in range(len(ifacts), n + 1):
        ifacts.append(modll(ifacts[-1].val * invs[i].val))

def combination(n, r):
    if n >= r >= 0:
        id7(n)
        id0(n)
        return facts[n] * ifacts[r] * ifacts[n - r]
    return modll(0)

def get_fact(n):
    id7(n)
    return facts[n]

def id3(n):
    id0(n)
    return ifacts[n]

def disc_log(a, b):
    ret = -1
    m = id8(MOD)
    mp = {}
    x = modll(1)
    for i in range(m):
        mp[x.get_val()] = i
        x *= a
    x = modll(1) / pow(a, m)
    k = b
    for i in range(m):
        if k.get_val() not in mp:
            k *= x
        else:
            ret = i * m + mp[k.get_val()]
            break
    return ret

def quickio():
    import sys
    input = sys.stdin.read
    data = input().split()
    return data

data = quickio()
n, q = int(data[0]), int(data[1])
a = list(map(int, data[2:n + 2]))
st = SegTree(n, 0)
ast = SegTree(n, modll(0))
lst = SegTree(n, modll(0))
rst = SegTree(n, modll(0))

for i in range(n):
    w = int(data[n + 2 + i])
    st.update(i, w)
    ast.update(i, modll(w.val * a[i]))
    lst.update(i, modll(w.val * (n - 1 - i)))
    rst.update(i, modll(w.val * i))

ans = []

for i in range(q):
    x = int(data[n + 2 + n + i])
    if x < 0:
        x += 1
        y = int(data[n + 2 + n + q + i])
        st.update(-x, y)
        ast.update(-x, modll(y) * a[-x])
        lst.update(-x, modll(y) * (n - 1 - (-x)))
        rst.update(-x, modll(y) * (-x))
    else:
        y = int(data[n + 2 + n + q + i])
        x -= 1
        y -= 1
        if x == y:
            ans.append(0)
        else:
            halfid = x if y - x == 1 else id4(x + 1, y, bsargv_t(st, x, st.sum(x, y + 1)), evalfunc)
            cand0 = st.sum(x, halfid + 1)
            cand1 = st.sum(halfid + 1, y + 1)
            dst, dstid = (a[halfid + 1], halfid + 1) if cand0 <= cand1 else (a[halfid], halfid)
            buf = modll(0)
            buf += modll(dst) * st.sum(x, dstid) - ast.sum(x, dstid) - (lst.sum(x, dstid) - modll(st.sum(x, dstid).val) * (n - 1 - dstid))
            buf += modll(ast.sum(dstid, y + 1)) - modll(dst) * st.sum(dstid, y + 1) - (rst.sum(dstid, y + 1) - modll(st.sum(dstid, y + 1).val) * dstid)
            ans.append(buf)

for value in ans:
    print(value)
