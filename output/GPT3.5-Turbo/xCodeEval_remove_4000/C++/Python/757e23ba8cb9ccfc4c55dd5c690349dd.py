import sys

class DSum:
    class Solver:
        def __init__(self, in_stream, out_stream):
            self._in = in_stream
            self._out = out_stream

        def read(self, *args):
            for arg in args:
                arg[0] = int(self._in.readline().strip())

        def write(self, *args):
            for arg in args:
                self._out.write(str(arg) + '\n')

        def solve(self):
            N, K = 0, 0
            A = []
            A_sum = []
            best = 0

            self.read([N], [K])
            for _ in range(N):
                t = 0
                self.read([t])
                a = list(map(int, self._in.readline().strip().split()))
                A.append(a[:min(t, K)])
                A_sum.append(sum(A[-1]))

            knapsack = [0] * (K + 1)

            def add_item(knapsack, size, s):
                for k in range(K - size, -1, -1):
                    knapsack[k + size] = max(knapsack[k + size], knapsack[k] + s)

            def recurse(start, end, knapsack):
                nonlocal best

                if start >= end:
                    return

                if end - start == 1:
                    s = 0
                    best = max(best, knapsack[K])

                    for prefix in range(1, len(A[start]) + 1):
                        s += A[start][prefix - 1]
                        best = max(best, s + knapsack[K - prefix])

                    return

                mid = (start + end) // 2
                state = knapsack[:]

                for i in range(start, mid):
                    add_item(state, len(A[i]), A_sum[i])

                recurse(mid, end, state)
                state = knapsack[:]

                for i in range(mid, end):
                    add_item(state, len(A[i]), A_sum[i])

                recurse(start, mid, state)

            recurse(0, N, knapsack)
            self.write(best)

    @staticmethod
    def solve(in_stream, out_stream):
        DSum.Solver(in_stream, out_stream).solve()


if __name__ == '__main__':
    DSum.solve(sys.stdin, sys.stdout)
