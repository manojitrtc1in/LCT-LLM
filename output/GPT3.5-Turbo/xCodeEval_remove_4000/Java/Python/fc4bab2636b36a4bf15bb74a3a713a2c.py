import sys
from typing import List

def solve(n: int, K: int, d: List[int]) -> int:
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
    
    return g[n * 10] if n * 10 < len(g) else 0

def clean(a: List[int]) -> List[int]:
    for i in range(len(a) - 1, -1, -1):
        if a[i] != 0:
            if i == len(a) - 1:
                return a
            return a[:i+1]
    return []

def id5(a: List[int], b: List[int]) -> List[int]:
    c = [0] * (len(a) + len(b) - 1)
    big = 8 * mod * mod
    for i in range(len(a)):
        for j in range(len(b)):
            c[i + j] += a[i] * b[j]
            if c[i + j] >= big:
                c[i + j] -= big
    for i in range(len(c)):
        c[i] %= mod
    return c

def id6(a: List[int], b: List[int], P: int, g: int) -> List[int]:
    m = max(2, (1 << (len(bin(max(len(a), len(b))) - 2)))) << 2
    fa = id9(a, m, False, P, g)
    fb = fa if a == b else id9(b, m, False, P, g)
    for i in range(m):
        fa[i] = fa[i] * fb[i] % P
    return id9(fa, m, True, P, g)

def id9(src: List[int], n: int, inverse: bool, P: int, g: int) -> List[int]:
    dst = src.copy()
    h = n.bit_length() - 1
    K = (1 << (P.bit_length() - 1)) << 1
    H = K.bit_length() * 2
    M = K * K // P

    wws = [0] * (1 << (h - 1))
    dw = pow(g, P - 1 - (P - 1) // n, P) if inverse else pow(g, (P - 1) // n, P)
    w = (1 << 32) % P
    for k in range(1 << (h - 1)):
        wws[k] = w
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
        rev = int(bin(i)[2:].zfill(h)[::-1], 2)
        if i < rev:
            dst[i], dst[rev] = dst[rev], dst[i]
    
    if inverse:
        inv = invl(n, P)
        for i in range(n):
            dst[i] = modh(dst[i] * inv, M, H, P)
    
    return dst

def modh(a: int, M: int, h: int, mod: int) -> int:
    r = a - ((M * (a & ((1 << 31) - 1)) >> 31) + M * (a >> 31) >> (h - 31)) * mod
    return r if r < mod else r - mod

def id1(m: List[int]) -> List[int]:
    n = len(m)
    gamma = [0] * n
    for k in range(1, n):
        prod = 1
        for i in range(k):
            prod = prod * m[i] % m[k]
        gamma[k] = invl(prod, m[k])
    return gamma

def id7(u: List[int], m: List[int], gamma: List[int]) -> List[int]:
    n = len(u)
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

def pow(a: int, n: int, mod: int) -> int:
    ret = 1
    x = 63 - n.bit_length()
    while x >= 0:
        ret = ret * ret % mod
        if n << (63 - x) < 0:
            ret = ret * a % mod
        x -= 1
    return ret

def invl(a: int, mod: int) -> int:
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

mod = 998244353

def main():
    n, K = map(int, input().split())
    d = list(map(int, input().split()))
    result = solve(n, K, d)
    print(result)

if __name__ == "__main__":
    main()
