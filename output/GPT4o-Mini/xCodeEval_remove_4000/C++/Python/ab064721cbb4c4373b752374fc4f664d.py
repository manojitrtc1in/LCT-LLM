import sys
import time
from collections import namedtuple
from random import randint, seed

li = int
ld = float
pt = namedtuple('pt', ['x', 'y'])

def operator_lt(a, b):
    if a.x != b.x:
        return a.x < b.x
    return a.y < b.y

def operator_eq(a, b):
    return a.x == b.x and a.y == b.y

def sdist(a, b):
    return (a.x - b.x) ** 2 + (a.y - b.y) ** 2

def dot(a, b):
    return a.x * b.x + a.y * b.y

def cross(a, b):
    return a.x * b.y - a.y * b.x

def build(points):
    if len(points) <= 1:
        return points

    up = [points[0]]
    dw = [points[0]]

    for i in range(1, len(points)):
        if i == len(points) - 1 or cross(points[len(points) - 1] - points[0], points[i] - points[0]) >= 0:
            while len(up) > 1 and cross(points[i] - up[-2], up[-1] - up[-2]) < 0:
                up.pop()
            up.append(points[i])
        if i == len(points) - 1 or cross(points[len(points) - 1] - points[0], points[i] - points[0]) < 0:
            while len(dw) > 1 and cross(points[i] - dw[-2], dw[-1] - dw[-2]) > 0:
                dw.pop()
            dw.append(points[i])

    res = up + dw[-2:0:-1]
    return res

def solve(points, s):
    points.sort(key=lambda p: (p.x, p.y))
    ans = []

    ch = build(points)
    ans.append(ch[0])
    if s[0] == 'L':
        ans.append(ch[-1])
    else:
        ans.append(ch[1])

    for i in range(len(s)):
        x = points.index(ans[-2])
        points = points[:x] + points[x + 1:]
        n = len(points)
        ch = build(points)
        pos = ch.index(ans[-1])
        if s[i + 1] == 'L':
            ans.append(ch[(pos - 1 + len(ch)) % len(ch)])
        else:
            ans.append(ch[(pos + 1) % len(ch)])

    print(' '.join(str(it.i) for it in ans))

def read():
    n = int(sys.stdin.readline().strip())
    points = []
    for i in range(n):
        x, y = map(int, sys.stdin.readline().strip().split())
        points.append(pt(x, y, i + 1))
    s = sys.stdin.readline().strip()
    return n, points, s

if __name__ == "__main__":
    seed(int(time.time()))
    tt = time.clock()

    while True:
        try:
            n, points, s = read()
            solve(points, s)
            print(f'TIME = {time.clock() - tt}')
            tt = time.clock()
        except EOFError:
            break
