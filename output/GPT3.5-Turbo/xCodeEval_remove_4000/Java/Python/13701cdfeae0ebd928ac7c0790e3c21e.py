import sys
from typing import List, Dict, Any, Tuple
from io import IOBase, BytesIO

def main():
    n, k = map(int, input().split())
    allow = [0] * 10
    for i in map(int, input().split()):
        allow[i] = 1
    p = allow[:]

    m = n // 2
    last = p[:]
    mod = Modular(998244353)
    ntt = id8(mod, 3)
    lists = []
    while m > 1:
        if m % 2 == 1:
            lists.append(last[:])
        ntt.pow2(last)
        Polynomials.normalize(last)
        m //= 2
    lists.append(last)

    prod = []
    ntt.id1(lists, prod)

    ans = 0
    for i in range(len(prod)):
        plus = prod[i]
        ans = mod.plus(ans, mod.mul(plus, plus))

    print(ans)

class Modular:
    def __init__(self, m: int):
        self.m = m

    def valueOf(self, x: int) -> int:
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x: int, y: int) -> int:
        return self.valueOf(x * y)

    def plus(self, x: int, y: int) -> int:
        return self.valueOf(x + y)

class id8:
    def __init__(self, mod: Modular, g: int):
        self.modular = mod
        self.power = Power(mod)
        self.g = g
        self.wCache = [0] * 30
        self.invCache = [0] * 30
        for i in range(len(self.wCache)):
            s = 1 << i
            self.wCache[i] = self.power.pow(self.g, (self.modular.m - 1) // 2 // s)
            self.invCache[i] = self.power.inverse(s)

    def dotMul(self, a: List[int], b: List[int], c: List[int], m: int):
        for i in range(1 << m):
            c[i] = self.modular.mul(a[i], b[i])

    def dft(self, p: List[int], m: int):
        n = 1 << m

        shift = 32 - p.bit_length()
        for i in range(1, n):
            j = int(bin(i << shift)[:1:-1], 2)
            if i < j:
                p[i], p[j] = p[j], p[i]

        w = 0
        t = 0
        for d in range(m):
            w1 = self.wCache[d]
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
        invN = self.invCache[m]

        p[0] = self.modular.mul(p[0], invN)
        p[n // 2] = self.modular.mul(p[n // 2], invN)
        for i in range(1, n // 2):
            a = p[n - i]
            p[n - i] = self.modular.mul(p[i], invN)
            p[i] = self.modular.mul(a, invN)

    def id1(self, lists: List[List[int]], ans: List[int]):
        pqs = []
        for l in lists:
            pqs.append(l[:])
        while len(pqs) > 1:
            a = pqs.pop(0)
            b = pqs.pop(0)
            self.id9(a, b)
            pqs.append(a)

        last = pqs.pop()
        ans.clear()
        ans.extend(last)

    def pow2(self, a: List[int]):
        rankAns = (len(a) - 1) * 2
        proper = (rankAns + 1).bit_length()
        a.extend([0] * (1 << proper))
        self.dft(a, proper)
        self.dotMul(a, a, a, proper)
        self.idft(a, proper)
        Polynomials.normalize(a)

    def id9(self, a: List[int], b: List[int]):
        rankAns = len(a) - 1 + len(b) - 1
        proper = (rankAns + 1).bit_length()
        a.extend([0] * (1 << proper))
        b.extend([0] * (1 << proper))
        self.dft(a, proper)
        self.dft(b, proper)
        self.dotMul(a, b, a, proper)
        self.idft(a, proper)
        Polynomials.normalize(a)

class Polynomials:
    @staticmethod
    def rankOf(p: List[int]) -> int:
        r = len(p) - 1
        while r >= 0 and p[r] == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def normalize(p: List[int]):
        p[:] = p[:Polynomials.rankOf(p) + 1]

class Power:
    def __init__(self, modular: Modular):
        self.modular = modular

    def pow(self, x: int, n: int) -> int:
        if n == 0:
            return self.modular.valueOf(1)
        r = self.pow(x, n >> 1)
        r = self.modular.valueOf(r * r)
        if n & 1:
            r = self.modular.valueOf(r * x)
        return r

    def inverse(self, x: int) -> int:
        return self.pow(x, self.modular.m - 2)

class FastInput:
    def __init__(self, file: IOBase):
        self.file = file
        self.buffer = BytesIO()
        self.bufLen = 0
        self.bufOffset = 0
        self.next = 0

    def read(self):
        while self.bufLen == self.bufOffset:
            self.bufOffset = 0
            self.bufLen = self.file.readinto(self.buffer)
            if self.bufLen == 0:
                return -1
        self.next = self.buffer[self.bufOffset]
        self.bufOffset += 1
        return self.next

    def skipBlank(self):
        while self.next >= 0 and self.next <= 32:
            self.next = self.read()

    def readInt(self) -> int:
        sign = 1

        self.skipBlank()
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

class FastOutput:
    def __init__(self, file: IOBase):
        self.file = file
        self.buffer = BytesIO()

    def println(self, c: int):
        self.buffer.write(str(c).encode() + b'\n')

    def flush(self):
        self.file.write(self.buffer.getvalue())
        self.file.flush()
        self.buffer.seek(0)
        self.buffer.truncate(0)

sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')
main()
sys.stdin.close()
sys.stdout.close()
