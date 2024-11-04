import sys
import math
import itertools
from collections import defaultdict, Counter
from typing import List, Tuple, Dict, Any


class MyInput:
    def __init__(self, stream):
        self.stream = stream
        self.buf = bytearray()
        self.curChar = 0
        self.numChars = 0

    def read(self):
        if self.numChars == -1:
            raise UnknownError()
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.readinto(self.buf)
            if self.numChars <= 0:
                return -1
        c = self.buf[self.curChar]
        self.curChar += 1
        return c

    def hasNext(self):
        return self.peek() != -1

    def peek(self):
        if self.numChars == -1:
            return -1
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.readinto(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def next(self):
        if not self.hasNext():
            raise UnknownError()
        sb = bytearray()
        c = self.read()
        while not self.id4(c):
            sb.append(c)
            c = self.read()
        return sb.decode()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def readString(self):
        return self.next()

    def readLine(self):
        sb = bytearray()
        c = self.read()
        while c != ord('\n') and c != -1:
            if c != ord('\r'):
                sb.append(c)
            c = self.read()
        return sb.decode()

    def id12(self):
        self.readLine()

    def id4(self, c):
        return c == ord(' ') or c == ord('\n') or c == ord('\r') or c == ord('\t') or c == -1


class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def setX(self, a):
        self.a = a

    def setY(self, b):
        self.b = b

    def getX(self):
        return self.a

    def getY(self):
        return self.b

    def __str__(self):
        return "(" + str(self.a) + ", " + str(self.b) + ")"

    def __lt__(self, other):
        if self.a != other.a:
            return self.a < other.a
        return self.b < other.b


class PairInt:
    def __init__(self, X, Y):
        self.X = X
        self.Y = Y

    def add(self, b):
        return PairInt(self.X + b.X, self.Y + b.Y)

    def sub(self, b):
        return PairInt(self.X - b.X, self.Y - b.Y)

    def __lt__(self, other):
        if self.X != other.X:
            return self.X < other.X
        return self.Y < other.Y


class Solver:
    def solve(self, in_stream, out_stream):
        m = in_stream.nextInt()
        h1 = in_stream.nextInt()
        a1 = in_stream.nextInt()
        x1 = in_stream.nextInt()
        y1 = in_stream.nextInt()

        h2 = in_stream.nextInt()
        a2 = in_stream.nextInt()
        x2 = in_stream.nextInt()
        y2 = in_stream.nextInt()

        zone = 1
        r1, mu1 = self.cycleFinding(h1, x1, y1, m)
        zone = 2
        r2, mu2 = self.cycleFinding(h2, x2, y2, m)

        can = True

        zone = 1
        len1 = 0
        while h1 != a1:
            h1 = self.f(h1, x1, y1, m)
            len1 += 1
            if len1 > m:
                can = False
                break

        zone = 2
        len2 = 0
        while h2 != a2:
            h2 = self.f(h2, x2, y2, m)
            len2 += 1
            if len2 > m:
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
            out_stream.println(ans)
            return

        M = len2 - len1
        gcd = self.GCD(r1, r2)
        if M % gcd != 0:
            can = False

        if can:
            k = 0
            while True:
                kPrim = ((r1 * k - M) // r2)
                if kPrim < 0:
                    continue
                if r1 * k - r2 * kPrim == M:
                    out_stream.println(r1 * k + len1)
                    return
        out_stream.println(-1)

    def cycleFinding(self, a, x, y, m):
        mu = 0
        lambd = 1

        turtle = self.f(a, x, y, m)
        hare = self.f(turtle, x, y, m)
        while turtle != hare:
            turtle = self.f(turtle, x, y, m)
            hare = self.f(self.f(hare, x, y, m), x, y, m)
        mu = 0
        turtle = a
        while turtle != hare:
            turtle = self.f(turtle, x, y, m)
            hare = self.f(hare, x, y, m)
            mu += 1
        lambd = 1

        hare = self.f(turtle, x, y, m)
        while turtle != hare:
            hare = self.f(hare, x, y, m)
            lambd += 1
        return PairInt(mu, lambd)

    def f(self, h, x, y, m):
        if zone == 1:
            return (x * h + y) % m
        else:
            return (x * h + y) % m

    def GCD(self, a, b):
        return b if a == 0 else self.GCD(b % a, a)


class Solution:
    def main(self):
        in_stream = MyInput(sys.stdin.buffer)
        out_stream = sys.stdout
        solver = Solver()

        test = 1
        try:
            while True:
                solver.solve(in_stream, out_stream)
                out_stream.flush()
                test += 1
        except UnknownError:
            out_stream.flush()
            out_stream.close()


if __name__ == "__main__":
    Solution().main()
