import sys
import random
from collections import defaultdict
from math import atan2, sqrt
from itertools import islice

def in_int():
    return int(sys.stdin.readline().strip())

def in_str():
    return sys.stdin.readline().strip()

def in_list_int():
    return list(map(int, sys.stdin.readline().strip().split()))

def ou(data):
    print(' '.join(map(str, data)))

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def cross_product(self, other):
        return self.x * other.y - other.x * self.y

    def dot_product(self, other):
        return self.x * other.x + self.y * other.y

def cross_product(a, b):
    return a.cross_product(b)

def angle(a):
    return atan2(a.y, a.x)

def contains(a, b):
    return abs(cross_product(a.q - a.p, b - a.p)) < 1e-8 and dot_product(b - a.p, b - a.q) < 1e-8

def intersection(a, b):
    a1 = cross_product(b.p - a.q, b.q - b.p)
    a2 = cross_product(a.p - b.q, b.q - b.p)
    if abs(a1 + a2) < 1e-8:
        return []
    else:
        return [(a.p * a1 + a.q * a2) / (a1 + a2)]

def main():
    n = in_int()
    a = [Point(*in_list_int()) for _ in range(n)]
    index = {(p.x, p.y): i for i, p in enumerate(a)}
    
    a.sort(key=lambda p: p.x)
    d = in_str()[::-1]
    
    ans = [a[0]]
    a.pop(0)
    
    while a:
        td = 1 if not d else (1 if d[-1] == 'L' else -1)
        if d:
            d = d[:-1]
        
        cur = 0
        for i in range(len(a)):
            if cross_product(a[cur] - ans[-1], a[i] - ans[-1]) * td < 0:
                cur = i
        
        ans.append(a[cur])
        a.pop(cur)
    
    aaa = [index[(t.x, t.y)] + 1 for t in ans]
    ou(aaa)

if __name__ == "__main__":
    main()
