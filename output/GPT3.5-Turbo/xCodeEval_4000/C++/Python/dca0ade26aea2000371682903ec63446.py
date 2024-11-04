class modinfo:
    def __init__(self, mod, root):
        self.mod = mod
        self.root = root

class modular:
    def __init__(self, v):
        self.v = v

    def s(self, vv):
        self.v = vv % self.mod if vv < self.mod else vv - self.mod

    def __neg__(self):
        return modular(-self.v)

    def __add__(self, rhs):
        return self.s(self.v + rhs.v)

    def __sub__(self, rhs):
        return self.s(self.v + self.mod - rhs.v)

    def __mul__(self, rhs):
        return self.s(self.v * rhs.v)

    def __truediv__(self, rhs):
        return self * rhs.inv()

    def __pow__(self, n):
        res = modular(1)
        x = modular(self.v)
        while n:
            if n & 1:
                res *= x
            x *= x
            n >>= 1
        return res

    def inv(self):
        return self.pow(self.mod - 2)

def multiply(x, y, same=False):
    n = len(x) + len(y) - 1
    s = 1
    while s < n:
        s *= 2
    p = [modular(0)] * s
    q = [modular(0)] * s
    for i in range(len(x)):
        p[i] = x[i]
    for i in range(len(y)):
        q[i] = y[i]
    inplace_fmt(p, False)
    inplace_fmt(q, False)
    for i in range(s):
        p[i] *= q[i]
    inplace_fmt(p, True)
    return p[:n]

