from typing import List
from math import isclose

class Mint:
    def __init__(self, value: int):
        self.value = value

    def __add__(self, other: 'Mint') -> 'Mint':
        return Mint((self.value + other.value) % Mint.mod())

    def __sub__(self, other: 'Mint') -> 'Mint':
        return Mint((self.value - other.value + Mint.mod()) % Mint.mod())

    def __mul__(self, other: 'Mint') -> 'Mint':
        return Mint((self.value * other.value) % Mint.mod())

    def __truediv__(self, other: 'Mint') -> 'Mint':
        return self * other.inv()

    def __eq__(self, other: 'Mint') -> bool:
        return self.value == other.value

    def __ne__(self, other: 'Mint') -> bool:
        return self.value != other.value

    def __str__(self) -> str:
        return str(self.value)

    def __repr__(self) -> str:
        return str(self.value)

    @staticmethod
    def mod() -> int:
        return 998244353

    @staticmethod
    def inv() -> 'Mint':
        return Mint(pow(Mint.mod(), -1, Mint.mod()))

    @staticmethod
    def normalize(x: int) -> int:
        return x % Mint.mod()

    @staticmethod
    def power(a: 'Mint', b: int) -> 'Mint':
        res = Mint(1)
        while b > 0:
            if b & 1:
                res *= a
            a *= a
            b >>= 1
        return res

class Mat:
    def __init__(self, m: List[List[Mint]]):
        self.m = m

    def __getitem__(self, i: int) -> List[Mint]:
        return self.m[i]

    def __mul__(self, other: 'Mat') -> 'Mat':
        c = [[Mint(0) for _ in range(2)] for _ in range(2)]
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    c[i][j] += self.m[i][k] * other.m[k][j]
        return Mat(c)

def solve(n: int, x: List[int], v: List[int], p: List[Mint]) -> Mint:
    if n == 1:
        return Mint(0)
    
    id2 = [Mat([[Mint(0), p[i+1]], [Mint(0), Mint(0)]]) for i in range(n-1)]
    
    id1 = Mint(1) / Mint(100)
    
    a = [None] * (2 * (n - 1) - 1)
    
    def get_prob() -> Mint:
        return to_right * (mat[1][0] + mat[1][1]) + (Mint(1) - to_right) * (mat[0][0] + mat[0][1])
    
    def build(l: int, r: int) -> None:
        if l == r:
            a[2 * l] = id2[l]
            return
        mid = (l + r) // 2
        build(l, mid)
        build(mid + 1, r)
        a[(l + r) | (l != r)] = a[l] * a[mid + 1]
    
    build(0, n - 2)
    
    events = []
    
    for i in range(n - 1):
        d = x[i + 1] - x[i]
        events.append(((d, v[i + 1] + v[i]), i << 2 | 1))
        events.append(((d, v[i + 1] - v[i]), i << 2 | 0))
        events.append(((d, v[i] - v[i + 1]), i << 2 | 3))
    
    events.sort()
    
    prev_prob = get_prob()
    ans = Mint(0)
    
    for event in reversed(events):
        i = event[1] >> 2
        dir1 = (event[1] >> 0) & 1
        dir2 = (event[1] >> 1) & 1
        
        id2[i][dir1][dir2] = p[i + 1] if dir2 else Mint(1) - p[i + 1]
        a[2 * i] = id2[i]
        
        prob = get_prob()
        if not isclose(event[0][1], 0):
            ans += (prob - prev_prob) * event[0]
        prev_prob = prob
    
    return ans

n = int(input())
x = list(map(int, input().split()))
v = list(map(int, input().split()))
p = [Mint(int(x)) for x in input().split()]

print(solve(n, x, v, p))
