class Modular:
    def __init__(self, m):
        self.m = m

    def valueOf(self, x):
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x, y):
        return self.valueOf(x * y)

    def plus(self, x, y):
        return self.valueOf(x + y)

    def getModularForPowerComputation(self):
        return Modular(self.m - 1)


class FastInput:
    def __init__(self, is):
        self.is = is
        self.buf = bytearray()
        self.bufLen = 0
        self.bufOffset = 0
        self.next = 0

    def read(self):
        while self.bufLen == self.bufOffset:
            self.bufOffset = 0
            self.buf = self.is.read(1 << 13)
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


class FastOutput:
    def __init__(self, os):
        self.os = os
        self.cache = bytearray()

    def println(self, c):
        self.cache.extend(str(c).encode())
        self.cache.extend(b'\n')

    def flush(self):
        self.os.write(self.cache)
        self.os.flush()
        self.cache = bytearray()

    def close(self):
        self.flush()
        self.os.close()


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


class Factorial:
    def __init__(self, limit, modular):
        self.modular = modular
        self.fact = [0] * (limit + 1)
        self.inv = [0] * (limit + 1)
        self.fact[0] = self.inv[0] = 1
        for i in range(1, limit + 1):
            self.fact[i] = self.modular.mul(self.fact[i - 1], i)
            self.inv[i] = self.modular.mul(self.inv[i - 1], self.inv[i])

    def fact(self, n):
        return self.fact[n]

    def invFact(self, n):
        return self.inv[n]


class InverseNumber:
    def __init__(self, limit, modular):
        self.inv = [0] * (limit + 1)
        self.inv[1] = 1
        p = modular.getMod()
        for i in range(2, limit + 1):
            k = p // i
            r = p % i
            self.inv[i] = modular.mul(-k, self.inv[r])


class IntegerList:
    def __init__(self, cap=0):
        self.size = 0
        self.cap = cap
        self.data = []

    def remove(self, l, r):
        if l > r:
            return
        self.checkRange(l)
        self.checkRange(r)
        if r == self.size - 1:
            self.size = l
            return
        else:
            self.data[l:self.size - (r + 1)] = self.data[r + 1:self.size]
            self.size -= (r - l + 1)

    def ensureSpace(self, req):
        if req > self.cap:
            while self.cap < req:
                self.cap = max(self.cap + 10, 2 * self.cap)
            self.data = self.data[:self.cap]

    def checkRange(self, i):
        if i < 0 or i >= self.size:
            raise IndexError("index " + str(i) + " out of range")

    def get(self, i):
        self.checkRange(i)
        return self.data[i]

    def add(self, x):
        self.ensureSpace(self.size + 1)
        self.data.append(x)
        self.size += 1

    def addAll(self, x, offset=0, length=None):
        if length is None:
            length = len(x)
        self.ensureSpace(self.size + length)
        self.data.extend(x[offset:offset + length])
        self.size += length

    def expandWith(self, x, length):
        self.ensureSpace(self.size + length)
        self.data.extend([x] * length)
        self.size += length

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


class Polynomials:
    @staticmethod
    def rankOf(p):
        r = p.size - 1
        while r >= 0 and p.data[r] == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def mul(a, b, c, mod):
        rA = Polynomials.rankOf(a)
        rB = Polynomials.rankOf(b)
        c.clear()
        c.expandWith(0, rA + rB + 1)
        for i in range(rA + 1):
            for j in range(rB + 1):
                c.data[i + j] = mod.plus(c.data[i + j], mod.mul(a.data[i], b.data[j]))


