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
    return ((p >= 0) and (q <= 0)) or ((p <= 0) and (q >= 0))

def id5(a, b, c, d):
    x = b[0] - a[0]
    p = x[0] * (c[1] - b[1]) - x[1] * (c[0] - b[0])
    q = x[0] * (d[1] - b[1]) - x[1] * (d[0] - b[0])
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

def id17(r):
    return 32 - int(math.log2(r))

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

def id2(p, q):
    return ((q[1] - p[1], p[0] - q[0]), -p[0] * q[1] + p[1] * q[0])

def id11(a, b):
    id14 = []
    for j in range(len(a)):
        pairr = a[j]
        id14.append(id1(pairr, b[(j + 1) % len(b)], len(b)))
    return id14

def id0(normal, point):
    return (normal, -normal[0] * point[0] - normal[1] * point[1])

def serper(a, b):
    p = (b[0] - a[0], b[1] - a[1])
    return (p[0] + p[0], -p[0] * (a[0] + b[0]) - p[1] * (a[1] + b[1]))

def height(a, b, c):
    return projection(id2(a, c), b)

def projection(line, point):
    temp = perpendicular(line, point)
    return ints(line[0], line[1], temp[0], temp[1])

def perpendicular(line, point):
    return id0(id16(line), point)

def on_segment(a, b, c):
    return id15(b - a, c - b)

def id15(a, b):
    return (a[0] * b[0] + a[1] * b[1] == 0)

def are_parallel(a, b):
    return (a[0] * b[1] - a[1] * b[0] == 0)

def npocs(a, c):
    return (a[0] * c[1] - a[1] * c[0] <= 0)

def npocs(a, b, c):
    return npocs(a - b, a - c)

def prcs(a, c):
    return (a[0] * c[1] - a[1] * c[0] > 0)

def prcs(a, b, c):
    return prcs(a - b, a - c)

def pocs(a, c):
    return (a[0] * c[1] - a[1] * c[0] < 0)

def pocs(a, b, c):
    return pocs(a - b, a - c)

def id4(a, c):
    return (a[0] * c[0] + a[1] * c[1] >= 0)

def id4(a, b, c):
    return id4(a - b, a - c)

def id4(a, c):
    return (a[0] * c[0] + a[1] * c[1] <= 0)

def id4(a, b, c):
    return id4(a - b, a - c)

def id12(a, b, c, d):
    x = a - b
    z = d - c
    return id15(x, z)

def id8(a, b, c, d):
    x = a - b
    y = b - c
    z = c - d
    t = d - a
    p = x[0] * y[1] - x[1] * y[0]
    q = y[0] * z[1] - y[1] * z[0]
    r = z[0] * t[1] - z[1] * t[0]
    s = t[0] * x[1] - t[1] * x[0]
    return (((p >= 0) and (q >= 0) and (r >= 0) and (s >= 0)) or ((p <= 0) and (q <= 0) and (r <= 0) and (s <= 0)))

def id20(a, b, c, d):
    return ((a - b) == (d - c))

def id7(a, b):
    return (a[0] * b[0] + a[1] * b[1] == 0)

def id15(a, b):
    return (a[0] * b[0] + a[1] * b[1] == 0)

def id6(a, b, c, d):
    x = sq_dist(a, b)
    y = sq_dist(b, c)
    z = sq_dist(c, d)
    t = sq_dist(d, a)
    return ((x == y) and (y == z) and (z == t))

def dist(p, q):
    return math.sqrt(sq_dist(p, q))

def len(p):
    return math.sqrt(sq_len(p))

def sq_dist(p, q):
    return sq_len((p[0] - q[0], p[1] - q[1]))

def sq_len(p):
    return p[0] * p[0] + p[1] * p[1]

def prod(a, b, M):
    return (a * b) % M

def sum(a, b, M):
    c = a + b
    return c if c < M else c - M

def raz(a, b, M):
    c = a - b
    return c if c >= 0 else c + M

def euc(m, n):
    if n == 0:
        return (1 if m >= 0 else -1, 0)
    t = m // n
    ans1 = euc(n, m - t * n)
    return (ans1[1], ans1[0] - ans1[1] * t)

def z_function(s):
    n = len(s)
    z = [0] * n
    l = 0
    r = 1
    for i in range(1, n):
        z[i] = max(0, min(r - i, z[i - l]))
        while i + z[i] < n and s[i + z[i]] == s[z[i]]:
            z[i] += 1
        if r < i + z[i]:
            l = i
            r = i + z[i]
    return z

def sopr(p):
    return (p[0], -p[1])

def id13(a, b, c, d):
    return id5(a, b, c, d) and id5(c, d, a, b)

