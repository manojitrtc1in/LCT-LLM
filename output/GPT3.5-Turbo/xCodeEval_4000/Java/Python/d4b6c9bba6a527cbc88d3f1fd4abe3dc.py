import sys
from typing import List
from collections import defaultdict


class MyScanner:
    def __init__(self, input_stream=sys.stdin):
        self.input_stream = input_stream
        self.buffer = []
        self.buffer_idx = 0

    def close(self):
        if self.input_stream != sys.stdin:
            self.input_stream.close()

    def next(self) -> str:
        if self.buffer_idx >= len(self.buffer):
            self.buffer = self.input_stream.readline().split()
            self.buffer_idx = 0
        self.buffer_idx += 1
        return self.buffer[self.buffer_idx - 1]

    def next_int(self) -> int:
        return int(self.next())

    def next_long(self) -> int:
        return int(self.next())

    def next_double(self) -> float:
        return float(self.next())

    def next_line(self) -> str:
        return self.input_stream.readline().strip()

    def next_tree_edges(self, n: int, offset: int = 0) -> List[List[int]]:
        edges = [[] for _ in range(n - 1)]
        for i in range(n - 1):
            u = self.next_int() + offset
            v = self.next_int() + offset
            edges[i] = [u, v]
        return edges

    def next_matrix(self, n: int, m: int, offset: int = 0) -> List[List[int]]:
        matrix = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                matrix[i][j] = self.next_int() + offset
        return matrix

    def next_pairs(self, n: int, offset: int = 0) -> List[List[int]]:
        pairs = [[0] * 2 for _ in range(n)]
        for i in range(n):
            pairs[i][0] = self.next_int() + offset
            pairs[i][1] = self.next_int() + offset
        return pairs

    def next_graph_edges(self, offset: int = 0) -> List[List[int]]:
        m = self.next_int()
        edges = [[] for _ in range(m)]
        for i in range(m):
            u = self.next_int() + offset
            v = self.next_int() + offset
            edges[i] = [u, v]
        return edges

    def next_int_array(self, length: int, offset: int = 0) -> List[int]:
        return [self.next_int() + offset for _ in range(length)]

    def next_long_array(self, length: int, offset: int = 0) -> List[int]:
        return [self.next_long() + offset for _ in range(length)]


class MyPrintWriter:
    def __init__(self, output_stream=sys.stdout):
        self.output_stream = output_stream

    def close(self):
        if self.output_stream != sys.stdout:
            self.output_stream.close()

    def print_ans(self, ans: int):
        self.output_stream.write(str(ans))

    def println_ans(self, ans: int):
        self.output_stream.write(str(ans) + "\n")

    def println_ans_split(self, arr: List[int], split: int):
        for i in range(0, len(arr), split):
            self.output_stream.write(" ".join(map(str, arr[i:i+split])) + "\n")


