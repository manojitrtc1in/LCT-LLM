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
        self.id16 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id15 = []
        self._rebuild = True
 
    def id0(self):
        
        self.id15[:] = self.id16
        id15 = self.id15
        for i in range(len(id15)):
            if i | i + 1 < len(id15):
                id15[i | i + 1] += id15[i]
        self._rebuild = False
 
    def id1(self, index, value):
        
        if not self._rebuild:
            id15 = self.id15
            while index < len(id15):
                id15[index] += value
                index |= index + 1
 
    def id5(self, end):
        
        if self._rebuild:
            self.id0()
 
        id15 = self.id15
        x = 0
        while end:
            x += id15[end - 1]
            end &= end - 1
        return x
 
    def id4(self, k):
        
        id16 = self.id16
        if k < id16[0]:
            return 0, k
        if k >= self._len - id16[-1]:
            return len(id16) - 1, k + id16[-1] - self._len
        if self._rebuild:
            self.id0()
 
        id15 = self.id15
        idx = -1
        for d in reversed(range(len(id15).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id15) and k >= id15[right_idx]:
                idx = right_idx
                k -= id15[idx]
        return idx + 1, k
 
    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id16 = self.id16
 
        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id16[pos] -= 1
 
        if id16[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id16[pos]
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
        id16 = self.id16
 
        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id16[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id16.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id16[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id16.append(1)
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
 
    def id2(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id5(pos) + idx
 
    def id12(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id5(pos) + idx
 
    def count(self, value):
        
        return self.id12(value) - self.id2(value)
 
    def id19(self):
        
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
 
    def id18(self):
        
        return (value for _list in self._lists for value in _list)
 
    def id14(self):
        
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

def id10(limit):
    
    isPrime = [True]*(limit+1)
    isPrime[0] = isPrime[1] = False
    primes = []
    for i in range(2, limit+1):
        if not isPrime[i]:continue
        primes += [i]
        for j in range(i*i, limit+1, i):
            isPrime[j] = False
    return primes

def main():

    mod=1000000007
    
    
    
    starttime=datetime.datetime.now()
    if(os.path.exists('input.txt')):
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    
    
    
    def valid_graph(b,n,m):
        
        graph=[[] for v in range(n+1)]
        vis=[0]*(n+1)
        for i in range(n):
            graph[a[i]].append(b[i])
            graph[b[i]].append(a[i])
        connected_components=0
        
        def dfs(v):
            vis[v]=1
            for u in graph[v]:
                if not vis[u]:
                    dfs(u)
                
        for i in range(1,n+1):
            if not vis[i]:
                connected_components+=1
                dfs(i)
        
        if n-connected_components<=m:
            return True
        return False
            
    tc = ri()
    for _ in range(tc):
        n,m=ria()
        a=ria()
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        offsets={}
        for pos in range(1,n+1):
            
            
            
            
            
            offset = (n+pos-a[pos-1])%n
            offsets[offset]=offsets.get(offset,0)+1
        
        
        
        id3=[]
        for offset in offsets:
            if offsets[offset]>=n//3:
                id3.append(offset)
        
        
        valid_offsets=[]
        for offset in id3:
            
            id6=[0]*n
            for i in range(1,n+1):
                pos=(i+offset-1)%n
                id6[pos]=i
            
            if valid_graph(id6,n,m):
                valid_offsets.append(offset)
        print(len(valid_offsets),*sorted(valid_offsets))
                    
                
        
            


                

        
        
        
        
        
       
        
       

        
        

            
            
            
                
            

            
            
        
        
           
        
        
                 
                
        
        

        
        

        
        
        
            
        
        
            
                

            
            
                
            
            
            
            
        
        
       
         
        

        
        
                    
                        

                    
           
                     
            
        
                
        
        
            
        
        
        
        
        

    
        
        
        
                
                
        
        
        
    

        
        
        

        
                             
        
        
        
            
        
        
                     
        
        
                    
        
                     
                    
                    
                
                
                    
                
        
        
            
                   
        
                    

        
        
                
            
            
    
            
                        
        
    

        
    
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


class id17(io.IOBase):
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
    sys.stdin = id17()
    sys.stdout = id7()
    main()
    