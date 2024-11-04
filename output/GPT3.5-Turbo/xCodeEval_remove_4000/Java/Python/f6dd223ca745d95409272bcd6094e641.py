class FastIO:
    def __init__(self, input_stream, output_stream):
        self.input_stream = input_stream
        self.output_stream = output_stream
        self.buffer = ""
        self.buffer_pos = 0

    def read(self):
        if self.buffer_pos >= len(self.buffer):
            self.buffer = self.input_stream.readline().strip()
            self.buffer_pos = 0
        if not self.buffer:
            return -1
        result = self.buffer[self.buffer_pos]
        self.buffer_pos += 1
        return result

    def read_int(self):
        sign = 1
        num = 0
        c = self.read()
        if c == '-':
            sign = -1
            c = self.read()
        while '0' <= c <= '9':
            num = num * 10 + int(c)
            c = self.read()
        return sign * num

    def read_string(self):
        result = ""
        c = self.read()
        while c != -1 and not c.isspace():
            result += c
            c = self.read()
        return result

    def write(self, value):
        self.output_stream.write(str(value))

    def flush(self):
        self.output_stream.flush()


class Task:
    def __init__(self, io):
        self.io = io

    def solve(self):
        n = self.io.read_int()
        points = []
        for _ in range(n):
            x, y = self.io.read_int(), self.io.read_int()
            points.append((x, y))
        last = points[0]
        for pt in points:
            if pt[0] == last[0]:
                if pt[1] < last[1]:
                    last = pt
            elif pt[0] > last[0]:
                last = pt
        last = list(last)
        last.append(1)
        self.io.write(last[2])
        self.io.write(' ')
        for _ in range(n - 2):
            c = self.io.read_string()
            cmp = None
            choose = None
            if c == 'L':
                cmp = lambda a, b: -1 if Geometry.cross(a[0] - last[0], a[1] - last[1], b[0] - last[0], b[1] - last[1]) < 0 else 1
            else:
                cmp = lambda a, b: -1 if Geometry.cross(a[0] - last[0], a[1] - last[1], b[0] - last[0], b[1] - last[1]) > 0 else 1
            for pt in points:
                if pt[2] == 1:
                    continue
                if choose is None or cmp(pt, choose) < 0:
                    choose = pt
            last = choose
            last[2] = 1
            self.io.write(last[3])
            self.io.write(' ')
        for pt in points:
            if pt[2] == 1:
                continue
            self.io.write(pt[3])
            self.io.write(' ')


class Geometry:
    @staticmethod
    def cross(x1, y1, x2, y2):
        return x1 * y2 - y1 * x2


def main():
    io = FastIO(sys.stdin, sys.stdout)
    task = Task(io)
    task.solve()
    io.flush()


if __name__ == "__main__":
    main()
