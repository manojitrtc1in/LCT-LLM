def main():
    n = int(input())
    q = int(input())
    a = list(map(int, input().split()))
    m = max(a)

    itrv = []
    for _ in range(q):
        l, r, p = map(int, input().split())
        l -= 1
        itrv.append((l, r, p))
    itrv.sort(key=lambda x: x[1] - x[0])
    itrv.append((0, n, 0))

    cur = {}

    for l, r, p in itrv:
        be = cur.lower_bound(l)
        en = cur.lower_bound(r)

        nv = [1.0] * (q * 2 + 1)
        pv = l
        for itr in range(be, en):
            zer = 0
            while pv < itr[0]:
                dif = a[pv] - m + q
                if dif > zer:
                    zer = dif
                pv += 1
            for i in range(zer):
                nv[i] = 0
            tmp = itr[1]
            for i in range(q * 2 + 1):
                nv[i] *= tmp[i]

        zer = 0
        while pv < r:
            dif = a[pv] - m + q
            if dif > zer:
                zer = dif
            pv += 1
        for i in range(zer):
            nv[i] = 0

        nx = [0.0] * (q * 2 + 1)
        for i in range(q * 2 + 1):
            nx[i] += (1 - p) * nv[i]
        for i in range(q * 2):
            nx[i + 1] += p * nv[i]
        cur = {}
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

main()
