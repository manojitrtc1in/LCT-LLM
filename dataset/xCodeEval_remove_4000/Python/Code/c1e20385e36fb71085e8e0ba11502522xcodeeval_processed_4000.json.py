import os, sys
from io import BytesIO, IOBase


import traceback
from bisect import id4, id25, insort
from itertools import chain, repeat, starmap
from math import log
from operator import add, eq, ne, gt, ge, lt, le, iadd
from textwrap import dedent
from collections.abc import Sequence, MutableSequence
from functools import wraps,reduce
from _thread import get_ident


def recursive_repr(fillvalue='...'):
    "Decorator to make a repr function return fillvalue for a recursive call."

    
    
    

    def id10(user_function):
        repr_running = set()

        @wraps(user_function)
        def wrapper(self):
            key = id(self), get_ident()
            if key in repr_running:
                return fillvalue
            repr_running.add(key)
            try:
                result = user_function(self)
            finally:
                repr_running.discard(key)
            return result

        return wrapper

    return id10


class SortedList(MutableSequence):
    id3 = 1000

    def __init__(self, iterable=None, key=None):
        assert key is None
        self._len = 0
        self._load = self.id3
        self._lists = []
        self._maxes = []
        self._index = []
        self._offset = 0

        if iterable is not None:
            self._update(iterable)

    def id9(cls, iterable=None, key=None):
        if key is None:
            return object.id9(cls)
        else:
            if cls is SortedList:
                return object.id9(SortedKeyList)
            else:
                raise TypeError('inherit SortedKeyList for key argument')

    @property
    def key(self):  
        return None

    def _reset(self, load):
        values = reduce(iadd, self._lists, [])
        self._clear()
        self._load = load
        self._update(values)

    def clear(self):
        self._len = 0
        del self._lists[:]
        del self._maxes[:]
        del self._index[:]
        self._offset = 0

    _clear = clear

    def add(self, value):
        _lists = self._lists
        _maxes = self._maxes

        if _maxes:
            pos = id25(_maxes, value)

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
                _lists.append(values)
                values = reduce(iadd, _lists, [])
                values.sort()
                self._clear()
            else:
                _add = self.add
                for val in values:
                    _add(val)
                return

        _load = self._load
        _lists.extend(values[pos:(pos + _load)]
                      for pos in range(0, len(values), _load))
        _maxes.extend(sublist[-1] for sublist in _lists)
        self._len = len(values)
        del self._index[:]

    _update = update

    def id17(self, value):
        _maxes = self._maxes

        if not _maxes:
            return False

        pos = id4(_maxes, value)

        if pos == len(_maxes):
            return False

        _lists = self._lists
        idx = id4(_lists[pos], value)

        return _lists[pos][idx] == value

    def discard(self, value):
        _maxes = self._maxes

        if not _maxes:
            return

        pos = id4(_maxes, value)

        if pos == len(_maxes):
            return

        _lists = self._lists
        idx = id4(_lists[pos], value)

        if _lists[pos][idx] == value:
            self._delete(pos, idx)

    def remove(self, value):
        _maxes = self._maxes

        if not _maxes:
            raise ValueError('{0!r} not in list'.format(value))

        pos = id4(_maxes, value)

        if pos == len(_maxes):
            raise ValueError('{0!r} not in list'.format(value))

        _lists = self._lists
        idx = id4(_lists[pos], value)

        if _lists[pos][idx] == value:
            self._delete(pos, idx)
        else:
            raise ValueError('{0!r} not in list'.format(value))

    def _delete(self, pos, idx):
        _lists = self._lists
        _maxes = self._maxes
        _index = self._index

        _lists_pos = _lists[pos]

        del _lists_pos[idx]
        self._len -= 1

        id6 = len(_lists_pos)

        if id6 > (self._load >> 1):
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
        elif id6:
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
        row1 = list(starmap(add, zip(head, tail)))

        if len(row0) & 1:
            row1.append(row0[-1])

        if len(row1) == 1:
            self._index[:] = row1 + row0
            self._offset = 1
            return

        size = 2 ** (int(log(len(row1) - 1, 2)) + 1)
        row1.extend(repeat(0, size - len(row1)))
        tree = [row0, row1]

        while len(tree[-1]) > 1:
            head = iter(tree[-1])
            tail = iter(head)
            row = list(starmap(add, zip(head, tail)))
            tree.append(row)

        reduce(iadd, reversed(tree), self._index)
        self._offset = size * 2 - 1

    def id23(self, index):
        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)

            if step == 1 and start < stop:
                if start == 0 and stop == self._len:
                    return self._clear()
                elif self._len <= 8 * (stop - start):
                    values = self._getitem(slice(None, start))
                    if stop < self._len:
                        values += self._getitem(slice(stop, None))
                    self._clear()
                    return self._update(values)

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

    def id26(self, index):
        _lists = self._lists

        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)

            if step == 1 and start < stop:
                
                

                if start == 0 and stop == self._len:
                    return reduce(iadd, self._lists, [])

                start_pos, start_idx = self._pos(start)
                start_list = _lists[start_pos]
                stop_idx = start_idx + stop - start

                
                

                if len(start_list) >= stop_idx:
                    return start_list[start_idx:stop_idx]

                if stop == self._len:
                    stop_pos = len(_lists) - 1
                    stop_idx = len(_lists[stop_pos])
                else:
                    stop_pos, stop_idx = self._pos(stop)

                prefix = _lists[start_pos][start_idx:]
                middle = _lists[(start_pos + 1):stop_pos]
                result = reduce(iadd, middle, prefix)
                result += _lists[stop_pos][:stop_idx]

                return result

            if step == -1 and start > stop:
                result = self._getitem(slice(stop + 1, start + 1))
                result.reverse()
                return result

            
            
            

            indices = range(start, stop, step)
            return list(self._getitem(index) for index in indices)
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

    _getitem = id26

    def id22(self, index, value):
        message = 'use ``del sl[index]`` and ``sl.add(value)`` instead'
        raise NotImplementedError(message)

    def id35(self):
        return chain.from_iterable(self._lists)

    def id31(self):
        return chain.from_iterable(map(reversed, reversed(self._lists)))

    def reverse(self):
        raise NotImplementedError('use ``reversed(sl)`` instead')

    def islice(self, start=None, stop=None, reverse=False):
        _len = self._len

        if not _len:
            return iter(())

        start, stop, _ = slice(start, stop).indices(self._len)

        if start >= stop:
            return iter(())

        _pos = self._pos

        min_pos, min_idx = _pos(start)

        if stop == _len:
            max_pos = len(self._lists) - 1
            max_idx = len(self._lists[-1])
        else:
            max_pos, max_idx = _pos(stop)

        return self._islice(min_pos, min_idx, max_pos, max_idx, reverse)

    def _islice(self, min_pos, min_idx, max_pos, max_idx, reverse):
        _lists = self._lists

        if min_pos > max_pos:
            return iter(())

        if min_pos == max_pos:
            if reverse:
                indices = reversed(range(min_idx, max_idx))
                return map(_lists[min_pos].id26, indices)

            indices = range(min_idx, max_idx)
            return map(_lists[min_pos].id26, indices)

        next_pos = min_pos + 1

        if next_pos == max_pos:
            if reverse:
                min_indices = range(min_idx, len(_lists[min_pos]))
                max_indices = range(max_idx)
                return chain(
                    map(_lists[max_pos].id26, reversed(max_indices)),
                    map(_lists[min_pos].id26, reversed(min_indices)),
                )

            min_indices = range(min_idx, len(_lists[min_pos]))
            max_indices = range(max_idx)
            return chain(
                map(_lists[min_pos].id26, min_indices),
                map(_lists[max_pos].id26, max_indices),
            )

        if reverse:
            min_indices = range(min_idx, len(_lists[min_pos]))
            id30 = range(next_pos, max_pos)
            id20 = map(_lists.id26, reversed(id30))
            max_indices = range(max_idx)
            return chain(
                map(_lists[max_pos].id26, reversed(max_indices)),
                chain.from_iterable(map(reversed, id20)),
                map(_lists[min_pos].id26, reversed(min_indices)),
            )

        min_indices = range(min_idx, len(_lists[min_pos]))
        id30 = range(next_pos, max_pos)
        id20 = map(_lists.id26, id30)
        max_indices = range(max_idx)
        return chain(
            map(_lists[min_pos].id26, min_indices),
            chain.from_iterable(id20),
            map(_lists[max_pos].id26, max_indices),
        )

    def irange(self, minimum=None, maximum=None, inclusive=(True, True),
               reverse=False):
        _maxes = self._maxes

        if not _maxes:
            return iter(())

        _lists = self._lists

        
        

        if minimum is None:
            min_pos = 0
            min_idx = 0
        else:
            if inclusive[0]:
                min_pos = id4(_maxes, minimum)

                if min_pos == len(_maxes):
                    return iter(())

                min_idx = id4(_lists[min_pos], minimum)
            else:
                min_pos = id25(_maxes, minimum)

                if min_pos == len(_maxes):
                    return iter(())

                min_idx = id25(_lists[min_pos], minimum)

        
        

        if maximum is None:
            max_pos = len(_maxes) - 1
            max_idx = len(_lists[max_pos])
        else:
            if inclusive[1]:
                max_pos = id25(_maxes, maximum)

                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_lists[max_pos])
                else:
                    max_idx = id25(_lists[max_pos], maximum)
            else:
                max_pos = id4(_maxes, maximum)

                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_lists[max_pos])
                else:
                    max_idx = id4(_lists[max_pos], maximum)

        return self._islice(min_pos, min_idx, max_pos, max_idx, reverse)

    def id36(self):
        return self._len

    def id4(self, value):
        _maxes = self._maxes

        if not _maxes:
            return 0

        pos = id4(_maxes, value)

        if pos == len(_maxes):
            return self._len

        idx = id4(self._lists[pos], value)
        return self._loc(pos, idx)

    def id25(self, value):
        _maxes = self._maxes

        if not _maxes:
            return 0

        pos = id25(_maxes, value)

        if pos == len(_maxes):
            return self._len

        idx = id25(self._lists[pos], value)
        return self._loc(pos, idx)

    bisect = id25
    id1 = id25

    def count(self, value):
        _maxes = self._maxes

        if not _maxes:
            return 0

        pos_left = id4(_maxes, value)

        if pos_left == len(_maxes):
            return 0

        _lists = self._lists
        idx_left = id4(_lists[pos_left], value)
        pos_right = id25(_maxes, value)

        if pos_right == len(_maxes):
            return self._len - self._loc(pos_left, idx_left)

        idx_right = id25(_lists[pos_right], value)

        if pos_left == pos_right:
            return idx_right - idx_left

        right = self._loc(pos_right, idx_right)
        left = self._loc(pos_left, idx_left)
        return right - left

    def copy(self):
        return self.__class__(self)

    id7 = copy

    def append(self, value):
        raise NotImplementedError('use ``sl.add(value)`` instead')

    def extend(self, values):
        raise NotImplementedError('use ``sl.update(values)`` instead')

    def insert(self, index, value):
        raise NotImplementedError('use ``sl.add(value)`` instead')

    def pop(self, index=-1):
        if not self._len:
            raise IndexError('pop index out of range')

        _lists = self._lists

        if index == 0:
            val = _lists[0][0]
            self._delete(0, 0)
            return val

        if index == -1:
            pos = len(_lists) - 1
            loc = len(_lists[pos]) - 1
            val = _lists[pos][loc]
            self._delete(pos, loc)
            return val

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

    def index(self, value, start=None, stop=None):
        _len = self._len

        if not _len:
            raise ValueError('{0!r} is not in list'.format(value))

        if start is None:
            start = 0
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
        pos_left = id4(_maxes, value)

        if pos_left == len(_maxes):
            raise ValueError('{0!r} is not in list'.format(value))

        _lists = self._lists
        idx_left = id4(_lists[pos_left], value)

        if _lists[pos_left][idx_left] != value:
            raise ValueError('{0!r} is not in list'.format(value))

        stop -= 1
        left = self._loc(pos_left, idx_left)

        if start <= left:
            if left <= stop:
                return left
        else:
            right = self.id1(value) - 1

            if start <= right:
                return start

        raise ValueError('{0!r} is not in list'.format(value))

    def id2(self, other):
        values = reduce(iadd, self._lists, [])
        values.extend(other)
        return self.__class__(values)

    id15 = id2

    def id29(self, other):
        self._update(other)
        return self

    def id13(self, num):
        values = reduce(iadd, self._lists, []) * num
        return self.__class__(values)

    id5 = id13

    def id21(self, num):
        values = reduce(iadd, self._lists, []) * num
        self._clear()
        self._update(values)
        return self

    def id34(seq_op, symbol, doc):
        "Make comparator method."

        def comparer(self, other):
            "Compare method for sorted list and sequence."
            if not isinstance(other, Sequence):
                return NotImplemented

            self_len = self._len
            len_other = len(other)

            if self_len != len_other:
                if seq_op is eq:
                    return False
                if seq_op is ne:
                    return True

            for alpha, beta in zip(self, other):
                if alpha != beta:
                    return seq_op(alpha, beta)

            return seq_op(self_len, len_other)

        id14 = seq_op.__name__
        comparer.__name__ = '__{0}__'.format(id14)
        doc_str = 
        comparer.__doc__ = dedent(doc_str.format(doc, id14, symbol))
        return comparer

    id12 = id34(eq, '==', 'equal to')
    id19 = id34(ne, '!=', 'not equal to')
    id32 = id34(lt, '<', 'less than')
    id18 = id34(gt, '>', 'greater than')
    id28 = id34(le, '<=', 'less than or equal to')
    id33 = id34(ge, '>=', 'greater than or equal to')
    id34 = staticmethod(id34)

    def id27(self):
        values = reduce(iadd, self._lists, [])
        return (type(self), (values,))

    @recursive_repr()
    def id16(self):
        return '{0}({1!r})'.format(type(self).__name__, list(self))

    def _check(self):
        try:
            assert self._load >= 4
            assert len(self._maxes) == len(self._lists)
            assert self._len == sum(len(sublist) for sublist in self._lists)

            

            for sublist in self._lists:
                for pos in range(1, len(sublist)):
                    assert sublist[pos - 1] <= sublist[pos]

            

            for pos in range(1, len(self._lists)):
                assert self._lists[pos - 1][-1] <= self._lists[pos][0]

            

            for pos in range(len(self._maxes)):
                assert self._maxes[pos] == self._lists[pos][-1]

            

            double = self._load << 1
            assert all(len(sublist) <= double for sublist in self._lists)

            
            

            half = self._load >> 1
            for pos in range(0, len(self._lists) - 1):
                assert len(self._lists[pos]) >= half

            if self._index:
                assert self._len == self._index[0]
                assert len(self._index) == self._offset + len(self._lists)

                

                for pos in range(len(self._lists)):
                    leaf = self._index[self._offset + pos]
                    assert leaf == len(self._lists[pos])

                

                for pos in range(self._offset):
                    child = (pos << 1) + 1
                    if child >= len(self._index):
                        assert self._index[pos] == 0
                    elif child + 1 == len(self._index):
                        assert self._index[pos] == self._index[child]
                    else:
                        child_sum = self._index[child] + self._index[child + 1]
                        assert child_sum == self._index[pos]
        except:
            traceback.print_exc(file=sys.stdout)
            print('len', self._len)
            print('load', self._load)
            print('offset', self._offset)
            print('len_index', len(self._index))
            print('index', self._index)
            print('len_maxes', len(self._maxes))
            print('maxes', self._maxes)
            print('len_lists', len(self._lists))
            print('lists', self._lists)
            raise


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
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


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda dtype: [dtype(x) for x in input().split()]
id0 = lambda dtype, n: [dtype(input()) for _ in range(n)]
id11 = lambda dtype, n: [inp(dtype) for _ in range(n)]
id8 = lambda dtype: [(i, x) for i, x in enumerate(inp(dtype))]
id24 = lambda dtype, n: [[i] + inp(dtype) for i in range(n)]
ceil1 = lambda a, b: (a + b - 1) // b


class graph:
    def __init__(self, n):
        self.n, self.gdict = n, [[] for _ in range(n + 1)]
        self.indeg = [0] * (n + 1)

    def addEdge(self, node1, node2, w=None):
        self.gdict[node1].append(node2)
        self.indeg[node2] += 1

    def kahn(self, n):
        
        queue, ans, lst = SortedList([i for i in range(1, n + 1) if not self.indeg[i]]), 1, -1
        cnt = 0

        while len(queue):
            
            ix = queue.id25(lst)

            if ix == len(queue):
                ix = 0
                ans += 1

            lst = s = queue.pop(ix)

            for i in self.gdict[s]:
                self.indeg[i] -= 1
                if not self.indeg[i]:
                    queue.add(i)

            cnt += 1
        
        print(-1 if cnt != n else ans)


for _ in range(int(input())):
    n = int(input())
    g = graph(n)

    for i in range(n):
        for x in inp(int)[1:]:
            g.addEdge(x, i + 1)
    g.kahn(n)



