import sys
from collections import deque

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

    def get(self, i):
        if i < 0 or i >= self.size:
            raise IndexError("index out of range")
        return self.data[i]

    def to_array(self):
        return self.data[:self.size]

class FastInput:
    def __init__(self, stream):
        self.stream = stream
        self.buf = bytearray(1 << 13)
        self.buf_len = 0
        self.buf_offset = 0
        self.next = 0

    def read(self):
        if self.buf_offset == self.buf_len:
            self.buf_len = self.stream.readinto(self.buf)
            self.buf_offset = 0
        if self.buf_len == 0:
            return -1
        byte = self.buf[self.buf_offset]
        self.buf_offset += 1
        return byte

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
        while self.next >= ord('0') and self.next <= ord('9'):
            val = val * 10 + self.next - ord('0')
            self.next = self.read()

        return val * sign

    def read_long(self):
        sign = 1
        self.skip_blank()
        if self.next == ord('+') or self.next == ord('-'):
            sign = 1 if self.next == ord('+') else -1
            self.next = self.read()

        val = 0
        while self.next >= ord('0') and self.next <= ord('9'):
            val = val * 10 + self.next - ord('0')
            self.next = self.read()

        return val * sign

class Power:
    def __init__(self, modular):
        self.modular = modular

    def pow(self, x, n):
        if n == 0:
            return self.modular.value_of(1)
        r = self.pow(x, n >> 1)
        r = self.modular.value_of(r * r)
        if n & 1:
            r = self.modular.value_of(r * x)
        return r

    def inverse_by_fermat(self, x):
        return self.pow(x, self.modular.m - 2)

class CYetAnotherNumberSequence:
    def solve(self, test_number, in_stream, out_stream):
        n = in_stream.read_long()
        k = in_stream.read_int()

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
        for num in a:
            seq.add(num)

        solver = LinearRecurrenceSolver.new_solver_from_sequence(seq, mod)
        ans = solver.solve(n - 1, seq)

        out_stream.write(f"{ans}\n")

class LinearRecurrenceSolver:
    def __init__(self, coe, mod):
        self.coe = coe
        self.mod = mod
        self.n = coe.size
        self.pow = Power(mod)
        self.remainder = IntegerList(coe.size)
        self.p = IntegerList(coe.size + 1)
        for i in range(self.n - 1, -1, -1):
            self.p.add(mod.value_of(-coe.get(i)))
        self.p.add(1)

    @staticmethod
    def new_solver_from_sequence(seq, mod):
        lfsr = ModLinearFeedbackShiftRegister(mod, seq.size)
        for i in range(seq.size):
            lfsr.add(seq.get(i))
        coes = IntegerList(lfsr.length())
        for i in range(1, lfsr.length() + 1):
            coes.add(lfsr.code_at(i))
        return LinearRecurrenceSolver(coes, mod)

    def solve(self, k, a):
        if k < a.size:
            return a.get(int(k))
        Polynomials.module(k, self.p, self.remainder, self.pow)
        return self.solve(a)

class ModLinearFeedbackShiftRegister:
    def __init__(self, mod, cap):
        self.cm = IntegerList(cap + 1)
        self.cn = IntegerList(cap + 1)
        self.seq = IntegerList(cap + 1)
        self.buf = IntegerList(cap + 1)
        self.cn.add(1)
        self.mod = mod
        self.pow = Power(mod)
        self.m = -1
        self.dm = 0

    def estimate_delta(self):
        n = self.seq.size - 1
        ans = 0
        cn_data = self.cn.to_array()
        seq_data = self.seq.to_array()
        for i in range(self.cn.size):
            ans = self.mod.plus(ans, self.mod.mul(cn_data[i], seq_data[n - i]))
        return ans

    def add(self, x):
        x = self.mod.value_of(x)
        n = self.seq.size
        self.seq.add(x)
        dn = self.estimate_delta()
        if dn == 0:
            return

        if self.m < 0:
            self.cm = IntegerList(self.cn.size)
            for i in range(self.cn.size):
                self.cm.add(self.cn.get(i))
            self.dm = dn
            self.m = n
            self.cn.ensure_space(n + 2)
            return

        ln = self.cn.size - 1
        len_ = max(ln, n + 1 - ln)
        self.buf = IntegerList(len_)
        for i in range(self.cn.size):
            self.buf.add(self.cn.get(i))
        self.buf.ensure_space(len_ + 1)

        factor = self.mod.mul(dn, self.pow.inverse_by_fermat(self.dm))

        buf_data = self.buf.to_array()
        cm_data = self.cm.to_array()
        for i in range(n - self.m, n - self.m + len(cm_data)):
            buf_data[i] = self.mod.subtract(buf_data[i], self.mod.mul(factor, cm_data[i - (n - self.m)]))

        if self.cn.size < len(buf_data):
            self.cm, self.cn = self.cn, self.cm
            self.m = n
            self.dm = dn

        self.cn, self.buf = self.buf, self.cn

class FastOutput:
    def __init__(self, stream):
        self.cache = []
        self.os = stream

    def println(self, c):
        self.cache.append(str(c) + '\n')
        return self

    def flush(self):
        self.os.write(''.join(self.cache))
        self.cache.clear()
        return self

def main():
    input_stream = FastInput(sys.stdin)
    output_stream = FastOutput(sys.stdout)
    task_adapter = CYetAnotherNumberSequence()
    task_adapter.solve(1, input_stream, output_stream)
    output_stream.flush()

if __name__ == "__main__":
    main()
