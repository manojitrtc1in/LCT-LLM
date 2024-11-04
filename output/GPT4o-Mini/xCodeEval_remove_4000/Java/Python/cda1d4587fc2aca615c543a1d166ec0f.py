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

    def id3(self):
        return Modular(self.m - 1)

class FastInput:
    def __init__(self, stream):
        self.stream = stream
        self.buf = bytearray(1 << 13)
        self.buf_len = 0
        self.buf_offset = 0
        self.next = 0

    def read(self):
        if self.buf_offset == self.buf_len:
            self.buf_offset = 0
            self.buf_len = self.stream.readinto(self.buf)
            if self.buf_len == 0:
                return -1
        result = self.buf[self.buf_offset]
        self.buf_offset += 1
        return result

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
            while 48 <= self.next <= 57:
                val = val * 10 + self.next - 48
                self.next = self.read()
        else:
            while 48 <= self.next <= 57:
                val = val * 10 - self.next + 48
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
        bc = id1(n, k, self.mod)
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

class CachedPow:
    def __init__(self, x, mod):
        self.mod = mod
        self.pow_mod = mod.id3()
        k = max(1, int(math.sqrt(x)))
        self.first = [1] * k
        self.second = [1] * (x // k + 1)
        for i in range(1, k):
            self.first[i] = mod.mul(x, self.first[i - 1])
        step = mod.mul(x, self.first[k - 1])
        for i in range(1, len(self.second)):
            self.second[i] = mod.mul(self.second[i - 1], step)

    def pow(self, exp):
        return self.mod.mul(self.first[exp % len(self.first)], self.second[exp // len(self.first)])

    def inverse(self, exp):
        return self.pow(self.pow_mod.value_of(-exp))

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

class id1:
    def __init__(self, n, m, mod):
        self.m = m
        self.mod = mod
        self.id8 = self.pow(n)
        self.id8.expand_with(0, m + 1)

    def get(self, i):
        return self.id8.get(i)

    def pow(self, exp):
        ceil = id11.ceil_log(self.m + 1 + self.m)
        loop = Loop(IntegerList(1 << ceil), IntegerList(1 << ceil))
        loop.get().add(1)
        for i in range(id11.floor_log(exp), -1, -1):
            self.mul(loop.get(), loop.get())
            if Bits.bit_at(exp, i) == 1:
                self.mul(loop.get(), loop.turn())
        return loop.get()

    def mul(self, a, b):
        Polynomials.mul(a, b, self.id8, self.mod)
        self.trim(self.id8)

    def trim(self, x):
        if x.size() > self.m + 1:
            x.remove(self.m + 1, x.size() - 1)

class IntegerList:
    def __init__(self, cap=0):
        self.size = 0
        self.cap = cap
        self.data = [0] * cap if cap > 0 else []

    def get_data(self):
        return self.data

    def remove(self, l, r):
        if l > r:
            return
        self.check_range(l)
        self.check_range(r)
        if r == self.size - 1:
            self.size = l
        else:
            self.data[l:self.size - (r + 1)] = self.data[r + 1:self.size]
            self.size -= (r - l + 1)

    def check_range(self, i):
        if i < 0 or i >= self.size:
            raise IndexError(f"index {i} out of range")

    def get(self, i):
        self.check_range(i)
        return self.data[i]

    def add(self, x):
        self.ensure_space(self.size + 1)
        self.data[self.size] = x
        self.size += 1

    def ensure_space(self, req):
        if req > self.cap:
            while self.cap < req:
                self.cap = max(self.cap + 10, 2 * self.cap)
            self.data = self.data + [0] * (self.cap - len(self.data))

    def size(self):
        return self.size

    def clear(self):
        self.size = 0

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

class Loop:
    def __init__(self, *data):
        self.data = data
        self.pos = 0

    def turn(self, i=1):
        self.pos += i
        return self.get(0)

    def get(self, i):
        return self.data[(self.pos + i) % len(self.data)]

class Polynomials:
    @staticmethod
    def rank_of(p):
        r = p.size() - 1
        while r >= 0 and p.get_data()[r] == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def mul(a, b, c, mod):
        rA = Polynomials.rank_of(a)
        rB = Polynomials.rank_of(b)
        c.clear()
        c.expand_with(0, rA + rB + 1)
        if rA >= 64 and rB >= 64:
            ans = id10.multiply_mod(a.get_data(), rA + 1, b.get_data(), rB + 1, mod.get_mod())
            c.clear()
            c.add_all(ans)
            return
        a_data = a.get_data()
        b_data = b.get_data()
        c_data = c.get_data()
        for i in range(rA + 1):
            for j in range(rB + 1):
                c_data[i + j] = mod.plus(c_data[i + j], mod.mul(a_data[i], b_data[j]))

class Bits:
    @staticmethod
    def bit_at(x, i):
        return (x >> i) & 1

class id11:
    @staticmethod
    def ceil_log(x):
        ans = id11.floor_log(x)
        if (1 << ans) < x:
            ans += 1
        return ans

    @staticmethod
    def floor_log(x):
        return x.bit_length() - 1

class InverseNumber:
    def __init__(self, limit, modular):
        self.inv = [0] * (limit + 1)
        self.inv[1] = 1
        p = modular.get_mod()
        for i in range(2, limit + 1):
            k = p // i
            r = p % i
            self.inv[i] = modular.mul(-k, self.inv[r])

def main():
    input_stream = FastInput(sys.stdin.buffer)
    output_stream = FastOutput(sys.stdout.buffer)
    thread = FCards()
    thread.solve(1, input_stream, output_stream)
    output_stream.close()

if __name__ == "__main__":
    main()
