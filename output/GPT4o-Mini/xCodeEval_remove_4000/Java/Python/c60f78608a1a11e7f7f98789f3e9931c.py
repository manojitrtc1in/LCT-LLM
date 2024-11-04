import sys
from collections import defaultdict
from functools import reduce
from itertools import combinations

BIG = 1000000007

class Point:
    def __init__(self, index, x, y):
        self.index = index
        self.x = x
        self.y = y

    def get_x(self):
        return self.x

    def get_y(self):
        return self.y

def mod_multiply(a, b):
    return (a * b) % BIG

def mod_add(a, b):
    return (a + b) % BIG

def mod_subtract(a, b):
    return (a - b + BIG) % BIG

def id12(a):
    result = 1
    for _ in range(a):
        result = mod_multiply(result, 2)
    return result

def count_lines(points):
    xs = set()
    ys = set()
    for point in points:
        xs.add(point.get_x())
        ys.add(point.get_y())
    return len(xs) + len(ys)

def solve():
    n = int(sys.stdin.readline().strip())
    points = []
    id3 = defaultdict(set)

    for index in range(n):
        x, y = map(int, sys.stdin.readline().strip().split())
        point = Point(index, x, y)
        points.append(point)
        id3[y].add(point)

    id49 = {}
    for point_set in id3.values():
        last_x = None
        for point in point_set:
            if last_x is not None:
                # Create edge between point and last_x (not implemented)
                pass
            last_x = point
            last_y = id49.get(point.get_x())
            if last_y is not None:
                # Create edge between point and last_y (not implemented)
                pass
            id49[point.get_x()] = point

    id35 = {}
    id29 = {}
    points_processed = set()

    for point in points:
        if point not in points_processed:
            structure = set()
            # Check for cycles (not implemented)
            if False:  # Replace with actual cycle check
                id29[point] = structure
            else:
                id35[point] = structure
            points_processed.update(structure)

    result = 1
    for point_set in id35.values():
        result = mod_multiply(result, mod_subtract(id12(count_lines(point_set)), 1))
    for point_set in id29.values():
