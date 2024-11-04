from typing import List, Tuple
from fractions import Fraction
import sys
from itertools import accumulate

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

def get_mid(l: int, r: int) -> int:
    assert l <= r
    return l + (r - l) // 2

def get_id(l: int, r: int) -> int:
    assert 0 <= l <= r
    return l + r | (l != r)

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    if n == 1:
        print(0)
        return

    x = list(map(int, data[1:n + 1]))
    v = list(map(int, data[n + 1:2 * n + 1]))
    p = [Modular(int(data[2 * n + i + 1]) * pow(100, -1, 998244353), 998244353) for i in range(n)]

    id2 = [None] * (n - 1)
    for i in range(n - 1):
        id2[i] = [[0, 0], [0, 0]]
        id2[i][0][1] = p[i + 1]

    a = [None] * (2 * (n - 1) - 1)

    def get_prob(to_right: Modular, mat):
        return to_right * (mat[1][0] + mat[1][1]) + (1 - to_right) * (mat[0][0] + mat[0][1])

    def build(l: int, r: int):
        if l == r:
            a[2 * l] = id2[l]
            return
        mid = get_mid(l, r)
        build(l, mid)
        build(mid + 1, r)
        a[get_id(l, r)] = [[0, 0], [0, 0]]
        for i in range(2):
            for j in range(2):
                a[get_id(l, r)][i][j] = a[get_id(l, mid)][i][0] * a[get_id(mid + 1, r)][0][j]

    build(0, n - 2)

    def modify(l: int, r: int, k: int):
        if l == r:
            a[2 * l] = id2[k]
            return
        mid = get_mid(l, r)
        if k <= mid:
            modify(l, mid, k)
        else:
            modify(mid + 1, r, k)
        a[get_id(l, r)] = [[0, 0], [0, 0]]
        for i in range(2):
            for j in range(2):
                a[get_id(l, r)][i][j] = a[get_id(l, mid)][i][0] * a[get_id(mid + 1, r)][0][j]

    events = []
    for i in range(n - 1):
        d = x[i + 1] - x[i]
        events.append((Fraction(d, v[i + 1] + v[i]), i << 2 | 1))
        events.append((Fraction(d, v[i + 1] - v[i]) if v[i] < v[i + 1] else Fraction(1, 0), i << 2 | 0))
        events.append((Fraction(d, v[i] - v[i + 1]) if v[i] > v[i + 1] else Fraction(1, 0), i << 2 | 3))

    events.sort()

    prev_prob = get_prob(p[0], a[get_id(0, n - 2)])
    ans = 0

    for event in reversed(events):
        i = event[1] >> 2
        dir1 = event[1] & 1
        dir2 = (event[1] >> 1) & 1

        id2[i][dir1][dir2] = p[i + 1] if dir2 else Modular(1 - p[i + 1].value, 998244353)
        modify(0, n - 2, i)
        prob = get_prob(p[0], a[get_id(0, n - 2)])
        if event[0].denominator != 0:
            ans += (prob - prev_prob) * event[0]
        prev_prob = prob

    print(ans)

if __name__ == "__main__":
    main()
