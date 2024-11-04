import sys
import numpy as np

mod = 998244353
id8 = [1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681]
id4 = [7, 6, 3, 5, 3, 3, 3, 3, 3, 17]

def clean(a):
    for i in range(len(a) - 1, -1, -1):
        if a[i] != 0:
            if i == len(a) - 1:
                return a
            return a[:i + 1]
    return []

def id5(a, b):
    c = [0] * (len(a) + len(b) - 1)
    big = 8 * mod * mod
    for i in range(len(a)):
        for j in range(len(b)):
            c[i + j] += a[i] * b[j]
            if c[i + j] >= big:
                c[i + j] -= big
    return [x % mod for x in c]

def id6(a, b, P, g):
    m = max(2, 1 << (max(len(a), len(b)) - 1).bit_length() + 2)
    fa = id9(a, m, False, P, g)
    fb = fa if a == b else id9(b, m, False, P, g)
    for i in range(m):
        fa[i] = fa[i] * fb[i] % P
    return id9(fa, m, True, P, g)

def id9(src, n, inverse, P, g):
    dst = src + [0] * (n - len(src))
    h = (n).bit_length() - 1
    K = 1 << (P.bit_length() - 1)
    H = (K * K // P).bit_length() * 2
    M = K * K // P

    wws = [0] * (1 << (h - 1))
    dw = pow(g, (P - 1) // n, P) if not inverse else pow(g, P - 1 - (P - 1) // n, P)
    w = (1 << 32) % P
    for k in range(1 << (h - 1)):
        wws[k] = int(w)
        w = modh(w * dw, M, H, P)

    J = invl(P, 1 << 32)
    for i in range(h):
        for j in range(1 << i):
            for k in range(1 << (h - i - 1)):
                s = j << (h - i)
                t = s | (1 << (h - i - 1))
                u = (dst[s] - dst[t] + 2 * P) * wws[k]
                dst[s] += dst[t]
                if dst[s] >= 2 * P:
                    dst[s] -= 2 * P

                Q = (u << 32) * J >> 32
                dst[t] = (u >> 32) - (Q * P >> 32) + P

        if i < h - 1:
            for k in range(1 << (h - i - 2)):
                wws[k] = wws[k * 2]

    for i in range(n):
        if dst[i] >= P:
            dst[i] -= P
    for i in range(n):
        rev = int('{:0{width}b}'.format(i, width=h)[::-1], 2)
        if i < rev:
            dst[i], dst[rev] = dst[rev], dst[i]

    if inverse:
        in_inv = invl(n, P)
        for i in range(n):
            dst[i] = modh(dst[i] * in_inv, M, H, P)

    return dst

def modh(a, M, h, mod):
    r = a - ((M * (a & ((1 << 31) - 1)) >> 31) + M * (a >> 31) >> h - 31) * mod)
    return r if r < mod else r - mod

def invl(a, mod):
    b = mod
    p, q = 1, 0
    while b > 0:
        c = a // b
        a, b = b, a % b
        p, q = q, p - c * q
    return p if p >= 0 else p + mod

def solve():
    n = int(sys.stdin.readline().strip())
    K = int(sys.stdin.readline().strip())
    d = list(map(int, sys.stdin.readline().strip().split()))
    f = [0] * 20
    for i in range(K):
        for j in range(K):
            f[10 + d[i] - d[j]] += 1

    n //= 2
    g = [1]
    for D in range(17, -1, -1):
        g = clean(id6(g, g, mod, 3))
        if n << ~D < 0:
            g = clean(id5(g, f))

    print(g[n * 10] if n * 10 < len(g) else 0)

if __name__ == "__main__":
    solve()
