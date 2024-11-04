import sys
from typing import List, Tuple, Dict, Any


class FastReader:
    def __init__(self):
        self.buffer = []
        self.buffer_size = 0
        self.pointer = 0

    def read(self) -> str:
        if self.pointer >= self.buffer_size:
            self.buffer = sys.stdin.readline().split()
            self.buffer_size = len(self.buffer)
            self.pointer = 0
        self.pointer += 1
        return self.buffer[self.pointer - 1]

    def read_int(self) -> int:
        return int(self.read())

    def read_long(self) -> int:
        return int(self.read())

    def read_double(self) -> float:
        return float(self.read())

    def read_char(self) -> str:
        return self.read()[0]

    def read_string(self) -> str:
        return self.read()

    def read_int_list(self, n: int) -> List[int]:
        return [self.read_int() for _ in range(n)]

    def read_double_list(self, n: int) -> List[float]:
        return [self.read_double() for _ in range(n)]

    def read_long_list(self, n: int) -> List[int]:
        return [self.read_long() for _ in range(n)]

    def read_int_grid(self, n: int, m: int) -> List[List[int]]:
        return [self.read_int_list(m) for _ in range(n)]


class CFPS:
    def __init__(self):
        self.fr = FastReader()
        self.out = sys.stdout
        self.id32 = 1000000007
        self.t = 1
        self.epsilon = 0.00000001
        self.isPrime = []
        self.id24 = []

    def main(self):
        self.isPrime = self.prime_generator(1000000)
        self.id24 = [0] * (1000000 + 1)

        for tc in range(self.t):
            n = self.fr.read_int()
            mod = self.fr.read_long()

            dp = [0] * (n + 1)
            dp[n] = 1

            for i in range(n - 1, 0, -1):
                dp[i] += dp[i + 1]
                dp[i] %= mod

                for div in range(1, (n // i) + 1):
                    lb = div * i
                    ub = min((div * (i + 1) - 1), n)
                    seg_sum = dp[lb]
                    if ub + 1 <= n:
                        seg_sum -= dp[ub + 1]
                    dp[i] += seg_sum
                    dp[i] %= mod

                dp[i] += dp[i + 1]
                dp[i] %= mod

            self.out.write(str((dp[1] - dp[2] + mod) % mod) + "\n")
        self.out.close()

    def prime_generator(self, upto: int) -> List[bool]:
        is_prime = [True] * (upto + 1)
        is_prime[0] = is_prime[1] = False

        for i in range(2, upto + 1):
            if is_prime[i]:
                for j in range(i * i, upto + 1, i):
                    is_prime[j] = False

        return is_prime


if __name__ == "__main__":
    cfps = CFPS()
    cfps.main()
