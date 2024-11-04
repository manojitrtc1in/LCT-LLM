import sys
from collections import deque
from typing import List, Tuple, Set, Dict

class Point:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

def count_lines(points: Set[Point]) -> int:
    xs = set()
    ys = set()
    for point in points:
        xs.add(point.x)
        ys.add(point.y)
    return len(xs) + len(ys)

def mod_multiply(a: int, b: int, mod: int) -> int:
    return (a * b) % mod

def mod_add(a: int, b: int, mod: int) -> int:
    return (a + b) % mod

def mod_subtract(a: int, b: int, mod: int) -> int:
    return (a - b + mod) % mod

def mod_power2(a: int, mod: int) -> int:
    result = 1
    for _ in range(a):
        result = mod_multiply(result, 2, mod)
    return result

