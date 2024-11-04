class Modular:
    def __init__(self, m):
        self.m = m

    def getMod(self):
        return self.m

    def valueOf(self, x):
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x, y):
        return self.valueOf(x * y)

    def plus(self, x, y):
        return self.valueOf(x + y)

    def subtract(self, x, y):
        return self.valueOf(x - y)

class IntegerList:
    def __init__(self, cap=0):
        self.size = 0
        self.cap = cap
        self.data = [] if cap == 0 else [0] * cap

    def getData(self):
        return self.data

    def ensureSpace(self, req):
        if req > self.cap:
            while self.cap < req:
                self.cap = max(self.cap + 10, 2 * self.cap)
            self.data = self.data + [0] * (self.cap - len(self.data))

    def checkRange(self, i):
        if i < 0 or i >= self.size:
            raise IndexError("index " + str(i) + " out of range")

    def get(self, i):
        self.checkRange(i)
        return self.data[i]

    def add(self, x):
        self.ensureSpace(self.size + 1)
        self.data[self.size] = x
        self.size += 1

    def addAll(self, x, offset=0, length=None):
        if length is None:
            length = len(x)
        self.ensureSpace(self.size + length)
        self.data[self.size:self.size+length] = x[offset:offset+length]
        self.size += length

    def addAll(self, lst):
        self.addAll(lst.data, 0, lst.size)

    def expandWith(self, x, length):
        self.ensureSpace(self.size + length)
        for i in range(self.size, self.size + length):
            self.data[i] = x
        self.size += length

    def retain(self, n):
        if n < 0:
            raise ValueError()
        if n >= self.size:
            return
        self.size = n

    def set(self, i, x):
        self.checkRange(i)
        self.data[i] = x

    def size(self):
        return self.size

    def toArray(self):
        return self.data[:self.size]

    def clear(self):
        self.size = 0

    def __str__(self):
        return str(self.toArray())

    def __eq__(self, other):
        if not isinstance(other, IntegerList):
            return False
        return self.data[:self.size] == other.data[:other.size]

    def __hash__(self):
        h = 1
        for i in range(self.size):
            h = h * 31 + hash(self.data[i])
        return h

    def clone(self):
        ans = IntegerList()
        ans.addAll(self)
        return ans

class SequenceUtils:
    @staticmethod
    def equal(a, al, ar, b, bl, br):
        if (ar - al) != (br - bl):
            return False
        for i in range(al, ar+1):
            if a[i] != b[i-bl]:
                return False
        return True

class id0:
    def __init__(self, mod, cap=0):
        self.cm = IntegerList(cap + 1)
        self.cn = IntegerList(cap + 1)
        self.seq = IntegerList(cap + 1)
        self.buf = IntegerList(cap + 1)
        self.cn.add(1)

        self.mod = mod
        self.pow = Power(mod)

    def add(self, x):
        x = self.mod.valueOf(x)
        n = self.seq.size()

        self.seq.add(x)
        dn = self.estimateDelta()
        if dn == 0:
            return

        if self.m < 0:
            self.cm.clear()
            self.cm.addAll(self.cn)
            self.dm = dn
            self.m = n

            self.cn.expandWith(0, n + 2)
            return

        ln = self.cn.size() - 1
        length = max(ln, n + 1 - ln)
        self.buf.clear()
        self.buf.addAll(self.cn)
        self.buf.expandWith(0, length + 1)

        factor = self.mod.mul(dn, self.pow.id7(self.dm))

        bufData = self.buf.getData()
        cmData = self.cm.getData()
        for i in range(n - self.m, n - self.m + self.cm.size()):
            bufData[i] = self.mod.subtract(bufData[i], self.mod.mul(factor, cmData[i - (n - self.m)]))

        if self.cn.size() < self.buf.size():
            tmp = self.cm
            self.cm = self.cn
            self.cn = tmp
            self.m = n
            self.dm = dn
        else:
            tmp = self.cn
            self.cn = self.buf
            self.buf = tmp

    def length(self):
        return self.cn.size() - 1

    def __str__(self):
        return str(self.cn)

    def codeAt(self, i):
        return self.mod.valueOf(-self.cn.get(i))

    def estimateDelta(self):
        n = self.seq.size() - 1
        ans = 0
        cnData = self.cn.getData()
        seqData = self.seq.getData()
        for i in range(self.cn.size()):
            ans = self.mod.plus(ans, self.mod.mul(cnData[i], seqData[n - i]))
        return ans

