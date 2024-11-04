from typing import List, Tuple
from fractions import Fraction

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
        return self * Modular(pow(other.value, -1, self.mod), self.mod)

    def __repr__(self):
        return str(self.value)

def get_mid(l: int, r: int) -> int:
    assert l <= r
    return l + (r - l) // 2

class Mat:
    def __init__(self):
        self.m = [[0, 0], [0, 0]]

    def __mul__(self, other):
        c = Mat()
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    c.m[i][j] += self.m[i][k] * other.m[k][j]
        return c

def main():
    n = int(input())
    if n == 1:
        print(0)
        return

    x = [0] * n
    v = [0] * n
    p = [0] * n
    for i in range(n):
        x[i], v[i], p[i] = map(int, input().split())
        p[i] = Modular(p[i] * pow(100, -1, 998244353), 998244353)

    allowed_collisions = [Mat() for _ in range(n - 1)]
    for i in range(n - 1):
        allowed_collisions[i].m[0][1] = p[i + 1]

    a = [Mat() for _ in range(2 * (n - 1) - 1)]

    def get_prob():
        return to_right * (a[get_id(0, n - 2)].m[1][0] + a[get_id(0, n - 2)].m[1][1]) + \
               (1 - to_right) * (a[get_id(0, n - 2)].m[0][0] + a[get_id(0, n - 2)].m[0][1])

    def build(l: int, r: int):
        if l == r:
            a[2 * l] = allowed_collisions[l]
            return
        mid = get_mid(l, r)
        build(l, mid)
        build(mid + 1, r)
        a[get_id(l, r)] = a[get_id(l, mid)] * a[get_id(mid + 1, r)]

    build(0, n - 2)

    def modify(l: int, r: int, k: int):
        if l == r:
            a[2 * l] = allowed_collisions[k]
            return
        mid = get_mid(l, r)
        if k <= mid:
            modify(l, mid, k)
        else:
            modify(mid + 1, r, k)
        a[get_id(l, r)] = a[get_id(l, mid)] * a[get_id(mid + 1, r)]

    events = []
    for i in range(n - 1):
        d = x[i + 1] - x[i]
        events.append((Fraction(d, v[i + 1] + v[i]), i << 2 | 1))
        events.append((Fraction(d, v[i + 1] - v[i]) if v[i] < v[i + 1] else Fraction(1, 0), i << 2 | 0))
        events.append((Fraction(d, v[i] - v[i + 1]) if v[i] > v[i + 1] else Fraction(1, 0), i << 2 | 3))

    events.sort(reverse=True)

    prev_prob = get_prob()
    ans = Modular(0, 998244353)

    for event in events:
        i = event[1] >> 2
        dir1 = event[1] & 1
        dir2 = (event[1] >> 1) & 1

        allowed_collisions[i].m[dir1][dir2] = p[i + 1] if dir2 else Modular(1 - p[i + 1].value, 998244353)
        modify(0, n - 2, i)
        prob = get_prob()
        if event[0].denominator != 0:
            ans += (prob - prev_prob) * event[0]
        prev_prob = prob

    print(ans)

if __name__ == "__main__":
    main()
