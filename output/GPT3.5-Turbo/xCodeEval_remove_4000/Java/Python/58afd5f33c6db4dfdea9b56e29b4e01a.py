import sys
from typing import List
from io import IOBase, BytesIO

# Fast I/O implementation
class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")


class id1:
    def __init__(self, cap, rehash):
        self.slot = [0] * (1 << (32 - cap.bit_length() - (cap & 1 == 0))) if cap > 0 else []
        self.next = [0] * (cap + 1) if cap > 0 else []
        self.keys = [0] * (cap + 1) if cap > 0 else []
        self.values = [0] * (cap + 1) if cap > 0 else []
        self.alloc = 0
        self.removed = [False] * (cap + 1) if cap > 0 else []
        self.mask = len(self.slot) - 1 if cap > 0 else 0
        self.size = 0
        self.rehash = rehash

    def doubleCapacity(self):
        newSize = max(len(self.next) + 10, len(self.next) * 2)
        self.next.extend([0] * (newSize - len(self.next)))
        self.keys.extend([0] * (newSize - len(self.keys)))
        self.values.extend([0] * (newSize - len(self.values)))
        self.removed.extend([False] * (newSize - len(self.removed)))

    def alloc(self):
        self.alloc += 1
        if self.alloc >= len(self.next):
            self.doubleCapacity()
        self.next[self.alloc] = 0
        self.removed[self.alloc] = False
        self.size += 1

    def rehash(self):
        newSlots = [0] * max(16, len(self.slot) * 2)
        newMask = len(newSlots) - 1
        for i in range(len(self.slot)):
            if self.slot[i] == 0:
                continue
            head = self.slot[i]
            while head != 0:
                n = self.next[head]
                s = self.hash(self.keys[head]) & newMask
                self.next[head] = newSlots[s]
                newSlots[s] = head
                head = n
        self.slot = newSlots
        self.mask = newMask

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
            index = self.id8(s, x)
            if self.keys[index] != x:
                self.alloc()
                self.next[index] = self.alloc
                self.keys[self.alloc] = x
                self.values[self.alloc] = y
            elif cover:
                self.values[index] = y
        if self.rehash and self.size >= len(self.slot):
            self.rehash()

    def id5(self, x, default):
        h = self.hash(x)
        s = h & self.mask
        if self.slot[s] == 0:
            return default
        index = self.id8(s, x)
        return self.values[index] if self.keys[index] == x else default

    def get(self, x):
        return self.id5(x, 0)

    def id8(self, s, x):
        iter = self.slot[s]
        while self.keys[iter] != x:
            if self.next[iter] != 0:
                iter = self.next[iter]
            else:
                return iter
        return iter

    def iterator(self):
        index = 1
        readIndex = -1

        def hasNext():
            nonlocal index
            while index <= self.alloc and self.removed[index]:
                index += 1
            return index <= self.alloc

        def id10():
            return self.keys[readIndex]

        def id11():
            return self.values[readIndex]

        def next():
            nonlocal readIndex
            if not hasNext():
                raise Exception("No more elements")
            readIndex = index
            index += 1

        return {"hasNext": hasNext, "next": next, "id10": id10, "id11": id11}


class id12:
    def mul(self, a, b):
        pass


class id4(id12):
    def __init__(self, m):
        self.m = m

    def mul(self, a, b):
        return (a * b) % self.m


class id6(id12):
    def __init__(self, m):
        self.m = m

    def mul(self, a, b):
        return (a * b) % self.m


