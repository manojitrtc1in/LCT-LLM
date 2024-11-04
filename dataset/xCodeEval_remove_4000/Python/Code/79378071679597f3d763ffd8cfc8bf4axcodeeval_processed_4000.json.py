

import time












    



import os
import sys
from io import BytesIO, IOBase


import random


from math import ceil, gcd, log2, sqrt
from bisect import bisect_right, bisect_left, insort, insort_left, insort_right

from heapq import heapify, heappop, heappush, heappushpop, nlargest, heapreplace, nsmallest
from collections import OrderedDict, defaultdict, deque, Counter




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


def wrap(x):
    return x ^ rand


















































































































































































































































































class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
ss = lambda: sys.stdin.readline().rstrip("\r\n")
ip = lambda: int(sys.stdin.readline().rstrip("\r\n"))
ips = lambda: map(int, sys.stdin.readline().rstrip("\r\n").split())
ll = lambda: list(map(int, sys.stdin.readline().rstrip("\r\n").split()))
sss = lambda: map(str, sys.stdin.readline().rstrip("\r\n").split())
ls = lambda: list(map(str, sys.stdin.readline().rstrip("\r\n").split()))

yn = ['No', 'Yes']
YN = ['NO', 'YES']
YY = "YES"
NN = "NO"
yy = "Yes"
nn = "No"
rand = random.randrange(1 << 63)
letter_val = {chr(97 + i): i for i in range(26)}
val_letter = {i: chr(97 + i) for i in range(26)}
bigm = int(1e12)
mod1 = int(1e9 + 7)
mod2 = int(1e9 + 9)
mod3 = 998244353
big = sys.maxsize


def prog_name() -> None:
    n = ip()
    l = ll()
    one = 0
    zero = 0
    n_one = 0
    for num in l:
        if num:
            if num == 1:
                one += 1
            else:
                n_one += 1
        else:
            zero += 1
    _sum = sum(l)
    if not _sum:
        print(n)
        for i in range(n):
            print(i + 1, i + 1)
    else:
        S = 0
        for i in range(n):
            if i & 1 ^ 1:
                S += l[i]
            else:
                S -= l[i]
        if not S:
            print(1)
            print(1, n)
        else:
            if _sum & 1:
                print(-1)
                return
            ind = 0
            final = []
            one = 0
            n_one = 0
            while ind < n:
                if one == n_one:
                    if l[ind] == 0:
                        final.append([ind + 1, ind + 1])
                        ind += 1
                    else:
                        if ind + 1 < n:
                            if l[ind] == l[ind + 1]:
                                final.append([ind + 1, ind + 2])
                                ind += 2
                            elif abs(l[ind]) == abs(l[ind + 1]):
                                final.append([ind + 1, ind + 1])
                                final.append([ind + 2, ind + 2])
                                ind += 2
                            else:
                                final.append([ind + 1, ind + 1])
                                if l[ind] == 1:
                                    one += 1
                                else:
                                    n_one += 1
                                ind += 1

                        else:
                            final.append([ind + 1, ind + 1])
                            if l[ind] == 1:
                                one += 1
                            else:
                                n_one += 1
                            ind += 1

                else:
                    if one > n_one:
                        if ind + 1 < n:
                            if l[ind] == 0 and l[ind + 1] == 1:
                                n_one += 1
                                final.append([ind + 1, ind + 2])
                                ind += 2
                            elif l[ind] == l[ind + 1] and l[ind] == 0:
                                final.append([ind + 1, ind + 1])
                                ind += 1
                            elif l[ind] == 0 and l[ind + 1] == -1:
                                n_one += 1
                                final.append([ind + 1, ind + 1])
                                final.append([ind + 2, ind + 2])
                                ind += 2
                        else:
                            final.append([ind + 1, ind + 1])
                            ind += 1
                    else:
                        if ind + 1 < n:
                            if l[ind] == 0 and l[ind + 1] == -1:
                                one += 1
                                final.append([ind + 1, ind + 2])
                                ind += 2
                            elif l[ind] == l[ind + 1] and l[ind] == 0:
                                final.append([ind + 1, ind + 1])
                                ind += 1
                            elif l[ind] == 0 and l[ind + 1] == 1:
                                one += 1
                                final.append([ind + 1, ind + 1])
                                final.append([ind + 2, ind + 2])
                                ind += 2
                        else:
                            final.append([ind + 1, ind + 1])
                            ind += 1
            print(len(final))
            for a, b in final:
                print(a, b)
    


def main():
    
    Testcase = ip()
    begin = time.time()
    for unique in range(Testcase):
        
        
        
        prog_name()
    end = time.time()
    


if __name__ == "__main__":
    main()