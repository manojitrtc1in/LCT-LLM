from bisect import id3, id19, insort
from collections import Sequence
from functools import wraps
from itertools import chain, repeat, starmap
from math import log
from operator import add, eq, ge, gt, iadd, le, lt, ne

try:
    from thread import get_ident
except ImportError:
    from functools import reduce
    from _thread import get_ident


def recursive_repr(fillvalue='...'):
    "Decorator to make a repr function return fillvalue for a recursive call."

    def id8(user_function):
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

    return id8


class SortedList():
    
    id2 = 1000

    def __init__(self, iterable=None, key=None):
        
        assert key is None
        self._len = 0
        self._load = self.id2
        self._lists = []
        self._maxes = []
        self._index = []
        self._offset = 0

        if iterable is not None:
            self._update(iterable)

    def id7(cls, iterable=None, key=None):
        
        if key is None:
            return object.id7(cls)
        else:
            if cls is SortedList:
                return object.id7(SortedKeyList)
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
            pos = id19(_maxes, value)

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
                self._clear()
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

    _update = update

    def id14(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            return False

        pos = id3(_maxes, value)

        if pos == len(_maxes):
            return False

        _lists = self._lists
        idx = id3(_lists[pos], value)

        return _lists[pos][idx] == value

    def remove(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            return

        pos = id3(_maxes, value)

        if pos == len(_maxes):
            return

        _lists = self._lists
        idx = id3(_lists[pos], value)

        if _lists[pos][idx] == value:
            self._delete(pos, idx)

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _maxes = self._maxes
        _index = self._index

        _lists_pos = _lists[pos]

        del _lists_pos[idx]
        self._len -= 1

        id5 = len(_lists_pos)

        if id5 > (self._load >> 1):
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
        elif id5:
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

        size = 2**(int(log(len(row1) - 1, 2)) + 1)
        row1.extend(repeat(0, size - len(row1)))
        tree = [row0, row1]

        while len(tree[-1]) > 1:
            head = iter(tree[-1])
            tail = iter(head)
            row = list(starmap(add, zip(head, tail)))
            tree.append(row)

        reduce(iadd, reversed(tree), self._index)
        self._offset = size * 2 - 1

    def id18(self, index):
        
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

    def id20(self, index):
        
        _lists = self._lists

        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)

            if step == 1 and start < stop:
                if start == 0 and stop == self._len:
                    return reduce(iadd, self._lists, [])

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

    _getitem = id20

    def id28(self):
        
        return chain.from_iterable(self._lists)

    def id24(self):
        
        return chain.from_iterable(map(reversed, reversed(self._lists)))

    def id29(self):
        
        return self._len

    def id3(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            return 0

        pos = id3(_maxes, value)

        if pos == len(_maxes):
            return self._len

        idx = id3(self._lists[pos], value)
        return self._loc(pos, idx)

    def id19(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            return 0

        pos = id19(_maxes, value)

        if pos == len(_maxes):
            return self._len

        idx = id19(self._lists[pos], value)
        return self._loc(pos, idx)

    bisect = id19
    id0 = id19

    def count(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            return 0

        pos_left = id3(_maxes, value)

        if pos_left == len(_maxes):
            return 0

        _lists = self._lists
        idx_left = id3(_lists[pos_left], value)
        pos_right = id19(_maxes, value)

        if pos_right == len(_maxes):
            return self._len - self._loc(pos_left, idx_left)

        idx_right = id19(_lists[pos_right], value)

        if pos_left == pos_right:
            return idx_right - idx_left

        right = self._loc(pos_right, idx_right)
        left = self._loc(pos_left, idx_left)
        return right - left

    def copy(self):
        
        return self.__class__(self)

    id6 = copy

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
        pos_left = id3(_maxes, value)

        if pos_left == len(_maxes):
            raise ValueError('{0!r} is not in list'.format(value))

        _lists = self._lists
        idx_left = id3(_lists[pos_left], value)

        if _lists[pos_left][idx_left] != value:
            raise ValueError('{0!r} is not in list'.format(value))

        stop -= 1
        left = self._loc(pos_left, idx_left)

        if start <= left:
            if left <= stop:
                return left
        else:
            right = self.id0(value) - 1

            if start <= right:
                return start

        raise ValueError('{0!r} is not in list'.format(value))

    def id1(self, other):
        
        values = reduce(iadd, self._lists, [])
        values.extend(other)
        return self.__class__(values)

    id12 = id1

    def id23(self, other):
        
        self._update(other)
        return self

    def id10(self, num):
        
        values = reduce(iadd, self._lists, []) * num
        return self.__class__(values)

    id4 = id10

    def id17(self, num):
        
        values = reduce(iadd, self._lists, []) * num
        self._clear()
        self._update(values)
        return self

    def id27(seq_op, symbol, doc):
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

        id11 = seq_op.__name__
        comparer.__name__ = '__{0}__'.format(id11)
        return comparer

    id9 = id27(eq, '==', 'equal to')
    id16 = id27(ne, '!=', 'not equal to')
    id25 = id27(lt, '<', 'less than')
    id15 = id27(gt, '>', 'greater than')
    id22 = id27(le, '<=', 'less than or equal to')
    id26 = id27(ge, '>=', 'greater than or equal to')
    id27 = staticmethod(id27)

    def id21(self):
        values = reduce(iadd, self._lists, [])
        return (type(self), (values, ))

    @recursive_repr()
    def id13(self):
        
        return '{0}({1!r})'.format(type(self).__name__, list(self))


n = input()
a = [int(x) for x in raw_input().split()]
b = SortedList(int(x) for x in raw_input().split())
res = []
for ai in a:
    it = b.id3(n - ai)
    x = b[0] if it == len(b) else b[it]
    res.append((x + ai) % n)
    b.remove(x)

print ' '.join(str(x) for x in res)
