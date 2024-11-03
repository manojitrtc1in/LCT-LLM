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
        n = self.io.next_int()

        end_of_brute = min(n, 30)
        prev = set()
        prev.add(0)
        for i in range(end_of_brute):
            next_set = set()
            for v in prev:
                next_set.add(v + 1)
                next_set.add(v + 5)
                next_set.add(v + 10)
                next_set.add(v + 50)
            prev = next_set

        if n > end_of_brute:
            diff = n - end_of_brute
            self.done(len(prev) + diff * 49)

        self.io.println(len(prev))


class IO:
    def __init__(self):
        self.r = sys.stdin
        self.buf = ""
        self.bufc = 0
        self.bufi = 0

    def fill_buf(self):
        self.bufi = 0
        self.bufc = 0
        while self.bufc == 0:
            self.buf = self.r.read(1 << 15)
            self.bufc = len(self.buf)

    def pump_buf(self):
        if self.bufi == self.bufc:
            self.fill_buf()
        return self.bufc != 0

    def is_delimiter(self, c: str) -> bool:
        return c == ' ' or c == '\t' or c == '\n' or c == '\r' or c == '\f'

    def eat_delimiters(self):
        while True:
            if self.bufi == self.bufc:
                self.fill_buf()
                if self.bufc == 0:
                    raise RuntimeError("IO: Out of input.")

            if not self.is_delimiter(self.buf[self.bufi]):
                break
            self.bufi += 1

    def next(self) -> str:
        sb = []
        self.eat_delimiters()
        start = self.bufi

        while True:
            if self.bufi == self.bufc:
                sb.append(self.buf[start:self.bufi])
                self.fill_buf()
                start = 0
                if self.bufc == 0:
                    break

            if self.is_delimiter(self.buf[self.bufi]):
                if self.bufi == start:
                    raise RuntimeError("IO.next: Invalid string.")
                break

            self.bufi += 1

        sb.append(self.buf[start:self.bufi])

        return ''.join(sb)

    def next_int(self) -> int:
        eat_delimiters()

        positive = True
        if self.buf[self.bufi] == '-':
            self.bufi += 1
            if not self.pump_buf():
                raise RuntimeError("IO.nextInt: Invalid int.")
            positive = False

        ret = 0
        first = True
        while True:
            if not self.pump_buf():
                break
            if self.is_delimiter(self.buf[self.bufi]):
                if first:
                    raise RuntimeError("IO.nextInt: Invalid int.")
                break
            first = False

            if '0' <= self.buf[self.bufi] <= '9':
                if ret < -214748364:
                    raise RuntimeError("IO.nextInt: Invalid int.")
                ret *= 10
                ret -= ord(self.buf[self.bufi]) - ord('0')
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

    def println(self, output: Any):
        print(output)

    def close(self):
        self.r.close()


if __name__ == "__main__":
    solver = Solver()
