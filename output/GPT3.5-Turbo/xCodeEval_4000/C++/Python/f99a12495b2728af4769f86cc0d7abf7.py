MOD = 998244353

class ModInt:
    def __init__(self, x):
        self.x = x % MOD

    def val(self):
        return self.x

    def __add__(self, rhs):
        if isinstance(rhs, ModInt):
            return ModInt(self.x + rhs.x)
        elif isinstance(rhs, int):
            return ModInt(self.x + rhs)
        else:
            raise TypeError("Unsupported operand type for +")

    def __sub__(self, rhs):
        if isinstance(rhs, ModInt):
            return ModInt(self.x - rhs.x)
        elif isinstance(rhs, int):
            return ModInt(self.x - rhs)
        else:
            raise TypeError("Unsupported operand type for -")

    def __mul__(self, rhs):
        if isinstance(rhs, ModInt):
            return ModInt(self.x * rhs.x)
        elif isinstance(rhs, int):
            return ModInt(self.x * rhs)
        else:
            raise TypeError("Unsupported operand type for *")

    def __truediv__(self, rhs):
        if isinstance(rhs, ModInt):
            return ModInt(self.x * pow(rhs.x, MOD - 2, MOD))
        elif isinstance(rhs, int):
            return ModInt(self.x * pow(rhs, MOD - 2, MOD))
        else:
            raise TypeError("Unsupported operand type for /")

    def __pow__(self, n):
        return ModInt(pow(self.x, n, MOD))

    def __str__(self):
        return str(self.x)

    def __repr__(self):
        return str(self.x)


class NumberTheoreticTransformFriendlyModInt:
    def __init__(self):
        self.dw = []
        self.idw = []
        self.max_base = 0
        self.root = ModInt(2)

        tmp = MOD - 1
        self.max_base = 0
        while tmp % 2 == 0:
            tmp >>= 1
            self.max_base += 1

        self.dw = [ModInt(0)] * self.max_base
        self.idw = [ModInt(0)] * self.max_base

        for i in range(self.max_base):
            self.dw[i] = -self.root.pow((MOD - 1) >> (i + 2))
            self.idw[i] = ModInt(1) / self.dw[i]

    def ntt(self, a):
        n = len(a)
        assert (n & (n - 1)) == 0
        assert __builtin_ctz(n) <= self.max_base

        for m in range(n, 1, -1):
            w = ModInt(1)
            for s in range(0, n, 2 * m):
                for i in range(s, s + m):
                    j = i + m
                    x = a[i]
                    y = a[j] * w
                    a[i] = x + y
                    a[j] = x - y
                w *= self.dw[__builtin_ctz(m) + 1]

    def intt(self, a, f=True):
        n = len(a)
        assert (n & (n - 1)) == 0
        assert __builtin_ctz(n) <= self.max_base

        for m in range(1, n):
            w = ModInt(1)
            for s in range(0, n, 2 * m):
                for i in range(s, s + m):
                    j = i + m
                    x = a[i]
                    y = a[j]
                    a[i] = x + y
                    a[j] = (x - y) * w
                w *= self.idw[__builtin_ctz(m) + 1]

        if f:
            inv_sz = ModInt(1) / n
            for i in range(n):
                a[i] *= inv_sz

    def multiply(self, a, b):
        need = len(a) + len(b) - 1
        nbase = 1
        while (1 << nbase) < need:
            nbase += 1
        sz = 1 << nbase
        a += [ModInt(0)] * (sz - len(a))
        b += [ModInt(0)] * (sz - len(b))
        self.ntt(a)
        self.ntt(b)
        inv_sz = ModInt(1) / sz
        for i in range(sz):
            a[i] *= b[i] * inv_sz
        self.intt(a, False)
        a = a[:need]
        return a


ntt = NumberTheoreticTransformFriendlyModInt()


