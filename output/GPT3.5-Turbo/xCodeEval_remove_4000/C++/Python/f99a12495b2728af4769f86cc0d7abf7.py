MOD = 998244353

class ModInt:
    def __init__(self, x):
        self.x = x % MOD

    def val(self):
        return self.x

    def __add__(self, rhs):
        if isinstance(rhs, ModInt):
            return ModInt(self.x + rhs.x)
        else:
            return ModInt(self.x + rhs)

    def __sub__(self, rhs):
        if isinstance(rhs, ModInt):
            return ModInt(self.x - rhs.x)
        else:
            return ModInt(self.x - rhs)

    def __mul__(self, rhs):
        if isinstance(rhs, ModInt):
            return ModInt(self.x * rhs.x)
        else:
            return ModInt(self.x * rhs)

    def __truediv__(self, rhs):
        if isinstance(rhs, ModInt):
            return ModInt(self.x * pow(rhs.x, MOD - 2, MOD))
        else:
            return ModInt(self.x * pow(rhs, MOD - 2, MOD))

    def __pow__(self, n):
        return ModInt(pow(self.x, n, MOD))

    def __str__(self):
        return str(self.x)

    def __repr__(self):
        return str(self.x)

def press(x):
    res = sorted(list(set(x)))
    x = [res.index(i) for i in x]
    return res, x

def chmin(a, b):
    if a > b:
        a = b
        return True
    return False

def chmax(a, b):
    if a < b:
        a = b
        return True
    return False

def divup(x, y):
    return (x + (y - 1)) // y

def pow(a, n, e=1):
    ret = e
    while n:
        if n & 1:
            ret *= a
        a *= a
        n >>= 1
    return ret

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def ntt(a):
    n = len(a)
    assert (n & (n - 1)) == 0
    assert n.bit_length() <= max_base
    for m in range(n, 1, -1):
        w = ModInt(1)
        for s in range(0, n, 2 * m):
            for i in range(s, s + m):
                x = a[i]
                y = a[i + m] * w
                a[i] = x + y
                a[i + m] = x - y
            w *= dw[(k + 1).bit_length() - 2]
    return a

def intt(a, f=True):
    n = len(a)
    assert (n & (n - 1)) == 0
    assert n.bit_length() <= max_base
    for m in range(1, n):
        w = ModInt(1)
        for s in range(0, n, 2 * m):
            for i in range(s, s + m):
                x = a[i]
                y = a[i + m]
                a[i] = x + y
                a[i + m] = (x - y) * w
            w *= idw[(k + 1).bit_length() - 2]
    if f:
        inv_sz = ModInt(1) / n
        for i in range(n):
            a[i] *= inv_sz
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

def multiply(a, b):
    need = len(a) + len(b) - 1
    nbase = 1
    while (1 << nbase) < need:
        nbase += 1
    sz = 1 << nbase
    a += [0] * (sz - len(a))
    b += [0] * (sz - len(b))
    a = ntt(a)
    b = ntt(b)
    inv_sz = ModInt(1) / sz
    for i in range(sz):
        a[i] *= b[i] * inv_sz
    a = intt(a, False)
    a = a[:need]
    return a

class FormalPowerSeries(list):
    def __init__(self, *args):
        super().__init__(*args)

    def __add__(self, r):
        if isinstance(r, FormalPowerSeries):
            return FormalPowerSeries([x + y for x, y in zip(self, r)])
        else:
            return FormalPowerSeries([x + r for x in self])

    def __sub__(self, r):
        if isinstance(r, FormalPowerSeries):
            return FormalPowerSeries([x - y for x, y in zip(self, r)])
        else:
            return FormalPowerSeries([x - r for x in self])

    def __mul__(self, r):
        if isinstance(r, FormalPowerSeries):
            return FormalPowerSeries(multiply(self, r))
        else:
            return FormalPowerSeries([x * r for x in self])

    def __truediv__(self, r):
        if isinstance(r, FormalPowerSeries):
            return FormalPowerSeries(divide(self, r))
        else:
            inv_r = ModInt(1) / r
            return FormalPowerSeries([x * inv_r for x in self])

    def __mod__(self, r):
        if isinstance(r, FormalPowerSeries):
            return FormalPowerSeries(modulo(self, r))
        else:
            return FormalPowerSeries([x % r for x in self])

    def __neg__(self):
        return FormalPowerSeries([-x for x in self])

    def __pow__(self, n):
        return FormalPowerSeries(pow(self, n))

    def __str__(self):
        return str(self[:len(self) - 1])

    def __repr__(self):
        return str(self[:len(self) - 1])

    def shrink(self):
        while self and self[-1] == 0:
            self.pop()

    def pre(self, sz):
        return FormalPowerSeries(self[:sz])

    def rev(self, deg=-1):
        ret = FormalPowerSeries(self)
        if deg != -1:
            ret = ret[:deg]
        ret.reverse()
        return ret

    def diff(self):
        n = len(self)
        ret = FormalPowerSeries([self[i] * i for i in range(1, n)])
        return ret

    def integral(self):
        n = len(self)
        ret = FormalPowerSeries([0] + [self[i] / (i + 1) for i in range(n)])
        return ret

    def inv(self, deg=-1):
        assert self[0] != 0
        n = len(self)
        if deg == -1:
            deg = n
        ret = FormalPowerSeries([ModInt(1) / self[0]])
        for i in range(1, deg):
