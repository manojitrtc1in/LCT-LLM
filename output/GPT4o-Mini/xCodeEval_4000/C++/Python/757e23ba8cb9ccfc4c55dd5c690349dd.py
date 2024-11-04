import sys
from itertools import accumulate

class DSum:
    class Solver:
        def __init__(self, in_stream, out_stream):
            self.in_stream = in_stream
            self.out_stream = out_stream
            self.N = 0
            self.K = 0
            self.A = []
            self.A_sum = []
            self.best = 0

        def read_ints(self):
            return list(map(int, self.in_stream.readline().split()))

        def add_item(self, knapsack, size, sum_):
            for k in range(self.K - size, -1, -1):
                knapsack[k + size] = max(knapsack[k + size], knapsack[k] + sum_)

        def recurse(self, start, end, knapsack):
            if start >= end:
                return

            if end - start == 1:
                sum_ = 0
                self.best = max(self.best, knapsack[self.K])

                for prefix in range(1, len(self.A[start]) + 1):
                    sum_ += self.A[start][prefix - 1]
                    self.best = max(self.best, sum_ + knapsack[self.K - prefix])

                return

            mid = (start + end) // 2
            state = knapsack[:]

            for i in range(start, mid):
                self.add_item(state, len(self.A[i]), self.A_sum[i])

            self.recurse(mid, end, state)
            state = knapsack[:]

            for i in range(mid, end):
                self.add_item(state, len(self.A[i]), self.A_sum[i])

            self.recurse(start, mid, state)

        def solve(self):
            self.N, self.K = self.read_ints()
            self.A = [[] for _ in range(self.N)]
            self.A_sum = [0] * self.N

            for i in range(self.N):
                t = int(self.in_stream.readline())
                self.A[i] = list(map(int, self.in_stream.readline().split()))

                if t > self.K:
                    self.A[i] = self.A[i][:self.K]

                self.A_sum[i] = sum(self.A[i])

            self.best = 0
            knapsack = [0] * (self.K + 1)
            self.recurse(0, self.N, knapsack)
            print(self.best)

    @staticmethod
    def solve(in_stream, out_stream):
        DSum.Solver(in_stream, out_stream).solve()

if __name__ == "__main__":
    DSum.solve(sys.stdin, sys.stdout)
