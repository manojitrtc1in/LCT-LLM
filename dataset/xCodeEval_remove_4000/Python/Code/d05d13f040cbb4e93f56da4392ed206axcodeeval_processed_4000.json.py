import sys
input = lambda: sys.stdin.buffer.readline().decode().strip()
from math import inf, gcd, log, log2, floor, ceil, sqrt
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from functools import lru_cache
from itertools import permutations, accumulate, groupby
from bisect import insort, id4, id17
import random
import threading


class DefaultDict:
    def __init__(self, default=None):
        self.default = default
        self.x = random.randrange(1, 1 << 31)
        self.dd = defaultdict(default)
    def id10(self):
        return "{"+", ".join(f"{k ^ self.x}: {v}" for k, v in self.dd.items())+"}"
    def id9(self, other):
        for k in set(self) | set(other):
            if self[k] != other[k]: return False
        return True
    def id20(self, other):
        res = DefaultDict(self.default)
        for k, v in self.dd: res[k] = v
        for k, v in other.dd: res[k] = v
        return res
    def id26(self):
        return len(self.dd)
    def id18(self, item):
        return self.dd[item ^ self.x]
    def id14(self, key, value):
        self.dd[key ^ self.x] = value
    def id16(self, key):
        del self.dd[key ^ self.x]
    def id11(self, item):
        return item ^ self.x in self.dd
    def items(self):
        for k, v in self.dd.items(): yield (k ^ self.x, v)
    def keys(self):
        for k in self.dd: yield k ^ self.x
    def values(self):
        for v in self.dd.values(): yield v
    def id25(self):
        for k in self.dd: yield k ^ self.x
class CounterInt(DefaultDict):
    def __init__(self, aa=[]):
        super().__init__(int)
        for a in aa: self.dd[a ^ self.x] += 1
    def id3(self, other):
        res = Counter()
        for k in set(self) | set(other):
            v = self[k]+other[k]
            if v > 0: res[k] = v
        return res
    def id6(self, other):
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
    def id20(self, other):
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
    def id10(self):
        return "{"+", ".join(str(k ^ self.x) for k in self.st)+"}"
    def id26(self):
        return len(self.st)
    def add(self, item):
        self.st.add(item ^ self.x)
    def discard(self, item):
        self.st.discard(item ^ self.x)
    def id11(self, item):
        return item ^ self.x in self.st
    def id25(self):
        for k in self.st: yield k ^ self.x
    def pop(self):
        return self.st.pop() ^ self.x
    def id20(self, other):
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
        self.id23 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id22 = []
        self._rebuild = True

    def id0(self):
        
        self.id22[:] = self.id23
        id22 = self.id22
        for i in range(len(id22)):
            if i | i + 1 < len(id22):
                id22[i | i + 1] += id22[i]
        self._rebuild = False

    def id2(self, index, value):
        
        if not self._rebuild:
            id22 = self.id22
            while index < len(id22):
                id22[index] += value
                index |= index + 1

    def id7(self, end):
        
        if self._rebuild:
            self.id0()

        id22 = self.id22
        x = 0
        while end:
            x += id22[end - 1]
            end &= end - 1
        return x

    def id5(self, k):
        
        id23 = self.id23
        if k < id23[0]:
            return 0, k
        if k >= self._len - id23[-1]:
            return len(id23) - 1, k + id23[-1] - self._len
        if self._rebuild:
            self.id0()

        id22 = self.id22
        idx = -1
        for d in reversed(range(len(id22).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id22) and k >= id22[right_idx]:
                idx = right_idx
                k -= id22[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id23 = self.id23

        self._len -= 1
        self.id2(pos, -1)
        del _lists[pos][idx]
        id23[pos] -= 1

        if id23[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id23[pos]
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
        id23 = self.id23

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id2(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id23[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id23.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id23[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id23.append(1)
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
        return self.id7(pos) + idx

    def id17(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id7(pos) + idx

    def count(self, value):
        
        return self.id17(value) - self.id4(value)

    def id26(self):
        
        return self._len

    def id18(self, index):
        
        pos, idx = self.id5(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id16(self, index):
        
        pos, idx = self.id5(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id11(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id25(self):
        
        return (value for _list in self._lists for value in _list)

    def id21(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id10(self):
        
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

    def id19(self, left, right):  
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

def id24(n):
    return ((n)*(n+1)) // 2

def id1(n):
    return n > 0 and n & (n-1) == 0






def read_int(): return(int(input()))
def id8(): return(map(int,input().split()))
def read_list(): return(list(map(int,input().split())))
def read_matrix(m,n):
    ans = []
    for _ in range(m):
        ans.append(read_list())
    return ans


def solve(old, mul):
    
    
    twos, fives = 0, 0
    div = old
    while div % 2 == 0:
        div //= 2
        twos += 1
    
    while div % 5 == 0:
        div //= 5
        fives += 1

    for i in range(31,-1,-1):
        id13 = max(twos, i)
        id12 = max(fives, i)
        p = 1
        if id13 > twos:
            p *= pow(2, id13-twos)
        if id12 > fives:
            p *= pow(5, id12-fives)
            
        if p <= mul:
            mx_div = mul // p
            return old * p * mx_div
        
            
    
    
    
    
       
 
t = read_int()
for _ in range(t):
    n,m = id8()
    print(solve(n,m))
    
    
    
    
    
    




