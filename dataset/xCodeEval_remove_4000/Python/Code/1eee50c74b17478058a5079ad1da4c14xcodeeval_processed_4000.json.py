


from linecache import getline
from operator import index
import os
import sys
from io import BytesIO, IOBase
from webbrowser import get
from math import gcd


id0: int = 8192

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

def print(*args, **kwargs):
    
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

def id2(array):
    cur = None
    for x in array:
        if (cur == None):
            cur = x
            continue
        cur = gcd(cur, x)
    return cur
def id1(debug = False):
    
    
    for _ in range(int(input())):
        lth = int(input())
        ll = [int(x) for x in input().split()]
        cur = id2(ll)
        if (cur == 1):
            print(0)
            continue
        zz = ll.copy()
        
        
        
        
        ll[-1] = gcd(ll[-1], lth)
        if (id2(ll) == 1):
            print(1)
            continue
        ll = zz
        ll[-2] = gcd(ll[-2], lth-1)
        if (id2(ll) == 1):
            print(2)
            continue
        ll = zz 
        
        ll[-1] = gcd(ll[-1], lth)
        
        ll[-2] = gcd(ll[-2], lth-1)
        if (id2(ll) == 1):
            print(3)
            continue

        


    return 0

if (__name__ == "id1"):
    exit(id1())