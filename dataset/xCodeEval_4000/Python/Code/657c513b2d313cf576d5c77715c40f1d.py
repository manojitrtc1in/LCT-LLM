
from __future__ import division, print_function

import operator as op
import os
import sys
from bisect import bisect_left, bisect_right, insort
from io import BytesIO, IOBase
from itertools import chain, repeat, starmap

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip
else:
    _str = str
    str = lambda x=b"": x if type(x) is bytes else _str(x).encode()


class SortedList():
    """Sorted list is a sorted mutable sequence."""
    DEFAULT_LOAD_FACTOR = 500

    def __init__(self, iterable=None):
        """Initialize sorted list instance."""
        self._len = 0
        self._load = self.DEFAULT_LOAD_FACTOR
        self._lists = []
        self._maxes = []
        self._index = []
        self._offset = 0
        if iterable is not None:
            self.update(iterable)

    def clear(self):
        """Remove all values from sorted list."""
        self._len = 0
        del self._lists[:]
        del self._maxes[:]
        del self._index[:]
        self._offset = 0

    def add(self, value):
        """Add `value` to sorted list."""
        _lists = self._lists
        _maxes = self._maxes
        if _maxes:
            pos = bisect_right(_maxes, value)
            if pos == len(_maxes):
                pos -= 1
                _lists[pos].append(value)
                _maxes[pos] = value
            else:
                insort(_lists[pos], value)
            
        else:
            _lists.append([value])
            _maxes.append(value)
        self._len += 1

    def _expand(self, pos):
        """Split sublists with length greater than double the load-factor."""
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
        """Update sorted list by adding all values from `iterable`."""
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

    def __contains__(self, value):
        """Return true if `value` is an element of the sorted list."""
        _maxes = self._maxes
        pos = bisect_left(_maxes, value)
        if pos == len(_maxes):
            return False

        _lists = self._lists
        idx = bisect_left(_lists[pos], value)
        return _lists[pos][idx] == value

    def remove(self, value):
        """Remove `value` from sorted list if it is a member."""
        _maxes = self._maxes
        pos = bisect_left(_maxes, value)
        if pos == len(_maxes):
            return

        _lists = self._lists
        idx = bisect_left(_lists[pos], value)
        if _lists[pos][idx] == value:
            self._delete(pos, idx)

    def _delete(self, pos, idx):
        """Delete value at the given `(pos, idx)`."""
        _lists = self._lists
        _maxes = self._maxes
        _index = self._index

        _lists_pos = _lists[pos]
        del _lists_pos[idx]
        self._len -= 1

        len_lists_pos = len(_lists_pos)
        if len_lists_pos > (self._load >> 1):
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
            
        elif len_lists_pos:
            _maxes[pos] = _lists_pos[-1]
        else:
            del _lists[pos]
            del _maxes[pos]
            del _index[:]

    def _loc(self, pos, idx):
        """Convert an index pair (lists index, sublist index) into a single
        index number that corresponds to the position of the value in the
        sorted list."""
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
        """Convert an index into an index pair (lists index, sublist index)
        that can be used to access the corresponding lists position."""
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
        """Build a positional index for indexing the sorted list."""
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
        reduce(list.__iadd__, reversed(tree), self._index)
        self._offset = size * 2 - 1

    def __delitem__(self, index):
        """Remove value at `index` from sorted list."""
        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)
            if step == 1 and start < stop:
                if start == 0 and stop == self._len:
                    return self.clear()
                elif self._len <= 8 * (stop - start):
                    values = self.__getitem__(slice(None, start))
                    if stop < self._len:
                        values += self.__getitem__(slice(stop, None))
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

    def __getitem__(self, index):
        """Lookup value at `index` in sorted list."""
        _lists = self._lists

        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)

            if step == 1 and start < stop:
                if start == 0 and stop == self._len:
                    return reduce(list.__iadd__, self._lists, [])

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
                result = reduce(list.__iadd__, middle, prefix)
                result += _lists[stop_pos][:stop_idx]
                return result

            if step == -1 and start > stop:
                result = self.__getitem__(slice(stop + 1, start + 1))
                result.reverse()
                return result

            indices = range(start, stop, step)
            return list(self.__getitem__(index) for index in indices)
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

    def __iter__(self):
        """Return an iterator over the sorted list."""
        return chain.from_iterable(self._lists)

    def __reversed__(self):
        """Return a reverse iterator over the sorted list."""
        return chain.from_iterable(map(reversed, reversed(self._lists)))

    def __len__(self):
        """Return the size of the sorted list."""
        return self._len

    def bisect_left(self, value):
        """Return an index to insert `value` in the sorted list."""
        pos = bisect_left(self._maxes, value)
        return self._len if pos == len(self._maxes) else self._loc(pos, bisect_left(self._lists[pos], value))

    def bisect_right(self, value):
        """Return an index to insert `value` in the sorted list."""
        pos = bisect_right(self._maxes, value)
        return self._len if pos == len(self._maxes) else self._loc(pos, bisect_right(self._lists[pos], value))

    bisect = bisect_right

    def count(self, value):
        """Return number of occurrences of `value` in the sorted list."""
        _maxes = self._maxes
        if not _maxes:
            return 0

        pos_left = bisect_left(_maxes, value)
        if pos_left == len(_maxes):
            return 0

        _lists = self._lists
        idx_left = bisect_left(_lists[pos_left], value)
        pos_right = bisect_right(_maxes, value)
        if pos_right == len(_maxes):
            return self._len - self._loc(pos_left, idx_left)

        idx_right = bisect_right(_lists[pos_right], value)
        if pos_left == pos_right:
            return idx_right - idx_left

        right = self._loc(pos_right, idx_right)
        left = self._loc(pos_left, idx_left)
        return right - left

    def copy(self):
        """Return a shallow copy of the sorted list."""
        return self.__class__(self)

    __copy__ = copy

    def pop(self, index=-1):
        """Remove and return value at `index` in sorted list."""
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
        """Return first index of value in sorted list."""
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
        pos_left = bisect_left(_maxes, value)
        if pos_left == len(_maxes):
            raise ValueError('{0!r} is not in list'.format(value))

        _lists = self._lists
        idx_left = bisect_left(_lists[pos_left], value)
        if _lists[pos_left][idx_left] != value:
            raise ValueError('{0!r} is not in list'.format(value))

        stop -= 1
        left = self._loc(pos_left, idx_left)
        if start <= left:
            if left <= stop:
                return left
        else:
            if start <= self.bisect_right(value) - 1:
                return start
        raise ValueError('{0!r} is not in list'.format(value))

    def __add__(self, other):
        """Return new sorted list containing all values in both sequences."""
        values = reduce(list.__iadd__, self._lists, [])
        values.extend(other)
        return self.__class__(values)

    __radd__ = __add__

    def __iadd__(self, other):
        """Update sorted list with values from `other`."""
        self.update(other)
        return self

    def __mul__(self, num):
        """Return new sorted list with `num` shallow copies of values."""
        values = reduce(list.__iadd__, self._lists, []) * num
        return self.__class__(values)

    __rmul__ = __mul__

    def __imul__(self, num):
        """Update the sorted list with `num` shallow copies of values."""
        values = reduce(list.__iadd__, self._lists, []) * num
        self.clear()
        self.update(values)
        return self

    def __make_cmp(seq_op):
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

    __eq__ = __make_cmp(op.eq)
    __ne__ = __make_cmp(op.ne)
    __lt__ = __make_cmp(op.lt)
    __gt__ = __make_cmp(op.gt)
    __le__ = __make_cmp(op.le)
    __ge__ = __make_cmp(op.ge)
    __make_cmp = staticmethod(__make_cmp)

    def __repr__(self):
        """Return string representation of sorted list."""
        return 'SortedList({0})'.format(reduce(list.__iadd__, self._lists, []))


