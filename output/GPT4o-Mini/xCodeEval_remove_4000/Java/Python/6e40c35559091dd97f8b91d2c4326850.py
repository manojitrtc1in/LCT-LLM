import sys
from collections import deque

class Main:
    @staticmethod
    def main():
        thread = Thread(None, TaskAdapter(), "", 1 << 27)
        thread.start()
        thread.join()

class TaskAdapter:
    def run(self):
        input_stream = sys.stdin.buffer
        output_stream = sys.stdout.buffer
        in_ = FastInput(input_stream)
        out = FastOutput(output_stream)
        solver = id5()
        solver.solve(1, in_, out)
        out.close()

class id5:
    def solve(self, test_number, in_, out):
        n = in_.read_long()
        k = in_.read_int()

        mod = Modular(1000000007)
        power = Power(mod)

        items = 200
        fib = [0] * items
        fib[0] = 1
        fib[1] = 2
        a = [0] * items
        for i in range(2, items):
            fib[i] = mod.plus(fib[i - 1], fib[i - 2])
        for i in range(items):
            a[i] = mod.mul(fib[i], power.pow(i + 1, k))
            if i > 0:
                a[i] = mod.plus(a[i], a[i - 1])

        seq = IntegerList()
        seq.add_all(a)
        solver = id9.id2(seq, mod)
        ans = solver.solve(n - 1, seq)

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

    def subtract(self, x, y):
        return self.value_of(x - y)

class IntegerList:
    def __init__(self, cap=0):
        self.size = 0
        self.cap = cap
        self.data = [0] * cap if cap > 0 else []

    def ensure_space(self, req):
        if req > self.cap:
            while self.cap < req:
                self.cap = max(self.cap + 10, 2 * self.cap)
            self.data.extend([0] * (self.cap - len(self.data)))

    def add(self, x):
        self.ensure_space(self.size + 1)
        self.data[self.size] = x
        self.size += 1

    def add_all(self, x):
        self.add_all_with_offset(x, 0, len(x))

    def add_all_with_offset(self, x, offset, length):
        self.ensure_space(self.size + length)
        self.data[self.size:self.size + length] = x[offset:offset + length]
        self.size += length

    def get(self, i):
        if i < 0 or i >= self.size:
            raise IndexError("index out of range")
        return self.data[i]

    def clear(self):
        self.size = 0

    def to_array(self):
        return self.data[:self.size]

class FastInput:
    def __init__(self, is_):
        self.is_ = is_
        self.buf = bytearray(1 << 13)
        self.buf_len = 0
        self.buf_offset = 0
        self.next = 0

    def read(self):
        while self.buf_len == self.buf_offset:
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
            while ord('0') <= self.next <= ord('9'):
                val = val * 10 + self.next - ord('0')
                self.next = self.read()
        else:
            while ord('0') <= self.next <= ord('9'):
                val = val * 10 - self.next + ord('0')
                self.next = self.read()

        return val

    def read_long(self):
        sign = 1
        self.skip_blank()
        if self.next == ord('+') or self.next == ord('-'):
            sign = 1 if self.next == ord('+') else -1
            self.next = self.read()

        val = 0
        if sign == 1:
            while ord('0') <= self.next <= ord('9'):
                val = val * 10 + self.next - ord('0')
                self.next = self.read()
        else:
            while ord('0') <= self.next <= ord('9'):
                val = val * 10 - self.next + ord('0')
                self.next = self.read()

        return val

class FastOutput:
    def __init__(self, os):
        self.cache = bytearray()
        self.os = os

    def println(self, c):
        self.cache.extend(str(c).encode() + b'\n')
        return self

    def flush(self):
        self.os.write(self.cache)
        self.os.flush()
        self.cache.clear()
        return self

    def close(self):
        self.flush()
        self.os.close()

class id9:
    def __init__(self, coe, mod):
        self.coe = coe
        self.mod = mod
        self.n = coe.size
        self.remainder = IntegerList(coe.size)
        self.p = IntegerList(coe.size + 1)
        for i in range(self.n - 1, -1, -1):
            self.p.add(mod.value_of(-coe.get(i)))
        self.p.add(1)

    @staticmethod
    def id2(seq, mod):
        id10 = id0(mod, seq.size)
        for i in range(seq.size):
            id10.add(seq.get(i))
        coes = IntegerList(id10.length())
        for i in range(1, id10.length() + 1):
            coes.add(id10.code_at(i))
        return id9(coes, mod)

    def solve(self, k, a):
        if k < self.coe.size:
            return a.get(int(k))
        Polynomials.module(k, self.p, self.remainder)
        return self.solve(a)

