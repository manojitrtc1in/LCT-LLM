class FastInput:
    def __init__(self, is):
        self.is_ = is
        self.buf = bytearray()
        self.buf_offset = 0
        self.buf_len = 0
        self.next_ = 0

    def read(self):
        while self.buf_len == self.buf_offset:
            self.buf_offset = 0
            self.buf = self.is_.read(1 << 13)
            self.buf_len = len(self.buf)
            if self.buf_len == 0:
                return -1
        self.next_ = self.buf[self.buf_offset]
        self.buf_offset += 1
        return self.next_

    def skip_blank(self):
        while self.next_ >= 0 and self.next_ <= 32:
            self.next_ = self.read()

    def read_int(self):
        sign = 1
        self.skip_blank()
        if self.next_ == ord('+') or self.next_ == ord('-'):
            sign = 1 if self.next_ == ord('+') else -1
            self.next_ = self.read()
        val = 0
        if sign == 1:
            while self.next_ >= ord('0') and self.next_ <= ord('9'):
                val = val * 10 + self.next_ - ord('0')
                self.next_ = self.read()
        else:
            while self.next_ >= ord('0') and self.next_ <= ord('9'):
                val = val * 10 - self.next_ + ord('0')
                self.next_ = self.read()
        return val


class FastOutput:
    def __init__(self, os):
        self.os = os
        self.cache = bytearray()

    def append(self, csq):
        self.cache.extend(csq.encode())

    def append(self, csq, start, end):
        self.cache.extend(csq.encode()[start:end])

    def append(self, c):
        self.cache.append(c)

    def append(self, x):
        self.cache.extend(str(x).encode())

    def println(self, x):
        self.append(x)
        self.println()

    def println(self):
        self.cache.append(ord('\n'))

    def flush(self):
        self.os.write(self.cache)
        self.os.flush()
        self.cache = bytearray()

    def close(self):
        self.flush()
        self.os.close()


class IntegerList:
    def __init__(self, cap=0):
        self.size = 0
        self.cap = cap
        self.data = []

    def ensure_space(self, req):
        if req > self.cap:
            self.cap = max(self.cap + 10, 2 * self.cap)
            self.data = self.data[:self.cap]

    def add(self, x):
        self.ensure_space(self.size + 1)
        self.data.append(x)
        self.size += 1

    def add_all(self, x, offset, length):
        self.ensure_space(self.size + length)
        self.data.extend(x[offset:offset+length])
        self.size += length

    def add_all(self, lst):
        self.add_all(lst.data, 0, lst.size)

    def sort(self):
        if self.size <= 1:
            return
        self.data = sorted(self.data)

    def unique(self):
        if self.size <= 1:
            return
        self.sort()
        wpos = 1
        for i in range(1, self.size):
            if self.data[i] != self.data[wpos - 1]:
                self.data[wpos] = self.data[i]
                wpos += 1
        self.size = wpos

    def to_array(self):
        return self.data[:self.size]

    def clear(self):
        self.size = 0

    def __str__(self):
        return str(self.to_array())

    def __eq__(self, other):
        if not isinstance(other, IntegerList):
            return False
        return self.data[:self.size] == other.data[:other.size]

    def __hash__(self):
        h = 1
        for i in range(self.size):
            h = h * 31 + hash(self.data[i])
        return h

    def clone(self):
        return IntegerList(self.cap).add_all(self)


class Randomized:
    @staticmethod
    def shuffle(data, from_, to):
        to -= 1
        for i in range(from_, to + 1):
            s = RandomWrapper.next_int(i, to)
            data[i], data[s] = data[s], data[i]

    @staticmethod
    def next_int(l, r):
        return RandomWrapper.next_int(l, r)


class Point:
    def __init__(self):
        self.x = 0
        self.y = 0


