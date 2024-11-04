import sys
from collections import defaultdict
from math import atan2, sqrt
from random import randint, seed

def fast_input():
    return sys.stdin.readline().strip()

class Vector2D:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    @classmethod
    def from_list(cls, v):
        assert len(v) == 2
        return cls(v[0], v[1])

    def direction(self):
        return -1 if self.x == 0 and self.y == 0 else (1 if self.x < 0 else (1 if self.y < 0 else 0))

    def __sub__(self, other):
        return Vector2D(self.x - other.x, self.y - other.y)

    def __add__(self, other):
        return Vector2D(self.x + other.x, self.y + other.y)

    def __mul__(self, scalar):
        return Vector2D(self.x * scalar, self.y * scalar)

    def __truediv__(self, scalar):
        return Vector2D(self.x / scalar, self.y / scalar)

def cross_product(a, b):
    return a.x * b.y - b.x * a.y

def dot_product(a, b):
    return a.x * b.x + a.y * b.y

def read_vector_list(n):
    return [Vector2D(*map(int, fast_input().split())) for _ in range(n)]

def main():
    n = int(fast_input())
    a = read_vector_list(n)
    index = {(v.x, v.y): i for i, v in enumerate(a)}
    a.sort(key=lambda v: v.x)
    d = fast_input()[::-1]
    ans = [a.pop(0)]

    while a:
        td = 1 if not d else (1 if d[-1] == 'L' else -1)
        if d:
            d = d[:-1]
        cur = 0
        for i in range(len(a)):
            if cross_product(a[cur] - ans[-1], a[i] - ans[-1]) * td < 0:
                cur = i
        ans.append(a.pop(cur))

    result = [index[(t.x, t.y)] + 1 for t in ans]
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    seed()
    main()
