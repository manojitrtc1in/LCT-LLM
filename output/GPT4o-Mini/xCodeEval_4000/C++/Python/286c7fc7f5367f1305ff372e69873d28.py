import sys
from collections import defaultdict
from itertools import combinations

class Input:
    def __init__(self):
        self.exhausted = False
        self.buf_size = 4096
        self.buf = sys.stdin.read(self.buf_size)
        self.buf_read = 0
        self.buf_at = 0

    def get(self):
        if self.exhausted:
            return EOF
        if self.buf_read == self.buf_at:
            self.buf = sys.stdin.read(self.buf_size)
            self.buf_read = len(self.buf)
            self.buf_at = 0
        if self.buf_read == self.buf_at:
            self.exhausted = True
            return EOF
        char = self.buf[self.buf_at]
        self.buf_at += 1
        return char

    def skip_whitespace(self):
        while True:
            char = self.get()
            if char == EOF or not char.isspace():
                return char

    def read_int(self):
        char = self.skip_whitespace()
        sgn = 1
        if char == '-':
            sgn = -1
            char = self.get()
        res = 0
        while char.isdigit():
            res = res * 10 + int(char)
            char = self.get()
        return res * sgn

    def read_long_array(self, size):
        return [self.read_int() for _ in range(size)]

in_ = Input()

class Output:
    def __init__(self):
        self.autoflush = False

    def print_line(self, *args):
        print(*args)

out = Output()

def bit_count(x):
    return bin(x).count('1')

class EDerevoDelitelei:
    def solve(self):
        n = in_.read_int()
        a = in_.read_long_array(n)

        a.sort()
        d = [0] * n
        for i in range(n):
            c = a[i]
            for j in range(2, int(c**0.5) + 1):
                while c % j == 0:
                    d[i] += 1
                    c //= j
            if c != 1:
                d[i] += 1

        infty = float('inf')
        reachable = [infty] * (1 << n)
        reachable[0] = 0

        for i in range(n):
            for j in range(1 << i):
                rem = a[i]
                good = True
                for k in range(i):
                    if (j & (1 << k)) != 0:
                        if rem % a[k] != 0:
                            good = False
                            break
                        rem //= a[k]
                qty = 0
                for c in range(2, int(rem**0.5) + 1):
                    while rem % c == 0:
                        qty += 1
                        rem //= c
                if rem != 1:
                    qty += 1
                lim = 0 if i == 0 else (1 << (i - 1))
                if good:
                    for k in range(1 << i):
                        if (j & k) == 0 and reachable[j + k] != infty and j + k >= lim:
                            reachable[(1 << i) + k] = min(reachable[(1 << i) + k], reachable[j + k] + qty + (0 if d[i] == 1 else 1))

        answer = infty
        for i in range(1 << (n - 1), 1 << n):
            if reachable[i] != infty:
                answer = min(answer, reachable[i] + (0 if bit_count(i) == 1 else 1))

        out.print_line(answer)

def main():
    EDerevoDelitelei().solve()

if __name__ == "__main__":
    main()
