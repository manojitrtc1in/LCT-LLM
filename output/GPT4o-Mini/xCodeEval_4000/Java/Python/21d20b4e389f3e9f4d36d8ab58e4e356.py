import sys
import random

IMPOSSIBLE = "IMPOSSIBLE"
POSSIBLE = "POSSIBLE"
YES = "YES"
NO = "NO"
MOD = 998244353

class MyScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def next(self):
        return next(self.input_stream)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.input_stream.readline().strip()

class MyPrintWriter:
    def __init__(self, output_stream):
        self.output_stream = output_stream

    def println(self, ans):
        self.output_stream.write(f"{ans}\n")

    def print_ans(self, arr):
        if arr:
            self.output_stream.write(" ".join(map(str, arr)) + "\n")

class RoundEdu132F:
    def __init__(self):
        self.out = MyPrintWriter(sys.stdout)
        self.in_ = MyScanner(sys.stdin)

    def run(self):
        is_debug = False
        is_file_io = False
        has_multiple_tests = False

        t = 1 if not has_multiple_tests else self.in_.next_int()

        for i in range(1, t + 1):
            if is_debug:
                self.out.println(f"Test {i}")

            self.get_input()
            ans = self.solve()
            self.print_output(ans)

    def get_input(self):
        self.n = self.in_.next_int()
        self.k = self.in_.next_int()
        self.f = self.in_.next_int()

    def print_output(self, ans):
        self.out.println(ans)

    def solve(self):
        ans = 0
        len_ = 1
        while len_ < self.f + 2 + self.f + 2:
            len_ <<= 1
        ways = [0] * len_
        suffix = [0] * (self.f + 2)

        for i in range(min(self.k, self.f) + 1):
            ways[i] = 1
        ways[self.f + 1] = max(0, self.k - self.f)

        for i in range(self.n):
            if i < self.n - 1:
                self.square(ways)
                val = sum(ways[j] for j in range(len(ways) - 1, self.f, -1)) % MOD
                suffix[self.f + 1] = val

                for j in range(self.f, -1, -1):
                    val = (suffix[j + 1] + ways[j]) % MOD
                    suffix[j] = val

                for j in range(min(self.k, self.f) + 1):
                    val = (suffix[j] + ways[j] * (self.k - j)) % MOD
                    ways[j] = val

                ways[self.f + 1] = (suffix[self.f + 1] * max(0, self.k - self.f)) % MOD
                for j in range(self.k + 1, self.f + 2):
                    ways[j] = 0
                ways[self.f + 2:] = [0] * (len(ways) - (self.f + 2))

            else:
                for j in range(self.f + 1):
                    ans = (ans + ways[j] * ways[self.f - j]) % MOD

        return ans

    @staticmethod
    def pow(a, k, p):
        m = k
        ans = 1
        curr = a

        while m > 0:
            if m & 1:
                ans = (ans * curr) % p
            m >>= 1
            curr = (curr * curr) % p
        return ans

    @staticmethod
    def inverse(a, p):
        return RoundEdu132F.pow(a, p - 2, p)

    @staticmethod
    def swap(a, i, j):
        a[i], a[j] = a[j], a[i]

    @staticmethod
    def fft(a, is_inverted_fft):
        n = len(a)
        j = 0
        for i in range(1, n):
            bit = n >> 1
            while j & bit:
                j ^= bit
                bit >>= 1
            j ^= bit
            if i < j:
                RoundEdu132F.swap(a, i, j)

        for len_ in range(2, n + 1, len_):
            wlen = RoundEdu132F.ROOT_INV if is_inverted_fft else RoundEdu132F.ROOT
            for i in range(len_, RoundEdu132F.ORDER, len_):
                wlen = (wlen * wlen) % MOD

            for i in range(0, n, len_):
                w = 1
                for j in range(len_ // 2):
                    u = a[i + j]
                    v = (a[i + j + len_ // 2] * w) % MOD
                    a[i + j] = (u + v) % MOD
                    a[i + j + len_ // 2] = (u - v + MOD) % MOD
                    w = (w * wlen) % MOD

        if is_inverted_fft:
            inv = RoundEdu132F.inverse(n, MOD)
            for i in range(len(a)):
                a[i] = (a[i] * inv) % MOD

    @staticmethod
    def square(a):
        RoundEdu132F.fft(a, False)
        for i in range(len(a)):
            a[i] = (a[i] * a[i]) % MOD
        RoundEdu132F.fft(a, True)

    @staticmethod
    def multiply_polynomial(a, b):
        n = 1
        while n < len(a) + len(b):
            n <<= 1
        fa = a + [0] * (n - len(a))
        fb = b + [0] * (n - len(b))

        RoundEdu132F.fft(fa, False)
        RoundEdu132F.fft(fb, False)
        for i in range(n):
            fa[i] = (fa[i] * fb[i]) % MOD
        RoundEdu132F.fft(fa, True)

        return fa

if __name__ == "__main__":
    sol = RoundEdu132F()
    sol.run()
