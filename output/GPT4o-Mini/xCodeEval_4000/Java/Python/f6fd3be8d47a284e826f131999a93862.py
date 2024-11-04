import sys
import random
from collections import defaultdict
from math import gcd

IMPOSSIBLE = "IMPOSSIBLE"
POSSIBLE = "POSSIBLE"
YES = "YES"
NO = "NO"
MOD = 1_000_000_007

class MyScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def next_int(self):
        return int(self.input_stream.readline().strip())

    def next_int_array(self, length):
        return list(map(int, self.input_stream.readline().strip().split()))[:length]

class MyPrintWriter:
    def __init__(self, output_stream):
        self.output_stream = output_stream

    def println(self, value):
        self.output_stream.write(str(value) + "\n")

    def print_ans(self, arr):
        if arr:
            self.output_stream.write(" ".join(map(str, arr)) + "\n")

class Round818E:
    def __init__(self):
        self.in_stream = sys.stdin
        self.out_stream = sys.stdout
        self.in_scanner = MyScanner(self.in_stream)
        self.out_writer = MyPrintWriter(self.out_stream)
        self.n = 0
        self.ans = 0
        self.check = []

    def get_input(self):
        self.n = self.in_scanner.next_int()

    def print_output(self):
        self.out_writer.println(self.ans)

    def solve(self):
        prime_factors = [[] for _ in range(self.n + 1)]
        for i in range(2, self.n + 1):
            if not prime_factors[i]:
                prime_factors[i].append(i)
                for j in range(i * i, self.n + 1, i):
                    if not prime_factors[j]:
                        prime_factors[j].append(i)
            else:
                prime = prime_factors[i][0]
                rest = i // prime
                while rest % prime == 0:
                    rest //= prime
                if rest > 1:
                    prime_factors[i].extend(prime_factors[rest])

        self.ans = 0
        self.check = [0] * (self.n + 1)
        for g in range(1, self.n + 1):
            if g * 2 + 1 > self.n:
                break
            cnt = 0
            sum_ = 0

            for ap in range(2, self.n + 1):
                if g * (ap + 1) + 1 > self.n:
                    break

                max_bp = min(ap - 1, (self.n - 1) // g - ap)
                curr_cnt = max_bp
                sum_ += max_bp * (max_bp + 1) // 2 % MOD

                k = len(prime_factors[ap])
                for mask in range(1, 1 << k):
                    curr = 1
                    sign = 1
                    for pos in range(k):
                        if (mask & (1 << pos)) > 0:
                            curr *= prime_factors[ap][pos]
                            sign *= -1

                    s = min((ap - 1) // curr, (self.n - 1 - g * ap) // curr // g)

                    curr_cnt += s * sign
                    sum_ += curr * s * (s + 1) // 2 * sign

                cnt += curr_cnt
                sum_ += curr_cnt * ap
                sum_ %= MOD

            cnt *= 2
            sum_ *= g * 2

            cnt += 1
            sum_ += g * 2

            cnt %= MOD
            sum_ %= MOD
            if sum_ < 0:
                sum_ += MOD

            self.check[g] -= self.ans
            k = gcd(g, self.n)
            self.ans += g * self.n // k * cnt % MOD
            self.ans -= g // k * sum_ % MOD
            self.check[g] += self.ans

        self.ans %= MOD
        if self.ans < 0:
            self.ans += MOD

    def run(self):
        t = 1
        for _ in range(t):
            self.get_input()
            self.solve()
            self.print_output()

if __name__ == "__main__":
    sol = Round818E()
    sol.run()
