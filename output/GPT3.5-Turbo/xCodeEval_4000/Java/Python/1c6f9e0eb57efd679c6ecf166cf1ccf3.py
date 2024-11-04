import sys
from typing import List

class FastWriter:
    def __init__(self, out=sys.stdout):
        self.out = out
        self.buf = []
    
    def write(self, s):
        self.buf.append(str(s))
    
    def writeln(self, s=''):
        self.buf.append(str(s) + '\n')
    
    def flush(self):
        self.out.write(''.join(self.buf))
        self.out.flush()

class F2:
    def __init__(self):
        self.INPUT = ''
        self.ispace = 0
        self.is = sys.stdin
        self.out = FastWriter()
    
    def solve(self):
        n, m = self.ni(), self.ni()
        ss = [list(self.ns()) for _ in range(n)]
        oss = [''.join(s) for s in ss]
        offset = [0] * (n+1)
        offset[0] = 1
        for i in range(n):
            offset[i+1] = offset[i] + len(ss[i]) - 1
        U = offset[n] - 1

        D = 5
        M = [[0] * ((U+1)*D) for _ in range((U+1)*D)]

        for i in range(U+1):
            lb, of = 0, 0
            if i != 0:
                lb = self.lowerBound(offset, i+1) - 1
                of = i - offset[lb] + 1

            if i == 0:
                for j in range(n):
                    for k in range(n):
                        if k != j and oss[k].startswith(oss[j]):
                            M[offset[k]+len(ss[j])-1][0+(U+1)*(len(ss[j])-1)] = 1
                    M[0][0+(U+1)*(len(ss[j])-1)] += 1
            else:
                for j in range(n):
                    if oss[lb][of:] == oss[j]:
                        M[0][i+(U+1)*(len(oss[j])-1)] += 2
                    elif oss[lb][of:].startswith(oss[j]):
                        M[i+len(oss[j])][i+(U+1)*(len(oss[j])-1)] += 1

                suf = oss[lb][of:]
                for j in range(n):
                    if oss[j].startswith(suf) and oss[j] != suf:
                        M[offset[j]+len(suf)-1][i+(U+1)*(len(suf)-1)] += 1

        for i in range(U+1):
            for j in range(D-1):
                M[i+(U+1)*(j+1)][i+(U+1)*j] = 1

        v = [0] * ((U+1)*D)
        v[0] = 1
        v = self.pow(M, v, m)

        self.out.writeln(v[0])

    @staticmethod
    def mod():
        return 998244353
    
    @staticmethod
    def pow(A, v, e):
        for i in range(len(v)):
            if v[i] >= F2.mod():
                v[i] %= F2.mod()
        MUL = A
        while e > 0:
            if e & 1:
                v = F2.mul(MUL, v)
            MUL = F2.p2(MUL)
            e >>= 1
        return v
    
    @staticmethod
    def mul(A, v):
        m = len(A)
        n = len(v)
        w = [0] * m
        for i in range(m):
            s = 0
            for k in range(n):
                s += A[i][k] * v[k]
                if s >= F2.BIG():
                    s -= F2.BIG()
            w[i] = s % F2.mod()
        return w
    
    @staticmethod
    def p2(A):
        n = len(A)
        C = [[0] * n for _ in range(n)]
        for i in range(n):
            sum_ = [0] * n
            for k in range(n):
                for j in range(n):
                    sum_[j] += A[i][k] * A[k][j]
                    if sum_[j] >= F2.BIG():
                        sum_[j] -= F2.BIG()
            for j in range(n):
                C[i][j] = sum_[j] % F2.mod()
        return C
    
    @staticmethod
    def lowerBound(a, v):
        l, r = 0, len(a)
        while r - l > 1:
            h = (r + l) // 2
            if a[h] >= v:
                r = h
            else:
                l = h
        return r
    
    def run(self):
        s = 0
        self.solve()
        self.out.flush()
    
    def main(self):
        self.run()
    
    def readByte(self):
        if self.ispace == 0:
            self.ispace = 1024
            self.inbuf = self.is.read(1024)
            if len(self.inbuf) == 0:
                return -1
        self.ispace -= 1
        return self.inbuf[self.ispace]
    
    def isSpaceChar(self, c):
        return not (c >= 33 and c <= 126)
    
    def skip(self):
        b = self.readByte()
        while b != -1 and self.isSpaceChar(b):
            b = self.readByte()
        return b
    
    def nd(self):
        return float(self.ns())
    
    def nc(self):
        return chr(self.skip())
    
    def ns(self):
        b = self.skip()
        sb = []
        while not self.isSpaceChar(b):
            sb.append(chr(b))
            b = self.readByte()
        return ''.join(sb)
    
    def ns(self, n):
        buf = [0] * n
        b = self.skip()
        p = 0
        while p < n and not self.isSpaceChar(b):
            buf[p] = chr(b)
            p += 1
            b = self.readByte()
        return buf if n == p else buf[:p]
    
    def na(self, n):
        a = [0] * n
        for i in range(n):
            a[i] = self.ni()
        return a
    
    def nal(self, n):
        a = [0] * n
        for i in range(n):
            a[i] = self.nl()
        return a
    
    def nm(self, n, m):
        map_ = [0] * n
        for i in range(n):
            map_[i] = self.ns(m)
        return map_
    
    def nmi(self, n, m):
        map_ = [0] * n
        for i in range(n):
            map_[i] = self.na(m)
        return map_
    
    def ni(self):
        return int(self.nl())
    
    def nl(self):
        num = 0
        b = self.readByte()
        minus = False
        while b != -1 and not ((b >= 48 and b <= 57) or b == 45):
            b = self.readByte()
        if b == 45:
            minus = True
            b = self.readByte()
        while True:
            if b >= 48 and b <= 57:
                num = num * 10 + (b - 48)
            else:
                return -num if minus else num
            b = self.readByte()

    def tr(self, *o):
        if not self.oj:
            print(*o)

    def trnz(self, *o):
        for i in range(len(o)):
            if o[i] != 0:
                print(i, ':', o[i], end=' ')
        print()

    def trt(self, *o):
        stands = []
        for i in range(len(o)):
            for x in range(64):
                if o[i] & (1 << x):
                    stands.append(i << 6 | x)
        print(stands)

    def tf(self, *r):
        for x in r:
            print('#' if x else '.', end='')
        print()

    def tf(self, *r):
        for x in r:
            self.tf(x)
        print()

    def tf(self, *b):
        for r in b:
            for x in r:
                self.tf(x)
            print()

    def tf(self, *b):
        for x in b:
            self.tf(x)
        print()

    def tf(self, *b):
        if len(self.INPUT) != 0:
            for x in b:
                self.tf(x)
            print()

    def BIG(self):
        return 8 * self.m2()

    def m2(self):
        return self.mod() * self.mod()

    def mod(self):
        return 998244353

    def lowerBound(self, a, v):
        return self.lowerBound(a, 0, len(a), v)

    def lowerBound(self, a, l, r, v):
        low, high = l-1, r
        while high - low > 1:
            h = (high + low) >> 1
            if a[h] >= v:
                high = h
            else:
                low = h
        return high

    def pow(self, A, v, e):
        for i in range(len(v)):
            if v[i] >= self.mod():
                v[i] %= self.mod()
        MUL = A
        while e > 0:
            if e & 1:
                v = self.mul(MUL, v)
            MUL = self.p2(MUL)
            e >>= 1
        return v

    def mul(self, A, v):
        m = len(A)
        n = len(v)
        w = [0] * m
        for i in range(m):
            s = 0
            for k in range(n):
                s += A[i][k] * v[k]
                if s >= self.BIG():
                    s -= self.BIG()
            w[i] = s % self.mod()
        return w

    def p2(self, A):
        n = len(A)
        C = [[0] * n for _ in range(n)]
        for i in range(n):
            sum_ = [0] * n
            for k in range(n):
                for j in range(n):
                    sum_[j] += A[i][k] * A[k][j]
                    if sum_[j] >= self.BIG():
                        sum_[j] -= self.BIG()
            for j in range(n):
                C[i][j] = sum_[j] % self.mod()
        return C

    def main(self):
        self.run()

    def run(self):
        self.is = sys.stdin
        self.out = FastWriter(sys.stdout)
        self.solve()
        self.out.flush()

if __name__ == '__main__':
    F2().main()
