
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

class IterativeSegTree:
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
                index |= index + 1
 
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
 


def prime_factors(n):
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

def all_factors(n):
    i = 1
    ans = []
    while i < int(n**0.5) + 1:
        if n%i == 0 :
            ans.append(i)
            if n//i != i:
                ans.append(n//i)
        i+=1
    return ans

def sum_all_fac(n):
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

def number_of_divisor(n):
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

def get_factor_logn(num,n):
    d = {}
    while num[n] != 1:
       d[num[n]] = d.get(num[n],0)+1
       n //= num[n]
    return d



def main():
    d = {}
    for i in range(1,2*(10**5)+1):
        x,cur = i,0
        while x%2==0:
            cur+=1
            x//=2
        d[i] = cur
    for _ in range(mi()):
        n = mi()
        arr = LMI()
        cur = 0
        for i in arr:
            x = i
            while x%2==0:
                cur+=1
                x//=2
        if cur >= n: print(0);continue
        pos = 0
        temp = []
        for i in range(n,0,-1):
            pos += d[i]
            temp += [d[i]]
        if pos + cur < n : print(-1);continue

        temp.sort(reverse=True)
        ans = 0
        for i in temp:
            cur+=i
            ans +=1 
            if cur >=n:break
        print(ans)




 

 
BUFSIZE = 8192
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
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
