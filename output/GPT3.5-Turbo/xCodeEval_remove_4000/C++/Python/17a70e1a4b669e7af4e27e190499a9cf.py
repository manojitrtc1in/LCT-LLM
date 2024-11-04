import math

def ints(p, a, q, b):
    D = p[0] * q[1] - p[1] * q[0]
    E = (-a * p[1] + p[0] * b) / D
    F = (a * q[0] - q[1] * b) / D
    return (E, F)

def id18(x, y, z):
    p1 = serper(x, y)
    p2 = serper(x, z)
    return ints(p1[0], p1[1], p2[0], p2[1])

def id16(p, c=None):
    if c is None:
        return (-p[1], p[0])
    else:
        return (c[0] + (-p[1]), c[1] + p[0])

def id21(a, b, c, d):
    x = b[0] - a[0]
    p = x[0] * (c[1] - b[1]) - x[1] * (c[0] - b[0])
    q = x[0] * (d[1] - b[1]) - x[1] * (d[0] - b[0])
    return ((p >= 0 and q <= 0) or (p <= 0 and q >= 0))

def id5(a, b, c, d):
    x = b[0] - a[0]
    p = x[0] * (c[1] - b[1]) - x[1] * (c[0] - b[0])
    q = x[0] * (d[1] - b[1]) - x[1] * (d[0] - b[0])
    return ((p > 0 and q < 0) or (p < 0 and q > 0))

def id10(a, b):
    p = a[0] * b[1] - a[1] * b[0]
    if p:
        return (p > 0)
    else:
        return (a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1])

def id9(v):
    ans = 0
    n = len(v)
    for i in range(1, n):
        if v[i] < v[ans]:
            ans = i
    return ans

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])

        idx = list(range(n))
        idx.sort(key=lambda x: id10(a[x]))

        h = [idx[0]]
        for it in idx[1:]:
            temp = a[it]
            if len(h) >= 2:
                if are_parallel(a[h[-1]], temp):
                    h.pop()
                while len(h) >= 3 and npocs(a[h[-2]], a[h[-1]], temp):
                    h.pop()
            h.append(it)

        for i in range(n):
            a[i] = (a[i][0] + d[0], a[i][1] + d[1])
        return h
    else:
        return []

def id17(r):
    ans = 0
    while r:
        ans += 1
        r >>= 1
    return ans

def id1(p1, p2, n):
    if p1[0] == -1 or p2[0] == -1:
        return (-1, -1)
    np1 = (0, p1[1] - p1[0])
    np2 = (p2[0] - p1[0], p2[1] - p1[0])
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return (np1[0] + p1[0], max(np1[1], np2[1]) + p1[0])
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return (np2[0] + p1[0], max(np1[1], np2[1]) + p1[0])

def sparse_construct(v):
    n = len(v)
    r = id17(n - 1)
    sp = [[(0, 0) for _ in range(n)] for _ in range(r)]
    for i in range(n):
        sp[0][i] = v[i]
    for i in range(1, r):
        for j in range(n):
            p1 = sp[i - 1][j]
            p2 = sp[i - 1][(j + (1 << (i - 1))) % n]
            sp[i][j] = id1(p1, p2, n)
    return sp

def sparse_segment(sp, l, r):
    if l == -1 or r == -1:
        return (-1, -1)
    szz = (r - l) % len(sp)
    if l == r:
        return sp[0][l]
    g = id17(szz) - 1
    return id1(sp[g][l], sp[g][((r + 1 - (1 << g)) % len(sp) + len(sp)) % len(sp)], len(sp))

n = int(input())
if n == 1:
    print("0")
    exit()
r = list(map(int, input().split()))
zz = id17(n) + 1
v = [sparse_construct([]) for _ in range(zz)]
prs = []

for i in range(n):
    if r[i] >= n - 1:
        prs.append((-1, -1))
    else:
        prs.append(id1((i, (i - r[i]) % n), (i, (i + r[i]) % n), n))

v[0] = sparse_construct(prs)

for i in range(1, zz):
    id14 = []
    for j in range(n):
        pairr = sparse_segment(v[i - 1], j, j)
        id14.append(sparse_segment(v[i - 1], pairr[0], pairr[1]))
    v[i] = sparse_construct(id14)

for i in range(n):
    my_pr = (i, i)
    ans = 0
    for j in range(zz - 1, -1, -1):
        new_pr = sparse_segment(v[j], my_pr[0], my_pr[1])
        if new_pr[0] != -1:
            ans += (1 << j)
            my_pr = new_pr
    print(ans + 1, end=' ')
print()
