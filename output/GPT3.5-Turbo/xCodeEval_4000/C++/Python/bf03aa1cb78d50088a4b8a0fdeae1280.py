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


def try_recover(l, r, s, p):
    if r - l <= 1:
        return True
    mid = (l + r) // 2
    if not try_recover(l, mid, s, p) or not try_recover(mid, r, s, p):
        return False
    left = []
    for i in range(mid - 1, l - 1, -1):
        left.append(p[i])
    right = []
    for i in range(r - 1, mid - 1, -1):
        right.append(p[i])
    pos = l
    while left and right:
        if not s:
            return False
        ch = s[-1]
        s = s[:-1]
        if ch == '1':
            p[pos] = right.pop()
            pos += 1
        else:
            p[pos] = left.pop()
            pos += 1
    while left:
        p[pos] = left.pop()
        pos += 1
    while right:
        p[pos] = right.pop()
        pos += 1
    return True


def solve(in_stream, out_stream):
    s = in_stream.readline().strip()
    s = s[::-1]

    L = 1
    R = 1111
    while R - L > 1:
        len_ = (L + R) // 2
        p = list(range(len_))
        tmp = s
        recovered = try_recover(0, len_, tmp, p)
        if recovered:
            if not tmp:
                ans = [0] * len_
                for i in range(len_):
                    ans[p[i]] = i
                out_stream.write(str(len_) + "\n")
                out_stream.write(" ".join(str(x + 1) for x in ans) + "\n")
                return
            L = len_
        else:
            R = len_
    assert False


solve(sys.stdin, sys.stdout)