class id8:
    def __init__(self, n, rehash):
        self.slot = [0] * (1 << (32 - n.bit_length() - (n == 0)))  # bit_length() returns the number of bits required to represent the number
        self.next = [0] * (n + 1)
        self.keys = [0] * (n + 1)
        self.values = [0] * (n + 1)
        self.alloc = 0
        self.removed = [False] * (n + 1)
        self.mask = len(self.slot) - 1
        self.size = 0
        self.rehash = rehash
        self.hasher = Hasher()

    def double_capacity(self):
        new_size = max(len(self.next) + 10, len(self.next) * 2)
        self.next.extend([0] * (new_size - len(self.next)))
        self.keys.extend([0] * (new_size - len(self.keys)))
        self.values.extend([0] * (new_size - len(self.values)))
        self.removed.extend([False] * (new_size - len(self.removed)))

    def alloc_(self):
        self.alloc += 1
        if self.alloc >= len(self.next):
            self.double_capacity()
        self.next[self.alloc] = 0
        self.removed[self.alloc] = False
        self.size += 1

    def rehash_(self):
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
        return self.hasher.hash(x)

    def put(self, x, y, cover=True):
        h = self.hash(x)
        s = h & self.mask
        if self.slot[s] == 0:
            self.alloc_()
            self.slot[s] = self.alloc
            self.keys[self.alloc] = x
            self.values[self.alloc] = y
        else:
            index = self.id2(s, x)
            if self.keys[index] != x:
                self.alloc_()
                self.next[index] = self.alloc
                self.keys[self.alloc] = x
                self.values[self.alloc] = y
            elif cover:
                self.values[index] = y
        if self.rehash and self.size >= len(self.slot):
            self.rehash_()

    def contain_key(self, x):
        h = self.hash(x)
        s = h & self.mask
        if self.slot[s] == 0:
            return False
        return self.keys[self.id2(s, x)] == x

    def id1(self, x, default):
        h = self.hash(x)
        s = h & self.mask
        if self.slot[s] == 0:
            return default
        index = self.id2(s, x)
        return self.values[index] if self.keys[index] == x else default

    def get(self, x):
        return self.id1(x, 0)

    def id2(self, s, x):
        iter_ = self.slot[s]
        while self.keys[iter_] != x:
            if self.next[iter_] != 0:
                iter_ = self.next[iter_]
            else:
                return iter_
        return iter_

    def iterator(self):
        return id5(self)

    def __str__(self):
        iterator = self.iterator()
        builder = []
        while iterator.has_next():
            iterator.next()
            builder.append(str(iterator.id4()) + "->" + str(iterator.id6()) + ',')
        if builder[-1] == ',':
            builder.pop()
        return '{' + ''.join(builder) + '}'


class id3:
    def __init__(self, q_num, total_capacity):
        self.values = [0] * (total_capacity + 1)
        self.next = [0] * (total_capacity + 1)
        self.heads = [0] * q_num
        self.alloc = 0
        self.stack_num = q_num

    def iterator(self, queue):
        return id5(self, queue)

    def double_capacity(self):
        new_size = max(len(self.next) + 10, len(self.next) * 2)
        self.next.extend([0] * (new_size - len(self.next)))
        self.values.extend([0] * (new_size - len(self.values)))

    def alloc_(self):
        self.alloc += 1
        if self.alloc >= len(self.next):
            self.double_capacity()
        self.next[self.alloc] = 0

    def add_last(self, q_id, x):
        self.alloc_()
        self.values[self.alloc] = x
        self.next[self.alloc] = self.heads[q_id]
        self.heads[q_id] = self.alloc

    def __str__(self):
        builder = []
        for i in range(self.stack_num):
            builder.append(str(i) + ": ")
            iterator = self.iterator(i)
            while iterator.has_next():
                builder.append(str(iterator.next()) + ",")
            if builder[-1] == ',':
                builder.pop()
            builder.append('\n')
        return ''.join(builder)


class id5:
    def __init__(self, id3, queue):
        self.id3 = id3
        self.index = 1
        self.read_index = -1
        self.queue = queue

    def has_next(self):
        while self.index <= self.id3.alloc and self.id3.removed[self.index]:
            self.index += 1
        return self.index <= self.id3.alloc

    def id4(self):
        return self.id3.values[self.read_index]

    def id6(self):
        return self.id3.values[self.read_index]

    def next(self):
        if not self.has_next():
            raise ValueError("No more elements")
        self.read_index = self.index
        self.index += 1


class Hasher:
    def __init__(self):
        self.time = int(time.time() * 1000)

    def shuffle(self, x):
        x += self.time
        x += 0x9e3779b97f4a7c15
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb
        return x ^ (x >> 31)

    def hash(self, x):
        return self.shuffle(x)


class Main:
    @staticmethod
    def main(args):
        thread = threading.Thread(target=Main.TaskAdapter())
        thread.start()
        thread.join()

    class TaskAdapter:
        def run(self):
            input_stream = sys.stdin.buffer
            output_stream = sys.stdout.buffer
            in_ = FastInput(input_stream)
            out = FastOutput(output_stream)
            solver = Main.id7()
            solver.solve(1, in_, out)
            out.close()

    class id7:
        def solve(self, test_number, in_, out):
            n = in_.read_int()
            pts = [Point() for _ in range(n)]
            for i in range(n):
                pts[i].x = in_.read_int()
                pts[i].y = in_.read_int()

            x = id8(n, False)
            y = id8(n, False)
            dsu = DSU(n)
            for i in range(n):
                if x.contain_key(pts[i].x):
                    dsu.merge(x.get(pts[i].x), i)
                if y.contain_key(pts[i].y):
                    dsu.merge(y.get(pts[i].y), i)
                x.put(pts[i].x, i)
                y.put(pts[i].y, i)

            x_stack = id3(n, n)
            y_stack = id3(n, n)
            for i in range(n):
                x_stack.add_last(dsu.find(i), pts[i].x)
                y_stack.add_last(dsu.find(i), pts[i].y)
            x_list = IntegerList(n)
            y_list = IntegerList(n)

            mod = Modular(1e9 + 7)
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

                line = x_list.size() + y_list.size()
                num = dsu.size[i]
                local = 0
                for j in range(num + 1):
                    local = mod.plus(local, comb.combination(line, j))

                ans = mod.mul(ans, local)

            out.println(ans)


