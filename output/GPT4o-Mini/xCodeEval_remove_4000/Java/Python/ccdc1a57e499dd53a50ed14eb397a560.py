import sys
from collections import defaultdict
import math

class IntervalTree:
    def __init__(self, n):
        self.array = [0] * (4 * n + 1)
        self.n = n

    def update(self, pos, x):
        self._update(0, 0, self.n - 1, pos, x)

    def _update(self, node, left, right, pos, val):
        if left == right:
            self.array[node] = val
            return
        middle = (left + right) // 2
        if pos <= middle:
            self._update(2 * node + 1, left, middle, pos, val)
        else:
            self._update(2 * node + 2, middle + 1, right, pos, val)
        self.array[node] = max(self.array[2 * node + 1], self.array[2 * node + 2])

    def query(self, from_, to):
        return self._query(0, 0, self.n - 1, from_, to)

    def _query(self, node, left, right, from_, to):
        if left > to or right < from_:
            return 0
        if left >= from_ and right <= to:
            return self.array[node]
        middle = (left + right) // 2
        return max(self._query(2 * node + 1, left, middle, from_, to),
                   self._query(2 * node + 2, middle + 1, right, from_, to))


class Task:
    def __init__(self):
        self.L = []
        self.R = []
        self.A = []
        self.B = []
        self.C = []
        self.max = []
        self.best = []
        self.orderV = []
        self.orderC = []
        self.tree = None
        self.map = {}

    def solve(self, test_number, in_stream, out_stream):
        n = int(in_stream.readline().strip())
        m = int(in_stream.readline().strip())
        idx = 0
        flag = n == 200000 and m == 200000
        self.L = list(map(int, in_stream.readline().strip().split()))
        self.R = list(map(int, in_stream.readline().strip().split()))
        self.A = list(map(int, in_stream.readline().strip().split()))
        self.B = list(map(int, in_stream.readline().strip().split()))
        self.C = list(map(int, in_stream.readline().strip().split()))
        self.max = [0] * m
        self.best = [-1] * m
        self.orderV = list(range(n))
        self.orderC = list(range(m))

        arr = [0] * (2 * (n + m))
        for i in range(n):
            arr[2 * i] = self.L[i]
            arr[2 * i + 1] = self.R[i]
        for i in range(m):
            arr[2 * (n + i)] = self.A[i]
            arr[2 * (n + i) + 1] = self.B[i]

        arr = sorted(set(arr))
        self.map = {val: idx for idx, val in enumerate(arr)}
        self.tree = IntervalTree(len(self.map))

        self.process1(n, m, out_stream)
        self.process2(n, m)
        self.process3(n, m)

        ret = 0
        aux = -1
        for i in range(m):
            x = self.max[i] * self.C[i]
            if x > ret:
                ret = x
                aux = i

        out_stream.write(f"{ret}\n")
        if ret > 0:
            out_stream.write(f"{self.best[aux] + 1} {aux + 1}\n")

    def process1(self, n, m, out_stream):
        self.orderV.sort(key=lambda x: self.L[x])
        self.orderC.sort(key=lambda x: self.A[x])

        v = 0
        c = 0
        ret = 0
        idx = -1

        while v < n or c < m:
            while v < n and (c == m or self.L[self.orderV[v]] <= self.A[self.orderC[c]]):
                x = self.orderV[v]
                if self.R[x] > ret:
                    ret = self.R[x]
                    idx = x
                v += 1

            while c < m and (v == n or self.A[self.orderC[c]] < self.L[self.orderV[v]]):
                x = self.orderC[c]
                length = min(ret, self.B[x]) - self.A[x]
                if length > self.max[x]:
                    self.max[x] = length
                    self.best[x] = idx
                c += 1

    def process2(self, n, m):
        self.orderV.sort(key=lambda x: self.R[x])
        self.orderC.sort(key=lambda x: self.B[x])

        v = 0
        c = 0

        while v < n or c < m:
            while v < n and (c == m or self.R[self.orderV[v]] <= self.B[self.orderC[c]]):
                x = self.orderV[v]
                self.tree.update(self.map[self.L[x]], (self.R[x] - self.L[x]) * n + x)
                v += 1

            while c < m and (v == n or self.B[self.orderC[c]] < self.R[self.orderV[v]]):
                x = self.orderC[c]
                aux = self.tree.query(self.map[self.A[x]], self.map[self.B[x]])
                length = aux // n
                y = aux % n
                if length > self.max[x]:
                    self.max[x] = length
                    self.best[x] = y
                c += 1

    def process3(self, n, m):
        v = n - 1
        c = m - 1
        ret = float('inf')
        idx = -1

        while v >= 0 or c >= 0:
            while v >= 0 and (c == -1 or self.R[self.orderV[v]] >= self.B[self.orderC[c]]):
                x = self.orderV[v]
                if self.L[x] < ret:
                    ret = self.L[x]
                    idx = x
                v -= 1

            while c >= 0 and (v == -1 or self.B[self.orderC[c]] > self.R[self.orderV[v]]):
                x = self.orderC[c]
                length = self.B[x] - max(ret, self.A[x])
                if length > self.max[x]:
                    self.max[x] = length
                    self.best[x] = idx
                c -= 1


def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    solver = Task()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()
