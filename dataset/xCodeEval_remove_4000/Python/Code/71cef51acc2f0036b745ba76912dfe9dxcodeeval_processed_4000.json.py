def main():
    mod=1000000007
    
    
    
    tc=ri()
    for i in range(tc): 
        A,B,n=ria()
        a=ria()
        b=ria()
        d=[]
        ans="YES"
        for i in range(n):
            id19=(b[i]+A-1)//A
            B-=(id19-1)*a[i] 
            
        a=sorted(a)
        for i in a[:n-1]:
            B-=i
        if B<=0:
            ans="NO"
        ws(ans)
                  

        
def rant():
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return "AAAAAAAAAAAAAAAAARRRGHHHHHHHHHHHHHHHHHHHHHHHH"
    
def position_dict(arr):
    posn={}
    for i in range(len(arr)):
        if arr[i] in posn:
            posn[arr[i]].append(i)
        else:
            posn[arr[i]]=[i]
    return posn

def id11(limit):
    
    isPrime = [True]*(limit+1)
    isPrime[0] = isPrime[1] = False
    primes = []
    for i in range(2, limit+1):
        if not isPrime[i]:continue
        primes += [i]
        for j in range(i*i, limit+1, i):
            isPrime[j] = False
    return primes

def id12(f):
    
    class id12(dict):
        def id13(self, key):
            ret = self[key] = f(key)
            return ret

    return id12().id21

def id18(n):
    
    if n & 1 == 0:
        return 2
    if n % 3 == 0:
        return 3

    s = ((n - 1) & (1 - n)).bit_length() - 1
    d = n >> s
    for a in [2, 325, 9375, 28178, 450775, 9780504, 1795265022]:
        p = pow(a, d, n)
        if p == 1 or p == n - 1 or a % n == 0:
            continue
        for _ in range(s):
            prev = p
            p = (p * p) % n
            if p == 1:
                return math.gcd(prev - 1, n)
            if p == n - 1:
                break
        else:
            for i in range(2, n):
                x, y = i, (i * i + 1) % n
                f = math.gcd(abs(x - y), n)
                while f == 1:
                    x, y = (x * x + 1) % n, (y * y + 1) % n
                    y = (y * y + 1) % n
                    f = math.gcd(abs(x - y), n)
                if f != n:
                    return f
    return n