class Buffer:
    def __init__(self, supplier, cleaner, exp=0):
        self.deque = []
        self.supplier = supplier
        self.cleaner = cleaner

    def alloc(self):
        if len(self.deque) == 0:
            return self.supplier()
        else:
            return self.deque.pop(0)

    def release(self, e):
        self.cleaner(e)
        self.deque.append(e)

class FastOutput:
    def __init__(self, os):
        self.cache = []
        self.os = os

    def println(self, c):
        self.cache.append(str(c) + '\n')

    def flush(self):
        self.os.write(''.join(self.cache))
        self.os.flush()
        self.cache = []

    def close(self):
        self.flush()
        self.os.close()

    def __str__(self):
        return ''.join(self.cache)

class id9:
    def __init__(self, coe, mod):
        self.coe = coe
        self.mod = mod
        self.n = coe.size()
        self.pow = Power(mod)
        self.remainder = IntegerList(coe.size())
        self.p = IntegerList(coe.size() + 1)
        for i in range(self.n - 1, -1, -1):
            self.p.add(mod.valueOf(-self.coe.get(i)))
        self.p.add(1)

    @staticmethod
    def id6(coe, mod):
        return id9(coe, mod)

    @staticmethod
    def id2(seq, mod):
        id10 = id0(mod, seq.size())
        for i in range(seq.size()):
            id10.add(seq.get(i))
        coes = IntegerList(id10.length())
        for i in range(1, id10.length() + 1):
            coes.add(id10.codeAt(i))
        return id9.id6(coes, mod)

    def solve(self, a):
        ans = 0
        self.remainder.expandWith(0, self.n)
        for i in range(self.n):
            ans = self.mod.plus(ans, self.mod.mul(self.remainder.get(i), a.get(i)))
        return ans

    def solve(self, k, a):
        if k < a.size():
            return a.get(k)
        Polynomials.module(k, self.p, self.remainder, self.pow)
        return self.solve(a)

class FastInput:
    def __init__(self, is_):
        self.is_ = is_
        self.buf = bytearray()
        self.bufLen = 0
        self.bufOffset = 0
        self.next = 0

    def read(self):
        while self.bufLen == self.bufOffset:
            self.bufOffset = 0
            self.buf = self.is_.read(1 << 13)
            self.bufLen = len(self.buf)
            if self.bufLen == 0:
                return -1
        self.next = self.buf[self.bufOffset]
        self.bufOffset += 1
        return self.next

    def skipBlank(self):
        while self.next >= 0 and self.next <= 32:
            self.next = self.read()

    def readInt(self):
        sign = 1

        self.skipBlank()
        if self.next == ord('+') or self.next == ord('-'):
            sign = 1 if self.next == ord('+') else -1
            self.next = self.read()

        val = 0
        if sign == 1:
            while self.next >= ord('0') and self.next <= ord('9'):
                val = val * 10 + self.next - ord('0')
                self.next = self.read()
        else:
            while self.next >= ord('0') and self.next <= ord('9'):
                val = val * 10 - self.next + ord('0')
                self.next = self.read()

        return val

    def readLong(self):
        sign = 1

        self.skipBlank()
        if self.next == ord('+') or self.next == ord('-'):
            sign = 1 if self.next == ord('+') else -1
            self.next = self.read()

        val = 0
        if sign == 1:
            while self.next >= ord('0') and self.next <= ord('9'):
                val = val * 10 + self.next - ord('0')
                self.next = self.read()
        else:
            while self.next >= ord('0') and self.next <= ord('9'):
                val = val * 10 - self.next + ord('0')
                self.next = self.read()

        return val

