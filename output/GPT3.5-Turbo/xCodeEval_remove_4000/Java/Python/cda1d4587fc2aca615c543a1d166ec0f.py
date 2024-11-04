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

    def id3(self):
        return Modular(self.m - 1)


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


class FastOutput:
    def __init__(self, os):
        self.cache = ""
        self.os = os

    def println(self, c):
        self.cache += str(c) + "\n"
        return self

    def flush(self):
        self.os.write(self.cache)
        self.os.flush()
        self.cache = ""

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


class Composite:
    def __init__(self, limit, modular):
        self.factorial = Factorial(limit, modular)
        self.modular = modular

    def composite(self, m, n):
        if n > m:
            return 0
        return self.modular.mul(self.modular.mul(self.factorial.fact(m), self.factorial.invFact(n)), self.factorial.invFact(m - n))


class id11:
    BITS = 16
    LIMIT = 1 << BITS
    CACHE = [0] * LIMIT

    @staticmethod
    def ceilLog(x):
        ans = id11.floorLog(x)
        if (1 << ans) < x:
            ans += 1
        return ans

    @staticmethod
    def floorLog(x):
        return id11.CACHE[x] if x < id11.LIMIT else id11.BITS + id11.CACHE[x >> id11.BITS]

    @staticmethod
    def floorLog(x):
        ans = 0
        while x >= id11.LIMIT:
            ans += id11.BITS
            x >>= id11.BITS
        return ans + id11.CACHE[x]


class InverseNumber:
    def __init__(self, limit, modular):
        self.inv = [0] * (limit + 1)
        self.inv[1] = 1
        p = modular.m
        for i in range(2, limit + 1):
            k = p // i
            r = p % i
            self.inv[i] = modular.mul(-k, self.inv[r])


class Polynomials:
    @staticmethod
    def rankOf(p):
        r = len(p) - 1
        while r >= 0 and p[r] == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def mul(a, b, c, mod):
        rA = Polynomials.rankOf(a)
        rB = Polynomials.rankOf(b)
        c.clear()
        c.extend([0] * (rA + rB + 1))
        if rA >= 64 and rB >= 64:
            ans = id10.multiplyMod(a, rA + 1, b, rB + 1, mod.m)
            c.clear()
            c.extend(ans)
            return
        for i in range(rA + 1):
            for j in range(rB + 1):
                c[i + j] = mod.plus(c[i + j], mod.mul(a[i], b[j]))


class id10:
    @staticmethod
    def dft(p, m):
        n = 1 << m

        shift = 32 - bin(n).count('0')
        for i in range(1, n):
            j = int(bin(i << shift)[:1:-1], 2)
            if i < j:
                p[0][i], p[0][j] = p[0][j], p[0][i]
                p[1][i], p[1][j] = p[1][j], p[1][i]

        t = [0, 0]
        for d in range(m):
            s = 1 << d
            s2 = s << 1
            for i in range(0, n, s2):
                for j in range(s):
                    a = i + j
                    b = a + s
                    id10.mul(realLevels[d][j], imgLevels[d][j], p[0][b], p[1][b], t, 0)
                    id10.sub(p[0][a], p[1][a], t[0], t[1], p, b)
                    id10.add(p[0][a], p[1][a], t[0], t[1], p, a)

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
            aa = round(faReal[i])
            bb = round(fbReal[i])
            cc = round(faImag[i])
            res[i] = (aa % m + (bb % m << 15) + (cc % m << 30)) % m
        return res


class id1:
    def __init__(self, n, m, mod):
        self.m = m
        self.mod = mod
        self.id8 = self.pow(n)
        self.id8.extend([0] * (m + 1))

    def get(self, i):
        return self.id8[i]

    def mul(self, a, b, c):
        c.clear()
        c.extend([0] * (len(a) + len(b) - 1))
        n = len(a)
        for i in range(n):
            val = a[i]
            c[i] = self.mod.plus(c[i], val)
            c[i + 1] = val
        while len(c) > self.m + 1:
            c.pop()

    def pow(self, exp):
        ceil = id11.ceilLog(self.m + 1 + self.m)
        loop = Loop([0] * (1 << ceil), [0] * (1 << ceil))
        loop.get()[0] = 1
        for i in range(id11.floorLog(exp), -1, -1):
            self.mul(loop.get(), loop.get(), loop.turn())
            if 1 == Bits.bitAt(exp, i):
                self.mul(loop.get(), loop.turn())
        return loop.get()


class id10:
    realLevels = []
    imgLevels = []

    @staticmethod
    def prepareLevel(i):
        if id10.realLevels[i] is None:
            id10.realLevels[i] = [0] * (1 << i)
            id10.imgLevels[i] = [0] * (1 << i)
            for j in range(1 << i):
                id10.realLevels[i][j] = math.cos(math.pi / (1 << i) * j)
                id10.imgLevels[i][j] = math.sin(math.pi / (1 << i) * j)

    @staticmethod
    def dft(p, m):
        n = 1 << m

        shift = 32 - id11.floorLog(n)
        for i in range(1, n):
            j = (i << shift) & (n - 1)
            if i < j:
                p[0][i], p[0][j] = p[0][j], p[0][i]
                p[1][i], p[1][j] = p[1][j], p[1][i]

        t = [0, 0]
        for d in range(m):
            s = 1 << d
            s2 = s << 1
            id10.prepareLevel(d)
            for i in range(0, n, s2):
                for j in range(s):
                    a = i + j
                    b = a + s
                    id10.mul(id10.realLevels[d][j], id10.imgLevels[d][j], p[0][b], p[1][b], t, 0)
                    id10.sub(p[0][a], p[1][a], t[0], t[1], p, b)
                    id10.add(p[0][a], p[1][a], t[0], t[1], p, a)

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
            aa = round(faReal[i])
            bb = round(fbReal[i])
            cc = round(faImag[i])
            res[i] = (aa % m + (bb % m << 15) + (cc % m << 30)) % m
        return res


class FCards:
    def __init__(self):
        self.mod = Modular(998244353)
        self.comp = Composite(5000, self.mod)
        self.power = Power(self.mod)

    def solve(self, testNumber, in_, out):
        n = in_.readInt()
        m = in_.readInt()
        k = in_.readInt()

        pm = CachedPow(m, self.mod)
        xk = [0] * (k + 1)
        for i in range(k + 1):
            xk[i] = self.power.pow(i, k)

        ans = 0
        bc = id1(n, k, self.mod)
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

        out.println(ans)


def main():
    import sys
    in_ = FastInput(sys.stdin)
    out = FastOutput(sys.stdout)
    task = FCards()
    task.solve(1, in_, out)
    out.close()


if __name__ == '__main__':
    main()
