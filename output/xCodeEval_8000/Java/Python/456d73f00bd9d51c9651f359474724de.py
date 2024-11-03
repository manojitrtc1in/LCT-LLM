import sys

class Solver:
    def __init__(self):
        self.io = IO()
        try:
            self.solve()
        except RuntimeError as e:
            if str(e) != "Clean exit":
                raise e
        finally:
            self.io.close()

    def solve(self):
        n = self.io.nextLong()
        m = self.io.nextLong()
        if m < n:
            helper = m
            m = n
            n = helper

        if n == 1:
            self.io.println(self.brute1(m))
            return
        if n == 2:
            if m < 3:
                self.io.println(0)
            elif m == 3:
                self.io.println(4)
            elif m == 7:
                self.io.println(12)
            else:
                self.io.println(2 * m)
            return

        self.io.println(2 * (n * m // 2))

    def brute1(self, m):
        ans = 6 * (m // 6)
        if m % 6 == 5:
            ans += 4
        elif m % 6 == 4:
            ans += 2
        return ans

    def closeToZero(self, v):
        return abs(v) <= 0.0000000000001

    class IO:
        def __init__(self):
            self.r = sys.stdin
            self.buf = ""
            self.bufc = 0
            self.bufi = 0
            self.sb = []

        def queryInt(self, s):
            self.println(s)
            self.flush()
            return self.nextInt()

        def queryLong(self, s):
            self.println(s)
            self.flush()
            return self.nextLong()

        def queryNext(self, s):
            self.println(s)
            self.flush()
            return self.next()

        def fillBuf(self):
            self.bufi = 0
            self.bufc = 0
            while self.bufc == 0:
                self.buf = self.r.readline()
                self.bufc = len(self.buf)
                if self.bufc == 0:
                    raise EOFError()

        def pumpBuf(self):
            if self.bufi == self.bufc:
                self.fillBuf()
            return self.bufc != 0

        def isDelimiter(self, c):
            return c == ' ' or c == '\t' or c == '\n' or c == '\r' or c == '\f'

        def eatDelimiters(self):
            while True:
                if self.bufi == self.bufc:
                    self.fillBuf()
                if not self.isDelimiter(self.buf[self.bufi]):
                    break
                self.bufi += 1

        def next(self):
            self.sb.clear()

            self.eatDelimiters()
            start = self.bufi

            while True:
                if self.bufi == self.bufc:
                    self.sb.append(self.buf[start:self.bufi])
                    self.fillBuf()
                    start = 0
                    if self.bufc == 0:
                        break

                if self.isDelimiter(self.buf[self.bufi]):
                    if start == self.bufi:
                        raise ValueError("IO.next: Invalid string.")
                    break

                self.bufi += 1

            self.sb.append(self.buf[start:self.bufi])

            return "".join(self.sb)

        def nextInt(self):
            ret = 0

            self.eatDelimiters()

            positive = True
            if self.buf[self.bufi] == '-':
                self.bufi += 1
                if not self.pumpBuf():
                    raise ValueError("IO.nextInt: Invalid int.")
                positive = False

            first = True
            while True:
                if not self.pumpBuf():
                    break
                if self.isDelimiter(self.buf[self.bufi]):
                    if first:
                        raise ValueError("IO.nextInt: Invalid int.")
                    break
                first = False

                if self.buf[self.bufi] >= '0' and self.buf[self.bufi] <= '9':
                    if ret < -214748364:
                        raise ValueError("IO.nextInt: Invalid int.")
                    ret *= 10
                    ret -= int(self.buf[self.bufi]) - ord('0')
                    if ret > 0:
                        raise ValueError("IO.nextInt: Invalid int.")
                else:
                    raise ValueError("IO.nextInt: Invalid int.")

                self.bufi += 1

            if positive:
                if ret == -2147483648:
                    raise ValueError("IO.nextInt: Invalid int.")
                ret = -ret

            return ret

        def nextLong(self):
            ret = 0

            self.eatDelimiters()

            positive = True
            if self.buf[self.bufi] == '-':
                self.bufi += 1
                if not self.pumpBuf():
                    raise ValueError("IO.nextLong: Invalid long.")
                positive = False

            first = True
            while True:
                if not self.pumpBuf():
                    break
                if self.isDelimiter(self.buf[self.bufi]):
                    if first:
                        raise ValueError("IO.nextLong: Invalid long.")
                    break
                first = False

                if self.buf[self.bufi] >= '0' and self.buf[self.bufi] <= '9':
                    if ret < -922337203685477580:
                        raise ValueError("IO.nextLong: Invalid long.")
                    ret *= 10
                    ret -= int(self.buf[self.bufi]) - ord('0')
                    if ret > 0:
                        raise ValueError("IO.nextLong: Invalid long.")
                else:
                    raise ValueError("IO.nextLong: Invalid long.")

                self.bufi += 1

            if positive:
                if ret == -9223372036854775808:
                    raise ValueError("IO.nextLong: Invalid long.")
                ret = -ret

            return ret

        def nextDouble(self):
            return float(self.next())

        def print(self, output):
            self.sb.append(str(output))

        def println(self, output):
            self.sb.append(str(output))
            self.sb.append("\n")

        def flush(self):
            sys.stdout.write("".join(self.sb))
            sys.stdout.flush()

        def close(self):
            self.flush()

    def main(self):
        solver = Solver()

if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    Solver().main()
