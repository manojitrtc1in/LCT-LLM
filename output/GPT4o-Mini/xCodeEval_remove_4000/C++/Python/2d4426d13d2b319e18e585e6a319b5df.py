from collections import defaultdict
import math
import sys

class FastIO:
    def __init__(self):
        self.input = sys.stdin.read
        self.output = sys.stdout.write

    def read_int(self):
        return int(self.input().strip())

    def read_string(self):
        return self.input().strip()

    def print_int(self, num):
        self.output(f"{num}\n")

    def print_float(self, num):
        self.output(f"{num:.10f}\n")

fio = FastIO()

def Mask(x):
    return (1 << x) - 1

def Maskx(condition, index):
    return (1 << index) if condition else 0

n = fio.read_int()
s = [fio.read_string() for _ in range(n)]
m = len(s[0])
dy = [0] * (Mask(20) + 5)
dp = [0.0] * (Mask(20) + 5)

for i in range(n):
    for j in range(i + 1, n):
        num = 0
        for k in range(m):
            num |= Maskx(s[i][k] == s[j][k], k)
        dy[num] |= (1 << i) | (1 << j)

for i in range(Mask(m) + 1):
    j = i
    while j:
        lst = j & -j
        dy[i ^ lst] |= dy[i]
        j -= lst

dp[0] = 1.0
ans = 0.0

for i in range(Mask(m) + 1):
    v = dp[i] / (m - bin(i).count('1'))
    j = Mask(m) ^ i
    while j:
        dp[i | (j & -j)] += v
        j -= j & -j
    ans += dp[i] * bin(dy[i]).count('1')

fio.print_float(ans / n)
