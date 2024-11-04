import sys
import math
import heapq
import bisect
from collections import Counter, defaultdict, deque
from io import BytesIO, IOBase
from types import GeneratorType
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


def id9():
    return list(map(int, input().split(' ')))


def id6(n):
    return [id9() for _ in range(n)]


def get_str():
    return input().strip()


def id10():
    return get_str().split(' ')


def yes_no(b):
    if b:
        return "YES"
    else:
        return "NO"


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


def solve_a():
    n = get_int()
    if n % 3 == 0:
        return n // 3, n // 3 + 1, n // 3 - 1
    elif n % 3 == 1:
        return n // 3, n // 3 + 2, n // 3 - 1
    else:
        return n // 3 + 1, n // 3 + 2, n // 3 - 1


def solve_b():
    n = get_int()
    a = id9()
    b = id9()
    d = 0
    for i in range(n):
        c = a[i] - b[i]
        if c < 0:
            return "NO"
        else:
            d = max(d, c)

    for i in range(n):
        if b[i] != max(0, a[i] - d):
            return "NO"
    return "YES"


def solve_c():
    n = get_int()
    s = id9()
    f = id9() + [0]

    ans = [None] * n
    for i in range(n):
        ans[i] = f[i] - max(s[i], f[i - 1])
    return ans


def solve_d():
    n, k = id9()
    cnt = [0]
    s = get_str()
    for i in range(n):
        if s[i] == 'B':
            cnt.append(cnt[-1] + 1)
        else:
            cnt.append(cnt[-1] + 0)
    best = float('inf')
    for i in range(k, n + 1):
        best = min(best, k - cnt[i] + cnt[i - k])
    return best


class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id17 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id16 = []
        self._rebuild = True

    def id0(self):
        
        self.id16[:] = self.id17
        id16 = self.id16
        for i in range(len(id16)):
            if i | i + 1 < len(id16):
                id16[i | i + 1] += id16[i]
        self._rebuild = False

    def id1(self, index, value):
        
        if not self._rebuild:
            id16 = self.id16
            while index < len(id16):
                id16[index] += value
                index |= index + 1

    def id5(self, end):
        
        if self._rebuild:
            self.id0()

        id16 = self.id16
        x = 0
        while end:
            x += id16[end - 1]
            end &= end - 1
        return x

    def id4(self, k):
        
        id17 = self.id17
        if k < id17[0]:
            return 0, k
        if k >= self._len - id17[-1]:
            return len(id17) - 1, k + id17[-1] - self._len
        if self._rebuild:
            self.id0()

        id16 = self.id16
        idx = -1
        for d in reversed(range(len(id16).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id16) and k >= id16[right_idx]:
                idx = right_idx
                k -= id16[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id17 = self.id17

        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id17[pos] -= 1

        if id17[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id17[pos]
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
        id17 = self.id17

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id17[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id17.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id17[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id17.append(1)
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

    def id3(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id5(pos) + idx

    def id12(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id5(pos) + idx

    def count(self, value):
        
        return self.id12(value) - self.id3(value)

    def id19(self):
        
        return self._len

    def id13(self, index):
        
        pos, idx = self.id4(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id11(self, index):
        
        pos, idx = self.id4(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id8(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id18(self):
        
        return (value for _list in self._lists for value in _list)

    def id15(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id7(self):
        
        return 'SortedList({0})'.format(list(self))


def solve_e():
    n, k = id9()
    a = id9()
    S = sum(a)
    w = 0
    SL = SortedList([x % k for x in a])
    while SL:
        z = SL.pop(0)
        j = SL.id3(k - z)
        j %= len(SL)
        y = SL.pop(j)
        w += (z + y) % k
    return S // k - w // k


def solve_f():
    n = get_int()
    s = get_str()
    p = id9()
    SL = SortedList(list(range(n)))
    ans = 1
    while SL:
        x = SL.pop(0)
        lst = [x]
        while p[x] - 1 != lst[0]:
            x = p[x] - 1
            SL.remove(x)
            lst.append(x)
        z = [s[x] for x in lst]
        for k in range(1, len(z) + 1):
            if len(z) % k:
                continue
            zn = [s[x] for x in lst[k:] + lst[:k]]
            if zn == z:
                break
        if k > 1:
            ans = (ans * k) // (math.gcd(ans, k))
    return ans


class id14:
    
    def __init__(self, arr):
        self.size = 1
        while self.size < len(arr):
            self.size <<= 1
        self.values = [0] * (2 * self.size - 1)
        for i in range(len(arr)):
            self.set(i, arr[i])

    def set(self, i, v):
        self._set(i, v, 0, 0, self.size)
        return

    def _set(self, i, v, x, lx, rx):
        if rx - lx == 1:
            self.values[x] = v
        else:
            m = (lx + rx) >> 1
            if i < m:
                self._set(i, v, 2 * x + 1, lx, m)
            else:
                self._set(i, v, 2 * x + 2, m, rx)
            self.values[x] = min(self.values[2 * x + 1], self.values[2 * x + 2])
        return

    def min(self, l, r):
        return self._min(l, r, 0, 0, self.size)

    def _min(self, l, r, x, lx, rx):
        if lx >= r or rx <= l:
            return float('inf')
        elif lx >= l and rx <= r:
            return self.values[x]
        else:
            m = (lx + rx) >> 1
            return min(self._min(l, r, x, lx, m), self._min(l, r, x, m, rx))


def solve_g():
    _ = get_str()
    n, m = id9()
    a = id9()
    start = 0
    end = 0
    SL = SortedList([])
    ST = id14(a)

    start = n - 1
    end = n - 1
    while start >= 0:
        print(start, end)
        while end >= 1 and a[end - 1] >= a[start]:
            end -= 1
        SL.add((end, start, a[start]))
        start = end - 1
        end = start
    print(SL)
    for _ in range(m):
        k, d = id9()
        k -= 1
        a[k] -= d
        ST.set(k, a[k])
        i = SL.id12((d + 1, -1, -1)) - 1
        start, end, speed = SL.pop(i)
        speedor = speed
        j = i
        while j > 0:
            startp, endp, speedp = SL.pop(j - 1)
            if speedp >= speed:
                start = startp
                j -= 1
            else:
                SL.add((startp, endp, speedp))
                break
        SL.add((start, i, speed))
        if i < end:
            SL.add((i + 1, end, speedor))
        print(SL)

        print(len(SL))


t = get_int()
for _ in range(t):
    print(solve_f())
