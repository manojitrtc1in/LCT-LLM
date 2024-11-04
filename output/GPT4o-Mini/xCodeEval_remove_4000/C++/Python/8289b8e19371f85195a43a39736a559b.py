from collections import defaultdict
import sys
import math
from typing import List, Tuple, Callable, Any

class Scanner:
    def __init__(self, fp):
        self.fp = fp
        self.line = ''
        self.index = 0

    def read(self):
        self.line = self.fp.readline().strip()
        self.index = 0

    def read_single(self):
        if self.index >= len(self.line):
            self.read()
        while self.index < len(self.line) and self.line[self.index].isspace():
            self.index += 1
        start = self.index
        while self.index < len(self.line) and not self.line[self.index].isspace():
            self.index += 1
        return self.line[start:self.index]

    def read_int(self):
        return int(self.read_single())

    def read_string(self):
        return self.read_single()

    def read_double(self):
        return float(self.read_single())

scanner = Scanner(sys.stdin)

class Printer:
    def __init__(self, fp):
        self.fp = fp

    def write(self, val):
        self.fp.write(str(val))

    def flush(self):
        self.fp.flush()

printer = Printer(sys.stdout)

def YES(t=True):
    printer.write("YES" if t else "NO")
    printer.write("\n")

def NO(t=True):
    YES(not t)

def solve():
    N = scanner.read_int()
    mod = scanner.read_int()

    class ModInt:
        def __init__(self, val=0):
            self.val = val % mod

        def __add__(self, other):
            return ModInt(self.val + other.val)

        def __sub__(self, other):
            return ModInt(self.val - other.val)

        def __mul__(self, other):
            return ModInt(self.val * other.val)

        def __truediv__(self, other):
            return self * other.inverse()

        def inverse(self):
            a, b = self.val, mod
            u, v = 1, 0
            while b > 0:
                t = a // b
                a, b = b, a - t * b
                u, v = v, u - t * v
            return ModInt(u)

        def __repr__(self):
            return str(self.val)

    seg = [ModInt(0) for _ in range(N + 1)]

    seg[1] += ModInt(1)

    for n in range(1, N + 1):
        dp = seg[n]
        for i in range(n + 1, N + 1):
            seg[i] += dp
        z = 2
        while True:
            l = n * z
            r = (n + 1) * z
            if l > N:
                break
            z += 1
            r = min(r, N + 1)
            for j in range(l, r):
                seg[j] += dp

    printer.write(seg[N])
    printer.write("\n")

def main():
    T = 1
    for _ in range(T):
        solve()

if __name__ == "__main__":
    main()
