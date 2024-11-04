import sys
import os
from io import BytesIO, IOBase
from math import floor
from random import randint
import time


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

if sys.version_info[0] < 3:
    sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

file = sys.stdin
if os.environ.get('USER') == "loic":
    file = open("data.in")
    
line = lambda: file.readline().split()
ui = lambda: int(line()[0])
ti = lambda: map(int,line())
li = lambda: list(ti())




class IntervalList:
    def __init__(self, iterable=[], _load=5000):
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

    def _prev_interval(self, pos, idx):
        _lists = self._lists
        if idx < 0 or pos < 0:
            raise ValueError("idx or pos < 0 ", (idx,pos))
        if idx > 0:
            return pos, idx - 1, _lists[pos][idx - 1]
        if pos > 0:
            last = self._list_lens[pos - 1] - 1
            return pos - 1, last, _lists[pos - 1][last]
        return -1, -1, None
    
    def _next_interval(self, pos, idx):
        _lists = self._lists
        _list_lens = self._list_lens
        if idx < 0 or pos < 0:
            raise ValueError("idx or pos < 0 ", (idx,pos))
        if idx < _list_lens[pos] - 1:
            return pos, idx + 1, _lists[pos][idx + 1]
        if pos < len(_lists) - 1:
            return pos + 1, 0, _lists[pos + 1][0]
        return -1, -1, None

    def _insert(self, pos, idx, l, r):
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens
        
        if _lists:
            _list = _lists[pos]
            self._fen_update(pos, 1)
            _list.insert(idx, Interval(l, r))
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
            itv = Interval(l, r)
            _lists.append([itv])
            _mins.append(itv)
            _list_lens.append(1)
            self._rebuild = True
        
        self._len += 1

    def get_left_interval(self, position):
        pos, idx = self._loc_right(Interval(position, position))
        prev_pos, prev_idx, prev_itv = self._prev_interval(pos, idx)
        if prev_itv is not None:
            return prev_pos, prev_idx, prev_itv
        return -1, -1, None

    def get_right_interval(self, position):
        prev_pos, prev_idx, prev_itv = self.get_left_interval(position)
        if prev_itv is not None:
            if position <= prev_itv.r:
                return prev_pos, prev_idx, prev_itv
            else:
                return self._next_interval(prev_pos, prev_idx)
        if self._lists:
            return 0, 0, self._lists[0][0]
        return -1, -1, None

    def add(self, l, r):
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens

        if not _lists:
            self._insert(0, 0, l, r)
            
        pos, idx = self._loc_right(Interval(l,r))
        prev_pos, prev_idx, prev_itv = self._prev_interval(pos, idx)
        
        in_left = False
        if prev_itv is not None and l <= prev_itv.r:
            if r <= prev_itv.r:
                return
            in_left = True
        
        in_right = False
        rem = []

        nxt_pos,nxt_idx,nxt_itv = self._next_interval(prev_pos,prev_idx) if prev_itv is not None else (0, 0, self._lists[0][0])
        while nxt_itv is not None and r >= nxt_itv.r:
            rem.append((nxt_pos,nxt_idx))
            nxt_pos,nxt_idx,nxt_itv = self._next_interval(nxt_pos,nxt_idx)
        
        for rem_pos,rem_idx in reversed(rem):
            self._delete(rem_pos, rem_idx)
    
        if nxt_itv is not None and nxt_itv.l <= r:
            in_right = True
        
        if not in_left and not in_right:
            self._insert(pos, idx, l, r)
        elif in_left and not in_right:
            prev_itv.r = r
        elif not in_left and in_right:
            nxt_itv.l = l
        else:
            nxt_itv.l = prev_itv.l
            self._delete(prev_pos, prev_idx)

    def discard(self, l, r):
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens

        if _lists:
            pos, idx = self._loc_right(Interval(l,r))
            prev_pos, prev_idx, prev_itv = self._prev_interval(pos, idx)
            in_left = False
            in_right = False
            if prev_itv is not None:
                if prev_itv.l < l < prev_itv.r:
                    in_left = True
                if prev_itv.l < r < prev_itv.r:
                    in_right = True
            else:
                prev_pos, prev_idx, prev_itv = pos, idx, _lists[pos][idx]
            
            rem = []
            nxt_pos,nxt_idx,nxt_itv = prev_pos, prev_idx, prev_itv
            while nxt_itv is not None and nxt_itv.r <= r:
                if l <= nxt_itv.l:
                    rem.append((nxt_pos,nxt_idx))
                nxt_pos,nxt_idx,nxt_itv = self._next_interval(nxt_pos,nxt_idx)
            
            for rem_pos,rem_idx in reversed(rem):
                self._delete(rem_pos, rem_idx)
            
            if in_left and in_right:
                if l != r:
                    self._insert(pos, idx, r, prev_itv.r)
                    prev_itv.r = l
                return
            elif in_left:
                prev_itv.r = l
            
            if nxt_itv is not None and nxt_itv.l < r < nxt_itv.r:
                nxt_itv.l = r

    def pop(self, index=-1):
        """Remove and return value at `index` in sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def bisect_left(self, value):
        """Return the left most index to insert `value` in the sorted list
           Index == size if insertion is after last element"""
        pos, idx = self._loc_left(value)
        return self._fen_query(pos) + idx

    def bisect_right(self, value):
        """Return the right most index to insert `value` in the sorted list
           Index == size if insertion is after last element"""
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
        return '[' + ", ".join(str(itvl) for itvl in list(self)) + ']'


class Interval:
    def __init__(self, l, r):
        self.l = l
        self.r = r

    def __str__(self):
        return "(" + str(self.l) + ", " +  str(self.r) + ")"
    
    def __repr__(self):
        return self.__str__()
    
    def __eq__(self, other):
        return self.l == other.l and self.r == other.r
    
    def __lt__(self, other):
        return self.l < other.l
    
    def __le__(self, other):
        return self.l <= other.l

def rem(il,val):
    pos,idx,itv = il.get_right_interval(val)
    if itv is not None and val >= itv.l:
        il.discard(floor(val), floor(val) + 1)
    else:
        left = itv.l
        il.add(floor(val),left)
        il.discard(left, left + 1)

def add(il,val):
    pos,idx,itv = il.get_left_interval(val)
    if itv is not None and val <= itv.r:
        right = itv.r
        il.discard(floor(val),right)
        il.add(right, right + 1)
    else:
        il.add(floor(val), floor(val) + 1)

def solve():
    
    res = []
    il = IntervalList([], 1000)
    
    for val in A:
        add(il, val + 0.5)
    
    for _ in range(Q):
        idx, val = ti()
        idx -= 1
        
        rem(il, A[idx] + 0.5)
        A[idx] = val
        add(il, val + 0.5)
        
        res.append(il[-1].r - 1)
    
    
    return "\n".join(str(v) for v in res)

for test in range(1,1+1):
    N,Q = ti()
    A = li()
    
    print(solve())
    
file.close()