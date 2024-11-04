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

def div_list(n):
    div = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            div.append(i)
            if i * i != n:
                div.append(n // i)
    return div

def id9(x):
    mp = {}
    t = x
    for i in range(2, int(x**0.5) + 1):
        if t % i == 0:
            num = 0
            while t % i == 0:
                t //= i
                num += 1
            mp[i] = num
    if t != 1:
        mp[t] = 1
    return mp

def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n == 1:
        return False
    if n > 2**31 - 1:
        return id5(n)
    d = n - 1
    s = 0
    while d % 2 == 0:
        d //= 2
        s += 1
    aa = [2, 3, 5, 7, 11, 13, 17]
    for a in aa:
        if a < n:
            t = d
            y = repow(a, t)
            while t != n - 1 and y != 1 and y != n - 1:
                y = (y * y) % n
                t *= 2
            if y != n - 1 and t % 2 == 0:
                return False
    return True

def id5(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

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
    
    out.write(f"{cnt} {a} {b}\n")

class Scnr:
    def __init__(self):
        self.buffer = bytearray(1024)
        self.ptr = 0
        self.buflen = 0
        self.ins = sys.stdin.buffer

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
out = sys.stdout

def main():
    for _ in range(int(sc.next())):
        solve()

if __name__ == "__main__":
    main()
