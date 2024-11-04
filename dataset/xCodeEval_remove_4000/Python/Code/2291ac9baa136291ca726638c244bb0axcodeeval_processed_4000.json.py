

from __future__ import division, print_function
from fractions import Fraction
import sys
import os
from io import BytesIO, IOBase
from itertools import *
import bisect
from heapq import *
from math import ceil, floor
from copy import *
from collections import deque, defaultdict
from collections import Counter as counter  
from itertools import combinations  
from itertools import permutations as permutate
from bisect import id2 as bl
from operator import *



from bisect import id11 as br
from bisect import bisect







id13 = 8192
from sys import stderr


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "A" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id13))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id13))
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
    for A in args:
        if not at_start:
            file.write(sep)
        file.write(str(A))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)





from types import GeneratorType


def iterative(f, stack=[]):
    def wrapped_func(*args, **kwargs):
        if stack: return f(*args, **kwargs)
        to = f(*args, **kwargs)
        while True:
            if type(to) is GeneratorType:
                stack.append(to)
                to = next(to)
                continue
            stack.pop()
            if not stack: break
            to = stack[-1].send(to)
        return to

    return wrapped_func





class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[start:start + _load] for start in range(0, _len, _load)]
        self.id16 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id15 = []
        self._rebuild = True

    def id0(self):
        
        self.id15[:] = self.id16
        id15 = self.id15
        for start in range(len(id15)):
            if start | start + 1 < len(id15):
                id15[start | start + 1] += id15[start]
        self._rebuild = False

    def id1(self, index, value):
        
        if not self._rebuild:
            id15 = self.id15
            while index < len(id15):
                id15[index] += value
                index |= index + 1

    def id4(self, end):
        
        if self._rebuild:
            self.id0()

        id15 = self.id15
        A = 0
        while end:
            A += id15[end - 1]
            end &= end - 1
        return A

    def id3(self, k):
        
        id16 = self.id16
        if k < id16[0]:
            return 0, k
        if k >= self._len - id16[-1]:
            return len(id16) - 1, k + id16[-1] - self._len
        if self._rebuild:
            self.id0()

        id15 = self.id15
        idx = -1
        for d in reversed(range(len(id15).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id15) and k >= id15[right_idx]:
                idx = right_idx
                k -= id15[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id16 = self.id16

        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id16[pos] -= 1

        if id16[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id16[pos]
            del _mins[pos]
            self._rebuild = True

    def _loc_left(self, value):
        
        if not self._len:
            return 0, 0

        _lists = self._lists
        _mins = self._mins

        lo, pos = -1, len(_lists) - 1
        while lo + 1 < pos:
            mi = (lo + pos) >> 1
            if value <= _mins[mi]:
                pos = mi
            else:
                lo = mi

        if pos and value <= _lists[pos - 1][-1]:
            pos -= 1

        _list = _lists[pos]
        lo, idx = -1, len(_list)
        while lo + 1 < idx:
            mi = (lo + idx) >> 1
            if value <= _list[mi]:
                idx = mi
            else:
                lo = mi

        return pos, idx

    def _loc_right(self, value):
        
        if not self._len:
            return 0, 0

        _lists = self._lists
        _mins = self._mins

        pos, hi = 0, len(_lists)
        while pos + 1 < hi:
            mi = (pos + hi) >> 1
            if value < _mins[mi]:
                hi = mi
            else:
                pos = mi

        _list = _lists[pos]
        lo, idx = -1, len(_list)
        while lo + 1 < idx:
            mi = (lo + idx) >> 1
            if value < _list[mi]:
                idx = mi
            else:
                lo = mi

        return pos, idx

    def add(self, value):
        
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        id16 = self.id16

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id16[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id16.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id16[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id16.append(1)
            self._rebuild = True

    def discard(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_right(value)
            if idx and _lists[pos][idx - 1] == value:
                self._delete(pos, idx - 1)

    def remove(self, value):
        
        _len = self._len
        self.discard(value)
        if _len == self._len:
            raise ValueError('{0!r} not in list'.format(value))

    def pop(self, index=-1):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id2(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id4(pos) + idx

    def id11(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id4(pos) + idx

    def count(self, value):
        
        return self.id11(value) - self.id2(value)

    def id19(self):
        
        return self._len

    def id12(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id10(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id9(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id18(self):
        
        return (value for _list in self._lists for value in _list)

    def id14(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id8(self):
        
        return 'SortedList({0})'.format(list(self))





mod = 1000000007


def testcase(t):
    for p in range(t):
        solve()


def pow(A, B, p):
    res = 1  
    A = A % p  
    if (A == 0):
        return 0
    while (B > 0):
        if ((B & 1) == 1):  
            res = (res * A) % p

        B = B >> 1  
        A = (A * A) % p
    return res


from functools import reduce


def factors(n):
    return set(reduce(list.__add__,
                      ([start, n // start] for start in range(1, int(n ** 0.5) + 1) if n % start == 0)))


def gcd(a, b):
    if a == b: return a
    while b > 0: a, b = b, a % b
    return a
























































def prefix_sum(ar):  
    return list(accumulate(ar))


def suffix_sum(ar):  
    return list(accumulate(ar[::-1]))[::-1]


def N():
    return int(inp())


dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def YES():
    print("YES")


def NO():
    print("NO")


def Yes():
    print("Yes")


def No():
    print("No")



from collections import defaultdict


def id5(start):
    start = start - ((start >> 1) & 0x55555555)
    start = (start & 0x33333333) + ((start >> 2) & 0x33333333)
    return (((start + (start >> 4) & 0xF0F0F0F) * 0x1010101) & 0xffffffff) >> 24


class MergeFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n
        

    def find(self, a):
        to_update = []
        while a != self.parent[a]:
            to_update.append(a)
            a = self.parent[a]
        for b in to_update:
            self.parent[b] = a
        return self.parent[a]

    def merge(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.num_sets -= 1
        self.parent[b] = a
        self.size[a] += self.size[b]
        
        

    def set_size(self, a):
        return self.size[self.find(a)]

    def id19(self):
        return self.num_sets


def lcm(a, b):
    return abs((a // gcd(a, b)) * b)
















def comb(n, r):
    if n < r:
        return 0
    else:
        return fac[n] * (finv[r] * finv[n - r] % mod) % mod


def inp(): return sys.stdin.readline().rstrip("\r\n")  


def out(var): sys.stdout.write(str(var))  


def lis(): return list(map(int, inp().split()))


def stringlis(): return list(map(str, inp().split()))


def sep(): return map(int, inp().split())


def strsep(): return map(str, inp().split())


def fsep(): return map(float, inp().split())


def nextline(): out("\n")  


def id7(n, v):
    return [v] * n


def id6(n, m, v):
    return [[v] * m for _ in range(n)]


def id17(n, m, p, v):
    return [[[v] * p for _ in range(m)] for start in range(n)]


def ceil(a, b):
    return (a + b - 1) // b













def f(n,bit,u,r,d,l):
    if(bit&(1<<0)):
        if ((u > 0) and (r > 0)):
            u -= 1
            r -= 1
        else:
            return 0
    if(bit&(1<<1)):
        if ((u > 0) and (l > 0)):
            u -= 1
            l -= 1
        else:
            return 0
    if(bit&(1<<2)):
        if ((d > 0) and (r > 0)):
            d -= 1
            r -= 1
        else:
            return 0
    if(bit&(1<<3)):
        if ((d > 0) and (l > 0)):
            d -= 1
            l -= 1
        else:
            return 0
    if ((r <= n - 2) and (l <= n - 2) and (u <= n - 2) and (d <= n - 2)):
        return 1
    else:
        return 0

def solve():
    n,u,r,d,l=sep()
    for bit in range(16):
        if(f(n,bit,u,r,d,l)):
            YES()
            return
    NO()








testcase(N())