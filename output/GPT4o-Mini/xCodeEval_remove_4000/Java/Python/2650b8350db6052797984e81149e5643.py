import sys
from collections import defaultdict

class FastScanner:
    def __init__(self):
        self.buffer = sys.stdin.read().split()
        self.index = 0

    def next(self):
        if self.index < len(self.buffer):
            self.index += 1
            return self.buffer[self.index - 1]
        raise Exception("No more input")

    def int_next(self):
        return int(self.next())

class FastWriter:
    def __init__(self):
        self.out = []

    def p(self, obj):
        self.out.append(str(obj))
        return self

    def pp(self, *args):
        self.out.append(" ".join(map(str, args)))
        self.out.append("\n")
        return self

    def println(self, obj):
        self.out.append(str(obj) + "\n")
        return self

    def close(self):
        sys.stdout.write("".join(self.out))

def main():
    in_ = FastScanner()
    out = FastWriter()

    lng = in_.next()
    sht = in_.next()
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

    out.println(ans)
    out.close()

if __name__ == "__main__":
    main()