@id12
def id16(n):
    
    if n <= 1:
        return Counter()
    f = id18(n)
    return Counter([n]) if f == n else id16(f) + id16(n // f)

def id15(n):
    
    factors = [1]
    for p, exp in id16(n).items():
        factors += [p**i * factor for factor in factors for i in range(1, exp + 1)]
    return factors

def id10(n):
    
    small, large = [], []
    for i in range(1, int(n**0.5) + 1, 2 if n & 1 else 1):
        if not n % i:
            small.append(i)
            large.append(n // i)
    if small[-1] == large[-1]:
        large.pop()
    large.reverse()
    small.extend(large)
    return small

def id9(max_n=2 * 10**5, mod=10**9 + 7):
    max_n = min(max_n, mod - 1)

    fact, inv_fact = [0] * (max_n + 1), [0] * (max_n + 1)
    fact[0] = 1
    for i in range(max_n):
        fact[i + 1] = fact[i] * (i + 1) % mod

    inv_fact[-1] = pow(fact[-1], mod - 2, mod)
    for i in reversed(range(max_n)):
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod

    def id26(n, r):
        res = 1
        while n or r:
            a, b = n % mod, r % mod
            if a < b:
                return 0
            res = res * fact[a] % mod * inv_fact[b] % mod * inv_fact[a - b] % mod
            n //= mod
            r //= mod
        return res

    return id26

class id4:
    def __init__(self, n):
        self.parent = [*range(n+1)]
        self.size = [1]*(n+1)
        self.min, self.max = [*range(n+1)], [*range(n+1)]
        self.count = n

    def get(self, a):
        
        if self.parent[a] == a:
            return a
        x = a
        while a != self.parent[a]:
            a = self.parent[a]
        while x != self.parent[x]:
            self.parent[x], x = a, self.parent[x]
        return a

    def union(self, a, b):
        
        a, b = self.get(a), self.get(b)
        if a != b:
            if self.size[a] > self.size[b]:
                a, b = b, a
            self.parent[a] = b
            self.size[b] += self.size[a]
            self.min[b] = min(self.min[a], self.min[b])
            self.max[b] = max(self.max[a], self.max[b])
            self.count -= 1

    def sz(self,a):
        return self.size[self.get(a)]
    
    def count_sets(self):
        
        return self.count
    
class SegmentTree:
    
    
    
    def __init__(self, data, default=0, func=max):
        
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def id17(self, idx):
        self[idx] = self._default

    def id21(self, idx):
        return self.data[idx + self._size]

    def id14(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def id28(self):
        return self._len

    def query(self, start, stop):
        
        stop+=1
        start += self._size
        stop += self._size

        res_left = res_right = self._default
        while start < stop:
            if start & 1:
                res_left = self._func(res_left, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res_right = self._func(self.data[stop], res_right)
            start >>= 1
            stop >>= 1

        return self._func(res_left, res_right)

    def id7(self):
        return "SegmentTree({0})".format(self.data)

class SparseTable:
    def __init__(self, data, func=min):
        self.func = func
        self._data = _data = [list(data)]
        i, n = 1, len(_data[0])
        while 2 * i <= n:
            prev = _data[-1]
            _data.append([func(prev[j], prev[j + i]) for j in range(n - 2 * i + 1)])
            i <<= 1

    def query(self, start, stop):
        
        depth = (stop + 1 - start).bit_length() - 1
        return self.func(self._data[depth][start], self._data[depth][stop + 1 - (1 << depth)])

    def id21(self, idx):
        return self._data[0][idx]
              
class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id24 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id23 = []
        self._rebuild = True
 
    def id0(self):
        
        self.id23[:] = self.id24
        id23 = self.id23
        for i in range(len(id23)):
            if i | i + 1 < len(id23):
                id23[i | i + 1] += id23[i]
        self._rebuild = False
 
    def id1(self, index, value):
        
        if not self._rebuild:
            id23 = self.id23
            while index < len(id23):
                id23[index] += value
                index |= index + 1
 
    def id5(self, end):
        
        if self._rebuild:
            self.id0()
 
        id23 = self.id23
        x = 0
        while end:
            x += id23[end - 1]
            end &= end - 1
        return x
 
    def id3(self, k):
        
        id24 = self.id24
        if k < id24[0]:
            return 0, k
        if k >= self._len - id24[-1]:
            return len(id24) - 1, k + id24[-1] - self._len
        if self._rebuild:
            self.id0()
 
        id23 = self.id23
        idx = -1
        for d in reversed(range(len(id23).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id23) and k >= id23[right_idx]:
                idx = right_idx
                k -= id23[idx]
        return idx + 1, k
 
    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id24 = self.id24
 
        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id24[pos] -= 1
 
        if id24[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id24[pos]
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
        id24 = self.id24
 
        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id24[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id24.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id24[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id24.append(1)
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
        return self.id5(pos) + idx
 
    def id20(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id5(pos) + idx
 
    def count(self, value):
        
        return self.id20(value) - self.id2(value)
 
    def id28(self):
        
        return self._len
 
    def id21(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        return self._lists[pos][idx]
 
    def id17(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        self._delete(pos, idx)
 
    def id8(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False
 
    def id27(self):
        
        return (value for _list in self._lists for value in _list)
 
    def id22(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))
 
    def id7(self):
        
        return 'SortedList({0})'.format(list(self))

import sys, os, io ,copy
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')
import math,datetime,functools,itertools,operator,bisect,fractions,statistics
from math import log2
from bisect import id2,id20
from collections import deque,defaultdict,OrderedDict,Counter
from fractions import Fraction
from decimal import Decimal
from sys import stdout
from heapq import heappush, heappop, heapify ,_heapify_max,_heappop_max,nsmallest,nlargest

INF=999999999999999999999999
alphabets="abcdefghijklmnopqrstuvwxyz"

class FastReader(io.IOBase):
    newlines = 0

    def __init__(self, fd, chunk_size=1024 * 8):
        self._fd = fd
        self._chunk_size = chunk_size
        self.buffer = io.BytesIO()

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, self._chunk_size))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self, size=-1):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, self._chunk_size if size == -1 else size))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

class FastWriter(io.IOBase):

    def __init__(self, fd):
        self._fd = fd
        self.buffer = io.BytesIO()
        self.write = self.buffer.write

    def flush(self):
        os.write(self._fd, self.buffer.getvalue())
        self.buffer.truncate(0), self.buffer.seek(0)

class id25(io.IOBase):
    def __init__(self, fd=0):
        self.buffer = FastReader(fd)
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")

class id6(io.IOBase):
    def __init__(self, fd=1):
        self.buffer = FastWriter(fd)
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.flush = self.buffer.flush

if __name__ == '__main__':
    sys.stdin = id25()
    sys.stdout = id6()
    starttime=datetime.datetime.now()
    if(os.path.exists('input.txt')):
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    main()
    endtime=datetime.datetime.now()
    time=(endtime-starttime).total_seconds()*1000
    if(os.path.exists('input.txt')):
        print("Time:",time,"ms")  
    