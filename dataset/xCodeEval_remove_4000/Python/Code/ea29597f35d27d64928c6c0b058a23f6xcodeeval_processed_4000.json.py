import sys

from io import BytesIO, IOBase
import string


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        import os
        self.os = os
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
        self.BUFSIZE = 8192

    def read(self):
        while True:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, self.BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, self.BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            self.os.write(self._fd, self.buffer.getvalue())
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


def get_int():
    return int(input())


def id11():
    return list(map(int, input().split(' ')))


def id7(n):
    return [id11() for _ in range(n)]


def get_str():
    return input().strip()


def id12():
    return get_str().split(' ')


def flat_list(arr):
    return [item for subarr in arr for item in subarr]


def yes_no(b):
    if b:
        return "YES"
    else:
        return "NO"


def binary_search(good, left, right, delta=1, right_true=False):
    

    limits = [left, right]
    while limits[1] - limits[0] > delta:
        if delta == 1:
            mid = sum(limits) // 2
        else:
            mid = sum(limits) / 2
        if good(mid):
            limits[int(right_true)] = mid
        else:
            limits[int(~right_true)] = mid
    if good(limits[int(right_true)]):
        return limits[int(right_true)]
    else:
        return False


def id2(a):
    p = [0]
    for x in a:
        p.append(p[-1] + x)
    return p



def solve_b():
    n = get_int()
    s = list(get_str())
    if n == 1:
        return s[0] * 2
    if s[0] == s[1]:
        return s[:2]
    for i in range(1, n):
        if s[i] > s[i - 1]:
            return s[:i] + s[:i][::-1]
    return s + s[::-1]


def solve_c():
    n = get_int()
    a = id11()

    if n == 1:
        return 0

    best = float('inf')
    for i in range(n):
        for j in range(i + 1, n):
            cnt = 0
            for k in range(n):
                if (a[k] - a[i]) * (j - i) != (k - i) * (a[j] - a[i]):
                    cnt += 1
            best = min(best, cnt)
    return best


class id4:
    def __init__(self, arr, func=max):
        self.n = len(arr)
        
        
        self.log = [-float('inf'), 0]
        for i in range(2, self.n + 1):
            self.log.append(self.log[i // 2] + 1)
        
        self.m = 1 + self.log[-1]
        self.func = func
        self.sparse_table = [[-float('inf') for _ in range(self.m)] for _ in range(self.n)]
        for i in range(self.n):
            self.sparse_table[i][0] = arr[i]

        for j in range(1, self.m):
            for i in range(self.n - (1 << j) + 1):
                self.sparse_table[i][j] = self.func(self.sparse_table[i][j - 1], self.sparse_table[i + (1 << (j - 1))][j - 1])

    def query(self, l, r):
        
        k = self.log[r - l]
        return self.func(self.sparse_table[l][k], self.sparse_table[r - (1 << k)][k])


def solve_d():
    n = get_int()
    a = id11()
    x = get_int()

    b = [z - x for z in a]
    p = id2(b)
    ST = id4(p)
    prev = 0
    cnt = 0
    for i in range(1, n):
        s = p[i + 1]
        if i == prev:
            continue
        best = ST.query(prev, i)
        if best > s:
            cnt += 1
            prev = i + 1

    return n - cnt


class id16:
    

    def __init__(self, arr, merge=min, neutral=(25, 3 * 10 ** 5), singleton=lambda _: _):
        
        
        self.size = 1
        while self.size < len(arr):
            self.size *= 2
        
        self.merge = merge
        self.neutral = neutral
        self.singleton = singleton
        
        self.func_values = [self.neutral] * (2 * self.size - 1)
        
        for i in range(len(arr)):
            self.update(i, arr[i])

    def update(self, i, v):
        
        self._update(i, v, 0, 0, self.size)
        return

    def _update(self, i, v, x, lx, rx):
        
        if rx - lx == 1:
            
            self.func_values[x] = self.singleton(v)
            return
        else:
            
            m = (lx + rx) // 2
            if i < m:
                
                self._update(i, v, 2 * x + 1, lx, m)
            else:
                
                self._update(i, v, 2 * x + 2, m, rx)
            
            self.func_values[x] = self.merge(self.func_values[2 * x + 1], self.func_values[2 * x + 2])

    def query(self, l, r):
        
        return self._query(l, r, 0, 0, self.size)

    def _query(self, l, r, x, lx, rx):
        
        if lx >= r or l >= rx:
            
            return self.neutral
        elif lx >= l and rx <= r:
            
            return self.func_values[x]
        else:
            
            m = (lx + rx) // 2
            
            return self.merge(self._query(l, r, 2 * x + 1, lx, m), self._query(l, r, 2 * x + 2, m, rx))


class id8:
    def __init__(self, arr, func=min):
        self.n = len(arr)
        
        
        self.log = [-float('inf'), 0]
        for i in range(2, self.n + 1):
            self.log.append(self.log[i // 2] + 1)
        
        self.m = 1 + self.log[-1]
        self.func = func
        self.sparse_table = [[float('inf') for _ in range(self.m)] for _ in range(self.n)]
        for i in range(self.n):
            self.sparse_table[i][0] = arr[i]

        for j in range(1, self.m):
            for i in range(self.n - (1 << j) + 1):
                self.sparse_table[i][j] = self.func(self.sparse_table[i][j - 1], self.sparse_table[i + (1 << (j - 1))][j - 1])

    def query(self, l, r):
        
        k = self.log[r - l]
        return self.func(self.sparse_table[l][k], self.sparse_table[r - (1 << k)][k])



class SortedList:
    def __init__(self, iterable=[], _load=200):
        
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

    def id6(self, end):
        
        if self._rebuild:
            self.id0()

        id18 = self.id18
        x = 0
        while end:
            x += id18[end - 1]
            end &= end - 1
        return x

    def id5(self, k):
        
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

    def add(self, value):
        
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        id19 = self.id19

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
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
            _lists.append([value])
            _mins.append(value)
            id19.append(1)
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

    def id3(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id6(pos) + idx

    def id14(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id6(pos) + idx

    def count(self, value):
        
        return self.id14(value) - self.id3(value)

    def id21(self):
        
        return self._len

    def id15(self, index):
        
        pos, idx = self.id5(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id13(self, index):
        
        pos, idx = self.id5(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id10(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id20(self):
        
        return (value for _list in self._lists for value in _list)

    def id17(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id9(self):
        
        return 'SortedList({0})'.format(list(self))


def solve_e():
    n = get_int()
    s = get_str()
    t = get_str()

    
        

    alpha = {x: i for i, x in enumerate(string.ascii_lowercase)}

    SL = SortedList([])

    pos = [[] for _ in range(26)]
    for i, char in enumerate(s):
        pos[alpha[char]].append(i)

    for i in range(26):
        pos[i].append(float('inf'))
        pos[i] = pos[i][::-1]

    moves = 0
    bestmoves = float('inf')
    for j, char in enumerate(t):
        d = alpha[char]
        best = float('inf')
        for i in range(d):
            best = min(pos[i][-1], best)
        bestmoves = min(bestmoves, moves + best - j - SL.id14(best) + len(SL))
        k = pos[d].pop()
        SL.add(k)
        moves += k - j - SL.id14(k) + len(SL)
        if moves >= bestmoves:
            break
    if bestmoves == float('inf'):
        bestmoves = -1
    return bestmoves


t = get_int()
for _ in range(t):
    print(solve_e())
