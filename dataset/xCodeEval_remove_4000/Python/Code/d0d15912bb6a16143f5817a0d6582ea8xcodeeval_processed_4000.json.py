

import os
import sys
from collections import defaultdict, Counter

from io import BytesIO, IOBase
from math import inf, gcd

from math import ceil


def lcm(a, b):
    return (a * b) // gcd(a, b)







def sieve():
    global spf, adj, MAXN
    spf[1] = 1
    for i in range(2, MAXN):
        spf[i] = i

    for i in range(2, MAXN):
        if i * i > MAXN:
            break
        if (spf[i] == i):
            for j in range(i * i, MAXN, i):
                if (spf[j] == j):
                    spf[j] = i
def id4(n):
    global adj, spf, MAXN
    for i in range(1, n + 1):
        index = 1
        x = i
        if (x != 1):
            adj[i].append(spf[x])
        x = x // spf[x]
        while (x != 1):
            if (adj[i][index - 1] != spf[x]):
                adj[i].append(spf[x])
                index += 1
            x = x // spf[x]
def id3(n):
    i = 2
    z = [1, n]
    while i <= sqrt(n):
        if (n % i == 0):
            if (n / i == i):
                z.append(i)
            else:
                z.append(i)
                z.append(n // i)
        i = i + 1
    return z
def create(n, x, f):
    pq = len(bin(n)[2:])
    if f == 0:
        tt = min
    else:
        tt = max
    dp = [[inf] * n for _ in range(pq)]
    dp[0] = x
    for i in range(1, pq):
        for j in range(n - (1 << i) + 1):
            dp[i][j] = tt(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))])
    return dp
def enquiry(l, r, dp, f):
    if l > r:
        return inf if not f else -inf
    if f == 1:
        tt = max
    else:
        tt = min
    pq1 = len(bin(r - l + 1)[2:]) - 1
    return tt(dp[pq1][l], dp[pq1][r - (1 << pq1) + 1])
def id0(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
    x = []
    for i in range(2, n + 1):
        if prime[i]:
            x.append(i)
    return x


def id2(w, d, v, n):
    dp = []

    for i in range(n + 1):
        dp.append([0] * (w + 1))

    dp[0][0] = 0

    for i in range(1, n + 1):
        for j in range(0, w + 1):
            if j - d[i - 1] >= 0:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - d[i - 1]] + v[i - 1])

            dp[i][j] = max(dp[i][j], dp[i - 1][j])

    print(dp[n][w])
def main():

    z=[0, 0, 1, 2, 2, 3, 3, 4, 3, 4, 4, 5, 4, 5, 5, 5, 4, 5, 5, 5, 5, 5, 6, 6, 5, 6, 6, 6, 6, 7, 6, 6, 5, 6, 6, 6, 6, 6, 6, 7, 6, 7, 6, 7, 7, 7, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 7, 8, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 7, 8, 8, 8, 7, 8, 8, 8, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 8, 9, 9, 9, 8, 9, 8, 8, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 8, 9, 8, 9, 8, 9, 8, 8, 9, 9, 8, 8, 9, 9, 9, 9, 9, 9, 8, 9, 9, 9, 9, 9, 9, 9, 8, 9, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 10, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 9, 10, 9, 9, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 9, 10, 10, 10, 9, 10, 10, 10, 9, 10, 10, 10, 9, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 10, 10, 10, 10, 10, 10, 10, 11, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 10, 10, 10, 11, 10, 10, 10, 11, 11, 11, 11, 11, 10, 11, 11, 11, 10, 11, 10, 11, 10, 11, 11, 11, 10, 11, 10, 10, 10, 11, 11, 11, 10, 10, 10, 11, 10, 11, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 10, 11, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 10, 11, 10, 11, 10, 11, 10, 11, 10, 11, 10, 10, 10, 11, 10, 11, 10, 11, 10, 11, 10, 11, 10, 10, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 10, 10, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 10, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 10, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 12, 11, 11, 11, 11, 12, 12, 11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 11, 11, 12, 12, 11, 12, 11, 12, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 12, 11, 12, 11, 11, 12, 12, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 12, 12, 11, 12, 11, 11, 11, 12, 12, 12, 11, 12, 11, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 11, 11, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 11, 12, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 11, 12, 11, 11, 12, 12, 11, 12, 12, 12, 11, 12, 11, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 12]

    for _ in range(int(input())):
        n,k=map(int,input().split())
        b=[int(x) for x in input().split()]
        c=[int(X) for X in input().split()]
        w=[z[b[i]] for i in range(n)]
        k=min(sum(w),k)
        
        id2(k,w,c,n)

id1 = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id1))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id1))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

if __name__ == '__main__':
    main()