class Modular:
    def __init__(self, m):
        self.m = m

    def get_mod(self):
        return self.m

    def value_of(self, x):
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x, y):
        return self.value_of(x * y)

    def plus(self, x, y):
        return self.value_of(x + y)

    def __str__(self):
        return "mod " + str(self.m)


class Combination:
    def __init__(self, factorial):
        self.factorial = factorial
        self.modular = factorial.id0()

    def combination(self, m, n):
        if n > m:
            return 0
        return self.modular.mul(self.modular.mul(self.factorial.fact(m), self.factorial.inv_fact(n)), self.factorial.inv_fact(m - n))


class Factorial:
    def __init__(self, limit, modular):
        self.fact = [0] * (limit + 1)
        self.inv = [0] * (limit + 1)
        self.modular = modular
        self.fact[0] = self.inv[0] = 1
        for i in range(1, limit + 1):
            self.fact[i] = self.modular.mul(self.fact[i - 1], i)
            self.inv[i] = self.modular.mul(self.inv[i - 1], InverseNumber.inv[i])


class InverseNumber:
    inv = []

    @staticmethod
    def init(limit, modular):
        InverseNumber.inv = [0] * (limit + 1)
        InverseNumber.inv[1] = 1
        p = modular.get_mod()
        for i in range(2, limit + 1):
            k = p // i
            r = p % i
            InverseNumber.inv[i] = modular.mul(-k, InverseNumber.inv[r])


class DSU:
    def __init__(self, n):
        self.p = [0] * n
        self.rank = [0] * n
        self.size = [1] * n
        self.reset()

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


class Main:
    @staticmethod
    def main(args):
        thread = threading.Thread(target=Main.TaskAdapter())
        thread.start()
        thread.join()

    class TaskAdapter:
        def run(self):
            input_stream = sys.stdin.buffer
            output_stream = sys.stdout.buffer
            in_ = FastInput(input_stream)
            out = FastOutput(output_stream)
            solver = Main.id7()
            solver.solve(1, in_, out)
            out.close()

    class id7:
        def solve(self, test_number, in_, out):
            n = in_.read_int()
            pts = [Point() for _ in range(n)]
            for i in range(n):
                pts[i].x = in_.read_int()
                pts[i].y = in_.read_int()

            x = id8(n, False)
            y = id8(n, False)
            dsu = DSU(n)
            for i in range(n):
                if x.contain_key(pts[i].x):
                    dsu.merge(x.get(pts[i].x), i)
                if y.contain_key(pts[i].y):
                    dsu.merge(y.get(pts[i].y), i)
                x.put(pts[i].x, i)
                y.put(pts[i].y, i)

            x_stack = id3(n, n)
            y_stack = id3(n, n)
            for i in range(n):
                x_stack.add_last(dsu.find(i), pts[i].x)
                y_stack.add_last(dsu.find(i), pts[i].y)
            x_list = IntegerList(n)
            y_list = IntegerList(n)

            mod = Modular(1e9 + 7)
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

                line = x_list.size() + y_list.size()
                num = dsu.size[i]
                local = 0
                for j in range(num + 1):
                    local = mod.plus(local, comb.combination(line, j))

                ans = mod.mul(ans, local)

            out.println(ans)


class Modular:
    def __init__(self, m):
        self.m = m

    def get_mod(self):
        return self.m

    def value_of(self, x):
        x %= self.m
        if x < 0:
            x += self.m
        return x

    def mul(self, x, y):
        return self.value_of(x * y)

    def plus(self, x, y):
        return self.value_of(x + y)

    def __str__(self):
        return "mod " + str(self.m)


class Combination:
    def __init__(self, factorial):
        self.factorial = factorial
        self.modular = factorial.id0()

    def combination(self, m, n):
        if n > m:
            return 0
        return self.modular.mul(self.modular.mul(self.factorial.fact(m), self.factorial.inv_fact(n)), self.factorial.inv_fact(m - n))


class Factorial:
    def __init__(self, limit, modular):
        self.fact = [0] * (limit + 1)
        self.inv = [0] * (limit + 1)
        self.modular = modular
        self.fact[0] = self.inv[0] = 1
        for i in range(1, limit + 1):
            self.fact[i] = self.modular.mul(self.fact[i - 1], i)
            self.inv[i] = self.modular.mul(self.inv[i - 1], InverseNumber.inv[i])


class InverseNumber:
    inv = []

    @staticmethod
    def init(limit, modular):
        InverseNumber.inv = [0] * (limit + 1)
        InverseNumber.inv[1] = 1
        p = modular.get_mod()
        for i in range(2, limit + 1):
            k = p // i
            r = p % i
            InverseNumber.inv[i] = modular.mul(-k, InverseNumber.inv[r])


class DSU:
    def __init__(self, n):
        self.p = [0] * n
        self.rank = [0] * n
        self.size = [1] * n
        self.reset()

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


if __name__ == '__main__':
    Main.main(sys.argv[1:])
