import sys
from collections import defaultdict
from decimal import Decimal, getcontext

getcontext().prec = 100  # Set precision for Decimal

class MyScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = []
    
    def next(self):
        while not self.buffer:
            self.buffer = self.input_stream.readline().strip().split()
        return self.buffer.pop(0)
    
    def next_int(self):
        return int(self.next())
    
    def next_pairs(self, n):
        u = []
        v = []
        for _ in range(n):
            u.append(self.next_int())
            v.append(self.next_int())
        return u, v

class MyPrintWriter:
    def __init__(self, output_stream):
        self.output_stream = output_stream
    
    def println(self, *args):
        self.output_stream.write(" ".join(map(str, args)) + "\n")

    def close(self):
        self.output_stream.close()

class Round791F:
    IMPOSSIBLE = "IMPOSSIBLE"
    POSSIBLE = "POSSIBLE"
    YES = "YES"
    NO = "NO"
    MOD = 998244353
    RADIX = 10

    def __init__(self):
        self.out = MyPrintWriter(sys.stdout)
        self.in_stream = MyScanner(sys.stdin)

    def run(self):
        t = 1  # Change this if you want to handle multiple test cases
        for _ in range(t):
            n = self.in_stream.next_int()
            m = self.in_stream.next_int()
            u, v = self.in_stream.next_pairs(m)
            ans = self.solve2(u, v, n)
            self.out.println(ans)

        self.out.close()

    def validate(self, u, v, n):
        cmp = [[0] * self.RADIX for _ in range(self.RADIX)]
        for i in range(len(u)):
            small = min(u[i], v[i])
            large = max(u[i], v[i])
            cmp[small][large] = -1
            cmp[large][small] = 1

        curr = Decimal(0)
        limit = Decimal(self.RADIX) ** n
        unique_set = set()

        while curr < limit:
            s = format(curr, 'x')  # Convert to base RADIX
            padding = n - len(s)
            s = '0' * padding + s
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
                    val = next_dp[mask2] + dp[mask]
                    next_dp[mask2] = val % self.MOD
            dp = next_dp

        return sum(dp) % self.MOD

if __name__ == "__main__":
    Round791F().run()
