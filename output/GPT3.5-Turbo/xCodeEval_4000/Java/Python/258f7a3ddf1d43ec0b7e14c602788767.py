import sys
from collections import defaultdict

class FastScanner:
    def __init__(self):
        self.input_buffer = []
        self.ptr = 0
        self.buflen = 0
        self.sin = sys.stdin

    def hasNextByte(self):
        if self.ptr < self.buflen:
            return True
        else:
            self.ptr = 0
            self.buflen = self.sin.readinto(self.input_buffer)
            if self.buflen <= 0:
                return False
        return True

    def readByte(self):
        if self.hasNextByte():
            result = self.input_buffer[self.ptr]
            self.ptr += 1
            return result
        else:
            return -1

    def isPrintableChar(self, c):
        return 33 <= c and c <= 126

    def hasNext(self):
        while self.hasNextByte() and not self.isPrintableChar(self.input_buffer[self.ptr]):
            self.ptr += 1
        return self.hasNextByte()

    def next(self):
        if not self.hasNext():
            raise ValueError("No more tokens are available.")
        sb = []
        b = self.readByte()
        while self.isPrintableChar(b):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)

    def longNext(self):
        if not self.hasNext():
            raise ValueError("No more tokens are available.")
        n = 0
        minus = False
        b = self.readByte()
        if b == ord("-"):
            minus = True
            b = self.readByte()
        if b < ord("0") or ord("9") < b:
            raise ValueError("Invalid long value")
        while True:
            if ord("0") <= b and b <= ord("9"):
                n *= 10
                n += b - ord("0")
            elif b == -1 or not self.isPrintableChar(b) or b == ord(":"):
                return -n if minus else n
            else:
                raise ValueError("Invalid long value")
            b = self.readByte()

    def intNext(self):
        nl = self.longNext()
        if nl < -2147483648 or nl > 2147483647:
            raise ValueError("Invalid int value")
        return int(nl)

    def doubleNext(self):
        return float(self.next())

    def nextLongArray(self, n):
        a = []
        for _ in range(n):
            a.append(self.longNext())
        return a

    def nextIntArray(self, n):
        a = []
        for _ in range(n):
            a.append(self.intNext())
        return a

    def nextDoubleArray(self, n):
        a = []
        for _ in range(n):
            a.append(self.doubleNext())
        return a

class FastWriter:
    def __init__(self):
        self.out = []
        self.IO_BUFFERS = 128 * 1024

    def p(self, obj):
        self.out.append(str(obj))

    def pp(self, *args):
        for ob in args:
            self.out.append(str(ob))
            self.out.append(" ")
        self.out.append("\n")

    def println(self, arr):
        for e in arr:
            self.out.append(str(e))
            self.out.append(" ")
        self.out.append("\n")

    def toFile(self, fileName):
        with open(fileName, "w") as f:
            f.write("".join(self.out))

    def close(self):
        sys.stdout.write("".join(self.out))

class F:
    def __init__(self):
        self.n = 0
        self.m = 0
        self.arr = []
        self.required = 0
        self.typeDays = defaultdict(set)

    def solver(self):
        self.n = in.intNext()
        self.m = in.intNext()
        self.arr = in.nextIntArray(self.n)
        self.required = sum(self.arr)
        for _ in range(self.m):
            d = in.intNext()
            typ = in.intNext()
            if self.arr[typ - 1] <= 0:
                continue
            self.typeDays[typ].add(d)

        lo = self.required
        hi = 2 * self.required
        valid = hi
        while lo <= hi:
            mid = (lo + hi) // 2
            if self.isEnough(mid):
                valid = mid
                hi = mid - 1
            else:
                lo = mid + 1
        out.println(valid)

    def isEnough(self, day):
        totalCoin = day
        req = self.required

        ddays = [0] * (day + 1)
        for typ in self.typeDays.keys():
            lastDay = max(filter(lambda x: x <= day, self.typeDays[typ]), default=None)
            if lastDay is None:
                continue
            ddays[lastDay] += self.arr[typ - 1]

        removed = 0
        for i in range(1, day + 1):
            coins = i - removed
            toRemove = min(coins, ddays[i])
            removed += toRemove
            totalCoin -= toRemove
            req -= toRemove

        return req * 2 <= totalCoin

out = FastWriter()
in = FastScanner()
f = F()
f.solver()
out.close()
