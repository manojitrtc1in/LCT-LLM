def multiply(a, b, mod):
    v = mod
    v *= mod
    ans = [0] * (len(a) + len(b) - 1)
    for i in range(len(a)):
        for j in range(len(b)):
            ans[i + j] += a[i] * b[j]
            if ans[i + j] >= v:
                ans[i + j] -= v
    for i in range(len(ans)):
        ans[i] %= mod
    return ans

def id3(a, b, USE, mod):
    if len(a) + len(b) <= 200:
        return multiply(a, b, mod)
    m = max(2, (max(len(a), len(b)) - 1).bit_length() << 2)
    fs = []
    for k in range(USE):
        P, g = id10[k], id4[k]
        fa = id13(a, m, False, P, g)
        fb = fa if a == b else id13(b, m, False, P, g)
        for i in range(m):
            fa[i] = fa[i] * fb[i] % P
        fs.append(id13(fa, m, True, P, g))

    mods = id10[:USE]
    gammas = id2(mods)
    buf = [0] * USE
    for i in range(len(fs[0])):
        for j in range(USE):
            buf[j] = int(fs[j][i])
        res = id8(buf, mods, gammas)
        ret = 0
        for j in range(len(res) - 1, -1, -1):
            ret = ret * mods[j] + res[j]
        fs[0][i] = ret
    return fs[0]

def id2(m):
    n = len(m)
    assert n == len(m)
    if n == 0:
        return []
    gamma = [0] * n
    for k in range(1, n):
        prod = 1
        for i in range(k):
            prod = prod * m[i] % m[k]
        gamma[k] = invl(prod, m[k])
    return gamma

def id8(u, m, gamma):
    n = len(u)
    assert n == len(m)
    v = [0] * n
    v[0] = u[0]
    for k in range(1, n):
        temp = v[k - 1]
        for j in range(k - 2, -1, -1):
            temp = (temp * m[j] + v[j]) % m[k]
        v[k] = (u[k] - temp) * gamma[k] % m[k]
        if v[k] < 0:
            v[k] += m[k]
    return v

def pow(a, n, mod):
    ret = 1
    x = 63 - n.bit_length()
    while x >= 0:
        ret = ret * ret % mod
        if n << 63 - x < 0:
            ret = ret * a % mod
        x -= 1
    return ret

def invl(a, mod):
    b = mod
    p, q = 1, 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + mod if p < 0 else p

def modh(a, M, h, mod):
    r = a - ((M * (a & ((1 << 31) - 1)) >> 31) + M * (a >> 31) >> h - 31) * mod
    return r if r < mod else r - mod

def id13(src, n, inverse, P, g):
    dst = src[:n]
    h = n.bit_length() - 1
    K = (P.bit_length() - 1).bit_length() << 1
    H = (K * 2).bit_length()
    M = K * K // P

    wws = [0] * (1 << h - 1)
    dw = pow(g, P - 1 - (P - 1) // n, P) if inverse else pow(g, (P - 1) // n, P)
    w = (1 << 32) % P
    for k in range(1 << h - 1):
        wws[k] = w
        w = modh(w * dw, M, H, P)

    J = invl(P, 1 << 32)
    for i in range(h):
        for j in range(1 << i):
            for k in range(1 << h - i - 1):
                s = j << h - i
                t = s | 1 << h - i - 1
                u = (dst[s] - dst[t] + 2 * P) * wws[k]
                dst[s] += dst[t]
                if dst[s] >= 2 * P:
                    dst[s] -= 2 * P

                Q = (u << 32) * J >> 32
                dst[t] = (u >> 32) - (Q * P >> 32) + P

        if i < h - 1:
            for k in range(1 << h - i - 2):
                wws[k] = wws[k * 2]

    for i in range(n):
        if dst[i] >= P:
            dst[i] -= P
    for i in range(n):
        rev = (i.bit_length() - 1).bit_length() - i
        if i < rev:
            d = dst[i]
            dst[i] = dst[rev]
            dst[rev] = d

    if inverse:
        in_ = invl(n, P)
        for i in range(n):
            dst[i] = modh(dst[i] * in_, M, H, P)

    return dst

def id7(a, b, P, g):
    m = max(2, (max(len(a), len(b)) - 1).bit_length() << 2)
    fa = id13(a, m, False, P, g)
    fb = fa if a == b else id13(b, m, False, P, g)
    for i in range(m):
        fa[i] = fa[i] * fb[i] % P
    return id13(fa, m, True, P, g)

def id11(a, b):
    m = max(2, (max(len(a), len(b)) - 1).bit_length() << 2)
    P, g = id10[0], id4[0]
    fa = id13(a, m, False, P, g)
    fb = fa if a == b else id13(b, m, False, P, g)
    for i in range(m):
        fa[i] = fa[i] * fb[i] % P
    return id13(fa, m, True, P, g)

def id3(a, b):
    USE = 2
    m = max(2, (max(len(a), len(b)) - 1).bit_length() << 2)
    fs = []
    for k in range(USE):
        P, g = id10[k], id4[k]
        fa = id13(a, m, False, P, g)
        fb = fa if a == b else id13(b, m, False, P, g)
        for i in range(m):
            fa[i] = fa[i] * fb[i] % P
        fs.append(id13(fa, m, True, P, g))

    mods = id10[:USE]
    gammas = id2(mods)
    buf = [0] * USE
    for i in range(len(fs[0])):
        for j in range(USE):
            buf[j] = int(fs[j][i])
        res = id8(buf, mods, gammas)
        ret = 0
        for j in range(len(res) - 1, -1, -1):
            ret = ret * mods[j] + res[j]
        fs[0][i] = ret
    return fs[0]

id10 = [1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681]
id4 = [7, 6, 3, 5, 3, 3, 3, 3, 3, 17]

def solve():
    n = int(input()) // 2
    b = [0] * 10
    for _ in range(int(input())):
        b[int(input())] = 1
    mod = 998244353
    ans = [1]
    while n > 0:
        if n & 1:
            ans = id7(ans, b, mod, 3)
            sz = len(ans) - 1
            while sz > 0 and ans[sz] == 0:
                sz -= 1
            if len(ans) - sz > 100:
                ans = ans[:sz + 1]
        n >>= 1
        b = id7(b, b, mod, 3)
        sz = len(b) - 1
        while sz > 0 and b[sz] == 0:
            sz -= 1
        if len(b) - sz > 100:
            b = b[:sz + 1]
    res = 0
    for i in range(len(ans)):
        res += ans[i] * ans[i]
        res %= mod
    print(res)

solve()
