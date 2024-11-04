import math
from typing import List, Tuple

class Vector2D:
    def __init__(self, x: int = 0, y: int = 0):
        self.x = x
        self.y = y

    def __sub__(self, other: 'Vector2D') -> 'Vector2D':
        return Vector2D(self.x - other.x, self.y - other.y)

    def __mul__(self, scalar: int) -> 'Vector2D':
        return Vector2D(self.x * scalar, self.y * scalar)

    def __truediv__(self, scalar: int) -> 'Vector2D':
        return Vector2D(self.x / scalar, self.y / scalar)

    def dir(self) -> int:
        if self.x:
            return 1 if self.x < 0 else -1
        elif self.y:
            return 1 if self.y < 0 else -1
        else:
            return -1

    def __lt__(self, other: 'Vector2D') -> bool:
        t = self.dir() - other.dir()
        return t < 0 if t else self.x * other.y - other.x * self.y < 0

    def __str__(self) -> str:
        return f"{self.x} {self.y}"

class Line2D:
    def __init__(self, p: Vector2D, q: Vector2D):
        self.p = p
        self.q = q
        self.a = math.atan2(p.x - q.x, p.y - q.y)

class Segment2D:
    def __init__(self, p: Vector2D, q: Vector2D):
        self.p = p
        self.q = q
        self.a = math.atan2(p.x - q.x, p.y - q.y)

    def __str__(self) -> str:
        return f"{self.p} {self.q}"

def intersection(a: Line2D, b: Line2D) -> List[Vector2D]:
    a1 = (b.p - a.q).cross_product(b.q - b.p)
    a2 = (a.p - b.q).cross_product(b.q - b.p)
    if abs(a1 + a2) < 1e-8:
        return []
    else:
        return [(a.p * a1 + a.q * a2) / (a1 + a2)]

def contains(a: Segment2D, b: Vector2D) -> bool:
    return abs((a.q - a.p).cross_product(b - a.p)) < 1e-8 and (b - a.p).dot_product(b - a.q) < 1e-8

def intersection_segments(a: Segment2D, b: Segment2D) -> List[Vector2D]:
    i = intersection(Line2D(a.p, a.q), Line2D(b.p, b.q))
    r, t = [], []
    if i:
        r = i
    else:
        r = [a.p, a.q, b.p, b.q]
    for p in r:
        if contains(a, p) and contains(b, p):
            t.append(p)
    return t

def solve(n: int, points: List[Tuple[int, int]], d: str) -> List[int]:
    a = [Vector2D(x, y) for x, y in points]
    index = {point: i for i, point in enumerate(a)}
    a.sort(key=lambda p: p.x)
    ans = [a[0]]
    a = a[1:]
    while a:
        td = 1 if not d or d[-1] == 'L' else -1
        if d:
            d = d[:-1]
        cur = 0
        for i, point in enumerate(a):
            if (a[cur] - ans[-1]).cross_product(point - ans[-1]) * td < 0:
                cur = i
        ans.append(a[cur])
        a.pop(cur)
    return [index[point] + 1 for point in ans]

n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
d = input().strip()[::-1]
result = solve(n, points, d)
print(result)
