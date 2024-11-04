import sys

class Scanner:
    def __init__(self, fp):
        self.fd = fp.fileno()
        self.line = bytearray()
        self.st = 0
        self.ed = 0
        self.eof = False

    def read(self):
        pass

    def read_single(self, ref):
        if not self.skip_space():
            return False
        ref.clear()
        while True:
            c = self.top()
            if c <= ord(' '):
                break
            ref.append(c)
            self.st += 1
        return True

    def read_single_double(self, ref):
        s = bytearray()
        if not self.read_single(s):
            return False
        ref = float(s)
        return True

    def read_single_int(self, ref):
        if not self.skip_space(50):
            return False
        neg = False
        if self.line[self.st] == ord('-'):
            neg = True
            self.st += 1
        ref = 0
        while self.line[self.st] >= ord('0'):
            ref = 10 * ref + (self.line[self.st] & 0x0f)
            self.st += 1
        if neg:
            ref = -ref
        return True

    def read_single_uint(self, ref):
        if not self.skip_space(50):
            return False
        ref = 0
        while self.line[self.st] >= ord('0'):
            ref = 10 * ref + (self.line[self.st] & 0x0f)
            self.st += 1
        return True

    def top(self):
        if self.st == self.ed:
            self.reread()
        return self.line[self.st]

    def skip_space(self, token_len=0):
        while True:
            while self.st != self.ed and self.line[self.st] <= ord(' '):
                self.st += 1
            if self.ed - self.st > token_len:
                return True
            for i in range(self.st, self.ed):
                if self.line[i] <= ord(' '):
                    return True
            if not self.reread():
                return False

    def reread(self):
        if self.ed - self.st >= 50:
            return True
        if self.st > len(self.line) // 2:
            self.line[:self.ed - self.st] = self.line[self.st:self.ed]
            self.ed -= self.st
            self.st = 0
        if self.eof:
            return False
        u = os.read(self.fd, len(self.line) - self.ed)
        if u == 0:
            self.eof = True
            self.line[self.ed] = ord('\0')
            u = 1
        self.ed += u
        return True

class Printer:
    def __init__(self, fp):
        self.fd = fp.fileno()
        self.line = bytearray()
        self.pos = 0

    def flush(self):
        os.write(self.fd, self.line[:self.pos])
        self.pos = 0

    def write_single(self, val):
        if self.pos == len(self.line):
            self.flush()
        self.line[self.pos] = val
        self.pos += 1

    def write_single_str(self, s):
        for c in s:
            self.write_single(ord(c))

    def write_single_int(self, val):
        if val == 0:
            self.write_single(ord('0'))
            return
        if self.pos > len(self.line) - 50:
            self.flush()
        uval = val
        if val < 0:
            self.write_single(ord('-'))
            uval = -uval
        self.write_unsigned(uval)

    def write_unsigned(self, uval):
        if uval == 0:
            self.write_single(ord('0'))
            return
        if self.pos > len(self.line) - 50:
            self.flush()
        len = self.calc_len(uval)
        self.pos += len
        ptr = self.line[self.pos:]
        while uval >= 100:
            ptr -= 2
            ptr[0:2] = self.small[uval % 100]
            uval //= 100
        if uval >= 10:
            ptr -= 2
            ptr[0:2] = self.small[uval]
        else:
            ptr -= 1
            ptr[0] = ord('0') + uval

    def write_single_list(self, val):
        n = len(val)
        for i in range(n):
            if i:
                self.write_single(ord(' '))
            self.write_single(val[i])

    def calc_len(self, x):
        i = (self.bsr(x) * 3 + 3) // 10
        if x < self.tens[i]:
            return i
        else:
            return i + 1

    def bsr(self, n):
        return 8 * n.bit_length() - 1

    def write(self, *args):
        for x in args:
            self.write_single_str(str(x))

    def writeln(self, *args):
        self.write(*args)
        self.write_single(ord('\n'))

    small = [
        bytearray([ord('0') + i // 10, ord('0') + i % 10])
        for i in range(100)
    ]
    tens = [1] * 20
    for i in range(20):
        for j in range(i):
            tens[i] *= 10

def main():
    n, m, mod = map(int, input().split())
    mint.set_mod(mod)

    C = [[0] * (n + 1) for _ in range(n + 1)]
    C[0][0] = 1
    for i in range(1, n + 1):
        C[i][0] = 1
        for j in range(1, n + 1):
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j]

    g = [0] * (n + 1)
    for i in range(n + 1):
        g[i] = i * (i + 1) // 2

    f = [(0, 0)] * (n + 1)
    f[0] = (1, 0)

    for i in range(1, n + 1):
        for j in range(i):
            z = f[j][0] * f[i - 1 - j][0] * C[i - 1][j]
            f[i] = (f[i][0] + z * (i + 1), f[i][1] + z * (g[j] + g[i - 1 - j]))
            f[i] = (f[i][0], f[i][1] + (f[i - 1 - j][0] * f[j][1] + f[j][0] * f[i - 1 - j][1]) * C[i - 1][j] * (i + 1))

    dp = [[(0, 0)] * (m + 1) for _ in range(n + 2)]
    dp[0][0] = (1, 0)
    for l in range(n + 1):
        for r in range(l + 1, n + 2):
            di = r - l - 1
            for i in range(m - di + 1):
                z = dp[l][i][0] * f[di][0]
                dp[r][i + di] = (dp[r][i + di][0] + z * C[i + di][di], dp[r][i + di][1] + (dp[l][i][1] * f[di][0] + dp[l][i][0] * f[di][1]) * C[i + di][di])

    pr.writeln(dp[n + 1][m][1])

if __name__ == "__main__":
    main()
