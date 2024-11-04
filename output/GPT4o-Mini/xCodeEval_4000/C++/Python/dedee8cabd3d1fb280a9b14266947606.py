from itertools import combinations
import sys

MOD = 1000000007
INF = float('inf')

A = []
cnt = 0

def dfs(k=0, n=0):
    A.append(n)
    if k == 9:
        return
    else:
        dfs(k + 1, n * 10 + 4)
        dfs(k + 1, n * 10 + 7)

def I(l, r, l_, r_):
    l = max(l, l_)
    r = min(r, r_)
    return max(0, r - l + 1)

def main():
    global cnt
    dfs()
    A.sort()
    A.append(INF)

    pl, pr, vl, vr, k = map(int, sys.stdin.readline().split())

    for i in range(len(A) - k):
        l1 = A[i - 1] + 1
        r1 = A[i]
        l2 = A[i + k - 1]
        r2 = A[i + k] - 1
        d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr)
        d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr)
        cnt += d1 + d2
        if d2 and d2 and k == 1:
            cnt -= 1

    print(f"{cnt / ((pr - pl + 1) * (vr - vl + 1)):.12f}")

if __name__ == "__main__":
    main()
