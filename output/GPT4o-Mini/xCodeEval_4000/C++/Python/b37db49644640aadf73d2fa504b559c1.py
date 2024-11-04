from collections import defaultdict
import sys
import itertools

def main():
    n = int(input())
    q = int(input())
    a = list(map(int, input().split()))
    m = max(a)

    itrv = []
    for _ in range(q):
        l, r, p = map(float, input().split())
        itrv.append((int(l) - 1, int(r), p))

    itrv.sort(key=lambda x: x[1] - x[0])
    itrv.append((0, n, 0))

    cur = {}

    for l, r, p in itrv:
        be = next((k for k in cur if k >= l), None)
        en = next((k for k in cur if k >= r), None)

        nv = [1.0] * (q * 2 + 1)
        pv = l

        for k in range(be, en):
            zer = 0
            while pv < k:
                dif = a[pv] - m + q
                zer = max(zer, dif)
                pv += 1
            
            for i in range(zer):
                nv[i] = 0
            
            tmp = cur[k][1]
            for i in range(q * 2 + 1):
                nv[i] *= tmp[i]

        zer = 0
        while pv < r:
            dif = a[pv] - m + q
            zer = max(zer, dif)
            pv += 1
        
        for i in range(zer):
            nv[i] = 0

        nx = [0] * (q * 2 + 1)
        for i in range(q * 2 + 1):
            nx[i] += (1 - p) * nv[i]
        for i in range(q * 2):
            nx[i + 1] += p * nv[i]

        if be is not None:
            del cur[be:en]

        cur[l] = (r, nx)

    ans = m
    sum_ = 0
    assert next(iter(cur)) == 0
    ren, top = cur[0]
    assert ren == n

    for i in range(q * 2 + 1):
        if i < q:
            assert top[i] < 1e-6
        ans += (i - q) * (top[i] - sum_)
        sum_ = top[i]

    assert top[-1] > 1 - 1e-6
    print(ans)

if __name__ == "__main__":
    main()
