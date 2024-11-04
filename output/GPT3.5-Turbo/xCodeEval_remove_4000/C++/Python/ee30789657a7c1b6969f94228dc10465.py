import sys
from typing import List, Tuple

MOD = 10**9 + 7

class FastIO:
    def __init__(self):
        self.rdata = sys.stdin.buffer.read()
        self.rb = 0
        self.wb = 0
        self.tmp_s = bytearray(20)
    
    def read_i(self) -> int:
        neg = False
        x = 0
        while self.rb < len(self.rdata) and (self.rdata[self.rb] < ord('0') or self.rdata[self.rb] > ord('9')) and self.rdata[self.rb] != ord('-'):
            self.rb += 1
        if self.rb < len(self.rdata) and self.rdata[self.rb] == ord('-'):
            neg = True
            self.rb += 1
        while self.rb < len(self.rdata) and ord('0') <= self.rdata[self.rb] <= ord('9'):
            x = 10 * x + (self.rdata[self.rb] - ord('0'))
            self.rb += 1
        if neg:
            x = -x
        return x

    def id0(self, x: int) -> None:
        if x == 0:
            sys.stdout.buffer.write(b'0\n')
            return
        if x < 0:
            sys.stdout.buffer.write(b'-')
            x = -x
        t = self.tmp_s
        while x:
            y = x // 10
            t.append((x - y * 10) + ord('0'))
            x = y
        while t:
            sys.stdout.buffer.write(bytes((t.pop(),)))
        sys.stdout.buffer.write(b'\n')

io = FastIO()

class IO:
    buf_size = 1 << 18
    buf_in = bytearray(buf_size)
    buf_out = bytearray(buf_size)
    pt_in = 0
    pt_out = 0
    tail_in = 0
    strs = bytearray(10000 * 4)

    def num_digits(self, x: int) -> int:
        if x >= 10**9:
            if x >= 10**18:
                return 19
            if x >= 10**17:
                return 18
            if x >= 10**16:
                return 17
            if x >= 10**15:
                return 16
            if x >= 10**14:
                return 15
            if x >= 10**13:
                return 14
            if x >= 10**12:
                return 13
            if x >= 10**11:
                return 12
            if x >= 10**10:
                return 11
            return 10
        else:
            if x >= 10**8:
                return 9
            if x >= 10**7:
                return 8
            if x >= 10**6:
                return 7
            if x >= 10**5:
                return 6
            if x >= 10**4:
                return 5
            if x >= 10**3:
                return 4
            if x >= 10**2:
                return 3
            if x >= 10**1:
                return 2
            return 1

    def __init__(self):
        self.load()
        for i in range(10000):
            j = i
            for t in range(3, -1, -1):
                self.strs[i * 4 + t] = j % 10 + ord('0')
                j //= 10

    def __del__(self):
        self.flush()

    def load(self) -> None:
        self.buf_in[:self.tail_in - self.pt_in] = self.buf_in[self.pt_in:self.tail_in]
        width = self.tail_in - self.pt_in
        self.tail_in = width + sys.stdin.buffer.readinto(self.buf_in, self.buf_size - width)
        self.pt_in = 0

    def flush(self) -> None:
        sys.stdout.buffer.write(self.buf_out[:self.pt_out])
        self.pt_out = 0

    def read(self) -> int:
        c = self.buf_in[self.pt_in]
        self.pt_in += 1
        return c

    def write(self, c: int) -> None:
        self.buf_out[self.pt_out] = c
        self.pt_out += 1

    def write_str(self, s: str) -> None:
        for c in s:
            self.write(ord(c))

    def write_ln(self, x: int) -> None:
        self.write_str(str(x))
        self.write(ord('\n'))

io2 = IO()

def solve() -> None:
    t = io.read_i()

    dp = [[[0] * 2 for _ in range(2)] for _ in range(61)]
    dp[0][0][0] = 1
    for i in range(60):
        f2 = (t >> i) & 1
        if f2:
            dp[i + 1][0][0] += dp[i][0][0]
            dp[i + 1][1][0] += dp[i][0][0]
            dp[i + 1][0][1] += dp[i][0][0]
            dp[i + 1][1][1] += dp[i][0][0]
            dp[i + 1][0][1] += dp[i][0][1]
            dp[i + 1][1][1] += dp[i][0][1]
            dp[i + 1][0][0] += dp[i][0][1]
            dp[i + 1][1][0] += dp[i][0][1]
            dp[i + 1][1][0] += dp[i][1][0]
            dp[i + 1][0][1] += dp[i][1][0]
            dp[i + 1][1][1] += dp[i][1][0]
            dp[i + 1][0][0] += dp[i][1][0]
            dp[i + 1][1][1] += dp[i][1][1]
            dp[i + 1][0][0] += dp[i][1][1]
            dp[i + 1][1][0] += dp[i][1][1]
            dp[i + 1][0][1] += dp[i][1][1]
        else:
            dp[i + 1][0][0] += dp[i][0][0]
            dp[i + 1][1][0] += dp[i][0][0]
            dp[i + 1][0][1] += dp[i][0][0]
            dp[i + 1][1][1] += dp[i][0][0]
            dp[i + 1][0][1] += dp[i][0][1]
            dp[i + 1][1][1] += dp[i][0][1]
            dp[i + 1][0][0] += dp[i][0][1]
            dp[i + 1][1][0] += dp[i][0][1]
            dp[i + 1][1][0] += dp[i][1][0]
            dp[i + 1][0][1] += dp[i][1][0]
            dp[i + 1][1][1] += dp[i][1][0]
            dp[i + 1][0][0] += dp[i][1][0]
            dp[i + 1][1][1] += dp[i][1][1]
            dp[i + 1][0][0] += dp[i][1][1]
            dp[i + 1][1][0] += dp[i][1][1]
            dp[i + 1][0][1] += dp[i][1][1]
        for j in range(2):
            for k in range(2):
                for l in range(2):
                    dp[i + 1][j][k][l] %= MOD

    io2.write_ln(dp[60][0][0][0])

q = io.read_i()
for _ in range(q):
    solve()
