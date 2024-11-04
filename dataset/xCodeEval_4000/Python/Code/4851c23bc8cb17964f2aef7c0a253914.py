    

import os 
import sys 
from io import BytesIO, IOBase  
import heapq as h 
import bisect 
import math as mt
from types import GeneratorType  
BUFSIZE = 8192
class SortedList: 
    def __init__(self, iterable=[], _load=200):
        """Initialize sorted list instance."""
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self._list_lens = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self._fen_tree = []
        self._rebuild = True
 
    def _fen_build(self):
        """Build a fenwick tree instance."""
        self._fen_tree[:] = self._list_lens
        _fen_tree = self._fen_tree
        for i in range(len(_fen_tree)):
            if i | i + 1 < len(_fen_tree):
                _fen_tree[i | i + 1] += _fen_tree[i]
        self._rebuild = False
 
    def _fen_update(self, index, value):
        """Update `fen_tree[index] += value`."""
        if not self._rebuild:
            _fen_tree = self._fen_tree
            while index < len(_fen_tree):
                _fen_tree[index] += value
                index |= index+1
 
    def _fen_query(self, end):
        """Return `sum(_fen_tree[:end])`."""
        if self._rebuild:
            self._fen_build()
 
        _fen_tree = self._fen_tree
        x = 0
        while end:
            x += _fen_tree[end - 1]
            end &= end - 1
        return x
 
    def _fen_findkth(self, k):
        """Return a pair of (the largest `idx` such that `sum(_fen_tree[:idx]) <= k`, `k - sum(_fen_tree[:idx])`)."""
        _list_lens = self._list_lens
        if k < _list_lens[0]:
            return 0, k
        if k >= self._len - _list_lens[-1]:
            return len(_list_lens) - 1, k + _list_lens[-1] - self._len
        if self._rebuild:
            self._fen_build()
 
        _fen_tree = self._fen_tree
        idx = -1
        for d in reversed(range(len(_fen_tree).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(_fen_tree) and k >= _fen_tree[right_idx]:
                idx = right_idx
                k -= _fen_tree[idx]
        return idx + 1, k
 
    def _delete(self, pos, idx):
        """Delete value at the given `(pos, idx)`."""
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens
 
        self._len -= 1
        self._fen_update(pos, -1)
        del _lists[pos][idx]
        _list_lens[pos] -= 1
 
        if _list_lens[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del _list_lens[pos]
            del _mins[pos]
            self._rebuild = True
 
    def _loc_left(self, value):
        """Return an index pair that corresponds to the first position of `value` in the sorted list."""
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
        """Return an index pair that corresponds to the last position of `value` in the sorted list."""
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
        """Add `value` to sorted list."""
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens
 
        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self._fen_update(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            _list_lens[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                _list_lens.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                _list_lens[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            _list_lens.append(1)
            self._rebuild = True
 
    def discard(self, value):
        """Remove `value` from sorted list if it is a member."""
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_right(value)
            if idx and _lists[pos][idx - 1] == value:
                self._delete(pos, idx - 1)
 
    def remove(self, value):
        """Remove `value` from sorted list; `value` must be a member."""
        _len = self._len
        self.discard(value)
        if _len == self._len:
            raise ValueError('{0!r} not in list'.format(value))
 
    def pop(self, index=-1):
        """Remove and return value at `index` in sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value
 
    def bisect_left(self, value):
        """Return the first index to insert `value` in the sorted list."""
        pos, idx = self._loc_left(value)
        return self._fen_query(pos) + idx
 
    def bisect_right(self, value):
        """Return the last index to insert `value` in the sorted list."""
        pos, idx = self._loc_right(value)
        return self._fen_query(pos) + idx
 
    def count(self, value):
        """Return number of occurrences of `value` in the sorted list."""
        return self.bisect_right(value) - self.bisect_left(value)
 
    def __len__(self):
        """Return the size of the sorted list."""
        return self._len
 
    def __getitem__(self, index):
        """Lookup value at `index` in sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        return self._lists[pos][idx]
 
    def __delitem__(self, index):
        """Remove value at `index` from sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        self._delete(pos, idx)
 
    def __contains__(self, value):
        """Return true if `value` is an element of the sorted list."""
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False
 
    def __iter__(self):
        """Return an iterator over the sorted list."""
        return (value for _list in self._lists for value in _list)
 
    def __reversed__(self):
        """Return a reverse iterator over the sorted list."""
        return (value for _list in reversed(self._lists) for value in reversed(_list))
 
    def __repr__(self):
        """Return string representation of sorted list."""
        return 'SortedList({0})'.format(list(self))
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        import os
        self.os = os
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            self.os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
import sys
from math import ceil,log2 
  
INT_MAX = sys.maxsize
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
import collections as col
import math, string
 
def getInts():
    return [int(s) for s in input().split()]
 
def getInt():
    return int(input())
 
def getStrs():
    return [s for s in input().split()]
 
def getStr():
    return input()
 
def listStr():
    return list(input())
def minVal(x, y) : 
    return x if (x < y) else y;  
  


def getMid(s, e) : 
    return s + (e - s) // 2;  
  
""" A recursive function to get the  
minimum value in a given range  
of array indexes. The following  
are parameters for this function.  
  
    st --> Pointer to segment tree  
    index --> Index of current node in the  
        segment tree. Initially 0 is  
        passed as root is always at index 0  
    ss & se --> Starting and ending indexes  
                of the segment represented  
                by current node, i.e., st[index]  
    qs & qe --> Starting and ending indexes of query range """
def RMQUtil( st, ss, se, qs, qe, index) : 
  
    
    
    
    if (qs <= ss and qe >= se) : 
        return st[index];  
  
    
    
    if (se < qs or ss > qe) : 
        return INT_MAX;  
  
    
    
    mid = getMid(ss, se);  
    return minVal(RMQUtil(st, ss, mid, qs,  
                          qe, 2 * index + 1),  
                  RMQUtil(st, mid + 1, se, 
                          qs, qe, 2 * index + 2));  
  



def RMQ( st, n, qs, qe) :  
  
    
    if (qs < 0 or qe > n - 1 or qs > qe) : 
      
        print("Invalid Input");  
        return -1;  
      
    return RMQUtil(st, 0, n - 1, qs, qe, 0);  
  



def constructSTUtil(arr, ss, se, st, si) : 
  
    
    
    
    if (ss == se) : 
  
        st[si] = arr[ss];  
        return arr[ss];  
  
    
    
    
    mid = getMid(ss, se);  
    st[si] = minVal(constructSTUtil(arr, ss, mid, 
                                    st, si * 2 + 1), 
                    constructSTUtil(arr, mid + 1, se, 
                                    st, si * 2 + 2));  
      
    return st[si];  
  
"""Function to construct segment tree  
from given array. This function allocates  
memory for segment tree and calls constructSTUtil() 
to fill the allocated memory """
def constructST( arr, n) : 
  
    
  
    
    x = (int)(ceil(log2(n)));  
  
    
    max_size = 2 * (int)(2**x) - 1;  
   
    st = [0] * (max_size);  
  
    
    constructSTUtil(arr, 0, n - 1, st, 0);  
  
    
    return st;  
  
 
MOD = 10**9+7
mod=10**9+7

p=10**9+7
def ncr_util():
    
    inv[0]=inv[1]=1
    fact[0]=fact[1]=1
    for i in range(2,300001):
        inv[i]=(inv[i%p]*(p-p//i))%p
    for i in range(1,300001):
        inv[i]=(inv[i-1]*inv[i])%p
        fact[i]=(fact[i-1]*i)%p

def z_array(s1):
    n = len(s1)
    z=[0]*(n)
    l, r, k = 0, 0, 0
    for i in range(1,n): 
  
        
        
        if i > r: 
            l, r = i, i 
  
            
            
            
            
            
            while r < n and s1[r - l] == s1[r]: 
                r += 1
            z[i] = r - l 
            r -= 1
        else: 
  
            
            
            k = i - l 
  
            
            
            
            
            if z[k] < r - i + 1: 
                z[i] = z[k] 
  
            
            
            else: 
  
                
                l = i 
                while r < n and s1[r - l] == s1[r]: 
                    r += 1
                z[i] = r - l 
         
                r -= 1  
    return z
'''
MAXN1=100001
spf=[0]*MAXN1

def sieve():
    spf[1]=1
    for i in range(2,MAXN1):
        spf[i]=i
    for i in range(4,MAXN1,2):
        spf[i]=2
    for i in range(3,math.ceil(math.sqrt(MAXN1))):
        if spf[i]==i:
            for j in range(i*i,MAXN1,i):
                if spf[j]==j:
                    spf[j]=i
    
def factor(x):
    d1={}
    x1=x
    while x!=1:
        d1[spf[x]]=d1.get(spf[x],0)+1
        x//=spf[x]
    return d1 
'''
def primeFactors(n): 
    d1={}  
    while n % 2 == 0: 
        d1[2]=d1.get(2,0)+1 
        n = n / 2
          
    for i in range(3,int(math.sqrt(n))+1,2): 
          
        
        while n % i== 0: 
            d1[i]=d1.get(i,0)+1 
            n = n // i 
              
    
    if n > 2: 
        d1[n]=d1.get(n,0)+1
    return d1
def fs(x):
    if x<2:
        return 0
        
    return (x*(x-1))//2
t=int(input())

def solve():
    ans=0    
    for i in range(n):
        x,ind=0,0
        for j in range(2):
            if (int(b[i])+j)!=ans and x<=(int(b[i])+j):
                x=(int(b[i])+j)
                ind=j 
        print(ind,end="")      
        ans=x
                
    print()
for _ in range(t):
    n=int(input())
    
    
    
    b=input()
    
    
    
    
    
    
    
    
    
    
    
    (solve())
    
        