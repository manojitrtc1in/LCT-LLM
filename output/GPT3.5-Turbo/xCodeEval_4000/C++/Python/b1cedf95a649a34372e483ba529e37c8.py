import sys
from typing import List

def main():
    N, M = map(int, input().split())
    K = list(map(int, input().split()))
    vv = [[] for _ in range(4 * 10**5 + 1)]
    for _ in range(M):
        D, T = map(int, input().split())
        vv[D - 1].append(T - 1)
    ok = 2 * sum(K)
    ng = sum(K) - 1
    while ok - ng > 1:
        k = (ok + ng) // 2
        v = [0] * k
        b = [False] * N
        for i in range(k - 1, -1, -1):
            for j in vv[i]:
                if not b[j]:
                    b[j] = True
                    v[i] += K[j]
        t = 0
        s = sum(K)
        for i in range(k):
            t += 1
            m = min(t, v[i])
            t -= m
            s -= m
        if t >= s * 2:
            ok = k
        else:
            ng = k
    print(ok)

if __name__ == "__main__":
    main()
