class CF1158D:
    def __init__(self, io, debug):
        self.io = io
        self.debug = debug
        self.inf = int(1e8)
        self.mod = int(1e9) + 7

    def mod(self, val):
        val %= self.mod
        if val < 0:
            val += self.mod
        return val

    def bitAt(self, x, i):
        return (x >> i) & 1

    def solve(self):
        n = self.io.readInt()
        points = [[0] * 4 for _ in range(n)]
        for i in range(n):
            for j in range(2):
                points[i][j] = self.io.readInt()
            points[i][3] = i + 1

        last = points[0]
        for pt in points:
            if pt[0] == last[0]:
                if pt[1] < last[1]:
                    last = pt
            elif pt[0] > last[0]:
                last = pt

        last[2] = 1
        self.io.cache.append(str(last[3]) + ' ')
        for i in range(n - 2):
            c = self.io.readChar()
            cmp = None
            finalLast = last
            choose = None
            if c == 'L':
                cmp = lambda a, b: -1 if Geometry.cross(a[0] - finalLast[0], a[1] - finalLast[1], b[0] - finalLast[0], b[1] - finalLast[1]) < 0 else 1
            else:
                cmp = lambda a, b: -1 if Geometry.cross(a[0] - finalLast[0], a[1] - finalLast[1], b[0] - finalLast[0], b[1] - finalLast[1]) > 0 else 1
            for pt in points:
                if pt[2] == 1:
                    continue
                if choose is None or cmp(pt, choose) < 0:
                    choose = pt
            last = choose
            last[2] = 1
            self.io.cache.append(str(last[3]) + ' ')

        for pt in points:
            if pt[2] == 1:
                continue
            self.io.cache.append(str(pt[3]) + ' ')

class Geometry:
    class Point2:
        def __init__(self, x, y):
            self.x = x
            self.y = y

        def add(self, other):
            return Point2(self.x + other.x, self.y + other.y)

        def sub(self, other):
            return Point2(self.x - other.x, self.y - other.y)

        def __str__(self):
            return f"({self.x},{self.y})"

    class Line2:
        def __init__(self, begin, end):
            self.begin = begin
            self.end = end

        def getVector(self):
            return self.end.sub(self.begin)

        def getPointAt(self, alpha):
            return Point2((1 - alpha) * self.begin.x + alpha * self.end.x, (1 - alpha) * self.begin.y + alpha * self.end.y)

        def __str__(self):
            return f"{self.begin}-> {self.end}"

    @staticmethod
    def compare(a, b, prec):
        return 0 if abs(a - b) < prec else -1 if a < b else 1

    @staticmethod
    def grahamScan(point2s, prec):
        points = point2s[:]
        n = len(points)

        def swap(data, i, j):
            data[i], data[j] = data[j], data[i]

        swap(points, 0, min(range(n), key=lambda i: (points[i].y, points[i].x)))

        cmp = lambda o1, o2: Geometry.compare(0, Geometry.cross(o1.sub(points[0]), o2.sub(points[0])), prec)
        points[1:] = sorted(points[1:], key=lambda x: cmp(x))

        shrinkSize = 2
        for i in range(2, n):
            if cmp(points[i], points[shrinkSize - 1]) == 0:
                if Geometry.distance2(points[i].sub(points[0])) > Geometry.distance2(points[shrinkSize - 1].sub(points[0])):
                    points[shrinkSize - 1] = points[i]
            else:
                points[shrinkSize] = points[i]
                shrinkSize += 1

        n = shrinkSize
        stack = [points[0]]
        for i in range(1, n):
            while len(stack) >= 2:
                last = stack.pop()
                second = stack[-1]
                if Geometry.cross(points[i].sub(second), last.sub(second)) < -prec:
                    stack.append(last)
                    break
            stack.append(points[i])

        return stack

    @staticmethod
    def cross(x1, y1, x2, y2):
        return x1 * y2 - y1 * x2

    @staticmethod
    def cross(a, b):
        return a.x * b.y - a.y * b.x

    @staticmethod
    def onSection(p, section, precision):
        return abs(Geometry.cross(p.sub(section.begin), section.getVector())) < precision and section.begin.x - precision <= p.x <= section.end.x + precision

    @staticmethod
    def distance2(p):
        return p.x * p.x + p.y * p.y

    @staticmethod
    def distance(p):
        return math.sqrt(Geometry.distance2(p))

    @staticmethod
    def lineIntersection(s1, s2, prec):
        m11 = s1.end.x - s1.begin.x
        m01 = s2.end.x - s2.begin.x
        m10 = s1.begin.y - s1.end.y
        m00 = s2.begin.y - s2.end.y

        div = m00 * m11 - m01 * m10
        if abs(div) < prec:
            return None

        v0 = (s2.begin.x - s1.begin.x) / div
        v1 = (s2.begin.y - s1.begin.y) / div

        alpha = m00 * v0 + m01 * v1

        return s1.getPointAt(alpha)

    @staticmethod
    def sectionIntersection(s1, s2, prec):
        m11 = s1.end.x - s1.begin.x
        m01 = s2.end.x - s2.begin.x
        m10 = s1.begin.y - s1.end.y
        m00 = s2.begin.y - s2.end.y

        div = m00 * m11 - m01 * m10
        if abs(div) < prec:
            return None

        v0 = (s2.begin.x - s1.begin.x) / div
        v1 = (s2.begin.y - s1.begin.y) / div

        alpha = m00 * v0 + m01 * v1
        beta = m10 * v0 + m11 * v1

        if -prec <= alpha <= 1 + prec and -prec <= beta <= 1 + prec:
            return s1.getPointAt(alpha)
        return None

