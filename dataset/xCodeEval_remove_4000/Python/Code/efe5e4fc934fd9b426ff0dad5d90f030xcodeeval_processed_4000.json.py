from bisect import id2
import math
import os
import sys
from io import BytesIO, IOBase
M = 1000000007
import random
import heapq
import threading
import bisect
import time
from functools import *
from collections import *
from itertools import *
id9 = 8192
import array
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id9))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id9))
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
input = lambda: sys.stdin.readline().rstrip("\r\n")
def inp(): return sys.stdin.readline().rstrip("\r\n")  
def out(var): sys.stdout.write(str(var))  
def lis(): return list(map(int, inp().split()))
def stringlis(): return list(map(str, inp().split()))
def sep(): return map(int, inp().split())
def strsep(): return map(str, inp().split())
def fsep(): return map(float, inp().split())
def inpu(): return int(inp())
class SortedList:
    def __init__(self, iterable=None, _load=200):
        
        if iterable is None:
            iterable = []
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id12 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id11 = []
        self._rebuild = True

    def id0(self):
        
        self.id11[:] = self.id12
        id11 = self.id11
        for i in range(len(id11)):
            if i | i + 1 < len(id11):
                id11[i | i + 1] += id11[i]
        self._rebuild = False

    def id1(self, index, value):
        
        if not self._rebuild:
            id11 = self.id11
            while index < len(id11):
                id11[index] += value
                index |= index + 1

    def id4(self, end):
        
        if self._rebuild:
            self.id0()
        id11 = self.id11
        x = 0
        while end:
            x += id11[end - 1]
            end &= end - 1
        return x

    def id3(self, k):
        
        id12 = self.id12
        if k < id12[0]:
            return 0, k
        if k >= self._len - id12[-1]:
            return len(id12) - 1, k + id12[-1] - self._len
        if self._rebuild:
            self.id0()

        id11 = self.id11
        idx = -1
        for d in reversed(range(len(id11).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id11) and k >= id11[right_idx]:
                idx = right_idx
                k -= id11[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id12 = self.id12

        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id12[pos] -= 1

        if id12[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id12[pos]
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
        id12 = self.id12

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id12[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id12.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id12[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id12.append(1)
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

    def id7(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id4(pos) + idx

    def id14(self):
        
        return self._len

    def id8(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id6(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id5(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id13(self):
        
        return (value for _list in self._lists for value in _list)

def build(a,b,st,arr,node):
    if a==b:
        st[node] = arr[a]
        return arr[a]
    mid = (a+b)//2
    p = build(a,mid,st,arr,2*node+1)
    q = build(mid+1,b,st,arr,2*node+2)
    st[node] = p+q
    return st[node]
def update(st,a,b,x,val,node):
    if x<a or x>b:
        return
    st[node] = st[node] + val
    if a!=b:
        mid = (a+b)//2
        update(st,a,mid,x,val,2*node+1)
        update(st,mid+1,b,x,val,2*node+2)
def getsum(st,a,b,l,r,node):
    if l>b or r<a:
        return 0
    if l<=a and r>=b:
        return st[node]
    mid = (a+b)//2
    return getsum(st,a,mid,l,r,2*node+1) + getsum(st,mid+1,b,l,r,2*node+2)
def dfs2(curr,parent,start,end,cnt,res,d,arr):
    res[cnt[0]] = arr[curr-1]
    start[curr] = cnt[0]
    cnt[0]+=1
    for i in d[curr]:
        if i!=parent:
            dfs2(i,curr,start,end,cnt,res,d,arr)
            cnt[0]+=1
    res[cnt[0]] = arr[curr-1]
    end[curr] = cnt[0]




def calculate(p, q ,mod):
    expo = mod - 2
    while (expo):
        if (expo & 1):
            p = (p * q) % mod
        q = (q * q) % mod
        expo >>= 1
    return p
def checkBit(pattern, arr, n):
    count = 0
    for i in range(0, n):
        if ((pattern & arr[i]) == pattern):
            count = count + 1
    return count
def maxAND(arr, n):
    res = 0
    for bit in range(31, -1, -1):
        count = checkBit(res | (1 << bit), arr, n)
        if (count >= 2):
            res = res | (1 << bit)
    return res
def mex(arr):
    len1 = len(arr)
    lo=0
    hi=len1-1
    ans = 0
    while(lo<=hi):
        mid = (lo+hi)//2
        if arr[mid]==mid:
            ans = mid+1
            lo=mid+1
        else:
            ans = mid
            hi=mid-1
    return ans
def main():
    id10 = 1
    id10 = inpu()
    for _ in range(id10):
        n = inpu()
        aa = lis()
        a = SortedList()
        for i in aa:
            a.add(i)
        bb = lis()
        b = SortedList()
        for i in range(n):
            p = bb[i]
            if p in a:
                a.remove(p)
            else:
                b.add(p)
        l = []
        for i in b:
            temp = i
            while (temp <= 10 ** 9):
                if temp in a:
                    l.append(i)
                    a.remove(temp)
                    break
                temp *= 2
        for i in l:
            b.remove(i)
        s=SortedList()
        for i in a:
            p = i
            while(p%2==0):
                p//=2
            s.add(p)
        for i in b:
            t=i
            while(t):
                if t in s:
                    s.remove(t)
                    break
                t//=2
        if len(s)!=0:
            print("NO")
        else:
            print("YES")
if __name__ == '__main__':
    
    
    
    main()
