import sys
import math

class Modular:
    def __init__(self, m):
        self.m = m

    def value_of(self, x):
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x, y):
        return self.value_of(x * y)

    def plus(self, x, y):
        return self.value_of(x + y)

    def get_modular_for_power_computation(self):
        return Modular(self.m - 1)

class FastInput:
    def __init__(self, stream):
        self.stream = stream
        self.buf = bytearray(1 << 13)
        self.buf_len = 0
        self.buf_offset = 0
        self.next = -1

    def read(self):
        if self.buf_offset == self.buf_len:
            self.buf_offset = 0
            self.buf_len = self.stream.readinto(self.buf)
            if self.buf_len == 0:
                return -1
        return self.buf[self.buf_offset]

    def skip_blank(self):
        while self.next >= 0 and self.next <= 32:
            self.next = self.read()

    def read_int(self):
        sign = 1
        self.skip_blank()
        if self.next == ord('+') or self.next == ord('-'):
            sign = 1 if self.next == ord('+') else -1
            self.next = self.read()

        val = 0
        if sign == 1:
            while ord('0') <= self.next <= ord('9'):
                val = val * 10 + self.next - ord('0')
                self.next = self.read()
        else:
            while ord('0') <= self.next <= ord('9'):
                val = val * 10 - self.next + ord('0')
                self.next = self.read()

        return val

class FastOutput:
    def __init__(self, stream):
        self.cache = []
        self.stream = stream

    def println(self, c):
        self.cache.append(f"{c}\n")

    def flush(self):
        self.stream.write(''.join(self.cache))
        self.cache.clear()

    def close(self):
        self.flush()
        self.stream.close()

class FCards:
    def __init__(self):
        self.mod = Modular(998244353)
        self.comp = Composite(5000, self.mod)
        self.power = Power(self.mod)

    def solve(self, test_number, in_stream, out_stream):
        in_ = FastInput(in_stream)
        out_ = FastOutput(out_stream)

        n = in_.read_int()
        m = in_.read_int()
        k = in_.read_int()

        pm = CachedPow(m, self.mod)
        xk = [self.power.pow(i, k) for i in range(k + 1)]

        ans = 0
        bc = BinomialComposite(n, k, self.mod, True)
        for t in range(k + 1):
            p1 = bc.get(t)
            p2 = 0
            for i in range(t + 1):
                contrib = self.comp.composite(t, i)
                contrib = self.mod.mul(contrib, xk[t - i])
                if i % 2 == 1:
                    contrib = self.mod.value_of(-contrib)
                p2 = self.mod.plus(p2, contrib)
            p3 = pm.inverse(t)

            contrib = self.mod.mul(p1, p2)
            contrib = self.mod.mul(contrib, p3)
            ans = self.mod.plus(ans, contrib)

        out_.println(ans)

class Composite:
    def __init__(self, limit, modular):
        self.factorial = Factorial(limit, modular)
        self.modular = modular

    def composite(self, m, n):
        if n > m:
            return 0
        return self.modular.mul(self.modular.mul(self.factorial.fact(m), self.factorial.inv_fact(n)), self.factorial.inv_fact(m - n))

class Factorial:
    def __init__(self, limit, modular):
        self.modular = modular
        self.fact = [0] * (limit + 1)
        self.inv = [0] * (limit + 1)
        self.fact[0] = self.inv[0] = 1
        for i in range(1, limit + 1):
            self.fact[i] = modular.mul(self.fact[i - 1], i)
            self.inv[i] = modular.mul(self.inv[i - 1], pow(i, modular.m - 2, modular.m))

    def fact(self, n):
        return self.fact[n]

    def inv_fact(self, n):
        return self.inv[n]

class Power:
    def __init__(self, modular):
        self.modular = modular

    def pow(self, x, n):
        if n == 0:
            return self.modular.value_of(1)
        r = self.pow(x, n >> 1)
        r = self.modular.value_of(r * r)
        if (n & 1) == 1:
            r = self.modular.value_of(r * x)
        return r