class LongList:
    def __init__(self, cap=0):
        self.size = 0
        self.cap = cap
        self.data = [0] * cap if cap > 0 else []

    def ensureSpace(self, req):
        if req > self.cap:
            self.cap = max(self.cap + 10, 2 * self.cap)
            self.data.extend([0] * (self.cap - len(self.data)))

    def checkRange(self, i):
        if i < 0 or i >= self.size:
            raise Exception("Index out of range")

    def get(self, i):
        self.checkRange(i)
        return self.data[i]

    def add(self, x):
        self.ensureSpace(self.size + 1)
        self.data[self.size] = x
        self.size += 1

    def addAll(self, x: List[int], offset: int, length: int):
        self.ensureSpace(self.size + length)
        self.data[self.size:self.size + length] = x[offset:offset + length]
        self.size += length

    def sort(self):
        if self.size <= 1:
            return
        random.shuffle(self.data)

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

    def toArray(self):
        return self.data[:self.size]

    def clear(self):
        self.size = 0

    def __str__(self):
        return str(self.toArray())

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
        return LongList(self.data[:self.size])


class Randomized:
    @staticmethod
    def shuffle(data, from_, to):
        to -= 1
        for i in range(from_, to + 1):
            s = Randomized.nextInt(i, to)
            data[i], data[s] = data[s], data[i]

    @staticmethod
    def nextInt(l, r):
        return random.randint(l, r)


class Factorization:
    @staticmethod
    def id13(x):
        ans = []
        i = 2
        while i * i <= x:
            if x % i == 0:
                ans.append(i)
                while x % i == 0:
                    x //= i
            i += 1
        if x > 1:
            ans.append(x)
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


class Main:
    def __init__(self):
        pass

    def solve(self, m, x):
        primes = Factorization.id13(m)
        id9 = LongList(20000)
        tmpList = LongList(20000)
        id2 = LongList()
        for p in primes:
            id2.add(p)
            id2.addAll(Factorization.id13(p - 1))
        id2.unique()

        self.collect(id9, m, 0)
        power = LongPower(id12.getInstance(m))

        total = 1
        for i in range(id9.size()):
            g = id9.get(i)
            if g == m:
                continue
            mg = m // g
            tmpList.clear()
            self.collect(tmpList, mg, 0)
            cnt = 0
            for j in range(tmpList.size() - 1, -1, -1):
                t = tmpList.get(j)
                cnt += self.mu(t) * ((m - 1) // (t * g))

            tmpList.clear()
            euler = self.euler(mg)
            primeFactors = tmpList
            for j in range(id2.size()):
                p = id2.get(j)
                if euler % p == 0:
                    primeFactors.add(p)

            n = euler
            for j in range(primeFactors.size()):
                p = primeFactors.get(j)
                while n % p == 0 and power.pow(x, n // p) % mg == 1:
                    n //= p

            if cnt % n != 0:
                raise Exception("Invalid state")
            total += cnt // n

        return total

    def collect(self, lst, x, i):
        if i == len(primes):
            lst.add(x)
            return
        self.collect(lst, x, i + 1)
        while x % primes[i] == 0:
            x //= primes[i]
            self.collect(lst, x, i + 1)

    def mu(self, x):
        ans = mu.id5(x, -1)
        if ans == -1:
            self.populate(x)
            ans = mu.get(x)
        return ans

    def euler(self, x):
        ans = euler.id5(x, -1)
        if ans == -1:
            self.populate(x)
            ans = euler.get(x)
        return ans

    def populate(self, x):
        factor = self.id0(x)
        cnt = 0
        y = x
        while y % factor == 0:
            cnt += 1
            y //= factor
        if cnt > 1:
            mu.put(x, 0)
        else:
            mu.put(x, -self.mu(y))
        euler.put(x, self.euler(y) * (x // y - x // y // factor))

    def id0(self, x):
        for p in primes:
            if x % p == 0:
                return p
        return x


if __name__ == "__main__":
    m = int(input())
    x = int(input())
    primes = Factorization.id13(m)
    mu = id1(100000, False)
    euler = id1(100000, False)
    primes = Factorization.id13(m)
    primes = Factorization.id13(m)
    mu.put(1, 1)
    euler.put(1, 1)
    solver = Main()
    ans = solver.solve(m, x)
    print(ans)
