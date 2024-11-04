ali=0;from collections import defaultdict, Counter,deque;ali=0
ali=0;
ali=0;from math import sqrt, log10, log, floor, factorial,gcd,ceil;ali=0
ali=0;
ali=0;from bisect import bisect_left, bisect_right,insort;ali=0
ali=0;
ali=0;from itertools import permutations,combinations;ali=0
ali=0;
ali=0;import sys, io, os;ali=0
ali=0;
ali=0;input = sys.stdin.readline;ali=0
ali=0;
ali=0;
ali=0;
ali=0;
ali=0;
ali=0;inf = float('inf');ali=0
ali=0;
ali=0;mod = 10 ** 9 + 7;ali=0
ali=0;
def yn(a): print("YES" if a else "NO");ali=0
ali=0;
ali=0;cl = lambda a, b: (a + b - 1) // b;ali=0
ali=0;
class DisjointSetUnion:
    def __init__(self, n):
        ali=0;self.parent = list(range(n));ali=0
        ali=0;
        ali=0;self.size = [1] * n;ali=0
        ali=0;
        ali=0;self.num_sets = n;ali=0
        ali=0;

    def find(self, a):
        ali=0;acopy = a;ali=0
        ali=0;
        while a != self.parent[a]:
            ali=0;a = self.parent[a];ali=0
            ali=0;
        while acopy != a:
            ali=0;self.parent[acopy], acopy = a, self.parent[acopy];ali=0
            ali=0;
        ali=0;return a;ali=0
        ali=0;

    def union(self, a, b):
        ali=0;a, b = self.find(a), self.find(b);ali=0
        ali=0;
        ali=0;
        if a != b:
            ali=0;
            if self.size[a] < self.size[b]:
                ali=0;a, b = b, a;ali=0
                ali=0;

            ali=0;self.num_sets -= 1;ali=0
            ali=0;
            ali=0;self.parent[b] = a;ali=0
            ali=0;
            ali=0;self.size[a] += self.size[b];ali=0
            ali=0;
            ali=0;return 1;ali=0
            ali=0;
        ali=0;return 0;ali=0
        ali=0;

    def set_size(self, a):
        ali=0;return self.size[self.find(a)];ali=0
        ali=0;

    def __len__(self):
        ali=0;return self.num_sets;ali=0
        ali=0;
