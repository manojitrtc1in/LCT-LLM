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
        self.data = []

    def ensure_space(self, req):
        if req > self.cap:
            while self.cap < req:
                self.cap = max(self.cap + 10, 2 * self.cap)
            self.data = self.data[:self.cap]

    def check_range(self, i):
        if i < 0 or i >= self.size:
            raise IndexError(f"index {i} out of range")

    def get(self, i):
        self.check_range(i)
        return self.data[i]

    def add(self, x):
        self.ensure_space(self.size + 1)
        self.data.append(x)
        self.size += 1

    def add_all(self, x, offset=0, length=None):
        if length is None:
            length = len(x)
        self.ensure_space(self.size + length)
        self.data.extend(x[offset:offset+length])
        self.size += length

    def add_all_list(self, lst):
        self.add_all(lst.data, 0, lst.size)

    def expand_with(self, x, length):
        self.ensure_space(self.size + length)
        for _ in range(length):
            self.data.append(x)
        self.size += length

    def retain(self, n):
        if n < 0:
            raise ValueError("n must be non-negative")
        if n >= self.size:
            return
        self.size = n

    def set(self, i, x):
        self.check_range(i)
        self.data[i] = x

    def to_array(self):
        return self.data[:self.size]

    def clear(self):
        self.size = 0

    def __str__(self):
        return str(self.to_array())

    def __eq__(self, other):
        if not isinstance(other, IntegerList):
            return False
        return self.to_array() == other.to_array()

    def __hash__(self):
        h = 1
        for i in range(self.size):
            h = h * 31 + hash(self.data[i])
        return h

    def clone(self):
        ans = IntegerList()
        ans.add_all_list(self)
        return ans


class SequenceUtils:
    @staticmethod
    def equal(a, al, ar, b, bl, br):
        if (ar - al) != (br - bl):
            return False
        for i in range(al, ar+1):
            if a[i] != b[i-bl]:
                return False
        return True


class ModLinearFeedbackShiftRegister:
    def __init__(self, mod, cap=0):
        self.cm = IntegerList(cap + 1)
        self.m = -1
        self.dm = 0
        self.cn = IntegerList(cap + 1)
        self.buf = IntegerList(cap + 1)
        self.seq = IntegerList(cap + 1)
        self.mod = mod
        self.pow = Power(mod)
        self.cn.add(1)

    def estimate_delta(self):
        n = self.seq.size - 1
        ans = 0
        cn_data = self.cn.data
        seq_data = self.seq.data
        for i in range(len(self.cn)):
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
            self.cm.clear()
            self.cm.add_all_list(self.cn)
            self.dm = dn
            self.m = n

            self.cn.expand_with(0, n + 2)
            return

        ln = self.cn.size - 1
        length = max(ln, n + 1 - ln)
        self.buf.clear()
        self.buf.add_all_list(self.cn)
        self.buf.expand_with(0, length + 1)

        factor = self.mod.mul(dn, self.pow.inverse_by_fermat(self.dm))

        buf_data = self.buf.data
        cm_data = self.cm.data
        for i in range(n - self.m, n - self.m + len(self.cm)):
            buf_data[i] = self.mod.subtract(buf_data[i], self.mod.mul(factor, cm_data[i - (n - self.m)]))

        if self.cn.size < len(self.buf):
            self.cm, self.cn = self.cn, self.cm
            self.m = n
            self.dm = dn
        else:
            self.cn, self.buf = self.buf, self.cn


class FastOutput:
    def __init__(self, os):
        self.cache = []
        self.os = os

    def println(self, c):
        self.cache.append(str(c) + '\n')

    def flush(self):
        self.os.write(''.join(self.cache))
        self.os.flush()
        self.cache = []

    def close(self):
        self.flush()
        self.os.close()

    def __str__(self):
        return ''.join(self.cache)


class FastInput:
    def __init__(self, is_):
        self.is_ = is_
        self.buf = bytearray()
        self.buf_len = 0
        self.buf_offset = 0
        self.next = 0

    def read(self):
        while self.buf_len == self.buf_offset:
            self.buf_offset = 0
            self.buf = self.is_.read(1 << 13)
            self.buf_len = len(self.buf)
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

    def read_long(self):
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


class Power:
    def __init__(self, modular):
        self.modular = modular

    def pow(self, x, n):
        if n == 0:
            return self.modular.value_of(1)
        r = self.pow(x, n >> 1)
        r = self.modular.value_of(r * r)
        if n & 1 == 1:
            r = self.modular.value_of(r * x)
        return r

    def inverse_by_fermat(self, x):
        return self.pow(x, self.modular.m - 2)


