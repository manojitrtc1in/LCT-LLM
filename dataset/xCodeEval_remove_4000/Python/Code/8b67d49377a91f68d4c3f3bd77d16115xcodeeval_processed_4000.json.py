
import os
import sys
import threading
from io import BytesIO, IOBase
import math
from heapq import heappop, heappush, heapify, heapreplace
from collections import defaultdict, deque, OrderedDict, Counter
from bisect import id4, id14
from functools import lru_cache



mod = 1000000007
mod1 = 998244353

alpha = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}


def read():
    sys.stdin  = open('input.txt', 'r')  
    sys.stdout = open('output.txt', 'w') 


def primeFactors(n):
    arr = []
    l = 0
    while n % 2 == 0:
        arr.append(2)
        l += 1
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            arr.append(i)
            l += 1
            n = n // i
    if n > 2:
        arr.append(n)
        l += 1
    return arr
    
def id16(n):
    s = set()
    while n % 2 == 0:
        s.add(2)
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            s.add(i)
            n = n // i
    if n > 2:
        s.add(n)
    return s
def sieve(n):
    res=[0 for i in range(n+1)]
    
    prime=[]
    for i in range(2,n+1):
        if not res[i]:
            
            prime.append(i)
            for j in range(1,n//i+1):
                res[i*j]=1
    return prime
def isPrime(n) : 
    if (n <= 1) : return False
    if (n <= 3) : return True
    if (n % 2 == 0 or n % 3 == 0) : return False
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
    return True
def id9(n):
    seen, ans = [0] * n, 0
    for num in range(2, n):
        if seen[num]: continue
        ans += 1
        seen[num*num:n:num] = [1] * ((n - 1) // num - num + 1)
    return ans
def gcd(x, y):
    return math.gcd(x, y)
def lcm(a,b):
    return (a // gcd(a,b))* b
def id12(n,k):
    
    res = (n >> (k + 1)) << k
    if ((n >> k) & 1):
        res += n & ((1 << k) - 1)
    return res
def popcount(x):
    x = x - ((x >> 1) & 0x55555555)
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f
    x = x + (x >> 8)
    x = x + (x >> 16)
    return x & 0x0000007f
def id5(x, y, p):    
    res = 1
    x = x % p
    if (x == 0) :
        return 0
    while (y > 0) :
        if ((y & 1) == 1) :
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res
def nCr(n, r, p):    
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
            p - 2, p)) % p
def id17(n):
    if (n % 2 == 0):
        return 2
    i = 3
    while(i * i <= n):
        if (n % i == 0):
            return i
        i += 2
    return n
def id3(n):
    def pf(n):
        dic = defaultdict(int)
        while n % 2 == 0:
            dic[2] += 1
            n = n // 2
        for i in range(3,int(math.sqrt(n))+1,2):
            while n % i== 0:
                dic[i] += 1
                n = n // i
        if n > 2:
            dic[n] += 1
        return dic
    p = pf(n)
    ans = 1
    for item in p:
        ans *= (p[item] + 1)
    return ans




def id2(x, spf):
    
    dic = defaultdict(int)
    while (x != 1):
        
        dic[spf[x]] += 1
        x = x // spf[x]
    
    return dic



class id7:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.num_sets -= 1
        self.parent[b] = a
        self.size[a] += self. size[b]
        return True

    def set_size(self, a):
        return self.size[self.find(a)]

    def id23(self):
        return self.num_sets



class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id21 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id20 = []
        self._rebuild = True

    def id0(self):
        
        self.id20[:] = self.id21
        id20 = self.id20
        for i in range(len(id20)):
            if i | i + 1 < len(id20):
                id20[i | i + 1] += id20[i]
        self._rebuild = False

    def id1(self, index, value):
        
        if not self._rebuild:
            id20 = self.id20
            while index < len(id20):
                id20[index] += value
                index |= index + 1

    def id8(self, end):
        
        if self._rebuild:
            self.id0()

        id20 = self.id20
        x = 0
        while end:
            x += id20[end - 1]
            end &= end - 1
        return x

    def id6(self, k):
        
        id21 = self.id21
        if k < id21[0]:
            return 0, k
        if k >= self._len - id21[-1]:
            return len(id21) - 1, k + id21[-1] - self._len
        if self._rebuild:
            self.id0()

        id20 = self.id20
        idx = -1
        for d in reversed(range(len(id20).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id20) and k >= id20[right_idx]:
                idx = right_idx
                k -= id20[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id21 = self.id21

        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id21[pos] -= 1

        if id21[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id21[pos]
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
        id21 = self.id21

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id21[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id21.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id21[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id21.append(1)
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
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id4(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id8(pos) + idx

    def id14(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id8(pos) + idx

    def count(self, value):
        
        return self.id14(value) - self.id4(value)

    def id23(self):
        
        return self._len

    def id15(self, index):
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id13(self, index):
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id11(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id22(self):
        
        return (value for _list in self._lists for value in _list)

    def id19(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id10(self):
        
        return 'SortedList({0})'.format(list(self))

def lis():
    return [int(i) for i in input().split()]

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = lis()

        s = set(arr)

        mn = [arr[0]]
        j = 1
        for i in range(1, n):
            if arr[i] == arr[i-1]:
                while j in s:
                    j += 1
                mn.append(j)
                j += 1
            else:
                mn.append(arr[i])

        sorted_list = SortedList()

        for i in range(1, n+1):
            if i not in s:
                sorted_list.add(i)

        curr = arr[0]
        for i in range(1, n):
            if arr[i] == curr:
                x = sorted_list.id4(curr)-1
                arr[i] = sorted_list[x]
                sorted_list.discard(arr[i])

            else:
                curr = arr[i]

        print(*mn)
        print(*arr)



id18 = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id18))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id18))
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





if __name__ == "__main__":
    
    main()