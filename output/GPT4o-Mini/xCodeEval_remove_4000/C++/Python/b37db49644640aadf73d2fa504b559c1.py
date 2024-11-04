import sys
from collections import defaultdict
from itertools import accumulate
from math import isclose

def main():
    n = int(sys.stdin.readline())
    q = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    m = max(a)

    itrv = []
    for _ in range(q):
        l, r, p = map(float, sys.stdin.readline().split())
        itrv.append((int(l) - 1, int(r), p))
    
    itrv.sort(key=lambda x: x[1] - x[0])
    itrv.append((0, n, 0))

    cur = defaultdict(lambda: (0, [1.0] * (q * 2 + 1)))

    for l, r, p in itrv:
        be = [k for k in cur.keys() if k >= l]
        en = [k for k in cur.keys() if k >= r]

        nv = [1.0] * (q * 2 + 1)
        pv = l

        for k in be:
            if k >= r:
                break
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
        
        for k in be:
            del cur[k]
        
        cur[l] = (r, nx)

    ans = m
    sum_ = 0
    assert next(iter(cur.keys())) == 0
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