class Memory:
    @staticmethod
    def swap(data, i, j):
        data[i], data[j] = data[j], data[i]

    @staticmethod
    def min(data, from_, to, cmp):
        m = from_
        for i in range(from_ + 1, to):
            if cmp(data[m], data[i]) > 0:
                m = i
        return m

    @staticmethod
    def move(data, from_, to, step):
        length = to - from_
        step = (length - (step % length) + length) % length
        buf = [None] * length
        for i in range(length):
            buf[i] = data[(i + step) % length + from_]
        for i in range(length):
            data[from_ + i] = buf[i]

    @staticmethod
    def reverse(data, f, t):
        l, r = f, t - 1
        while l < r:
            Memory.swap(data, l, r)
            l += 1
            r -= 1

    @staticmethod
    def copy(src, dst, srcf, dstf, length):
        if length < 8:
            for i in range(length):
                dst[dstf + i] = src[srcf + i]
        else:
            dst[dstf:dstf+length] = src[srcf:srcf+length]

    @staticmethod
    def fill(x, val):
        for v in x:
            v.fill(val)

class FastIO:
    def __init__(self, is_, os, charset):
        self.cache = []
        self.is_ = is_
        self.os = os
        self.charset = charset
        self.defaultStringBuf = []
        self.buf = bytearray(1 << 13)
        self.bufLen = 0
        self.bufOffset = 0
        self.next = 0

    def read(self):
        while self.bufLen == self.bufOffset:
            self.bufOffset = 0
            self.bufLen = self.is_.readinto(self.buf)
            if self.bufLen == -1:
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

    def readDouble(self):
        sign = True
        self.skipBlank()
        if self.next == ord('+') or self.next == ord('-'):
            sign = self.next == ord('+')
            self.next = self.read()

        val = 0
        while self.next >= ord('0') and self.next <= ord('9'):
            val = val * 10 + self.next - ord('0')
            self.next = self.read()
        if self.next != ord('.'):
            return val if sign else -val
        self.next = self.read()
        radix = 1
        point = 0
        while self.next >= ord('0') and self.next <= ord('9'):
            point = point * 10 + self.next - ord('0')
            radix = radix * 10
            self.next = self.read()
        result = val + point / radix
        return result if sign else -result

    def readString(self, builder):
        self.skipBlank()

        while self.next > 32:
            builder.append(chr(self.next))
            self.next = self.read()

        return ''.join(builder)

    def readString(self):
        self.defaultStringBuf.clear()
        return self.readString(self.defaultStringBuf)

    def readLine(self, data, offset):
        originalOffset = offset
        while self.next != -1 and self.next != ord('\n'):
            data[offset] = chr(self.next)
            offset += 1
            self.next = self.read()
        return offset - originalOffset

    def readString(self, data, offset):
        self.skipBlank()

        originalOffset = offset
        while self.next > 32:
            data[offset] = chr(self.next)
            offset += 1
            self.next = self.read()

        return offset - originalOffset

    def readString(self, data, offset):
        self.skipBlank()

        originalOffset = offset
        while self.next > 32:
            data[offset] = self.next
            offset += 1
            self.next = self.read()

        return offset - originalOffset

    def readChar(self):
        self.skipBlank()
        c = chr(self.next)
        self.next = self.read()
        return c

    def flush(self):
        try:
            self.os.write(''.join(self.cache).encode(self.charset))
            self.os.flush()
            self.cache.clear()
        except IOError as e:
            raise RuntimeError(e)

    def hasMore(self):
        self.skipBlank()
        return self.next != -1

class Debug:
    def __init__(self, allowDebug):
        self.allowDebug = allowDebug

    def assertTrue(self, flag):
        if not self.allowDebug:
            return
        if not flag:
            self.fail()

    def fail(self):
        raise RuntimeError()

    def assertFalse(self, flag):
        if not self.allowDebug:
            return
        if flag:
            self.fail()

    def outputName(self, name):
        print(name + " = ", end='')

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
        print(x)

    def debug(self, name, x):
        if not self.allowDebug:
            return

        self.outputName(name)
