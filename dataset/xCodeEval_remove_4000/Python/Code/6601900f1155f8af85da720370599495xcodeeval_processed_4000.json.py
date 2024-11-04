from itertools import accumulate as ac
from collections import Counter as cc
from bisect import bisect_left as bsl
from bisect import bisect as bs
from math import factorial
from collections import OrderedDict as odict
from collections import defaultdict as dfd
import itertools
from statistics import mean
from math import ceil, sqrt, log, gcd
import math
import os
import sys
from io import BytesIO, IOBase
import random
import copy
import time
from itertools import islice
from functools import lru_cache




id3 = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id3))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id3))
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
def input(): return sys.stdin.readline().rstrip()










def lcm(id6, id1): return (id6*id1//gcd(id6, id1))
def intinput(): return int(input())
def id2(): return input().split()
def id0(): return map(int, input().split())
def id5(): return list(id0())
def id4(): return set(id0())
















































































































































































































































































































n = int(input())
for _ in range(n):
    n, k = list(map(int, input().split()))
    mountains = list(map(int, input().split()))
    for i in range(k):
        ans = -1
        for j in range(n - 1):
            if mountains[j] < mountains[j + 1]:
                ans = j
                mountains[j] += 1
                break
        if ans == -1:
            break
    print(ans if ans == -1 else ans+1)
