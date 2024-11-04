import sys
import random
from collections import deque
from typing import List, Dict, Callable, TypeVar

T = TypeVar('T')

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
        self.next = 0

    def read(self) -> int:
        while self.buf_len == self.buf_offset:
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

    def read_int(self) -> int:
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

    def get(self, i: int) -> int:
        if i < 0 or i >= self.size:
            raise IndexError("Index out of bounds")
        return self.data[i]

    def add_all(self, x: List[int]):
        self.add_all_with_offset(x, 0, len(x))

    def add_all_with_offset(self, x: List[int], offset: int, length: int):
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
            raise ValueError("Negative size not allowed")
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
        last = IntList(p.size)
        last.add_all(p.to_array())

        ntt = NumberTheoryTransform(self.mod, 3)
        lists = []
        while m > 1:
            if m % 2 == 1:
                lists.append(IntList(last.size))
                lists[-1].add_all(last.to_array())
            ntt.pow2(last)
            last.retain(last.size)
            m //= 2
        lists.append(last)

        prod = IntList()
        ntt.mul_by_pq(lists, prod)

        ans = 0
        for i in range(prod.size):
            plus = prod.get(i)
            ans = self.mod.plus(ans, self.mod.mul(plus, plus))

        out_stream.write(f"{ans}\n")

class NumberTheoryTransform:
    def __init__(self, mod: Modular, g: int):
        self.modular = mod
        self.g = g
        self.w_cache = [0] * 30
        self.inv_cache = [0] * 30
        for i in range(len(self.w_cache)):
            s = 1 << i
            self.w_cache[i] = pow(self.g, (self.modular.get_mod() - 1) // (2 * s), self.modular.get_mod())
            self.inv_cache[i] = pow(s, self.modular.get_mod() - 2, self.modular.get_mod())

    def dot_mul(self, a: List[int], b: List[int], c: List[int], m: int):
        for i in range(1 << m):
            c[i] = self.modular.mul(a[i], b[i])

    def dft(self, p: List[int], m: int):
        n = 1 << m
        shift = 32 - (n - 1).bit_length()
        for i in range(1, n):
            j = int('{:0{width}b}'.format(i, width=shift)[::-1], 2)
            if i < j:
                p[i], p[j] = p[j], p[i]

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
        pqs = deque(sorted(lists, key=lambda x: x.size))
        while len(pqs) > 1:
            a = pqs.popleft()
            b = pqs.popleft()
            self.multiply_and_store_answer_into_a(a, b)
            pqs.append(a)

        last = pqs.popleft()
        ans.clear()
        ans.add_all(last.to_array())

    def pow2(self, a: IntList):
        rank_ans = (a.size - 1) * 2
        proper = (rank_ans + 1).bit_length()
        a.expand_with(0, (1 << proper))
        self.dft(a.to_array(), proper)
        self.dot_mul(a.to_array(), a.to_array(), a.to_array(), proper)
        self.idft(a.to_array(), proper)

    def multiply_and_store_answer_into_a(self, a: IntList, b: IntList):
        rank_ans = a.size - 1 + b.size - 1
        proper = (rank_ans + 1).bit_length()
        a.expand_with(0, (1 << proper))
        b.expand_with(0, (1 << proper))
        self.dft(a.to_array(), proper)
        self.dft(b.to_array(), proper)
        self.dot_mul(a.to_array(), b.to_array(), a.to_array(), proper)
        self.idft(a.to_array(), proper)

class Main:
    @staticmethod
    def main():
        input_stream = FastInput(sys.stdin.buffer)
        output_stream = sys.stdout
        task = TaskG()
        task.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    Main.main()