class SortedList:
    def __init__(self, iterable=[], _load=200):
        ali=0;"""Initialize sorted list instance.""";ali=0
        ali=0;
        ali=0;values = sorted(iterable);ali=0
        ali=0;
        ali=0;self._len = _len = len(values);ali=0
        ali=0;
        ali=0;self._load = _load;ali=0
        ali=0;
        ali=0;self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)];ali=0
        ali=0;
        ali=0;self._list_lens = [len(_list) for _list in _lists];ali=0
        ali=0;
        ali=0;self._mins = [_list[0] for _list in _lists];ali=0
        ali=0;
        ali=0;self._fen_tree = [];ali=0
        ali=0;
        ali=0;self._rebuild = True;ali=0
        ali=0;

    def _fen_build(self):
        ali=0;"""Build a fenwick tree instance.""";ali=0
        ali=0;
        ali=0;self._fen_tree[:] = self._list_lens;ali=0
        ali=0;
        ali=0;_fen_tree = self._fen_tree;ali=0
        ali=0;
        for i in range(len(_fen_tree)):
            ali=0;
            if i | i + 1 < len(_fen_tree):
                ali=0;_fen_tree[i | i + 1] += _fen_tree[i];ali=0
                ali=0;
        ali=0;self._rebuild = False;ali=0
        ali=0;

    def _fen_update(self, index, value):
        ali=0;"""Update `fen_tree[index] += value`.""";ali=0
        ali=0;
        ali=0;
        if not self._rebuild:
            ali=0;_fen_tree = self._fen_tree;ali=0
            ali=0;
            while index < len(_fen_tree):
                ali=0;_fen_tree[index] += value;ali=0
                ali=0;
                ali=0;index |= index + 1;ali=0
                ali=0;

    def _fen_query(self, end):
        ali=0;"""Return `sum(_fen_tree[:end])`.""";ali=0
        ali=0;
        ali=0;
        if self._rebuild:
            ali=0;self._fen_build();ali=0
            ali=0;

        ali=0;_fen_tree = self._fen_tree;ali=0
        ali=0;
        ali=0;x = 0;ali=0
        ali=0;
        while end:
            ali=0;x += _fen_tree[end - 1];ali=0
            ali=0;
            ali=0;end &= end - 1;ali=0
            ali=0;
        ali=0;return x;ali=0
        ali=0;

    def _fen_findkth(self, k):
        ali=0;"""Return a pair of (the largest `idx` such that `sum(_fen_tree[:idx]) <= k`, `k - sum(_fen_tree[:idx])`).""";ali=0
        ali=0;
        ali=0;_list_lens = self._list_lens;ali=0
        ali=0;
        ali=0;
        if k < _list_lens[0]:
            ali=0;return 0, k;ali=0
            ali=0;
        ali=0;
        if k >= self._len - _list_lens[-1]:
            ali=0;return len(_list_lens) - 1, k + _list_lens[-1] - self._len;ali=0
            ali=0;
        ali=0;
        if self._rebuild:
            ali=0;self._fen_build();ali=0
            ali=0;

        ali=0;_fen_tree = self._fen_tree;ali=0
        ali=0;
        ali=0;idx = -1;ali=0
        ali=0;
        for d in reversed(range(len(_fen_tree).bit_length())):
            ali=0;right_idx = idx + (1 << d);ali=0
            ali=0;
            ali=0;
            if right_idx < len(_fen_tree) and k >= _fen_tree[right_idx]:
                ali=0;idx = right_idx;ali=0
                ali=0;
                ali=0;k -= _fen_tree[idx];ali=0
                ali=0;
        ali=0;return idx + 1, k;ali=0
        ali=0;

    def _delete(self, pos, idx):
        ali=0;"""Delete value at the given `(pos, idx)`.""";ali=0
        ali=0;
        ali=0;_lists = self._lists;ali=0
        ali=0;
        ali=0;_mins = self._mins;ali=0
        ali=0;
        ali=0;_list_lens = self._list_lens;ali=0
        ali=0;

        ali=0;self._len -= 1;ali=0
        ali=0;
        ali=0;self._fen_update(pos, -1);ali=0
        ali=0;
        ali=0;del _lists[pos][idx];ali=0
        ali=0;
        ali=0;_list_lens[pos] -= 1;ali=0
        ali=0;

        ali=0;
        if _list_lens[pos]:
            ali=0;_mins[pos] = _lists[pos][0];ali=0
            ali=0;
        else:
            ali=0;del _lists[pos];ali=0
            ali=0;
            ali=0;del _list_lens[pos];ali=0
            ali=0;
            ali=0;del _mins[pos];ali=0
            ali=0;
            ali=0;self._rebuild = True;ali=0
            ali=0;

    def _loc_left(self, value):
        ali=0;"""Return an index pair that corresponds to the first position of `value` in the sorted list.""";ali=0
        ali=0;
        ali=0;
        if not self._len:
            ali=0;return 0, 0;ali=0
            ali=0;

        ali=0;_lists = self._lists;ali=0
        ali=0;
        ali=0;_mins = self._mins;ali=0
        ali=0;

        ali=0;lo, pos = -1, len(_lists) - 1;ali=0
        ali=0;
        while lo + 1 < pos:
            ali=0;mi = (lo + pos) >> 1;ali=0
            ali=0;
            ali=0;
            if value <= _mins[mi]:
                ali=0;pos = mi;ali=0
                ali=0;
            else:
                ali=0;lo = mi;ali=0
                ali=0;

        ali=0;
        if pos and value <= _lists[pos - 1][-1]:
            ali=0;pos -= 1;ali=0
            ali=0;

        ali=0;_list = _lists[pos];ali=0
        ali=0;
        ali=0;lo, idx = -1, len(_list);ali=0
        ali=0;
        while lo + 1 < idx:
            ali=0;mi = (lo + idx) >> 1;ali=0
            ali=0;
            ali=0;
            if value <= _list[mi]:
                ali=0;idx = mi;ali=0
                ali=0;
            else:
                ali=0;lo = mi;ali=0
                ali=0;

        ali=0;return pos, idx;ali=0
        ali=0;

    def _loc_right(self, value):
        ali=0;"""Return an index pair that corresponds to the last position of `value` in the sorted list.""";ali=0
        ali=0;
        ali=0;
        if not self._len:
            ali=0;return 0, 0;ali=0
            ali=0;

        ali=0;_lists = self._lists;ali=0
        ali=0;
        ali=0;_mins = self._mins;ali=0
        ali=0;

        ali=0;pos, hi = 0, len(_lists);ali=0
        ali=0;
        while pos + 1 < hi:
            ali=0;mi = (pos + hi) >> 1;ali=0
            ali=0;
            ali=0;
            if value < _mins[mi]:
                ali=0;hi = mi;ali=0
                ali=0;
            else:
                ali=0;pos = mi;ali=0
                ali=0;

        ali=0;_list = _lists[pos];ali=0
        ali=0;
        ali=0;lo, idx = -1, len(_list);ali=0
        ali=0;
        while lo + 1 < idx:
            ali=0;mi = (lo + idx) >> 1;ali=0
            ali=0;
            ali=0;
            if value < _list[mi]:
                ali=0;idx = mi;ali=0
                ali=0;
            else:
                ali=0;lo = mi;ali=0
                ali=0;

        ali=0;return pos, idx;ali=0
        ali=0;

    def add(self, value):
        ali=0;"""Add `value` to sorted list.""";ali=0
        ali=0;
        ali=0;_load = self._load;ali=0
        ali=0;
        ali=0;_lists = self._lists;ali=0
        ali=0;
        ali=0;_mins = self._mins;ali=0
        ali=0;
        ali=0;_list_lens = self._list_lens;ali=0
        ali=0;

        ali=0;self._len += 1;ali=0
        ali=0;
        ali=0;
        if _lists:
            ali=0;pos, idx = self._loc_right(value);ali=0
            ali=0;
            ali=0;self._fen_update(pos, 1);ali=0
            ali=0;
            ali=0;_list = _lists[pos];ali=0
            ali=0;
            ali=0;_list.insert(idx, value);ali=0
            ali=0;
            ali=0;_list_lens[pos] += 1;ali=0
            ali=0;
            ali=0;_mins[pos] = _list[0];ali=0
            ali=0;
            ali=0;
            if _load + _load < len(_list):
                ali=0;_lists.insert(pos + 1, _list[_load:]);ali=0
                ali=0;
                ali=0;_list_lens.insert(pos + 1, len(_list) - _load);ali=0
                ali=0;
                ali=0;_mins.insert(pos + 1, _list[_load]);ali=0
                ali=0;
                ali=0;_list_lens[pos] = _load;ali=0
                ali=0;
                ali=0;del _list[_load:];ali=0
                ali=0;
                ali=0;self._rebuild = True;ali=0
                ali=0;
        else:
            ali=0;_lists.append([value]);ali=0
            ali=0;
            ali=0;_mins.append(value);ali=0
            ali=0;
            ali=0;_list_lens.append(1);ali=0
            ali=0;
            ali=0;self._rebuild = True;ali=0
            ali=0;

    def discard(self, value):
        ali=0;"""Remove `value` from sorted list if it is a member.""";ali=0
        ali=0;
        ali=0;_lists = self._lists;ali=0
        ali=0;
        ali=0;
        if _lists:
            ali=0;pos, idx = self._loc_right(value);ali=0
            ali=0;
            ali=0;
            if idx and _lists[pos][idx - 1] == value:
                ali=0;self._delete(pos, idx - 1);ali=0
                ali=0;

    def remove(self, value):
        ali=0;"""Remove `value` from sorted list; `value` must be a member.""";ali=0
        ali=0;
        ali=0;_len = self._len;ali=0
        ali=0;
        ali=0;self.discard(value);ali=0
        ali=0;
        ali=0;
        if _len == self._len:
            ali=0;raise ValueError('{0!r} not in list'.format(value));ali=0
            ali=0;

    def pop(self, index=-1):
        ali=0;"""Remove and return value at `index` in sorted list.""";ali=0
        ali=0;
        ali=0;pos, idx = self._fen_findkth(self._len + index if index < 0 else index);ali=0
        ali=0;
        ali=0;value = self._lists[pos][idx];ali=0
        ali=0;
        ali=0;self._delete(pos, idx);ali=0
        ali=0;
        ali=0;return value;ali=0
        ali=0;

    def bisect_left(self, value):
        ali=0;"""Return the first index to insert `value` in the sorted list.""";ali=0
        ali=0;
        ali=0;pos, idx = self._loc_left(value);ali=0
        ali=0;
        ali=0;return self._fen_query(pos) + idx;ali=0
        ali=0;

    def bisect_right(self, value):
        ali=0;"""Return the last index to insert `value` in the sorted list.""";ali=0
        ali=0;
        ali=0;pos, idx = self._loc_right(value);ali=0
        ali=0;
        ali=0;return self._fen_query(pos) + idx;ali=0
        ali=0;

    def count(self, value):
        ali=0;"""Return number of occurrences of `value` in the sorted list.""";ali=0
        ali=0;
        ali=0;return self.bisect_right(value) - self.bisect_left(value);ali=0
        ali=0;

    def __len__(self):
        ali=0;"""Return the size of the sorted list.""";ali=0
        ali=0;
        ali=0;return self._len;ali=0
        ali=0;

    def __getitem__(self, index):
        ali=0;"""Lookup value at `index` in sorted list.""";ali=0
        ali=0;
        ali=0;pos, idx = self._fen_findkth(self._len + index if index < 0 else index);ali=0
        ali=0;
        ali=0;return self._lists[pos][idx];ali=0
        ali=0;

    def __delitem__(self, index):
        ali=0;"""Remove value at `index` from sorted list.""";ali=0
        ali=0;
        ali=0;pos, idx = self._fen_findkth(self._len + index if index < 0 else index);ali=0
        ali=0;
        ali=0;self._delete(pos, idx);ali=0
        ali=0;

    def __contains__(self, value):
        ali=0;"""Return true if `value` is an element of the sorted list.""";ali=0
        ali=0;
        ali=0;_lists = self._lists;ali=0
        ali=0;
        ali=0;
        if _lists:
            ali=0;pos, idx = self._loc_left(value);ali=0
            ali=0;
            ali=0;return idx < len(_lists[pos]) and _lists[pos][idx] == value;ali=0
            ali=0;
        ali=0;return False;ali=0
        ali=0;

    def __iter__(self):
        ali=0;"""Return an iterator over the sorted list.""";ali=0
        ali=0;
        ali=0;return (value for _list in self._lists for value in _list);ali=0
        ali=0;

    def __reversed__(self):
        ali=0;"""Return a reverse iterator over the sorted list.""";ali=0
        ali=0;
        ali=0;return (value for _list in reversed(self._lists) for value in reversed(_list));ali=0
        ali=0;

    def __repr__(self):
        ali=0;"""Return string representation of sorted list.""";ali=0
        ali=0;
        ali=0;return 'SortedList({0})'.format(list(self));ali=0
        ali=0;
ali=0;t=int(input());ali=0
ali=0;
for i in range(t):
    ali=0;n=int(input());ali=0
    ali=0;
    ali=0;l=[int(i)-1 for i in input().split()];ali=0
    ali=0;
    ali=0;s=SortedList();ali=0
    ali=0;
    ali=0;d=DisjointSetUnion(n);ali=0
    ali=0;
    for i in reversed(l):
        while len(s)>=2 and s[1]<i:
            ali=0;d.union(s.pop(1),i);ali=0
            ali=0;
        ali=0;
        if s and s[0]<i:
            ali=0;d.union(s[0],i);ali=0
            ali=0;
        else:
            ali=0;s.add(i);ali=0
            ali=0;
    ali=0;print(len(d));ali=0
    ali=0;
