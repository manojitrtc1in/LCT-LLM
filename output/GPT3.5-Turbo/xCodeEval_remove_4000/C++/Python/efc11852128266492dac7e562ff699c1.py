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
    return (c[0] + (-p[1]), c[1] + p[0])

def id21(a, b, c, d):
    x = b[0] - a[0]
    p = x[0] * (c[1] - b[1])
    q = x[0] * (d[1] - b[1])
    return ((p >= 0) and (q <= 0)) or ((p <= 0) and (q >= 0))

def id5(a, b, c, d):
    x = b[0] - a[0]
    p = x[0] * (c[1] - b[1])
    q = x[0] * (d[1] - b[1])
    return ((p > 0) and (q < 0)) or ((p < 0) and (q > 0))

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
    return 32 - int(math.log2(r))

def id1(p1, p2, n):
    if (p1[0] == -1) or (p2[0] == -1):
        return (-1, -1)
    np1 = (0, raz(p1[1], p1[0], n))
    np2 = (raz(p2[0], p1[0], n), raz(p2[1], p1[0], n))
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return (sum(np1[0], p1[0], n), sum(max(np1[1], np2[1]), p1[0], n))
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return (sum(np2[0], p1[0], n), sum(max(np1[1], np2[1]), p1[0], n))

def serper(a, b):
    p = (b[0] - a[0], b[1] - a[1])
    return ((p[0] + p[0], -(p[0] * (a[0] + b[0]) + p[1] * (a[1] + b[1]))))

def id0(normal, point):
    return (normal, -(normal[0] * point[0] + normal[1] * point[1]))

def id2(p, q):
    return ((q[1] - p[1], p[0] - q[0]), -p[0] * q[1] + p[1] * q[0])

def id11(a, b):
    c = (b[0] - a[0], b[1] - a[1])
    rr1 = a[1] * a[1]
    rr2 = b[1] * b[1]
    cc = c[0] * c[0] + c[1] * c[1]
    rrrr1 = rr1 * rr1
    rrrr2 = rr2 * rr2
    cccc = cc * cc
    D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc)
    if D >= 0:
        E = ((rr1 - rr2) / cc + 1) / 2
        baza = (a[0] + c[0] * E, a[1] + c[1] * E)
        if D:
            lll = math.sqrt(D) / (2 * cc)
            cr = id16(c)
            pmm = (cr[0] * lll, cr[1] * lll)
            return [((baza[0] + pmm[0]), (baza[1] + pmm[1])), ((baza[0] - pmm[0]), (baza[1] - pmm[1]))]
        else:
            return [(baza[0], baza[1])]
    else:
        return []

def id13(a, b, c, d):
    return id5(a, b, c, d) and id5(c, d, a, b)

def id3(a, b, c, d):
    return id21(a, b, c, d) and id21(c, d, a, b)

def id8(a, b, c, d):
    x = (a[0] - b[0], a[1] - b[1])
    y = (b[0] - c[0], b[1] - c[1])
    z = (c[0] - d[0], c[1] - d[1])
    t = (d[0] - a[0], d[1] - a[1])
    p = x[0] * y[1]
    q = y[0] * z[1]
    r = z[0] * t[1]
    s = t[0] * x[1]
    return (((p >= 0) and (q >= 0) and (r >= 0) and (s >= 0)) or ((p <= 0) and (q <= 0) and (r <= 0) and (s <= 0)))

def id12(a, b, c, d):
    x = (a[0] - b[0], a[1] - b[1])
    z = (d[0] - c[0], d[1] - c[1])
    return id15(x, z)

def id20(a, b, c, d):
    return ((a[0] - b[0]) == (d[0] - c[0])) and ((a[1] - b[1]) == (d[1] - c[1]))

def id15(a, b):
    return are_parallel(a, b) and (a[0] * b[0] >= 0)

def are_parallel(a, b):
    return (a[0] * b[1] - a[1] * b[0] == 0)

