from collections import deque
import sys

class Scnr:
    def __init__(self, input_stream=sys.stdin):
        self.ins = input_stream
        self.buffer = bytearray(1024)
        self.ptr = 0
        self.buflen = 0

    def has_next_byte(self):
        if self.ptr < self.buflen:
            return True
        else:
            self.ptr = 0
            self.buflen = self.ins.readinto(self.buffer)
            return self.buflen > 0

    def read_byte(self):
        if self.has_next_byte():
            return self.buffer[self.ptr]
        else:
            return -1

    def is_printable_char(self, c):
        return 33 <= c <= 126

    def has_next(self):
        while self.has_next_byte() and not self.is_printable_char(self.buffer[self.ptr]):
            self.ptr += 1
        return self.has_next_byte()

    def next(self):
        return self.next_builder().decode()

    def next_builder(self):
        if not self.has_next():
            raise StopIteration()
        sb = bytearray()
        b = self.read_byte()
        while self.is_printable_char(b):
            sb.append(b)
            b = self.read_byte()
        return sb

    def next_int(self):
        if not self.has_next():
            raise StopIteration()
        n = 0
        minus = False
        b = self.read_byte()
        if b == ord('-'):
            minus = True
            b = self.read_byte()
        if b < ord('0') or b > ord('9'):
            raise ValueError()
        while True:
            if ord('0') <= b <= ord('9'):
                n = n * 10 + (b - ord('0'))
            elif b == -1 or not self.is_printable_char(b):
                return -n if minus else n
            else:
                raise ValueError()
            b = self.read_byte()

def repow(b, p, modder=None):
    a = b % modder if modder else b
    res = 1
    while p > 0:
        if p % 2 == 1:
            res = (res * a) % modder if modder else res * a
        a = (a * a) % modder if modder else a * a
        p //= 2
    return res

def gcd(c, d):
    while True:
        f = c % d
        if f == 0:
            return d
        c = d
        d = f

def lcm(c, d):
    return c // gcd(c, d) * d

def div_list(n):
    div = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            div.append(i)
            if i * i != n:
                div.append(n // i)
    return div

def solve():
    n = sc.next_int()
    dq = deque()
    for _ in range(n):
        dq.append(sc.next_int())
    a = dq.popleft()
    b = 0
    pre = a
    cnt = 1

    while dq:
        now = 0
        while now <= pre and dq:
            now += dq.pop()
        if now != 0:
            b += now
            pre = now
            cnt += 1

        if not dq:
            break

        now = 0
        while now <= pre and dq:
            now += dq.popleft()
        if now != 0:
            a += now
            pre = now
            cnt += 1

    print(cnt, a, b)

sc = Scnr()
t = sc.next_int()
for _ in range(t):
    solve()
