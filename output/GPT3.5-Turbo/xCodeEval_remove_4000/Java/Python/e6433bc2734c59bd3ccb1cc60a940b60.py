import sys
from typing import List
from io import BytesIO, IOBase


class FastReader(IOBase):
    def __init__(self, fd: BytesIO = sys.stdin.buffer, chunk_size: int = 1 << 20):
        self.fd = fd
        self.buffer = BytesIO()
        self.buffer.seek(0, 2)
        self.writable = False
        self.readable = True
        self.closed = False
        self.chunk_size = chunk_size
        self.over = False
        self.closefd = False

    def read(self):
        if self.buffer.tell():
            return self.buffer.read()
        while True:
            if self.over:
                break
            b = self.fd.read(self.chunk_size)
            if b == b"":
                self.over = True
                break
            elif len(b) < self.chunk_size:
                self.over = True
            self.buffer.write(b)
        return self.buffer.read()

    def readline(self):
        while self.buffer.tell() == 0:
            b = self.fd.readline()
            if b == b"":
                break
            self.buffer.write(b)
        return self.buffer.readline()

    def readlines(self):
        while True:
            b = self.readline()
            if b == b"":
                break
            yield b

    def flush(self):
        if self.writable:
            self.fd.flush()

    def write(self, b):
        if not self.writable:
            raise IOError("Write operation not allowed")
        self.fd.write(b)

    def writelines(self, lines):
        self.fd.writelines(lines)


class FastWriter(IOBase):
    def __init__(self, fd: BytesIO = sys.stdout.buffer):
        self.fd = fd
        self.writable = True
        self.readable = False
        self.closed = False
        self.closefd = False

    def write(self, b):
        self.fd.write(b)

    def writeln(self, b=b"\n"):
        self.fd.write(b)

    def flush(self):
        self.fd.flush()


def solve():
    mod = 998244353
    n = int(input())
    a = list(map(int, input().split()))
    all = 26 * 26 * pow(25, n-2, mod) % mod

    dp = [[[0] * (n+1) for _ in range(n+1)] for _ in range(3)]
    dp[0][1][0] = 1
    dp[1][0][1] = 1
    dp[2][0][0] = 1
    for i in range(n-1):
        ndp = [[[0] * (n+1) for _ in range(n+1)] for _ in range(3)]
        if i == (n+1)//2-1:
            for j in range(n+1):
                for k in range(n-j+1):
                    if j + 1 <= n:
                        ndp[0][j + 1][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24
                        ndp[0][j + 1][k] %= mod
                    if k + 1 <= n:
                        ndp[1][j][k + 1] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24
                        ndp[1][j][k + 1] %= mod
                    ndp[2][j][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24
                    ndp[2][j][k] %= mod
        else:
            for j in range(n+1):
                for k in range(n-j+1):
                    if j + 1 <= n:
                        ndp[0][j + 1][k] += dp[1][j][k] + dp[2][j][k] * 24
                        ndp[0][j + 1][k] %= mod
                    if k + 1 <= n:
                        ndp[1][j][k + 1] += dp[0][j][k] + dp[2][j][k] * 24
                        ndp[1][j][k + 1] %= mod
                    ndp[2][j][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 23
                    ndp[2][j][k] %= mod
        dp = ndp

    sdp = [0] * (n+1)
    for i in range(n+1):
        for j in range(n+1):
            sdp[i] += dp[0][i][j] + dp[1][i][j] + dp[2][i][j] * 24
    sdp[i] %= mod

    for i in range(26):
        for k in range(a[i]+1, n+1):
            all -= sdp[k]

    for i in range(26):
        for j in range(i+1, 26):
            for k in range(a[i]+1, n+1):
                for l in range(a[j]+1, n-k+1):
                    all += (dp[0][k][l] + dp[1][k][l] + dp[2][k][l] * 24)
    all %= mod

    if all < 0:
        all += mod
    print(all)


def main():
    reader = FastReader()
    writer = FastWriter()
    solve()
    writer.flush()


if __name__ == "__main__":
    main()
