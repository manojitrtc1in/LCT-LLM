import sys
from collections import deque
from math import gcd

L = 360360
INF = float('inf')

def lcm(a, b):
    return a * b // gcd(a, b)

def bfs(s, adj, D, lcm):
    for i in range(3 * lcm):
        u = (s - i) % lcm
        if u < 0:
            u += lcm
        Du = D[i]
        if Du == INF:
            continue
        for v in adj[u]:
            if D[i + v] > Du + 1:
                D[i + v] = Du + 1

def main():
    a, b, k = map(int, sys.stdin.readline().split())
    
    lcm_value = 1
    for i in range(2, k + 1):
        lcm_value = lcm(lcm_value, i)

    adj = [[] for _ in range(lcm_value)]
    for i in range(lcm_value):
        adj[i].append(1)
        for j in range(2, k + 1):
            if i % j != 0:
                adj[i].append(i % j)

    tt = (a - b) // lcm_value
    aa = a % lcm_value
    bb = b % lcm_value

    D = [INF] * (3 * lcm_value)
    D[0] = 0

    bfs(aa, adj, D, lcm_value)

    bb = (aa - bb + 3 * lcm_value) % lcm_value
    tt *= (D[bb + lcm_value] - D[bb])

    print(D[bb] + tt)

if __name__ == "__main__":
    main()
