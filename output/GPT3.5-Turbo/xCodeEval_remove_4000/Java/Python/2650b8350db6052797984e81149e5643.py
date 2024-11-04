import sys
from typing import List

class FastWriter:
    def __init__(self):
        self.out = []
    
    def p(self, obj):
        self.out.append(str(obj))
        return self
    
    def pp(self, *args):
        self.out.append(' '.join(map(str, args)))
        self.out.append('\n')
        return self
    
    def println(self, arr):
        self.out.append(' '.join(map(str, arr)))
        self.out.append('\n')
    
    def to_file(self, file_name):
        with open(file_name, 'w') as f:
            f.write(''.join(self.out))
    
    def close(self):
        sys.stdout.write(''.join(self.out))

class FastScanner:
    def __init__(self):
        self.sin = sys.stdin
        self.buffer = bytearray()
        self.ptr = 0
        self.buflen = 0
    
    def id21(self):
        if self.ptr < self.buflen:
            return True
        else:
            self.ptr = 0
            self.buffer = self.sin.read(1024)
            self.buflen = len(self.buffer)
            if self.buflen <= 0:
                return False
        return True
    
    def read_byte(self):
        if self.id21():
            val = self.buffer[self.ptr]
            self.ptr += 1
            return val
        else:
            return -1
    
    def id23(self, c):
        return 33 <= c <= 126
    
    def has_next(self):
        while self.id21() and not self.id23(self.buffer[self.ptr]):
            self.ptr += 1
        return self.id21()
    
    def next(self):
        if not self.has_next():
            raise StopIteration()
        sb = []
        b = self.read_byte()
        while self.id23(b):
            sb.append(chr(b))
            b = self.read_byte()
        return ''.join(sb)
    
    def long_next(self):
        if not self.has_next():
            raise StopIteration()
        n = 0
        minus = False
        b = self.read_byte()
        if b == ord('-'):
            minus = True
            b = self.read_byte()
        if not ord('0') <= b <= ord('9'):
            raise ValueError()
        while True:
            if ord('0') <= b <= ord('9'):
                n *= 10
                n += b - ord('0')
            elif b == -1 or not self.id23(b) or b == ord(':'):
                return -n if minus else n
            else:
                raise ValueError()
            b = self.read_byte()
    
    def int_next(self):
        nl = self.long_next()
        if nl < -2147483648 or nl > 2147483647:
            raise ValueError()
        return int(nl)
    
    def double_next(self):
        return float(self.next())

def main():
    out = FastWriter()
    in_ = FastScanner()
    lng = in_.next()
    sht = in_.next()
    n = len(lng)
    m = len(sht)
    leftmost = [0] * (m + 1)
    rightmost = [0] * (m + 1)
    rightmost[m] = n
    idx = 0
    for i in range(m):
        while sht[i] != lng[idx]:
            idx += 1
        leftmost[i] = idx
        idx += 1
    idx = n - 1
    for i in range(m - 1, -1, -1):
        while sht[i] != lng[idx]:
            idx -= 1
        rightmost[i] = idx
        idx -= 1
    ans = rightmost[0]
    for i in range(m):
        ans = max(ans, rightmost[i + 1] - leftmost[i] - 1)
    out.println(ans)
    out.close()

if __name__ == '__main__':
    main()
