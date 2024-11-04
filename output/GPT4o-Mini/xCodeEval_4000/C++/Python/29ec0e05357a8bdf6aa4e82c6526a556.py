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
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1)
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2)
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4)
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8)
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16)
    return x

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
    n, k = map(int, input().split())
    k -= 2000
    for _ in range(int(input())):
        u, v = map(int, input().split())
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
