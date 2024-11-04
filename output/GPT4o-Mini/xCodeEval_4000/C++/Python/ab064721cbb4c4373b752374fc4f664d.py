import sys
import random
from math import acos

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = acos(-1.0)

N = 2000 + 7

class Point:
    def __init__(self, x=0, y=0, i=-1):
        self.x = x
        self.y = y
        self.i = i

    def __lt__(self, other):
        if self.x != other.x:
            return self.x < other.x
        return self.y < other.y

    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

def sqr(a):
    return a * a

def sdist(a, b):
    return sqr(a.x - b.x) + sqr(a.y - b.y)

def dot(a, b):
    return a.x * b.x + a.y * b.y

def cross(a, b):
    return a.x * b.y - a.y * b.x

def build(points, n):
    if n <= 1:
        return points[:n]

    up = [points[0]]
    dw = [points[0]]

    for i in range(1, n):
        if i == n - 1 or cross(points[n - 1] - points[0], points[i] - points[0]) >= 0:
            while len(up) > 1 and cross(points[i] - up[-2], up[-1] - up[-2]) < 0:
                up.pop()
            up.append(points[i])
        if i == n - 1 or cross(points[n - 1] - points[0], points[i] - points[0]) < 0:
            while len(dw) > 1 and cross(points[i] - dw[-2], dw[-1] - dw[-2]) > 0:
                dw.pop()
            dw.append(points[i])

    res = up + dw[-2:0:-1]
    return res

def read():
    n = int(sys.stdin.readline().strip())
    points = []
    for i in range(n):
        x, y = map(int, sys.stdin.readline().strip().split())
        points.append(Point(x, y, i + 1))
    s = sys.stdin.readline().strip()
    return points, n, s

def solve(points, n, s):
    points.sort()
    ans = []

    ch = build(points, n)
    ans.append(ch[0])
    if s[0] == 'L':
        ans.append(ch[-1])
    else:
        ans.append(ch[1])

    for i in range(len(s)):
        x = points.index(ans[-2])
        points = points[:x] + points[x + 1:]
        n -= 1
        ch = build(points, n)
        pos = ch.index(ans[-1])
        if s[i + 1] == 'L':
            ans.append(ch[(pos - 1 + len(ch)) % len(ch)])
        else:
            ans.append(ch[(pos + 1) % len(ch)])

    print(' '.join(str(it.i) for it in ans))

def main():
    points, n, s = read()
    solve(points, n, s)

if __name__ == "__main__":
    main()
