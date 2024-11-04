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
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id1(p1, p2, n):
    if p1[0] == -1 or p2[0] == -1:
        return (-1, -1)
    np1 = (0, (p1[1] - p1[0]) % n)
    np2 = (((p2[0] - p1[0]) % n), ((p2[1] - p1[0]) % n))
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return ((np1[0] + p1[0]) % n, (max(np1[1], np2[1]) + p1[0]) % n)
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return ((np2[0] + p1[0]) % n, (max(np1[1], np2[1]) + p1[0]) % n)

def id17(r):
    return 32 - int(math.log2(r))

def id14(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id0(normal, point):
    return (normal, -(normal[0] * point[0] + normal[1] * point[1]))

def serper(a, b):
    p = (b[0] - a[0], b[1] - a[1])
    return ((p[0] + p[0], -(p[0] * (a[0] + b[0]) + p[1] * (a[1] + b[1]))))

def id2(p, q):
    return ((q[1] - p[1], p[0] - q[0]), -(p[0] * q[1] - p[1] * q[0]))

def id11(a, b):
    p1 = serper(a, b)
    p2 = serper(a, c)
    return ints(p1[0], p1[1], p2[0], p2[1])

def id13(a, b, c, d):
    return id5(a, b, c, d) and id5(c, d, a, b)

def id3(a, b, c, d):
    return id21(a, b, c, d) and id21(c, d, a, b)

def id12(a, b, c, d):
    x = b[0] - a[0]
    z = d[0] - c[0]
    return id15(x, z)

def id8(a, b, c, d):
    x = a[0] - b[0]
    y = b[0] - c[0]
    z = c[0] - d[0]
    t = d[0] - a[0]
    p = x[0] * y[1] - x[1] * y[0]
    q = y[0] * z[1] - y[1] * z[0]
    r = z[0] * t[1] - z[1] * t[0]
    s = t[0] * x[1] - t[1] * x[0]
    return (((p >= 0) and (q >= 0) and (r >= 0) and (s >= 0)) or ((p <= 0) and (q <= 0) and (r <= 0) and (s <= 0)))

def id4(a, c=None):
    if c is None:
        return (a[0] * a[1] >= 0)
    else:
        return id4((a[0] - b[0], a[1] - b[1]))

def npocs(a, c=None):
    if c is None:
        return (a[0] * a[1] <= 0)
    else:
        return npocs((a[0] - b[0], a[1] - b[1]))

def prcs(a, c=None):
    if c is None:
        return (a[0] * a[1] > 0)
    else:
        return prcs((a[0] - b[0], a[1] - b[1]))

def pocs(a, c=None):
    if c is None:
        return (a[0] * a[1] < 0)
    else:
        return pocs((a[0] - b[0], a[1] - b[1]))

def on_segment(a, b, c):
    return id15(b - a, c - b)

def id6(a, b, c, d):
    x = sq_dist(a, b)
    y = sq_dist(b, c)
    z = sq_dist(c, d)
    t = sq_dist(d, a)
    return ((x == y) and (y == z) and (z == t))

def is_rectangle(a, b, c, d):
    x = a - b
    y = b - c
    z = c - d
    t = d - a
    return ((x[0] * y[1] - x[1] * y[0] == 0) and (y[0] * z[1] - y[1] * z[0] == 0) and (z[0] * t[1] - z[1] * t[0] == 0) and (t[0] * x[1] - t[1] * x[0] == 0))

def are_parallel(a, b):
    return (a[0] * b[1] - a[1] * b[0] == 0)

def id7(a, b):
    return (a[0] * b[0] + a[1] * b[1] == 0)

def id15(a, b):
    return (are_parallel(a, b) and (a[0] * b[0] + a[1] * b[1] >= 0))

def id20(a, b, c, d):
    return ((a[0] - b[0] == d[0] - c[0]) and (a[1] - b[1] == d[1] - c[1]))

def id2(p, q):
    return ((q[1] - p[1], p[0] - q[0]), -(p[0] * q[1] - p[1] * q[0]))

def id4(a, c=None):
    if c is None:
        return ((a[0] * a[1]) >= 0)
    else:
        return id4((a[0] - b[0], a[1] - b[1]))

def npocs(a, c=None):
    if c is None:
        return ((a[0] * a[1]) <= 0)
    else:
        return npocs((a[0] - b[0], a[1] - b[1]))

def prcs(a, c=None):
    if c is None:
        return ((a[0] * a[1]) > 0)
    else:
        return prcs((a[0] - b[0], a[1] - b[1]))

def pocs(a, c=None):
    if c is None:
        return ((a[0] * a[1]) < 0)
    else:
        return pocs((a[0] - b[0], a[1] - b[1]))

def id21(a, b, c, d):
    x = b[0] - a[0]
    p = x[0] * (c[1] - b[1]) - x[1] * (c[0] - b[0])
    q = x[0] * (d[1] - b[1]) - x[1] * (d[0] - b[0])
    return (((p >= 0) and (q <= 0)) or ((p <= 0) and (q >= 0)))

def id5(a, b, c, d):
    x = b[0] - a[0]
    p = x[0] * (c[1] - b[1]) - x[1] * (c[0] - b[0])
    q = x[0] * (d[1] - b[1]) - x[1] * (d[0] - b[0])
    return (((p > 0) and (q < 0)) or ((p < 0) and (q > 0)))

def id16(p, c=None):
    if c is None:
        return (-p[1], p[0])
    else:
        return (c[0] + (-p[1]), c[1] + p[0])

def id3(a, b, c, d):
    return id21(a, b, c, d) and id21(c, d, a, b)

def id13(a, b, c, d):
    return id5(a, b, c, d) and id5(c, d, a, b)

def id0(normal, point):
    return (normal, -(normal[0] * point[0] + normal[1] * point[1]))

def serper(a, b):
    p = (b[0] - a[0], b[1] - a[1])
    return ((p[0] + p[0], -(p[0] * (a[0] + b[0]) + p[1] * (a[1] + b[1]))))

def id2(p, q):
    return ((q[1] - p[1], p[0] - q[0]), -(p[0] * q[1] - p[1] * q[0]))

def id11(a, b):
    p1 = serper(a, b)
    p2 = serper(a, c)
    return ints(p1[0], p1[1], p2[0], p2[1])

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id9(v):
    ans = 0
    n = len(v)
    for i in range(1, n):
        if v[i] < v[ans]:
            ans = i
    return ans

def id17(r):
    return 32 - int(math.log2(r))

def id1(p1, p2, n):
    if p1[0] == -1 or p2[0] == -1:
        return (-1, -1)
    np1 = (0, (p1[1] - p1[0]) % n)
    np2 = (((p2[0] - p1[0]) % n), ((p2[1] - p1[0]) % n))
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return ((np1[0] + p1[0]) % n, (max(np1[1], np2[1]) + p1[0]) % n)
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return ((np2[0] + p1[0]) % n, (max(np1[1], np2[1]) + p1[0]) % n)

def id17(r):
    return 32 - int(math.log2(r))

def id1(p1, p2, n):
    if p1[0] == -1 or p2[0] == -1:
        return (-1, -1)
    np1 = (0, (p1[1] - p1[0]) % n)
    np2 = (((p2[0] - p1[0]) % n), ((p2[1] - p1[0]) % n))
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return ((np1[0] + p1[0]) % n, (max(np1[1], np2[1]) + p1[0]) % n)
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return ((np2[0] + p1[0]) % n, (max(np1[1], np2[1]) + p1[0]) % n)

def id14(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])
        idx = sorted(range(n), key=lambda x: id10(a[x]))
        h = [idx[0]]
        for it in idx[1:]:
            temp = (a[it][0], a[it][1])
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

def id19(a):
    n = len(a)
    if n:
        mt = id9(a)
        d = a[mt]
        for i in range(n):
