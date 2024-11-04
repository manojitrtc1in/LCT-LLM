import sys
import random
from collections import defaultdict

MOD = int(1e9) + 7
N = 32

def add(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def mul(a, b):
    return a * b % MOD

class Mat:
    def __init__(self):
        self.data = [[0] * (N) for _ in range(N)]

    def __mul__(self, other):
        c = Mat()
        for i in range(k + 1):
            for j in range(k + 1):
                c.data[i][j] = 0
                for t in range(k + 1):
                    c.data[i][j] = add(c.data[i][j], mul(self.data[i][t], other.data[t][j]))
        return c

amat = [[Mat() for _ in range(N)] for _ in range(62)]

def solve(n, k):
    num = []
    while n > 0:
        num.append(n % k)
        n //= k

    for d in range(k):
        for i in range(k + 1):
            for j in range(k + 1):
                amat[0][d].data[i][j] = 0
        for i in range(k + 1):
            amat[0][d].data[i][i] = 1
        for i in range(k + 1):
            amat[0][d].data[i][d] = 1

    for r in range(1, len(num)):
        pr = [Mat() for _ in range(k + 1)]
        for i in range(k + 1):
            pr[0].data[i][i] = 1
        for i in range(k):
            pr[i + 1] = pr[i] * amat[r - 1][i]

        for sh in range(k):
            amat[r][sh] = pr[0]
            for i in range(k - sh):
                amat[r][sh] = amat[r][sh] * amat[r - 1][(i + sh) % k]
            amat[r][sh] = amat[r][sh] * pr[sh]

    dp = Mat()
    for i in range(k + 1):
        for j in range(k + 1):
            dp.data[i][j] = 0
    dp.data[0][k] = 1

    rem = 0
    for i in range(len(num) - 1, -1, -1):
        while num[i] > 0:
            dp = dp * amat[i][rem]
            rem = (rem + 1) % k
            num[i] -= 1

    ans = 0
    for i in range(k + 1):
        ans = add(ans, dp.data[0][i])
    print(ans)

def read():
    line = sys.stdin.readline()
    if not line:
        return False
    n, k = map(int, line.split())
    solve(n, k)
    return True

if __name__ == "__main__":
    while read():
        pass