class Polynomials:
    @staticmethod
    def rank_of(p):
        r = len(p) - 1
        while r >= 0 and p[r] == 0:
            r -= 1
        return max(0, r)

    @staticmethod
    def normalize(lst):
        lst.retain(Polynomials.rank_of(lst) + 1)

    @staticmethod
    def mul(a, b, c, mod):
        rA = Polynomials.rank_of(a)
        rB = Polynomials.rank_of(b)
        c.clear()
        c.expand_with(0, rA + rB + 1)
        for i in range(rA + 1):
            for j in range(rB + 1):
                c[i + j] = mod.plus(c[i + j], mod.mul(a[i], b[j]))

    @staticmethod
    def divide(a, b, c, remainder, pow):
        mod = pow.get_modular()
        rA = Polynomials.rank_of(a)
        rB = Polynomials.rank_of(b)

        if rA < rB:
            c.clear()
            c.add(0)
            remainder.clear()
            remainder.add_all_list(a)
            return

        rC = max(0, rA - rB)
        c.clear()
        c.expand_with(0, rC + 1)
        remainder.clear()
        remainder.add_all_list(a)

        if pow.extgcd(b[rB], mod.get_mod()) != 1:
            raise ValueError()
        inv = mod.value_of(pow.extgcd.getX())
        for i in range(rA, rB-1, -1):
            if remainder[i] == 0:
                continue
            factor = mod.mul(-remainder[i], inv)
            c[i - rB] = mod.value_of(-factor)
            for j in range(rB, -1, -1):
                remainder[j + i - rB] = mod.plus(remainder[j + i - rB], mod.mul(factor, b[j]))

        Polynomials.normalize(remainder)

    @staticmethod
    def module(k, p, remainder, pow):
        rP = Polynomials.rank_of(p)
        if rP == 0:
            remainder.clear()
            remainder.add(0)
            return

        a = IntegerList()
        c = IntegerList()

        Polynomials.module(k, a, p, c, remainder, rP, pow)

    @staticmethod
    def module(k, a, b, c, remainder, rb, pow):
        mod = pow.get_modular()
        if k < rb:
            remainder.clear()
            remainder.expand_with(0, k + 1)
            remainder[k] = 1
            return
        Polynomials.module(k // 2, a, b, c, remainder, rb, pow)
        Polynomials.mul(remainder, remainder, a, mod)
        if k % 2 == 1:
            ra = Polynomials.rank_of(a)
            a.expand_with(0, ra + 2)
            for i in range(ra, -1, -1):
                a[i + 1] = a[i]
            a[0] = 0
        Polynomials.divide(a, b, c, remainder, pow)


class LinearRecurrenceSolver:
    def __init__(self, coe, mod):
        self.mod = mod
        self.coe = coe
        self.p = IntegerList(coe.size() + 1)
        self.remainder = IntegerList(coe.size())
        self.pow = Power(mod)
        for i in range(coe.size() - 1, -1, -1):
            self.p.add(mod.value_of(-coe.get(i)))
        self.p.add(1)

    @staticmethod
    def new_solver_from_linear_recurrence(coe, mod):
        return LinearRecurrenceSolver(coe, mod)

    @staticmethod
    def new_solver_from_sequence(seq, mod):
        lfsr = ModLinearFeedbackShiftRegister(mod, seq.size())
        for i in range(seq.size()):
            lfsr.add(seq.get(i))
        coes = IntegerList(lfsr.length())
        for i in range(1, lfsr.length() + 1):
            coes.add(lfsr.code_at(i))
        return LinearRecurrenceSolver.new_solver_from_linear_recurrence(coes, mod)

    def solve(self, a):
        ans = 0
        self.remainder.expand_with(0, self.coe.size())
        for i in range(self.coe.size()):
            ans = self.mod.plus(ans, self.mod.mul(self.remainder.get(i), a.get(i)))
        return ans

    def solve_k(self, k, a):
        if k < a.size():
            return a.get(k)
        Polynomials.module(k, self.p, self.remainder, self.pow)
        return self.solve(a)


def main():
    n, k = map(int, input().split())

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
    solver = LinearRecurrenceSolver.new_solver_from_sequence(seq, mod)
    ans = solver.solve_k(n - 1, seq)

    print(ans)


if __name__ == '__main__':
    main()
