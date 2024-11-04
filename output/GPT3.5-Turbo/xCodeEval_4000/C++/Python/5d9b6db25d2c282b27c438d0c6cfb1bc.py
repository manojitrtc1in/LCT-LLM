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
    left = [p[i] for i in range(mid - 1, l - 1, -1)]
    right = [p[i] for i in range(r - 1, mid - 1, -1)]
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

    for length in range(2, 1112):
        p = list(range(length))
        tmp = s
        if try_recover(0, length, tmp, p) and not tmp:
            ans = [0] * length
            for i in range(length):
                ans[p[i]] = i
            out_stream.write(str(length) + '\n')
            out_stream.write(' '.join(str(x + 1) for x in ans) + '\n')
            return


if __name__ == "__main__":
    import sys

    solve(sys.stdin, sys.stdout)
