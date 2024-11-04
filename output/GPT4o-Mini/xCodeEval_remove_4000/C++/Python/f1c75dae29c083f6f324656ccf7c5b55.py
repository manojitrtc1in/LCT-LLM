from collections import defaultdict
from itertools import combinations

MOD = 1000000007
N = 16
S = 1 << 16

F = [0] * S
k, t = 0, 0
adj = [0] * N
A = [0] * N
P = [-1] * N
n = 0

def low_bit(x):
    return x & -x

def _1(i):
    return 1 << i

def _U(i):
    return _1(i) - 1

def dfs():
    global F
    F = [0] * S
    F[0] = 1
    for s in range(_U(n) + 1):
        if F[s]:
            for i in range(n):
                if not (s & _1(i)) and (pos == -1 or pos == i) and not (s & adj[i]):
                    F[s | _1(i)] += F[s]
    return F[_U(n)]

def main():
    global n, k
    n, k = map(int, input().split())
    k -= 2000
    for _ in range(n):
        u, v = map(int, input().split())
        adj[u - 1] |= _1(v - 1)

    if dfs() < k:
        print("The times have changed")
    else:
        s = _U(n)
        for i in range(n):
            for j in range(n):
                if s & _1(j):
                    P[A[i]] = i
                    t = dfs()
                    if t < k:
                        k -= t
                        P[j] = -1
                    else:
                        s ^= _1(j)
                        print(j + 1, end=' ')
                        break

if __name__ == "__main__":
    main()
