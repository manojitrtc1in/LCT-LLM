from typing import List
from math import isclose

class Modular:
    def __init__(self, value):
        self.value = value
    
    def __add__(self, other):
        return Modular((self.value + other.value) % self.mod())
    
    def __sub__(self, other):
        return Modular((self.value - other.value) % self.mod())
    
    def __mul__(self, other):
        return Modular((self.value * other.value) % self.mod())
    
    def __truediv__(self, other):
        return Modular(self.value * self.inverse(other.value))
    
    def __eq__(self, other):
        return self.value == other.value
    
    def __lt__(self, other):
        return self.value < other.value
    
    def __str__(self):
        return str(self.value)
    
    def __repr__(self):
        return str(self.value)
    
    @staticmethod
    def mod():
        return 998244353
    
    @staticmethod
    def inverse(a):
        m = Modular.mod()
        u, v = 0, 1
        while a != 0:
            t = m // a
            m -= t * a
            a, m = m, a
            u -= t * v
            u, v = v, u
        assert m == 1
        return u

class Mat:
    def __init__(self, m):
        self.m = m
    
    def __getitem__(self, i):
        return self.m[i]
    
    def __setitem__(self, i, value):
        self.m[i] = value
    
    def __mul__(self, other):
        c = [[0, 0], [0, 0]]
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    c[i][j] += self.m[i][k] * other.m[k][j]
        return Mat(c)

def solve(n: int, x: List[int], v: List[int], p: List[int]) -> Modular:
    if n == 1:
        return Modular(0)
    
    inv_100 = Modular(Modular.inverse(100))
    
    allowed_collisions = []
    for i in range(n - 1):
        mat = Mat([[0, p[i + 1]], [0, 0]])
        allowed_collisions.append(mat)
    
    a = [None] * (2 * (n - 1) - 1)
    def get_prob() -> Modular:
        return to_right * (a[1][0] + a[1][1]) + (1 - to_right) * (a[0][0] + a[0][1])
    
    def build(l: int, r: int) -> None:
        if l == r:
            a[2 * l] = allowed_collisions[l]
            return
        mid = (l + r) // 2
        build(l, mid)
        build(mid + 1, r)
        a[(l + r) | (l != r)] = a[l, mid] * a[mid + 1, r]
    
    build(0, n - 2)
    
    events = []
    for i in range(n - 1):
        d = x[i + 1] - x[i]
        events.append(((d, v[i + 1] + v[i]), i << 2 | 1))
        events.append(((d, v[i + 1] - v[i]), i << 2 | 0))
        events.append(((d, v[i] - v[i + 1]), i << 2 | 3))
    
    events.sort(reverse=True)
    
    prev_prob = get_prob()
    ans = Modular(0)
    
    for event in events:
        i = event[1] >> 2
        dir1 = (event[1] >> 0) & 1
        dir2 = (event[1] >> 1) & 1
        
        allowed_collisions[i][dir1][dir2] = p[i + 1] if dir2 else 1 - p[i + 1]
        modify(0, n - 2, i)
        prob = get_prob()
        if not isclose(event[0][1], 0):
            ans += (prob - prev_prob) * event[0]
        prev_prob = prob
    
    return ans
