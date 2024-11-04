import sys
from typing import List, Tuple

MOD = 998244353
ROOT = pow(3, 7*17, MOD)
ROOT_INV = pow(ROOT, MOD - 2, MOD)
ORDER = 1 << 23
W4 = pow(ROOT, (MOD - 1) // 4, MOD)
ID15 = pow(ROOT, (MOD - 1) // 4 * 3, MOD)
YES = "YES"
NO = "NO"


class MyScanner:
    def __init__(self, input_stream=sys.stdin):
        self.input_stream = input_stream
        self.buffer = ""
        self.pos = 0

    def close(self):
        if self.input_stream != sys.stdin:
            self.input_stream.close()

    def next(self) -> str:
        while self.pos >= len(self.buffer):
            self.buffer = self.input_stream.readline().strip()
            self.pos = 0
        self.pos += 1
        return self.buffer[self.pos - 1]

    def next_int(self) -> int:
        return int(self.next())

    def next_long(self) -> int:
        return int(self.next())

    def next_double(self) -> float:
        return float(self.next())

    def next_line(self) -> str:
        return self.input_stream.readline().strip()

    def read_int_list(self, n: int) -> List[int]:
        return [self.next_int() for _ in range(n)]

    def read_long_list(self, n: int) -> List[int]:
        return [self.next_long() for _ in range(n)]

    def read_int_matrix(self, n: int, m: int) -> List[List[int]]:
        return [self.read_int_list(m) for _ in range(n)]

    def read_pairs(self, n: int) -> Tuple[List[int], List[int]]:
        x = self.read_int_list(n)
        y = self.read_int_list(n)
        return x, y


class id5:
    def __init__(self, output_stream=sys.stdout):
        self.output_stream = output_stream

    def close(self):
        if self.output_stream != sys.stdout:
            self.output_stream.close()

    def println(self, *args, **kwargs):
        print(*args, **kwargs, file=self.output_stream)

    def print(self, *args, **kwargs):
        print(*args, **kwargs, file=self.output_stream, end="")

    def println_ans(self, ans):
        self.println(ans)

    def print_ans(self, arr):
        if arr:
            self.print(arr[0])
            for i in range(1, len(arr)):
                self.print(" ")
                self.print(arr[i])

    def println_ans(self, arr):
        self.print_ans(arr)
        self.println()

    def print_ans(self, arr, add):
        if arr:
            self.print(arr[0] + add)
            for i in range(1, len(arr)):
                self.print(" ")
                self.print(arr[i] + add)

    def println_ans(self, arr, add):
        self.print_ans(arr, add)
        self.println()


def fft(a: List[int], id0: bool) -> None:
    n = len(a)

    def swap(i: int, j: int) -> None:
        a[i], a[j] = a[j], a[i]

    def fft_helper(id0: bool) -> None:
        for i in range(1, n):
            j = 0
            bit = n >> 1
            while j & bit:
                j ^= bit
                bit >>= 1
            j ^= bit

            if i < j:
                swap(i, j)

        len = 2
        while len <= n:
            wlen = ROOT_INV if id0 else ROOT
            for i in range(len, ORDER):
                wlen = wlen * wlen % MOD

            for i in range(0, n, len):
                w = 1
                for j in range(len // 2):
                    u = a[i + j]
                    v = a[i + j + len // 2] * w % MOD
                    a[i + j] = (u + v) % MOD if u + v < MOD else u + v - MOD
                    a[i + j + len // 2] = (u - v) % MOD if u - v >= 0 else u - v + MOD
                    w = w * wlen % MOD

            len <<= 1

        if id0:
            inv = pow(n, MOD - 2, MOD)
            for i in range(n):
                a[i] = a[i] * inv % MOD

    fft_helper(id0)


def fft4(a: List[int], id0: bool) -> None:
    n = len(a)

    def swap(i: int, j: int) -> None:
        a[i], a[j] = a[j], a[i]

    def fft_helper(id0: bool) -> None:
        parity = 0
        len = 2
        while len <= n:
            parity += 1
            len <<= 1

        if parity % 2 == 1:
            len = 2
            if len <= n:
                wlen = ROOT_INV if id0 else ROOT
                for i in range(len, ORDER):
                    wlen = wlen * wlen % MOD

                for i in range(0, n, len):
                    w = 1
                    for j in range(len // 2):
                        x0 = a[i + j]
                        x1 = a[i + j + len // 2] * w % MOD
                        x2 = a[i + j + len // 4] * w % MOD
                        x2 = x2 * w % MOD
                        x3 = a[i + j + len * 3 // 4] * w % MOD
                        x3 = x3 * w % MOD
                        x3 = x3 * w % MOD

                        y0 = (x0 + x1 + x2 + x3) % MOD
                        a[i + j] = y0
                        y1 = (x0 + x1 * W4 - x2 - x3 * W4) % MOD
                        a[i + j + len * 3 // 4] = y1 if y1 >= 0 else y1 + MOD
                        y2 = (x0 - x1 + x2 - x3) % MOD
                        a[i + j + len // 2] = y2 if y2 >= 0 else y2 + MOD
                        y3 = (x0 - x1 * W4 - x2 + x3 * W4) % MOD
                        a[i + j + len // 4] = y3 if y3 >= 0 else y3 + MOD

                        w = w * wlen % MOD

                len *= 4
        else:
            len = 4
            wlen = ROOT_INV if id0 else ROOT
            w4 = ID15 if id0 else W4
            for i in range(len, ORDER):
                wlen = wlen * wlen % MOD

            for i in range(0, n, len):
                w = 1
                for j in range(len // 4):
                    x0 = a[i + j]
                    x1 = a[i + j + len // 2] * w % MOD
                    x2 = a[i + j + len // 4] * w % MOD
                    x2 = x2 * w % MOD
                    x3 = a[i + j + len * 3 // 4] * w % MOD
                    x3 = x3 * w % MOD
                    x3 = x3 * w % MOD

                    y0 = (x0 + x1 + x2 + x3) % MOD
                    a[i + j] = y0
                    y1 = (x0 + x1 * w4 - x2 - x3 * w4) % MOD
                    a[i + j + len * 3 // 4] = y1 if y1 >= 0 else y1 + MOD
                    y2 = (x0 - x1 + x2 - x3) % MOD
                    a[i + j + len // 2] = y2 if y2 >= 0 else y2 + MOD
                    y3 = (x0 - x1 * w4 - x2 + x3 * w4) % MOD
                    a[i + j + len // 4] = y3 if y3 >= 0 else y3 + MOD

                    w = w * wlen % MOD

        if id0:
            inv = pow(n, MOD - 2, MOD)
            for i in range(n):
                a[i] = a[i] * inv % MOD

    fft_helper(id0)


def square(a: List[int]) -> None:
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

    for _ in range(n):
        if _ < n - 1:
            square(ways)
            suffix[f + 1] = sum(ways[f + 1:]) % MOD
            for j in range(f, -1, -1):
                suffix[j] = (suffix[j + 1] + ways[j]) % MOD

            for j in range(k + 1):
                val = suffix[j]
                val += ways[j] * (k - j)
                val %= MOD
                ways[j] = val

            ways[f + 1] = suffix[f + 1] * max(0, k - f) % MOD
            for j in range(k + 1, f + 2):
                ways[j] = 0
            ways[f + 2:] = [0] * (len(ways) - f - 2)
        else:
            for j in range(f + 1):
                ans += ways[j] * ways[f - j] % MOD
            ans %= MOD

    return ans


def main() -> None:
    in_stream = open("input.txt", "r") if "ONLINE_JUDGE" not in sys.argv else sys.stdin
    out_stream = open("output.txt", "w") if "ONLINE_JUDGE" not in sys.argv else sys.stdout
    scanner = MyScanner(in_stream)
    printer = id5(out_stream)

    t = 1
    for _ in range(t):
        n, k, f = scanner.next_int(), scanner.next_int(), scanner.next_int()
        ans = solve(n, k, f)
        printer.println_ans(ans)

    scanner.close()
    printer.close()


if __name__ == "__main__":
    main()