class BinomialComposite:
    def __init__(self, n, m, mod, fft):
        self.m = m
        self.mod = mod
        self.n = n
        self.fft = fft
        self.composites = self.pow(n)
        self.composites.expandWith(0, m + 1)

    def get(self, i):
        return self.composites.get(i)

    def mul(self, a, b, c):
        if not self.fft:
            Polynomials.mul(a, b, c, self.mod)
        else:
            ans = multiplyMod(a.toArray(), len(a), b.toArray(), len(b), self.mod.getMod())
            c.clear()
            c.addAll(ans)

    def trim(self, x):
        if x.size > self.m + 1:
            x.remove(self.m + 1, x.size - 1)

    def mul(self, p, ans):
        ans.clear()
        ans.expandWith(0, p.size + 1)

        n = p.size
        for i in range(n):
            val = p.get(i)
            ans.set(i, self.mod.plus(ans.get(i), val))
            ans.set(i + 1, val)

        self.trim(ans)

    def pow(self, exp):
        ceil = CachedLog2.ceilLog(self.m + 1 + self.m)
        loop = Loop(IntegerList(1 << ceil), IntegerList(1 << ceil))
        loop.get().add(1)
        for i in range(CachedLog2.floorLog(exp), -1, -1):
            self.mul(loop.get(), loop.get(), loop.turn())
            if 1 == Bits.bitAt(exp, i):
                self.mul(loop.get(), loop.turn())
        return loop.get()


class Bits:
    @staticmethod
    def bitAt(x, i):
        return (x >> i) & 1


class CachedLog2:
    BITS = 16
    LIMIT = 1 << BITS
    CACHE = [0] * LIMIT

    @staticmethod
    def ceilLog(x):
        ans = CachedLog2.floorLog(x)
        if (1 << ans) < x:
            ans += 1
        return ans

    @staticmethod
    def floorLog(x):
        return CachedLog2.CACHE[x] if x < CachedLog2.LIMIT else (CachedLog2.BITS + CachedLog2.CACHE[x >> CachedLog2.BITS])

    @staticmethod
    def floorLog(x):
        ans = 0
        while x >= CachedLog2.LIMIT:
            ans += CachedLog2.BITS
            x >>= CachedLog2.BITS
        return ans + CachedLog2.CACHE[x]


class Loop:
    def __init__(self, *data):
        self.data = data
        self.pos = 0

    def turn(self, i=1):
        self.pos += i
        return self.get(0)

    def get(self, i=0):
        return self.data[(self.pos + i) % len(self.data)]


def multiplyMod(a, aLen, b, bLen, m):
    need = aLen + bLen - 1
    n = 1 << CachedLog2.ceilLog(need)

    aReal = [0] * n
    aImag = [0] * n
    for i in range(aLen):
        x = (a[i] % m + m) % m
        aReal[i] = x & ((1 << 15) - 1)
        aImag[i] = x >> 15

    dft([aReal, aImag], CachedLog2.floorLog(n))

    bReal = [0] * n
    bImag = [0] * n
    for i in range(bLen):
        x = (b[i] % m + m) % m
        bReal[i] = x & ((1 << 15) - 1)
        bImag[i] = x >> 15

    dft([bReal, bImag], CachedLog2.floorLog(n))

    faReal = [0] * n
    faImag = [0] * n
    fbReal = [0] * n
    fbImag = [0] * n

    for i in range(n):
        j = (n - i) & (n - 1)

        a1r = (aReal[i] + aReal[j]) / 2
        a1i = (aImag[i] - aImag[j]) / 2
        a2r = (aImag[i] + aImag[j]) / 2
        a2i = (aReal[j] - aReal[i]) / 2

        b1r = (bReal[i] + bReal[j]) / 2
        b1i = (bImag[i] - bImag[j]) / 2
        b2r = (bImag[i] + bImag[j]) / 2
        b2i = (bReal[j] - bReal[i]) / 2

        faReal[i] = a1r * b1r - a1i * b1i - a2r * b2i - a2i * b2r
        faImag[i] = a1r * b1i + a1i * b1r + a2r * b2r - a2i * b2i

        fbReal[i] = a1r * b2r - a1i * b2i + a2r * b1r - a2i * b1i
        fbImag[i] = a1r * b2i + a1i * b2r + a2r * b1i + a2i * b1r

    idft([faReal, faImag], CachedLog2.floorLog(n))
    idft([fbReal, fbImag], CachedLog2.floorLog(n))
    res = [0] * need
    for i in range(need):
        aa = int(faReal[i] + 0.5)
        bb = int(fbReal[i] + 0.5)
        cc = int(faImag[i] + 0.5)
        res[i] = (aa % m + (bb % m << 15) + (cc % m << 30)) % m
    return res


