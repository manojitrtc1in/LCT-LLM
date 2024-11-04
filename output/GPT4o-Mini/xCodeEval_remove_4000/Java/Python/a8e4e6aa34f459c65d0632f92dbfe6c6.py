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

    def id2(self):
        return Modular(self.m - 1)

class FastInput:
    def __init__(self, stream):
        self.stream = stream
        self.buf = bytearray(1 << 13)
        self.buf_len = 0
        self.buf_offset = 0
        self.next = -1

    def read(self):
        while self.buf_len == self.buf_offset:
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
        n = in_stream.read_int()
        m = in_stream.read_int()
        k = in_stream.read_int()

        pm = CachedPow(m, self.mod)
        xk = [self.power.pow(i, k) for i in range(k + 1)]

        ans = 0
        bc = id1(n, k, self.mod, True)
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

        out_stream.println(ans)

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
            self.inv[i] = modular.mul(self.inv[i - 1], InverseNumber(limit, modular).inv[i])

    def fact(self, n):
        return self.fact[n]

    def inv_fact(self, n):
        return self.inv[n]

class InverseNumber:
    def __init__(self, limit, modular):
        self.inv = [0] * (limit + 1)
        self.inv[1] = 1
        p = modular.m
        for i in range(2, limit + 1):
            k = p // i
            r = p % i
            self.inv[i] = modular.mul(-k, self.inv[r])

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

class id1:
    def __init__(self, n, m, mod, fft):
        self.m = m
        self.mod = mod
        self.n = n
        self.fft = fft
        self.id8 = self.pow(n)
        self.id8.expand_with(0, m + 1)

    def get(self, i):
        return self.id8.get(i)

    def mul(self, a, b, c):
        if not self.fft:
            Polynomials.mul(a, b, c, self.mod)
        else:
            ans = id10.multiply_mod(a.get_data(), a.size(), b.get_data(), b.size(), self.mod.m)
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
        ceil = id11.ceil_log(self.m + 1 + self.m)
        loop = Loop(IntegerList(1 << ceil), IntegerList(1 << ceil))
        loop.get().add(1)
        for i in range(id11.floor_log(exp), -1, -1):
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

class id10:
    @staticmethod
    def multiply_mod(a, a_len, b, b_len, m):
        need = a_len + b_len - 1
        n = 1 << id11.ceil_log(need)

        a_real = [0] * n
        a_imag = [0] * n
        for i in range(a_len):
            x = (a[i] % m + m) % m
            a_real[i] = x & ((1 << 15) - 1)
            a_imag[i] = x >> 15
        dft([a_real, a_imag], id11.floor_log(n))

        b_real = [0] * n
        b_imag = [0] * n
        for i in range(b_len):
            x = (b[i] % m + m) % m
            b_real[i] = x & ((1 << 15) - 1)
            b_imag[i] = x >> 15
        dft([b_real, b_imag], id11.floor_log(n))

        fa_real = [0] * n
        fa_imag = [0] * n
        fb_real = [0] * n
        fb_imag = [0] * n

        for i in range(n):
            j = (n - i) & (n - 1)

            id6 = (a_real[i] + a_real[j]) / 2
            id5 = (a_imag[i] - a_imag[j]) / 2
            id4 = (a_imag[i] + a_imag[j]) / 2
            id12 = (a_real[j] - a_real[i]) / 2

            id0 = (b_real[i] + b_real[j]) / 2
            id7 = (b_imag[i] - b_imag[j]) / 2
            id13 = (b_imag[i] + b_imag[j]) / 2
            id9 = (b_real[j] - b_real[i]) / 2

            fa_real[i] = id6 * id0 - id5 * id7 - id4 * id9 - id12 * id13
            fa_imag[i] = id6 * id7 + id5 * id0 + id4 * id13 - id12 * id9

            fb_real[i] = id6 * id13 - id5 * id9 + id4 * id0 - id12 * id7
            fb_imag[i] = id6 * id9 + id5 * id13 + id4 * id7 + id12 * id0

        idft([fa_real, fa_imag], id11.floor_log(n))
        idft([fb_real, fb_imag], id11.floor_log(n))
        res = [0] * need
        for i in range(need):
            aa = round(fa_real[i])
            bb = round(fb_real[i])
            cc = round(fa_imag[i])
            res[i] = (aa % m + (bb % m << 15) + (cc % m << 30)) % m
        return res

class id11:
    BITS = 16
    LIMIT = 1 << BITS
    CACHE = bytearray(LIMIT)

    @staticmethod
    def ceil_log(x):
        ans = id11.floor_log(x)
        if (1 << ans) < x:
            ans += 1
        return ans

    @staticmethod
    def floor_log(x):
        if x < id11.LIMIT:
            return id11.CACHE[x]
        b = 0
        while (1 << (b + 1)) <= x:
            b += 1
        return b

def main():
    input_stream = FastInput(sys.stdin.buffer)
    output_stream = FastOutput(sys.stdout.buffer)
    thread = FCards()
    thread.solve(1, input_stream, output_stream)
    output_stream.close()

if __name__ == "__main__":
    main()