def id7(a, b):
    return (a[0] * b[0] + a[1] * b[1] == 0)

def id4(a, b, c=None):
    if c is None:
        return (a[0] * b[1] - a[1] * b[0] >= 0)
    return id4((a[0] - b[0], a[1] - b[1]), (a[0] - c[0], a[1] - c[1]))

def npocs(a, b, c=None):
    if c is None:
        return (a[0] * b[1] - a[1] * b[0] <= 0)
    return npocs((a[0] - b[0], a[1] - b[1]), (a[0] - c[0], a[1] - c[1]))

def prcs(a, b, c=None):
    if c is None:
        return (a[0] * b[1] - a[1] * b[0] > 0)
    return prcs((a[0] - b[0], a[1] - b[1]), (a[0] - c[0], a[1] - c[1]))

def pocs(a, b, c=None):
    if c is None:
        return (a[0] * b[1] - a[1] * b[0] < 0)
    return pocs((a[0] - b[0], a[1] - b[1]), (a[0] - c[0], a[1] - c[1]))

def id6(a, b, c, d):
    x = sq_dist(a, b)
    y = sq_dist(b, c)
    z = sq_dist(c, d)
    t = sq_dist(d, a)
    return ((x == y) and (y == z) and (z == t))

def is_rectangle(a, b, c, d):
    x = (a[0] - b[0], a[1] - b[1])
    y = (b[0] - c[0], b[1] - c[1])
    z = (c[0] - d[0], c[1] - d[1])
    t = (d[0] - a[0], d[1] - a[1])
    return ((x[0] * y[1] == 0) and (y[0] * z[1] == 0) and (z[0] * t[1] == 0) and (t[0] * x[1] == 0))

def sq_len(p):
    return p[0] * p[0] + p[1] * p[1]

def sq_dist(p, q):
    return sq_len((p[0] - q[0], p[1] - q[1]))

def len(p):
    return math.sqrt(sq_len(p))

def dist(p, q):
    return len((p[0] - q[0], p[1] - q[1]))

def id4(a, c=None):
    if c is None:
        return (a[0] * a[1] >= 0)
    return id4((a[0] - b[0], a[1] - b[1]), (a[0] - c[0], a[1] - c[1]))

def id4(a, b, c):
    return id4((a[0] - b[0], a[1] - b[1]), (a[0] - c[0], a[1] - c[1]))

def id20(a, b, c, d):
    return ((a[0] - b[0]) == (d[0] - c[0])) and ((a[1] - b[1]) == (d[1] - c[1]))

def id12(a, b, c, d):
    x = (a[0] - b[0], a[1] - b[1])
    z = (d[0] - c[0], d[1] - c[1])
    return id15(x, z)

def id8(a, b, c, d):
    x = (a[0] - b[0], a[1] - b[1])
    y = (b[0] - c[0], b[1] - c[1])
    z = (c[0] - d[0], c[1] - d[1])
    t = (d[0] - a[0], d[1] - a[1])
    p = x[0] * y[1]
    q = y[0] * z[1]
    r = z[0] * t[1]
    s = t[0] * x[1]
    return (((p >= 0) and (q >= 0) and (r >= 0) and (s >= 0)) or ((p <= 0) and (q <= 0) and (r <= 0) and (s <= 0)))

def id3(a, b, c, d):
    return id21(a, b, c, d) and id21(c, d, a, b)

def id13(a, b, c, d):
    return id5(a, b, c, d) and id5(c, d, a, b)

def id21(a, b, c, d):
    x = (b[0] - a[0], b[1] - a[1])
    p = x[0] * (c[1] - b[1])
    q = x[0] * (d[1] - b[1])
    return (((p >= 0) and (q <= 0)) or ((p <= 0) and (q >= 0)))

def id5(a, b, c, d):
    x = (b[0] - a[0], b[1] - a[1])
    p = x[0] * (c[1] - b[1])
    q = x[0] * (d[1] - b[1])
    return (((p > 0) and (q < 0)) or ((p < 0) and (q > 0)))

