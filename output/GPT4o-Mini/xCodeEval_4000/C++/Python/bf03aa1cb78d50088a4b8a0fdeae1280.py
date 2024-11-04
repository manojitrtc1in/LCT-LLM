import sys
import random
from collections import deque

class E1SortirovkaSliyaniem:
    kWriteCaseNumber = False
    kMultiTest = False

    kMinLen = 1
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

    kMaxn = 100001

    @staticmethod
    def try_recover(l, r, s, p):
        if r - l <= 1:
            return True
        mid = (l + r) // 2
        if not E1SortirovkaSliyaniem.try_recover(l, mid, s, p) or not E1SortirovkaSliyaniem.try_recover(mid, r, s, p):
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

        L = self.kMinLen
        R = self.kMaxLen
        while R - L > 1:
            length = (L + R) // 2
            p = list(range(length))
            tmp = list(s)
            recovered = self.try_recover(0, length, tmp, p)
            if recovered:
                if not tmp:
                    ans = [0] * length
                    for i in range(length):
                        ans[p[i]] = i
                    out_stream.write(f"{length}\n")
                    out_stream.write(" ".join(str(x + 1) for x in ans) + "\n")
                    return
                L = length
            else:
                R = length
        assert False

def main():
    solver = E1SortirovkaSliyaniem()
    in_stream = sys.stdin
    out_stream = sys.stdout

    random.seed()
    if E1SortirovkaSliyaniem.kMultiTest:
        tests_count = int(in_stream.readline().strip())
        for test_id in range(1, tests_count + 1):
            if E1SortirovkaSliyaniem.kWriteCaseNumber:
                out_stream.write(f"Case #{test_id}: ")
            solver.solve(in_stream, out_stream)
    else:
        solver.solve(in_stream, out_stream)

if __name__ == "__main__":
    main()
