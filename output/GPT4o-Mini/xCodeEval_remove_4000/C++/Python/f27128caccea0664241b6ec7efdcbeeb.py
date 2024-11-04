from typing import List, Callable, TypeVar, Generic
from functools import reduce
from math import gcd

T = TypeVar('T')

def inverse(a: T, m: T) -> T:
    u, v = 0, 1
    while a != 0:
        t = m // a
        m -= t * a
        a, m = m, a
        u -= t * v
        u, v = v, u
    assert m == 1
    return u

class Modular(Generic[T]):
    def __init__(self, x: T = 0):
        self.value = self.normalize(x)

    @staticmethod
    def normalize(x: T) -> T:
        v = x % Modular.mod()
        if v < 0:
            v += Modular.mod()
        return v

    @staticmethod
    def mod() -> int:
        return T.value

    def __call__(self) -> T:
        return self.value

    def __add__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value + other.value)

    def __sub__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value - other.value)

    def __mul__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value * other.value)

    def __truediv__(self, other: 'Modular') -> 'Modular':
        return self * Modular(inverse(other.value, Modular.mod()))

    def __eq__(self, other: 'Modular') -> bool:
        return self.value == other.value

    def __str__(self) -> str:
        return str(self.value)

md = int(1e9 + 7)

class id0:
    class node:
        def __init__(self):
            self.w = 0
            self.Wp = Modular(0)
            self.fp = Modular(0)
            self.tp = Modular(0)

        def apply(self, l: int, r: int, v: int, id: int, rid: int, a: int):
            self.w = v
            self.Wp = Modular(v) * a
            self.fp = Modular(v) * id
            self.tp = Modular(v) * rid

    def __init__(self, v: List[int], t: List[int]):
        self.n = len(v)
        assert self.n > 0
        self.tree = [self.node() for _ in range(2 * self.n - 1)]
        self.build(0, 0, self.n - 1, v, t)

    def build(self, x: int, l: int, r: int, v: List[int], a: List[int]):
        if l == r:
            self.tree[x].apply(l, r, v[l], l, self.n - 1 - r, a[l])
            return
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        self.build(x + 1, l, y, v, a)
        self.build(z, y + 1, r, v, a)
        self.pull(x, z)

    def pull(self, x: int, z: int):
        self.tree[x] = self.unite(self.tree[x + 1], self.tree[z])

    def unite(self, a: 'id0.node', b: 'id0.node') -> 'id0.node':
        res = self.node()
        res.w = a.w + b.w
        res.Wp = a.Wp + b.Wp
        res.fp = a.fp + b.fp
        res.tp = a.tp + b.tp
        return res

    def get(self, ll: int, rr: int) -> 'id0.node':
        assert 0 <= ll <= rr < self.n
        return self.get_recursive(0, 0, self.n - 1, ll, rr)

    def get_recursive(self, x: int, l: int, r: int, ll: int, rr: int) -> 'id0.node':
        if ll <= l and r <= rr:
            return self.tree[x]
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        res = self.node()
        if rr <= y:
            res = self.get_recursive(x + 1, l, y, ll, rr)
        elif ll > y:
            res = self.get_recursive(z, y + 1, r, ll, rr)
        else:
            res = self.unite(self.get_recursive(x + 1, l, y, ll, rr), self.get_recursive(z, y + 1, r, ll, rr))
        self.pull(x, z)
        return res

    def modify(self, ll: int, rr: int, v: int, id: int, rid: int, a: int):
        assert 0 <= ll <= rr < self.n
        self.modify_recursive(0, 0, self.n - 1, ll, rr, v, id, rid, a)

    def modify_recursive(self, x: int, l: int, r: int, ll: int, rr: int, v: int, id: int, rid: int, a: int):
        if ll <= l and r <= rr:
            self.tree[x].apply(l, r, v, id, rid, a)
            return
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        if ll <= y:
            self.modify_recursive(x + 1, l, y, ll, rr, v, id, rid, a)
        if rr > y:
            self.modify_recursive(z, y + 1, r, ll, rr, v, id, rid, a)
        self.pull(x, z)

n, q = map(int, input().split())
a = list(map(int, input().split()))
w = list(map(int, input().split()))
st = id0(w, a)

for _ in range(q):
    x, y = map(int, input().split())
    if x < 0:
        x = -x - 1
        st.modify(x, x, y, x, n - 1 - x, a[x])
    else:
        x -= 1
        y -= 1
        v = 0
        sum_w = st.get(x, y).w
        pos = st.find_first(x, y, lambda a: (v + a.w) * 2 >= sum_w if (v := v + a.w) else False)
        assert pos != -1
        l = st.get(x, pos)
        r = st.get(pos, y)
        res = Modular(0)
        res += r.Wp - r.fp - Modular(a[pos] - pos) * r.w
        res += Modular(a[pos] - pos) * l.w + l.fp - l.Wp
        print(res)
