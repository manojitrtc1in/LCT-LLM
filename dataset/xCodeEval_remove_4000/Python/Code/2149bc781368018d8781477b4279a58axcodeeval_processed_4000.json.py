import sys, os, io
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')
import math,datetime,functools,itertools,operator,bisect,fractions,statistics
from collections import deque,defaultdict,OrderedDict,Counter
from fractions import Fraction
from decimal import Decimal
from sys import stdout
from heapq import heappush, heappop, heapify ,_heapify_max,_heappop_max,nsmallest,nlargest

INF=999999999999999999999999
alphabets="abcdefghijklmnopqrstuvwxyz"
class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id25 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id24 = []
        self._rebuild = True
 
    def id0(self):
        
        self.id24[:] = self.id25
        id24 = self.id24
        for i in range(len(id24)):
            if i | i + 1 < len(id24):
                id24[i | i + 1] += id24[i]
        self._rebuild = False
 
    def id1(self, index, value):
        
        if not self._rebuild:
            id24 = self.id24
            while index < len(id24):
                id24[index] += value
                index |= index + 1
 
    def id4(self, end):
        
        if self._rebuild:
            self.id0()
 
        id24 = self.id24
        x = 0
        while end:
            x += id24[end - 1]
            end &= end - 1
        return x
 
    def id3(self, k):
        
        id25 = self.id25
        if k < id25[0]:
            return 0, k
        if k >= self._len - id25[-1]:
            return len(id25) - 1, k + id25[-1] - self._len
        if self._rebuild:
            self.id0()
 
        id24 = self.id24
        idx = -1
        for d in reversed(range(len(id24).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id24) and k >= id24[right_idx]:
                idx = right_idx
                k -= id24[idx]
        return idx + 1, k
 
    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id25 = self.id25
 
        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id25[pos] -= 1
 
        if id25[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id25[pos]
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
        id25 = self.id25
 
        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id25[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id25.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id25[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id25.append(1)
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
 
    def id20(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id4(pos) + idx
 
    def count(self, value):
        
        return self.id20(value) - self.id2(value)
 
    def id14(self):
        
        return self._len
 
    def id21(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        return self._lists[pos][idx]
 
    def id17(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        self._delete(pos, idx)
 
    def id9(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False
 
    def id28(self):
        
        return (value for _list in self._lists for value in _list)
 
    def id23(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))
 
    def id8(self):
        
        return 'SortedList({0})'.format(list(self))
    
class SegTree:
    
    def __init__(self, n):
        self.N = 1 << n.bit_length()
        self.tree = [0] * (self.N<<1)
    
    def update(self, i, j, v):
        i += self.N
        j += self.N
        while i <= j:
            if i%2==1: self.tree[i] += v
            if j%2==0: self.tree[j] += v
            i, j = (i+1) >> 1, (j-1) >> 1
    
    def query(self, i):
        v = 0
        i += self.N
        while i > 0:
            v += self.tree[i]
            i >>= 1
        return v

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
from collections import Counter


def gcd(x, y):
    
    while y:
        x, y = y, x % y
    return x


def id12(f):
    
    class id12(dict):
        def id13(self, key):
            ret = self[key] = f(key)
            return ret

    return id12().id21


def id19(n):
    
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
                return gcd(prev - 1, n)
            if p == n - 1:
                break
        else:
            for i in range(2, n):
                x, y = i, (i * i + 1) % n
                f = gcd(abs(x - y), n)
                while f == 1:
                    x, y = (x * x + 1) % n, (y * y + 1) % n
                    y = (y * y + 1) % n
                    f = gcd(abs(x - y), n)
                if f != n:
                    return f
    return n


@id12
def id16(n):
    
    if n <= 1:
        return Counter()
    f = id19(n)
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

def main():

    mod=1000000007
    
    
    
    starttime=datetime.datetime.now()
    if(os.path.exists('input.txt')):
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    
    tc=1
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    tc=ri()
    for _ in range(tc):
        n,m=ria()
        s=rs()
        cum=0  
        val=[0]
        mxpref=[0]
        id5=[0]
        for i in s:
            if i=="+":
                cum+=1
            else:
                cum-=1
            val.append(cum)
            mxpref.append(max(cum,mxpref[-1]))
            id5.append(min(cum,id5[-1]))
        
        
        
        
        id6=[val[-1]]
        id27=[val[-1]]
        for i in range(n,0,-1):
            id6.append(max(val[i],id6[-1]))
            id27.append(min(val[i],id27[-1]))
        
        
        
       
        for i in range(m):
            l,r=ria()
            upperpref=mxpref[l-1]
            lowerpref=id5[l-1]
            netchange=val[r]-val[l-1]
            id18=id6[n-r]-netchange
            id22=id27[n-r]-netchange
            wi(max(upperpref,id18)-min(lowerpref,id22)+1)
                
        
                            
       
       
        
        
        
                 
            
            
            

        
                                    
        
                
                    

        
        
 
                
        
        
        
        
        
        

                    
                
                
                
        
        
        
            
        
                        
            
 
            


                

        
        
        
        
        
       
        
       

        
        

            
            
            
                
            

            
            
        
        
           
        
        
                 
                
        
        

        
        

        
        
        
            
        
        
            
                

            
            
                
            
            
            
            
        
        
       
         
        

        
        
                    
                        

                    
           
                     
            
        
                
        
        
            
        
        
        
        
        

    
        
        
        
                
                
        
        
        
    

        
        
        

        
                             
        
        
        
            
        
        
                     
        
        
                    
        
                     
                    
                    
                
                
                    
                
        
        
            
                   
        
                    

        
        
                
            
            
    
            
                        
        
    

        
    
    endtime=datetime.datetime.now()
    time=(endtime-starttime).total_seconds()*1000
    if(os.path.exists('input.txt')):
        print("Time:",time,"ms")  
    
                
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


class id26(io.IOBase):
    def __init__(self, fd=0):
        self.buffer = FastReader(fd)
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


class id7(io.IOBase):
    def __init__(self, fd=1):
        self.buffer = FastWriter(fd)
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.flush = self.buffer.flush


if __name__ == '__main__':
    sys.stdin = id26()
    sys.stdout = id7()
    main()
    