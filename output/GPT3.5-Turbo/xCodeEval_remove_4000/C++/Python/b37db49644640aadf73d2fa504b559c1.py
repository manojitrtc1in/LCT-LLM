import sys
from typing import List, Tuple
from collections import defaultdict

def main() -> None:
    n = int(input())
    q = int(input())
    a = list(map(int, input().split()))
    m = max(a)

    itrv = []
    for _ in range(q):
        l, r, p = map(int, input().split())
        itrv.append((l-1, r, p))
    itrv.sort(key=lambda x: x[1] - x[0])
    itrv.append((0, n, 0))

    cur = defaultdict(lambda: (0, [1.0] * (q * 2 + 1)))

    for l, r, p in itrv:
        be = list(cur.keys())
        en = list(cur.keys())
        for i in range(len(be)):
            if be[i] >= l:
                be = be[i:]
                break
        for i in range(len(en)):
            if en[i] >= r:
                en = en[i:]
                break

        nv = [1.0] * (q * 2 + 1)
        pv = l
        for i in range(len(be)):
            zer = 0
            while pv < be[i]:
                dif = a[pv] - m + q
                zer = max(zer, dif)
                pv += 1
            for j in range(zer):
                nv[j] = 0
            tmp = cur[be[i]][1]
            for j in range(q * 2 + 1):
                nv[j] *= tmp[j]

        zer = 0
        while pv < r:
            dif = a[pv] - m + q
            zer = max(zer, dif)
            pv += 1
        for i in range(zer):
            nv[i] = 0

        nx = [0.0] * (q * 2 + 1)
        for i in range(q * 2 + 1):
            nx[i] += (1 - p) * nv[i]
        for i in range(q * 2):
            nx[i + 1] += p * nv[i]
        for key in be:
            del cur[key]
        cur[l] = (r, nx)

    ans = m
    sum = 0
    ren, top = cur[0]
    assert ren == n
    for i in range(q * 2 + 1):
        if i < q:
            assert top[i] < 1e-6
        ans += (i - q) * (top[i] - sum)
        sum = top[i]
    assert top[-1] > 1 - 1e-6
    print(ans)

if __name__ == "__main__":
    main()
