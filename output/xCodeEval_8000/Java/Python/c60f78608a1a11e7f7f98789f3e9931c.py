class Point:
    def __init__(self, index, x, y):
        self.index = index
        self.x = x
        self.y = y

def count_lines(points):
    xs = sorted(set(point.x for point in points))
    ys = sorted(set(point.y for point in points))
    return len(xs) + len(ys)

def mod_multiply(a, b, mod):
    return (a * b) % mod

def mod_add(a, b, mod):
    return (a + b) % mod

def mod_subtract(a, b, mod):
    return (a - b + mod) % mod

def mod_power2(a, mod):
    result = 1
    for _ in range(a):
        result = mod_multiply(result, 2, mod)
    return result

def solve():
    n = int(input())
    points = []
    y2points = {}
    for index in range(n):
        x, y = map(int, input().split())
        point = Point(index, x, y)
        points.append(point)
        if y in y2points:
