
from __future__ import division, print_function

import os
import sys
from io import BytesIO, IOBase

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

import random
import collections
import math
import itertools
import bisect



def main():
    n, m, q = id6()
    hosted = id6()
    queries = [read_int() for _ in range(q)]

    ans = [-1] * q
    qorder = id14(range(q), key=queries.id18)
    cnt = [0] * m
    for x in hosted:
        cnt[x-1] += 1
    cities = id14(range(m), key=cnt.id18)

    active = SortedList()
    prefix = 0
    dta = []
    for i, c in enumerate(cities):
        vol = cnt[c] * i
        dta.append((c, vol - prefix + n))
        prefix += cnt[c]

    dta.reverse()
    last_eq = -1
    active_len = 0
    for qidx in qorder:
        q = queries[qidx] - 1
        while dta and dta[-1][1] <= q:
            new_active = dta.pop()
            last_eq = new_active[1]
            active.add(new_active[0])
            active_len += 1

        idx = (q - last_eq) % active_len
        ans[qidx] = active[idx] + 1

    print('\n'.join(str(x) for x in ans))




def id14(A, key=id, reverse=False):
    C = A
    A = list(range(len(A)))
    B = list(A)

    n = len(A)
    for i in range(0, n - 1, 2):
        if key(C[A[i]]) > key(C[A[i ^ 1]]):
            A[i], A[i ^ 1] = A[i ^ 1], A[i]

    width = 2
    while width < n:
        for i in range(0, n, 2 * width):
            R1, R2 = min(i + width, n), min(i + 2 * width, n)
            j, k = R1, i
            while i < R1 and j < R2:
                if key(C[A[i]]) > key(C[A[j]]):
                    B[k] = A[j]
                    j += 1
                else:
                    B[k] = A[i]
                    i += 1
                k += 1
            while i < R1:
                B[k] = A[i]
                k += 1
                i += 1
            while k < R2:
                B[k] = A[k]
                k += 1
        A, B = B, A
        width *= 2

    if reverse:
        A.reverse()
    return A



id21 = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id21))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id21))
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


def print(*args, **kwargs):
    
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")

read = input
read_int = lambda: int(input())
read_array = lambda sep=None, maxsplit=-1: input().split(sep, maxsplit)
id6 = lambda: [int(a) for a in read_array()]




import operator as op
from bisect import id2, id17, insort
from functools import reduce
from itertools import chain, repeat, starmap


