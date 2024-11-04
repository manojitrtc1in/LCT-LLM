


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




id14 = 8192
 
 
class FastIO(IOBase):
    newlines = 0
    
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
     
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id14))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id14))
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
    def __init__(self, data, default=0, func=lambda a, b: max(a,b)):
        
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
 
        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])
 
    def id11(self, idx):
        self[idx] = self._default
 
    def id13(self, idx):
        return self.data[idx + self._size]
 
    def id8(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1
 
    def id7(self):
        return self._len
 
    def query(self, start, stop):
        if start == stop:
            return self.id13(start)
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
 
    def id1(self):
        return "SegmentTree({0})".format(self.data)
    
class id0:
    def __init__(self, data, default=10**6, func=lambda a, b: min(a,b)):
        
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
 
        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])
 
    def id11(self, idx):
        self[idx] = self._default
 
    def id13(self, idx):
        return self.data[idx + self._size]
 
    def id8(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1
 
    def id7(self):
        return self._len
 
    def query(self, start, stop):
        if start == stop:
            return self.id13(start)
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
 
    def id1(self):
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
 
    def id16(self, n):
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
        return f.calc(n) * f.id16(max(n - k, k)) * f.id16(min(k, n - k)) % self.MOD
mod=10**9+7
omod=998244353

prime = [True for i in range(10001)] 
prime[0]=prime[1]=False

def id3(n=10000):
    p = 2
    c=0
    while (p <= n): 
          
        if (prime[p] == True):
            c+=1
            for i in range(p, n+1, p): 
                
                prime[i] = False
        p += 1

class DSU:
    def __init__(self, R, C):
        
        self.par = range(R*C + 1)
        self.rnk = [0] * (R*C + 1)
        self.sz = [1] * (R*C + 1)

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr: return
        if self.rnk[xr] < self.rnk[yr]:
            xr, yr = yr, xr
        if self.rnk[xr] == self.rnk[yr]:
            self.rnk[xr] += 1

        self.par[yr] = xr
        self.sz[xr] += self.sz[yr]

    def size(self, x):
        return self.sz[self.find(x)]

    def top(self):
        
        
        return self.size(len(self.sz) - 1) - 1


class id6:
    def __init__(self, _op, _e, _mapping, _composition, _id, v):
        def set(p, x):
            assert 0 <= p < _n
            p += _size
            for i in range(_log, 0, -1):
                _push(p >> i)
            _d[p] = x
            for i in range(1, _log + 1):
                _update(p >> i)
 
        def get(p):
            assert 0 <= p < _n
            p += _size
            for i in range(_log, 0, -1):
                _push(p >> i)
            return _d[p]
 
        def prod(l, r):
            assert 0 <= l <= r <= _n
 
            if l == r:
                return _e
 
            l += _size
            r += _size
 
            for i in range(_log, 0, -1):
                if ((l >> i) << i) != l:
                    _push(l >> i)
                if ((r >> i) << i) != r:
                    _push(r >> i)
 
            sml = _e
            smr = _e
            while l < r:
                if l & 1:
                    sml = _op(sml, _d[l])
                    l += 1
                if r & 1:
                    r -= 1
                    smr = _op(_d[r], smr)
                l >>= 1
                r >>= 1
 
            return _op(sml, smr)
 
        def apply(l, r, f):
            assert 0 <= l <= r <= _n
            if l == r:
                return
 
            l += _size
            r += _size
 
            for i in range(_log, 0, -1):
                if ((l >> i) << i) != l:
                    _push(l >> i)
                if ((r >> i) << i) != r:
                    _push((r - 1) >> i)
 
            l2 = l
            r2 = r
            while l < r:
                if l & 1:
                    _all_apply(l, f)
                    l += 1
                if r & 1:
                    r -= 1
                    _all_apply(r, f)
                l >>= 1
                r >>= 1
            l = l2
            r = r2
 
            for i in range(1, _log + 1):
                if ((l >> i) << i) != l:
                    _update(l >> i)
                if ((r >> i) << i) != r:
                    _update((r - 1) >> i)
 
        def _update(k):
            _d[k] = _op(_d[2 * k], _d[2 * k + 1])
 
        def _all_apply(k, f):
            _d[k] = _mapping(f, _d[k])
            if k < _size:
                _lz[k] = _composition(f, _lz[k])
 
        def _push(k):
            _all_apply(2 * k, _lz[k])
            _all_apply(2 * k + 1, _lz[k])
            _lz[k] = _id
 
        _n = len(v)
        _log = _n.bit_length()
        _size = 1 << _log
        _d = [_e] * (2 * _size)
        _lz = [_id] * _size
        for i in range(_n):
            _d[_size + i] = v[i]
        for i in range(_size - 1, 0, -1):
            _update(i)
 
        self.set = set
        self.get = get
        self.prod = prod
        self.apply = apply
 
 
MIL = 1 << 20
 
 
def makeNode(total, count):
    
    return (total * MIL) + count
 
 
def getTotal(node):
    return math.floor(node / MIL)
 
 
def getCount(node):
    return node - getTotal(node) * MIL
 
 
nodeIdentity = makeNode(0.0, 0.0)
 
 
def nodeOp(node1, node2):
    return node1 + node2
    
    return makeNode(
        getTotal(node1) + getTotal(node2), getCount(node1) + getCount(node2)
    )
 
 
identityMapping = -1
 
 
def mapping(tag, node):
    if tag == identityMapping:
        return node
    
    count = getCount(node)
    return makeNode(tag * count, count)
 
 
def composition(mapping1, mapping2):
    
    return mapping1 if mapping1 != identityMapping else mapping2

def id4(f):
    
    class id4(dict):
        def id5(self, key):
            ret = self[key] = f(key)
            return ret
 
    return id4().id13
 
 
def id12(n):
    
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
 
 
@id4
def id10(n):
    
    if n <= 1:
        return Counter()
    f = id12(n)
    return Counter([n]) if f == n else id10(f) + id10(n // f)
 
 
def id9(n):
    
    factors = [1]
    for p, exp in id10(n).items():
        factors += [p**i * factor for factor in factors for i in range(1, exp + 1)]
    return factors
 
 
def id2(n):
    
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

def binarySearch(arr, n, key):
    left = 0
    right = n-1
    mid = 0
    res=arr[n-1]
    while (left <= right):
        mid = (right + left)//2
        if (arr[mid] >= key):
            res=arr[mid]
            right = mid-1
        else:
            left = mid + 1
    return res

def id15(arr, n, key):
    left = 0
    right = n-1
    mid = 0
    res=-1
    while (left <= right):
        mid = (right + left)//2
        if (arr[mid][0] >= key):
            right = mid-1
        else:
            res=mid
            left = mid + 1
    return res

from heapq import heapify,heappop,heappush
t=1
t=int(input())
for _ in range (t):
    
    x=input()
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    tp=list(map(int,input().split()))
    
    b=[[a[i],tp[i]]for i in range (k)]
    b.sort()
    
    h=[]
    heapify(h)
    res=[2*10**9]*n
    j=0
    for i in range (n):
        if j<k and b[j][0]==i+1:
            heappush(h,b[j][1]+n-i)
            j+=1
        if not h:
            continue
        res[i]=min(res[i],h[0]-n+i)
    h=[]
    
    heapify(h)
    j=k-1
    for i in range (n-1,-1,-1):
        if j>=0 and b[j][0]==i+1:
            heappush(h,b[j][1]+i)
            j-=1
        if not h:
            continue
        res[i]=min(res[i],h[0]-i)
    print(*res)