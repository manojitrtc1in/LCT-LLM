import math

mod = 998244353

def powmod(a, b):
    res = 1
    a %= mod
    while b > 0:
        if b & 1:
            res = (res * a) % mod
        a = (a * a) % mod
        b >>= 1
    return res

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a // gcd(a, b) * b

def bpow(x, n):
    return pow(x, n, mod)

def nCr(n, r):
    res = 1
    for i in range(r):
        res = (res * (n - i)) % mod
        res = (res * powmod(i + 1, mod - 2)) % mod
    return res

def mul_slow(a, b):
    res = [0] * (len(a) + len(b) - 1)
    for i in range(len(a)):
        for j in range(len(b)):
            res[i + j] += a[i] * b[j]
            res[i + j] %= mod
    return res

def mul(a, b):
    if min(len(a), len(b)) < 500:
        return mul_slow(a, b)
    n = 1
    while n < len(a) + len(b) - 1:
        n <<= 1
    a += [0] * (n - len(a))
    b += [0] * (n - len(b))
    w = [0] * n
    wn = powmod(3, (mod - 1) // n)
    w[0] = 1
    for i in range(1, n):
        w[i] = (w[i - 1] * wn) % mod
    a = fft(a, w, n)
    b = fft(b, w, n)
    for i in range(n):
        a[i] = (a[i] * b[i]) % mod
    a = fft(a, w, n, inv=True)
    inv_n = powmod(n, mod - 2)
    for i in range(n):
        a[i] = (a[i] * inv_n) % mod
    return a

def fft(a, w, n, inv=False):
    if n == 1:
        return a
    a0 = a[::2]
    a1 = a[1::2]
    y0 = fft(a0, w, n // 2, inv)
    y1 = fft(a1, w, n // 2, inv)
    y = [0] * n
    wn = 1
    if inv:
        wn = powmod(wn, mod - 2)
    for k in range(n // 2):
        u = y0[k]
        v = (y1[k] * wn) % mod
        y[k] = (u + v) % mod
        y[k + n // 2] = (u - v) % mod
        wn = (wn * w) % mod
    return y

def poly_mul(a, b):
    res = mul(a, b)
    while len(res) > 1 and res[-1] == 0:
        res.pop()
    return res

def poly_pow(a, k):
    res = [1]
    while k > 0:
        if k & 1:
            res = poly_mul(res, a)
        a = poly_mul(a, a)
        k >>= 1
    return res

def poly_inv(a, n):
    res = poly_pow(a, n)
    return res[:n]

def poly_divmod(a, b):
    n = len(a)
    m = len(b)
    if n < m:
        return [0], a
    inv_b = poly_inv(b, n - m + 1)
    res = poly_mul(a, inv_b)
    res = res[:n - m + 1]
    return res, a[n - m + 1:]

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_log(a, n):
    assert a[0] == 1
    b = poly_inv(a, n)
    c = poly_mul(a[1:], poly_inv(a, n - 1))
    c = c[:n - 1]
    c = [0] + c
    c = poly_interpolate(b, c)
    c = poly_mul(c, poly_inv(a, n))
    c = c[:n]
    return c

def poly_exp(a, n):
    if len(a) == 1:
        return [1]
    b = poly_exp(a[:len(a) // 2], n)
    c = poly_log(b, n)
    for i in range(len(c)):
        c[i] = (a[i] - c[i]) % mod
    c[0] = (c[0] + 1) % mod
    c = poly_mul(c, b)
    c = c[:n]
    return c

def poly_pow(a, k, n):
    if k == 0:
        return [1]
    if k % 2 == 1:
        return poly_mul(poly_pow(a, k - 1, n), a)[:n]
    b = poly_pow(a, k // 2, n)
    return poly_mul(b, b)[:n]

def poly_mulx(a, x):
    res = [0] * (len(a) + 1)
    for i in range(len(a)):
        res[i + 1] = a[i]
    res[0] = x
    return res

def poly_mulx_sq(a, x):
    res = [0] * (len(a) + 2)
    for i in range(len(a)):
        res[i + 2] = a[i]
    res[0] = x * x
    res[1] = x
    return res

def poly_chirpz_even(z, n):
    m = len(z)
    if m == 0:
        return [0] * n
    if m == 1:
        return [z[0]] * n
    even = poly_chirpz_even(z[::2], (n + 1) // 2)
    odd = poly_chirpz_even(z[1::2], n // 2)
    res = [0] * n
    for i in range(n // 2):
        res[2 * i] = even[i]
        res[2 * i + 1] = odd[i]
    if n % 2 == 1:
        res[n - 1] = even[-1]
    return res

def poly_chirpz(z, n):
    even = poly_chirpz_even(z, (n + 1) // 2)
    odd = poly_chirpz_even(poly_mulx(z, 1), n // 2)
    res = [0] * n
    for i in range(n // 2):
        res[2 * i] = even[i]
        res[2 * i + 1] = odd[i]
    if n % 2 == 1:
        res[n - 1] = even[-1]
    return res

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
    c = fft(c, powmod(3, (mod - 1) // m, mod - 1), m, inv=True)
    return c[:n]

def poly_eval(p, x):
    res = 0
    for i in range(len(p) - 1, -1, -1):
        res = (res * x + p[i]) % mod
    return res

def poly_interpolate(x, y):
    n = len(x)
    m = 1
    while m < n:
        m <<= 1
    x += [0] * (m - n)
    y += [0] * (m - n)
    a = fft(x, powmod(3, (mod - 1) // m), m)
    b = fft(y, powmod(3, (mod - 1) // m), m)
    c = [0] * m
    inv_m = powmod(m, mod - 2)
    for i in range(m):
        c[i] = (a[i] * b[i] * inv_m) % mod
