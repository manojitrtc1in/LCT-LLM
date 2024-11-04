import sys
import math
import heapq
import bisect
from collections import Counter
from collections import defaultdict
from io import BytesIO, IOBase
from itertools import permutations
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


def solve_a():
    n = get_int()
    a = get_ints()
    suf_mex = [0]
    SL = SortedList(list(range(n + 1)))

    for i in range(n - 1, - 1, -1):
        SL.discard(a[i])
        suf_mex.append(SL[0])

    suf_mex = suf_mex[::-1]

    ans = []
    j = 0
    SL2 = SortedList(list(range(suf_mex[j] + 1)))
    while i < n and j < n:
        SL2.discard(a[i])
        mex = SL2[0]
        if mex == suf_mex[j]:
            ans.append(mex)
            j = i + 1
            i = j
            if j < n:
                SL2 = SortedList(list(range(suf_mex[j] + 1)))
        else:
            i += 1

    return ans


def solve_b():
    n = get_int()

    s2 = set()
    s2b = set()
    s3 = set()

    ans = False

    for _ in range(n):
        s = get_str()
        if s == s[::-1]:
            ans = True

        elif len(s) == 2:
            if s[::-1] in s2:
                ans = True
            if s[::-1] in s2b:
                ans = True
            s2.add(s)

        elif len(s) == 3:
            if s[::-1] in s3:
                ans = True
            s3.add(s)
            if s[::-1][:-1] in s2:
                ans = True
            s2b.add(s[:-1])

    return ans


def solve_c():
    n = get_int()
    a = [get_ints() for _ in range(n)]
    cnts = [[0] * n for _ in range(n)]
    ans = 0
    for i in range(n):
        for j in range(n):

            change = True
            if i and cnts[i - 1][j]:
                change = False
            if change:
                ans ^= a[i][j]
                if i > 0:
                    cnts[i - 1][j] ^= 1
                if j > 0:
                    cnts[i][j - 1] ^= 1
                if i < n - 1:
                    cnts[i + 1][j] ^= 1
                if j < n - 1:
                    cnts[i][j + 1] ^= 1

    return ans





def solve_d():
    n, m, k = get_ints()
    M = 10 ** 9 + 7
    p = [[0 for _ in range(n - m + 1)] for __ in range(n + 1)]
    inv2 = pow(2, M - 2, M)

    for i in range(n + 1):
        p[i][0] = (k * i) % M

    for j in range(n - m + 1):
        p[0][j] = 0
    if n - m > 0:
        p[1][1] = 0
        for j in range(1, n - m + 1):
            for i in range(1, n + 1):
                A = p[i - 1][j]
                B = p[i - 1][j - 1]
                p[i][j] = ((A + B) * inv2) % M

    return p[n][n - m]


def inv_mod(a, M):
    '''
    Returns the inverse of a modulo M (prime), uses Fermat's Little Theorem.
    Time complexity: O(log M) - fast exponentiation
    Memory complexity: O(1)
    :param a: number to invert
    :param M: modulo base, must be prime
    :return: returns inverse of a modulo M
    '''
    return pow(a, M - 2, M)


def choices(n, M):
    '''
    Returns an array of binomial co-efficients (n choose k) modulo M, for k in {0, 1, ..., n}
    Time complexity: O(n log M)
    Memory complexity: O(n)
    :param n: upper index for the binomial co-efficients
    :param M: modulo base, usually (large) prime
    :return: array of kth binomial co-efficients, modulo M
    '''
    
    ret = [0] * (n + 1)
    ret[0] = 1
    
    for k in range(1, n + 1):
        ret[k] = (ret[k - 1] * (n - k + 1) * inv_mod(k, M)) % M
    
    return ret


def solve_d2():
    n, m, k = get_ints()
    M = 10 ** 9 + 7
    inv2 = pow(2, M - 2, M)
    p = defaultdict(int)
    for i in range(2):
        p[(i, 0)] = (k * i) % M

    for j in range(n - m + 1):
        p[(0, j)] = 0
    if n - m > 0:
        p[(1, 1)] = 0
        for j in range(n - m + 1):
            for i in range(2):
                A = p[(i - 1, j)]
                B = p[(i - 1, j - 1)]
                p[(i, j)] = ((A + B) * inv2) % M


    C = choices(n - 1, M)

    ans = 0

    for d in range(n - m):
        ans += p[(1, n - m - d)] * C[d]
        ans %= M

    ans *= pow(inv2, n - 2, M)
    ans %= M

    return ans


t = get_int()
for _ in range(t):
    print(solve_c())