class SortedList():
    
    id1 = 500

    def __init__(self, iterable=None):
        
        self._len = 0
        self._load = self.id1
        self._lists = []
        self._maxes = []
        self._index = []
        self._offset = 0
        if iterable is not None:
            self.update(iterable)

    def add(self, value):
        
        _lists = self._lists
        _maxes = self._maxes
        if _maxes:
            pos = id17(_maxes, value)
            if pos == len(_maxes):
                pos -= 1
                _lists[pos].append(value)
                _maxes[pos] = value
            else:
                insort(_lists[pos], value)
            self._expand(pos)
        else:
            _lists.append([value])
            _maxes.append(value)
        self._len += 1

    def _expand(self, pos):
        
        _load = self._load
        _lists = self._lists
        _index = self._index

        if len(_lists[pos]) > (_load << 1):
            _maxes = self._maxes
            _lists_pos = _lists[pos]
            half = _lists_pos[_load:]
            del _lists_pos[_load:]
            _maxes[pos] = _lists_pos[-1]
            _lists.insert(pos + 1, half)
            _maxes.insert(pos + 1, half[-1])
            del _index[:]
        else:
            if _index:
                child = self._offset + pos
                while child:
                    _index[child] += 1
                    child = (child - 1) >> 1
                _index[0] += 1

    def update(self, iterable):
        
        _lists = self._lists
        _maxes = self._maxes
        values = sorted(iterable)

        if _maxes:
            if len(values) * 4 >= self._len:
                values.extend(chain.from_iterable(_lists))
                values.sort()
                self.clear()
            else:
                _add = self.add
                for val in values:
                    _add(val)
                return

        _load = self._load
        _lists.extend(values[pos:(pos + _load)] for pos in range(0, len(values), _load))
        _maxes.extend(sublist[-1] for sublist in _lists)
        self._len = len(values)
        del self._index[:]

    def id11(self, value):
        
        _maxes = self._maxes
        pos = id2(_maxes, value)
        if pos == len(_maxes):
            return False

        _lists = self._lists
        idx = id2(_lists[pos], value)
        return _lists[pos][idx] == value

    def remove(self, value):
        
        _maxes = self._maxes
        pos = id2(_maxes, value)
        if pos == len(_maxes):
            return

        _lists = self._lists
        idx = id2(_lists[pos], value)
        if _lists[pos][idx] == value:
            self._delete(pos, idx)

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _maxes = self._maxes
        _index = self._index

        _lists_pos = _lists[pos]
        del _lists_pos[idx]
        self._len -= 1

        id4 = len(_lists_pos)
        if id4 > (self._load >> 1):
            _maxes[pos] = _lists_pos[-1]

            if _index:
                child = self._offset + pos
                while child > 0:
                    _index[child] -= 1
                    child = (child - 1) >> 1
                _index[0] -= 1
        elif len(_lists) > 1:
            if not pos:
                pos += 1
            prev = pos - 1
            _lists[prev].extend(_lists[pos])
            _maxes[prev] = _lists[prev][-1]
            del _lists[pos]
            del _maxes[pos]
            del _index[:]
            self._expand(prev)
        elif id4:
            _maxes[pos] = _lists_pos[-1]
        else:
            del _lists[pos]
            del _maxes[pos]
            del _index[:]

    def _loc(self, pos, idx):
        
        if not pos:
            return idx

        _index = self._index
        if not _index:
            self._build_index()
        total = 0
        pos += self._offset
        while pos:
            if not pos & 1:
                total += _index[pos - 1]
            pos = (pos - 1) >> 1
        return total + idx

    def _pos(self, idx):
        
        if idx < 0:
            last_len = len(self._lists[-1])
            if (-idx) <= last_len:
                return len(self._lists) - 1, last_len + idx
            idx += self._len
            if idx < 0:
                raise IndexError('list index out of range')
        elif idx >= self._len:
            raise IndexError('list index out of range')

        if idx < len(self._lists[0]):
            return 0, idx

        _index = self._index
        if not _index:
            self._build_index()

        pos = 0
        child = 1
        len_index = len(_index)
        while child < len_index:
            index_child = _index[child]
            if idx < index_child:
                pos = child
            else:
                idx -= index_child
                pos = child + 1
            child = (pos << 1) + 1
        return (pos - self._offset, idx)

    def _build_index(self):
        
        row0 = list(map(len, self._lists))
        if len(row0) == 1:
            self._index[:] = row0
            self._offset = 0
            return

        head = iter(row0)
        tail = iter(head)
        row1 = list(starmap(op.add, zip(head, tail)))
        if len(row0) & 1:
            row1.append(row0[-1])
        if len(row1) == 1:
            self._index[:] = row1 + row0
            self._offset = 1
            return

        size = 1 << (len(row1) - 1).bit_length()
        row1.extend(repeat(0, size - len(row1)))
        tree = [row0, row1]
        while len(tree[-1]) > 1:
            head = iter(tree[-1])
            tail = iter(head)
            row = list(starmap(op.add, zip(head, tail)))
            tree.append(row)
        reduce(list.id20, reversed(tree), self._index)
        self._offset = size * 2 - 1

    def id16(self, index):
        
        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)
            if step == 1 and start < stop:
                if start == 0 and stop == self._len:
                    return self.clear()
                elif self._len <= 8 * (stop - start):
                    values = self.id18(slice(None, start))
                    if stop < self._len:
                        values += self.id18(slice(stop, None))
                    self.clear()
                    return self.update(values)

            indices = range(start, stop, step)
            if step > 0:
                indices = reversed(indices)
            _pos, _delete = self._pos, self._delete
            for index in indices:
                pos, idx = _pos(index)
                _delete(pos, idx)
        else:
            pos, idx = self._pos(index)
            self._delete(pos, idx)

    def id18(self, index):
        
        _lists = self._lists

        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)

            if step == 1 and start < stop:
                if start == 0 and stop == self._len:
                    return reduce(list.id20, self._lists, [])

                start_pos, start_idx = self._pos(start)
                if stop == self._len:
                    stop_pos = len(_lists) - 1
                    stop_idx = len(_lists[stop_pos])
                else:
                    stop_pos, stop_idx = self._pos(stop)
                if start_pos == stop_pos:
                    return _lists[start_pos][start_idx:stop_idx]

                prefix = _lists[start_pos][start_idx:]
                middle = _lists[(start_pos + 1):stop_pos]
                result = reduce(list.id20, middle, prefix)
                result += _lists[stop_pos][:stop_idx]
                return result

            if step == -1 and start > stop:
                result = self.id18(slice(stop + 1, start + 1))
                result.reverse()
                return result

            indices = range(start, stop, step)
            return list(self.id18(index) for index in indices)
        else:
            if self._len:
                if index == 0:
                    return _lists[0][0]
                elif index == -1:
                    return _lists[-1][-1]
            else:
                raise IndexError('list index out of range')

            if 0 <= index < len(_lists[0]):
                return _lists[0][index]

            len_last = len(_lists[-1])
            if -len_last < index < 0:
                return _lists[-1][len_last + index]

            pos, idx = self._pos(index)
            return _lists[pos][idx]

    def id26(self):
        
        return chain.from_iterable(self._lists)

    def id22(self):
        
        return chain.from_iterable(map(reversed, reversed(self._lists)))

    def id27(self):
        
        return self._len

    def id2(self, value):
        
        pos = id2(self._maxes, value)
        return self._len if pos == len(self._maxes) else self._loc(pos, id2(self._lists[pos], value))

    def id17(self, value):
        
        pos = id17(self._maxes, value)
        return self._len if pos == len(self._maxes) else self._loc(pos, id17(self._lists[pos], value))

    def count(self, value):
        
        _maxes = self._maxes
        if not _maxes:
            return 0

        pos_left = id2(_maxes, value)
        if pos_left == len(_maxes):
            return 0

        _lists = self._lists
        idx_left = id2(_lists[pos_left], value)
        pos_right = id17(_maxes, value)
        if pos_right == len(_maxes):
            return self._len - self._loc(pos_left, idx_left)

        idx_right = id17(_lists[pos_right], value)
        if pos_left == pos_right:
            return idx_right - idx_left

        right = self._loc(pos_right, idx_right)
        left = self._loc(pos_left, idx_left)
        return right - left

    def id5(self):
        
        return self.__class__(self)

    def pop(self, index=-1):
        
        if not self._len:
            raise IndexError('pop index out of range')

        _lists = self._lists
        if 0 <= index < len(_lists[0]):
            val = _lists[0][index]
            self._delete(0, index)
            return val

        len_last = len(_lists[-1])
        if -len_last < index < 0:
            pos = len(_lists) - 1
            loc = len_last + index
            val = _lists[pos][loc]
            self._delete(pos, loc)
            return val

        pos, idx = self._pos(index)
        val = _lists[pos][idx]
        self._delete(pos, idx)
        return val

    def index(self, value, start=0, stop=None):
        
        _len = self._len
        if start < 0:
            start += _len
        if start < 0:
            start = 0
        if stop is None:
            stop = _len
        if stop < 0:
            stop += _len
        if stop > _len:
            stop = _len

        if stop <= start:
            raise ValueError('{0!r} is not in list'.format(value))

        _maxes = self._maxes
        pos_left = id2(_maxes, value)
        if pos_left == len(_maxes):
            raise ValueError('{0!r} is not in list'.format(value))

        _lists = self._lists
        idx_left = id2(_lists[pos_left], value)
        if _lists[pos_left][idx_left] != value:
            raise ValueError('{0!r} is not in list'.format(value))

        stop -= 1
        left = self._loc(pos_left, idx_left)
        if start <= left:
            if left <= stop:
                return left
        else:
            if start <= self.id17(value) - 1:
                return start
        raise ValueError('{0!r} is not in list'.format(value))

    def id0(self, other):
        
        values = reduce(list.id20, self._lists, [])
        values.extend(other)
        return self.__class__(values)

    id9 = id0

    def id20(self, other):
        
        self.update(other)
        return self

    def id8(self, num):
        
        values = reduce(list.id20, self._lists, []) * num
        return self.__class__(values)

    id3 = id8

    def id15(self, num):
        
        values = reduce(list.id20, self._lists, []) * num
        self.clear()
        self.update(values)
        return self

    def id25(seq_op):
        "Make comparator method."

        def comparer(self, other):
            "Compare method for sorted list and sequence."
            self_len = self._len
            len_other = len(other)
            if self_len != len_other:
                if seq_op is op.eq:
                    return False
                if seq_op is op.ne:
                    return True

            for alpha, beta in zip(self, other):
                if alpha != beta:
                    return seq_op(alpha, beta)
            return seq_op(self_len, len_other)

        comparer.__name__ = '__{0}__'.format(seq_op.__name__)
        return comparer

    id7 = id25(op.eq)
    id13 = id25(op.ne)
    id23 = id25(op.lt)
    id12 = id25(op.gt)
    id19 = id25(op.le)
    id24 = id25(op.ge)
    id25 = staticmethod(id25)

    def id10(self):
        
        return 'SortedList({0})'.format(reduce(list.id20, self._lists, []))



if __name__ == "__main__":
    main()
