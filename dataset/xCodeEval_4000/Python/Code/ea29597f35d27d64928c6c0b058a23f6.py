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


def get_ints():
    return list(map(int, input().split(' ')))


def get_int_grid(n):
    return [get_ints() for _ in range(n)]


def get_str():
    return input().strip()


def get_strs():
    return get_str().split(' ')


def flat_list(arr):
    return [item for subarr in arr for item in subarr]


def yes_no(b):
    if b:
        return "YES"
    else:
        return "NO"


def binary_search(good, left, right, delta=1, right_true=False):
    """
    Performs binary search
    ----------
    Parameters
    ----------
    :param good: Function used to perform the binary search
    :param left: Starting value of left limit
    :param right: Starting value of the right limit
    :param delta: Margin of error, defaults value of 1 for integer binary search
    :param right_true: Boolean, for whether the right limit is the true invariant
    :return: Returns the most extremal value interval [left, right] which is good function evaluates to True,
            alternatively returns False if no such value found
    """

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


def prefix_sums(a):
    p = [0]
    for x in a:
        p.append(p[-1] + x)
    return p

'''
def solve_a():
    n = get_int()
    a = get_ints()

    d = defaultdict(int)
    for x in a:
        d[abs(x)] += 1

    S = 0
    for k, v in d.items():
        if k:
            S += min(2, v)
        else:
            S += min(1, v)

    return S
'''

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
    a = get_ints()

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


class SparseTableIdempotent:
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
    a = get_ints()
    x = get_int()

    b = [z - x for z in a]
    p = prefix_sums(b)
    ST = SparseTableIdempotent(p)
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


class SegmentTreeGeneral:
    """
    General segment tree data structure for performing range (associative) function queries on a mutable array
    """

    def __init__(self, arr, merge=min, neutral=(25, 3 * 10 ** 5), singleton=lambda _: _):
        """
        Initialises the object.
        Time Complexity: O(N log N)
        ----------
        Parameters
        ----------
        :param arr: array used to initialise the segment tree
        :param merge: function used for range queries, must be associative
        :param neutral: invariant of the function used for range queries
        """
        
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
        """
        Recursively, updates the segment tree based on changing the value of one of the elements of the underlying array.
        Uses helper function _assign for the recursion.
        Time complexity: O(log N)
        ----------
        Parameters
        ----------
        :param i: index of the element to update
        :param v: 1601-1700 value for the element to update
        :return: None
        """
        self._update(i, v, 0, 0, self.size)
        return

    def _update(self, i, v, x, lx, rx):
        """
        Helper function, updates the value of the segment tree values on the intersection of two intervals.
        In particular the intersection of [l, r) and [lx, rx), where [lx, rx) is always one of the segment tree ranges.
        ----------
        Parameters
        ----------
        :param i: array index to update
        :param v: 1601-1700 array value for update
        :param x: current index on the segment tree
        :param lx: current left side of range represented by x
        :param rx: current right side of range represented by x
        :return: None
        """
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
        """
        Recursively, returns the range-function-query
        Uses helper function _query for the recursion.
        Time complexity: O(log N)
        ----------
        Parameters
        ----------
        :param l: start index of the range query (inclusive)
        :param r: end index of the range query (exclusive)
        :return: value of the function on the range [l, r)
        """
        return self._query(l, r, 0, 0, self.size)

    def _query(self, l, r, x, lx, rx):
        """
        Helper function, returns the value of the range-function-query on the intersection of two intervals.
        In particular the intersection of [l, r) and [lx, rx), where [lx, rx) is always one of the pre-computed ranges.
        ----------
        Parameters
        ----------
        :param l: start index of original query range
        :param r: end index of original query range
        :param x: current index on the segment tree
        :param lx: current left side of range represented by x
        :param rx: current right side of range represented by x
        :return: segment tree on intersection between [l, r) and [lx, rx)
        """
        if lx >= r or l >= rx:
            
            return self.neutral
        elif lx >= l and rx <= r:
            
            return self.func_values[x]
        else:
            
            m = (lx + rx) // 2
            
            return self.merge(self._query(l, r, 2 * x + 1, lx, m), self._query(l, r, 2 * x + 2, m, rx))


class SparseTableMin:
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
        bestmoves = min(bestmoves, moves + best - j - SL.bisect_right(best) + len(SL))
        k = pos[d].pop()
        SL.add(k)
        moves += k - j - SL.bisect_right(k) + len(SL)
        if moves >= bestmoves:
            break
    if bestmoves == float('inf'):
        bestmoves = -1
    return bestmoves


t = get_int()
for _ in range(t):
    print(solve_e())
