def check(a):
    n = len(a)
    b = [0] * n
    log = ""

    def merge(l, r):
        nonlocal a, b, log
        if r - l <= 1:
            return
        m = (l + r) // 2
        merge(l, m)
        merge(m, r)
        i = l
        j = m
        k = l
        while i < m and j < r:
            if a[i] < a[j]:
                log += '0'
                b[k] = a[i]
                i += 1
            else:
                log += '1'
                b[k] = a[j]
                j += 1
            k += 1
        while i < m:
            b[k] = a[i]
            i += 1
            k += 1
        while j < r:
            b[k] = a[j]
            j += 1
            k += 1
        for p in range(l, r):
            a[p] = b[p]

    merge(0, n)
    return log


def solve():
    s = input().strip()
    s = s[::-1]

    L = 1
    R = 1111
    while R - L > 1:
        len = (L + R) // 2
        p = list(range(len))
        tmp = s
        recovered = try_recover(0, len, tmp, p)
        if recovered:
            if len(tmp) == 0:
                ans = [0] * len
                for i in range(len):
                    ans[p[i]] = i
                print(len)
                print(" ".join(str(x + 1) for x in ans))
                return
            L = len
        else:
            R = len
    assert False


solve()
