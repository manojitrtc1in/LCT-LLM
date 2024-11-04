import sys
import math
from collections import defaultdict
import random

class MyInput:
    def __init__(self, input_stream):
        self.br = input_stream
        self.st = None

    def next(self):
        if self.st is None or not self.st:
            line = self.br.readline()
            if line == '':
                raise Exception("UnknownError")
            while line.strip() == '':
                line = self.br.readline()
                if line == '':
                    raise Exception("UnknownError")
            self.st = line.split()
        return self.st.pop(0)

    def next_int(self):
        return int(self.next())

class PairInt:
    def __init__(self, X, Y):
        self.X = X
        self.Y = Y

    def add(self, b):
        return PairInt(self.X + b.X, self.Y + b.Y)

    def sub(self, b):
        return PairInt(self.X - b.X, self.Y - b.Y)

class MyMath:
    @staticmethod
    def sieve(n):
        pr = [1] * (n + 1)
        prime = []
        pr[0] = pr[1] = 0
        for i in range(2, n + 1):
            if pr[i] == 1:
                prime.append(i)
                if i * i <= n:
                    for j in range(i * i, n + 1, i):
                        pr[j] = 0
        return prime

    @staticmethod
    def GCD(a, b):
        return b if a == 0 else MyMath.GCD(b % a, a)

    @staticmethod
    def add(a, b, MOD):
        return (a + b) % MOD

    @staticmethod
    def mul(a, b, MOD):
        return (a * b) % MOD

class Solver:
    def __init__(self):
        self.zone = 0
        self.x1 = self.y1 = self.x2 = self.y2 = 0
        self.m = 0

    def solve(self, in_stream, out_stream, test_case):
        self.m = in_stream.next_int()
        h1 = in_stream.next_int()
        a1 = in_stream.next_int()
        self.x1 = in_stream.next_int()
        self.y1 = in_stream.next_int()

        h2 = in_stream.next_int()
        a2 = in_stream.next_int()
        self.x2 = in_stream.next_int()
        self.y2 = in_stream.next_int()

        r1 = self.cycle_finding(h1).Y
        mu1 = self.cycle_finding(h1).X

        r2 = self.cycle_finding(h2).Y
        mu2 = self.cycle_finding(h2).X

        can = True

        len1 = 0
        while h1 != a1:
            h1 = self.f(h1)
            len1 += 1
            if len1 > self.m:
                can = False
                break

        len2 = 0
        while h2 != a2:
            h2 = self.f(h2)
            len2 += 1
            if len2 > self.m:
                can = False
                break

        ans = -2
        if mu1 > len1:
            if mu2 > len2:
                if len1 == len2:
                    ans = len1
                else:
                    can = False
            else:
                temp = len1 - len2
                if temp % r2 == 0 and temp >= 0:
                    ans = len1
                else:
                    can = False
        else:
            if mu2 > len2:
                temp = len2 - len1
                if temp % r1 == 0 and temp >= 0:
                    ans = len2
                else:
                    can = False

        if ans != -2:
            out_stream.write(f"{ans}\n")
            return

        M = len2 - len1
        gcd = MyMath.GCD(r1, r2)
        if M % gcd != 0:
            can = False

        if can:
            for k in range(0, sys.maxsize):
                kPrim = (r1 * k - M) // r2
                if kPrim < 0:
                    continue
                if r1 * k - r2 * kPrim == M:
                    out_stream.write(f"{r1 * k + len1}\n")
                    return

        out_stream.write("-1\n")

    def cycle_finding(self, a):
        mu = 0
        lambda_ = 0

        turtle = self.f(a)
        hare = self.f(turtle)
        while turtle != hare:
            turtle = self.f(turtle)
            hare = self.f(self.f(hare))

        mu = 0
        turtle = a
        while turtle != hare:
            turtle = self.f(turtle)
            hare = self.f(hare)
            mu += 1

        lambda_ = 1
        hare = self.f(turtle)
        while turtle != hare:
            hare = self.f(hare)
            lambda_ += 1

        return PairInt(mu, lambda_)

    def f(self, h):
        if self.zone == 1:
            return MyMath.add(MyMath.mul(self.x1, h, self.m), self.y1, self.m)
        else:
            return MyMath.add(MyMath.mul(self.x2, h, self.m), self.y2, self.m)

def main():
    in_stream = MyInput(sys.stdin)
    out_stream = sys.stdout
    solver = Solver()

    test = 1
    while True:
        try:
            solver.solve(in_stream, out_stream, test)
            test += 1
        except Exception:
            out_stream.flush()
            break

if __name__ == "__main__":
    main()