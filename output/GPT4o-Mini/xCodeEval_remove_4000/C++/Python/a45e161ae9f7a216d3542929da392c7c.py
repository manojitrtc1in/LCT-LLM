from collections import deque
import sys
import math

input = sys.stdin.read
MOD = int(1e7 + 9)
INF = 0x3f3f3f3f
L = 360360
N = 100009

def id1(a, b):
    return a * b // math.gcd(a, b)

def bfs(aa, adj, lcm):
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

        for v in adj[u]:
            if D[i + v] > Du + 1:
                D[i + v] = Du + 1

    return D

def main():
    a, b, k = map(int, input().split())
    lcm = 1
    for i in range(2, k + 1):
        lcm = id1(lcm, i)

    adj = [[] for _ in range(lcm)]
    for i in range(lcm):
        adj[i].append(1)
        for j in range(2, k + 1):
            if i % j:
                adj[i].append(i % j)

    tt = (a - b) // lcm
    aa = a % lcm
    bb = b % lcm

    D = bfs(aa, adj, lcm)

    bb = (aa - bb + 3 * lcm) % lcm
    tt *= (D[bb + lcm] - D[bb])

    print(D[bb] + tt)

if __name__ == "__main__":
    sys.stdin = open("in.txt", "r")
    main()
