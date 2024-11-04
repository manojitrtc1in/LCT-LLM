import sys
from typing import List

class FastScanner:
    def __init__(self):
        self.sin = sys.stdin.buffer
        self.buffer = bytearray()
        self.ptr = 0
        self.buflen = 0

    def id22(self):
        if self.ptr < self.buflen:
            return True
        else:
            self.ptr = 0
            self.buffer = self.sin.read(1024)
            self.buflen = len(self.buffer)
            if self.buflen <= 0:
                return False
        return True

    def read_byte(self):
        if self.id22():
            self.ptr += 1
            return self.buffer[self.ptr - 1]
        else:
            return -1

    def id24(self, c):
        return 33 <= c <= 126

    def hasNext(self):
        while self.id22() and not self.id24(self.buffer[self.ptr]):
            self.ptr += 1
        return self.id22()

    def next(self):
        if not self.hasNext():
            raise StopIteration()
        sb = bytearray()
        b = self.read_byte()
        while self.id24(b):
            sb.append(b)
            b = self.read_byte()
        return sb.decode()

    def longNext(self):
        if not self.hasNext():
            raise StopIteration()
        n = 0
        minus = False
        b = self.read_byte()
        if b == ord('-'):
            minus = True
            b = self.read_byte()
        if b < ord('0') or b > ord('9'):
            raise ValueError()
        while True:
            if ord('0') <= b and b <= ord('9'):
                n *= 10
                n += b - ord('0')
            elif b == -1 or not self.id24(b) or b == ord(':'):
                return -n if minus else n
            else:
                raise ValueError()
            b = self.read_byte()

    def intNext(self):
        nl = self.longNext()
        if nl < -2147483648 or nl > 2147483647:
            raise ValueError()
        return int(nl)

    def doubleNext(self):
        return float(self.next())

    def id23(self, n):
        a = []
        for _ in range(n):
            a.append(self.longNext())
        return a

    def id12(self, n):
        a = []
        for _ in range(n):
            a.append(self.intNext())
        return a

    def id21(self, n):
        a = []
        for _ in range(n):
            a.append(self.doubleNext())
        return a

    def getAdj(self, n):
        adj = [[] for _ in range(n + 1)]
        return adj

    def id7(self, nodes, edges, isDirected=False):
        adj = self.getAdj(nodes)
        for _ in range(edges):
            a = self.intNext()
            b = self.intNext()
            adj[a].append(b)
            if not isDirected:
                adj[b].append(a)
        return adj

class FastWriter:
    def __init__(self):
        self.out = []

    def p(self, object):
        self.out.append(str(object))

    def pp(self, *args):
        for ob in args:
            self.out.append(str(ob))
            self.out.append(' ')
        self.out.append('\n')

    def println(self, arr):
        for e in arr:
            self.out.append(str(e))
            self.out.append(' ')
        self.out.append('\n')

    def toFile(self, fileName):
        with open(fileName, 'w') as f:
            f.write(''.join(self.out))

    def close(self):
        print(''.join(self.out), end='')

class E:
    def __init__(self):
        self.out = FastWriter()
        self.inp = FastScanner()

    def solver(self):
        n = self.inp.intNext()
        ar = self.inp.id23(3)
        br = self.inp.id23(3)
        mxWins = 0
        id19 = 0
        draws = 0
        for i in range(3):
            mxWins += min(ar[i], br[(i + 1) % 3])
            mxLose = min(br[i], ar[(i + 1) % 3])
            mxDraw = min(br[i], ar[i])
            id19 += min(br[i], mxLose + mxDraw)

        self.out.pp(n - id19, mxWins)

    def main(self):
        self.solver()
        self.out.close()

if __name__ == '__main__':
    e = E()
    e.main()
