from typing import List, Callable, Tuple
from functools import reduce
from math import gcd

class Modular:
    def __init__(self, value: int, mod: int):
        self.mod = mod
        self.value = value % mod
        if self.value < 0:
            self.value += mod

    def __add__(self, other):
        return Modular(self.value + other.value, self.mod)

    def __sub__(self, other):
        return Modular(self.value - other.value, self.mod)

    def __mul__(self, other):
        return Modular(self.value * other.value, self.mod)

    def __truediv__(self, other):
        return self * Modular(inverse(other.value, self.mod), self.mod)

    def __int__(self):
        return self.value

    def __repr__(self):
        return str(self.value)

def inverse(a: int, m: int) -> int:
    u, v = 0, 1
    while a != 0:
        t = m // a
        m -= t * a
        a, m = m, a
        u -= t * v
        u, v = v, u
    assert m == 1
    return u % m

class SegmentTree:
    class Node:
        def __init__(self):
            self.w = 0
            self.Wp = Modular(0, md)
            self.fp = Modular(0, md)
            self.tp = Modular(0, md)

        def apply(self, l: int, r: int, v: int, id: int, rid: int, a: int):
            self.w = v
            self.Wp = Modular(v, md) * a
            self.fp = Modular(v, md) * id
            self.tp = Modular(v, md) * rid

    def __init__(self, v: List[int], a: List[int]):
        self.n = len(v)
        assert self.n > 0
        self.tree = [self.Node() for _ in range(2 * self.n - 1)]
        self.build(0, 0, self.n - 1, v, a)

    def unite(self, a: Node, b: Node) -> Node:
        res = self.Node()
        res.w = a.w + b.w
        res.Wp = a.Wp + b.Wp
        res.fp = a.fp + b.fp
        res.tp = a.tp + b.tp
        return res

    def push(self, x: int, l: int, r: int):
        pass

    def pull(self, x: int, z: int):
        self.tree[x] = self.unite(self.tree[x + 1], self.tree[z])

    def build(self, x: int, l: int, r: int, v: List[int], a: List[int]):
        if l == r:
            self.tree[x].apply(l, r, v[l], l, self.n - 1 - r, a[l])
            return
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        self.build(x + 1, l, y, v, a)
        self.build(z, y + 1, r, v, a)
        self.pull(x, z)

    def get(self, x: int, l: int, r: int, ll: int, rr: int) -> Node:
        if ll <= l and r <= rr:
            return self.tree[x]
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        self.push(x, l, r)
        res = self.Node()
        if rr <= y:
            res = self.get(x + 1, l, y, ll, rr)
        else:
            if ll > y:
                res = self.get(z, y + 1, r, ll, rr)
            else:
                res = self.unite(self.get(x + 1, l, y, ll, rr), self.get(z, y + 1, r, ll, rr))
        self.pull(x, z)
        return res

    def modify(self, x: int, l: int, r: int, ll: int, rr: int, v: int, id: int, rid: int, a: int):
        if ll <= l and r <= rr:
            self.tree[x].apply(l, r, v, id, rid, a)
            return
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        self.push(x, l, r)
        if ll <= y:
            self.modify(x + 1, l, y, ll, rr, v, id, rid, a)
        if rr > y:
            self.modify(z, y + 1, r, ll, rr, v, id, rid, a)
        self.pull(x, z)

    def get_range(self, ll: int, rr: int) -> Node:
        assert 0 <= ll <= rr < self.n
        return self.get(0, 0, self.n - 1, ll, rr)

md = int(1e9 + 7)

n, q = map(int, input().split())
a = list(map(int, input().split()))
w = list(map(int, input().split()))
st = SegmentTree(w, a)

for _ in range(q):
    x, y = map(int, input().split())
    if x < 0:
        x = -x - 1
        st.modify(0, 0, n - 1, x, x, y, x, n - 1 - x, a[x])
    else:
        x -= 1
        y -= 1
        v = 0
        sum_w = st.get_range(x, y).w
        pos = st.find_first(x, y, lambda node: (v + node.w) * 2 >= sum_w)
        assert pos != -1
        l = st.get_range(x, pos)
        r = st.get_range(pos, y)
        res = Modular(0, md)

        res += r.Wp - r.fp - Modular(a[pos] - pos, md) * r.w
        res += Modular(a[pos] - pos, md) * l.w + l.fp - l.Wp
        print(int(res))
