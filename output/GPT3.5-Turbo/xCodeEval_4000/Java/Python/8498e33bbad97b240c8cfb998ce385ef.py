import sys
from typing import List, Tuple, Dict, Any


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
        n = self.io.nextInt()

        endOfBrute = min(n, 30)
        prev = set()
        prev.add(0)
        for i in range(endOfBrute):
            next_set = set()
            for v in prev:
                next_set.add(v + 1)
                next_set.add(v + 5)
                next_set.add(v + 10)
                next_set.add(v + 50)
            prev = next_set

        if n > endOfBrute:
            diff = n - endOfBrute
            self.done(len(prev) + diff * 49)

        self.io.println(len(prev))


class IO:
    def __init__(self):
        self.r = sys.stdin
        self.w = sys.stdout
        self.buf = ""
        self.bufc = 0
        self.bufi = 0

    def queryInt(self, s: str) -> int:
        self.println(s)
        self.flush()
        return self.nextInt()

    def queryLong(self, s: str) -> int:
        self.println(s)
        self.flush()
        return self.nextLong()

    def queryNext(self, s: str) -> str:
        self.println(s)
        self.flush()
        return self.next()

    def fillBuf(self) -> None:
        self.bufi = 0
        self.bufc = 0
        while self.bufc == 0:
            self.buf = self.r.read(1 << 15)
            self.bufc = len(self.buf)

    def pumpBuf(self) -> bool:
        if self.bufi == self.bufc:
            self.fillBuf()
        return self.bufc != 0

    def isDelimiter(self, c: str) -> bool:
        return c == " " or c == "\t" or c == "\n" or c == "\r" or c == "\f"

    def eatDelimiters(self) -> None:
        while True:
            if self.bufi == self.bufc:
                self.fillBuf()
                if self.bufc == 0:
                    raise RuntimeError("IO: Out of input.")

            if not self.isDelimiter(self.buf[self.bufi]):
                break
            self.bufi += 1

    def next(self) -> str:
        self.sb = []
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
                if self.bufi == start:
                    raise RuntimeError("IO.next: Invalid input.")
                break

            self.bufi += 1

        self.sb.append(self.buf[start:self.bufi])

        return "".join(self.sb)

    def nextInt(self) -> int:
        ret = 0

        self.eatDelimiters()

        positive = True
        if self.buf[self.bufi] == "-":
            self.bufi += 1
            if not self.pumpBuf():
                raise RuntimeError("IO.nextInt: Invalid int.")
            positive = False

        first = True
        while True:
            if not self.pumpBuf():
                break
            if self.isDelimiter(self.buf[self.bufi]):
                if first:
                    raise RuntimeError("IO.nextInt: Invalid int.")
                break
            first = False

            if "0" <= self.buf[self.bufi] <= "9":
                if ret < -214748364:
                    raise RuntimeError("IO.nextInt: Invalid int.")
                ret *= 10
                ret -= int(self.buf[self.bufi]) - int("0")
                if ret > 0:
                    raise RuntimeError("IO.nextInt: Invalid int.")
            else:
                raise RuntimeError("IO.nextInt: Invalid int.")

            self.bufi += 1

        if positive:
            if ret == -2147483648:
                raise RuntimeError("IO.nextInt: Invalid int.")
            ret = -ret

        return ret

    def nextLong(self) -> int:
        ret = 0

        self.eatDelimiters()

        positive = True
        if self.buf[self.bufi] == "-":
            self.bufi += 1
            if not self.pumpBuf():
                raise RuntimeError("IO.nextLong: Invalid long.")
            positive = False

        first = True
        while True:
            if not self.pumpBuf():
                break
            if self.isDelimiter(self.buf[self.bufi]):
                if first:
                    raise RuntimeError("IO.nextLong: Invalid long.")
                break
            first = False

            if "0" <= self.buf[self.bufi] <= "9":
                if ret < -922337203685477580:
                    raise RuntimeError("IO.nextLong: Invalid long.")
                ret *= 10
                ret -= int(self.buf[self.bufi]) - int("0")
                if ret > 0:
                    raise RuntimeError("IO.nextLong: Invalid long.")
            else:
                raise RuntimeError("IO.nextLong: Invalid long.")

            self.bufi += 1

        if positive:
            if ret == -9223372036854775808:
                raise RuntimeError("IO.nextLong: Invalid long.")
            ret = -ret

        return ret

    def nextDouble(self) -> float:
        return float(self.next())

    def println(self, output: Any = "") -> None:
        self.w.write(str(output) + "\n")

    def flush(self) -> None:
        self.w.flush()

    def close(self) -> None:
        self.w.close()


if __name__ == "__main__":
    solver = Solver()
