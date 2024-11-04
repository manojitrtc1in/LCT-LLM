import sys
import random
from collections import deque
from itertools import islice

class Permutation(list):
    def __init__(self, size=0):
        super().__init__(range(size))
    
    def multiply(self, rhs):
        return Permutation(len(self)).from_list(self[i] for i in rhs)

    def pow(self, deg):
        result = Permutation(len(self))
        a = self[:]
        b = deg
        while b > 0:
            if b & 1:
                result *= a
            a *= a
            b >>= 1
        return result

    def next(self):
        return self._next_permutation()

    def _next_permutation(self):
        # Implement next permutation logic
        pass

class E1SortirovkaSliyaniem:
    kMinLen = 2
    kMaxLen = 1111

    @staticmethod
    def check(a):
        n = len(a)
        b = [0] * n
        log = []

        def merge(l, r):
            if r - l <= 1:
                return
            m = (l + r) // 2
            merge(l, m)
            merge(m, r)
            i, j, k = l, m, l
            while i < m and j < r:
                if a[i] < a[j]:
                    log.append('0')
                    b[k] = a[i]
                    i += 1
                else:
                    log.append('1')
                    b[k] = a[j]
                    j += 1
                k += 1
            while i < m:
                b[k] = a[i]
                i += 1
                k += 1
            while j < r:
                b[k] = a[j]
                j += 1
                k += 1
            for p in range(l, r):
                a[p] = b[p]

        merge(0, n)
        return ''.join(log)

    @staticmethod
    def try_recover(l, r, s, p):
        if r - l <= 1:
            return True
        mid = (l + r) // 2
        if not (E1SortirovkaSliyaniem.try_recover(l, mid, s, p) and E1SortirovkaSliyaniem.try_recover(mid, r, s, p)):
            return False
        left = [p[i] for i in range(mid - 1, l - 1, -1)]
        right = [p[i] for i in range(r - 1, mid - 1, -1)]
        pos = l
        while left and right:
            if not s:
                return False
            ch = s.pop()
            if ch == '1':
                p[pos] = right.pop()
            else:
                p[pos] = left.pop()
            pos += 1
        while left:
            p[pos] = left.pop()
            pos += 1
        while right:
            p[pos] = right.pop()
            pos += 1
        return True

    def solve(self, in_stream, out_stream):
        s = in_stream.readline().strip()[::-1]

        for length in range(self.kMinLen, self.kMaxLen + 1):
            p = Permutation(length)
            tmp = list(s)
            if self.try_recover(0, length, tmp, p) and not tmp:
                ans = [0] * length
                for i in range(length):
                    ans[p[i]] = i
                out_stream.write(f"{length}\n")
                out_stream.write(" ".join(str(x + 1) for x in ans) + "\n")
                return

def main():
    solver = E1SortirovkaSliyaniem()
    in_stream = sys.stdin
    out_stream = sys.stdout

    random.seed()
    out_stream.write(f"{'%.16f' % 0.0}\n")  # Placeholder for precision output
    solver.solve(in_stream, out_stream)

if __name__ == "__main__":
    main()
