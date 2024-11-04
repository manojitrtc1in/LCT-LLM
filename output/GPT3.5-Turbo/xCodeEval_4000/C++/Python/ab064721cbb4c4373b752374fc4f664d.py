import random
import math

def sqr(a):
    return a * a

def sz(a):
    return len(a)

def all(a):
    return a

def forn(n):
    return range(n)

def fore(l, r):
    return range(l, r)

class pt:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def __str__(self):
    return "(" + str(self.x) + ", " + str(self.y) + ")"

def __lt__(self, other):
    if self.x != other.x:
        return self.x < other.x
    return self.y < other.y

class point:
    def __init__(self, x, y, i):
        self.x = x
        self.y = y
        self.i = i

def __str__(self):
    return "(" + str(self.x) + ", " + str(self.y) + ")"

def __sub__(self, other):
    return point(self.x - other.x, self.y - other.y, -1)

def __add__(self, other):
    return point(self.x + other.x, self.y + other.y, -1)

def __eq__(self, other):
    return self.x == other.x and self.y == other.y

def sdist(a, b):
    return sqr(a.x - b.x) + sqr(a.y - b.y)

def dot(a, b):
    return a.x * b.x + a.y * b.y

def cross(a, b):
    return a.x * b.y - a.y * b.x

def build():
    if n <= 1:
        return a[:n]
    
    up = []
    dw = []
    up.append(a[0])
    dw.append(a[0])
    
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

def solve():
    a.sort()
    ans = []
    
    ch = build()
    ans.append(ch[0])
    if s[0] == 'L':
        ans.append(ch[-1])
    else:
        ans.append(ch[1])
    
    for i in range(sz(s)):
        x = a.index(ans[-2])
        for j in range(x + 1, n):
            a[j - 1] = a[j]
        n -= 1
        ch = build()
        pos = ch.index(ans[-1])
        if s[i + 1] == 'L':
            ans.append(ch[(pos - 1 + sz(ch)) % sz(ch)])
        else:
            ans.append(ch[(pos + 1) % sz(ch)])
    
    for it in ans:
        print(it.i, end=" ")
    print()

if __name__ == "__main__":
    n = int(input())
    a = []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append(point(x, y, _ + 1))
    s = input()
    solve()
