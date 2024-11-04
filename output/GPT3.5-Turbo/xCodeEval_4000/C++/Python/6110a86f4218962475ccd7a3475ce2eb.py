import sys
from collections import deque
from heapq import *
from math import *
from bisect import *
from itertools import *
from functools import *
from operator import *
from fractions import *
from decimal import *
from random import *
from time import *
from copy import *
from queue import *

def read():
    global h, n, m, k, a
    h, n, m, k = map(int, input().split())
    a = []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append((x, y))

def add(x):
    global mn
    q = deque()
    for i in range(k):
        q.append(i)
    while q:
        v = q.popleft()
        if mn[v] + x < mn[(v + x) % k]:
            mn[(v + x) % k] = mn[v] + x
            q.append((v + x) % k)

def recalc():
    global cur
    cur.clear()
    for i in range(n):
        if not used[i] and mn[a[i][0] % k] <= a[i][0]:
            cur.add((a[i][1], -i))

def solve():
    global mn, used, cur
    mn = [h + 1] * k
    mn[1] = 1
    used = [False] * N
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
                cur.add((a[x][1], -x))
        elif cur:
            print(cur[0][0])
            used[-cur[0][1]] = True
            cur.remove(cur[0])
        else:
            print(0)

while True:
    try:
        read()
        solve()
    except EOFError:
        break
