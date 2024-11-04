import sys
from collections import defaultdict

MOD = 1000000007
N = 16
S = 1 << 16

F = [0] * S
adj = [0] * N
A = [0] * N
P = [-1] * N
n = 0
k = 0
t = 0

def count_bits(x):
    return bin(x).count('1')

def low_bit(x):
    return x & -x

def high_bit(x):
    p = low_bit(x)
    while p != x:
        x -= p
        p = low_bit(x)
    return p

def dfs():
    global F
    F = [0] * S
    F[0] = 1
    for s in range(1 << n):
        if F[s]:
            for i in range(n):
                if not (s & (1 << i)) and (P[count_bits(s)] == -1 or P[count_bits(s)] == i) and not (s & adj[i]):
                    F[s | (1 << i)] += F[s]
    return F[(1 << n) - 1]

def main():
    global n, k
    n, k = map(int, sys.stdin.readline().split())
    k -= 2000

    for _ in range(int(sys.stdin.readline().strip())):
        u, v = map(int, sys.stdin.readline().split())
        adj[u - 1] |= (1 << (v - 1))

    if dfs() < k:
        print("The times have changed")
    else:
        s = (1 << n) - 1
        for i in range(n):
            for j in range(n):
                if s & (1 << j):
                    P[A[i]] = j
                    t = dfs()
                    if t < k:
                        k -= t
                        P[j] = -1
                    else:
                        s ^= (1 << j)
                        print(j + 1, end=' ')
                        break

if __name__ == "__main__":
    main()
