import sys
from collections import defaultdict
from math import isqrt

class Task:
    def __init__(self):
        self.map = {}
        self.divides = defaultdict(list)
        self.dp = []
        self.idx = 0

    def solve(self, test_number, in_stream, out_stream):
        A = int(in_stream.readline().strip())
        for i in range(1, isqrt(A) + 1):
            if A % i == 0:
                self.process(i)
                if i * i != A:
                    self.process(A // i)

        self.dp = [[0] * len(self.map) for _ in range(2)]
        self.dp[0][self.map[1]] = 1
        idx = 0

        for i in self.divides.keys():
            idx ^= 1
            for j in self.map.keys():
                j2 = self.map[j]
                self.dp[idx][j2] = self.dp[idx ^ 1][j2]
                for x in self.divides[i]:
                    if j % x == 0:
                        self.dp[idx][j2] += self.dp[idx ^ 1][self.map[j // x]]

        out_stream.write(f"{self.dp[idx][self.map[A]]}\n")

    def prime(self, n):
        if n <= 1:
            return -1
        for i in range(2, isqrt(n) + 1):
            if n % i == 0:
                while n % i == 0:
                    n //= i
                return i if n == 1 else -1
        return n

    def process(self, x):
        self.map[x] = self.idx
        self.idx += 1
        p = self.prime(x - 1)
        if p > 0:
            self.divides[p].append(x)

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    solver = Task()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()
