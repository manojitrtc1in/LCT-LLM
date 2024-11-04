import sys
import random
from collections import defaultdict
from decimal import Decimal

class MyScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def next(self):
        return next(self.input_stream)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_pairs(self, n, offset=0):
        xy = [[0] * n for _ in range(2)]
        for i in range(n):
            xy[0][i] = self.next_int() + offset
            xy[1][i] = self.next_int() + offset
        return xy

class Id4:
    def __init__(self, output_stream):
        self.output_stream = output_stream

    def println(self, message):
        self.output_stream.write(str(message) + '\n')

    def print_ans(self, arr):
        if arr:
            self.output_stream.write(' '.join(map(str, arr)) + '\n')

class Id3:
    MOD = 998244353
    RADIX = 10

    def __init__(self):
        self.out = Id4(sys.stdout)
        self.in_stream = MyScanner(sys.stdin)

    def run(self):
        is_debug = False
        id7 = True
        id1 = False

        t = 1 if not id1 else self.in_stream.next_int()

        for i in range(1, t + 1):
            n = self.in_stream.next_int()
            m = self.in_stream.next_int()
            uv = self.in_stream.next_pairs(m)
            u = uv[0]
            v = uv[1]

            if is_debug:
                self.out.println(f"Test {i}")

            ans = self.solve2(u, v, n)
            self.out.println(ans)

            if is_debug:
                self.out.flush()

    def validate(self, u, v, n):
        cmp = [[0] * self.RADIX for _ in range(self.RADIX)]
        for i in range(len(u)):
            small = min(u[i], v[i])
            large = max(u[i], v[i])
            cmp[small][large] = -1
            cmp[large][small] = 1

        curr = 0
        limit = self.RADIX ** n
        unique_set = set()

        while curr < limit:
            s = format(curr, '0' + str(self.RADIX))
            arr = list(s)
            arr.sort(key=lambda x: cmp[int(x)][int(x)])

            unique_set.add(''.join(arr))
            curr += 1

        self.out.println(len(unique_set))
        self.out.println(unique_set)

    def solve2(self, u, v, n):
        dp = [0] * (1 << self.RADIX)
        for j in range(self.RADIX):
            dp[1 << j] = 1

        cmp = [[0] * self.RADIX for _ in range(self.RADIX)]
        m = len(u)
        for i in range(m):
            small = min(u[i], v[i])
            larger = max(u[i], v[i])
            cmp[small][larger] = -1
            cmp[larger][small] = 1

        is_valid = [[False] * self.RADIX for _ in range(1 << self.RADIX)]
        map_mask = [[0] * self.RADIX for _ in range(1 << self.RADIX)]

        for mask in range(1 << self.RADIX):
            for j in range(self.RADIX):
                ok = True
                next_mask = 1 << j
                for k in range(self.RADIX):
                    if (1 << k & mask) == 0:
                        continue

                    if cmp[j][k] == 0:
                        continue
                    elif cmp[j][k] == -1:
                        next_mask |= 1 << k
                    else:
                        ok = False

                is_valid[mask][j] = ok
                map_mask[mask][j] = next_mask

        for i in range(n - 2, -1, -1):
            next_dp = [0] * (1 << self.RADIX)
            for mask in range(1 << self.RADIX):
                for j in range(self.RADIX):
                    if not is_valid[mask][j]:
                        continue
                    mask2 = map_mask[mask][j]
                    next_dp[mask2] = (next_dp[mask2] + dp[mask]) % self.MOD
            dp = next_dp

        return sum(dp) % self.MOD

    @staticmethod
    def pow(a, k, p):
        ans = 1
        curr = a
        while k > 0:
            if (k & 1) == 1:
                ans = (ans * curr) % p
            k >>= 1
            curr = (curr * curr) % p
        return ans

    @staticmethod
    def inverse(a, p):
        return Id3.pow(a, p - 2, p)

if __name__ == "__main__":
    sol = Id3()
    sol.run()