def dft(p, m):
    n = 1 << m

    shift = 32 - bin(n).count('1')
    for i in range(1, n):
        j = int(bin(i << shift)[:1:-1], 2)
        if i < j:
            p[0][i], p[0][j] = p[0][j], p[0][i]
            p[1][i], p[1][j] = p[1][j], p[1][i]

    t = [0, 0]
    for d in range(m):
        s = 1 << d
        s2 = s << 1
        prepareLevel(d)
        for i in range(0, n, s2):
            for j in range(s):
                a = i + j
                b = a + s
                mul(realLevels[d][j], imgLevels[d][j], p[0][b], p[1][b], t, 0)
                sub(p[0][a], p[1][a], t[0], t[1], p, b)
                add(p[0][a], p[1][a], t[0], t[1], p, a)


def idft(p, m):
    dft(p, m)

    n = 1 << m
    div(p[0][0], p[1][0], n, p, 0)
    div(p[0][n // 2], p[1][n // 2], n, p, n // 2)
    for i in range(1, n // 2):
        a = p[0][n - i]
        b = p[1][n - i]
        div(p[0][i], p[1][i], n, p, n - i)
        div(a, b, n, p, i)


def add(r1, i1, r2, i2, r, i):
    r[i] = r1 + r2
    i[i] = i1 + i2


def sub(r1, i1, r2, i2, r, i):
    r[i] = r1 - r2
    i[i] = i1 - i2


def mul(r1, i1, r2, i2, r, i):
    r[i] = r1 * r2 - i1 * i2
    i[i] = r1 * i2 + i1 * r2


def div(r1, i1, r2, r, i):
    r[i] = r1 / r2
    i[i] = i1 / r2


def prepareLevel(i):
    if realLevels[i] is None:
        realLevels[i] = [0] * (1 << i)
        imgLevels[i] = [0] * (1 << i)
        for j in range(1 << i):
            realLevels[i][j] = math.cos(math.pi / (1 << i) * j)
            imgLevels[i][j] = math.sin(math.pi / (1 << i) * j)


class Loop:
    def __init__(self, *data):
        self.data = data
        self.pos = 0

    def turn(self, i=1):
        self.pos += i
        return self.get(0)

    def get(self, i=0):
        return self.data[(self.pos + i) % len(self.data)]


class FCards:
    def __init__(self):
        self.mod = Modular(998244353)
        self.comp = Composite(5000, self.mod)
        self.power = Power(self.mod)

    def solve(self, testNumber, inStream, outStream):
        inStream = FastInput(inStream)
        outStream = FastOutput(outStream)
        n = inStream.readInt()
        m = inStream.readInt()
        k = inStream.readInt()

        pm = CachedPow(m, self.mod)
        xk = [0] * (k + 1)
        for i in range(k + 1):
            xk[i] = self.power.pow(i, k)

        ans = 0
        bc = BinomialComposite(n, k, self.mod, True)
        for t in range(k + 1):
            p1 = bc.get(t)
            p2 = 0
            for i in range(t + 1):
                contrib = self.comp.composite(t, i)
                contrib = self.mod.mul(contrib, xk[t - i])
                if i % 2 == 1:
                    contrib = self.mod.valueOf(-contrib)
                p2 = self.mod.plus(p2, contrib)
            p3 = pm.inverse(t)

            contrib = self.mod.mul(p1, p2)
            contrib = self.mod.mul(contrib, p3)
            ans = self.mod.plus(ans, contrib)

        outStream.println(ans)
        outStream.close()


def main():
    solver = FCards()
    solver.solve(1, sys.stdin.buffer, sys.stdout.buffer)


if __name__ == '__main__':
    main()
