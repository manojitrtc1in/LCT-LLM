import math
import random

class point:
    def __init__(self, x, y, i):
        self.x = x
        self.y = y
        self.i = i
    
    def __str__(self):
        return f"({self.x}, {self.y})"
    
    def __lt__(self, other):
        if self.x != other.x:
            return self.x < other.x
        return self.y < other.y

def read():
    n = int(input())
    a = []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append(point(x, y, len(a) + 1))
    s = input()
    return n, a, s

def dist(a, b):
    return (a.x - b.x) ** 2 + (a.y - b.y) ** 2

def dot(a, b):
    return a.x * b.x + a.y * b.y

def cross(a, b):
    return a.x * b.y - a.y * b.x

def build(n, a):
    if n <= 1:
        return a
    
    up = [a[0]]
    dw = [a[0]]
    
    for i in range(1, n):
        if i == n - 1 or cross(a[n - 1] - a[0], a[i] - a[0]) >= 0:
            while len(up) > 1 and cross(a[i] - up[-2], up[-1] - up[-2]) < 0:
                up.pop()
            up.append(a[i])
        if i == n - 1 or cross(a[n - 1] - a[0], a[i] - a[0]) < 0:
            while len(dw) > 1 and cross(a[i] - dw[-2], dw[-1] - dw[-2]) > 0:
                dw.pop()
            dw.append(a[i])
    
    res = up
    for i in range(len(dw) - 2, 0, -1):
        res.append(dw[i])
    
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
        n = len(cur)
        a = list(cur)
        ch = build(n, a)
        pos = ch.index(ans[-1])
        if s[i + 1] == 'L':
            ans.append(ch[(pos - 1 + len(ch)) % len(ch)])
        else:
            ans.append(ch[(pos + 1) % len(ch)])
        cur.remove(ans[-2])
    
    for p in ans:
        print(p.i, end=' ')
    print()

if __name__ == "__main__":
    n, a, s = read()
    solve(n, a, s)
