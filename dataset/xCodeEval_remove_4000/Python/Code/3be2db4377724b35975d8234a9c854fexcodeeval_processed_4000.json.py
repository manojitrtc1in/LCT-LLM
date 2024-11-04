

from __future__ import division, print_function

import io, os, sys, math
from io import BytesIO, IOBase







if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

class Solution:      
    def primeRange(self,m,n):
        if n == 0 or n == 1:
            return []
        primes = [1] * (n + 1) 
        primes[0] = primes[1] = 0 
        for i in range(4, n + 1, 2):    
            primes[i] = 0
        
        for i in range(3, n + 1, 2):
            if primes[i] == 1:
                for j in range(2 * i, n + 1, i):
                    primes[j] = 0
        return [x for x in range(m, n + 1) if primes[x]]

def solve():
    n, m = map(int, input().split())
    ans = 0
    c = list()
    for i in range(n):
        temp = input()
        c.append(temp)
        if i == 0 or i == n - 1:
            ans = max(ans, temp.count("
    for i in range(n):
        cnt, up, down = 0, 0, 0
        if i != 0 and i != n - 1:
            for j in range(m):
                if c[i][j] == "
                    if c[i - 1][j] == ".":
                        up += 1
                    else:
                        ans = max(ans, up)
                        up = 0
                    if c[i + 1][j] == ".":
                        down += 1
                    else:
                        ans = max(ans, down)
                        down = 0
            ans = max(up, max(down, ans))
    for j in range(m):
        cnt, up, down = 0, 0, 0
        for i in range(n):
            if j != 0 and j != m - 1:
                if c[i][j] == "
                    if c[i][j - 1] == ".":
                        up += 1
                    else:
                        ans = max(ans, up)
                        up = 0
                    if c[i][j + 1] == ".":
                        down += 1
                    else:
                        ans = max(ans, down)
                        down = 0
            else:
                right, left = 0, 0
                cnt2, cnt3 = 0, 0
                if j == 0:
                    for i in range(n):
                        if c[i][j] == "
                            cnt2 += 1
                            if c[i][1] == ".":
                                right += 1
                            else:
                                ans = max(ans, right)
                                right = 0
                        else:
                            ans = max(ans, cnt2)
                            cnt2 = 0
                if j == m - 1:
                    for i in range(n):
                        if c[i][j] == "
                            cnt3 += 1
                            if c[i][m - 2] == ".":
                                left += 1
                            else:
                                ans = max(ans, left)
                                left = 0
                        else:
                            ans = max(ans, cnt3)
                            cnt3 = 0
            ans = max(up, max(down, ans))
    print(ans)
    

def main():
    
    
    testcases = int(input())
    for _ in range(testcases):   
        
        
        
        
        x, y, z = map(int, input().split())
        if (abs(y-z)+z)>x:
            print(1)
        elif (abs(y-z)+z)<x:
            print(2)
        else:
            print(3)
        
        



id0 = 8192

class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id0))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id0))
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

if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")



if __name__ == "__main__":
    main()












