






import os
import sys
import math
import random
import threading
from copy import deepcopy
from io import BytesIO, IOBase
from types import GeneratorType
from functools import lru_cache, reduce
from bisect import id2, id12
from collections import Counter, defaultdict, deque
from itertools import accumulate, combinations, permutations
from heapq import nsmallest, nlargest, heapify, heappop, heappush
from typing import Generic, Iterable, Iterator, TypeVar, Union, List


def debug(func):
    def wrapper(*args, **kwargs):
        print('----------------')
        res = func(*args, **kwargs)
        print('----------------')
        return res

    return wrapper


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc


class SegTree:
    

    def id7(self, f1, f2, l, r, v=0):
        
        self.ans = f2(v, r - l)
        self.f1 = f1
        self.f2 = f2
        self.l = l  
        self.r = r  
        self.v = v  
        self.lazy_tag = 0  
        self.left = None  
        self.right = None  

    @property
    def mid_h(self):
        return (self.l + self.r) // 2

    def id10(self):
        midh = self.mid_h
        if not self.left and midh > self.l:
            self.left = SegTree(self.f1, self.f2, self.l, midh)
        if not self.right:
            self.right = SegTree(self.f1, self.f2, midh, self.r)

    def init_seg(self, M):
        
        m0 = M[0]
        self.lazy_tag = 0
        for a in M:
            if a != m0:
                break
        else:
            self.v = m0
            self.ans = self.f2(m0, len(M))
            return self.ans
        self.v = '
        midh = self.mid_h
        self.id10()
        self.ans = self.f1(self.left.init_seg(M[:midh - self.l]), self.right.init_seg(M[midh - self.l:]))
        return self.ans

    def cover_seg(self, l, r, v):
        
        if self.v == v or l >= self.r or r <= self.l:
            return self.ans
        if l <= self.l and r >= self.r:
            self.v = v
            self.lazy_tag = 0
            self.ans = self.f2(v, self.r - self.l)
            return self.ans
        self.id10()
        if self.v != '
            if self.left:
                self.left.v = self.v
                self.left.ans = self.f2(self.v, self.left.r - self.left.l)
            if self.right:
                self.right.v = self.v
                self.right.ans = self.f2(self.v, self.right.r - self.right.l)
            self.v = '
        
        self.ans = self.f1(self.left.cover_seg(l, r, v), self.right.cover_seg(l, r, v))
        return self.ans

    def inc_seg(self, l, r, v):
        
        if v == 0 or l >= self.r or r <= self.l:
            return self.ans
        
        if l <= self.l and r >= self.r:
            if self.v == '
                self.lazy_tag += v
            else:
                self.v += v
            self.ans += self.f2(v, self.r - self.l)
            return self.ans
        self.id10()
        if self.v != '
            self.left.v = self.v
            self.left.ans = self.f2(self.v, self.left.r - self.left.l)
            self.right.v = self.v
            self.right.ans = self.f2(self.v, self.right.r - self.right.l)
            self.v = '
        self.pushdown()
        self.ans = self.f1(self.left.inc_seg(l, r, v), self.right.inc_seg(l, r, v))
        return self.ans

    def inc_idx(self, idx, v):
        
        if v == 0 or idx >= self.r or idx < self.l:
            return self.ans
        if idx == self.l == self.r - 1:
            self.v += v
            self.ans += self.f2(v, 1)
            return self.ans
        self.id10()
        if self.v != '
            self.left.v = self.v
            self.left.ans = self.f2(self.v, self.left.r - self.left.l)
            self.right.v = self.v
            self.right.ans = self.f2(self.v, self.right.r - self.right.l)
            self.v = '
        self.pushdown()
        self.ans = self.f1(self.left.inc_idx(idx, v), self.right.inc_idx(idx, v))
        return self.ans

    def pushdown(self):
        if self.lazy_tag != 0:
            if self.left:
                if self.left.v != '
                    self.left.v += self.lazy_tag
                    self.left.lazy_tag = 0
                else:
                    self.left.lazy_tag += self.lazy_tag
                self.left.ans += self.f2(self.lazy_tag, self.left.r - self.left.l)
            if self.right:
                if self.right.v != '
                    self.right.v += self.lazy_tag
                    self.right.lazy_tag = 0
                else:
                    self.right.lazy_tag += self.lazy_tag
                self.right.ans += self.f2(self.lazy_tag, self.right.r - self.right.l)
            self.lazy_tag = 0

    def query(self, l, r):
        
        if l >= r: return 0
        if l <= self.l and r >= self.r:
            return self.ans
        if self.v != '
            return self.f2(self.v, min(self.r, r) - max(self.l, l))
        midh = self.mid_h
        anss = []
        if l < midh:
            anss.append(self.left.query(l, r))
        if r > midh:
            anss.append(self.right.query(l, r))
        return reduce(self.f1, anss)


