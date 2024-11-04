import sys
input = lambda: sys.stdin.buffer.readline().decode().strip()
from math import inf, gcd, lcm, log, log2, floor, ceil, sqrt
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from functools import lru_cache
from itertools import permutations, accumulate, groupby
from bisect import insort, bisect_left, bisect_right
import random
import threading


class DefaultDict:
    def __init__(self, default=None):
        self.default = default
        self.x = random.randrange(1, 1 << 31)
        self.dd = defaultdict(default)
    def __repr__(self):
        return "{"+", ".join(f"{k ^ self.x}: {v}" for k, v in self.dd.items())+"}"
    def __eq__(self, other):
        for k in set(self) | set(other):
            if self[k] != other[k]: return False
        return True
    def __or__(self, other):
        res = DefaultDict(self.default)
        for k, v in self.dd: res[k] = v
        for k, v in other.dd: res[k] = v
        return res
    def __len__(self):
        return len(self.dd)
    def __getitem__(self, item):
        return self.dd[item ^ self.x]
    def __setitem__(self, key, value):
        self.dd[key ^ self.x] = value
    def __delitem__(self, key):
        del self.dd[key ^ self.x]
    def __contains__(self, item):
        return item ^ self.x in self.dd
    def items(self):
        for k, v in self.dd.items(): yield (k ^ self.x, v)
    def keys(self):
        for k in self.dd: yield k ^ self.x
    def values(self):
        for v in self.dd.values(): yield v
    def __iter__(self):
        for k in self.dd: yield k ^ self.x
class CounterInt(DefaultDict):
    def __init__(self, aa=[]):
        super().__init__(int)
        for a in aa: self.dd[a ^ self.x] += 1
    def __add__(self, other):
        res = CounterInt()
        for k in set(self) | set(other):
            v = self[k]+other[k]
            if v > 0: res[k] = v
        return res
    def __sub__(self, other):
        res = CounterInt()
        for k in set(self) | set(other):
            v = self[k]-other[k]
            if v > 0: res[k] = v
        return res
    def __and__(self, other):
        res = CounterInt()
        for k in self:
            v = min(self[k], other[k])
            if v > 0: res[k] = v
        return res
    def __or__(self, other):
        res = CounterInt()
        for k in set(self) | set(other):
            v = max(self[k], other[k])
            if v > 0: res[k] = v
        return res
class Set:
    def __init__(self, aa=[]):
        self.x = random.randrange(1, 1 << 31)
        self.st = set()
        for a in aa: self.st.add(a ^ self.x)
    def __repr__(self):
        return "{"+", ".join(str(k ^ self.x) for k in self.st)+"}"
    def __len__(self):
        return len(self.st)
    def add(self, item):
        self.st.add(item ^ self.x)
    def discard(self, item):
        self.st.discard(item ^ self.x)
    def __contains__(self, item):
        return item ^ self.x in self.st
    def __iter__(self):
        for k in self.st: yield k ^ self.x
    def pop(self):
        return self.st.pop() ^ self.x
    def __or__(self, other):
        res = Set(self)
        for a in other: res.add(a)
        return res
    def __and__(self, other):
        res = Set()
        for a in self:
            if a in other: res.add(a)
        for a in other:
            if a in self: res.add(a)
        return res
    
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
 

class BIT:
    def __init__(self, size):
        self.bit = [0] * (size + 1)

    def getSum(self, idx):  
        s = 0
        while idx > 0:
            s += self.bit[idx]
            idx -= idx & (-idx)
        return s

    def getSumRange(self, left, right):  
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

def sumtoN(n):
    return ((n)*(n+1)) // 2

def powerOf2(n):
    return n > 0 and n & (n-1) == 0






def read_int(): return(int(input()))
def read_ints(): return(map(int,input().split()))
def read_list(): return(list(map(int,input().split())))
def read_matrix(m,n):
    ans = []
    for _ in range(m):
        ans.append(read_list())
    return ans


def solve(n,c,d,arr):
    
    
    arr.sort(reverse = True)
    
    
    mx = max(arr)
    sm = sum(arr)
    if mx >= c:
        return "Infinity"
    
    
        
    
    if mx * d < c:
        return "Impossible"
    
    def check(mid):
        
        mid += 1
        
        total = 0
        cycles, last_cy_size = d // mid, d % mid
        one_cy = sm
        if mid <= n:
            one_cy = sum(arr[:mid])
        total += one_cy * cycles
        last_cy = sm
        if last_cy_size <= n:
            last_cy = sum(arr[:last_cy_size])
        
        total += last_cy
        
        return total >= c
    
    
        

    l,r = 0, 10**18
    while l < r:
        mid = l+r >> 1
        if check(mid):
            l = mid+1
        else:
            r = mid
            
    if l == 10**18:
        if check(l):
            return "Infinity"
    if check(l):
        return l 
    
    return l-1
    
    
    
    
       
 
t = read_int()
for _ in range(t):
    
    n,c,d = read_ints()
    
    arr = read_list()
    print(solve(n,c,d,arr))
    
    
    
    
    
    