class CachedPow:
    def __init__(self, x, modular):
        self.mod = modular
        self.pow_mod = modular.get_modular_for_power_computation()
        k = max(1, int(math.sqrt(x)))
        self.first = [0] * k
        self.second = [0] * (x // k + 1)
        self.first[0] = 1
        for i in range(1, k):
            self.first[i] = modular.mul(x, self.first[i - 1])
        self.second[0] = 1
        step = modular.mul(x, self.first[k - 1])
        for i in range(1, len(self.second)):
            self.second[i] = modular.mul(self.second[i - 1], step)

    def pow(self, exp):
        return self.mod.mul(self.first[exp % len(self.first)], self.second[exp // len(self.first)])

    def inverse(self, exp):
        return self.pow(self.pow_mod.value_of(-exp))

class BinomialComposite:
    def __init__(self, n, m, modular, fft):
        self.m = m
        self.mod = modular
        self.n = n
        self.fft = fft
        self.composites = self.pow(n)
        self.composites.expand_with(0, m + 1)

    def get(self, i):
        return self.composites.get(i)

    def mul(self, a, b, c):
        if not self.fft:
            Polynomials.mul(a, b, c, self.mod)
        else:
            ans = FastFourierTransform.multiply_mod(a.get_data(), a.size(), b.get_data(), b.size(), self.mod.get_mod())
            c.clear()
            c.add_all(ans)
        self.trim(c)

    def trim(self, x):
        if x.size() > self.m + 1:
            x.remove(self.m + 1, x.size() - 1)

    def mul(self, p, ans):
        ans.clear()
        ans.expand_with(0, p.size() + 1)

        n = p.size()
        for i in range(n):
            val = p.get(i)
            ans.set(i, self.mod.plus(ans.get(i), val))
            ans.set(i + 1, val)

        self.trim(ans)

    def pow(self, exp):
        ceil = CachedLog2.ceil_log(self.m + 1 + self.m)
        loop = Loop(IntegerList(1 << ceil), IntegerList(1 << ceil))
        loop.get().add(1)
        for i in range(CachedLog2.floor_log(exp), -1, -1):
            self.mul(loop.get(), loop.get(), loop.turn())
            if Bits.bit_at(exp, i) == 1:
                self.mul(loop.get(), loop.turn())
        return loop.get()

class Loop:
    def __init__(self, *data):
        self.data = data
        self.pos = 0

    def turn(self, i=1):
        self.pos += i
        return self.get(0)

    def get(self, i):
        return self.data[(self.pos + i) % len(self.data)]

class Bits:
    @staticmethod
    def bit_at(x, i):
        return (x >> i) & 1

class Polynomials:
    @staticmethod
    def rank_of(p):
        data = p.get_data()
        r = p.size() - 1
        while r >= 0 and data[r] == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def mul(a, b, c, mod):
        rA = Polynomials.rank_of(a)
        rB = Polynomials.rank_of(b)
        c.clear()
        c.expand_with(0, rA + rB + 1)
        a_data = a.get_data()
        b_data = b.get_data()
        c_data = c.get_data()
        for i in range(rA + 1):
            for j in range(rB + 1):
                c_data[i + j] = mod.plus(c_data[i + j], mod.mul(a_data[i], b_data[j]))

class FastFourierTransform:
    @staticmethod
    def multiply_mod(a, a_len, b, b_len, m):
        need = a_len + b_len - 1
        n = 1 << CachedLog2.ceil_log(need)

        a_real = [0] * n
        a_imag = [0] * n
        for i in range(a_len):
            x = (a[i] % m + m) % m
            a_real[i] = x & ((1 << 15) - 1)
            a_imag[i] = x >> 15
        FastFourierTransform.dft([a_real, a_imag], CachedLog2.floor_log(n))

        b_real = [0] * n
        b_imag = [0] * n
        for i in range(b_len):
            x = (b[i] % m + m) % m
            b_real[i] = x & ((1 << 15) - 1)
            b_imag[i] = x >> 15
        FastFourierTransform.dft([b_real, b_imag], CachedLog2.floor_log(n))

        fa_real = [0] * n
        fa_imag = [0] * n
        fb_real = [0] * n
        fb_imag = [0] * n

        for i in range(n):
            j = (n - i) & (n - 1)

            a1r = (a_real[i] + a_real[j]) / 2
            a1i = (a_imag[i] - a_imag[j]) / 2
            a2r = (a_imag[i] + a_imag[j]) / 2
            a2i = (a_real[j] - a_real[i]) / 2

            b1r = (b_real[i] + b_real[j]) / 2
            b1i = (b_imag[i] - b_imag[j]) / 2
            b2r = (b_imag[i] + b_imag[j]) / 2
            b2i = (b_real[j] - b_real[i]) / 2

            fa_real[i] = a1r * b1r - a1i * b1i - a2r * b2i - a2i * b2r
            fa_imag[i] = a1r * b1i + a1i * b1r + a2r * b2r - a2i * b2i

            fb_real[i] = a1r * b2r - a1i * b2i + a2r * b1r - a2i * b1i
            fb_imag[i] = a1r * b2i + a1i * b2r + a2r * b1i + a2i * b1r

        FastFourierTransform.idft([fa_real, fa_imag], CachedLog2.floor_log(n))
        res = [0] * need
        for i in range(need):
            aa = round(fa_real[i])
            bb = round(fb_real[i])
            cc = round(fa_imag[i])
            res[i] = (aa % m + (bb % m << 15) + (cc % m << 30)) % m
        return res

    @staticmethod
    def dft(p, m):
        n = 1 << m
        shift = 32 - (n).bit_length()
        for i in range(1, n):
            j = int('{:0{width}b}'.format(i, width=shift)[::-1], 2)
            if i < j:
                p[0][i], p[0][j] = p[0][j], p[0][i]
                p[1][i], p[1][j] = p[1][j], p[1][i]

        for d in range(m):
            s = 1 << d
            s2 = s << 1
            for i in range(0, n, s2):
                for j in range(s):
                    a = i + j
                    b = a + s
                    t = [0, 0]
                    FastFourierTransform.mul(p[0][b], p[1][b], t)
                    FastFourierTransform.sub(p[0][a], p[1][a], t[0], t[1], p, b)
                    FastFourierTransform.add(p[0][a], p[1][a], t[0], t[1], p, a)

    @staticmethod
    def idft(p, m):
        FastFourierTransform.dft(p, m)
        n = 1 << m
        FastFourierTransform.div(p[0][0], p[1][0], n, p, 0)
        FastFourierTransform.div(p[0][n // 2], p[1][n // 2], n, p, n // 2)
        for i in range(1, n // 2):
            a = p[0][n - i]
            b = p[1][n - i]
            FastFourierTransform.div(p[0][i], p[1][i], n, p, n - i)
            FastFourierTransform.div(a, b, n, p, i)

    @staticmethod
    def add(r1, i1, r2, i2, r, i):
        r[0][i] = r1 + r2
        r[1][i] = i1 + i2

    @staticmethod
    def sub(r1, i1, r2, i2, r, i):
        r[0][i] = r1 - r2
        r[1][i] = i1 - i2

    @staticmethod
    def mul(r1, i1, r2, i2, r, i):
        r[0][i] = r1 * r2 - i1 * i2
        r[1][i] = r1 * i2 + i1 * r2

    @staticmethod
    def div(r1, i1, r2, r, i):
        r[0][i] = r1 / r2
        r[1][i] = i1 / r2

class CachedLog2:
    LIMIT = 1 << 16
    CACHE = [0] * LIMIT

    @staticmethod
    def ceil_log(x):
        ans = CachedLog2.floor_log(x)
        if (1 << ans) < x:
            ans += 1
        return ans

    @staticmethod
    def floor_log(x):
        if x < CachedLog2.LIMIT:
            return CachedLog2.CACHE[x]
        b = 0
        while (1 << (b + 1)) <= x:
            b += 1
        return b

def main():
    thread = Thread(target=TaskAdapter)
    thread.start()
    thread.join()

class TaskAdapter:
    def run(self):
        in_stream = sys.stdin
        out_stream = sys.stdout
        solver = FCards()
        solver.solve(1, in_stream, out_stream)

if __name__ == "__main__":
    main()
