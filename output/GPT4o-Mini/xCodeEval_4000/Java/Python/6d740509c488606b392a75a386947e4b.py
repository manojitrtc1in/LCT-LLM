import sys
import random
from collections import deque
from typing import List, Dict, Callable

class Modular:
    def __init__(self, m: int):
        self.m = m

    def get_mod(self) -> int:
        return self.m

    def value_of(self, x: int) -> int:
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x: int, y: int) -> int:
        return self.value_of(x * y)

    def plus(self, x: int, y: int) -> int:
        return self.value_of(x + y)

class FastInput:
    def __init__(self, stream):
        self.stream = stream
        self.buf = bytearray(1 << 13)
        self.buf_len = 0
        self.buf_offset = 0
        self.next_char = None

    def read(self) -> int:
        if self.buf_offset == self.buf_len:
            self.buf_offset = 0
            self.buf_len = self.stream.readinto(self.buf)
            if self.buf_len == 0:
                return -1
        char = self.buf[self.buf_offset]
        self.buf_offset += 1
        return char

    def skip_blank(self):
        while self.next_char is not None and self.next_char <= 32:
            self.next_char = self.read()

    def read_int(self) -> int:
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

class IntList:
    def __init__(self, cap: int = 0):
        self.size = 0
        self.cap = cap
        self.data = [0] * cap if cap > 0 else []

    def ensure_space(self, req: int):
        if req > self.cap:
            while self.cap < req:
                self.cap = max(self.cap + 10, 2 * self.cap)
            self.data.extend([0] * (self.cap - len(self.data)))

    def add_all(self, x: List[int]):
        self.add_all_range(x, 0, len(x))

    def add_all_range(self, x: List[int], offset: int, length: int):
        self.ensure_space(self.size + length)
        self.data[self.size:self.size + length] = x[offset:offset + length]
        self.size += length

    def expand_with(self, x: int, length: int):
        self.ensure_space(length)
        while self.size < length:
            self.data.append(x)
            self.size += 1

    def retain(self, n: int):
        if n < 0:
            raise ValueError("n must be non-negative")
        if n >= self.size:
            return
        self.size = n

    def to_array(self) -> List[int]:
        return self.data[:self.size]

    def clear(self):
        self.size = 0

class TaskG:
    def __init__(self):
        self.mod = Modular(998244353)

    def solve(self, test_number: int, in_stream: FastInput, out_stream):
        n = in_stream.read_int()
        k = in_stream.read_int()
        allow = [0] * 10
        for _ in range(k):
            allow[in_stream.read_int()] = 1
        p = IntList()
        p.add_all(allow)

        m = n // 2
        last = p
        ntt = NumberTheoryTransform(self.mod, 3)

        lists = []
        while m > 1:
            if m % 2 == 1:
                lists.append(last)
            proper = CachedLog2.ceil_log(2 * len(last.data))
            last.expand_with(0, 1 << proper)
            NTT.ntt(last.data, 1 << proper, False, self.mod.get_mod(), 3)
            ntt.dot_mul(last.data, last.data, last.data, proper)
            NTT.ntt(last.data, 1 << proper, True, self.mod.get_mod(), 3)
            Polynomials.normalize(last)
            m //= 2
        lists.append(last)

        prod = IntList()
        ntt.mul_by_pq(lists, prod)

        ans = 0
        for i in range(prod.size):
            plus = prod.data[i]
            ans = self.mod.plus(ans, self.mod.mul(plus, plus))

        out_stream.println(ans)

class NumberTheoryTransform:
    def __init__(self, mod: Modular, g: int):
        self.modular = mod
        self.power = Power(mod)
        self.g = g
        self.w_cache = [0] * 30
        self.inv_cache = [0] * 30
        for i in range(len(self.w_cache)):
            s = 1 << i
            self.w_cache[i] = self.power.pow(self.g, (self.modular.get_mod() - 1) // (2 * s))
            self.inv_cache[i] = self.power.inverse(s)

    def dot_mul(self, a: List[int], b: List[int], c: List[int], m: int):
        for i in range(1 << m):
            c[i] = self.modular.mul(a[i], b[i])

    def prepare_reverse(self, r: List[int], b: int):
        n = 1 << b
        r[0] = 0
        for i in range(1, n):
            r[i] = (r[i >> 1] >> 1) | ((1 & i) << (b - 1))

    def dft(self, p: List[int], m: int):
        n = 1 << m
        rev = IntList()
        rev.expand_with(0, 1 << m)
        r = rev.data
        self.prepare_reverse(r, m)

        for i in range(n):
            if r[i] > i:
                p[i], p[r[i]] = p[r[i]], p[i]

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

    def mul_by_pq(self, lists: List[IntList], ans: IntList):
        pqs = sorted(lists, key=lambda x: x.size)
        while len(pqs) > 1:
            a = pqs.pop(0)
            b = pqs.pop(0)
            self.multiply_and_store_answer_into_a(a, b)
            pqs.append(a)

        last = pqs.pop()
        ans.clear()
        ans.add_all(last.data)
        return

    def multiply_and_store_answer_into_a(self, a: IntList, b: IntList):
        rank_ans = a.size - 1 + b.size - 1
        proper = CachedLog2.ceil_log(rank_ans + 1)
        a.expand_with(0, 1 << proper)
        b.expand_with(0, 1 << proper)
        self.dft(a.data, proper)
        self.dft(b.data, proper)
        self.dot_mul(a.data, b.data, a.data, proper)
        self.idft(a.data, proper)
        Polynomials.normalize(a)

class NTT:
    @staticmethod
    def pow(x: int, n: int, mod: int) -> int:
        res = 1
        for p in range(n):
            res = (res * x) % mod
        return res

    @staticmethod
    def ntt(a: List[int], n: int, invert: bool, mod: int, root: int):
        shift = 32 - (n).bit_length()
        for i in range(1, n):
            j = int('{:0{width}b}'.format(i, width=shift)[::-1], 2)
            if i < j:
                a[i], a[j] = a[j], a[i]

        root_inv = NTT.pow(root, mod - 2, mod)

        for length in range(1, n, length << 1):
            wlen = NTT.pow(root_inv if invert else root, (mod - 1) // (2 * length), mod)
            for i in range(0, n, 2 * length):
                w = 1
                for j in range(length):
                    u = a[i + j]
                    v = (a[i + j + length] * w) % mod
                    a[i + j] = (u + v) % mod
                    a[i + j + length] = (u - v + mod) % mod
                    w = (w * wlen) % mod
        if invert:
            nrev = NTT.pow(n, mod - 2, mod)
            for i in range(n):
                a[i] = (a[i] * nrev) % mod

class CachedLog2:
    LIMIT = 1 << 16
    CACHE = [0] * LIMIT

    @staticmethod
    def ceil_log(x: int) -> int:
        ans = CachedLog2.floor_log(x)
        if (1 << ans) < x:
            ans += 1
        return ans

    @staticmethod
    def floor_log(x: int) -> int:
        return CachedLog2.CACHE[x] if x < CachedLog2.LIMIT else (16 + CachedLog2.CACHE[x >> 16])

class Polynomials:
    @staticmethod
    def rank_of(p: IntList) -> int:
        r = p.size - 1
        while r >= 0 and p.data[r] == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def normalize(list: IntList):
        list.retain(Polynomials.rank_of(list) + 1)

class Main:
    @staticmethod
    def main():
        input_stream = FastInput(sys.stdin.buffer)
        output_stream = FastOutput(sys.stdout.buffer)
        task = TaskG()
        task.solve(1, input_stream, output_stream)
        output_stream.flush()

if __name__ == "__main__":
    Main.main()
