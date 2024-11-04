import sys
import math
import random

def read():
    n = int(input())
    a = []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append((x, y))
    s = input().strip()
    return n, a, s

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
    
    for point in ans:
        print(point, end=' ')
    print()

if __name__ == '__main__':
    n, a, s = read()
    solve(n, a, s)
