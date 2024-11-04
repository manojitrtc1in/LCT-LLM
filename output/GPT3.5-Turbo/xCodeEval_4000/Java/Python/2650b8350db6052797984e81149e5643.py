import sys
from typing import List

class FastWriter:
    def __init__(self):
        self.out = []

    def p(self, obj):
        self.out.append(str(obj))

    def pp(self, *args):
        for ob in args:
            self.out.append(str(ob) + " ")
        self.out.append("\n")

    def println(self, arr):
        for e in arr:
            self.out.append(str(e) + " ")
        self.out.append("\n")

    def to_file(self, file_name):
        with open(file_name, "w") as f:
            f.write("".join(self.out))

    def close(self):
        sys.stdout.write("".join(self.out))

class FastScanner:
    def __init__(self):
        self.sin = sys.stdin.buffer
        self.buffer = bytearray()
        self.ptr = 0
        self.buflen = 0

    def has_next_byte(self):
        if self.ptr < self.buflen:
            return True
        else:
            self.ptr = 0
            self.buflen = self.sin.readinto(self.buffer)
            if self.buflen <= 0:
                return False
        return True

    def read_byte(self):
        if self.has_next_byte():
            self.ptr += 1
            return self.buffer[self.ptr - 1]
        else:
            return -1

    def is_printable_char(self, c):
        return 33 <= c <= 126

    def has_next(self):
        while self.has_next_byte() and not self.is_printable_char(self.buffer[self.ptr]):
            self.ptr += 1
        return self.has_next_byte()

    def next(self):
        if not self.has_next():
            raise StopIteration()
        sb = []
        b = self.read_byte()
        while self.is_printable_char(b):
            sb.append(chr(b))
            b = self.read_byte()
        return "".join(sb)

    def long_next(self):
        if not self.has_next():
            raise StopIteration()
        n = 0
        minus = False
        b = self.read_byte()
        if b == ord("-"):
            minus = True
            b = self.read_byte()
        if not ord("0") <= b <= ord("9"):
            raise ValueError()
        while True:
            if ord("0") <= b <= ord("9"):
                n *= 10
                n += b - ord("0")
            elif b == -1 or not self.is_printable_char(b) or b == ord(":"):
                return -n if minus else n
            else:
                raise ValueError()
            b = self.read_byte()

    def int_next(self):
        nl = self.long_next()
        if nl < -2147483648 or nl > 2147483647:
            raise ValueError()
        return int(nl)

    def double_next(self):
        return float(self.next())

    def next_long_array(self, n):
        a = []
        for _ in range(n):
            a.append(self.long_next())
        return a

    def next_int_array(self, n):
        a = []
        for _ in range(n):
            a.append(self.int_next())
        return a

    def next_double_array(self, n):
        a = []
        for _ in range(n):
            a.append(self.double_next())
        return a

    def get_adj(self, n):
        adj = [[] for _ in range(n + 1)]
        return adj

    def adjacency_list(self, nodes, edges, is_directed=False):
        adj = self.get_adj(nodes)
        for _ in range(edges):
            a = self.int_next()
            b = self.int_next()
            adj[a].append(b)
            if not is_directed:
                adj[b].append(a)
        return adj

out = FastWriter()
in_ = FastScanner()

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
