import sys
import random

class Main:
    @staticmethod
    def main():
        thread = Thread(None, TaskAdapter(), "", 1 << 27)
        thread.start()
        thread.join()

class TaskAdapter:
    def run(self):
        input_stream = sys.stdin
        output_stream = sys.stdout
        in_ = FastInput(input_stream)
        out = FastOutput(output_stream)
        solver = Id7()
        solver.solve(1, in_, out)
        out.close()

class Id7:
    def solve(self, test_number, in_, out):
        n = in_.read_int()
        pts = [Point() for _ in range(n)]
        for i in range(n):
            pts[i].x = in_.read_int()
            pts[i].y = in_.read_int()

        x = Id8(n, False)
        y = Id8(n, False)
        dsu = DSU(n)
        for i in range(n):
            if x.contain_key(pts[i].x):
                dsu.merge(x.get(pts[i].x), i)
            if y.contain_key(pts[i].y):
                dsu.merge(y.get(pts[i].y), i)
            x.put(pts[i].x, i)
            y.put(pts[i].y, i)

        x_stack = Id3(n, n)
        y_stack = Id3(n, n)
        for i in range(n):
            x_stack.add_last(dsu.find(i), pts[i].x)
            y_stack.add_last(dsu.find(i), pts[i].y)
        x_list = IntegerList(n)
        y_list = IntegerList(n)

        mod = Modular(int(1e9 + 7))
        comb = Combination(2 * n, mod)
        ans = 1
        for i in range(n):
            if dsu.find(i) != i:
                continue
            x_list.clear()
            y_list.clear()
            x_list.add_all(x_stack.iterator(i))
            y_list.add_all(y_stack.iterator(i))
            x_list.unique()
            y_list.unique()

            line = len(x_list)
            num = dsu.size[i]
            local = 0
            for j in range(num + 1):
                local = mod.plus(local, comb.combination(line, j))

            ans = mod.mul(ans, local)

        out.println(ans)

class Modular:
    def __init__(self, m):
        self.m = m

    def value_of(self, x):
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x, y):
        return self.value_of(x * y)

    def plus(self, x, y):
        return self.value_of(x + y)

class Factorial:
    def __init__(self, limit, modular):
        self.modular = modular
        self.fact = [0] * (limit + 1)
        self.inv = [0] * (limit + 1)
        self.fact[0] = self.inv[0] = 1
        for i in range(1, limit + 1):
            self.fact[i] = modular.mul(self.fact[i - 1], i)
            self.inv[i] = modular.mul(self.inv[i - 1], InverseNumber(limit, modular).inv[i])

    def fact(self, n):
        return self.fact[n]

    def inv_fact(self, n):
        return self.inv[n]

class FastOutput:
    def __init__(self, os):
        self.cache = []
        self.os = os

    def append(self, csq):
        self.cache.append(csq)
        return self

    def println(self, c):
        self.append(c).println()

    def flush(self):
        self.os.write(''.join(map(str, self.cache)) + '\n')
        self.cache.clear()

    def close(self):
        self.flush()
        self.os.close()

class IntegerList:
    def __init__(self, cap):
        self.cap = cap
        self.size = 0
        self.data = []

    def add(self, x):
        self.data.append(x)
        self.size += 1

    def unique(self):
        self.data = list(set(self.data))
        self.size = len(self.data)

    def clear(self):
        self.data.clear()
        self.size = 0

    def __len__(self):
        return self.size

class FastInput:
    def __init__(self, is_):
        self.is_ = is_
        self.buf = bytearray(1 << 13)
        self.buf_len = 0
        self.buf_offset = 0
        self.next = 0

    def read(self):
        if self.buf_len == self.buf_offset:
            self.buf_offset = 0
            self.buf_len = self.is_.readinto(self.buf)
        if self.buf_len == 0:
            return -1
        return self.buf[self.buf_offset]

    def skip_blank(self):
        while self.next >= 0 and self.next <= 32:
            self.next = self.read()

    def read_int(self):
        sign = 1
        self.skip_blank()
        if self.next == ord('+') or self.next == ord('-'):
            sign = 1 if self.next == ord('+') else -1
            self.next = self.read()

        val = 0
        if sign == 1:
            while '0' <= chr(self.next) <= '9':
                val = val * 10 + self.next - ord('0')
                self.next = self.read()
        else:
            while '0' <= chr(self.next) <= '9':
                val = val * 10 - self.next + ord('0')
                self.next = self.read()

        return val

class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.rank = [0] * n
        self.size = [1] * n

    def find(self, a):
        if self.p[a] != a:
            self.p[a] = self.find(self.p[a])
        return self.p[a]

    def merge(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return
        if self.rank[a] < self.rank[b]:
            a, b = b, a
        self.size[a] += self.size[b]
        self.p[b] = a
        if self.rank[a] == self.rank[b]:
            self.rank[a] += 1

class Point:
    def __init__(self):
        self.x = 0
        self.y = 0

class Id8:
    def __init__(self, cap, rehash):
        self.mask = (1 << (32 - (cap - 1).bit_length())) - 1
        self.slot = [0] * (self.mask + 1)
        self.next = [0] * (cap + 1)
        self.keys = [0] * (cap + 1)
        self.values = [0] * (cap + 1)
        self.removed = [False] * (cap + 1)
        self.alloc = 0
        self.size = 0
        self.rehash = rehash

    def put(self, x, y):
        h = self.hash(x)
        s = h & self.mask
        if self.slot[s] == 0:
            self.alloc += 1
            self.slot[s] = self.alloc
            self.keys[self.alloc] = x
            self.values[self.alloc] = y
        else:
            index = self.id2(s, x)
            if self.keys[index] != x:
                self.alloc += 1
                self.next[index] = self.alloc
                self.keys[self.alloc] = x
                self.values[self.alloc] = y

    def contain_key(self, x):
        h = self.hash(x)
        s = h & self.mask
        if self.slot[s] == 0:
            return False
        return self.keys[self.id2(s, x)] == x

    def hash(self, x):
        return Hasher().hash(x)

    def id2(self, s, x):
        iter_ = self.slot[s]
        while self.keys[iter_] != x:
            if self.next[iter_] != 0:
                iter_ = self.next[iter_]
            else:
                return iter_
        return iter_

class Id3:
    def __init__(self, q_num, total_capacity):
        self.values = [0] * (total_capacity + 1)
        self.next = [0] * (total_capacity + 1)
        self.heads = [0] * q_num
        self.alloc = 0
        self.stack_num = q_num

    def add_last(self, q_id, x):
        self.alloc += 1
        self.values[self.alloc] = x
        self.next[self.alloc] = self.heads[q_id]
        self.heads[q_id] = self.alloc

    def iterator(self, queue):
        ele = self.heads[queue]
        while ele != 0:
            yield self.values[ele]
            ele = self.next[ele]

class InverseNumber:
    def __init__(self, limit, modular):
        self.inv = [0] * (limit + 1)
        self.inv[1] = 1
        p = modular.m
        for i in range(2, limit + 1):
            k = p // i
            r = p % i
            self.inv[i] = modular.mul(-k, self.inv[r])

class Hasher:
    def __init__(self):
        self.time = random.randint(0, 1 << 30)

    def hash(self, x):
        x += self.time
        x += 0x9e3779b97f4a7c15
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb
        return int(x ^ (x >> 31))

if __name__ == "__main__":
    Main.main()
