import sys
from bisect import id16, id4
import os
import sys
from io import BytesIO, IOBase
from math import factorial, floor, inf, ceil, gcd
from collections import defaultdict, deque, Counter
from functools import cmp_to_key
from heapq import heappop, heappush, heapify

id18 = 8192
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id18))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id18))
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
input = lambda: sys.stdin.readline().rstrip("\r\n")


def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input().strip()
    return(s)
def invr():
    return(map(int,input().split()))
def id11():
    s = input()
    return(s.split(" "))





def sqrt(num):
    l, r  = 0, 10**18 + 7
    while r-l != 1:
        mid = (l+r)//2
        square = mid*mid
        if square <= num:
            l = mid
        else:
            r = mid
    return l



def id5(n, r, p):
    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = i * fact[i - 1] % p
    
    inv = [1] * (n + 1)
    inv[n] = pow(fact[n], p - 2, p)
    for i in range(n - 1, -1, -1):
        inv[i] = (i + 1) * inv[i + 1] % p
    
    return fact, inv


def comb(n, r, p, fact, inv):
    return fact[n] * inv[r] % p * inv[n - r] % p if n >= r >= 0 else 0
 
def id6(n):
    id0 = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            id0.append(i)
            if i != n // i and i != 1:
                id0.append(n // i)
    return id0

def dfs(graph, vertex):
    visited = set()
    tree = []
    deq = deque([vertex])
    while deq:
        vertex = deq.pop()
        if vertex not in visited:
            visited.add(vertex)
            deq.extend(graph[vertex])
            tree.append(vertex)
    return tree

def id20(elem, sorted_list):
    
    'Locate the leftmost value exactly equal to x'
    i = id4(sorted_list, elem)
    if i != len(sorted_list) and sorted_list[i] == elem:
        return i
    return -1



class SL:
    def __init__(self, iterable=[], _load=100):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id22 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id21 = []
        self._rebuild = True
 
    def id1(self):
        
        self.id21[:] = self.id22
        id21 = self.id21
        for i in range(len(id21)):
            if i | i + 1 < len(id21):
                id21[i | i + 1] += id21[i]
        self._rebuild = False
 
    def id3(self, index, value):
        
        if not self._rebuild:
            id21 = self.id21
            while index < len(id21):
                id21[index] += value
                index |= index + 1
 
    def id9(self, end):
        
        if self._rebuild:
            self.id1()
 
        id21 = self.id21
        x = 0
        while end:
            x += id21[end - 1]
            end &= end - 1
        return x
 
    def id7(self, k):
        
        id22 = self.id22
        if k < id22[0]:
            return 0, k
        if k >= self._len - id22[-1]:
            return len(id22) - 1, k + id22[-1] - self._len
        if self._rebuild:
            self.id1()
 
        id21 = self.id21
        idx = -1
        for d in reversed(range(len(id21).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id21) and k >= id21[right_idx]:
                idx = right_idx
                k -= id21[idx]
        return idx + 1, k
 
    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id22 = self.id22
 
        self._len -= 1
        self.id3(pos, -1)
        del _lists[pos][idx]
        id22[pos] -= 1
 
        if id22[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id22[pos]
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
        id22 = self.id22
 
        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id3(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id22[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id22.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id22[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id22.append(1)
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
        
        pos, idx = self.id7(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value
 
    def id4(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id9(pos) + idx
 
    def id16(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id9(pos) + idx
 
    def count(self, value):
        
        return self.id16(value) - self.id4(value)
 
    def id24(self):
        
        return self._len
 
    def id17(self, index):
        
        pos, idx = self.id7(self._len + index if index < 0 else index)
        return self._lists[pos][idx]
 
    def id15(self, index):
        
        pos, idx = self.id7(self._len + index if index < 0 else index)
        self._delete(pos, idx)
 
    def id13(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False
 
    def id23(self):
        
        return (value for _list in self._lists for value in _list)
 
    def id19(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))
 
    def id12(self):
        
        return 'SortedList({0})'.format(list(self))


class SegmentTree:
    def __init__(self, data, default=0, func=lambda a, b: a+b):
        
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
 
        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])
 
    def id15(self, idx):
        self[idx] = self._default
 
    def id17(self, idx):
        return self.data[idx + self._size]
 
    def id14(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1
 
    def id24(self):
        return self._len
 
    def query(self, start, stop):
        if start == stop:
            return self.id17(start)
        start += self._size
        stop += self._size
 
        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res
 
    def id12(self):
        return "SegmentTree({0})".format(self.data)
    

class id8():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n
        self.group = n
    
    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]
    
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
    
        if x == y:
            return
        self.group -= 1
        if self.parents[x] > self.parents[y]:
            x, y = y, x
    
        self.parents[x] += self.parents[y]
        self.parents[y] = x
    
    def size(self, x):
        return -self.parents[self.find(x)]
    
    def same(self, x, y):
        return self.find(x) == self.find(y)
    
    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]
    
    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]
    
    def group_count(self):
        return self.group
    
    def id2(self):
        dic = {r:[] for r in self.roots()}
        for i in range(self.n):
            dic[self.find(i)].append(i)
        return dic
    
    def id10(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())



__ = inp()
for _ in range(__):
    def solve():
        
        n = inp()
        l = []
        r = []
        colors = [[] for i in range(n)]
        for i in range(n):
            a,b,c = inlt()
            l.append(a)
            r.append(b)
            colors[c-1].append(i)
            
        sl_l = SL(l)
        sl_r = SL(r)
        ans = [-1]*n
        
        for i in range(n):
            for ind in colors[i]:
                sl_l.discard(l[ind])
                sl_r.discard(r[ind])
                
            for ind in colors[i]:
                
                search_r = sl_r.id16(l[ind])-1
                search_l = sl_l.id4(r[ind])
            
                mn = inf
                if search_r - search_l + 1 < 0:
                    mn = 0
                
                if search_r > -1:
                    mn = min(mn, l[ind] - sl_r[search_r])
                if search_l < len(sl_r):
                    mn = min(mn, sl_l[search_l] - r[ind])
                
                ans[ind] = mn
            
            for ind in colors[i]:
                sl_l.add(l[ind])
                sl_r.add(r[ind])
            
        print(' '.join(map(str, ans)))


        return
    solve() 