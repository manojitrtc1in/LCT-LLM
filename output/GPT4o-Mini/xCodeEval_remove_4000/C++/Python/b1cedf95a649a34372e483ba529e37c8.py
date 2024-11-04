from collections import defaultdict
import sys
import math

def input():
    return sys.stdin.readline().strip()

def sum_list(lst):
    return sum(lst)

def main():
    N, M = map(int, input().split())
    K = list(map(int, input().split()))
    vv = defaultdict(list)

    for _ in range(M):
        D, T = map(int, input().split())
        vv[D - 1].append(T - 1)

    ok = 2 * sum_list(K)
    ng = sum_list(K) - 1

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
        s = sum_list(K)

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
