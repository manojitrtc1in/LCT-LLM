import sys
import math
from collections import deque

class FastIO:
    def __init__(self, input_stream, output_stream):
        self.input_stream = input_stream
        self.output_stream = output_stream
        self.cache = []

    def read_int(self):
        return int(self.read_string().strip())

    def read_char(self):
        return self.read_string().strip()

    def read_string(self):
        return self.input_stream.readline().strip()

    def flush(self):
        self.output_stream.write(' '.join(map(str, self.cache)) + '\n')
        self.cache.clear()

class Task:
    def __init__(self, io):
        self.io = io
        self.inf = int(1e8)
        self.mod = int(1e9 + 7)

    def mod(self, val):
        val %= self.mod
        if val < 0:
            val += self.mod
        return val

    def solve(self):
        n = self.io.read_int()
        points = [[0] * 4 for _ in range(n)]
        for i in range(n):
            points[i][0], points[i][1] = map(int, self.io.read_string().split())
            points[i][3] = i + 1

        last = points[0]
        for pt in points:
            if pt[0] == last[0]:
                if pt[1] < last[1]:
                    last = pt
            elif pt[0] > last[0]:
                last = pt

        last[2] = 1
        self.io.cache.append(last[3])
        for _ in range(n - 2):
            c = self.io.read_char()
            choose = None
            if c == 'L':
                cmp = lambda a, b: -self.cross(a[0] - last[0], a[1] - last[1], b[0] - last[0], b[1] - last[1])
            else:
                cmp = lambda a, b: self.cross(a[0] - last[0], a[1] - last[1], b[0] - last[0], b[1] - last[1])
            for pt in points:
                if pt[2] == 1:
                    continue
                if choose is None or cmp(pt, choose) < 0:
                    choose = pt
            last = choose
            last[2] = 1
            self.io.cache.append(last[3])

        for pt in points:
            if pt[2] == 1:
                continue
            self.io.cache.append(pt[3])

    @staticmethod
    def cross(x1, y1, x2, y2):
        return x1 * y2 - y1 * x2

def main():
    local = 'ONLINE_JUDGE' not in sys.environ
    io = FastIO(open("D:\\DATABASE\\TESTCASE\\Code.in") if local else sys.stdin, sys.stdout)
    task = Task(io)

    task.solve()
    io.flush()

if __name__ == "__main__":
    main()
