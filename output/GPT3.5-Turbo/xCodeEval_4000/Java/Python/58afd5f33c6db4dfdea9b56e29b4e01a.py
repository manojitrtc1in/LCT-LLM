class LongHashMap:
    def __init__(self, cap, rehash):
        self.slot = [0] * (cap + 1)
        self.next = [0] * (cap + 1)
        self.keys = [0] * (cap + 1)
        self.values = [0] * (cap + 1)
        self.removed = [False] * (cap + 1)
        self.alloc = 0
        self.mask = (1 << (32 - cap.bit_length())) - 1
        self.size = 0
        self.rehash = rehash

    def double_capacity(self):
        new_size = max(self.next) + 10
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

    def iterator(self):
        index = 1
        read_index = -1

        def has_next():
            nonlocal index
            while index <= self.alloc and self.removed[index]:
                index += 1
            return index <= self.alloc

        def get_entry_key():
            return self.keys[read_index]

        def get_entry_value():
            return self.values[read_index]

        def next():
            nonlocal read_index
            if not has_next():
                raise StopIteration()
            read_index = index
            index += 1

        return {'has_next': has_next, 'get_entry_key': get_entry_key, 'get_entry_value': get_entry_value, 'next': next}

    def __str__(self):
        iterator = self.iterator()
        builder = "{"
        while iterator['has_next']():
            iterator['next']()
            builder += str(iterator['get_entry_key']()) + "->" + str(iterator['get_entry_value']()) + ","
        if builder[-1] == ",":
            builder = builder[:-1]
        builder += "}"
        return builder


class FastInput:
    def __init__(self, is_):
        self.is_ = is_

    def read(self):
        return self.is_.read(1)

    def skip_blank(self):
        while self.read() <= ' ':
            pass

    def read_long(self):
        sign = 1

        self.skip_blank()
        if self.read() == '+' or self.read() == '-':
            sign = 1 if self.read() == '+' else -1
            self.read()

        val = 0
        if sign == 1:
            while '0' <= self.read() <= '9':
                val = val * 10 + int(self.read())
                self.read()
        else:
            while '0' <= self.read() <= '9':
                val = val * 10 - int(self.read())
                self.read()

        return val


class FastOutput:
    def __init__(self, os):
        self.cache = ""
        self.os = os

    def append(self, csq):
        self.cache += csq
        return self

    def println(self, c):
        self.cache += str(c) + "\n"
        self.flush()
        return self

    def println(self):
        self.cache += "\n"
        self.flush()
        return self

    def flush(self):
        self.os.write(self.cache)
        self.os.flush()
        self.cache = ""

    def close(self):
        self.flush()
        self.os.close()


class LongList:
    def __init__(self, cap=0):
        self.size = 0
        self.cap = cap
        self.data = [] if cap == 0 else [0] * cap

    def ensure_space(self, req):
        if req > self.cap:
            self.cap = max(self.cap + 10, 2 * self.cap)
            self.data.extend([0] * (self.cap - len(self.data)))

    def check_range(self, i):
        if i < 0 or i >= self.size:
            raise IndexError()

    def get(self, i):
        self.check_range(i)
        return self.data[i]

    def add(self, x):
        self.ensure_space(self.size + 1)
        self.data[self.size] = x
        self.size += 1

    def add_all(self, x, offset, length):
        self.ensure_space(self.size + length)
        self.data[self.size:self.size + length] = x[offset:offset + length]
        self.size += length

    def add_all(self, lst):
        self.add_all(lst.data, 0, lst.size)

    def sort(self):
        if self.size <= 1:
            return
        random.shuffle(self.data)
        self.data.sort()

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

    def to_array(self):
        return self.data[:self.size]

    def clear(self):
        self.size = 0

    def __str__(self):
        return str(self.to_array())

    def __eq__(self, other):
        if not isinstance(other, LongList):
            return False
        return self.data[:self.size] == other.data[:other.size]

    def __hash__(self):
        h = 1
        for i in range(self.size):
            h = h * 31 + hash(self.data[i])
        return h

    def clone(self):
        ans = LongList()
        ans.add_all(self)
        return ans


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
        i = 2
        while i * i <= x:
            if x % i != 0:
                continue
            ans.add(i)
            while x % i == 0:
                x //= i
        if x > 1:
            ans.add(x)
        return ans


class Randomized:
    @staticmethod
    def shuffle(data, from_, to):
        to -= 1
        for i in range(from_, to + 1):
            s = Randomized.next_int(i, to)
            tmp = data[i]
            data[i] = data[s]
            data[s] = tmp

    @staticmethod
    def next_int(l, r):
        return random.randint(l, r)


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

        self.primes = Factorization.factorize_number_prime(m).to_array()
        all_factor_of_m = LongList(20000)
        tmp_list = LongList(20000)
        all_possible_prime_factor = LongList()
        for p in self.primes:
            all_possible_prime_factor.add(p)
            all_possible_prime_factor.add_all(Factorization.factorize_number_prime(p - 1))
        all_possible_prime_factor.unique()

        self.collect(all_factor_of_m, m, 0)
        power = LongPower(ILongModular(m))

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
                raise ValueError()
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


def main():
    in_stream = FastInput(sys.stdin)
    out_stream = FastOutput(sys.stdout)
    solver = GXMouseInTheCampus()
    solver.solve(1, in_stream, out_stream)
    out_stream.close()


if __name__ == '__main__':
    main()
