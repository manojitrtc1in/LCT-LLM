import sys
import math
from collections import defaultdict

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
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = bytearray()
        while not self.isSpaceChar(c):
            res.append(c)
            c = self.read()
        return res.decode()

    def nextInt(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < ord('0') or c > ord('9'):
                raise UnknownError()
            res = res * 10 + c - ord('0')
            c = self.read()
        return res * sgn

    def nextLong(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < ord('0') or c > ord('9'):
                raise UnknownError()
            res = res * 10 + c - ord('0')
            c = self.read()
        return res * sgn

    def readString(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = bytearray()
        while not self.isSpaceChar(c):
            res.append(c)
            c = self.read()
        return res.decode()

    def isSpaceChar(self, c):
        return c == ord(' ') or c == ord('\n') or c == ord('\r') or c == ord('\t') or c == -1

    def readLine(self):
        res = bytearray()
        while True:
            c = self.read()
            if c == -1:
                break
            if c == ord('\n'):
                break
            res.append(c)
        return res.decode()

    def readLine(self, ignoreEmptyLines):
        if ignoreEmptyLines:
            return self.readLine()
        else:
            return self.readLine0()

    def readBigInteger(self):
        try:
            return int(self.readString())
        except ValueError:
            raise UnknownError()

    def readCharacter(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        return chr(c)

    def readDouble(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c) and c != ord('.'):
            if c == ord('e') or c == ord('E'):
                return res * math.pow(10, self.nextInt())
            if c < ord('0') or c > ord('9'):
                raise UnknownError()
            res = res * 10 + c - ord('0')
            c = self.read()
        if c == ord('.'):
            c = self.read()
            m = 1
            while not self.isSpaceChar(c):
                if c == ord('e') or c == ord('E'):
                    return res * math.pow(10, self.nextInt())
                if c < ord('0') or c > ord('9'):
                    raise UnknownError()
                m /= 10
                res += (c - ord('0')) * m
                c = self.read()
        return res * sgn

    def isExhausted(self):
        value = self.peek()
        while self.isSpaceChar(value) and value != -1:
            self.read()
            value = self.peek()
        return value == -1

    def readEmptyLine(self):
        self.readLine()

    def nextLine(self):
        return self.readLine()

    def nextLine(self, ignoreEmptyLines):
        return self.readLine(ignoreEmptyLines)

    def nextBigInteger(self):
        return self.readBigInteger()

    def nextCharacter(self):
        return self.readCharacter()

    def nextDouble(self):
        return self.readDouble()

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

class FenwickTree:
    def __init__(self, n):
        self.tree = [0] * (n + 1)
        self.maxVal = n

    def update(self, idx, val):
        idx += 1
        while idx <= self.maxVal:
            self.tree[idx] += val
            idx += (idx & (-idx))

    def read(self, idx):
        idx += 1
        sum = 0
        while idx > 0:
            sum += self.tree[idx]
            idx -= (idx & -idx)
        return sum

    def getMaxVal(self):
        return self.maxVal

    def rangeSum(self, left, right):
        if left > right:
            return 0
        sumLeft = self.read(left - 1)
        sumRight = self.read(right)
        return sumRight - sumLeft

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
    def solve(self, inStream, outStream, testCase):
        m = inStream.nextInt()
        h1 = inStream.nextInt()
        a1 = inStream.nextInt()
        x1 = inStream.nextInt()
        y1 = inStream.nextInt()

        h2 = inStream.nextInt()
        a2 = inStream.nextInt()
        x2 = inStream.nextInt()
        y2 = inStream.nextInt()

        zone = 1
        r1, mu1 = self.cycleFinding(h1)
        zone = 2
        r2, mu2 = self.cycleFinding(h2)

        can = True

        zone = 1
        len1 = 0
        while h1 != a1:
            h1 = self.f(h1)
            len1 += 1
            if len1 > m:
                can = False
                break

        zone = 2
        len2 = 0
        while h2 != a2:
            h2 = self.f(h2)
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
            outStream.println(ans)
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
                    outStream.println(r1 * k + len1)
                    return
        outStream.println(-1)

    def cycleFinding(self, a):
        mu = 0
        lamb = 1

        turtle = self.f(a)
        hare = self.f(self.f(a))
        while turtle != hare:
            turtle = self.f(turtle)
            hare = self.f(self.f(hare))
        mu = 0
        turtle = a
        while turtle != hare:
            turtle = self.f(turtle)
            hare = self.f(hare)
            mu += 1
        lamb = 1

        hare = self.f(turtle)
        while turtle != hare:
            hare = self.f(hare)
            lamb += 1
        return PairInt(mu, lamb)

    def f(self, h):
        if zone == 1:
            return (x1 * h + y1) % m
        else:
            return (x2 * h + y2) % m

    def GCD(self, a, b):
        return b if a == 0 else self.GCD(b % a, a)

class Solution:
    def main(self):
        inStream = MyInput(sys.stdin.buffer)
        outStream = sys.stdout.buffer
        solver = Solver()

        test = 1
        try:
            while True:
                solver.solve(inStream, outStream, test)
                outStream.flush()
                test += 1
        except UnknownError:
            outStream.flush()
            outStream.close()

        outStream.flush()
        outStream.close()

Solution().main()
