class Modular:
    def __init__(self, m):
        self.m = m

    def get_mod(self):
        return self.m

    def value_of(self, x):
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x, y):
        return self.value_of(x * y)

    def plus(self, x, y):
        return self.value_of(x + y)


class Power:
    def __init__(self, modular):
        self.modular = modular

    def pow(self, x, n):
        if n == 0:
            return self.modular.value_of(1)
        r = self.pow(x, n >> 1)
        r = self.modular.value_of(r * r)
        if n & 1 == 1:
            r = self.modular.value_of(r * x)
        return r

    def inverse(self, x):
        return self.pow(x, self.modular.m - 2)


class NTT:
    @staticmethod
    def pow(x, n, mod):
        res = 1
        p = x
        while n > 0:
            if n & 1 == 1:
                res = res * p % mod
            p = p * p % mod
            n >>= 1
        return res

    @staticmethod
    def ntt(a, n, invert, mod, root):
        shift = 32 - n.bit_length()
        for i in range(1, n):
            j = (i << shift).bit_reverse()
            if i < j:
                a[i], a[j] = a[j], a[i]

        root_inv = NTT.pow(root, mod - 2, mod)

        for length in range(2, n + 1 << 1):
            half = length >> 1
            step = NTT.pow(root if not invert else root_inv, (mod - 1) // length, mod)
            for i in range(0, n, length):
                w = 1
                for j in range(i, i + half):
                    u = a[j]
                    v = a[j + half] * w % mod
                    a[j] = (u + v) % mod
                    a[j + half] = (u - v + mod) % mod
                    w = w * step % mod

        if invert:
            n_inv = NTT.pow(n, mod - 2, mod)
            for i in range(n):
                a[i] = a[i] * n_inv % mod


class Polynomials:
    @staticmethod
    def rank_of(p):
        r = len(p) - 1
        while r >= 0 and p[r] == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def normalize(p):
        p[:] = p[:Polynomials.rank_of(p) + 1]


class id9:
    def __init__(self, mod, g):
        self.modular = mod
        self.power = Power(mod)
        self.g = g
        self.w_cache = [0] * 30
        self.inv_cache = [0] * 30
        for i in range(30):
            s = 1 << i
            self.w_cache[i] = self.power.pow(self.g, (self.modular.get_mod() - 1) // 2 // s)
            self.inv_cache[i] = self.power.inverse(s)

    def dot_mul(self, a, b, c, m):
        for i in range(1 << m):
            c[i] = self.modular.mul(a[i], b[i])

    def prepare_reverse(self, r, b):
        n = 1 << b
        r[0] = 0
        for i in range(1, n):
            r[i] = (r[i >> 1] >> 1) | ((1 & i) << (b - 1))

    def dft(self, p, m):
        n = 1 << m

        rev = [0] * (1 << m)
        self.prepare_reverse(rev, m)

        for i in range(n):
            if rev[i] > i:
                p[i], p[rev[i]] = p[rev[i]], p[i]

        w = 0
        t = 0
        for d in range(m):
            w1 = self.w_cache[d]
            s = 1 << d
            s2 = s << 1
            for i in range(0, n, s2):
                w = 1
                for j in range(s):
                    a = i + j
                    b = a + s
                    t = self.modular.mul(w, p[b])
                    p[b] = self.modular.plus(p[a], -t)
                    p[a] = self.modular.plus(p[a], t)
                    w = self.modular.mul(w, w1)

    def idft(self, p, m):
        self.dft(p, m)

        n = 1 << m
        inv_n = self.inv_cache[m]

        p[0] = self.modular.mul(p[0], inv_n)
        p[n // 2] = self.modular.mul(p[n // 2], inv_n)
        for i in range(1, n // 2):
            a = p[n - i]
            p[n - i] = self.modular.mul(p[i], inv_n)
            p[i] = self.modular.mul(a, inv_n)

    def id1(self, lists, ans):
        pqs = []
        for lst in lists:
            clone = lst[:]
            pqs.append(clone)
        while len(pqs) > 1:
            a = pqs.pop(0)
            b = pqs.pop(0)
            self.id10(a, b)
            pqs.append(a)

        last = pqs.pop(0)
        ans[:] = last[:]


    def id10(self, a, b):
        rank_ans = len(a) - 1 + len(b) - 1
        proper = (rank_ans + 1).bit_length()
        a.extend([0] * (1 << proper))
        b.extend([0] * (1 << proper))
        self.dft(a, proper)
        self.dft(b, proper)
        self.dot_mul(a, b, a, proper)
        self.idft(a, proper)
        Polynomials.normalize(a)


class PrimitiveRoot:
    def __init__(self, mod):
        self.mod = mod
        self.pow = Power(mod)
        self.factors = self.find_factors(mod - 1)

    def find_factors(self, n):
        factors = []
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                factors.append(i)
                while n % i == 0:
                    n //= i
        if n > 1:
            factors.append(n)
        return factors

    def find_primitive_root(self):
        for i in range(2, self.mod):
            flag = True
            for f in self.factors:
                if self.pow.pow(i, (self.mod - 1) // f) == 1:
                    flag = False
                    break
            if flag:
                return i
        return -1


class TaskG:
    def __init__(self):
        self.mod = Modular(998244353)

    def solve(self, test_number, in_stream, out_stream):
        n = in_stream.readInt()
        k = in_stream.readInt()
        allow = [0] * 10
        for i in range(k):
            allow[in_stream.readInt()] = 1
        p = allow[:]

        m = n // 2
        last = p[:]
        ntt = id9(self.mod, 3)

        lists = []
        while m > 1:
            if m % 2 == 1:
                lists.append(last[:])
            proper = (2 * len(last)).bit_length()
            last.extend([0] * (1 << proper))
            ntt.dft(last, proper)
            ntt.dot_mul(last, last, last, proper)
            ntt.idft(last, proper)
            Polynomials.normalize(last)
            m //= 2
        lists.append(last)

        prod = [0] * len(last)
        ntt.id1(lists, prod)

        ans = 0
        for i in range(len(prod)):
            plus = prod[i]
            ans = self.mod.plus(ans, self.mod.mul(plus, plus))

        out_stream.println(ans)
