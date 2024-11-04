import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def angle(p):
    return math.atan2(p.x, p.y)

def cross_product(a, b):
    return a.x * b.y - b.x * a.y

def dot_product(a, b):
    return a.x * b.x + b.y * a.y

def intersection(a, b):
    a1 = cross_product(b.p - a.q, b.q - b.p)
    a2 = cross_product(a.p - b.q, b.q - b.p)
    if abs(a1 + a2) < 1e-8:
        return []
    else:
        return [(a.p * a1 + a.q * a2) / (a1 + a2)]

def contains(a, b):
    return abs(cross_product(a.q - a.p, b - a.p)) < 1e-8 and dot_product(b - a.p, b - a.q) < 1e-8

def intersection(a, b):
    i = intersection(id4(a), id4(b))
    r = []
    t = []
    if i:
        r = i
    else:
        r = [a.p, a.q, b.p, b.q]
    for p in r:
        if contains(a, p) and contains(b, p):
            t.append(p)
    return t

def solve():
    n = int(input())
    a = []
    index = {}
    for _ in range(n):
        x, y = map(int, input().split())
        a.append(Point(x, y))
        index[(x, y)] = len(a) - 1
    a.sort(key=lambda p: p.x)
    d = input().strip()[::-1]
    ans = [a[0]]
    a = a[1:]
    while a:
        if not d:
            td = 1
        elif d[-1] == 'L':
            td = 1
        else:
            td = -1
        if d:
            d = d[:-1]
        cur = 0
        for i in range(len(a)):
            if cross_product(a[cur] - ans[-1], a[i] - ans[-1]) * td < 0:
                cur = i
        ans.append(a[cur])
        a.pop(cur)
    aaa = [index[(p.x, p.y)] + 1 for p in ans]
    print(aaa)

solve()