class id11:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.g = 0

    def getX(self):
        return self.x

    def id3(self, a, b):
        if a >= b:
            self.g = self.id1(a, b)
        else:
            self.g = self.id1(b, a)
            tmp = self.x
            self.x = self.y
            self.y = tmp
        return self.g

    def id1(self, a, b):
        if b == 0:
            self.x = 1
            self.y = 0
            return a
        g = self.id1(b, a % b)
        n = self.x
        m = self.y
        self.x = m
        self.y = n - m * (a // b)
        return g

class Polynomials:
    @staticmethod
    def rankOf(p):
        r = p.size() - 1
        while r >= 0 and p.get(r) == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def normalize(lst):
        lst.retain(Polynomials.rankOf(lst) + 1)

    @staticmethod
    def mul(a, b, c, mod):
        rA = Polynomials.rankOf(a)
        rB = Polynomials.rankOf(b)
        c.clear()
        c.expandWith(0, rA + rB + 1)
        aData = a.getData()
        bData = b.getData()
        cData = c.getData()
        for i in range(rA + 1):
            for j in range(rB + 1):
                cData[i + j] = mod.plus(cData[i + j], mod.mul(aData[i], bData[j]))

    @staticmethod
    def divide(a, b, c, remainder, pow):
        mod = pow.id4()
        rA = Polynomials.rankOf(a)
        rB = Polynomials.rankOf(b)

        if rA < rB:
            c.clear()
            c.add(0)
            remainder.clear()
            remainder.addAll(a)
            return

        rC = max(0, rA - rB)
        c.clear()
        c.expandWith(0, rC + 1)
        remainder.clear()
        remainder.addAll(a)

        bData = b.getData()
        cData = c.getData()
        rData = remainder.getData()

        if id8.id3(b.get(rB), mod.getMod()) != 1:
            raise ValueError()
        inv = mod.valueOf(id8.getX())
        for i in range(rA, rB - 1, -1):
            if rData[i] == 0:
                continue
            factor = mod.mul(-rData[i], inv)
            cData[i - rB] = mod.valueOf(-factor)
            for k in range(rB + 1):
                rData[k + i - rB] = mod.plus(rData[k + i - rB], mod.mul(factor, bData[k]))

        Polynomials.normalize(remainder)

    @staticmethod
    def module(k, p, remainder, pow):
        rP = Polynomials.rankOf(p)
        if rP == 0:
            remainder.clear()
            remainder.add(0)
            return

        a = listBuffer.alloc()
        c = listBuffer.alloc()

        Polynomials.module(k, a, p, c, remainder, rP, pow)

        listBuffer.release(a)
        listBuffer.release(c)

    @staticmethod
    def module(k, a, b, c, remainder, rb, pow):
        mod = pow.id4()
        if k < rb:
            remainder.clear()
            remainder.expandWith(0, k + 1)
            remainder.set(k, 1)
            return
        Polynomials.module(k // 2, a, b, c, remainder, rb, pow)
        Polynomials.mul(remainder, remainder, a, mod)
        if k % 2 == 1:
            ra = Polynomials.rankOf(a)
            a.expandWith(0, ra + 2)
            aData = a.getData()
            for i in range(ra, -1, -1):
                aData[i + 1] = aData[i]
            aData[0] = 0
        Polynomials.divide(a, b, c, remainder, pow)

class Power:
    def __init__(self, modular):
        self.modular = modular

    def pow(self, x, n):
        if n == 0:
            return self.modular.valueOf(1)
        r = self.pow(x, n >> 1)
        r = self.modular.valueOf(r * r)
        if n & 1 == 1:
            r = self.modular.valueOf(r * x)
        return r

    def id7(self, x):
        return self.pow(x, self.modular.m - 2)

import sys

def main():
    mod = Modular(1000000007)
    in_ = FastInput(sys.stdin)
    out = FastOutput(sys.stdout)
    n = in_.readLong()
    k = in_.readInt()
    items = 200
    fib = [0] * items
    fib[0] = 1
    fib[1] = 2
    a = [0] * items
    for i in range(2, items):
        fib[i] = mod.plus(fib[i - 1], fib[i - 2])
    for i in range(items):
        a[i] = mod.mul(fib[i], pow.pow(i + 1, k))
        if i > 0:
            a[i] = mod.plus(a[i], a[i - 1])
    seq = IntegerList()
    seq.addAll(a)
    solver = id9.id2(seq, mod)
    ans = solver.solve(n - 1, seq)
    out.println(ans)
    out.close()

if __name__ == '__main__':
    main()
