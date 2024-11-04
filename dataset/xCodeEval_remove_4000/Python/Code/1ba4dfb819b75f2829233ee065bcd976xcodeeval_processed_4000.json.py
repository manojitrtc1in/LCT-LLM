


import os
import sys
import math
from io import BytesIO, IOBase
import io
from fractions import Fraction
import collections
from itertools import permutations
from collections import defaultdict
from collections import deque
from collections import Counter
import threading




id19 = 8192
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id19))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id19))
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



class SegmentTree:
    def __init__(self, data, default=10**18, func=lambda a, b: min(a,b)):
        
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
 
    def id18(self, idx):
        return self.data[idx + self._size]
 
    def id12(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1
 
    def id11(self):
        return self._len
 
    def query(self, start, stop):
        if start == stop:
            return self.id18(start)
        stop += 1
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
 
    def id5(self):
        return "SegmentTree({0})".format(self.data)
    
MOD=10**9+7
class Factorial:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorials = [1, 1]
        self.invModulos = [0, 1]
        self.invFactorial_ = [1, 1]
 
    def calc(self, n):
        if n <= -1:
            print("Invalid argument to calculate n!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.factorials):
            return self.factorials[n]
        nextArr = [0] * (n + 1 - len(self.factorials))
        initialI = len(self.factorials)
        prev = self.factorials[-1]
        m = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = prev * i % m
        self.factorials += nextArr
        return self.factorials[n]
 
    def inv(self, n):
        if n <= -1:
            print("Invalid argument to calculate n^(-1)")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        p = self.MOD
        pi = n % p
        if pi < len(self.invModulos):
            return self.invModulos[pi]
        nextArr = [0] * (n + 1 - len(self.invModulos))
        initialI = len(self.invModulos)
        for i in range(initialI, min(p, n + 1)):
            next = -self.invModulos[p % i] * (p // i) % p
            self.invModulos.append(next)
        return self.invModulos[pi]
 
    def id25(self, n):
        if n <= -1:
            print("Invalid argument to calculate (n^(-1))!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.invFactorial_):
            return self.invFactorial_[n]
        self.inv(n)  
        nextArr = [0] * (n + 1 - len(self.invFactorial_))
        initialI = len(self.invFactorial_)
        prev = self.invFactorial_[-1]
        p = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = (prev * self.invModulos[i % p]) % p
        self.invFactorial_ += nextArr
        return self.invFactorial_[n]
 
 
class Combination:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorial = Factorial(MOD)
 
    def ncr(self, n, k):
        if k < 0 or n < k:
            return 0
        k = min(k, n - k)
        f = self.factorial
        return f.calc(n) * f.id25(max(n - k, k)) * f.id25(min(k, n - k)) % self.MOD
mod=10**9+7
omod=998244353

prime = [True for i in range(101)] 
prime[0]=prime[1]=False

def id8(n=10000):
    p = 2
    c=0
    while (p <= n): 
          
        if (prime[p] == True):
            c+=1
            for i in range(p*p, n+1, p): 
                
                prime[i] = False
        p += 1


def id9(f):
    
    class id9(dict):
        def id10(self, key):
            ret = self[key] = f(key)
            return ret
 
    return id9().id18
 
 
def id16(n):
    
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
 
 
@id9
def id14(n):
    
    if n <= 1:
        return Counter()
    f = id16(n)
    return Counter([n]) if f == n else id14(f) + id14(n // f)
 
 
def id13(n):
    
    factors = [1]
    for p, exp in id14(n).items():
        factors += [p**i * factor for factor in factors for i in range(1, exp + 1)]
    return factors
 
 
def id7(n):
    
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

class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id22 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id21 = []
        self._rebuild = True
 
    def id0(self):
        
        self.id21[:] = self.id22
        id21 = self.id21
        for i in range(len(id21)):
            if i | i + 1 < len(id21):
                id21[i | i + 1] += id21[i]
        self._rebuild = False
 
    def id1(self, index, value):
        
        if not self._rebuild:
            id21 = self.id21
            while index < len(id21):
                id21[index] += value
                index |= index + 1
 
    def id4(self, end):
        
        if self._rebuild:
            self.id0()
 
        id21 = self.id21
        x = 0
        while end:
            x += id21[end - 1]
            end &= end - 1
        return x
 
    def id3(self, k):
        
        id22 = self.id22
        if k < id22[0]:
            return 0, k
        if k >= self._len - id22[-1]:
            return len(id22) - 1, k + id22[-1] - self._len
        if self._rebuild:
            self.id0()
 
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
        self.id1(pos, -1)
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
            self.id1(pos, 1)
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
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value
 
    def id2(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id4(pos) + idx
 
    def id17(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id4(pos) + idx
 
    def count(self, value):
        
        return self.id17(value) - self.id2(value)
 
    def id11(self):
        
        return self._len
 
    def id18(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        return self._lists[pos][idx]
 
    def id15(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        self._delete(pos, idx)
 
    def id6(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False
 
    def id26(self):
        
        return (value for _list in self._lists for value in _list)
 
    def id20(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))
 
    def id5(self):
        
        return 'SortedList({0})'.format(list(self))

def binarySearch(arr, n, key):
    left = 0
    right = n-1
    mid = 0
    res = n
    while (left <= right):
        mid = (right + left)//2
        if (arr[mid] >= key):
            res=mid
            right = mid-1
        else:
            left = mid + 1
    return res

def id23(arr, n, key):
    left = 0
    right = n-1
    mid = 0
    res=-1
    while (left <= right):
        mid = (right + left)//2
        if (arr[mid] > key):
            right = mid-1
        else:
            res=mid
            left = mid + 1
    return res

def id24(arr, n, key):
    left = 0
    right = n - 1
 
    count = 0
 
    while (left <= right):
        mid = int((right + left) / 2)
 
        
        
        if (arr[mid] < key):
            count = mid + 1
            left = mid + 1
 
        
        else:
            right = mid - 1
 
    return count


tt=1
tt=int(input()) 
for _ in range (tt):
    
    n=int(input())
    
    
    
    
    
    if n%2:
        print(0)
    else:
        print(pow(math.factorial(n//2)%omod,2,omod))