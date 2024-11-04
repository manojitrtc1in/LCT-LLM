import sys
from collections import deque
from math import gcd

def repow(b, p):
    a = b
    res = 1
    while p > 0:
        if p % 2 == 1:
            res *= a
        a *= a
        p //= 2
    return int(res)

def repow_mod(b, p, modder):
    a = b % modder
    res = 1
    while p > 0:
        if p % 2 == 1:
            res = (res * a) % modder
        a = (a * a) % modder
        p //= 2
    return int(res)

def gcd_func(c, d):
    while True:
        f = c % d
        if f == 0:
            return d
        c = d
        d = f

def lcm(c, d):
    return c // gcd_func(c, d) * d

def div_list(n):
    div = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            div.append(i)
            if i * i != n:
                div.append(n // i)
    return div

def kmp(t, p):
    f = [0] * (len(p) + 1)
    i = 0
    j = 1
    f[1] = 0
    while j < len(p):
        if i == 0 or p[i - 1] == p[j - 1]:
            i += 1
            j += 1
            f[j] = i
        else:
            i = f[i]
    i = 1
    j = 1
    while i <= len(p) and j <= len(t):
        if i == 0 or p[i - 1] == t[j - 1]:
            i += 1
            j += 1
        else:
            i = f[i]
    return j - i if i == (len(p) + 1) else -1

def solve():
    n = int(sc.next())
    dq = deque()
    for _ in range(n):
        dq.append(int(sc.next()))
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

class Scnr:
    def __init__(self):
        self.ins = sys.stdin
        self.buffer = bytearray(1024)
        self.ptr = 0
        self.buflen = 0

    def id12(self):
        if self.ptr < self.buflen:
            return True
        else:
            self.ptr = 0
            self.buflen = self.ins.readinto(self.buffer)
            return self.buflen > 0

    def read_byte(self):
        if self.id12():
            return self.buffer[self.ptr]
        else:
            return -1

    def has_next(self):
        while self.id12() and not (33 <= self.buffer[self.ptr] <= 126):
            self.ptr += 1
        return self.id12()

    def next(self):
        return self.next_builder().decode()

    def next_builder(self):
        if not self.has_next():
            raise StopIteration
        sb = bytearray()
        b = self.read_byte()
        while 33 <= b <= 126:
            sb.append(b)
            b = self.read_byte()
        return sb

    def next_int(self):
        return int(self.next())

sc = Scnr()
for _ in range(sc.next_int()):
    solve()
