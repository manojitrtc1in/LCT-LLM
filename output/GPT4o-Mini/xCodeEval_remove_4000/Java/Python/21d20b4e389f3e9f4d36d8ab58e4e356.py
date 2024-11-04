import sys
import random

class MyScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = []
    
    def next(self):
        if not self.buffer:
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

def init_io(id8):
    if "ONLINE_JUDGE" not in os.environ and id8:
        in_stream = MyScanner(open("input.txt"))
        out_stream = Id5(open("output.txt", "w"))
    else:
        in_stream = MyScanner(sys.stdin)
        out_stream = Id5(sys.stdout)
    return in_stream, out_stream

MOD = 998244353

class Id4:
    def __init__(self):
        self.in_stream, self.out_stream = init_io(True)
        self.n = self.k = self.f = 0
        self.ans = 0

    def get_input(self):
        self.n = self.in_stream.next_int()
        self.k = self.in_stream.next_int()
        self.f = self.in_stream.next_int()

    def print_output(self):
        self.out_stream.println_ans(self.ans)

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

    def square(self, a):
        self.fft(a, False)
        for i in range(len(a)):
            a[i] = a[i] * a[i] % MOD
        self.fft(a, True)

    def fft(self, a, invert):
        n = len(a)
        for i in range(1, n):
            j = 0
            for bit in range(n.bit_length() - 1):
                j |= ((i >> bit) & 1) << (n.bit_length() - 1 - bit)
            if i < j:
                a[i], a[j] = a[j], a[i]

        len_ = 2
        while len_ <= n:
            wlen = pow(3, (MOD - 1) // len_, MOD)
            if invert:
                wlen = pow(wlen, MOD - 2, MOD)
            for i in range(0, n, len_):
                w = 1
                for j in range(len_ // 2):
                    u = a[i + j]
                    v = a[i + j + len_ // 2] * w % MOD
                    a[i + j] = (u + v) % MOD
                    a[i + j + len_ // 2] = (u - v + MOD) % MOD
                    w = w * wlen % MOD
            len_ <<= 1

        if invert:
            inv = pow(n, MOD - 2, MOD)
            for i in range(n):
                a[i] = a[i] * inv % MOD

    def run(self):
        t = 1
        for i in range(1, t + 1):
            self.get_input()
            self.ans = self.solve()
            self.print_output()

if __name__ == "__main__":
    sol = Id4()
    sol.run()
