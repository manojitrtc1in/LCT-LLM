import math

def lcm(a, b):
    return a * b // math.gcd(a, b)

def f(s, t, D):
    return D[t]

def bfs(aa, adj, D, lcm):
    s = aa
    D[0] = 0

    for i in range(3 * lcm):
        u = (s - i) % lcm
        if u < 0:
            u += lcm

        Du = D[i]

        if Du == math.inf:
            continue

        for j in range(len(adj[u])):
            D[i + adj[u][j]] = min(D[i + adj[u][j]], Du + 1)

def solve(a, b, k):
    lcm_val = 1
    for i in range(2, k + 1):
        lcm_val = lcm(lcm_val, i)

    adj = [[] for _ in range(lcm_val)]

    for i in range(lcm_val):
        adj[i].append(1)
        for j in range(2, k + 1):
            if i % j != 0:
                adj[i].append(i % j)

    aa = a % lcm_val
    bb = b % lcm_val

    D = [math.inf] * (3 * lcm_val)
    bfs(aa, adj, D, lcm_val)

    bb = (aa - bb + 3 * lcm_val) % lcm_val

    tt = (a - b) // lcm_val
    tt *= (D[bb + lcm_val] - D[bb])

    return D[bb] + tt

a, b, k = map(int, input().split())
print(solve(a, b, k))
