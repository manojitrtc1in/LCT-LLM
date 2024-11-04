from collections import defaultdict
from itertools import accumulate
import sys

def is_whitespace(c):
    return c in (' ', '\n', '\r', '\t') or c == EOF

class Input:
    def __init__(self, stream):
        self.stream = stream
        self.exhausted = False

    def get(self):
        if self.exhausted:
            raise EOFError("Input exhausted")
        c = self.stream.read(1)
        if c == '':
            self.exhausted = True
            return EOF
        return c

    def skip_whitespace(self):
        while True:
            c = self.stream.peek(1)
            if is_whitespace(c) and c != EOF:
                self.get()
            else:
                break

    def read_int(self):
        self.skip_whitespace()
        c = self.get()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.get()
        res = 0
        while c.isdigit():
            res = res * 10 + int(c)
            c = self.get()
        return res * sgn

    def read_int_array(self, size):
        return [self.read_int() for _ in range(size)]

class Output:
    def __init__(self, stream):
        self.stream = stream

    def print(self, *args):
        self.stream.write(' '.join(map(str, args)))

    def print_line(self, *args):
        self.print(*args)
        self.stream.write('\n')

def primality_table(n):
    res = [True] * n
    if n > 0:
        res[0] = False
    if n > 1:
        res[1] = False
    for i in range(2, int(n**0.5) + 1):
        if res[i]:
            for j in range(i * i, n, i):
                res[j] = False
    return res

def divisor_table(n):
    res = [0] * n
    if n > 1:
        res[1] = 1
    for i in range(2, n):
        if res[i] == 0:
            res[i] = i
            for j in range(i * i, n, i):
                if res[j] == 0:
                    res[j] = i
    return res

def primes(n):
    is_prime = primality_table(n)
    return [i for i in range(n) if is_prime[i]]

class DKhaotichnayaV:
    def solve(self, inp, outp):
        in_stream = Input(inp)
        out_stream = Output(outp)

        n = in_stream.read_int()
        k = in_stream.read_int_array(n)

        p = primes(5000)
        d = divisor_table(5001)
        divisors = [[] for _ in range(5001)]
        for i in range(2, 5001):
            divisors[i] = divisors[i - 1][:]
            if d[i] == i:
                divisors[i].append(1)
            else:
                q = i
                while q > 1:
                    divisors[i][d[q]] += 1
                    q //= d[q]

        answer = 0
        q = [0] * 5001
        for num in k:
            q[num] += 1
        lost = 0
        still = [True] * 5001
        cur = [0] * len(p)

        while True:
            cur = [0] * len(p)
            for i in range(5001):
                if still[i] and divisors[i]:
                    cur[len(divisors[i]) - 1] += q[i]
            pos = cur.index(max(cur))
            if cur[pos] <= n // 2:
                pos = -2
            step = float('inf')
            for i in range(5001):
                if still[i] and len(divisors[i]) - 1 != pos:
                    answer += q[i] * sum(divisors[i])
                    lost += q[i]
                    still[i] = False
                elif still[i]:
                    step = min(step, divisors[i][-1])

            if pos == -2:
                break
            answer += step * lost
            for i in range(5001):
                if still[i]:
                    divisors[i][-1] -= step
                    if divisors[i][-1] == 0:
                        divisors[i].pop()

        out_stream.print_line(answer)

if __name__ == "__main__":
    solver = DKhaotichnayaV()
    solver.solve(sys.stdin, sys.stdout)