def id16(p, c=None):
    if c is None:
        return (-p[1], p[0])
    return (c[0] + (-p[1]), c[1] + p[0])

def id3(a, b, c, d):
    return id21(a, b, c, d) and id21(c, d, a, b)

def id13(a, b, c, d):
    return id5(a, b, c, d) and id5(c, d, a, b)

def id2(p, q):
    return ((q[1] - p[1], p[0] - q[0]), -p[0] * q[1] + p[1] * q[0])

def id0(normal, point):
    return (normal, -(normal[0] * point[0] + normal[1] * point[1]))

def serper(a, b):
    p = (b[0] - a[0], b[1] - a[1])
    return ((p[0] + p[0], -(p[0] * (a[0] + b[0]) + p[1] * (a[1] + b[1]))))

def id1(p1, p2, n):
    if (p1[0] == -1) or (p2[0] == -1):
        return (-1, -1)
    np1 = (0, raz(p1[1], p1[0], n))
    np2 = (raz(p2[0], p1[0], n), raz(p2[1], p1[0], n))
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return (sum(np1[0], p1[0], n), sum(max(np1[1], np2[1]), p1[0], n))
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return (sum(np2[0], p1[0], n), sum(max(np1[1], np2[1]), p1[0], n))

def sparse_construct(v):
    n = len(v)
    r = id17(n - 1)
    sp = [[(0, 0)] * n for _ in range(r)]
    for i in range(n):
        sp[0][i] = v[i]
    for i in range(1, r):
        for j in range(n):
            p1 = sp[i - 1][j]
            p2 = sp[i - 1][(j + (1 << (i - 1))) % n]
            sp[i][j] = id1(p1, p2, n)
    return sp

def sparse_segment(sp, l, r):
    if (l == -1) or (r == -1):
        return (-1, -1)
    szz = raz(r, l, len(sp))
    if l == r:
        return sp[0][l]
    g = id17(szz) - 1
    return id1(sp[g][l], sp[g][((r + 1 - (1 << g)) % len(sp) + len(sp)) % len(sp)], len(sp))

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
    return 32 - int(math.log2(r))

def id1(p1, p2, n):
    if (p1[0] == -1) or (p2[0] == -1):
        return (-1, -1)
    np1 = (0, raz(p1[1], p1[0], n))
    np2 = (raz(p2[0], p1[0], n), raz(p2[1], p1[0], n))
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return (sum(np1[0], p1[0], n), sum(max(np1[1], np2[1]), p1[0], n))
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return (sum(np2[0], p1[0], n), sum(max(np1[1], np2[1]), p1[0], n))

def segment(l, r):
    if (l == -1) or (r == -1):
        return (-1, -1)
    szz = raz(r, l, n)
    if l == r:
        return sp[0][l]
    g = id17(szz) - 1
    return id1(sp[g][l], sp[g][((r + 1 - (1 << g)) % n + n) % n], n)

n = int(input())
if n == 1:
    print("0")
    exit()
r = list(map(int, input().split()))
zz = id17(n) - 1
sp = sparse_construct(r)
prs = []

for i in range(n):
    if r[i] >= n - 1:
        prs.append((-1, -1))
    else:
        prs.append(id1((raz(i, r[i], n), i), (i, sum(i, r[i], n)), n))

sp = sparse_construct(prs)

for i in range(1, zz):
    id14 = []
    for j in range(n):
        pairr = segment(j, j)
        id14.append(segment(pairr[0], pairr[1]))
    sp = sparse_construct(id14)

for i in range(n):
    my_pr = (i, i)
    ans = 0
    for j in range(zz - 1, -1, -1):
        new_pr = segment(my_pr[0], my_pr[1])
        if new_pr[0] != -1:
            ans += (1 << j)
            my_pr = new_pr
    print(ans + 1, end=" ")
