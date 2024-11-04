from math import gcd

def id2(a, b):
    return a * b // gcd(a, b)

a, b, k = map(int, input().split())
lcm = 1
for i in range(2, k+1):
    lcm = id2(lcm, i)

adj = [[] for _ in range(lcm)]
for i in range(lcm):
    adj[i].append(1)
    for j in range(2, k+1):
        if i % j != 0:
            adj[i].append(i % j)

tt = (a - b) // lcm

aa = a % lcm
bb = b % lcm

D = [float('inf')] * (3 * lcm)
D[0] = 0

def f(s, t):
    return D[t]

def bfs():
    s = aa
    for i in range(3 * lcm):
        u = (s - i) % lcm
        Du = D[i]
        if Du == float('inf'):
            continue
        for j in range(len(adj[u])):
            D[i + adj[u][j]] = min(D[i + adj[u][j]], Du + 1)

bfs()

bb = (aa - bb + 3 * lcm) % lcm

tt *= (D[bb + lcm] - D[bb])

print(D[bb] + tt)
