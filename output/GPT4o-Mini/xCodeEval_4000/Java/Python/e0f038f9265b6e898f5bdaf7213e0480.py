import sys
from collections import deque
from math import gcd

def repow(b, p):
    res = 1
    a = b
    while p > 0:
        if p % 2 == 1:
            res *= a
        a *= a
        p //= 2
    return res

def repow_mod(b, p, modder):
    res = 1
    a = b % modder
    while p > 0:
        if p % 2 == 1:
            res = (res * a) % modder
        a = (a * a) % modder
        p //= 2
    return res

def div_list(n):
    div = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            div.append(i)
            if i * i != n:
                div.append(n // i)
    return div

def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n == 1:
        return False
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

    def next(self):
        while self.has_next_byte() and not (33 <= self.buffer[self.ptr] <= 126):
            self.ptr += 1
        if not self.has_next_byte():
            raise StopIteration
        sb = bytearray()
        b = self.read_byte()
        while 33 <= b <= 126:
            sb.append(b)
            b = self.read_byte()
        return sb.decode()

sc = Scnr()
out = sys.stdout

def main():
    t = int(sc.next())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
