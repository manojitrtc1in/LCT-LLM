import sys
from collections import defaultdict

class FastWriter:
    def __init__(self):
        self.out = []

    def p(self, obj):
        self.out.append(str(obj))
        return self

    def pp(self, *args):
        self.out.append(" ".join(map(str, args)) + "\n")
        return self

    def close(self):
        sys.stdout.write("".join(self.out))

class FastScanner:
    def __init__(self):
        self.buffer = sys.stdin.read().split()
        self.index = 0

    def has_next(self):
        return self.index < len(self.buffer)

    def next(self):
        if not self.has_next():
            raise Exception("No more elements")
        value = self.buffer[self.index]
        self.index += 1
        return value

    def long_next(self):
        return int(self.next())

    def int_next(self):
        return int(self.long_next())

    def next_long_array(self, n):
        return [self.long_next() for _ in range(n)]

def min(a, b):
    return a if a < b else b

class E:
    def solver(self):
        n = in_.int_next()
        ar = in_.next_long_array(3)
        br = in_.next_long_array(3)
        mxWins = 0
        mxLosesOrDraw = 0

        for i in range(3):
            mxWins += min(ar[i], br[(i + 1) % 3])
            mxLose = min(br[i], ar[(i + 1) % 3])
            mxDraw = min(br[i], ar[i])
            mxLosesOrDraw += min(br[i], mxLose + mxDraw)

        out.pp(n - mxLosesOrDraw, mxWins)

if __name__ == "__main__":
    in_ = FastScanner()
    out = FastWriter()
    E().solver()
    out.close()