def main():
    n = int(readline())
    a = readlist()
    b = SortedList(readlist())
    for i, ai in enumerate(a):
        it = b.bisect_left(n - ai)
        x = b[0] if it == len(b) else b[it]
        cout << (x + ai) % n << ' '
        b.remove(x)
        if i % 2000 == 0:
            b = SortedList(b)
    cout << '\n'




BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._buffer = BytesIO()
        self._fd = file.fileno()
        self._writable = "x" in file.mode or "r" not in file.mode
        self.write = self._buffer.write if self._writable else None

    def read(self):
        if self._buffer.tell():
            return self._buffer.read()
        return os.read(self._fd, os.fstat(self._fd).st_size)

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self._buffer.tell()
            self._buffer.seek(0, 2), self._buffer.write(b), self._buffer.seek(ptr)
        self.newlines -= 1
        return self._buffer.readline()

    def flush(self):
        if self._writable:
            os.write(self._fd, self._buffer.getvalue())
            self._buffer.truncate(0), self._buffer.seek(0)


class ostream:
    def __lshift__(self, a):
        if a is endl:
            sys.stdout.write(b"\n")
            sys.stdout.flush()
        else:
            sys.stdout.write(str(a))
        return self


def print(*args, **kwargs):
    sep, file = kwargs.pop("sep", b" "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", b"\n"))
    if kwargs.pop("flush", False):
        file.flush()


sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
cout, endl = ostream(), object()

readline = sys.stdin.readline
readlist = lambda var=int: [var(n) for n in readline().split()]
input = lambda: readline().rstrip(b"\r\n")



if __name__ == "__main__":
    main()