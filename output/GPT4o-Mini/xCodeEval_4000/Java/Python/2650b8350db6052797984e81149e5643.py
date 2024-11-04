import sys
from collections import defaultdict

class FastWriter:
    def __init__(self):
        self.out = []

    def p(self, obj):
        self.out.append(str(obj))
        return self

    def pp(self, *args):
        self.out.append(" ".join(map(str, args)) + "\n")
        return self

    def println(self, obj):
        self.out.append(str(obj) + "\n")
        return self

    def close(self):
        sys.stdout.write("".join(self.out))


class FastScanner:
    def __init__(self):
        self.buffer = sys.stdin.read().split()
        self.index = 0

    def has_next(self):
        return self.index < len(self.buffer)

    def next(self):
        if not self.has_next():
            raise Exception("No more elements")
        result = self.buffer[self.index]
        self.index += 1
        return result

    def int_next(self):
        return int(self.next())

    def long_next(self):
        return int(self.next())

def main():
    in_scanner = FastScanner()
    out_writer = FastWriter()

    lng = in_scanner.next()
    sht = in_scanner.next()
    n = len(lng)
    m = len(sht)
    leftmost = [0] * (m + 1)
    rightmost = [0] * (m + 1)
    rightmost[m] = n

    idx = 0
    for i in range(m):
        while sht[i] != lng[idx]:
            idx += 1
        leftmost[i] = idx
        idx += 1

    idx = n - 1
    for i in range(m - 1, -1, -1):
        while sht[i] != lng[idx]:
            idx -= 1
        rightmost[i] = idx
        idx -= 1

    ans = rightmost[0]
    for i in range(m):
        ans = max(ans, rightmost[i + 1] - leftmost[i] - 1)

    out_writer.println(ans)
    out_writer.close()

if __name__ == "__main__":
    main()
