from collections import defaultdict
from math import gcd
import sys
import time

MOD = 1000000007
INF = float('inf')
L = 360360
N = 100009

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def check_min(a, b):
    if b < a:
        return b
    return a

def bfs(aa, lcm, adj):
    D = [INF] * (3 * lcm)
    D[0] = 0
    s = aa

    for i in range(3 * lcm):
        u = (s - i) % lcm
        if u < 0:
            u += lcm

        Du = D[i]
        if Du == INF:
            continue

        for neighbor in adj[u]:
            D[i + neighbor] = check_min(D[i + neighbor], Du + 1)

    return D

def main():
    a, b, k = read_ints()
    lcm = 1
    for i in range(2, k + 1):
        lcm = lcm * i // gcd(lcm, i)

    adj = defaultdict(list)
    for i in range(lcm):
        adj[i].append(1)
        for j in range(2, k + 1):
            if i % j != 0:
                adj[i].append(i % j)

    tt = (a - b) // lcm
    aa = a % lcm
    bb = b % lcm

    D = bfs(aa, lcm, adj)

    bb = (aa - bb + 3 * lcm) % lcm
    tt *= (D[bb + lcm] - D[bb])

    print(D[bb] + tt)

if __name__ == "__main__":
    main()
