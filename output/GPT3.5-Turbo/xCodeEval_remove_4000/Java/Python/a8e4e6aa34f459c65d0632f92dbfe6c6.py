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

class IntegerList:
    def __init__(self, cap=0):
        self.size = 0
        self.cap = cap
        self.data = []

    def remove(self, l, r):
        if l > r:
            return
        self.data = self.data[:l] + self.data[r+1:]
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
        self.data += x[offset:offset+length]
        self.size += length

    def addAll(self, lst):
        self.addAll(lst.data)

    def expandWith(self, x, length):
        self.ensureSpace(self.size + length)
        self.data += [x] * length
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

class InverseNumber:
    def __init__(self, limit, modular):
        self.inv = [0] * (limit + 1)
        self.inv[1] = 1
        p = modular.getMod()
        for i in range(2, limit + 1):
            k = p // i
            r = p % i
            self.inv[i] = modular.mul(-k, self.inv[r])

class DigitUtils:
    @staticmethod
    def round(x):
        if x >= 0:
            return int(x + 0.5)
        else:
            return int(x - 0.5)

class Composite:
    def __init__(self, limit, modular):
        self.factorial = Factorial(limit, modular)
        self.modular = modular

    def composite(self, m, n):
        if n > m:
            return 0
        return self.modular.mul(self.modular.mul(self.factorial.fact(m), self.factorial.invFact(n)), self.factorial.invFact(m - n))

class SequenceUtils:
    @staticmethod
    def swap(data, i, j):
        data[i], data[j] = data[j], data[i]

    @staticmethod
    def equal(a, al, ar, b, bl, br):
        if (ar - al) != (br - bl):
            return False
        for i in range(al, ar+1):
            if a[i] != b[i-bl]:
                return False
        return True

