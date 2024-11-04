import sys
from collections import defaultdict
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

def count_lines(points):
    xs = set()
    ys = set()
    for point in points:
        xs.add(point.get_x())
        ys.add(point.get_y())
    return len(xs) + len(ys)

def mod_multiply(a, b):
    return (a * b) % BIG

def mod_add(a, b):
    return (a + b) % BIG

def mod_subtract(a, b):
    return (a - b + BIG) % BIG

def mod_power2(a):
    result = 1
    for _ in range(a):
        result = mod_multiply(result, 2)
    return result

def solve():
    n = int(sys.stdin.readline().strip())
    points = []
