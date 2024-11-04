import sys
from typing import List, Tuple

MOD = 998244353


class FastInput:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = []
        self.buffer_pos = 0

    def read(self) -> int:
        if self.buffer_pos >= len(self.buffer):
            self.buffer = self.input_stream.readline().split()
            self.buffer_pos = 0
        self.buffer_pos += 1
        return int(self.buffer[self.buffer_pos - 1])

    def read_int(self) -> int:
        return self.read()


class FastOutput:
    def __init__(self, output_stream):
        self.output_stream = output_stream

    def println(self, value):
        self.output_stream.write(str(value) + "\n")

    def flush(self):
        self.output_stream.flush()


class Modular:
    def __init__(self, m: int):
        self.m = m

    def value_of(self, x: int) -> int:
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x: int, y: int) -> int:
        return self.value_of(x * y)

    def plus(self, x: int, y: int) -> int:
        return self.value_of(x + y)


class Power:
    def __init__(self, modular: Modular):
        self.modular = modular

    def pow(self, x: int, n: int) -> int:
        if n == 0:
            return self.modular.value_of(1)
        r = self.pow(x, n >> 1)
        r = self.modular.value_of(r * r)
        if n & 1:
            r = self.modular.value_of(r * x)
        return r

    def inverse(self, x: int) -> int:
        return self.pow(x, self.modular.m - 2)


class NumberTheoryTransform:
    def __init__(self, modular: Modular, g: int):
        self.modular = modular
        self.power = Power(modular)
        self.g = g
        self.w_cache = [0] * 30
        self.inv_cache = [0] * 30
        for i in range(30):
            s = 1 << i
            self.w_cache[i] = self.power.pow(self.g, (self.modular.m - 1) // 2 // s)
            self.inv_cache[i] = self.power.inverse(s)

    def dot_mul(self, a: List[int], b: List[int], c: List[int], m: int):
        for i in range(1 << m):
            c[i] = self.modular.mul(a[i], b[i])

    def dft(self, p: List[int], m: int):
        n = 1 << m

        shift = 32 - p.bit_length()
        for i in range(1, n):
            j = int(bin(i << shift).replace("0b", "").zfill(32)[::-1], 2)
            if i < j:
                p[i], p[j] = p[j], p[i]

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

    def idft(self, p: List[int], m: int):
        self.dft(p, m)

        n = 1 << m
        inv_n = self.inv_cache[m]

        p[0] = self.modular.mul(p[0], inv_n)
        p[n // 2] = self.modular.mul(p[n // 2], inv_n)
        for i in range(1, n // 2):
            a = p[n - i]
            p[n - i] = self.modular.mul(p[i], inv_n)
            p[i] = self.modular.mul(a, inv_n)

    def mul_by_pq(self, lists: List[List[int]]) -> List[int]:
        pqs = []
        for lst in lists:
            pqs.append(lst[:])

        while len(pqs) > 1:
            a = pqs.pop(0)
            b = pqs.pop(0)
            self.multiply_and_store_answer_into_a(a, b)
            pqs.append(a)

        return pqs[0]

    def pow2(self, a: List[int]):
        rank_ans = (len(a) - 1) * 2
        proper = (rank_ans + 1).bit_length()
        a.extend([0] * (1 << proper))
        self.dft(a, proper)
        self.dot_mul(a, a, a, proper)
        self.idft(a, proper)
        normalize(a)

    def multiply_and_store_answer_into_a(self, a: List[int], b: List[int]):
        rank_ans = len(a) - 1 + len(b) - 1
        proper = (rank_ans + 1).bit_length()
        a.extend([0] * (1 << proper))
        b.extend([0] * (1 << proper))
        self.dft(a, proper)
        self.dft(b, proper)
        self.dot_mul(a, b, a, proper)
        self.idft(a, proper)
        normalize(a)


def normalize(lst: List[int]):
    while lst and lst[-1] == 0:
        lst.pop()


def solve(n: int, k: int, allow: List[int]) -> int:
    mod = Modular(MOD)
    p = allow[:]

    m = n // 2
    last = p[:]
    ntt = NumberTheoryTransform(mod, 3)
    lists = []
    while m > 1:
        if m % 2 == 1:
            lists.append(last[:])
        ntt.pow2(last)
        normalize(last)
        m //= 2
    lists.append(last)

    prod = ntt.mul_by_pq(lists)

    ans = 0
    for i in range(len(prod)):
        plus = prod[i]
        ans = mod.plus(ans, mod.mul(plus, plus))

    return ans


def main():
    input_stream = sys.stdin.buffer
    output_stream = sys.stdout.buffer
    fast_input = FastInput(input_stream)
    fast_output = FastOutput(output_stream)

    n, k = fast_input.read_int(), fast_input.read_int()
    allow = [0] * 10
    for _ in range(k):
        allow[fast_input.read_int()] = 1

    ans = solve(n, k, allow)
    fast_output.println(ans)
    fast_output.flush()


if __name__ == '__main__':
    main()
