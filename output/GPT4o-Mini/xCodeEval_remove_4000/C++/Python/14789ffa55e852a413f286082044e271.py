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
    def __init__(self, x=0, y=0, i=0):
        self.x = x
        self.y = y
        self.i = i

    def __repr__(self):
        return f"({self.x}, {self.y})"

    def __lt__(self, other):
        if self.x != other.x:
            return self.x < other.x
        return self.y < other.y

def read():
    n = int(sys.stdin.readline().strip())
    a = []
    for i in range(n):
        x, y = map(int, sys.stdin.readline().strip().split())
        a.append(Point(x, y, i + 1))
    s = sys.stdin.readline().strip()
    return n, a, s

def operator_sub(a, b):
    return Point(a.x - b.x, a.y - b.y)

def operator_add(a, b):
    return Point(a.x + b.x, a.y + b.y)

def operator_eq(a, b):
    return (a.x == b.x and a.y == b.y)

def sdist(a, b):
    return (a.x - b.x) ** 2 + (a.y - b.y) ** 2

def dot(a, b):
    return a.x * b.x + a.y * b.y

def cross(a, b):
    return a.x * b.y - a.y * b.x

def build(n, a):
    if n <= 1:
        return a[:n]

    up = [a[0]]
    dw = [a[0]]

    for i in range(1, n):
        if i == n - 1 or cross(operator_sub(a[n - 1], a[0]), operator_sub(a[i], a[0])) >= 0:
            while len(up) > 1 and cross(operator_sub(a[i], up[-2]), operator_sub(up[-1], up[-2])) < 0:
                up.pop()
            up.append(a[i])
        if i == n - 1 or cross(operator_sub(a[n - 1], a[0]), operator_sub(a[i], a[0])) < 0:
            while len(dw) > 1 and cross(operator_sub(a[i], dw[-2]), operator_sub(dw[-1], dw[-2])) > 0:
                dw.pop()
            dw.append(a[i])

    res = up + dw[-2:0:-1]
    return res

def solve(n, a, s):
    a.sort()
    cur = set(a)
    ans = []

    ch = build(n, a)
    ans.append(ch[0])
    if s[0] == 'L':
        ans.append(ch[-1])
    else:
        ans.append(ch[1])
    cur.remove(ch[0])

    for i in range(len(s)):
        n = 0
        for it in cur:
            a[n] = it
            n += 1
        ch = build(n, a)
        pos = ch.index(ans[-1])
        if s[i + 1] == 'L':
            ans.append(ch[(pos - 1 + len(ch)) % len(ch)])
        else:
            ans.append(ch[(pos + 1) % len(ch)])
        cur.remove(ans[-2])

    print(' '.join(str(it.i) for it in ans))

def main():
    input_file = open("input.txt", "r")
    sys.stdin = input_file

    while True:
        try:
            n, a, s = read()
            solve(n, a, s)
        except EOFError:
            break

if __name__ == "__main__":
    main()
