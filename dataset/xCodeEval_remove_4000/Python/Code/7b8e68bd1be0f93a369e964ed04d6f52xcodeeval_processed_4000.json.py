import sys 
from io import BytesIO, IOBase  
import heapq as h 
import bisect 
import math as mt
from types import GeneratorType  
id15 = 8192
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
 
    def id1(self):
        
        self.id17[:] = self.id18
        id17 = self.id17
        for i in range(len(id17)):
            if i | i + 1 < len(id17):
                id17[i | i + 1] += id17[i]
        self._rebuild = False
 
    def id2(self, index, value):
        
        if not self._rebuild:
            id17 = self.id17
            while index < len(id17):
                id17[index] += value
                index |= index+1
 
    def id5(self, end):
        
        if self._rebuild:
            self.id1()
 
        id17 = self.id17
        x = 0
        while end:
            x += id17[end - 1]
            end &= end - 1
        return x
 
    def id4(self, k):
        
        id18 = self.id18
        if k < id18[0]:
            return 0, k
        if k >= self._len - id18[-1]:
            return len(id18) - 1, k + id18[-1] - self._len
        if self._rebuild:
            self.id1()
 
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
        self.id2(pos, -1)
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
            self.id2(pos, 1)
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
        
        pos, idx = self.id4(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value
 
    def id3(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id5(pos) + idx
 
    def id12(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id5(pos) + idx
 
    def count(self, value):
        
        return self.id12(value) - self.id3(value)
 
    def id10(self):
        
        return self._len
 
    def id13(self, index):
        
        pos, idx = self.id4(self._len + index if index < 0 else index)
        return self._lists[pos][idx]
 
    def id11(self, index):
        
        pos, idx = self.id4(self._len + index if index < 0 else index)
        self._delete(pos, idx)
                 
    def id9(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False
 
    def id20(self):
        
        return (value for _list in self._lists for value in _list)
 
    def id16(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))
 
    def id8(self):
        
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
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, id15))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, id15))
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
 
def id14():
    return [s for s in input().split()]
 
def getStr():
    return input()
 
def listStr():
    return list(input())
def minVal(x, y) : 
    return x if (x < y) else y;  
  


def getMid(s, e) : 
    return s + (e - s) // 2;  
  

def id6( st, ss, se, qs, qe, index) : 
  
    
    
    
    if (qs <= ss and qe >= se) : 
        return st[index];  
  
    
    
    if (se < qs or ss > qe) : 
        return INT_MAX;  
  
    
    
    mid = getMid(ss, se);  
    return minVal(id6(st, ss, mid, qs,  
                          qe, 2 * index + 1),  
                  id6(st, mid + 1, se, 
                          qs, qe, 2 * index + 2));  
  



def RMQ( st, n, qs, qe) :  
  
    
    if (qs < 0 or qe > n - 1 or qs > qe) : 
      
        print("Invalid Input");  
        return -1;  
      
    return id6(st, 0, n - 1, qs, qe, 0);  
  



def id0(arr, ss, se, st, si) : 
  
    
    
    
    if (ss == se) : 
  
        st[si] = arr[ss];  
        return arr[ss];  
  
    
    
    
    mid = getMid(ss, se);  
    st[si] = minVal(id0(arr, ss, mid, 
                                    st, si * 2 + 1), 
                    id0(arr, mid + 1, se, 
                                    st, si * 2 + 2));  
      
    return st[si];  
  

def constructST( arr, n) : 
  
    
  
    
    x = (int)(ceil(log2(n)));  
  
    
    max_size = 2 * (int)(2**x) - 1;  
   
    st = [0] * (max_size);  
  
    
    id0(arr, 0, n - 1, st, 0);  
  
    
    return st;  
  
 
MOD = 10**9+7
mod=10**9+7

p=10**9+7
def id7():
    
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
    
id19=10000001


def sieve():
    d1={}
    d2=[0]*(id19)
    for i in range(1,id19):
        for j in range(i,id19,i):
            d2[j]+=i
        if d2[i]<id19 and d1.get(d2[i],-1)==-1:
            d1[d2[i]]=i
            
        
    
    return d1



def factor(x):
    d1={}
    x1=x
    while x!=1:
        d1[spf[x]]=d1.get(spf[x],0)+1
        x//=spf[x]
    
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


    
    
def solve(n,l,r,L):
    dl={}
    dr={}
    for i in range(l):
        dl[L[i]]=dl.get(L[i],0)+1
    for i in range(l,n):
        dr[L[i]]=dr.get(L[i],0)+1
    cnt=0
    n1=l
    for i in dr:
        mini=min(dr[i],dl.get(i,0))
        dr[i]-=mini
        if dl.get(i,-1)!=-1:
            dl[i]-=mini
        l-=mini
        r-=mini
    if l>r:
        l,r=r,l
        dl,dr=dr,dl
    rem=(r-l)//2
    ans=0
    
    for i in dr:
        mini=(r-l)
        mini=min(2*(dr[i]//2),mini)
        r-=mini
        ans+=(mini//2)
    return ans+(r+l)//2+(r-l)//2
    
    
        
        
        
for _ in range(t):
    
    n,l,r=map(int,input().split())
    
    
    L=list(map(int,input().split()))
    
    
    
    
    
    
    
    
    
    
    
    print(solve(n,l,r,L)) 
    
        