def inplace_fmt(f, inv):
    mod = 998244353
    mod2 = mod * 2
    L = 30
    g = [modular(0)] * L
    ig = [modular(0)] * L
    p2 = [modular(0)] * L
    if g[0].v == 0:
        for i in range(L):
            w = modular(-modular(3).pow(((mod - 1) >> (i + 2)) * 3))
            g[i] = w
            ig[i] = w.inv()
            p2[i] = modular(1 << i).inv()
    if not inv:
        b = len(f)
        if b >>= 1:
            for i in range(b):
                x = f[i + b].v
                f[i + b].v = f[i].v + mod - x
                f[i].v += x
        if b >>= 1:
            p = modular(1)
            for i in range(0, len(f), b * 2):
                for j in range(i, i + b):
                    x = (f[j + b] * p).v
                    f[j + b].v = f[j].v + mod - x
                    f[j].v += x
                p *= g[bin(i + b).count('1')]
        while b:
            if b >>= 1:
                p = modular(1)
                for i in range(0, len(f), b * 2):
                    for j in range(i, i + b):
                        x = (f[j + b] * p).v
                        f[j + b].v = f[j].v + mod - x
                        f[j].v += x
                    p *= g[bin(i + b).count('1')]
            if b >>= 1:
                p = modular(1)
                for i in range(0, len(f), b * 2):
                    for j in range(i, i + b):
                        x = (f[j + b] * p).v
                        f[j].v = (f[j].v < mod2) ? f[j].v : f[j].v - mod2
                        f[j + b].v = f[j].v + mod - x
                        f[j].v += x
                    p *= g[bin(i + b).count('1')]
    else:
        b = 1
        if b < len(f) / 2:
            p = modular(1)
            for i in range(0, len(f), b * 2):
                for j in range(i, i + b):
                    x = (f[j + b] * p).v
                    f[j + b].v = f[j].v + mod - x
                    f[j].v += x
                p *= g[bin(i + b).count('1')]
            b <<= 1
        for b < len(f) / 2:
            p = modular(1)
            for i in range(0, len(f), b * 2):
                for j in range(i, i + b // 2):
                    x = (f[j + b] * p).v
                    f[j + b].v = f[j].v + mod2 - x
                    f[j].v += x
                    f[j].v = (f[j].v < mod2) ? f[j].v : f[j].v - mod2
                p *= g[bin(i + b).count('1')]
            for i in range(i + b // 2, i + b):
                x = (f[j + b] * p).v
                f[j].v = (f[j].v < mod2) ? f[j].v : f[j].v - mod2
                f[j + b].v = f[j].v + mod - x
                f[j].v += x
            p *= g[bin(i + b).count('1')]
        if b < len(f):
            for i in range(b):
                x = f[i + b].v
                f[i + b].v = f[i].v + mod2 - x
                f[i].v += x
    else:
        for i in range(len(f)):
            f[i] *= p2[log2(len(f))]

def convolute2d(x, y):
    n1, m1 = len(x), len(x[0])
    n2, m2 = len(y), len(y[0])
    n, m = n1 + n2 - 1, m1 + m2 - 1
    s = 1
    while s < n * m:
        s *= 2
    p = [[modular(0)] * m for _ in range(n)]
    q = [[modular(0)] * m for _ in range(n)]
    for i in range(n1):
        for j in range(m1):
            p[i][j] = x[i][j]
    for i in range(n2):
        for j in range(m2):
            q[i][j] = y[i][j]
    inplace_fmt(p, False)
    inplace_fmt(q, False)
    for i in range(n):
        for j in range(m):
            p[i][j] *= q[i][j]
    inplace_fmt(p, True)
    res = [[modular(0)] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            res[i][j] = p[i][j]
    return res

def exp_poly_sum_limit(a, f):
    assert a != 1
    k = len(f) - 1
    if a == 0:
        return f[0]
    else:
        g = [modular(0)] * (k + 1)
        r = modular(1)
        for i in range(k + 1):
            g[i] = f[i] * r
            r *= a
        c = modular(0)
        w = modular(0)
        r = modular(1)
        for i in range(k + 1):
            w += choose(k + 1, i) * r
            r *= -a
            c += g[k - i] * w
        c /= (modular(1) - a).pow(k + 1)
        return c

def exp_gen_coeff_sum(a, f):
    ans = modular(0)
    w = (modular(1) - a).inv()
    cur = modular(1)
    for k in range(len(f)):
        cur *= w
        ans += fact[k] * cur * f[k]
    return ans

def multiply_large(a, b, mx):
    n, m = len(a), len(b)
    c = [modular(0)] * (n + m - 1)
    s = 1 << (mx - 1)
    for i in range(0, n, s):
        for j in range(0, n, s):
            x = min(s, n - i)
            y = min(s, m - j)
            d = multiply(a[i:i + x], b[j:j + y])
            for k in range(len(d)):
                c[i + j + k] += d[k]
    return c

def slv():
    n, k = map(int, input().split())
    ls = list(map(int, input().split()))
    tot = sum(ls)
    buf = []
    for idx in range(n):
        s = (ls[idx] - 1) // k + 1
        f = [[modular(0), modular(0)] for _ in range(s)]
        for num in range(s):
            w = modular(ls[idx] - k * num) / tot
            if num:
                f[num][0] = w.pow(num - 1) * finv[num - 1]
            f[num][1] = w.pow(num) * finv[num]
        buf.append(f)
    pq = []
    for i in range(n):
        pq.append((getsz(buf[i]), i))
    pq.sort()
    for _ in range(n - 1):
        i = pq[0][1]
        pq.pop(0)
        j = pq[0][1]
        pq.pop(0)
        buf[i] = convolute2d(buf[i], buf[j])
        buf[j] = []
        pq.append((getsz(buf[i]), i))
        pq.sort()
    ans = buf[pq[0][1]]
    sum = modular(0)
    for num in range(1, len(ans)):
        f = [modular(0)] * (num + 1)
        for i in range(len(ans[num])):
            if i + num - n >= 0:
                f[i + num - n] = ans[num][i]
            else:
                assert ans[num][i] == 0
        w = modular(tot - num * k) / tot
        val = exp_gen_coeff_sum(w, f)
        if num % 2 == 0:
            val = -val
        sum += val
    print(sum)

slv()
