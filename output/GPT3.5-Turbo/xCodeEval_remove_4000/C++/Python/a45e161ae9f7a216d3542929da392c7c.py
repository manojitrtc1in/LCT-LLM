import math

def id1(a, b):
    return a * b // math.gcd(a, b)

def f(s, t, D):
    return D[t]

def bfs(aa, lcm, adj, D):
    s = aa
    D = [float('inf')] * (3 * lcm)
    D[0] = 0

    for i in range(3 * lcm):
        u = (s - i) % lcm
        if u < 0:
            u += lcm

        Du = D[i]

        if Du == float('inf'):
            continue

        for j in range(len(adj[u])):
            D[i + adj[u][j]] = min(D[i + adj[u][j]], Du + 1)

    return D

a, b, k = map(int, input().split())

lcm = 1
for i in range(2, k + 1):
    lcm = id1(lcm, i)

adj = [[] for _ in range(lcm)]
for i in range(lcm):
    adj[i].append(1)
    for j in range(2, k + 1):
        if i % j != 0:
            adj[i].append(i % j)

tt = (a - b) // lcm

aa = a % lcm
bb = b % lcm

D = bfs(aa, lcm, adj, [])

tt *= (D[bb + lcm] - D[bb])

print(D[bb] + tt)