class SortedList:
    def id7(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id18 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id17 = []
        self._rebuild = True

    def id0(self):
        
        self.id17[:] = self.id18
        id17 = self.id17
        for i in range(len(id17)):
            if i | i + 1 < len(id17):
                id17[i | i + 1] += id17[i]
        self._rebuild = False

    def id1(self, index, value):
        
        if not self._rebuild:
            id17 = self.id17
            while index < len(id17):
                id17[index] += value
                index |= index + 1

    def id4(self, end):
        
        if self._rebuild:
            self.id0()

        id17 = self.id17
        x = 0
        while end:
            x += id17[end - 1]
            end &= end - 1
        return x

    def id3(self, k):
        
        id18 = self.id18
        if k < id18[0]:
            return 0, k
        if k >= self._len - id18[-1]:
            return len(id18) - 1, k + id18[-1] - self._len
        if self._rebuild:
            self.id0()

        id17 = self.id17
        idx = -1
        for d in reversed(range(len(id17).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id17) and k >= id17[right_idx]:
                idx = right_idx
                k -= id17[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id18 = self.id18

        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id18[pos] -= 1

        if id18[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id18[pos]
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
        id18 = self.id18

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id18[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id18.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id18[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id18.append(1)
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
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id2(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id4(pos) + idx

    def id12(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id4(pos) + idx

    def count(self, value):
        
        return self.id12(value) - self.id2(value)

    def id20(self):
        
        return self._len

    def id13(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id11(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id9(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id19(self):
        
        return (value for _list in self._lists for value in _list)

    def id16(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id8(self):
        
        return 'SortedList({0})'.format(list(self))


T = TypeVar('T')


class SortedSet(Generic[T]):
    id14 = 50
    id5 = 170

    def _build(self, a=None) -> None:
        "Evenly divide `a` into buckets."
        if a is None: a = list(self)
        size = self.size = len(a)
        bucket_size = int(math.ceil(math.sqrt(size / self.id14)))
        self.a = [a[size * i // bucket_size: size * (i + 1) // bucket_size] for i in range(bucket_size)]

    def id7(self, a: Iterable[T] = []) -> None:
        "Make a new SortedSet from iterable. / O(N) if sorted and unique / O(N log N)"
        a = list(a)
        if not all(a[i] < a[i + 1] for i in range(len(a) - 1)):
            a = sorted(set(a))
        self._build(a)

    def id19(self) -> Iterator[T]:
        for i in self.a:
            for j in i: yield j

    def id16(self) -> Iterator[T]:
        for i in reversed(self.a):
            for j in reversed(i): yield j

    def id20(self) -> int:
        return self.size

    def id8(self) -> str:
        return "SortedSet" + str(self.a)

    def id6(self) -> str:
        s = str(list(self))
        return "{" + s[1: len(s) - 1] + "}"

    def _find_bucket(self, x: T) -> List[T]:
        "Find the bucket which should contain x. self must not be empty."
        for a in self.a:
            if x <= a[-1]: return a
        return a

    def id9(self, x: T) -> bool:
        if self.size == 0: return False
        a = self._find_bucket(x)
        i = id2(a, x)
        return i != len(a) and a[i] == x

    def add(self, x: T) -> bool:
        "Add an element and return True if added. / O(√N)"
        if self.size == 0:
            self.a = [[x]]
            self.size = 1
            return True
        a = self._find_bucket(x)
        i = id2(a, x)
        if i != len(a) and a[i] == x: return False
        a.insert(i, x)
        self.size += 1
        if len(a) > len(self.a) * self.id5:
            self._build()
        return True

    def discard(self, x: T) -> bool:
        "Remove an element and return True if removed. / O(√N)"
        if self.size == 0: return False
        a = self._find_bucket(x)
        i = id2(a, x)
        if i == len(a) or a[i] != x: return False
        a.pop(i)
        self.size -= 1
        if len(a) == 0: self._build()
        return True

    def lt(self, x: T) -> Union[T, None]:
        "Find the largest element < x, or None if it doesn't exist."
        for a in reversed(self.a):
            if a[0] < x:
                return a[id2(a, x) - 1]

    def le(self, x: T) -> Union[T, None]:
        "Find the largest element <= x, or None if it doesn't exist."
        for a in reversed(self.a):
            if a[0] <= x:
                return a[id12(a, x) - 1]

    def gt(self, x: T) -> Union[T, None]:
        "Find the smallest element > x, or None if it doesn't exist."
        for a in self.a:
            if a[-1] > x:
                return a[id12(a, x)]

    def ge(self, x: T) -> Union[T, None]:
        "Find the smallest element >= x, or None if it doesn't exist."
        for a in self.a:
            if a[-1] >= x:
                return a[id2(a, x)]

    def id13(self, x: int) -> T:
        "Return the x-th element, or IndexError if it doesn't exist."
        if x < 0: x += self.size
        if x < 0: raise IndexError
        for a in self.a:
            if x < len(a): return a[x]
            x -= len(a)
        raise IndexError

    def index(self, x: T) -> int:
        "Count the number of elements < x."
        ans = 0
        for a in self.a:
            if a[-1] >= x:
                return ans + id2(a, x)
            ans += len(a)
        return ans

    def index_right(self, x: T) -> int:
        "Count the number of elements <= x."
        ans = 0
        for a in self.a:
            if a[-1] > x:
                return ans + id12(a, x)
            ans += len(a)
        return ans


id15 = 4096


class FastIO(IOBase):
    newlines = 0

    def id7(self, file):
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
    def id7(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin = IOWrapper(sys.stdin)
sys.stdout = IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")


def I():
    return input()


def II():
    return int(input())


def MI():
    return map(int, input().split())


def LI():
    return list(input().split())


def LII():
    return list(map(int, input().split()))


def GMI():
    return map(lambda x: int(x) - 1, input().split())


def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))


def solve():
    n, p = LII()
    a = LII()
    aset = set(a)
    pivot = a[-1]
    
    flag = True
    cur = 0
    while cur < pivot:
        if cur not in aset:
            flag = False
            break
        cur += 1
    if flag: 
        
        maxn = p - 1
        while maxn > pivot and maxn in aset:
            maxn -= 1
        return print(maxn - pivot)
    else: 
        used = p - pivot
        addset = set() 
        addset.add(0)
        flag = True 
        for i in range(n - 2, -1, -1):
            if a[i] + 1 != p:
                flag = False
                addset.add(a[i] + 1)
                break
        
        if flag:
            addset.add(1)
        
        aset |= addset
        
        maxn = pivot - 1
        while maxn > 0 and maxn in aset:
            maxn -= 1
        
        return print(used + maxn)



if __name__ == '__main__':
    for _ in range(II()):
        solve()

