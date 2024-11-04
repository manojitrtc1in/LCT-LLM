import sys

def add_edge(x, y, c, w):
    global m
    suc[m] = hd[x]
    to[m] = y
    cap[m] = c
    cst[m] = w
    hd[x] = m
    m += 1

def id11(x, y, c, w):
    if not w:
        add_edge(x, y, c, 0)
        add_edge(y, x, c, 0)
    else:
        add_edge(x, y, c, w)
        add_edge(y, x, c, w)

def spfa():
    global cz, op
    cz = 0
    op = 1
    inQ = [False] * n
    D = [float('inf')] * n
    F = [0] * n
    D[s] = 0
    F[s] = float('inf')
    while cz < op:
        u = Q[cz & mask]
        inQ[u] = False
        cz += 1
        for i in range(hd[u], -1, -1):
            v = to[i]
            c = cap[i]
            w = cst[i]
            if c and D[v] > D[u] + w:
                D[v] = D[u] + w
                F[v] = min(F[u], c)
                pre[v] = i
                if not inQ[v]:
                    Q[op & mask] = v
                    inQ[v] = True
                    op += 1
    return D[t] != float('inf')

def add_path():
    global flow, cost
    flow += F[t]
    u = t
    while u != s:
        i = pre[u]
        v = to[i ^ 1]
        f = F[t]
        c = cap[i]
        w = cst[i]
        cost += F[t] * w
        v = u
    flow += f
    c -= f

def id9():
    global flow, cost
    to[m] = s
    flow = 0
    cost = 0
    while spfa():
        add_path()
    return (cost, flow)

def main():
    n, m = map(int, input().split())
    c = []
    for _ in range(n):
        c.append(list(map(int, input().split())))
