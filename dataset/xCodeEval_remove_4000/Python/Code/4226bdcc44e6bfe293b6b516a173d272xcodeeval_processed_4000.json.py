import sys
import os
from io import BytesIO, IOBase
from math import floor
from random import randint


id15 = 8192
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
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
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id19 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id18 = []
        self._rebuild = True

    def id0(self):
        
        self.id18[:] = self.id19
        id18 = self.id18
        for i in range(len(id18)):
            if i | i + 1 < len(id18):
                id18[i | i + 1] += id18[i]
        self._rebuild = False

    def id1(self, index, value):
        
        if not self._rebuild:
            id18 = self.id18
            while index < len(id18):
                id18[index] += value
                index |= index + 1

    def id4(self, end):
        
        if self._rebuild:
            self.id0()

        id18 = self.id18
        x = 0
        while end:
            x += id18[end - 1]
            end &= end - 1
        return x

    def id3(self, k):
        
        id19 = self.id19
        if k < id19[0]:
            return 0, k
        if k >= self._len - id19[-1]:
            return len(id19) - 1, k + id19[-1] - self._len
        if self._rebuild:
            self.id0()

        id18 = self.id18
        idx = -1
        for d in reversed(range(len(id18).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id18) and k >= id18[right_idx]:
                idx = right_idx
                k -= id18[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id19 = self.id19

        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id19[pos] -= 1

        if id19[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id19[pos]
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

    def _prev_interval(self, pos, idx):
        _lists = self._lists
        if idx < 0 or pos < 0:
            raise ValueError("idx or pos < 0 ", (idx,pos))
        if idx > 0:
            return pos, idx - 1, _lists[pos][idx - 1]
        if pos > 0:
            last = self.id19[pos - 1] - 1
            return pos - 1, last, _lists[pos - 1][last]
        return -1, -1, None
    
    def _next_interval(self, pos, idx):
        _lists = self._lists
        id19 = self.id19
        if idx < 0 or pos < 0:
            raise ValueError("idx or pos < 0 ", (idx,pos))
        if idx < id19[pos] - 1:
            return pos, idx + 1, _lists[pos][idx + 1]
        if pos < len(_lists) - 1:
            return pos + 1, 0, _lists[pos + 1][0]
        return -1, -1, None

    def _insert(self, pos, idx, l, r):
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        id19 = self.id19
        
        if _lists:
            _list = _lists[pos]
            self.id1(pos, 1)
            _list.insert(idx, Interval(l, r))
            id19[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id19.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id19[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            itv = Interval(l, r)
            _lists.append([itv])
            _mins.append(itv)
            id19.append(1)
            self._rebuild = True
        
        self._len += 1

    def id5(self, position):
        pos, idx = self._loc_right(Interval(position, position))
        prev_pos, prev_idx, prev_itv = self._prev_interval(pos, idx)
        if prev_itv is not None:
            return prev_pos, prev_idx, prev_itv
        return -1, -1, None

    def id14(self, position):
        prev_pos, prev_idx, prev_itv = self.id5(position)
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
        id19 = self.id19

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
        id19 = self.id19

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
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id2(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id4(pos) + idx

    def id11(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id4(pos) + idx

    def count(self, value):
        
        return self.id11(value) - self.id2(value)

    def id21(self):
        
        return self._len

    def id12(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id10(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id9(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id20(self):
        
        return (value for _list in self._lists for value in _list)

    def id16(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id8(self):
        
        return '[' + ", ".join(str(itvl) for itvl in list(self)) + ']'


class Interval:
    def __init__(self, l, r):
        self.l = l
        self.r = r

    def id7(self):
        return "(" + str(self.l) + ", " +  str(self.r) + ")"
    
    def id8(self):
        return self.id7()
    
    def id6(self, other):
        return self.l == other.l and self.r == other.r
    
    def id17(self, other):
        return self.l < other.l
    
    def id13(self, other):
        return self.l <= other.l

def rem(il,val):
    pos,idx,itv = il.id14(val)
    if itv is not None and val >= itv.l:
        il.discard(floor(val), floor(val) + 1)
    else:
        left = itv.l
        il.add(floor(val),left)
        il.discard(left, left + 1)

def add(il,val):
    pos,idx,itv = il.id5(val)
    if itv is not None and val <= itv.r:
        right = itv.r
        il.discard(floor(val),right)
        il.add(right, right + 1)
    else:
        il.add(floor(val), floor(val) + 1)

def solve():
    
    res = []
    il = IntervalList()
    
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