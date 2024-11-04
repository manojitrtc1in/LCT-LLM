

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



from bisect import id13 as br
from bisect import bisect







id15 = 8192
from sys import stderr


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id15))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id15))
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
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id18 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id17 = []
        self._rebuild = True

    def id0(self):
        
        self.id17[:] = self.id18
        id17 = self.id17
        for i in range(len(id17)):
            if i | i + 1 < len(id17):
                id17[i | i + 1] += id17[i]
        self._rebuild = False

    def id1(self, index, value):
        
        if not self._rebuild:
            id17 = self.id17
            while index < len(id17):
                id17[index] += value
                index |= index + 1

    def id4(self, end):
        
        if self._rebuild:
            self.id0()

        id17 = self.id17
        x = 0
        while end:
            x += id17[end - 1]
            end &= end - 1
        return x

    def id3(self, k):
        
        id18 = self.id18
        if k < id18[0]:
            return 0, k
        if k >= self._len - id18[-1]:
            return len(id18) - 1, k + id18[-1] - self._len
        if self._rebuild:
            self.id0()

        id17 = self.id17
        idx = -1
        for d in reversed(range(len(id17).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id17) and k >= id17[right_idx]:
                idx = right_idx
                k -= id17[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id18 = self.id18

        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id18[pos] -= 1

        if id18[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id18[pos]
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
        id18 = self.id18

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id18[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id18.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id18[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id18.append(1)
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

    def id13(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id4(pos) + idx

    def count(self, value):
        
        return self.id13(value) - self.id2(value)

    def id11(self):
        
        return self._len

    def id14(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id12(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id10(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id20(self):
        
        return (value for _list in self._lists for value in _list)

    def id16(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id9(self):
        
        return 'SortedList({0})'.format(list(self))





mod = 1000000007


def testcase(t):
    for p in range(t):
        solve()


def pow(x, y, p):
    res = 1  
    x = x % p  
    if (x == 0):
        return 0
    while (y > 0):
        if ((y & 1) == 1):  
            res = (res * x) % p

        y = y >> 1  
        x = (x * x) % p
    return res


from functools import reduce


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0)))


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


def id5(i):
    i = i - ((i >> 1) & 0x55555555)
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333)
    return (((i + (i >> 4) & 0xF0F0F0F) * 0x1010101) & 0xffffffff) >> 24


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

    def id11(self):
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


def id8(n, v):
    return [v] * n


def id6(n, m, v):
    return [[v] * m for _ in range(n)]


def id19(n, m, p, v):
    return [[[v] * p for _ in range(m)] for i in range(n)]

def ceil(a,b):
    return (a+b-1)//b

mod1=1610612741
mod2=10**9 + 7
mod3=805306457

def id7(N):
    
    
    correction = N % 6 > 1
    N = {0:N, 1:N-1, 2:N+4, 3:N+3, 4:N+2, 5:N+1}[N%6]
    sieve = [True] * (N // 3)
    sieve[0] = False
    for i in range(int(N ** .5) // 3 + 1):
        if sieve[i]:
            k = (3 * i + 1) | 1
            sieve[k*k // 3::2*k] = [False] * ((N//6 - (k*k)//6 - 1)//k + 1)
            sieve[(k*k + 4*k - 2*k*(i%2)) // 3::2*k] = [False] * ((N // 6 - (k*k + 4*k - 2*k*(i%2))//6 - 1) // k + 1)
    return [2, 3] + [(3 * i + 1) | 1 for i in range(1, N//3 - correction) if sieve[i]]

primes=id7(1000000)
mxn=1000005
l=len(primes)
ind=defaultdict(int)
base=6917
for i in range(l):
    ind[primes[i]]=i
pow1=[1]
pow2=[1]
pow3=[1]
for i in range(1,l+2):
    pow1.append((pow1[-1]*base)%mod1)
    pow2.append((pow2[-1] * base) % mod2)
    pow3.append((pow3[-1] * base) % mod3)
lrg=[0]*(mxn)
for i in range(2,mxn-2):
    if(lrg[i]==0):
        for j in range(i,mxn-2,i):lrg[j]=i






def solve():
    d=defaultdict(int)
    n=N()
    ar=lis()
    for i in ar:
        temp=defaultdict(int)
        t=i
        while(t>1):
            temp[lrg[t]]^=1
            t//=lrg[t]
        h1=0
        h2=0
        h3=0
        for j in temp.keys():
            if(temp[j]==1):
                index=ind[j]
                h1=(h1+pow1[index])
                h2 = (h2 + pow2[index])
                h3 = (h3 + pow3[index])
                if(h1>=mod1): h1-=mod1
                if (h2 >= mod2): h2 -= mod2
                if (h3 >= mod3): h3 -= mod3
        d[(h1,h2,h3)]+=1
    fc=max(d.values())
    sc=1
    zero=d[(0,0,0)]

    for i in d.keys():
        if i==(0,0,0): continue
        if(d[i]%2==0):zero+=d[i]
        else:sc=max(sc,d[i])
    sc=max(sc,zero)
    q=N()
    
    
    for _ in range(q):
        tim=N()
        if(tim==0):print(fc)
        else: print(sc)












testcase(int(inp()))