def id3(a, b, c, d):
    return id21(a, b, c, d) and id21(c, d, a, b)

def id20(a, b, c, d):
    return (a - b) == (d - c)

def id12(a, b, c, d):
    x = a - b
    z = d - c
    return id15(x, z)

def id8(a, b, c, d):
    x = a - b
    y = b - c
    z = c - d
    t = d - a
    p = x[0] * y[1] - x[1] * y[0]
    q = y[0] * z[1] - y[1] * z[0]
    r = z[0] * t[1] - z[1] * t[0]
    s = t[0] * x[1] - t[1] * x[0]
    return (((p >= 0) and (q >= 0) and (r >= 0) and (s >= 0)) or ((p <= 0) and (q <= 0) and (r <= 0) and (s <= 0)))

def id4(a, c):
    return (a[0] * c[0] + a[1] * c[1] >= 0)

def id4(a, b, c):
    return id4(a - b, a - c)

def npocs(a, c):
    return (a[0] * c[0] + a[1] * c[1] <= 0)

def npocs(a, b, c):
    return npocs(a - b, a - c)

def prcs(a, c):
    return (a[0] * c[0] + a[1] * c[1] > 0)

def prcs(a, b, c):
    return prcs(a - b, a - c)

def pocs(a, c):
    return (a[0] * c[0] + a[1] * c[1] < 0)

def pocs(a, b, c):
    return pocs(a - b, a - c)

def id21(a, b, c, d):
    x = b - a
    p = x[0] * (c[1] - b[1]) - x[1] * (c[0] - b[0])
    q = x[0] * (d[1] - b[1]) - x[1] * (d[0] - b[0])
    return (((p >= 0) and (q <= 0)) or ((p <= 0) and (q >= 0)))

def id5(a, b, c, d):
    x = b - a
    p = x[0] * (c[1] - b[1]) - x[1] * (c[0] - b[0])
    q = x[0] * (d[1] - b[1]) - x[1] * (d[0] - b[0])
    return (((p > 0) and (q < 0)) or ((p < 0) and (q > 0)))

def id16(p, c=None):
    if c is None:
        return (-p[1], p[0])
    else:
        return (c[0] + (-p[1]), c[1] + p[0])

def id16(p, c):
    return c + id16(p - c)

def id3(a, b, c, d):
    return id21(a, b, c, d) and id21(c, d, a, b)

def id13(a, b, c, d):
    return id5(a, b, c, d) and id5(c, d, a, b)

def id0(normal, point):
    return (normal, -(normal[0] * point[0] + normal[1] * point[1]))

def serper(a, b):
    p = b - a
    return (p + p, -(p[0] * (a[0] + b[0]) + p[1] * (a[1] + b[1])))

def main():
    n = int(input())
    if n == 1:
        print("0")
        return
    r = list(map(int, input().split()))
    zz = id17(n - 1) + 1
    v = [None] * zz
    prs = [None] * n
    for i in range(n):
        if r[i] >= n - 1:
            prs[i] = (-1, -1)
        else:
            prs[i] = id1((raz(i, r[i], n), i), (i, sum(i, r[i], n)), n)
    v[0] = sparse()
    v[0].construct(prs)
    for i in range(1, zz):
        id14 = [None] * n
        for j in range(n):
            p1 = v[i - 1].segment(j, j)
            p2 = v[i - 1].segment((j + (1 << (i - 1))) % n, (j + (1 << (i - 1))) % n)
            id14[j] = id1(p1, p2, n)
        v[i] = sparse()
        v[i].construct(id14)
    for i in range(n):
        my_pr = (i, i)
        ans = 0
        for j in range(zz - 1, -1, -1):
            new_pr = v[j].segment(my_pr[0], my_pr[1])
            if new_pr[0] != -1:
                ans += (1 << j)
                my_pr = new_pr
        print(ans + 1, end=" ")
    print()

class sparse:
    def construct(self, v):
        self.n = len(v)
        r = id17(self.n - 1)
        self.sp = [[None] * self.n for _ in range(r)]
        for i in range(self.n):
            self.sp[0][i] = v[i]
        for i in range(1, r):
            for j in range(self.n):
                p1 = self.sp[i - 1][j]
                p2 = self.sp[i - 1][(j + (1 << (i - 1))) % self.n]
                self.sp[i][j] = id1(p1, p2, self.n)
    
    def segment(self, l, r):
        if l == -1 or r == -1:
            return (-1, -1)
        szz = raz(r, l, self.n)
        if l == r:
            return self.sp[0][l]
        g = id17(szz) - 1
        return id1(self.sp[g][l], self.sp[g][((r + 1 - (1 << g)) % self.n + self.n) % self.n], self.n)

if __name__ == "__main__":
    main()
