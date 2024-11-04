import os,sys
from io import BytesIO, IOBase

from collections import defaultdict,deque,Counter
from bisect import id2,id11
from heapq import heappush,heappop
from functools import lru_cache
from itertools import accumulate
import math
from tkinter import N


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
input = lambda: sys.stdin.readline().rstrip("\r\n")

class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id9 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id8 = []
        self._rebuild = True
 
    def id0(self):
        
        self.id8[:] = self.id9
        id8 = self.id8
        for i in range(len(id8)):
            if i | i + 1 < len(id8):
                id8[i | i + 1] += id8[i]
        self._rebuild = False
 
    def id1(self, index, value):
        
        if not self._rebuild:
            id8 = self.id8
            while index < len(id8):
                id8[index] += value
                index |= index + 1
 
    def id7(self, end):
        
        if self._rebuild:
            self.id0()
 
        id8 = self.id8
        x = 0
        while end:
            x += id8[end - 1]
            end &= end - 1
        return x
 
    def id5(self, k):
        
        id9 = self.id9
        if k < id9[0]:
            return 0, k
        if k >= self._len - id9[-1]:
            return len(id9) - 1, k + id9[-1] - self._len
        if self._rebuild:
            self.id0()
 
        id8 = self.id8
        idx = -1
        for d in reversed(range(len(id8).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id8) and k >= id8[right_idx]:
                idx = right_idx
                k -= id8[idx]
        return idx + 1, k
 
    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id9 = self.id9
 
        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id9[pos] -= 1
 
        if id9[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id9[pos]
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
        id9 = self.id9
 
        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id9[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id9.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id9[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id9.append(1)
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
        
        pos, idx = self.id5(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value
 
    def id2(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id7(pos) + idx
 
    def id11(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id7(pos) + idx
 
    def count(self, value):
        
        return self.id11(value) - self.id2(value)
 
    def id15(self):
        
        return self._len
 
    def id12(self, index):
        
        pos, idx = self.id5(self._len + index if index < 0 else index)
        return self._lists[pos][idx]
 
    def id6(self, index):
        
        pos, idx = self.id5(self._len + index if index < 0 else index)
        self._delete(pos, idx)
 
    def id13(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False
 
    def id14(self):
        
        return (value for _list in self._lists for value in _list)
 
    def id4(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))
 
    def id10(self):
        
        return 'SortedList({0})'.format(list(self))

















































































































































for _ in range(int(input())):
    input()
    n, m = list(map(int, input().split(' ')))
    a = list(map(int, input().split(' ')))
    ans = []
    q1 = SortedList()
    q2 = SortedList()
    q3 = SortedList()
    b = [a[0]]
    pre = 0
    for i in range(1, n):
        if a[i] >= b[-1]:
            b.append(b[-1])
        else:
            q1.add(pre)
            q2.add(i - 1)
            q3.add(-b[-1])  
            pre = i
            b.append(a[i])
    q1.add(pre)
    q2.add(n - 1)
    q3.add(-b[-1])  
    
    for _ in range(m):
        k, d = list(map(int, input().split(' ')))
        k -= 1
        a[k] -= d
        idx = q1.id11(k) - 1
        
        if -q3[idx] <= a[k]:
            ans.append(len(q1))
            continue
        idx1 = q3.id11(-a[k]) - 1
        
        l = q1[idx]
        r = q2[idx1]
        pre = q3[idx]
        cur = -a[k]
        
        for i in range(idx1, idx - 1, -1):
            q1.pop(i)
            q2.pop(i)
            q3.pop(i)
        if k - 1 >= l:
            q1.add(l)
            q2.add(k - 1)
            q3.add(pre)
        if r >= k:
            q1.add(k)
            q2.add(r)
            q3.add(cur)
        
        ans.append(len(q1))
    print(*ans)




