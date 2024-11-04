import sys
import math
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y', 'i'])

def read():
    n = int(sys.stdin.readline().strip())
    a = []
    for i in range(n):
        x, y = map(int, sys.stdin.readline().strip().split())
        a.append(Point(x, y, i + 1))
    s = sys.stdin.readline().strip()
    return n, a, s

def sdist(a, b):
    return (a.x - b.x) ** 2 + (a.y - b.y) ** 2

def dot(a, b):
    return a.x * b.x + a.y * b.y

def cross(a, b):
    return a.x * b.y - a.y * b.x

def build(a, n):
    if n <= 1:
        return a[:n]

    up = [a[0]]
    dw = [a[0]]

    for i in range(1, n):
        if i == n - 1 or cross(Point(a[n - 1].x - a[0].x, a[n - 1].y - a[0].y, -1), Point(a[i].x - a[0].x, a[i].y - a[0].y, -1)) >= 0:
            while len(up) > 1 and cross(Point(a[i].x - up[-2].x, a[i].y - up[-2].y, -1), Point(up[-1].x - up[-2].x, up[-1].y - up[-2].y, -1)) < 0:
                up.pop()
            up.append(a[i])
        if i == n - 1 or cross(Point(a[n - 1].x - a[0].x, a[n - 1].y - a[0].y, -1), Point(a[i].x - a[0].x, a[i].y - a[0].y, -1)) < 0:
            while len(dw) > 1 and cross(Point(a[i].x - dw[-2].x, a[i].y - dw[-2].y, -1), Point(dw[-1].x - dw[-2].x, dw[-1].y - dw[-2].y, -1)) > 0:
                dw.pop()
            dw.append(a[i])

    res = up + dw[-2:0:-1]
    return res

def solve(n, a, s):
    a.sort(key=lambda p: (p.x, p.y))
    cur = set(a)
    ans = []

    ch = build(a, n)
    ans.append(ch[0])
    if s[0] == 'L':
        ans.append(ch[-1])
    else:
        ans.append(ch[1])
    cur.remove(ch[0])

    for i in range(len(s) - 1):
        n = 0
        for it in cur:
            a[n] = it
            n += 1
        ch = build(a, n)
        pos = ch.index(ans[-1])
        if s[i + 1] == 'L':
            ans.append(ch[(pos - 1 + len(ch)) % len(ch)])
        else:
            ans.append(ch[(pos + 1) % len(ch)])
        cur.remove(ans[-2])

    print(' '.join(str(it.i) for it in ans))

if __name__ == "__main__":
    n, a, s = read()
    solve(n, a, s)
