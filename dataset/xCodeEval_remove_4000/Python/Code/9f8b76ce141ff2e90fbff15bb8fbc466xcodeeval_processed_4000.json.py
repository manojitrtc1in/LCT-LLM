import sys
input = lambda: sys.stdin.buffer.readline().decode().strip()
from math import inf, gcd, log, log2, floor, ceil, sqrt
from collections import defaultdict, deque
from heapq import heappush, heappop, heapify
from functools import lru_cache
from itertools import permutations, accumulate
from bisect import insort, id4, id19
import random
import threading


class DefaultDict:
    def __init__(self, default=None):
        self.default = default
        self.x = random.randrange(1, 1 << 31)
        self.dd = defaultdict(default)
    def id11(self):
        return "{"+", ".join(f"{k ^ self.x}: {v}" for k, v in self.dd.items())+"}"
    def id10(self, other):
        for k in set(self) | set(other):
            if self[k] != other[k]: return False
        return True
    def id22(self, other):
        res = DefaultDict(self.default)
        for k, v in self.dd: res[k] = v
        for k, v in other.dd: res[k] = v
        return res
    def id28(self):
        return len(self.dd)
    def id20(self, item):
        return self.dd[item ^ self.x]
    def id14(self, key, value):
        self.dd[key ^ self.x] = value
    def id18(self, key):
        del self.dd[key ^ self.x]
    def id12(self, item):
        return item ^ self.x in self.dd
    def items(self):
        for k, v in self.dd.items(): yield (k ^ self.x, v)
    def keys(self):
        for k in self.dd: yield k ^ self.x
    def values(self):
        for v in self.dd.values(): yield v
    def id27(self):
        for k in self.dd: yield k ^ self.x
class Counter(DefaultDict):
    def __init__(self, aa=[]):
        super().__init__(int)
        for a in aa: self.dd[a ^ self.x] += 1
    def id3(self, other):
        res = Counter()
        for k in set(self) | set(other):
            v = self[k]+other[k]
            if v > 0: res[k] = v
        return res
    def id7(self, other):
        res = Counter()
        for k in set(self) | set(other):
            v = self[k]-other[k]
            if v > 0: res[k] = v
        return res
    def id15(self, other):
        res = Counter()
        for k in self:
            v = min(self[k], other[k])
            if v > 0: res[k] = v
        return res
    def id22(self, other):
        res = Counter()
        for k in set(self) | set(other):
            v = max(self[k], other[k])
            if v > 0: res[k] = v
        return res
class Set:
    def __init__(self, aa=[]):
        self.x = random.randrange(1, 1 << 31)
        self.st = set()
        for a in aa: self.st.add(a ^ self.x)
    def id11(self):
        return "{"+", ".join(str(k ^ self.x) for k in self.st)+"}"
    def id28(self):
        return len(self.st)
    def add(self, item):
        self.st.add(item ^ self.x)
    def discard(self, item):
        self.st.discard(item ^ self.x)
    def id12(self, item):
        return item ^ self.x in self.st
    def id27(self):
        for k in self.st: yield k ^ self.x
    def pop(self):
        return self.st.pop() ^ self.x
    def id22(self, other):
        res = Set(self)
        for a in other: res.add(a)
        return res
    def id15(self, other):
        res = Set()
        for a in self:
            if a in other: res.add(a)
        for a in other:
            if a in self: res.add(a)
        return res
    
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

    def id2(self, index, value):
        
        if not self._rebuild:
            id24 = self.id24
            while index < len(id24):
                id24[index] += value
                index |= index + 1

    def id8(self, end):
        
        if self._rebuild:
            self.id0()

        id24 = self.id24
        x = 0
        while end:
            x += id24[end - 1]
            end &= end - 1
        return x

    def id6(self, k):
        
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
        self.id2(pos, -1)
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
            self.id2(pos, 1)
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
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id4(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id8(pos) + idx

    def id19(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id8(pos) + idx

    def count(self, value):
        
        return self.id19(value) - self.id4(value)

    def id28(self):
        
        return self._len

    def id20(self, index):
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id18(self, index):
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id12(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id27(self):
        
        return (value for _list in self._lists for value in _list)

    def id23(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id11(self):
        
        return 'SortedList({0})'.format(list(self))
 

class BIT:
    def __init__(self, size):
        self.bit = [0] * (size + 1)

    def getSum(self, idx):  
        s = 0
        while idx > 0:
            s += self.bit[idx]
            idx -= idx & (-idx)
        return s

    def id21(self, left, right):  
        return self.getSum(right) - self.getSum(left - 1)

    def addValue(self, idx, val):  
        while idx < len(self.bit):
            self.bit[idx] += val
            idx += idx & (-idx)
            
class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.word = None

    def addWord(self, word):
        cur = self
        for c in word:
            cur = cur.children[c]
        cur.word = "*"
    

class UnionFind:
    def __init__(self, size):
        self.root = [i for i in range(size)]
        
        
        
        self.rank = [1] * size
        self.connected = size

    
    def find(self, x):
        if x == self.root[x]:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]

    
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.root[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.root[rootX] = rootY
            else:
                self.root[rootY] = rootX
                self.rank[rootX] += 1
            self.connected -= 1

    def connected(self, x, y):
        return self.find(x) == self.find(y)

    
def largestPrime(n):
    
    primes = set()
    
    if n == 1:
        return {1}
    
    while n % 2 == 0:
        primes.add(2)
        n //= 2

    for i in range(3, int(sqrt(n)) + 1, 2):
        while n % i == 0:
            primes.add(i)
            n //= i

    if n > 2:
        primes.add(n)
        
    return primes

def id26(n):
    return ((n)*(n+1)) // 2

def id1(n):
    return n > 0 and n & (n-1) == 0








def read_int(): return(int(input()))
def id9(): return(map(int,input().split()))
def read_list(): return(list(map(int,input().split())))
def read_matrix(m,n):
    ans = []
    for _ in range(m):
        ans.append(read_list())
    return ans

import logging
logging.basicConfig(level=logging.INFO) 


def log(*args):
    logging.debug(*args)

def solve(n,arr,queries):
    
    ans = 0
    for i in range(n-1):
        idx = i + 1
        if arr[i] != arr[i+1]:
            ans += idx * (n - idx)
            
    ans += (n * (n+1)) // 2
    
    for i, x in queries:
        i -= 1
        id5 = (i >= 0) and arr[i] == arr[i-1]
        id17 = (i < n-1) and arr[i] == arr[i+1]
        
        arr[i] = x
        id13 = (i >= 0) and arr[i] == arr[i-1]
        id16 = (i < n-1) and arr[i] == arr[i+1]
        
        i += 1
        log([id5, id17, id13, id16])
        if id5 == False and id13 == True:
            ans -= (i-1) * (n-(i-1))
        if id5 == True and id13 == False:
            ans += (i-1) * (n-(i-1))  
        if id17 == False and id16 == True:
            ans -= (i) * (n-i)
        if id17 == True and id16 == False:
            ans += (i) * (n-i)
            
        print(ans)
 
        

 
n,q = id9()
arr = read_list()
queries = []
for _ in range(q):
    queries.append(read_list())
solve(n,arr,queries)




    
    




