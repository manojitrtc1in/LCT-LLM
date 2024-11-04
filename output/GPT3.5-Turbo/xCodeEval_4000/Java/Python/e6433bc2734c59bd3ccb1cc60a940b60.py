import sys
from typing import List
from io import BytesIO, IOBase

def solve() -> None:
    mod = 998244353
    n = ni()
    a = na(26)
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
    sdp = [x % mod for x in sdp]

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
    out.println(all)

def pow(a: int, n: int, mod: int) -> int:
    ret = 1
    x = 63 - n.bit_length()
    while x >= 0:
        ret = ret * ret % mod
        if n << 63 - x < 0:
            ret = ret * a % mod
        x -= 1
    return ret

def invl(a: int, mod: int) -> int:
    b = mod
    p, q = 1, 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    return p if p >= 0 else p + mod

def C(n: int, r: int, mod: int, fif: List[List[int]]) -> int:
    if n < 0 or r < 0 or r > n:
        return 0
    return (fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod)

def enumFIF(n: int, mod: int) -> List[List[int]]:
    f = [0] * (n + 1)
    invf = [0] * (n + 1)
    f[0] = 1
    for i in range(1, n+1):
        f[i] = (f[i - 1] * i) % mod
    a = f[n]
    b = mod
    p, q = 1, 0
    while b > 0:
        c = a // b
        d = a
        a = b
        b = d % b
        d = p
        p = q
        q = d - c * q
    invf[n] = p if p >= 0 else p + mod
    for i in range(n - 1, -1, -1):
        invf[i] = (invf[i + 1] * (i + 1)) % mod
    return [f, invf]

def main() -> None:
    ispace = False
    for line in sys.stdin:
        if ispace:
            print()
        else:
            ispace = True
        exec(line)

# region fastio
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
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
out = FastIO(sys.stdout)

# endregion

if __name__ == "__main__":
    main()
