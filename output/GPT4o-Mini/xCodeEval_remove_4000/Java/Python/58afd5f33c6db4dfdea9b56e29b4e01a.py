import sys
import random
from collections import defaultdict

class Main:
    @staticmethod
    def main():
        thread = Thread(target=TaskAdapter)
        thread.start()
        thread.join()

class TaskAdapter:
    def run(self):
        input_stream = sys.stdin
        output_stream = sys.stdout
        in_ = FastInput(input_stream)
        out = FastOutput(output_stream)
        solver = Id3()
        solver.solve(1, in_, out)
        out.close()

class Id3:
    def __init__(self):
        self.mu = Id1(100000, False)
        self.euler = Id1(100000, False)
        self.primes = []

        self.mu.put(1, 1)
        self.euler.put(1, 1)

    def id0(self, x):
        for p in self.primes:
            if x % p == 0:
                return p
        return x

    def populate(self, x):
        factor = self.id0(x)
        cnt = 0
        y = x
        while y % factor == 0:
            cnt += 1
            y //= factor
        if cnt > 1:
            self.mu.put(x, 0)
        else:
            self.mu.put(x, -self.mu_func(y))
        self.euler.put(x, self.euler_func(y) * (x // y - x // y // factor))

    def mu_func(self, x):
        ans = self.mu.id5(x, -1)
        if ans == -1:
            self.populate(x)
            ans = self.mu.get(x)
        return ans

    def euler_func(self, x):
        ans = self.euler.id5(x, -1)
        if ans == -1:
            self.populate(x)
            ans = self.euler.get(x)
        return ans

    def solve(self, test_number, in_, out):
        m = in_.read_long()
        x = in_.read_long()

        self.primes = Factorization.id13(m)
        id9 = LongList(20000)
        tmp_list = LongList(20000)
        id2 = LongList()
        for p in self.primes:
            id2.add(p)
            id2.add_all(Factorization.id13(p - 1))
        id2.unique()

        self.collect(id9, m, 0)
        power = LongPower(Id12.get_instance(m))

        total = 1
        for i in range(id9.size()):
            g = id9.get(i)
            if g == m:
                continue
            mg = m // g
            tmp_list.clear()
            self.collect(tmp_list, mg, 0)
            cnt = 0
            for j in range(tmp_list.size() - 1, -1, -1):
                t = tmp_list.get(j)
                cnt += self.mu_func(t) * ((m - 1) // (t * g))

            tmp_list.clear()
            euler = self.euler_func(mg)
            prime_factors = []
            for j in range(id2.size()):
                p = id2.get(j)
                if euler % p == 0:
                    prime_factors.append(p)

            n = euler
            for j in range(len(prime_factors)):
                p = prime_factors[j]
                while n % p == 0 and power.pow(x, n // p) % mg == 1:
                    n //= p

            if cnt % n != 0:
                raise Exception("Illegal State")
            total += cnt // n

        out.println(total)

    def collect(self, lst, x, i):
        if i == len(self.primes):
            lst.add(x)
            return
        self.collect(lst, x, i + 1)
        while x % self.primes[i] == 0:
            x //= self.primes[i]
            self.collect(lst, x, i + 1)

class DigitUtils:
    @staticmethod
    def round(x):
        return int(x + 0.5) if x >= 0 else int(x - 0.5)

    @staticmethod
    def mod(x, mod):
        x %= mod
        if x < 0:
            x += mod
        return x

    @staticmethod
    def mul_mod(a, b, mod):
        k = DigitUtils.round(a / mod * b)
        return DigitUtils.mod(a * b - k * mod, mod)

class FastOutput:
    def __init__(self, os):
        self.cache = []
        self.os = os

    def append(self, csq):
        self.cache.append(csq)
        return self

    def println(self, c):
        self.cache.append(str(c))
        self.println_empty()
        return self

    def println_empty(self):
        self.cache.append('\n')
        return self

    def flush(self):
        self.os.write(''.join(self.cache))
        self.os.flush()
        self.cache.clear()
        return self

    def close(self):
        self.flush()
        self.os.close()

class LongPower:
    def __init__(self, modular):
        self.modular = modular

    def pow(self, x, n):
        if n == 0:
            return 1
        r = self.pow(x, n >> 1)
        r = self.modular.mul(r, r)
        if (n & 1) == 1:
            r = self.modular.mul(r, x)
        return r

class Factorization:
    @staticmethod
    def id13(x):
        ans = LongList()
        for i in range(2, int(x**0.5) + 1):
            if x % i != 0:
                continue
            ans.add(i)
            while x % i == 0:
                x //= i
        if x > 1:
            ans.add(x)
        return ans

class Id1:
    def __init__(self, cap, rehash):
        self.slot = [0] * (1 << (32 - (cap - 1).bit_length()))  # mask
        self.next = [0] * (cap + 1)
        self.keys = [0] * (cap + 1)
        self.values = [0] * (cap + 1)
        self.removed = [False] * (cap + 1)
        self.alloc = 0
        self.size = 0
        self.rehash = rehash

    def double_capacity(self):
        new_size = max(len(self.next) + 10, len(self.next) * 2)
        self.next += [0] * (new_size - len(self.next))
        self.keys += [0] * (new_size - len(self.keys))
        self.values += [0] * (new_size - len(self.values))
        self.removed += [False] * (new_size - len(self.removed))

    def alloc_slot(self):
        self.alloc += 1
        if self.alloc >= len(self.next):
            self.double_capacity()
        self.next[self.alloc] = 0
        self.removed[self.alloc] = False
        self.size += 1

    def rehash_slots(self):
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

    def hash(self, x):
        h = hash(x)
        return h ^ (h >> 16)

    def put(self, x, y, cover=True):
        h = self.hash(x)
        s = h & (len(self.slot) - 1)
        if self.slot[s] == 0:
            self.alloc_slot()
            self.slot[s] = self.alloc
            self.keys[self.alloc] = x
            self.values[self.alloc] = y
        else:
            index = self.id8(s, x)
            if self.keys[index] != x:
                self.alloc_slot()
                self.next[index] = self.alloc
                self.keys[self.alloc] = x
                self.values[self.alloc] = y
            elif cover:
                self.values[index] = y
        if self.rehash and self.size >= len(self.slot):
            self.rehash_slots()

    def id5(self, x, default):
        h = self.hash(x)
        s = h & (len(self.slot) - 1)
        if self.slot[s] == 0:
            return default
        index = self.id8(s, x)
        return self.values[index] if self.keys[index] == x else default

    def get(self, x):
        return self.id5(x, 0)

    def id8(self, s, x):
        iter_ = self.slot[s]
        while self.keys[iter_] != x:
            if self.next[iter_] != 0:
                iter_ = self.next[iter_]
            else:
                return iter_
        return iter_

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

class Id12:
    @staticmethod
    def get_instance(mod):
        return Id4(mod) if mod <= (1 << 54) else Id6(mod)

class Id4:
    def __init__(self, m):
        self.m = m

    def mul(self, a, b):
        return DigitUtils.mul_mod(a, b, self.m)

class Id6:
    def __init__(self, m):
        self.m = m

    def mul(self, a, b):
        return 0 if b == 0 else (self.mul(a, b >> 1) << 1) % self.m + a * (b & 1) % self.m

class LongList:
    def __init__(self, cap=0):
        self.size = 0
        self.cap = cap
        self.data = [0] * cap if cap > 0 else []

    def ensure_space(self, req):
        if req > self.cap:
            while self.cap < req:
                self.cap = max(self.cap + 10, 2 * self.cap)
            self.data += [0] * (self.cap - len(self.data))

    def check_range(self, i):
        if i < 0 or i >= self.size:
            raise IndexError("Index out of range")

    def get(self, i):
        self.check_range(i)
        return self.data[i]

    def add(self, x):
        self.ensure_space(self.size + 1)
        self.data[self.size] = x
        self.size += 1

    def add_all(self, x, offset=0, length=None):
        if length is None:
            length = len(x)
        self.ensure_space(self.size + length)
        self.data[self.size:self.size + length] = x[offset:offset + length]
        self.size += length

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

    def size(self):
        return self.size

    def clear(self):
        self.size = 0

    def sort(self):
        if self.size <= 1:
            return
        random.shuffle(self.data[:self.size])
        self.data[:self.size] = sorted(self.data[:self.size])

    def to_array(self):
        return self.data[:self.size]

    def __str__(self):
        return str(self.to_array())

if __name__ == "__main__":
    Main.main()
