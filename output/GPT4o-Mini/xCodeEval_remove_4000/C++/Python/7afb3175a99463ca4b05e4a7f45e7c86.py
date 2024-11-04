from itertools import combinations
from collections import defaultdict
import sys

MOD = int(1e9) + 7
N, M = 50, 20
S = ["" for _ in range(N)]
f = [0] * (1 << M)
ok = [0] * (M + 1)

def count_bits(x):
    return bin(x).count('1')

def _1(i):
    return 1 << i

def main():
    global S, f, ok
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    for i in range(n):
        S[i] = data[i + 1]
    
    m = len(S[0])

    for i in range(n):
        for j in range(n):
            if i != j:
                s = 0
                for k in range(m):
                    if S[i][k] == S[j][k]:
                        s |= _1(k)
                f[s] |= _1(i)

    for s in range(1 << m):
        for i in range(m):
            if s & _1(i):
                f[s ^ _1(i)] |= f[s]

    for s in range(1 << m):
        step = count_bits(s) + 1
        for i in range(m):
            if not (s & _1(i)):
                d = f[s | _1(i)] ^ f[s]
                ok[step] += count_bits(d)

    ans = 0.0
    for i in range(m + 1):
        if ok[i]:
            t = ok[i] * i
            for j in range(1, i):
                t *= j
            for j in range(1, m - i + 1):
                t /= j
            ans += t

    ans /= n
    print(f"{ans:.15f}")

if __name__ == "__main__":
    main()