class id0:
    def __init__(self, mod, cap=0):
        self.cm = IntegerList(cap + 1)
        self.cn = IntegerList(cap + 1)
        self.seq = IntegerList(cap + 1)
        self.buf = IntegerList(cap + 1)
        self.cn.add(1)
        self.mod = mod
        self.pow = Power(mod)
        self.m = -1
        self.dm = 0

    def add(self, x):
        x = self.mod.value_of(x)
        n = self.seq.size
        self.seq.add(x)
        dn = self.estimate_delta()
        if dn == 0:
            return

        if self.m < 0:
            self.cm.clear()
            self.cm.add_all(self.cn)
            self.dm = dn
            self.m = n
            self.cn.expand_with(0, n + 2)
            return

        ln = self.cn.size - 1
        len_ = max(ln, n + 1 - ln)
        self.buf.clear()
        self.buf.add_all(self.cn)
        self.buf.expand_with(0, len_ + 1)

        factor = self.mod.mul(dn, self.pow.id7(self.dm))

        for i in range(n - self.m, n - self.m + self.cm.size):
            self.buf.data[i] = self.mod.subtract(self.buf.data[i], self.mod.mul(factor, self.cm.data[i - (n - self.m)]))

        if self.cn.size < self.buf.size:
            self.cm, self.cn = self.cn, self.cm
            self.m = n
            self.dm = dn
        self.cn, self.buf = self.buf, self.cn

    def estimate_delta(self):
        n = self.seq.size - 1
        ans = 0
        cn_data = self.cn.data
        seq_data = self.seq.data
        for i in range(self.cn.size):
            ans = self.mod.plus(ans, self.mod.mul(cn_data[i], seq_data[n - i]))
        return ans

    def length(self):
        return self.cn.size - 1

    def code_at(self, i):
        return self.mod.value_of(-self.cn.get(i))

class Power:
    def __init__(self, modular):
        self.modular = modular

    def pow(self, x, n):
        if n == 0:
            return self.modular.value_of(1)
        r = self.pow(x, n >> 1)
        r = self.modular.value_of(r * r)
        if (n & 1) == 1:
            r = self.modular.value_of(r * x)
        return r

    def id7(self, x):
        return self.pow(x, self.modular.m - 2)

class Polynomials:
    list_buffer = Buffer(IntegerList, lambda list_: list_.clear())

    @staticmethod
    def module(k, p, remainder):
        rP = Polynomials.rank_of(p)
        if rP == 0:
            remainder.clear()
            remainder.add(0)
            return

        a = Polynomials.list_buffer.alloc()
        c = Polynomials.list_buffer.alloc()

        Polynomials.module(k, a, p, c, remainder, rP)

        Polynomials.list_buffer.release(a)
        Polynomials.list_buffer.release(c)

    @staticmethod
    def rank_of(p):
        data = p.data
        r = p.size - 1
        while r >= 0 and data[r] == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def divide(a, b, c, remainder):
        rA = Polynomials.rank_of(a)
        rB = Polynomials.rank_of(b)

        if rA < rB:
            c.clear()
            c.add(0)
            remainder.clear()
            remainder.add_all(a)
            return

        rC = max(0, rA - rB)
        c.clear()
        c.expand_with(0, rC + 1)
        remainder.clear()
        remainder.add_all(a)

        b_data = b.data
        c_data = c.data
        r_data = remainder.data

        if id8.id3(b.get(rB), mod.get_mod()) != 1:
            raise ValueError("Invalid argument")
        inv = mod.value_of(id8.get_x())
        for i in range(rA, rB - 1, -1):
            if r_data[i] == 0:
                continue
            factor = mod.mul(-r_data[i], inv)
            c_data[j] = mod.value_of(-factor)
            for k in range(rB, -1, -1):
                r_data[k + j] = mod.plus(r_data[k + j], mod.mul(factor, b_data[k]))

        Polynomials.normalize(remainder)

    @staticmethod
    def normalize(list_):
        list_.retain(Polynomials.rank_of(list_) + 1)

class Buffer:
    def __init__(self, supplier, cleaner=lambda x: None, exp=0):
        self.supplier = supplier
        self.cleaner = cleaner
        self.deque = deque(maxlen=exp)

    def alloc(self):
        return self.deque.popleft() if self.deque else self.supplier()

    def release(self, e):
        self.cleaner(e)
        self.deque.append(e)

class Thread:
    def __init__(self, group, target, name, stack_size):
        self.group = group
        self.target = target
        self.name = name
        self.stack_size = stack_size

    def start(self):
        self.target.run()

    def join(self):
        pass

if __name__ == "__main__":
    Main.main()
