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


class Factorial:
    def __init__(self, limit, modular):
        self.modular = modular
        self.fact = [0] * (limit + 1)
        self.inv = [0] * (limit + 1)
        self.fact[0] = self.inv[0] = 1
        for i in range(1, limit + 1):
            self.fact[i] = self.modular.mul(self.fact[i - 1], i)
            self.inv[i] = self.modular.mul(self.inv[i - 1], self.inverse(i))

    def inverse(self, x):
        p = self.modular.get_mod()
        k = p // x
        r = p % x
        return self.modular.mul(-k, self.inv[r])

    def fact(self, n):
        return self.fact[n]

    def inv_fact(self, n):
        return self.inv[n]


class Composite:
    def __init__(self, limit, modular):
        self.factorial = Factorial(limit, modular)
        self.modular = modular

    def composite(self, m, n):
        if n > m:
            return 0
        return self.modular.mul(self.modular.mul(self.factorial.fact(m), self.factorial.inv_fact(n)), self.factorial.inv_fact(m - n))


class FCards:
    def __init__(self):
        self.mod = Modular(998244353)
        self.comp = Composite(5000, self.mod)
        self.power = Power(self.mod)

    def solve(self, test_number, in_stream, out_stream):
        n = int(in_stream.readline())
        m = int(in_stream.readline())
        k = int(in_stream.readline())

        pm = CachedPow(m, self.mod)
        xk = [0] * (k + 1)
        for i in range(k + 1):
            xk[i] = self.power.pow(i, k)

        ans = 0
        bc = BinomialComposite(n, k, self.mod)
        for t in range(k + 1):
            p1 = bc.get(t)
            p2 = 0
            for i in range(t + 1):
                contrib = self.comp.composite(t, i)
                contrib = self.mod.mul(contrib, xk[t - i])
                if i % 2 == 1:
                    contrib = self.mod.valueOf(-contrib)
                p2 = self.mod.plus(p2, contrib)
            p3 = pm.inverse(t)

            contrib = self.mod.mul(p1, p2)
            contrib = self.mod.mul(contrib, p3)
            ans = self.mod.plus(ans, contrib)

        out_stream.write(str(ans) + '\n')


class FastInput:
    def __init__(self, is_stream):
        self.is_stream = is_stream
        self.buffer = b''
        self.buffer_len = 0
        self.buffer_offset = 0
        self.next = self.read()

    def read(self):
        while self.buffer_len == self.buffer_offset:
            self.buffer_offset = 0
            try:
                self.buffer = self.is_stream.read(1 << 13)
            except:
                self.buffer = b''
            self.buffer_len = len(self.buffer)
            if self.buffer_len == 0:
                return -1
        c = self.buffer[self.buffer_offset]
        self.buffer_offset += 1
        return c

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
            while self.next >= ord('0') and self.next <= ord('9'):
                val = val * 10 + self.next - ord('0')
                self.next = self.read()
        else:
            while self.next >= ord('0') and self.next <= ord('9'):
                val = val * 10 - self.next + ord('0')
                self.next = self.read()

        return val


def main():
    in_stream = FastInput(sys.stdin.buffer)
    out_stream = sys.stdout

    n = int(in_stream.readline())
    m = int(in_stream.readline())
    k = int(in_stream.readline())

    fc = FCards()
    fc.solve(1, in_stream, out_stream)


if __name__ == '__main__':
    main()
