import sys
input=sys.stdin.readline





from collections import defaultdict,deque,Counter
from bisect import id3,id12
from heapq import heappush,heappop
from functools import lru_cache
from itertools import accumulate
import math

def dijkstra(roads):
    mod = 10**9+7 
    d = defaultdict(list)
    for u,v,w in roads:
        d[u].append((v,w))
        d[v].append((u,w))
    dist = [float('inf')]*n
    dist[0] = 0
    q = [(0,0)]
    while q:
        dis,u = heappop(q)
        if dis > dist[u]:
            continue
        for v,w in d[u]:
            if dist[u]+w < dist[v]:
                dist[v] = dist[u]+w
                heappush(q,(dist[v],v))
    return dist

class UnionFind:
    def __init__(self, n):
        self.n = n
        self.part = n
        self.parent = [x for x in range(n)]
        self.size = [1 for _ in range(n)]

    def Find(self, x: int) -> int:
        if self.parent[x] == x:
            return x
        return self.Find(self.parent[x])
    
    def Union(self, x: int, y: int) -> bool:
        root_x = self.Find(x)
        root_y = self.Find(y)
        if root_x == root_y:
            return False
        if self.size[root_x] > self.size[root_y]:
            root_x, root_y = root_y, root_x
        self.parent[root_x] = root_y
        self.size[root_y] += self.size[root_x]
        self.part -= 1
        return True

    def issame(self, x: int, y: int) -> bool:
        return self.Find(x) == self.Find(y)

    def id0(self, x: int) -> int:
        root_x = self.Find(x)
        return self.size[root_x]

class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id10 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id9 = []
        self._rebuild = True
 
    def id1(self):
        
        self.id9[:] = self.id10
        id9 = self.id9
        for i in range(len(id9)):
            if i | i + 1 < len(id9):
                id9[i | i + 1] += id9[i]
        self._rebuild = False
 
    def id2(self, index, value):
        
        if not self._rebuild:
            id9 = self.id9
            while index < len(id9):
                id9[index] += value
                index |= index + 1
 
    def id8(self, end):
        
        if self._rebuild:
            self.id1()
 
        id9 = self.id9
        x = 0
        while end:
            x += id9[end - 1]
            end &= end - 1
        return x
 
    def id6(self, k):
        
        id10 = self.id10
        if k < id10[0]:
            return 0, k
        if k >= self._len - id10[-1]:
            return len(id10) - 1, k + id10[-1] - self._len
        if self._rebuild:
            self.id1()
 
        id9 = self.id9
        idx = -1
        for d in reversed(range(len(id9).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id9) and k >= id9[right_idx]:
                idx = right_idx
                k -= id9[idx]
        return idx + 1, k
 
    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id10 = self.id10
 
        self._len -= 1
        self.id2(pos, -1)
        del _lists[pos][idx]
        id10[pos] -= 1
 
        if id10[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id10[pos]
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
        id10 = self.id10
 
        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id2(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id10[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id10.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id10[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id10.append(1)
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
 
    def id3(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id8(pos) + idx
 
    def id12(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id8(pos) + idx
 
    def count(self, value):
        
        return self.id12(value) - self.id3(value)
 
    def id4(self):
        
        return self._len
 
    def id13(self, index):
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        return self._lists[pos][idx]
 
    def id7(self, index):
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        self._delete(pos, idx)
 
    def id14(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False
 
    def id15(self):
        
        return (value for _list in self._lists for value in _list)
 
    def id5(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))
 
    def id11(self):
        
        return 'SortedList({0})'.format(list(self))










































    




































































def solve():
    
    
    n, k = list(map(int, input().split(' ')))
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input().split(' '))))
    posx = [0] * (n * n)
    posy = [0] * (n * n)
    for i in range(n):
        for j in range(n):
            grid[i][j] -= 1
            posx[grid[i][j]] = i
            posy[grid[i][j]] = j
    x, y = posx[n * n - 1], posy[n * n - 1]
    pp, pn ,np, nn = x + y, x - y, - x + y, - x - y
    ans = [['G'] * n for _ in range(n)]
    ans[x][y] = 'M'

    for i in range(n * n - 2, -1, -1):
        x, y = posx[i], posy[i]
        if (x + y - k <= pp and x - y - k <= pn and - x + y - k <= np and - x - y - k <= nn):
            pp = min(pp, x + y)
            pn = min(pn, x - y)
            np = min(np, - x + y)
            nn = min(nn, - x - y)
            ans[x][y] = 'M'
    for i in range(n):
        
        sys.stdout.write("".join(ans[i]) + "\n")
solve()
            


































        

