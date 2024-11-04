import sys
from typing import List, Tuple, Dict
from collections import defaultdict
import math


class FastInput:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = []
        self.buffer_index = 0

    def read(self):
        if self.buffer_index >= len(self.buffer):
            self.buffer = self.input_stream.readline().split()
            self.buffer_index = 0
        result = self.buffer[self.buffer_index]
        self.buffer_index += 1
        return result

    def read_int(self):
        return int(self.read())

    def read_long(self):
        return int(self.read())

    def read_float(self):
        return float(self.read())

    def read_double(self):
        return float(self.read())

    def read_string(self):
        return self.read()

    def read_line(self):
        return self.input_stream.readline().strip()


class FastOutput:
    def __init__(self, output_stream):
        self.output_stream = output_stream

    def print(self, *args, sep=' ', end='\n'):
        print(*args, sep=sep, end=end, file=self.output_stream)

    def println(self, *args, sep=' ', end='\n'):
        print(*args, sep=sep, end=end, file=self.output_stream)

    def flush(self):
        self.output_stream.flush()


class LongHashMap:
    def __init__(self, cap, rehash):
        self.slot = [0] * cap
        self.next = [0] * (cap + 1)
        self.keys = [0] * (cap + 1)
        self.values = [0] * (cap + 1)
        self.alloc = 0
        self.removed = [False] * (cap + 1)
        self.mask = (1 << (32 - int(math.log2(cap - 1)))) - 1
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

    def __str__(self):
        entries = []
        for i in range(len(self.slot)):
            if self.slot[i] == 0:
                continue
            head = self.slot[i]
            while head != 0:
                entries.append((self.keys[head], self.values[head]))
                head = self.next[head]
        return str(entries)


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
        ans = []
        for i in range(2, int(math.sqrt(x)) + 1):
            if x % i == 0:
                ans.append(i)
                while x % i == 0:
                    x //= i
        if x > 1:
            ans.append(x)
        return ans


class LongPollardRho:
    def __init__(self):
        self.mr = LongMillerRabin()
        self.modular = None
        self.random = random.Random()

    def find_factor(self, n):
        if self.mr.mr(n, 3):
            return n
        self.modular = LongModular(n)
        while True:
            f = self.find_factor_0(int(self.random.random() * n), int(self.random.random() * n), n)
            if f != -1:
                return f

    def find_factor_0(self, x, c, n):
        xi = x
        xj = x
        j = 2
        i = 1
        while i < n:
            i += 1
            xi = self.modular.plus(self.modular.mul(xi, xi), c)
            g = math.gcd(n, abs(xi - xj))
            if g != 1 and g != n:
                return g
            if i == j:
                j = j << 1
                xj = xi
        return -1

    def find_all_factors(self, n):
        factors = defaultdict(int)
        self.find_all_factors_0(factors, n)
        return factors

    def find_all_factors_0(self, factors, n):
        if n == 1:
            return
        f = self.find_factor(n)
        if f == n:
            factors[f] += 1
            return
        self.find_all_factors_0(factors, f)
        self.find_all_factors_0(factors, n // f)


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
        self.modular = LongModular(n)
        self.power = LongPower(self.modular)
        for _ in range(s):
            x = int(self.random.random() * (n - 2) + 2)
            if not self.mr_0(x, n):
                return False
        return True

    def mr_0(self, x, n):
        exp = n - 1
        while True:
            y = self.power.pow(x, exp)
            if y != 1 and y != n - 1:
                return False
            if y != 1 or exp % 2 == 1:
                break
            exp = exp // 2
        return True


class LongModular:
    def __init__(self, m):
        self.m = m

    def mul(self, a, b):
        return b if a == 0 else ((self.mul(a >> 1, b) << 1) % self.m + a % 2 * b) % self.m

    def plus(self, a, b):
        return (a + b) % self.m

    def value_of(self, a):
        a %= self.m
        if a < 0:
            a += self.m
        return a


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

    def solve(self, m, x):
        self.primes = list(LongPollardRho().find_all_factors(m).keys())

        all_factor_of_m = []
        tmp_list = []
        all_possible_prime_factor = []
        for p in self.primes:
            all_possible_prime_factor.append(p)
            all_possible_prime_factor.extend(Factorization.factorize_number_prime(p - 1))
        all_possible_prime_factor = list(set(all_possible_prime_factor))

        self.collect(all_factor_of_m, m, 0)
        power = LongPower(LongModular(m))

        total = 1
        for g in all_factor_of_m:
            if g == m:
                continue
            mg = m // g
            tmp_list.clear()
            self.collect(tmp_list, mg, 0)
            cnt = 0
            for j in range(len(tmp_list) - 1, -1, -1):
                t = tmp_list[j]
                cnt += self.mu(t) * ((m - 1) // (t * g))

            tmp_list.clear()
            euler = self.euler(mg)
            prime_factors = []
            for p in all_possible_prime_factor:
                if euler % p == 0:
                    prime_factors.append(p)

            n = euler
            for p in prime_factors:
                while n % p == 0 and power.pow(x, n // p) % mg == 1:
                    n //= p

            if cnt % n != 0:
                raise ValueError()
            total += cnt // n

        return total

    def collect(self, lst, x, i):
        if i == len(self.primes):
            lst.append(x)
            return
        self.collect(lst, x, i + 1)
        while x % self.primes[i] == 0:
            x //= self.primes[i]
            self.collect(lst, x, i + 1)


def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    fast_input = FastInput(input_stream)
    fast_output = FastOutput(output_stream)

    m = fast_input.read_long()
    x = fast_input.read_long()

    solver = GXMouseInTheCampus()
    result = solver.solve(m, x)

    fast_output.println(result)
    fast_output.flush()


if __name__ == '__main__':
    main()
