import sys
from collections import defaultdict
import random

class FastWriter:
    def __init__(self):
        self.out = []

    def p(self, object):
        self.out.append(str(object))
        return self

    def pp(self, *args):
        self.out.append(" ".join(map(str, args)) + "\n")
        return self

    def close(self):
        sys.stdout.write("".join(self.out))

class FastScanner:
    def __init__(self):
        self.buffer = sys.stdin.read().split()
        self.ptr = 0

    def has_next(self):
        return self.ptr < len(self.buffer)

    def next(self):
        if not self.has_next():
            raise Exception("No more elements")
        result = self.buffer[self.ptr]
        self.ptr += 1
        return result

    def long_next(self):
        return int(self.next())

    def id23(self, n):
        return [self.long_next() for _ in range(n)]

def min(a, b):
    return a if a < b else b

class E:
    def solver(self):
        n = in_.long_next()
        ar = in_.id23(3)
        br = in_.id23(3)
        mxWins = 0
        id19 = 0
        draws = 0

        for i in range(3):
            mxWins += min(ar[i], br[(i + 1) % 3])
            mxLose = min(br[i], ar[(i + 1) % 3])
            mxDraw = min(br[i], ar[i])
            id19 += min(br[i], mxLose + mxDraw)

        out.pp(n - id19, mxWins)

if __name__ == "__main__":
    in_ = FastScanner()
    out = FastWriter()
    E().solver()
    out.close()
