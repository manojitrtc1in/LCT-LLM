import sys
from collections import deque

class G3:
    def __init__(self):
        self.INPUT = ""
    
    def solve(self):
        mod = 998244353
        n = self.ni()
        a = self.na(26)
        all_count = 26 * 26 * self.pow(25, n - 2, mod) % mod

        dp = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(3)]
        dp[0][1][0] = 1
        dp[1][0][1] = 1
        dp[2][0][0] = 1
        
        for i in range(n - 1):
            ndp = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(3)]
            if i == (n + 1) // 2 - 1:
                for j in range(n + 1):
                    for k in range(n + 1):
                        if j + 1 <= n:
                            ndp[0][j + 1][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % mod
                        if k + 1 <= n:
                            ndp[1][j][k + 1] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % mod
                        ndp[2][j][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % mod
            else:
                for j in range(n + 1):
                    for k in range(n + 1):
                        if j + 1 <= n:
                            ndp[0][j + 1][k] += (dp[1][j][k] + dp[2][j][k] * 24) % mod
                        if k + 1 <= n:
                            ndp[1][j][k + 1] += (dp[0][j][k] + dp[2][j][k] * 24) % mod
                        ndp[2][j][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 23) % mod

            dp = ndp

        sdp = [0] * (n + 1)
        for i in range(n + 1):
            for j in range(n + 1):
                sdp[i] += (dp[0][i][j] + dp[1][i][j] + dp[2][i][j] * 24) % mod
            sdp[i] %= mod

        for i in range(26):
            for k in range(a[i] + 1, n + 1):
                all_count -= sdp[k]

        for i in range(26):
            for j in range(i + 1, 26):
                for k in range(a[i] + 1, n + 1):
                    for l in range(a[j] + 1, n + 1):
                        if l + k <= n:
                            all_count += (dp[0][k][l] + dp[1][k][l] + dp[2][k][l] * 24)
                all_count %= mod

        all_count %= mod
        if all_count < 0:
            all_count += mod
        print(all_count)

    @staticmethod
    def pow(a, n, mod):
        ret = 1
        x = 63 - (n.bit_length() - 1)
        for x in range(x, -1, -1):
            ret = ret * ret % mod
            if n << (63 - x) < 0:
                ret = ret * a % mod
        return ret

    @staticmethod
    def invl(a, mod):
        b = mod
        p, q = 1, 0
        while b > 0:
            c = a // b
            a, b = b, a % b
            p, q = q, p - c * q
        return p if p >= 0 else p + mod

    @staticmethod
    def C(n, r, mod, fif):
        if n < 0 or r < 0 or r > n:
            return 0
        return (fif[0][n] * fif[1][r] % mod) * fif[1][n - r] % mod

    @staticmethod
    def enumFIF(n, mod):
        f = [0] * (n + 1)
        invf = [0] * (n + 1)
        f[0] = 1
        for i in range(1, n + 1):
            f[i] = f[i - 1] * i % mod
        a, b = f[n], mod
        p, q = 1, 0
        while b > 0:
            c = a // b
            a, b = b, a % b
            p, q = q, p - c * q
        invf[n] = p if p >= 0 else p + mod
        for i in range(n - 1, -1, -1):
            invf[i] = invf[i + 1] * (i + 1) % mod
        return f, invf

    def run(self):
        self.is = sys.stdin
        self.solve()

    def read_byte(self):
        return self.is.read(1)

    def is_space_char(self, c):
        return not (33 <= c <= 126)

    def skip(self):
        b = self.read_byte()
        while b != b'' and self.is_space_char(ord(b)):
            b = self.read_byte()
        return b

    def nd(self):
        return float(self.ns())

    def nc(self):
        return chr(self.skip())

    def ns(self):
        b = self.skip()
        sb = []
        while not self.is_space_char(ord(b)):
            sb.append(b)
            b = self.read_byte()
        return ''.join(sb)

    def na(self, n):
        return [self.ni() for _ in range(n)]

    def ni(self):
        return int(self.nl())

    def nl(self):
        num = 0
        b = self.read_byte()
        minus = False
        while b != b'' and not (b'0' <= b <= b'9' or b == b'-'):
            b = self.read_byte()
        if b == b'-':
            minus = True
            b = self.read_byte()

        while True:
            if b'0' <= b <= b'9':
                num = num * 10 + (ord(b) - ord(b'0'))
            else:
                return -num if minus else num
            b = self.read_byte()

if __name__ == "__main__":
    G3().run()
