import random
import math
from queue import Queue
from collections import deque

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = math.acos(-1.0)

N = 100 * 1000 + 13

n, m, k = 0, 0, 0
h = 0
a = []

def read():
    global h, n, m, k, a
    try:
        h, n, m, k = map(int, input().split())
        a = []
        for _ in range(n):
            x, y = map(int, input().split())
            a.append((x, y))
        return True
    except:
        return False

def add(x):
    global k, mn
    q = Queue()
    for i in range(k):
        q.put(i)
    while not q.empty():
        v = q.get()
        if mn[v] + x < mn[(v + x) % k]:
            mn[(v + x) % k] = mn[v] + x
            q.put((v + x) % k)

def recalc():
    global n, k, used, mn, a, cur
    cur.clear()
    for i in range(n):
        if not used[i] and mn[a[i][0] % k] <= a[i][0]:
            cur.append((a[i][1], -i))
    cur.sort(reverse=True)

def solve():
    global k, h, m, mn, used, a, cur
    mn = [h + 1] * k
    mn[1] = 1
    used = [False] * N
    cur = []
    recalc()
    for _ in range(m):
        t = int(input())
        if t == 1:
            x = int(input())
            add(x)
            recalc()
        elif t == 2:
            x, y = map(int, input().split())
            x -= 1
            if mn[a[x][0] % k] <= a[x][0]:
                cur.remove((a[x][1], -x))
            a[x] = (a[x][0], a[x][1] - y)
            if mn[a[x][0] % k] <= a[x][0]:
                cur.append((a[x][1], -x))
        elif len(cur) > 0:
            print(cur[0][0])
            used[-cur[0][1]] = True
            cur.pop(0)
        else:
            print(0)

while read():
    solve()
