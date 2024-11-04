import sys
from collections import defaultdict
from itertools import combinations

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def count_lines(points):
    xs = set()
    ys = set()
    for point in points:
        xs.add(point.x)
        ys.add(point.y)
    return len(xs) + len(ys)

def mod_multiply(a, b, mod):
    return (a * b) % mod

def mod_add(a, b, mod):
    return (a + b) % mod

def mod_subtract(a, b, mod):
    return (a - b + mod) % mod

def mod_pow(a, b, mod):
    result = 1
    while b > 0:
        if b % 2 == 1:
            result = mod_multiply(result, a, mod)
        a = mod_multiply(a, a, mod)
        b //= 2
    return result

def solve():
    n = int(input())
    points = []
    id3 = defaultdict(list)
    for _ in range(n):
        x, y = map(int, input().split())
        point = Point(x, y)
        points.append(point)
        id3[y].append(point)
    
    id49 = {}
    for y, point_list in id3.items():
        point_list.sort(key=lambda p: p.x)
        last_x = None
        for point in point_list:
            if last_x is not None:
                last_x.add_neighbor(point)
                point.add_neighbor(last_x)
            last_x = point
            last_y = id49.get(point.x)
            if last_y is not None:
                last_y.add_neighbor(point)
                point.add_neighbor(last_y)
            id49[point.x] = point
    
    id35 = defaultdict(set)
    id29 = defaultdict(set)
    points_processed = set()
    for point in points:
        if point not in points_processed:
            structure = set()
            if point.cycle(structure):
                id29[point] = structure
            else:
                id35[point] = structure
            points_processed.update(structure)
    
    result = 1
    for structure in id35.values():
        result = mod_multiply(result, mod_subtract(mod_pow(2, count_lines(structure), MOD), 1), MOD)
    
    for structure in id29.values():
        result = mod_multiply(result, mod_pow(2, count_lines(structure), MOD), MOD)
