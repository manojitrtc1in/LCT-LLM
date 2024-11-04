class Point:
    def __init__(self):
        self.x = 0
        self.y = 0


class DSU:
    def __init__(self, n):
        self.p = [i for i in range(n)]
        self.rank = [0] * n
        self.size = [1] * n

    def reset(self):
        for i in range(len(self.p)):
            self.p[i] = i
            self.rank[i] = 0
            self.size[i] = 1

    def find(self, a):
        if self.p[a] == self.p[self.p[a]]:
            return self.p[a]
        self.p[a] = self.find(self.p[a])
        return self.p[a]

    def merge(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return
        if self.rank[a] == self.rank[b]:
            self.rank[a] += 1
        if self.rank[a] < self.rank[b]:
            a, b = b, a
        self.size[a] += self.size[b]
        self.p[b] = a


class IntegerHashMap:
    def __init__(self, cap, rehash):
        self.slot = [0] * cap
        self.next = [0] * (cap + 1)
        self.keys = [0] * (cap + 1)
        self.values = [0] * (cap + 1)
        self.removed = [False] * (cap + 1)
        self.alloc = 0
        self.mask = (1 << (32 - cap.bit_length())) - 1
        self.size = 0
        self.rehash = rehash

    def double_capacity(self):
        new_size = max(len(self.next) + 10, len(self.next) * 2)
        self.next.extend([0] * (new_size - len(self.next)))
        self.keys.extend([0] * (new_size - len(self.keys)))
        self.values.extend([0] * (new_size - len(self.values)))
        self.removed.extend([False] * (new_size - len(self.removed)))

    def alloc(self):
        self.alloc += 1
        if self.alloc >= len(self.next):
            self.double_capacity()
        self.next[self.alloc] = 0
        self.size += 1

    def rehash(self):
        new_slots = [0] * max(16, len(self.slot) * 2)
        new_mask = len(new_slots) - 1
        for i in range(len(self.slot)):
            if self.slot[i] == 0:
                continue
            head = self.slot[i]
            while head != 0:
                n = self.next[head]
                s = self.hash(self.keys[head]) & new_mask
                self.next[head] = new_slots[s]
                new_slots[s] = head
                head = n
        self.slot = new_slots
        self.mask = new_mask

    def hash(self, x):
        x = ((x >> 16) ^ x) * 0x45d9f3b
        x = ((x >> 16) ^ x) * 0x45d9f3b
        x = (x >> 16) ^ x
        return x & self.mask

    def put(self, x, y, cover=True):
        h = self.hash(x)
        s = h & self.mask
        if self.slot[s] == 0:
            self.alloc()
            self.slot[s] = self.alloc
            self.keys[self.alloc] = x
            self.values[self.alloc] = y
        else:
            index = self.find_index_or_last_entry(s, x)
            if self.keys[index] != x:
                self.alloc()
                self.next[index] = self.alloc
                self.keys[self.alloc] = x
                self.values[self.alloc] = y
            elif cover:
                self.values[index] = y
        if self.rehash and self.size >= len(self.slot):
            self.rehash()

    def contain_key(self, x):
        h = self.hash(x)
        s = h & self.mask
        if self.slot[s] == 0:
            return False
        return self.keys[self.find_index_or_last_entry(s, x)] == x

    def get_or_default(self, x, default):
        h = self.hash(x)
        s = h & self.mask
        if self.slot[s] == 0:
            return default
        index = self.find_index_or_last_entry(s, x)
        return self.values[index] if self.keys[index] == x else default

    def get(self, x):
        return self.get_or_default(x, 0)

    def find_index_or_last_entry(self, s, x):
        iter = self.slot[s]
        while self.keys[iter] != x:
            if self.next[iter] != 0:
                iter = self.next[iter]
            else:
                return iter
        return iter


class IntegerMultiWayStack:
    def __init__(self, q_num, total_capacity):
        self.values = [0] * (total_capacity + 1)
        self.next = [0] * (total_capacity + 1)
        self.heads = [0] * q_num
        self.alloc = 0
        self.stack_num = q_num

    def iterator(self, queue):
        ele = self.heads[queue]
        while ele != 0:
            yield self.values[ele]
            ele = self.next[ele]

    def add_last(self, q_id, x):
        self.alloc += 1
        self.values[self.alloc] = x
        self.next[self.alloc] = self.heads[q_id]
        self.heads[q_id] = self.alloc


class CPointsLinesAndReadyMadeTitles:
    def solve(self, test_number, in_stream, out_stream):
        n = in_stream.readInt()
        pts = [Point() for _ in range(n)]
        for i in range(n):
            pts[i].x = in_stream.readInt()
            pts[i].y = in_stream.readInt()

        x = IntegerHashMap(n, False)
        y = IntegerHashMap(n, False)
        dsu = DSU(n)
        for i in range(n):
            if x.contain_key(pts[i].x):
                dsu.merge(x.get(pts[i].x), i)
            if y.contain_key(pts[i].y):
                dsu.merge(y.get(pts[i].y), i)
            x.put(pts[i].x, i)
            y.put(pts[i].y, i)

        x_stack = IntegerMultiWayStack(n, n)
        y_stack = IntegerMultiWayStack(n, n)
        for i in range(n):
            x_stack.add_last(dsu.find(i), pts[i].x)
            y_stack.add_last(dsu.find(i), pts[i].y)
        x_list = []
        y_list = []

        mod = 10**9 + 7
        comb = Combination(2 * n, mod)
        ans = 1
        for i in range(n):
            if dsu.find(i) != i:
                continue
            x_list.clear()
            y_list.clear()
            x_list.extend(x_stack.iterator(i))
            y_list.extend(y_stack.iterator(i))
            x_list = list(set(x_list))
            y_list = list(set(y_list))

            line = len(x_list) + len(y_list)
            num = dsu.size[i]
            local = 0
            for j in range(num + 1):
                local = (local + comb.combination(line, j)) % mod

            ans = (ans * local) % mod

        out_stream.println(ans)


class FastInput:
    def __init__(self, is_stream):
        self.is_stream = is_stream
        self.buf = bytearray(1 << 13)
        self.buf_len = 0
        self.buf_offset = 0
        self.next = 0

    def read(self):
        while self.buf_len == self.buf_offset:
            self.buf_offset = 0
            self.buf_len = self.is_stream.readinto(self.buf)
            if self.buf_len == 0:
                return -1
        self.next = self.buf[self.buf_offset]
        self.buf_offset += 1
        return self.next

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
            while self.next >= ord('0') and self.next <= ord('9'):
                val = val * 10 + self.next - ord('0')
                self.next = self.read()
        else:
            while self.next >= ord('0') and self.next <= ord('9'):
                val = val * 10 - self.next + ord('0')
                self.next = self.read()

        return val


class FastOutput:
    def __init__(self, os_stream):
        self.os_stream = os_stream
        self.cache = bytearray()

    def append(self, csq):
        self.cache.extend(csq.encode())

    def println(self, c=None):
        if c is not None:
            self.cache.extend(str(c).encode())
        self.cache.extend(b'\n')

    def flush(self):
        self.os_stream.write(self.cache)
        self.os_stream.flush()
        self.cache = bytearray()

    def close(self):
        self.flush()
        self.os_stream.close()


def main():
    in_stream = FastInput(sys.stdin.buffer)
    out_stream = FastOutput(sys.stdout.buffer)
    task = CPointsLinesAndReadyMadeTitles()
    task.solve(1, in_stream, out_stream)
    out_stream.close()


if __name__ == '__main__':
    main()
