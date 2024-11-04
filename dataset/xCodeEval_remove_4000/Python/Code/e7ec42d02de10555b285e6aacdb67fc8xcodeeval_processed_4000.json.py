
import sys,os
import math
from random import *



if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')


 

from io import BytesIO, IOBase
from heapq import *
from bisect import *
from collections import *
from itertools import *



class SegTree:

    def __init__(self,arr,n):
        self.n = n
        self.size = 1
        while self.size<=n:
            self.size*=2
        self.ans = [0]*(2*self.size)
        self.build(arr,n)
    
    def builtUtil(self,arr, sl,sr,idx):
        if sl == sr:
            self.ans[idx] = arr[sl]
            return 
        mid = (sl+sr)//2
        self.builtUtil(arr,sl,mid,2*idx+1 )
        self.builtUtil(arr,mid+1,sr,2*idx+2 )
        self.ans[idx] = self.ans[2*idx+1] + self.ans[2*idx+2]
    
    def build(self,arr,n):
        self.builtUtil(arr,0,n-1,0)

    def sumUtil(self,sl,sr,l,r,idx):
        if r<sl or l>sr: return 0
        if l<=sl and sr<=r:
            return self.ans[idx]
        mid = (sl+sr)//2
        return self.sumUtil(sl,mid,l,r,2*idx+1) + self.sumUtil(mid+1,sr,l,r,2*idx+2)

    def sum(self,l,r):
        return self.sumUtil(0,self.n-1,l,r,0)
    

    def upUtil(self,sl,sr,idx,idx1,val):
        if idx1>sr or idx1<sl: return
        if sl == sr:
            self.ans[idx] = val
            return 
        mid = (sl+sr)//2
        self.upUtil(sl,mid,2*idx+1,idx1,val)
        self.upUtil(mid+1,sr,2*idx+2,idx1,val)
        self.ans[idx] = self.ans[2*idx+1] + self.ans[2*idx+2]
    
    def up(self,idx,val):
        self.upUtil(0,self.n-1,0,idx,val)

class id3:
    def __init__(self,arr):
        self.N = 10**5
        self.tree = [0]*(2*10**5)
        self.n  = len(arr)
        self.arr =arr
    
    def build(self):
        for i,j in enumerate(self.arr):
            self.tree[self.n+i] = j
        for i in range(self.n-1,0,-1):
            self.tree[i] = self.tree[i<<1] + self.tree[i<<1 | 1]

    def modify(self,idx,val):
        idx += self.n
        self.tree[idx] = val
        while idx>1:
            self.tree[idx>>1] = self.tree[idx] + self.tree[idx^1]
            idx>>=1
    
    def query(self,l,r):
        ans = 0
        l,r = l+self.n,r+self.n
        while l<r:
            if (l&1) : 
                ans+=self.tree[l]
                l+=1
            if (r&1) :
                r-=1
                ans += self.tree[r]
            l>>=1
            r>>=1
        return ans


class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id19 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id18 = []
        self._rebuild = True
 
    def id0(self):
        
        self.id18[:] = self.id19
        id18 = self.id18
        for i in range(len(id18)):
            if i | i + 1 < len(id18):
                id18[i | i + 1] += id18[i]
        self._rebuild = False
 
    def id2(self, index, value):
        
        if not self._rebuild:
            id18 = self.id18
            while index < len(id18):
                id18[index] += value
                index |= index + 1
 
    def id6(self, end):
        
        if self._rebuild:
            self.id0()
 
        id18 = self.id18
        x = 0
        while end:
            x += id18[end - 1]
            end &= end - 1
        return x
 
    def id5(self, k):
        
        id19 = self.id19
        if k < id19[0]:
            return 0, k
        if k >= self._len - id19[-1]:
            return len(id19) - 1, k + id19[-1] - self._len
        if self._rebuild:
            self.id0()
 
        id18 = self.id18
        idx = -1
        for d in reversed(range(len(id18).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id18) and k >= id18[right_idx]:
                idx = right_idx
                k -= id18[idx]
        return idx + 1, k
 
    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id19 = self.id19
 
        self._len -= 1
        self.id2(pos, -1)
        del _lists[pos][idx]
        id19[pos] -= 1
 
        if id19[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id19[pos]
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
        id19 = self.id19
 
        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id2(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id19[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id19.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id19[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id19.append(1)
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
 
    def id4(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id6(pos) + idx
 
    def id13(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id6(pos) + idx
 
    def count(self, value):
        
        return self.id13(value) - self.id4(value)
 
    def id21(self):
        
        return self._len
 
    def id14(self, index):
        
        pos, idx = self.id5(self._len + index if index < 0 else index)
        return self._lists[pos][idx]
 
    def id12(self, index):
        
        pos, idx = self.id5(self._len + index if index < 0 else index)
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
 


def id11(n):
    c,t = [],n
    for j in range(2,int(n**0.5)+1):
        if t%j == 0:
            c.append(j)
            while t%j == 0:
                t//=j
    if t>1:
        c.append(t)
    return c

def gcd(a,b):
    if b==0: return a
    return gcd(b,a%b)

def id10(n):
    i = 1
    ans = []
    while i < int(n**0.5) + 1:
        if n%i == 0 :
            ans.append(i)
            if n//i != i:
                ans.append(n//i)
        i+=1
    return ans

def id1(n):
    ans = 1
    p = 2
    while p < int(n**0.5) + 1:
        cnt = 0
        while n%p ==0 :
            n//=p
            cnt+=1
        ans *= ((p **cnt) - 1)//(p-1)
        p+=1
    return ans

def id7(n):
    ans = 1
    p = 2
    while p < int(n**0.5) + 1:
        cnt = 0
        while n%p == 0 :
            n//=p
            cnt+=1
        ans *= (cnt+1)
        p+=1
    if n>1:
        ans*=2
    return ans

def sieve(n):
    num = [i for i in range(n+1)]
    pr = [True]*(n+1)
    p = 2
    while p < int(n**0.5)+1:
        if pr[p]:
            for i in range(p*p,n+1,p):
                pr[i] = False
                num[i] = p
        p+=1
    return num

def ans_fl(fl):
    if fl: return "YES"
    else: return "NO"

def id17(num,n):
    d = {}
    while num[n] != 1:
       d[num[n]] = d.get(num[n],0)+1
       n //= num[n]
    return d


def main():
    for _ in range(mi()):
        n = mi()
        arr = LMI()
        tree = [[0,0] for i in range(2*n+1)]
        for i in range(n):
            tree[i+n] = [arr[i],arr[i]]
        fl = 1
        ans = 0
        for i in range(n-1,-1,-1):
            [a,b],[c,d] = tree[i<<1],tree[i<<1|1]
            if a>c:
                if a-1 ==d:
                    ans+=1
                    tree[i] = [ c,b ]
                else:
                    fl = 0
                    break
            else:
                if b+1 != c: 
                    fl = 0
                    break
                else:
                    tree[i] = [a,d]
        if fl: print(ans)
        else: print(-1)




 

 
id15 = 8192
 
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
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")


def mi():return int(input())
def MI():return (map(int,input().split()))
def LMI():return list(map(int,input().split()))



def outP(var): sys.stdout.write(str(var)+'\n')  

 
MOD=10**9+7
mod=998244353
dir4 = [(1,0),(0,1),(-1,0),(0,-1)]
dir8 = [(0,1),(-1,1),(-1,0),(-1,-1),(0,-1),(1,-1),(1,0),(1,1)]

 
if __name__ == '__main__':  
    
    main()
