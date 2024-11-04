import sys
from typing import List
from collections import deque

MOD = 998244353
G = 3


def solve() -> None:
    n = ni()
    g = [[False] * 10 for _ in range(10)]
    for _ in range(ni()):
        x, y = ni(), ni()
        g[x][y] = g[y][x] = True
    for i in range(10):
        g[i][i] = True

    njs = [[0] * 10 for _ in range(1 << 9)]
    for j in range(1 << 9):
        for k in range(10):
            if j << ~k >= 0:
                nj = j
                for l in range(10):
                    if g[k][l]:
                        if k > l:
                            nj |= 1 << l
                    else:
                        nj &= ~(1 << l)
                njs[j][k] = nj

    dp = [0] * (1 << 9)
    dp[0] = 1
    for _ in range(1, n + 1):
        ndp = [0] * (1 << 9)
        for j in range(1 << 9):
            for k in range(10):
                if j << ~k >= 0:
                    nj = njs[j][k]
                    ndp[nj] += dp[j]
                    if ndp[nj] >= MOD:
                        ndp[nj] -= MOD
        dp = ndp
    ans = sum(dp) % MOD
    out.println(ans)


def sum(a: List[int]) -> int:
    ret = 0
    for v in a:
        ret += v
    return ret


def mul(a: List[int], b: List[int]) -> List[int]:
    if len(a) == 0 and len(b) == 0:
        return []
    if len(a) + len(b) >= 300:
        return id2_convolve(a, b)[:len(a) + len(b) - 1]
    else:
        return id3(a, b)


def mul_lim(a: List[int], b: List[int], lim: int) -> List[int]:
    if len(a) + len(b) >= 300:
        return id2_convolve(a, b)[:lim]
    else:
        return id3(a, b, lim)


def id3(a: List[int], b: List[int]) -> List[int]:
    c = [0] * (len(a) + len(b) - 1)
    for i in range(len(a)):
        for j in range(len(b)):
            c[i + j] += a[i] * b[j]
            if c[i + j] >= big:
                c[i + j] -= big
    for i in range(len(c)):
        c[i] %= MOD
    return c


def id3_lim(a: List[int], b: List[int], lim: int) -> List[int]:
    c = [0] * lim
    for i in range(len(a)):
        for j in range(len(b)):
            if i + j < lim:
                c[i + j] += a[i] * b[j]
                if c[i + j] >= big:
                    c[i + j] -= big
    for i in range(len(c)):
        c[i] %= MOD
    return c


def id2_convolve(a: List[int], b: List[int]) -> List[int]:
    m = max(2, 1 << (len(a) + len(b) - 2).bit_length() << 2)

    wps = [0] * m
    unit = pow(G, (MOD - 1) // m, MOD)
    wps[0] = 1
    for p in range(1, m):
        wps[p] = wps[p - 1] * unit % MOD

    fa = go(a, m, False)
    fb = fa if a == b else go(b, m, False)
    for i in range(m):
        fa[i] = fa[i] * fb[i] % MOD
    fa = go(fa, m, True)
    fa[1:] = fa[-1:0:-1]
    return fa


def go(src: List[int], n: int, inverse: bool) -> List[int]:
    dst = src.copy()
    fft(dst, [0] * n)
    if inverse:
        in_ = invl(n)
        for i in range(n):
            dst[i] = dst[i] * in_ % MOD
    return dst


def fft(X: List[int], Y: List[int]) -> None:
    s = 1
    eo = False
    n = len(X)
    for m in range(n, 3, -1):
        m >>= 1
        for p in range(m):
            wp = wps[s * p]
            wk = (wp << 32) // MOD
            for q in range(s):
                a = X[q + s * (p + 0)]
                b = X[q + s * (p + m)]
                ndsts = a + b
                if ndsts >= 2 * MOD:
                    ndsts -= 2 * MOD
                T = a - b + 2 * MOD
                Q = wk * T >> 32
                Y[q + s * (2 * p + 0)] = ndsts
                Y[q + s * (2 * p + 1)] = wp * T - Q * MOD & ((1 << 32) - 1)
        s *= 2
        eo = not eo
        X, Y = Y, X
    z = Y if eo else X
    for q in range(s):
        a = X[q + 0]
        b = X[q + s]
        z[q + 0] = (a + b) % MOD
        z[q + s] = (a - b + 2 * MOD) % MOD


def id0(n: int) -> List[List[int]]:
    f = [0] * (n + 1)
    invf = [0] * (n + 1)
    f[0] = 1
    for i in range(1, n + 1):
        f[i] = f[i - 1] * i % MOD
    a = f[n]
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    invf[n] = p + MOD if p < 0 else p
    for i in range(n - 1, -1, -1):
        invf[i] = invf[i + 1] * (i + 1) % MOD
    return [f, invf]


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod


def id3(a: int, b: int) -> int:
    c = 0
    for i in range(64):
        c += a << ~i < 0
    return c


def invl(a: int) -> int:
    b = MOD
    p = 1
    q = 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p + MOD if p < 0 else p


