import array
import bisect
import heapq
import json
import math
import collections
import random
import re
import sys
import copy
from functools import reduce
import decimal
from io import BytesIO, IOBase
import os
import itertools
import functools
from types import GeneratorType
import fractions
from typing import Tuple, List, Union
from queue import PriorityQueue


decimal.getcontext().rounding = decimal.ROUND_HALF_UP

graphDict = collections.defaultdict

queue = collections.deque

big_prime = 135771883649879




def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        to = f(*args, **kwargs)
        if stack:
            return to
        else:
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        return to
                    to = stack[-1].send(to)

    return wrappedfunc



class Graphs:
    def __init__(self):
        self.graph = graphDict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def id9(self, nodes, visited_nodes, colors, parity, level):
        global count
        if nodes == 1:
            colors[nodes] = -1
        else:
            if len(self.graph[nodes]) == 1 and parity % 2 == 0:
                if q == 1:
                    colors[nodes] = 1
                else:
                    colors[nodes] = -1
                    count += 1
            else:
                if parity % 2 == 0:
                    colors[nodes] = -1
                else:
                    colors[nodes] = 1
        visited_nodes.add(nodes)
        for neighbour in self.graph[nodes]:
            new_level = level + 1
            if neighbour not in visited_nodes:
                self.id9(neighbour, visited_nodes, colors, level - 1, new_level)

    def dfs(self, node):
        Visited = set()
        color = collections.defaultdict()
        self.id9(node, Visited, color, 0, 0)
        return color

    def bfs(self, node, f_node):
        count = float("inf")
        visited = set()
        level = 0
        if node not in visited:
            queue.append([node, level])
            visited.add(node)
        flag = 0
        while queue:
            parent = queue.popleft()
            if parent[0] == f_node:
                flag = 1
                count = min(count, parent[1])
            level = parent[1] + 1
            for item in self.graph[parent[0]]:
                if item not in visited:
                    queue.append([item, level])
                    visited.add(item)
        return count if flag else -1
        return False



class Tree:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def inorder(node, lis):
    if node:
        inorder(node.left, lis)
        lis.append(node.data)
        inorder(node.right, lis)
    return lis


def id13(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return root.data
    return id13(root.left) + id13(root.right)


def hight(root):
    if root is None:
        return -1
    if root.left is None and root.right is None:
        return 0
    return max(hight(root.left), hight(root.right)) + 1



class UnionFind():
    parents = []
    sizes = []
    count = 0

    def __init__(self, n):
        self.count = n
        self.parents = [i for i in range(n)]
        self.sizes = [1 for i in range(n)]

    def find(self, i):
        if self.parents[i] == i:
            return i
        else:
            self.parents[i] = self.find(self.parents[i])
            return self.parents[i]

    def unite(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i == root_j:
            return
        elif root_i < root_j:
            self.parents[root_j] = root_i
            self.sizes[root_i] += self.sizes[root_j]
        else:
            self.parents[root_i] = root_j
            self.sizes[root_j] += self.sizes[root_i]

    def same(self, i, j):
        return self.find(i) == self.find(j)

    def size(self, i):
        return self.sizes[self.find(i)]

    def group_count(self):
        return len(set(self.find(i) for i in range(self.count)))

    def answer(self, extra, p, q):
        dic = collections.Counter()
        for q in range(n):
            dic[self.find(q)] = self.size(q)
        hq = list(dic.values())
        heapq._heapify_max(hq)
        ans = -1
        for z in range(extra + 1):
            if hq:
                ans += heapq._heappop_max(hq)
            else:
                break
        return ans




def rounding(n):
    return int(decimal.Decimal(f'{n}').to_integral_value())


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0), [1]))


def p_sum(array):
    return list(itertools.accumulate(array))


def base_change(nn, bb):
    if nn == 0:
        return [0]
    digits = []
    while nn:
        digits.append(int(nn % bb))
        nn //= bb
    return digits[::-1]


def id10(a: int, b: int, c: int):
    d, x, y = id17(a, b)
    r = c // d
    return r * x, r * y


@bootstrap
def id17(a: int, b: int):
    if b == 0:
        d, x, y = a, 1, 0
    else:
        (d, p, q) = yield id17(b, a % b)
        x = q
        y = p - q * (a // b)

    yield d, x, y







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

    def readline(self, **kwargs):
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





def inp():
    return sys.stdin.readline().strip()


def id3(v_type):
    return map(v_type, inp().split())


def id6(v_type):
    return list(id3(v_type))


def interactive():
    return sys.stdout.flush()





def id11(limit):
    limitn = limit + 1
    primes = dict()
    for i in range(2, limitn): primes[i] = True

    for i in primes:
        factors = range(i, limitn, i)
        for f in factors[1:]:
            primes[f] = False
    return [i for i in primes if primes[i] == True]


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

    def id5(self, end):
        
        if self._rebuild:
            self.id0()

        id20 = self.id20
        x = 0
        while end:
            x += id20[end - 1]
            end &= end - 1
        return x

    def id4(self, k):
        
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
        
        pos, idx = self.id4(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id2(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id5(pos) + idx

    def id15(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id5(pos) + idx

    def count(self, value):
        
        return self.id15(value) - self.id2(value)

    def id12(self):
        
        return self._len

    def id16(self, index):
        
        pos, idx = self.id4(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id14(self, index):
        
        pos, idx = self.id4(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id8(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id22(self):
        
        return (value for _list in self._lists for value in _list)

    def id19(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id7(self):
        
        return 'SortedList({0})'.format(list(self))


def n_sum(x):
    return (x * (x + 1)) // 2



def div(q, w):
    return decimal.Decimal(q).__truediv__(decimal.Decimal(w))



def ks(case, value, is_arr=False):
    if is_arr:
        return fCase 




for _ in range(int(inp())):
    n, c = id3(str)
    s = list(inp())
    if c=="g":
        print(0)
        continue
    dic = collections.defaultdict(list)
    for i, item in enumerate(s):
        if item == c:
            dic[c].append(i)
    s.extend(s)
    for i, item in enumerate(s[dic[c][0] + 1:]):
        if item == "g":
            dic["g"].append(i+dic[c][0])
    n = len(dic["g"])
    ans = 0
    for item in dic[c]:
        temp = bisect.id2(dic["g"], item)
        ans = max(ans, dic["g"][temp] - item+1)
    print(ans)
