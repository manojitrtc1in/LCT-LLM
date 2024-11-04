import sys
from typing import List, Tuple

MOD = 998244353

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
            self.w_cache[i] = self.power.pow(self.g, (self.modular.m - 1) // (2 * s))
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

    def multiply_and_store_answer_into_a(self, a: List[int], b: List[int]):
        rank_ans = len(a) - 1 + len(b) - 1
        proper = ceil_log(rank_ans + 1)
        a.extend([0] * (1 << proper))
        b.extend([0] * (1 << proper))
        self.dft(a, proper)
        self.dft(b, proper)
        self.dot_mul(a, b, a, proper)
        self.idft(a, proper)
        normalize(a)

def ceil_log(x: int) -> int:
    return 32 - x.bit_length()

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
        proper = ceil_log(2 * len(last))
        last.extend([0] * (1 << proper))
        ntt.dft(last, proper)
        ntt.dot_mul(last, last, last, proper)
        ntt.idft(last, proper)
        normalize(last)
        m //= 2
    lists.append(last)

    prod = []
    ntt.mul_by_pq(lists, prod)

    ans = 0
    for i in range(len(prod)):
        plus = prod[i]
        ans = mod.plus(ans, mod.mul(plus, plus))

    return ans

def from_input_string(input_string: str) -> Tuple[int, int, List[int]]:
    lines = input_string.strip().split('\n')
    n, k = map(int, lines[0].strip().split())
    allow = list(map(int, lines[1].strip().split()))
    return n, k, allow

def to_input_string(inputs: Tuple[int, int, List[int]]) -> str:
    n, k, allow = inputs
    res = []
    res.append(f"{n} {k}")
    res.append(' '.join(str(x) for x in allow))
    return '\n'.join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)
    
def main():
    input_str = sys.stdin.read()
    inputs = from_input_string(input_str)
    outputs = solve(*inputs)
    output_str = to_output_string(outputs)
    sys.stdout.write(output_str)

if __name__ == '__main__':
    main()
