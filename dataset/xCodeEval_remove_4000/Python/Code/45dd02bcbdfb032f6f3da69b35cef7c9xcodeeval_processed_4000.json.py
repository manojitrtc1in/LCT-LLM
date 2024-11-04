import sys
from math import gcd,sqrt,ceil,log2
from collections import defaultdict,Counter,deque
from bisect import id2,id9
import math
sys.setrecursionlimit(2*10**5+10)
import heapq
from itertools import permutations







import os
import sys
from io import BytesIO, IOBase

id12 = 8192

aa='abcdefghijklmnopqrstuvwxyz'
class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id12))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id12))
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




def get_sum(bit,i):
    s = 0

    i+=1
    while i>0:
        s+=bit[i]
        i-=i&(-i)

    return s

def update(bit,n,i,v):
    i+=1

    while i<=n:
        bit[i]+=v
        i+=i&(-i)


def modInverse(b,m):
    g = math.gcd(b, m)
    if (g != 1):
        return -1
    else:
        return pow(b, m - 2, m)

def primeFactors(n):

    sa = []
    
    while n % 2 == 0:
        sa.append(2)
        n = n // 2


    for i in range(3,int(math.sqrt(n))+1,2):


        while n % i== 0:
            sa.append(i)
            n = n // i

    
    if n > 2:
        sa.append(n)
    return sa


def seive(n):

    pri = [True]*(n+1)
    p = 2
    while p*p<=n:

        if pri[p] == True:

            for i in range(p*p,n+1,p):
                pri[i] = False

        p+=1

    return pri

def id11(n):

    if n<0:
        return False
    for i in range(2,int(sqrt(n))+1):
        if n%i == 0:
            return False

    return True


def id3(string, z):
    n = len(string)

    
    
    l, r, k = 0, 0, 0
    for i in range(1, n):

        
        
        if i > r:
            l, r = i, i

            
            
            
            
            
            while r < n and string[r - l] == string[r]:
                r += 1
            z[i] = r - l
            r -= 1
        else:

            
            
            k = i - l

            
            
            
            
            if z[k] < r - i + 1:
                z[i] = z[k]

                
            
            else:

                
                l = i
                while r < n and string[r - l] == string[r]:
                    r += 1
                z[i] = r - l
                r -= 1

def search(text, pattern):

    
    concat = pattern + "$" + text
    l = len(concat)


    z = [0] * l
    id3(concat, z)

    ha = []
    for i in range(l):


        if z[i] == len(pattern):
            ha.append(i - len(pattern) - 1)


    return ha









































































def mergeIntervals(arr):

    
    
    arr.sort(key = lambda x: x[0])

    
    m = []
    s = -10000
    max = -100000
    for i in range(len(arr)):
        a = arr[i]
        if a[0] > max:
            if i != 0:
                m.append([s,max])
            max = a[1]
            s = a[0]
        else:
            if a[1] >= max:
                max = a[1]

    
    
    
    

    if max != -100000 and [s, max] not in m:
        m.append([s, max])
    return m
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

    def id9(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id5(pos) + idx

    def count(self, value):
        
        return self.id9(value) - self.id2(value)

    def id18(self):
        
        return self._len

    def id10(self, index):
        
        pos, idx = self.id4(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id8(self, index):
        
        pos, idx = self.id4(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id7(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id17(self):
        
        return (value for _list in self._lists for value in _list)

    def id13(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id6(self):
        
        return 'SortedList({0})'.format(list(self))

def ncr(n, r, p):

    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p


def sol(n):

    seti = set()
    for i in range(1,int(sqrt(n))+1):
        if n%i == 0:
            seti.add(n//i)
            seti.add(i)


    return seti
def lcm(a,b):

    return (a*b)//gcd(a,b)










































def id14(l):

    count1 = 0
    count2 = 0
    first = 10**18
    second = 10**18
    n = len(l)
    for i in range(n):

        if l[i] == first:
            count1+=1
        elif l[i] == second:
            count2+=1

        elif count1 == 0:
            count1+=1
            first = l[i]

        elif count2 == 0:
            count2+=1
            second = l[i]
        else:
            count1-=1
            count2-=1

    for i in range(n):
        if l[i] == first:
            count1+=1
        elif l[i] == second:
            count2+=1
    if count1>n//3:
        return first
    if count2>n//3:
        return second

    return -1


n = int(input())
l = list(map(int,input().split()))
dp = [10**18]*(n)

for i in range(n):
    if i == 0:
        dp[i] = 1
    else:
        if l[i]>=l[i-1]:
            dp[i] = min(l[i],dp[i-1]+1,dp[i])
        else:
            dp[i] = min(l[i],dp[i],dp[i-1]+1)

l.reverse()
dp.reverse()
for i in range(n):
    if i == 0:
        dp[i] = 1
    else:
        if l[i]>=l[i-1]:
            dp[i] = min(l[i],dp[i-1]+1,dp[i])
        else:
            dp[i] = min(l[i],dp[i],dp[i-1]+1)

print(max(dp))
    




