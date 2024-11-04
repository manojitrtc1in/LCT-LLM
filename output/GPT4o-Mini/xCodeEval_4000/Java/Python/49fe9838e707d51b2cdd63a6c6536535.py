import sys
import random
from collections import defaultdict

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
        solver = GXMouseInTheCampus()
        solver.solve(1, in_, out)
        out.close()

class GXMouseInTheCampus:
    def __init__(self):
        self.mu = LongHashMap(100000, False)
        self.euler = LongHashMap(100000, False)
        self.primes = []

        self.mu.put(1, 1)
        self.euler.put(1, 1)

    def one_of_prime_factor(self, x):
        for p in self.primes:
            if x % p == 0:
                return p
        return x

    def populate(self, x):
        factor = self.one_of_prime_factor(x)
        cnt = 0
        y = x
        while y % factor == 0:
            cnt += 1
            y //= factor
        if cnt > 1:
            self.mu.put(x, 0)
        else:
            self.mu.put(x, -self.mu(y))
        self.euler.put(x, self.euler(y) * (x // y - x // y // factor))

    def mu(self, x):
        ans = self.mu.get_or_default(x, -1)
        if ans == -1:
            self.populate(x)
            ans = self.mu.get(x)
        return ans

    def euler(self, x):
        ans = self.euler.get_or_default(x, -1)
        if ans == -1:
            self.populate(x)
            ans = self.euler.get(x)
        return ans

    def solve(self, test_number, in_, out):
        m = in_.read_long()
        x = in_.read_long()

        self.primes = list(LongPollardRho().find_all_factors(m).keys())
        all_factor_of_m = LongList(20000)
        tmp_list = LongList(20000)
        all_possible_prime_factor = LongList()
        for p in self.primes:
            all_possible_prime_factor.add(p)
            all_possible_prime_factor.add_all(Factorization.factorize_number_prime(p - 1))
        all_possible_prime_factor.unique()

        self.collect(all_factor_of_m, m, 0)
        power = LongPower(ILongModular.get_instance(m))

        total = 1
        for i in range(all_factor_of_m.size()):
            g = all_factor_of_m.get(i)
            if g == m:
                continue
            mg = m // g
            tmp_list.clear()
            self.collect(tmp_list, mg, 0)
            cnt = 0
            for j in range(tmp_list.size() - 1, -1, -1):
                t = tmp_list.get(j)
                cnt += self.mu(t) * ((m - 1) // (t * g))

            tmp_list.clear()
            euler = self.euler(mg)
            prime_factors = tmp_list
            for j in range(all_possible_prime_factor.size()):
                p = all_possible_prime_factor.get(j)
                if euler % p == 0:
                    prime_factors.add(p)

            n = euler
            for j in range(prime_factors.size()):
                p = prime_factors.get(j)
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
        if n & 1 == 1:
            r = self.modular.mul(r, x)
        return r

class Factorization:
    @staticmethod
    def factorize_number_prime(x):
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

class LongHashMap:
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

    def double_capacity(self):
        new_size = max(len(self.next) + 10, len(self.next) * 2)
        self.next = self.next + [0] * (new_size - len(self.next))
        self.keys = self.keys + [0] * (new_size - len(self.keys))
        self.values = self.values + [0] * (new_size - len(self.values))
        self.removed = self.removed + [False] * (new_size - len(self.removed))

    def alloc_slot(self):
        self.alloc += 1
        if self.alloc >= len(self.next):
            self.double_capacity()
        self.next[self.alloc] = 0
        self.removed[self.alloc] = False
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
        h = hash(x)
        return h ^ (h >> 16)

    def put(self, x, y, cover=True):
        h = self.hash(x)
        s = h & self.mask
        if self.slot[s] == 0:
            self.alloc_slot()
            self.slot[s] = self.alloc
            self.keys[self.alloc] = x
            self.values[self.alloc] = y
        else:
            index = self.find_index_or_last_entry(s, x)
            if self.keys[index] != x:
                self.alloc_slot()
                self.next[index] = self.alloc
                self.keys[self.alloc] = x
                self.values[self.alloc] = y
            elif cover:
                self.values[index] = y
        if self.rehash and self.size >= len(self.slot):
            self.rehash()

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
        iter_ = self.slot[s]
        while self.keys[iter_] != x:
            if self.next[iter_] != 0:
                iter_ = self.next[iter_]
            else:
                return iter_
        return iter_

class LongPollardRho:
    def __init__(self):
        self.mr = LongMillerRabin()
        self.modular = None
        self.random = random.Random()

    def find_factor(self, n):
        if self.mr.mr(n, 3):
            return n
        self.modular = ILongModular.get_instance(n)
        while True:
            f = self.find_factor0(int(self.random.random() * n), int(self.random.random() * n), n)
            if f != -1:
                return f

    def find_factor0(self, x, c, n):
        xi = x
        xj = x
        j = 2
        i = 1
        while i < n:
            i += 1
            xi = self.modular.plus(self.modular.mul(xi, xi), c)
            g = GCDs.gcd(n, abs(xi - xj))
            if g != 1 and g != n:
                return g
            if i == j:
                j <<= 1
                xj = xi
        return -1

    def find_all_factors(self, n):
        map_ = {}
        self.find_all_factors_helper(map_, n)
        return map_

    def find_all_factors_helper(self, map_, n):
        if n == 1:
            return
        f = self.find_factor(n)
        if f == n:
            value = map_.get(f, 1)
            map_[f] = value * f
            return
        self.find_all_factors_helper(map_, f)
        self.find_all_factors_helper(map_, n // f)

class GCDs:
    @staticmethod
    def gcd(a, b):
        return a if a >= b else GCDs.gcd(b, a)

    @staticmethod
    def gcd0(a, b):
        return a if b == 0 else GCDs.gcd0(b, a % b)

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
            while self.next >= ord('0') and self.next <= ord('9'):
                val = val * 10 + self.next - ord('0')
                self.next = self.read()
        else:
            while self.next >= ord('0') and self.next <= ord('9'):
                val = val * 10 - self.next + ord('0')
                self.next = self.read()

        return val

class LongEntryIterator:
    def has_next(self):
        raise NotImplementedError

    def next(self):
        raise NotImplementedError

    def get_entry_key(self):
        raise NotImplementedError

    def get_entry_value(self):
        raise NotImplementedError

class LongModular:
    def __init__(self, m):
        self.m = m

    def mul(self, a, b):
        return 0 if b == 0 else (self.mul(a, b >> 1) << 1) % self.m + a * (b & 1) % self.m

    def plus(self, a, b):
        return self.value_of(a + b)

    def value_of(self, a):
        a %= self.m
        if a < 0:
            a += self.m
        return a

class LongMillerRabin:
    def __init__(self):
        self.modular = None
        self.power = None
        self.random = random.Random()

    def mr(self, n, s):
        if n <= 1:
            return False
        if n == 2:
            return True
        if n % 2 == 0:
            return False
        self.modular = ILongModular.get_instance(n)
        self.power = LongPower(self.modular)
        for _ in range(s):
            x = int(self.random.random() * (n - 2) + 2)
            if not self.mr0(x, n):
                return False
        return True

    def mr0(self, x, n):
        exp = n - 1
        while True:
            y = self.power.pow(x, exp)
            if y != 1 and y != n - 1:
                return False
            if y != 1 or exp % 2 == 1:
                break
            exp //= 2
        return True

class LongModularDanger:
    def __init__(self, m):
        self.m = m

    def mul(self, a, b):
        return DigitUtils.mul_mod(a, b, self.m)

    def plus(self, a, b):
        return self.value_of(a + b)

    def value_of(self, a):
        a %= self.m
        if a < 0:
            a += self.m
        return a

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

    def clear(self):
        self.size = 0

    def size(self):
        return self.size

    def unique(self):
        if self.size <= 1:
            return
        self.data = sorted(set(self.data[:self.size]))
        self.size = len(self.data)

class SequenceUtils:
    @staticmethod
    def equal(a, al, ar, b, bl, br):
        if (ar - al) != (br - bl):
            return False
        for i, j in zip(range(al, ar + 1), range(bl, br + 1)):
            if a[i] != b[j]:
                return False
        return True

class Randomized:
    random = random.Random(0)

    @staticmethod
    def shuffle(data, from_, to):
        to -= 1
        for i in range(from_, to + 1):
            s = Randomized.next_int(i, to)
            data[i], data[s] = data[s], data[i]

    @staticmethod
    def next_int(l, r):
        return Randomized.random.randint(l, r)

class ILongModular:
    @staticmethod
    def get_instance(mod):
        return LongModularDanger(mod) if mod <= (1 << 54) else LongModular(mod)
