from typing import List, Tuple, Callable
from fractions import Fraction
import sys
import itertools

class Modular:
    def __init__(self, value: int, mod: int):
        self.value = value % mod
        self.mod = mod

    def __add__(self, other):
        return Modular((self.value + other.value) % self.mod, self.mod)

    def __sub__(self, other):
        return Modular((self.value - other.value) % self.mod, self.mod)

    def __mul__(self, other):
        return Modular((self.value * other.value) % self.mod, self.mod)

    def __truediv__(self, other):
        return self * Modular(inverse(other.value, self.mod), self.mod)

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

def get_prob(a: List[Modular], n: int) -> Modular:
    return a[0] * (a[1][0] + a[1][1]) + (1 - a[0]) * (a[0][0] + a[0][1])

def build(l: int, r: int, id2: List[List[List[Modular]]], a: List[List[List[Modular]]]):
    if l == r:
        a[2 * l] = id2[l]
        return
    mid = (l + r) // 2
    build(l, mid, id2, a)
    build(mid + 1, r, id2, a)
    a[get_id(l, r)] = a[get_id(l, mid)] * a[get_id(mid + 1, r)]

def modify(l: int, r: int, k: int, id2: List[List[List[Modular]]], a: List[List[List[Modular]]]):
    if l == r:
        a[2 * l] = id2[k]
        return
    mid = (l + r) // 2
    if k <= mid:
        modify(l, mid, k, id2, a)
    else:
        modify(mid + 1, r, k, id2, a)
    a[get_id(l, r)] = a[get_id(l, mid)] * a[get_id(mid + 1, r)]

def get_id(l: int, r: int) -> int:
    assert 0 <= l <= r
    return l + r | (l != r)

def main():
    input = sys.stdin.read
    data = input().splitlines()
    n = int(data[0])
    if n == 1:
        print(0)
        return

    x, v, p = [], [], []
    for i in range(1, n + 1):
        xi, vi, pi = map(int, data[i].split())
        x.append(xi)
        v.append(vi)
        p.append(Modular(pi / 100, 1))

    id2 = [[[Modular(0, 1) for _ in range(2)] for _ in range(2)] for _ in range(n - 1)]
    for i in range(n - 1):
        id2[i][0][1] = p[i + 1]

    a = [[[Modular(0, 1) for _ in range(2)] for _ in range(2)] for _ in range(2 * (n - 1) - 1)]
    build(0, n - 2, id2, a)

    events = []
    for i in range(n - 1):
        d = x[i + 1] - x[i]
        events.append((Fraction(d, v[i + 1] + v[i]), i << 2 | 1))
        events.append((Fraction(d, v[i + 1] - v[i]) if v[i] < v[i + 1] else Fraction(1, 0), i << 2 | 0))
        events.append((Fraction(d, v[i] - v[i + 1]) if v[i] > v[i + 1] else Fraction(1, 0), i << 2 | 3))

    events.sort()

    prev_prob = get_prob(a, n)
    ans = Modular(0, 1)

    for event in reversed(events):
        i = event[1] >> 2
        dir1 = event[1] & 1
        dir2 = (event[1] >> 1) & 1

        id2[i][dir1][dir2] = p[i + 1] if dir2 else Modular(1 - p[i + 1].value, 1)
        modify(0, n - 2, i, id2, a)
        prob = get_prob(a, n)

        if event[0].denominator != 0:
            ans += (prob - prev_prob) * event[0]
        prev_prob = prob

    print(ans)

if __name__ == "__main__":
    main()