class id10:
    @staticmethod
    def prepareLevel(i):
        if len(realLevels[i]) == 0:
            realLevels[i] = [0] * (1 << i)
            imgLevels[i] = [0] * (1 << i)
            for j in range(1 << i):
                realLevels[i][j] = math.cos(math.pi / (1 << i) * j)
                imgLevels[i][j] = math.sin(math.pi / (1 << i) * j)

    @staticmethod
    def dft(p, m):
        n = 1 << m

        shift = 32 - int(math.log2(n))
        for i in range(1, n):
            j = int(bin(i << shift)[::-1], 2)
            if i < j:
                SequenceUtils.swap(p[0], i, j)
                SequenceUtils.swap(p[1], i, j)

        t = [0]
        for d in range(m):
            s = 1 << d
            s2 = s << 1
            id10.prepareLevel(d)
            for i in range(0, n, s2):
                for j in range(s):
                    a = i + j
                    b = a + s
                    id10.mul(realLevels[d][j], imgLevels[d][j], p[0][b], p[1][b], t, 0)
                    id10.sub(p[0][a], p[1][a], t[0][0], t[1][0], p, b)
                    id10.add(p[0][a], p[1][a], t[0][0], t[1][0], p, a)

    @staticmethod
    def idft(p, m):
        id10.dft(p, m)

        n = 1 << m
        id10.div(p[0][0], p[1][0], n, p, 0)
        id10.div(p[0][n // 2], p[1][n // 2], n, p, n // 2)
        for i in range(1, n // 2):
            a = p[0][n - i]
            b = p[1][n - i]
            id10.div(p[0][i], p[1][i], n, p, n - i)
            id10.div(a, b, n, p, i)

    @staticmethod
    def add(r1, i1, r2, i2, r, i):
        r[0][i] = r1 + r2
        r[1][i] = i1 + i2

    @staticmethod
    def sub(r1, i1, r2, i2, r, i):
        r[0][i] = r1 - r2
        r[1][i] = i1 - i2

    @staticmethod
    def mul(r1, i1, r2, i2, r, i):
        r[0][i] = r1 * r2 - i1 * i2
        r[1][i] = r1 * i2 + i1 * r2

    @staticmethod
    def div(r1, i1, r2, r, i):
        r[0][i] = r1 / r2
        r[1][i] = i1 / r2

    @staticmethod
    def multiplyMod(a, aLen, b, bLen, m):
        need = aLen + bLen - 1
        n = 1 << id11.ceilLog(need)

        aReal = [0] * n
        aImag = [0] * n
        for i in range(aLen):
            x = a[i] % m
            aReal[i] = x & ((1 << 15) - 1)
            aImag[i] = x >> 15
        id10.dft([aReal, aImag], id11.floorLog(n))

        bReal = [0] * n
        bImag = [0] * n
        for i in range(bLen):
            x = b[i] % m
            bReal[i] = x & ((1 << 15) - 1)
            bImag[i] = x >> 15
        id10.dft([bReal, bImag], id11.floorLog(n))

        faReal = [0] * n
        faImag = [0] * n
        fbReal = [0] * n
        fbImag = [0] * n

        for i in range(n):
            j = (n - i) & (n - 1)

            id6 = (aReal[i] + aReal[j]) / 2
            id5 = (aImag[i] - aImag[j]) / 2
            id4 = (aImag[i] + aImag[j]) / 2
            id12 = (aReal[j] - aReal[i]) / 2

            id0 = (bReal[i] + bReal[j]) / 2
            id7 = (bImag[i] - bImag[j]) / 2
            id13 = (bImag[i] + bImag[j]) / 2
            id9 = (bReal[j] - bReal[i]) / 2

            faReal[i] = id6 * id0 - id5 * id7 - id4 * id9 - id12 * id13
            faImag[i] = id6 * id7 + id5 * id0 + id4 * id13 - id12 * id9

            fbReal[i] = id6 * id13 - id5 * id9 + id4 * id0 - id12 * id7
            fbImag[i] = id6 * id9 + id5 * id13 + id4 * id7 + id12 * id0

        id10.idft([faReal, faImag], id11.floorLog(n))
        id10.idft([fbReal, fbImag], id11.floorLog(n))
        res = [0] * need
        for i in range(need):
            aa = int(faReal[i] + 0.5)
            bb = int(fbReal[i] + 0.5)
            cc = int(faImag[i] + 0.5)
            res[i] = (aa % m + (bb % m << 15) + (cc % m << 30)) % m
        return res

class Loop:
    def __init__(self, data):
        self.data = data
        self.pos = 0

    def turn(self, i):
        self.pos += i
        return self.get(0)

    def turn(self):
        return self.turn(1)

    def get(self, i):
        return self.data[(self.pos + i) % len(self.data)]

    def get(self):
        return self.get(0)

class id1:
    def __init__(self, n, m, mod, fft):
        self.m = m
        self.mod = mod
        self.n = n
        self.fft = fft
        self.id8 = self.pow(n)
        self.id8.expandWith(0, m + 1)

    def get(self, i):
        return self.id8.get(i)

    def mul(self, a, b, c):
        if not self.fft:
            Polynomials.mul(a, b, c, self.mod)
        else:
            ans = id10.multiplyMod(a.getData(), a.size(), b.getData(), b.size(), self.mod.getMod())
            c.clear()
            c.addAll(ans)
        self.trim(c)

    def trim(self, x):
        if x.size() > self.m + 1:
            x.remove(self.m + 1, x.size() - 1)

    def mul(self, p, ans):
        ans.clear()
        ans.expandWith(0, p.size() + 1)

        n = p.size()
        for i in range(n):
            val = p.get(i)
            ans.set(i, self.mod.plus(ans.get(i), val))
            ans.set(i + 1, val)

        self.trim(ans)

    def pow(self, exp):
        ceil = id11.ceilLog(self.m + 1 + self.m)
        loop = Loop([IntegerList(1 << ceil), IntegerList(1 << ceil)])
        loop.get().add(1)
        for i in range(id11.floorLog(exp), -1, -1):
            self.mul(loop.get(), loop.get(), loop.turn())
            if 1 == Bits.bitAt(exp, i):
                self.mul(loop.get(), loop.turn())
        return loop.get()

class Bits:
    @staticmethod
    def bitAt(x, i):
        return (x >> i) & 1

class Factorial:
    def __init__(self, limit, modular):
        self.modular = modular
        self.fact = [0] * (limit + 1)
        self.inv = [0] * (limit + 1)
        self.fact[0] = self.inv[0] = 1
        for i in range(1, limit + 1):
            self.fact[i] = modular.mul(self.fact[i - 1], i)
            self.inv[i] = modular.mul(self.inv[i - 1], self.inv[i])

    def fact(self, n):
        return self.fact[n]

    def invFact(self, n):
        return self.inv[n]

class CachedPow:
    def __init__(self, x, mod):
        self.mod = mod
        self.powMod = mod.id2()
        self.first = []
        self.second = []
        k = max(1, int(DigitUtils.round(math.sqrt(mod.getMod()))))
        self.first.append(1)
        for i in range(1, k):
            self.first.append(mod.mul(x, self.first[i - 1]))
        self.second.append(1)
        step = mod.mul(x, self.first[k - 1])
        for i in range(1, mod.getMod() // k + 1):
            self.second.append(mod.mul(self.second[i - 1], step))

    def pow(self, exp):
        return self.mod.mul(self.first[exp % len(self.first)], self.second[exp // len(self.first)])

    def inverse(self, exp):
        return self.pow(self.powMod.valueOf(-exp))

class Polynomials:
    @staticmethod
    def rankOf(p):
        r = p.size() - 1
        while r >= 0 and p.get(r) == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def mul(a, b, c, mod):
        rA = Polynomials.rankOf(a)
        rB = Polynomials.rankOf(b)
        c.clear()
        c.expandWith(0, rA + rB + 1)
        aData = a.toArray()
        bData = b.toArray()
        cData = c.getData()
        for i in range(rA + 1):
            for j in range(rB + 1):
                cData[i + j] = mod.plus(cData[i + j], mod.mul(aData[i], bData[j]))

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

mod = Modular(998244353)
in_ = FastInput(sys.stdin.buffer)
out = FastOutput(sys.stdout.buffer)

n = in_.readInt()
m = in_.readInt()
k = in_.readInt()

pm = CachedPow(m, mod)
xk = [0] * (k + 1)
for i in range(k + 1):
    xk[i] = pm.pow(i, k)

ans = 0
bc = id1(n, k, mod, True)
for t in range(k + 1):
    p1 = bc.get(t)
    p2 = 0
    for i in range(t + 1):
        contrib = Composite.composite(t, i)
        contrib = mod.mul(contrib, xk[t - i])
        if i % 2 == 1:
            contrib = mod.valueOf(-contrib)
        p2 = mod.plus(p2, contrib)
    p3 = pm.inverse(t)

    contrib = mod.mul(p1, p2)
    contrib = mod.mul(contrib, p3)
    ans = mod.plus(ans, contrib)

out.println(ans)
out.close()
