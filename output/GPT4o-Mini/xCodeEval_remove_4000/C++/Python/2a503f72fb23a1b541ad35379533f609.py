import sys
from collections import deque
from math import inf

input = sys.stdin.read
data = input().split()

N = 65536
M = int(1e6) + 9

D = [0] * N
hd = [0] * N
suc = [0] * M
to = [0] * M
cap = [0] * M
cst = [0] * M
n = m = s = t = 0
flow = cost = 0
mask = 65535

def add_edge(x, y, c, w):
    global m
    suc[m] = hd[x]
    to[m] = y
    cap[m] = c
    cst[m] = w
    hd[x] = m
    m += 1
    suc[m] = hd[y]
    to[m] = x
    cap[m] = 0
    cst[m] = -w
    hd[y] = m
    m += 1

def id11(x, y, c, w):
    if not w:
        suc[m] = hd[x]
        to[m] = y
        cap[m] = c
        cst[m] = 0
        hd[x] = m
        m += 1
        suc[m] = hd[y]
        to[m] = x
        cap[m] = c
        cst[m] = 0
        hd[y] = m
        m += 1
    else:
        add_edge(x, y, c, w)
        add_edge(y, x, c, w)

def id5(x, y, c, w):
    id11(x, y, c, 0)
    id11(x, y, inf, w)

Q = [0] * N
F = [0] * N
pre = [0] * N
cz = op = 0
inQ = [False] * N

def spfa():
    global cz, op
    cz = 0
    op = 1
    inQ[:] = [False] * n
    D[Q[cz] = s] = 0
    F[s] = inf
    while cz < op:
        u = Q[cz & mask]
        cz += 1
        inQ[u] = False
