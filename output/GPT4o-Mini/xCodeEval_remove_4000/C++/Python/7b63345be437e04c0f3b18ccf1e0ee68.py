import sys
from itertools import accumulate

class DSum:
    class Solver:
        def __init__(self, in_stream, out_stream):
            self._in = in_stream
            self._out = out_stream

        def rd(self):
            return map(int, self._in.readline().split())

        def pr(self, *args):
            self._out.write(' '.join(map(str, args)) + '\n')

        def add_item(self, knapsack, size, sum_):
            for k in range(K - size, -1, -1):
                knapsack[k + size] = max(knapsack[k + size], knapsack[k] + sum_)

        def recurse(self, start, end, knapsack):
            if start >= end:
                return

            if end - start == 1:
                sum_ = 0
                self.best = max(self.best, knapsack[K])

                for prefix in range(1, len(A[start]) + 1):
                    sum_ += A[start][prefix - 1]
                    self.best = max(self.best, sum_ + knapsack[K - prefix])

                return

            mid = (start + end) // 2
            state = knapsack[:]

            for i in range(start, mid):
                self.add_item(state, len(A[i]), self.A_sum[i])

            self.recurse(mid, end, state)
            state = knapsack[:]

            for i in range(mid, end):
                self.add_item(state, len(A[i]), self.A_sum[i])

            self.recurse(start, mid, state)

        def solve(self):
            global N, K, A, A_sum
            N, K = self.rd()
            A = []
            A_sum = []

            for _ in range(N):
                t, *a = self.rd()
                A.append(a)
                if t > K:
                    A[-1] = A[-1][:K]
                A_sum.append(sum(A[-1]))

            self.best = 0
            knapsack = [0] * (K + 1)
            self.recurse(0, N, knapsack)
            self.pr(self.best)

    @staticmethod
    def solve(in_stream, out_stream):
        DSum.Solver(in_stream, out_stream).solve()

if __name__ == "__main__":
    input_stream = sys.stdin
    output_stream = sys.stdout
    DSum.solve(input_stream, output_stream)
