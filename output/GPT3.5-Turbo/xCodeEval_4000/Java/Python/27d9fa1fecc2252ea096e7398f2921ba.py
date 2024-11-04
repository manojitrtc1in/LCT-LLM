NTTPrimes = [1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681]
NTTPrimitiveRoots = [7, 6, 3, 5, 3, 3, 3, 3, 3, 17]

def convoluteSimply(a, b, P, g):
    m = max(2, (1 << (max(len(a), len(b)) - 1).bit_length()) << 2)
    fa = nttmb(a, m, False, P, g)
    fb = fa if a == b else nttmb(b, m, False, P, g)
    for i in range(m):
        fa[i] = fa[i] * fb[i] % P
    return nttmb(fa, m, True, P, g)

def convolute(a, b):
    USE = 2
    m = max(2, (1 << (max(len(a), len(b)) - 1).bit_length()) << 2)
    fs = [[] for _ in range(USE)]
    for k in range(USE):
        P, g = NTTPrimes[k], NTTPrimitiveRoots[k]
        fa = nttmb(a, m, False, P, g)
        fb = fa if a == b else nttmb(b, m, False, P, g)
        for i in range(m):
            fa[i] = fa[i] * fb[i] % P
        fs[k] = nttmb(fa, m, True, P, g)

    mods = NTTPrimes[:USE]
    gammas = garnerPrepare(mods)
    buf = [0] * USE
    for i in range(len(fs[0])):
        for j in range(USE):
            buf[j] = int(fs[j][i])
        res = garnerBatch(buf, mods, gammas)
        ret = 0
        for j in range(len(res) - 1, -1, -1):
            ret = ret * mods[j] + res[j]
        fs[0][i] = ret
    return fs[0]

def convolute1(a, b):
    m = max(2, (1 << (max(len(a), len(b)) - 1).bit_length()) << 2)
    P, g = NTTPrimes[0], NTTPrimitiveRoots[0]
    fa = nttmb(a, m, False, P, g)
    fb = fa if a == b else nttmb(b, m, False, P, g)
    for i in range(m):
        fa[i] = fa[i] * fb[i] % P
    f = nttmb(fa, m, True, P, g)
    return f

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

def convolute(a, b, USE, mod):
    if len(a) + len(b) <= 200:
        return multiply(a, b, mod)
    m = max(2, (1 << (max(len(a), len(b)) - 1).bit_length()) << 2)
    fs = [[] for _ in range(USE)]
    for k in range(USE):
        P, g = NTTPrimes[k], NTTPrimitiveRoots[k]
        fa = nttmb(a, m, False, P, g)
        fb = fa if a == b else nttmb(b, m, False, P, g)
        for i in range(m):
            fa[i] = fa[i] * fb[i] % P
        fs[k] = nttmb(fa, m, True, P, g)

    mods = NTTPrimes[:USE]
    gammas = garnerPrepare(mods)
    buf = [0] * USE
    for i in range(len(fs[0])):
        for j in range(USE):
            buf[j] = int(fs[j][i])
        res = garnerBatch(buf, mods, gammas)
        ret = 0
        for j in range(len(res) - 1, -1, -1):
            ret = (ret * mods[j] + res[j]) % mod
        fs[0][i] = ret
    return fs[0]

def nttmb(src, n, inverse, P, g):
    dst = src[:n]

    h = n.bit_length() - 1
    K = (1 << (P - 1).bit_length()) << 1
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
        in_ = invl(n, P)
        for i in range(n):
            dst[i] = modh(dst[i] * in_, M, H, P)
    
    return dst

def nttsb(src, n, inverse, P, g):
    dst = src[:n]

    h = n.bit_length() - 1
    K = (1 << (P - 1).bit_length()) << 1
    H = K.bit_length() * 2
    M = K * K // P

    dw = pow(g, P - 1 - (P - 1) // n, P) if inverse else pow(g, (P - 1) // n, P)
    wws = [0] * (1 << (h - 1))
    ws = [0] * (1 << (h - 1))
    w = 1
    for k in range(1 << (h - 1)):
        wws[k] = w << 32 // P
        ws[k] = w
        w = modh(w * dw, M, H, P)
    
    for i in range(h):
        for j in range(1 << i):
            for k in range(1 << (h - i - 1)):
                s = j << (h - i)
                t = s | (1 << (h - i - 1))
                ndsts = dst[s] + dst[t]
                if ndsts >= 2 * P:
                    ndsts -= 2 * P
                T = dst[s] - dst[t] + 2 * P
                Q = wws[k] * T >> 32
                dst[s] = ndsts
                dst[t] = ws[k] * T - Q * P & ((1 << 32) - 1)
        
        if i < h - 1:
            for k in range(1 << (h - i - 2)):
                wws[k] = wws[k * 2]
                ws[k] = ws[k * 2]
    
    for i in range(n):
        if dst[i] >= P:
            dst[i] -= P
    
    for i in range(n):
        rev = int(bin(i)[2:].zfill(h)[::-1], 2)
        if i < rev:
            dst[i], dst[rev] = dst[rev], dst[i]
    
    if inverse:
        in_ = invl(n, P)
        for i in range(n):
            dst[i] = modh(dst[i] * in_, M, H, P)
    
    return dst

def garnerPrepare(m):
    n = len(m)
    if n == 0:
        return []
    gamma = [0] * n
    for k in range(1, n):
        prod = 1
        for i in range(k):
            prod = prod * m[i] % m[k]
        gamma[k] = invl(prod, m[k])
    return gamma

def garnerBatch(u, m, gamma):
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
    return p if p >= 0 else p + mod

def modh(a, M, h, mod):
    r = a - ((M * (a & ((1 << 31) - 1)) >> 31) + M * (a >> 31) >> h - 31) * mod
    return r if r < mod else r - mod

def solve():
    n = int(input()) // 2
    b = [0] * 10
    for _ in range(int(input())):
        b[int(input())] = 1
    mod = 998244353
    ans = [1]
    while n > 0:
        if n & 1:
            ans = convoluteSimply(ans, b, mod, 3)
            sz = len(ans) - 1
            while sz > 0 and ans[sz] == 0:
                sz -= 1
            if len(ans) - sz > 100:
                ans = ans[:sz + 1]
        n >>= 1
        b = convoluteSimply(b, b, mod, 3)
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

if __name__ == "__main__":
    solve()
