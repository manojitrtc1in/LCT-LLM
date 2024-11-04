import sys
import math
from collections import deque

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
        self.buffer = bytearray(1 << 13)
        self.buf_len = 0
        self.buf_offset = 0
        self.next_char = None

    def read(self):
        if self.buf_offset == self.buf_len:
            self.buf_offset = 0
            self.buf_len = self.stream.readinto(self.buffer)
            if self.buf_len == 0:
                return -1
        char = self.buffer[self.buf_offset]
        self.buf_offset += 1
        return char

    def skip_blank(self):
        while self.next_char is not None and self.next_char <= 32:
            self.next_char = self.read()

    def read_int(self):
        sign = 1
        self.skip_blank()
        if self.next_char == ord('+') or self.next_char == ord('-'):
            sign = 1 if self.next_char == ord('+') else -1
            self.next_char = self.read()

        val = 0
        if sign == 1:
            while self.next_char >= ord('0') and self.next_char <= ord('9'):
                val = val * 10 + self.next_char - ord('0')
                self.next_char = self.read()
        else:
            while self.next_char >= ord('0') and self.next_char <= ord('9'):
                val = val * 10 - self.next_char + ord('0')
                self.next_char = self.read()

        return val

class FastOutput:
    def __init__(self, stream):
        self.cache = []
        self.stream = stream

    def println(self, c):
        self.cache.append(str(c) + '\n')

    def flush(self):
        self.stream.write(''.join(self.cache))
        self.cache.clear()

    def close(self):
        self.flush()
        self.stream.close()

class FCards:
    def __init__(self):
        self.mod = Modular(998244353)
        self.power = Power(self.mod)

    def solve(self, test_number, in_stream, out_stream):
        n = in_stream.read_int()
        m = in_stream.read_int()
        k = in_stream.read_int()

        pm = CachedPow(m, self.mod)
        xk = [self.power.pow(i, k) for i in range(k + 1)]

        ans = 0
        bc = BinomialComposite(n, k, self.mod)
        for t in range(k + 1):
            p1 = bc.get(t)
            p2 = 0
            for i in range(t + 1):
                contrib = self.composite(t, i)
                contrib = self.mod.mul(contrib, xk[t - i])
                if i % 2 == 1:
                    contrib = self.mod.value_of(-contrib)
                p2 = self.mod.plus(p2, contrib)
            p3 = pm.inverse(t)

            contrib = self.mod.mul(p1, p2)
            contrib = self.mod.mul(contrib, p3)
            ans = self.mod.plus(ans, contrib)

        out_stream.println(ans)

    def composite(self, m, n):
        if n > m:
            return 0
        return self.mod.mul(self.factorial.fact(m), self.factorial.inv_fact(n))

class CachedPow:
    def __init__(self, x, mod):
        self.mod = mod
        self.pow_mod = mod.get_modular_for_power_computation()
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

class BinomialComposite:
    def __init__(self, n, m, mod):
        self.m = m
        self.mod = mod
        self.composites = self.pow(n)
        self.composites.expand_with(0, m + 1)

    def get(self, i):
        return self.composites.get(i)

    def pow(self, exp):
        ceil = CachedLog2.ceil_log(self.m + 1 + self.m)
        loop = Loop(IntegerList(1 << ceil), IntegerList(1 << ceil))
        loop.get().add(1)
        for i in range(CachedLog2.floor_log(exp), -1, -1):
            self.mul(loop.get(), loop.get(), loop.turn())
            if Bits.bit_at(exp, i) == 1:
                self.mul(loop.get(), loop.turn())
        return loop.get()

class IntegerList:
    def __init__(self, cap=0):
        self.size = 0
        self.cap = cap
        self.data = [0] * cap if cap > 0 else []

    def ensure_space(self, req):
        if req > self.cap:
            while self.cap < req:
                self.cap = max(self.cap + 10, 2 * self.cap)
            self.data = self.data + [0] * (self.cap - len(self.data))

    def get(self, i):
        self.check_range(i)
        return self.data[i]

    def add(self, x):
        self.ensure_space(self.size + 1)
        self.data[self.size] = x
        self.size += 1

    def expand_with(self, x, length):
        self.ensure_space(length)
        while self.size < length:
            self.data[self.size] = x
            self.size += 1

    def check_range(self, i):
        if i < 0 or i >= self.size:
            raise IndexError("index out of range")

    def clear(self):
        self.size = 0

class CachedLog2:
    LIMIT = 1 << 16
    CACHE = [0] * LIMIT

    @staticmethod
    def init():
        b = 0
        for i in range(CachedLog2.LIMIT):
            while (1 << (b + 1)) <= i:
                b += 1
            CachedLog2.CACHE[i] = b

    @staticmethod
    def ceil_log(x):
        ans = CachedLog2.floor_log(x)
        if (1 << ans) < x:
            ans += 1
        return ans

    @staticmethod
    def floor_log(x):
        return CachedLog2.CACHE[x] if x < CachedLog2.LIMIT else 16 + CachedLog2.CACHE[x >> 16]

class Bits:
    @staticmethod
    def bit_at(x, i):
        return (x >> i) & 1

class Loop:
    def __init__(self, *data):
        self.data = data
        self.pos = 0

    def turn(self):
        self.pos += 1
        return self.get(0)

    def get(self, i):
        return self.data[(self.pos + i) % len(self.data)]

class Main:
    @staticmethod
    def main():
        input_stream = FastInput(sys.stdin.buffer)
        output_stream = FastOutput(sys.stdout.buffer)
        thread = FCards()
        thread.solve(1, input_stream, output_stream)
        output_stream.close()

if __name__ == "__main__":
    CachedLog2.init()
    Main.main()
