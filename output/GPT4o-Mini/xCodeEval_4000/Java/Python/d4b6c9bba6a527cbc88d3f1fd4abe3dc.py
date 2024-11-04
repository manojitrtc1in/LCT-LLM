import sys
import random
from collections import defaultdict

IMPOSSIBLE = "IMPOSSIBLE"
POSSIBLE = "POSSIBLE"
YES = "YES"
NO = "NO"
MOD = 998244353

class MyScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = []
    
    def next(self):
        if not self.buffer:
            self.buffer = self.input_stream.readline().strip().split()
        return self.buffer.pop(0)
    
    def next_int(self):
        return int(self.next())
    
    def next_long(self):
        return int(self.next())
    
    def next_double(self):
        return float(self.next())
    
    def close(self):
        self.input_stream.close()

class MyPrintWriter:
    def __init__(self, output_stream):
        self.output_stream = output_stream
    
    def println(self, ans):
        self.output_stream.write(f"{ans}\n")
    
    def print_ans(self, arr):
        if arr:
            self.output_stream.write(" ".join(map(str, arr)) + "\n")

def square(a):
    fft4(a, False)
    for i in range(len(a)):
        a[i] = a[i] * a[i] % MOD
    fft4(a, True)

def fft(a, is_inverted_fft):
    n = len(a)
    j = 0
    for i in range(1, n):
        bit = n >> 1
        while j & bit:
            j ^= bit
            bit >>= 1
        j ^= bit
        if i < j:
            a[i], a[j] = a[j], a[i]
    
    len_ = 2
    while len_ <= n:
        wlen = ROOT_INV if is_inverted_fft else ROOT
        for i in range(len_, ORDER, len_):
            wlen = wlen * wlen % MOD
        
        for i in range(0, n, len_):
            w = 1
            for j in range(len_ // 2):
                u = a[i + j]
                v = a[i + j + len_ // 2] * w % MOD
                a[i + j] = (u + v) % MOD
                a[i + j + len_ // 2] = (u - v) % MOD
                w = w * wlen % MOD
        len_ <<= 1
    
    if is_inverted_fft:
        inv = inverse(n, MOD)
        for i in range(len(a)):
            a[i] = a[i] * inv % MOD

def fft4(a, is_inverted_fft):
    n = len(a)
    j = 0
    for i in range(1, n):
        bit = n >> 1
        while j & bit:
            j ^= bit
            bit >>= 1
        j ^= bit
        if i < j:
            a[i], a[j] = a[j], a[i]
    
    parity = 0
    len_ = 2
    while len_ <= n:
        parity += 1
        len_ <<= 1
    
    if parity % 2 == 1:
        len_ = 2
        if len_ <= n:
            wlen = ROOT_INV if is_inverted_fft else ROOT
            for i in range(len_, ORDER, len_):
                wlen = wlen * wlen % MOD
            
            for i in range(0, n, len_):
                w = 1
                for j in range(len_ // 2):
                    u = a[i + j]
                    v = a[i + j + len_ // 2] * w % MOD
                    a[i + j] = (u + v) % MOD
                    a[i + j + len_ // 2] = (u - v) % MOD
                    w = w * wlen % MOD
                len_ *= 4
    
    for len_ in range(4, n + 1, len_ << 2):
        wlen = ROOT_INV if is_inverted_fft else ROOT
        w4 = W4_INV if is_inverted_fft else W4
        for i in range(len_, ORDER, len_):
            wlen = wlen * wlen % MOD
        
        for i in range(0, n, len_):
            w = 1
            for j in range(len_ // 4):
                x0 = a[i + j]
                x1 = a[i + j + len_ // 2] * w % MOD
                x2 = a[i + j + len_ // 4] * w % MOD
                x2 = x2 * w % MOD
                x3 = a[i + j + len_ * 3 // 4] * w % MOD
                x3 = x3 * w % MOD
                x3 = x3 * w % MOD
                
                y0 = (x0 + x1 + x2 + x3) % MOD
                a[i + j] = y0
                y1 = (x0 + x1 * w4 - x2 - x3 * w4) % MOD
                a[i + j + len_ * 3 // 4] = y1 if y1 >= 0 else y1 + MOD
                y2 = (x0 - x1 + x2 - x3) % MOD
                a[i + j + len_ // 2] = y2 if y2 >= 0 else y2 + MOD
                y3 = (x0 - x1 * w4 - x2 + x3 * w4) % MOD
                a[i + j + len_ // 4] = y3 if y3 >= 0 else y3 + MOD
                
                w = w * wlen % MOD
    
    if is_inverted_fft:
        inv = inverse(n, MOD)
        for i in range(len(a)):
            a[i] = a[i] * inv % MOD

def multiply_polynomial(a, b):
    n = 1
    while n < len(a) + len(b):
        n <<= 1
    fa = a + [0] * (n - len(a))
    fb = b + [0] * (n - len(b))
    
    fft(fa, False)
    fft(fb, False)
    for i in range(n):
        fa[i] = fa[i] * fb[i] % MOD
    fft(fa, True)
    
    return fa

def inverse(a, p):
    return pow(a, p - 2, p)

def pow(a, k, p):
    m = k
    ans = 1
    curr = a
    while m > 0:
        if m & 1:
            ans = ans * curr % p
        m >>= 1
        curr = curr * curr % p
    return ans

def get_input():
    global n, k, f
    n = scanner.next_int()
    k = scanner.next_int()
    f = scanner.next_int()

def print_output():
    print_writer.println(ans)

def solve():
    global ans
    ans = 0
    len_ = 1
    while len_ < f + 2 + f + 2:
        len_ <<= 1
    ways = [0] * len_
    suffix = [0] * (f + 2)
    
    for i in range(min(k, f) + 1):
        ways[i] = 1
    ways[f + 1] = max(0, k - f)
    
    for i in range(n):
        if i < n - 1:
            square(ways)
            val = sum(ways[j] for j in range(f + 1, len(ways))) % MOD
            suffix[f + 1] = val
            
            for j in range(f, -1, -1):
                val = (suffix[j + 1] + ways[j]) % MOD
                suffix[j] = val
            
            for j in range(min(k, f) + 1):
                val = (suffix[j] + ways[j] * (k - j)) % MOD
                ways[j] = val
            
            ways[f + 1] = (suffix[f + 1] * max(0, k - f)) % MOD
            for j in range(k + 1, f + 2):
                ways[j] = 0
            ways[f + 2:] = [0] * (len(ways) - (f + 2))
        else:
            for j in range(f + 1):
                ans = (ans + ways[j] * ways[f - j]) % MOD
    
    return ans

def main():
    global scanner, print_writer, ans
    is_file_io = True
    if is_file_io:
        scanner = MyScanner(open("input.txt"))
        print_writer = MyPrintWriter(open("output.txt", "w"))
    else:
        scanner = MyScanner(sys.stdin)
        print_writer = MyPrintWriter(sys.stdout)
    
    t = 1
    for _ in range(t):
        get_input()
        ans = solve()
        print_output()
    
    scanner.close()
    print_writer.output_stream.close()

ROOT = int(pow(3, 7 * 17, MOD))
ROOT_INV = int(pow(ROOT, MOD - 2, MOD))
ORDER = 1 << 23
W4 = pow(ROOT, (MOD - 1) // 4, MOD)
W4_INV = pow(ROOT, (MOD - 1) // 4 * 3, MOD)

if __name__ == "__main__":
    main()