MOD = 998244353
ROOT = pow(3, 7 * 17, MOD)
ROOT_INV = pow(ROOT, MOD - 2, MOD)
ORDER = 1 << 23
W4 = pow(ROOT, (MOD - 1) // 4, MOD)
W4_INV = pow(ROOT, (MOD - 1) // 4 * 3, MOD)


def swap(a: List[int], i: int, j: int):
    a[i], a[j] = a[j], a[i]


def fft(a: List[int], is_inverted_fft: bool):
    n = len(a)

    for i in range(1, n):
        bit = n >> 1
        j = 0
        while j & bit:
            j ^= bit
            bit >>= 1
        j ^= bit

        if i < j:
            swap(a, i, j)

    for length in range(2, n + 1):
        wlen = ROOT_INV if is_inverted_fft else ROOT
        for i in range(length, ORDER):
            wlen = wlen * wlen % MOD

        for i in range(0, n, length):
            w = 1
            for j in range(length // 2):
                u = a[i + j]
                v = a[i + j + length // 2] * w % MOD
                a[i + j] = (u + v) % MOD
                a[i + j + length // 2] = (u - v) % MOD
                w = w * wlen % MOD

    if is_inverted_fft:
        inv = pow(n, MOD - 2, MOD)
        for i in range(n):
            a[i] = a[i] * inv % MOD


def fft4(a: List[int], is_inverted_fft: bool):
    n = len(a)

    for i in range(1, n):
        bit = n >> 1
        j = 0
        while j & bit:
            j ^= bit
            bit >>= 1
        j ^= bit

        if i < j:
            swap(a, i, j)

    parity = 0
    length = 2
    while length <= n:
        parity += 1
        length <<= 1

    if parity % 2 == 1:
        length = 2
        if length <= n:
            wlen = ROOT_INV if is_inverted_fft else ROOT
            for i in range(length, ORDER):
                wlen = wlen * wlen % MOD

            for i in range(0, n, length):
                w = 1
                for j in range(length // 2):
                    x0 = a[i + j]
                    x1 = a[i + j + length // 2] * w % MOD
                    x2 = a[i + j + length // 4] * w % MOD
                    x2 = x2 * w % MOD
                    x3 = a[i + j + length * 3 // 4] * w % MOD
                    x3 = x3 * w % MOD
                    x3 = x3 * w % MOD

                    y0 = (x0 + x1 + x2 + x3) % MOD
                    a[i + j] = y0
                    y1 = (x0 + x1 * W4 - x2 - x3 * W4) % MOD
                    a[i + j + length * 3 // 4] = y1 if y1 >= 0 else y1 + MOD
                    y2 = (x0 - x1 + x2 - x3) % MOD
                    a[i + j + length // 2] = y2 if y2 >= 0 else y2 + MOD
                    y3 = (x0 - x1 * W4 - x2 + x3 * W4) % MOD
                    a[i + j + length // 4] = y3 if y3 >= 0 else y3 + MOD

                    w = w * wlen % MOD
            length *= 4
    else:
        length = 4

    while length <= n:
        wlen = ROOT_INV if is_inverted_fft else ROOT
        w4 = W4_INV if is_inverted_fft else W4
        for i in range(length, ORDER):
            wlen = wlen * wlen % MOD

        for i in range(0, n, length):
            w = 1
            for j in range(length // 4):
                x0 = a[i + j]
                x1 = a[i + j + length // 2] * w % MOD
                x2 = a[i + j + length // 4] * w % MOD
                x2 = x2 * w % MOD
                x3 = a[i + j + length * 3 // 4] * w % MOD
                x3 = x3 * w % MOD
                x3 = x3 * w % MOD

                y0 = (x0 + x1 + x2 + x3) % MOD
                a[i + j] = y0
                y1 = (x0 + x1 * w4 - x2 - x3 * w4) % MOD
                a[i + j + length * 3 // 4] = y1 if y1 >= 0 else y1 + MOD
                y2 = (x0 - x1 + x2 - x3) % MOD
                a[i + j + length // 2] = y2 if y2 >= 0 else y2 + MOD
                y3 = (x0 - x1 * w4 - x2 + x3 * w4) % MOD
                a[i + j + length // 4] = y3 if y3 >= 0 else y3 + MOD

                w = w * wlen % MOD

    if is_inverted_fft:
        inv = pow(n, MOD - 2, MOD)
        for i in range(n):
            a[i] = a[i] * inv % MOD


def square(a: List[int]):
    fft4(a, False)
    for i in range(len(a)):
        a[i] = a[i] * a[i] % MOD
    fft4(a, True)


def multiply_polynomial(a: List[int], b: List[int]) -> List[int]:
    n = 1
    while n < len(a) + len(b):
        n <<= 1
    fa = a + [0] * (n - len(a))
    fb = b + [0] * (n - len(b))

    fft(fa, False)
    fft(fb, False)
    for i in range(n):
        fa[i] = fa[i] * fb[i] % MOD
    fft(fa, True)

    return fa


def solve(n: int, k: int, f: int) -> int:
    ans = 0

    ways = [0] * (f + 2 + f + 2)
    suffix = [0] * (f + 2)

    for i in range(k + 1):
        ways[i] = 1
    ways[f + 1] = max(0, k - f)

    for i in range(n):
        if i < n - 1:
            square(ways)

            val = sum(ways[f + 1:])
            suffix[f + 1] = val % MOD
            for j in range(f, -1, -1):
                val = (suffix[j + 1] + ways[j]) % MOD
                suffix[j] = val

            for j in range(k + 1):
                val = suffix[j]
                val += ways[j] * (k - j)
                val %= MOD
                ways[j] = val

            val = suffix[f + 1] * max(0, k - f)
            val %= MOD
            ways[f + 1] = val

            for j in range(k + 1, f + 2):
                ways[j] = 0
            ways[f + 2:] = [0] * (len(ways) - f - 2)
        else:
            for j in range(f + 1):
                ans += ways[j] * ways[f - j] % MOD
            ans %= MOD

    return ans


def main():
    in_file = open("input.txt", "r") if "ONLINE_JUDGE" not in sys.argv else sys.stdin
    out_file = open("output.txt", "w") if "ONLINE_JUDGE" not in sys.argv else sys.stdout
    scanner = MyScanner(in_file)
    printer = MyPrintWriter(out_file)

    t = scanner.next_int()

    for _ in range(t):
        n = scanner.next_int()
        k = scanner.next_int()
        f = scanner.next_int()

        ans = solve(n, k, f)

        printer.println_ans(ans)

    scanner.close()
    printer.close()


if __name__ == "__main__":
    main()
