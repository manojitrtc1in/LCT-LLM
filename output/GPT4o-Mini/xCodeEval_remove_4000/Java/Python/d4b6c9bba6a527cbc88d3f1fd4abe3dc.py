import sys
import random

MOD = 998244353
YES = "YES"
NO = "NO"

class MyScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = []
    
    def next(self):
        while not self.buffer:
            self.buffer = self.input_stream.readline().split()
        return self.buffer.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def close(self):
        self.input_stream.close()

class Id5:
    def __init__(self, output_stream):
        self.output_stream = output_stream

    def println_ans(self, ans):
        self.output_stream.write(f"{ans}\n")

    def print_ans(self, arr):
        if arr:
            self.output_stream.write(" ".join(map(str, arr)) + "\n")

class Id4:
    def __init__(self):
        self.out = Id5(sys.stdout)
        self.in_stream = MyScanner(sys.stdin)
        self.n = self.k = self.f = 0
        self.ans = 0

    def init_io(self, id8):
        if "ONLINE_JUDGE" not in sys.modules and id8:
            try:
                self.in_stream = MyScanner(open("input.txt"))
                self.out = Id5(open("output.txt", "w"))
            except FileNotFoundError as e:
                print(e)

    def run(self):
        is_debug = False
        id8 = True
        id2 = False

        self.init_io(id8)

        t = self.in_stream.next_int() if id2 else 1

        for i in range(1, t + 1):
            if is_debug:
                self.out.println_ans(f"Test {i}")

            self.get_input()
            self.ans = self.solve()
            self.print_output()

        self.in_stream.close()
        self.out.output_stream.close()

    def get_input(self):
        self.n = self.in_stream.next_int()
        self.k = self.in_stream.next_int()
        self.f = self.in_stream.next_int()

    def print_output(self):
        self.out.println_ans(self.ans)

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
        ans = 1
        curr = a
        while k > 0:
            if k & 1:
                ans = (ans * curr) % p
            k >>= 1
            curr = (curr * curr) % p
        return ans

    @staticmethod
    def inverse(a, p):
        return Id4.pow(a, p - 2, p)

    @staticmethod
    def swap(a, i, j):
        a[i], a[j] = a[j], a[i]

    @staticmethod
    def fft(a, id0):
        n = len(a)
        for i in range(1, n):
            j = 0
            bit = n >> 1
            while j & bit:
                j ^= bit
                bit >>= 1
            j ^= bit
            if i < j:
                Id4.swap(a, i, j)

        for len_ in range(2, n + 1, len_ << 1):
            wlen = Id4.ROOT_INV if id0 else Id4.ROOT
            for i in range(len_, Id4.ORDER, i << 1):
                wlen = (wlen * wlen) % MOD

            for i in range(0, n, len_):
                w = 1
                for j in range(len_ // 2):
                    u = a[i + j]
                    v = (a[i + j + len_ // 2] * w) % MOD
                    a[i + j] = (u + v) % MOD
                    a[i + j + len_ // 2] = (u - v) % MOD
                    w = (w * wlen) % MOD

        if id0:
            inv = Id4.inverse(n, MOD)
            for i in range(len(a)):
                a[i] = (a[i] * inv) % MOD

    @staticmethod
    def square(a):
        Id4.fft(a, False)
        for i in range(len(a)):
            a[i] = (a[i] * a[i]) % MOD
        Id4.fft(a, True)

    @staticmethod
    def multiply_polynomial(a, b):
        n = 1
        while n < len(a) + len(b):
            n <<= 1
        fa = a + [0] * (n - len(a))
        fb = b + [0] * (n - len(b))

        Id4.fft(fa, False)
        Id4.fft(fb, False)
        for i in range(n):
            fa[i] = (fa[i] * fb[i]) % MOD
        Id4.fft(fa, True)

        return fa

    ROOT = pow(3, 7 * 17, MOD)
    ROOT_INV = pow(ROOT, MOD - 2, MOD)
    ORDER = 1 << 23

if __name__ == "__main__":
    Id4().run()