class FormalPowerSeries(list):
    def __init__(self, *args):
        super().__init__(*args)

    def shrink(self):
        while self and self[-1] == ModInt(0):
            self.pop()

    def __add__(self, r):
        if isinstance(r, FormalPowerSeries):
            res = FormalPowerSeries(self)
            if len(r) > len(res):
                res += [ModInt(0)] * (len(r) - len(res))
            for i in range(len(r)):
                res[i] += r[i]
            return res
        elif isinstance(r, ModInt):
            res = FormalPowerSeries(self)
            res[0] += r
            return res
        else:
            raise TypeError("Unsupported operand type for +")

    def __sub__(self, r):
        if isinstance(r, FormalPowerSeries):
            res = FormalPowerSeries(self)
            if len(r) > len(res):
                res += [ModInt(0)] * (len(r) - len(res))
            for i in range(len(r)):
                res[i] -= r[i]
            res.shrink()
            return res
        elif isinstance(r, ModInt):
            res = FormalPowerSeries(self)
            res[0] -= r
            res.shrink()
            return res
        else:
            raise TypeError("Unsupported operand type for -")

    def __mul__(self, r):
        if isinstance(r, FormalPowerSeries):
            res = FormalPowerSeries(self)
            if len(r) > len(res):
                res += [ModInt(0)] * (len(r) - len(res))
            res = FormalPowerSeries(ntt.multiply(res, r))
            res.shrink()
            return res
        elif isinstance(r, ModInt):
            res = FormalPowerSeries(self)
            for i in range(len(res)):
                res[i] *= r
            return res
        else:
            raise TypeError("Unsupported operand type for *")

    def __truediv__(self, r):
        if isinstance(r, FormalPowerSeries):
            if len(self) < len(r):
                return FormalPowerSeries([])
            n = len(self) - len(r) + 1
            return (self.rev().pre(n) * r.rev().inv(n)).pre(n).rev(n)
        elif isinstance(r, ModInt):
            res = FormalPowerSeries(self)
            res[0] /= r
            return res
        else:
            raise TypeError("Unsupported operand type for /")

    def __mod__(self, r):
        return self - self // r * r

    def __neg__(self):
        res = FormalPowerSeries(self)
        for i in range(len(res)):
            res[i] = -res[i]
        return res

    def __str__(self):
        return str([str(x) for x in self])

    def __repr__(self):
        return str([str(x) for x in self])

    def pre(self, sz):
        return FormalPowerSeries(self[:min(len(self), sz)])

    def __rshift__(self, sz):
        if len(self) <= sz:
            return FormalPowerSeries([])
        res = FormalPowerSeries(self)
        del res[:sz]
        return res

    def __lshift__(self, sz):
        res = FormalPowerSeries(self)
        res = FormalPowerSeries([ModInt(0)] * sz + res)
        return res

    def rev(self, deg=-1):
        res = FormalPowerSeries(self)
        if deg != -1:
            res = res[:deg]
        res.reverse()
        return res

    def diff(self):
        res = FormalPowerSeries([ModInt(0)] * (len(self) - 1))
        for i in range(1, len(self)):
            res[i - 1] = self[i] * ModInt(i)
        return res

    def integral(self):
        res = FormalPowerSeries([ModInt(0)] * (len(self) + 1))
        for i in range(len(self)):
            res[i + 1] = self[i] / ModInt(i + 1)
        return res

    def inv(self, deg=-1):
        assert self[0] != ModInt(0)
        n = len(self)
        if deg == -1:
            deg = n
        res = FormalPowerSeries([ModInt(0)] * deg)
        res[0] = ModInt(1) / self[0]
        for i in range(1, deg):
            res = (res + res - res * res.pre(i << 1)).pre(i << 1)
        return res.pre(deg)

    def log(self, deg=-1):
        assert self[0] == ModInt(1)
        n = len(self)
        if deg == -1:
            deg = n
        return (self.diff() * self.inv(deg)).pre(deg - 1).integral()

    def sqrt(self, deg=-1):
        n = len(self)
        if deg == -1:
            deg = n
        if self[0] == ModInt(0):
            for i in range(1, n):
                if self[i] != ModInt(0):
                    if i & 1:
                        return FormalPowerSeries([])
                    if deg - i // 2 <= 0:
                        break
                    ret = (self >> i).sqrt(deg - i // 2)
                    if not ret:
                        return FormalPowerSeries([])
                    ret = ret << (i // 2)
                    if len(ret) < deg:
                        ret += [ModInt(0)] * (deg - len(ret))
                    return ret
            return FormalPowerSeries([ModInt(0)] * deg)
        ret = FormalPowerSeries([])
        if self[0] == ModInt(1):
            ret = FormalPowerSeries([ModInt(1)])
        else:
            sqr = self[0].sqrt()
            if sqr * sqr != self[0]:
                return FormalPowerSeries([])
            ret = FormalPowerSeries([ModInt(sqr)])
        inv2 = ModInt(1) / ModInt(2)
        for i in range(1, deg):
            ret = (ret + self.pre(i << 1) * ret.inv(i << 1)) * inv2
        return ret.pre(deg)

    def exp(self, deg=-1):
        assert self[0] == ModInt(0)
        n = len(self)
        if deg == -1:
            deg = n
        res = FormalPowerSeries([ModInt(1)])
        for i in range(1, deg):
            res = (res * (self.pre(i << 1) + ModInt(1) - res.log(i << 1))).pre(i << 1)
        return res.pre(deg)

    def online_convolution_exp(self, conv_coeff):
        n = len(conv_coeff)
        assert (n & (n - 1)) == 0
        conv_ntt_coeff = []
        for i in range(n, 0, -1):
            g = FormalPowerSeries(conv_coeff.pre(i))
            ntt.ntt(g)
            conv_ntt_coeff.append(g)
        conv_arg = FormalPowerSeries(n)
        conv_ret = FormalPowerSeries(n)
        rec = lambda rec, l, r, d: None if r - l <= 16 else None
        rec(rec, 0, n, 0)
        return conv_arg

    def exp_rec(self):
        assert self[0] == ModInt(0)
        n = len(self)
        m = 1
        while m < n:
            m *= 2
        conv_coeff = FormalPowerSeries(m)
        for i in range(1, n):
            conv_coeff[i] = self[i] * i
        return self.online_convolution_exp(conv_coeff).pre(n)

    def inv_fast(self):
        assert self[0] != ModInt(0)
        n = len(self)
        res = FormalPowerSeries([ModInt(1) / self[0]])
        for d in range(1, n):
            f = FormalPowerSeries(2 * d)
            g = FormalPowerSeries(2 * d)
            for j in range(min(n, 2 * d)):
                f[j] = self[j]
            for j in range(d):
                g[j] = res[j]
            ntt.ntt(f)
            ntt.ntt(g)
            for j in range(2 * d):
                f[j] *= g[j]
            ntt.intt(f)
            for j in range(d):
                f[j] = 0
                f[j + d] = -f[j + d]
            ntt.ntt(f)
            for j in range(2 * d):
                f[j] *= g[j]
            ntt.intt(f)
            for j in range(d):
                f[j] = res[j]
            res = f
        return res.pre(n)

    def pow(self, k, deg=-1):
        n = len(self)
        if deg == -1:
            deg = n
        for i in range(n):
            if self[i] != ModInt(0):
                rev = ModInt(1) / self[i]
                ret = (((self * rev) >> i).log() * k).exp() * (self[i].pow(k))
                if i * k > deg:
                    return FormalPowerSeries([])
                ret = (ret << (i * k)).pre(deg)
                if len(ret) < deg:
                    ret += [ModInt(0)] * (deg - len(ret))
                return ret
        return self

    def eval(self, x):
        r = ModInt(0)
        w = ModInt(1)
        for v in self:
            r += w * v
            w *= x
        return r

    def pow_mod(self, n, mod):
        modinv = mod.rev().inv()
        get_div = lambda base: base if len(base) >= len(mod) else FormalPowerSeries([])
        x = self
        ret = FormalPowerSeries([ModInt(1)])
        while n > 0:
            if n & 1:
                ret *= x
                ret -= get_div(ret) * mod
            x *= x
            x -= get_div(x) * mod
            n >>= 1
        return ret


def pow_mod(x, n, mod):
    res = ModInt(1)
    while n > 0:
        if n & 1:
            res = res * x % mod
        x = x * x % mod
        n >>= 1
    return res


def solve():
    n, k = map(int, input().split())
    h = list(map(int, input().split()))
    h.append(h[0])

    cnt = 0
    for i in range(n):
        if h[i] == h[i + 1]:
            cnt += 1
    d = n - cnt

    res = pow_mod(ModInt(k), cnt, MOD)
    sum = 0

    f = FormalPowerSeries([ModInt(0)] * (2 * d + 1))
    f[0] = ModInt(1)
    f[1] = ModInt(k - 2)
    f[2] = ModInt(1)
    f = f.pow(d)
    for i in range(d + 1, 2 * d + 1):
        sum += f[i]

    print(res * sum)


if __name__ == "__main__":
    solve()
