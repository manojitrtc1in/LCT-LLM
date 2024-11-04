import sys
from typing import List, Tuple

MOD = 998244353
ROOT = pow(3, 7*17, MOD)
ROOT_INV = pow(ROOT, MOD - 2, MOD)
ORDER = 1 << 23

class MyScanner:
    def __init__(self, input_file=None):
        if input_file:
            self.input = open(input_file, 'r')
        else:
            self.input = sys.stdin
        self.buffer = []
        self.buffer_pos = 0

    def close(self):
        if self.input != sys.stdin:
            self.input.close()

    def next(self) -> str:
        if self.buffer_pos >= len(self.buffer):
            self.buffer = self.input.readline().split()
            self.buffer_pos = 0
        self.buffer_pos += 1
        return self.buffer[self.buffer_pos - 1]

    def next_int(self) -> int:
        return int(self.next())

    def next_long(self) -> int:
        return int(self.next())

    def next_double(self) -> float:
        return float(self.next())

    def next_line(self) -> str:
        return self.input.readline().strip()

    def next_matrix(self, n: int, m: int, offset: int = 0) -> List[List[int]]:
        matrix = []
        for _ in range(n):
            row = [int(x) + offset for x in self.next().split()]
            matrix.append(row)
        return matrix

    def next_pairs(self, n: int, offset: int = 0) -> Tuple[List[int], List[int]]:
        x = []
        y = []
        for _ in range(n):
            a, b = map(int, self.next().split())
            x.append(a + offset)
            y.append(b + offset)
        return x, y

    def next_graph(self, n: int, offset: int = 0) -> List[List[int]]:
        graph = [[] for _ in range(n)]
        for _ in range(n-1):
            u, v = map(int, self.next().split())
            graph[u - offset].append(v - offset)
            graph[v - offset].append(u - offset)
        return graph

class id5:
    def __init__(self, output_file=None):
        if output_file:
            self.output = open(output_file, 'w')
        else:
            self.output = sys.stdout

    def close(self):
        if self.output != sys.stdout:
            self.output.close()

    def println(self, *args, **kwargs):
        print(*args, **kwargs, file=self.output)

    def print(self, *args, **kwargs):
        print(*args, **kwargs, file=self.output, end='')

    def println_ans(self, ans):
        self.println(ans)

    def print_ans(self, arr):
        if arr:
            self.print(arr[0], end='')
            for i in range(1, len(arr)):
                self.print(' ', arr[i], end='')
        self.println()

    def println_ans(self, arr):
        self.print_ans(arr)

    def print_ans(self, arr, add):
        if arr:
            self.print(arr[0] + add, end='')
            for i in range(1, len(arr)):
                self.print(' ', arr[i] + add, end='')
        self.println()

    def println_ans(self, arr, add):
        self.print_ans(arr, add)

    def id1(self, arr, split):
        if arr:
            for i in range(0, len(arr), split):
                self.print(arr[i], end='')
                for j in range(i+1, i+split):
                    self.print(' ', arr[j], end='')
                self.println()

class id4:
    def __init__(self):
        self.out = id5()
        self.inp = MyScanner()

    def run(self):
        is_debug = False
        id8 = True
        id2 = False

        t = self.inp.next_int() if id2 else 1

        for i in range(1, t+1):
            if is_debug:
                self.out.println(f"Test {i}")

            self.get_input()

            ans = self.solve()

            self.print_output(ans)

        self.inp.close()
        self.out.close()

    def get_input(self):
        self.n = self.inp.next_int()
        self.k = self.inp.next_int()
        self.f = self.inp.next_int()

    def print_output(self, ans):
        self.out.println_ans(ans)

    def solve(self) -> int:
        ans = 0

        ways = [0] * (self.f+2 + self.f+2)
        suffix = [0] * (self.f+2)

        for i in range(self.k+1):
            ways[i] = 1
        ways[self.f+1] = max(0, self.k-self.f)

        for i in range(self.n):
            if i < self.n-1:
                self.square(ways)

                val = 0
                for j in range(len(ways)-1, self.f+1, -1):
                    val += ways[j]
                val %= MOD
                suffix[self.f+1] = val

                for j in range(self.f, -1, -1):
                    val = suffix[j+1] + ways[j]
                    val = val if val < MOD else val - MOD
                    suffix[j] = val

                for j in range(self.k+1):
                    val = suffix[j]
                    val += ways[j] * (self.k-j)
                    val %= MOD
                    ways[j] = val

                val = suffix[self.f+1] * max(0, self.k-self.f)
                val %= MOD
                ways[self.f+1] = val

                for j in range(self.k+1, self.f+2):
                    ways[j] = 0
                ways[self.f+2:] = [0] * (len(ways) - (self.f+2))

            else:
                for j in range(self.f+1):
                    ans += ways[j] * ways[self.f-j]
                    ans %= MOD

        return ans

    @staticmethod
    def pow(a: int, k: int, p: int) -> int:
        m = k
        ans = 1
        curr = a

        while m > 0:
            if m & 1:
                ans *= curr
                ans %= p
            m >>= 1
            curr *= curr
            curr %= p

        return ans

    @staticmethod
    def inverse(a: int, p: int) -> int:
        return id4.pow(a, p-2, p)

    @staticmethod
    def swap(a: List[int], i: int, j: int):
        a[i], a[j] = a[j], a[i]

    @staticmethod
    def fft(a: List[int], id0: bool):
        n = len(a)

        i, j, bit = 1, 0, n >> 1
        while i < n:
            if j & bit:
                j ^= bit
                bit >>= 1
            else:
                j ^= bit
                bit >>= 1
                i |= bit

            if i < j:
                id4.swap(a, i, j)

        for length in range(2, n+1, 2):
            wlen = ROOT_INV if id0 else ROOT
            for i in range(length, ORDER, length << 1):
                wlen = wlen * wlen % MOD

            for i in range(0, n, length):
                w = 1
                for j in range(length >> 1):
                    u = a[i+j]
                    v = a[i+j+(length >> 1)] * w % MOD
                    a[i+j] = u + v if u + v < MOD else u + v - MOD
                    a[i+j+(length >> 1)] = u - v if u - v >= 0 else u - v + MOD
                    w = w * wlen % MOD

        if id0:
            inv = id4.inverse(n, MOD)
            for i in range(n):
                a[i] = a[i] * inv % MOD

    @staticmethod
    def square(a: List[int]):
        id4.fft(a, False)
        for i in range(len(a)):
            a[i] = a[i] * a[i] % MOD
        id4.fft(a, True)

if __name__ == '__main__':
    sol = id4()
    sol.run()
