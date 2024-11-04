from __future__ import print_function
from sys import stdin,stdout
import sys
import traceback

from bisect import id3, id27, insort
from itertools import chain, repeat, starmap
from math import log
from operator import add, eq, ne, gt, ge, lt, le, iadd
from textwrap import dedent

try:
    from collections.abc import Sequence, MutableSequence
except ImportError:
    from collections import Sequence, MutableSequence

from functools import wraps
from sys import hexversion

if hexversion < 0x03000000:
    from itertools import imap as map  
    from itertools import izip as zip  
    try:
        from thread import get_ident
    except ImportError:
        from dummy_thread import get_ident
else:
    from functools import reduce
    try:
        from _thread import get_ident
    except ImportError:
        from _dummy_thread import get_ident


def recursive_repr(fillvalue='...'):
    "Decorator to make a repr function return fillvalue for a recursive call."
    
    
    

    def id11(user_function):
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

    return id11
class SortedList(MutableSequence):
    
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


    def id10(cls, iterable=None, key=None):
        
        
        if key is None:
            return object.id10(cls)
        else:
            if cls is SortedList:
                return object.id10(id8)
            else:
                raise TypeError('inherit id8 for key argument')


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
            pos = id27(_maxes, value)

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

        pos = id3(_maxes, value)

        if pos == len(_maxes):
            return False

        _lists = self._lists
        idx = id3(_lists[pos], value)

        return _lists[pos][idx] == value


    def discard(self, value):
        
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


    def remove(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            raise ValueError('{0!r} not in list'.format(value))

        pos = id3(_maxes, value)

        if pos == len(_maxes):
            raise ValueError('{0!r} not in list'.format(value))

        _lists = self._lists
        idx = id3(_lists[pos], value)

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


    def id26(self, index):
        
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


    def id28(self, index):
        
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

    _getitem = id28


    def id24(self, index, value):
        
        message = 'use ``del sl[index]`` and ``sl.add(value)`` instead'
        raise NotImplementedError(message)


    def id41(self):
        
        return chain.from_iterable(self._lists)


    def id36(self):
        
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
                return map(_lists[min_pos].id28, indices)

            indices = range(min_idx, max_idx)
            return map(_lists[min_pos].id28, indices)

        next_pos = min_pos + 1

        if next_pos == max_pos:
            if reverse:
                min_indices = range(min_idx, len(_lists[min_pos]))
                max_indices = range(max_idx)
                return chain(
                    map(_lists[max_pos].id28, reversed(max_indices)),
                    map(_lists[min_pos].id28, reversed(min_indices)),
                )

            min_indices = range(min_idx, len(_lists[min_pos]))
            max_indices = range(max_idx)
            return chain(
                map(_lists[min_pos].id28, min_indices),
                map(_lists[max_pos].id28, max_indices),
            )

        if reverse:
            min_indices = range(min_idx, len(_lists[min_pos]))
            id34 = range(next_pos, max_pos)
            id22 = map(_lists.id28, reversed(id34))
            max_indices = range(max_idx)
            return chain(
                map(_lists[max_pos].id28, reversed(max_indices)),
                chain.from_iterable(map(reversed, id22)),
                map(_lists[min_pos].id28, reversed(min_indices)),
            )

        min_indices = range(min_idx, len(_lists[min_pos]))
        id34 = range(next_pos, max_pos)
        id22 = map(_lists.id28, id34)
        max_indices = range(max_idx)
        return chain(
            map(_lists[min_pos].id28, min_indices),
            chain.from_iterable(id22),
            map(_lists[max_pos].id28, max_indices),
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
                min_pos = id3(_maxes, minimum)

                if min_pos == len(_maxes):
                    return iter(())

                min_idx = id3(_lists[min_pos], minimum)
            else:
                min_pos = id27(_maxes, minimum)

                if min_pos == len(_maxes):
                    return iter(())

                min_idx = id27(_lists[min_pos], minimum)

        
        

        if maximum is None:
            max_pos = len(_maxes) - 1
            max_idx = len(_lists[max_pos])
        else:
            if inclusive[1]:
                max_pos = id27(_maxes, maximum)

                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_lists[max_pos])
                else:
                    max_idx = id27(_lists[max_pos], maximum)
            else:
                max_pos = id3(_maxes, maximum)

                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_lists[max_pos])
                else:
                    max_idx = id3(_lists[max_pos], maximum)

        return self._islice(min_pos, min_idx, max_pos, max_idx, reverse)


    def id42(self):
        
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


    def id27(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            return 0

        pos = id27(_maxes, value)

        if pos == len(_maxes):
            return self._len

        idx = id27(self._lists[pos], value)
        return self._loc(pos, idx)

    bisect = id27
    id0 = id27


    def count(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            return 0

        pos_left = id3(_maxes, value)

        if pos_left == len(_maxes):
            return 0

        _lists = self._lists
        idx_left = id3(_lists[pos_left], value)
        pos_right = id27(_maxes, value)

        if pos_right == len(_maxes):
            return self._len - self._loc(pos_left, idx_left)

        idx_right = id27(_lists[pos_right], value)

        if pos_left == pos_right:
            return idx_right - idx_left

        right = self._loc(pos_right, idx_right)
        left = self._loc(pos_left, idx_left)
        return right - left


    def copy(self):
        
        return self.__class__(self)

    id6 = copy


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

    id15 = id1


    def id32(self, other):
        
        self._update(other)
        return self


    def id13(self, num):
        
        values = reduce(iadd, self._lists, []) * num
        return self.__class__(values)

    id4 = id13


    def id23(self, num):
        
        values = reduce(iadd, self._lists, []) * num
        self._clear()
        self._update(values)
        return self


    def id40(seq_op, symbol, doc):
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


    id12 = id40(eq, '==', 'equal to')
    id21 = id40(ne, '!=', 'not equal to')
    id38 = id40(lt, '<', 'less than')
    id18 = id40(gt, '>', 'greater than')
    id30 = id40(le, '<=', 'less than or equal to')
    id39 = id40(ge, '>=', 'greater than or equal to')
    id40 = staticmethod(id40)


    def id29(self):
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
            
            raise


def identity(value):
    "Identity function."
    return value


class id8(SortedList):
    
    def __init__(self, iterable=None, key=identity):
        
        self._key = key
        self._len = 0
        self._load = self.id2
        self._lists = []
        self._keys = []
        self._maxes = []
        self._index = []
        self._offset = 0

        if iterable is not None:
            self._update(iterable)


    def id10(cls, iterable=None, key=identity):
        return object.id10(cls)


    @property
    def key(self):
        
        return self._key


    def clear(self):
        
        self._len = 0
        del self._lists[:]
        del self._keys[:]
        del self._maxes[:]
        del self._index[:]

    _clear = clear


    def add(self, value):
        
        _lists = self._lists
        _keys = self._keys
        _maxes = self._maxes

        key = self._key(value)

        if _maxes:
            pos = id27(_maxes, key)

            if pos == len(_maxes):
                pos -= 1
                _lists[pos].append(value)
                _keys[pos].append(key)
                _maxes[pos] = key
            else:
                idx = id27(_keys[pos], key)
                _lists[pos].insert(idx, value)
                _keys[pos].insert(idx, key)

            self._expand(pos)
        else:
            _lists.append([value])
            _keys.append([key])
            _maxes.append(key)

        self._len += 1


    def _expand(self, pos):
        
        _lists = self._lists
        _keys = self._keys
        _index = self._index

        if len(_keys[pos]) > (self._load << 1):
            _maxes = self._maxes
            _load = self._load

            _lists_pos = _lists[pos]
            _keys_pos = _keys[pos]
            half = _lists_pos[_load:]
            half_keys = _keys_pos[_load:]
            del _lists_pos[_load:]
            del _keys_pos[_load:]
            _maxes[pos] = _keys_pos[-1]

            _lists.insert(pos + 1, half)
            _keys.insert(pos + 1, half_keys)
            _maxes.insert(pos + 1, half_keys[-1])

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
        _keys = self._keys
        _maxes = self._maxes
        values = sorted(iterable, key=self._key)

        if _maxes:
            if len(values) * 4 >= self._len:
                _lists.append(values)
                values = reduce(iadd, _lists, [])
                values.sort(key=self._key)
                self._clear()
            else:
                _add = self.add
                for val in values:
                    _add(val)
                return

        _load = self._load
        _lists.extend(values[pos:(pos + _load)]
                      for pos in range(0, len(values), _load))
        _keys.extend(list(map(self._key, _list)) for _list in _lists)
        _maxes.extend(sublist[-1] for sublist in _keys)
        self._len = len(values)
        del self._index[:]

    _update = update


    def id17(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            return False

        key = self._key(value)
        pos = id3(_maxes, key)

        if pos == len(_maxes):
            return False

        _lists = self._lists
        _keys = self._keys

        idx = id3(_keys[pos], key)

        len_keys = len(_keys)
        id9 = len(_keys[pos])

        while True:
            if _keys[pos][idx] != key:
                return False
            if _lists[pos][idx] == value:
                return True
            idx += 1
            if idx == id9:
                pos += 1
                if pos == len_keys:
                    return False
                id9 = len(_keys[pos])
                idx = 0


    def discard(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            return

        key = self._key(value)
        pos = id3(_maxes, key)

        if pos == len(_maxes):
            return

        _lists = self._lists
        _keys = self._keys
        idx = id3(_keys[pos], key)
        len_keys = len(_keys)
        id9 = len(_keys[pos])

        while True:
            if _keys[pos][idx] != key:
                return
            if _lists[pos][idx] == value:
                self._delete(pos, idx)
                return
            idx += 1
            if idx == id9:
                pos += 1
                if pos == len_keys:
                    return
                id9 = len(_keys[pos])
                idx = 0


    def remove(self, value):
        
        _maxes = self._maxes

        if not _maxes:
            raise ValueError('{0!r} not in list'.format(value))

        key = self._key(value)
        pos = id3(_maxes, key)

        if pos == len(_maxes):
            raise ValueError('{0!r} not in list'.format(value))

        _lists = self._lists
        _keys = self._keys
        idx = id3(_keys[pos], key)
        len_keys = len(_keys)
        id9 = len(_keys[pos])

        while True:
            if _keys[pos][idx] != key:
                raise ValueError('{0!r} not in list'.format(value))
            if _lists[pos][idx] == value:
                self._delete(pos, idx)
                return
            idx += 1
            if idx == id9:
                pos += 1
                if pos == len_keys:
                    raise ValueError('{0!r} not in list'.format(value))
                id9 = len(_keys[pos])
                idx = 0


    def _delete(self, pos, idx):
        
        _lists = self._lists
        _keys = self._keys
        _maxes = self._maxes
        _index = self._index
        keys_pos = _keys[pos]
        lists_pos = _lists[pos]

        del keys_pos[idx]
        del lists_pos[idx]
        self._len -= 1

        id19 = len(keys_pos)

        if id19 > (self._load >> 1):
            _maxes[pos] = keys_pos[-1]

            if _index:
                child = self._offset + pos
                while child > 0:
                    _index[child] -= 1
                    child = (child - 1) >> 1
                _index[0] -= 1
        elif len(_keys) > 1:
            if not pos:
                pos += 1

            prev = pos - 1
            _keys[prev].extend(_keys[pos])
            _lists[prev].extend(_lists[pos])
            _maxes[prev] = _keys[prev][-1]

            del _lists[pos]
            del _keys[pos]
            del _maxes[pos]
            del _index[:]

            self._expand(prev)
        elif id19:
            _maxes[pos] = keys_pos[-1]
        else:
            del _lists[pos]
            del _keys[pos]
            del _maxes[pos]
            del _index[:]


    def irange(self, minimum=None, maximum=None, inclusive=(True, True),
               reverse=False):
        
        min_key = self._key(minimum) if minimum is not None else None
        max_key = self._key(maximum) if maximum is not None else None
        return self.id7(
            min_key=min_key, max_key=max_key,
            inclusive=inclusive, reverse=reverse,
        )


    def id31(self, min_key=None, max_key=None, inclusive=(True, True),
                   reverse=False):
        
        _maxes = self._maxes

        if not _maxes:
            return iter(())

        _keys = self._keys

        if min_key is None:
            min_pos = 0
            min_idx = 0
        else:
            if inclusive[0]:
                min_pos = id3(_maxes, min_key)

                if min_pos == len(_maxes):
                    return iter(())

                min_idx = id3(_keys[min_pos], min_key)
            else:
                min_pos = id27(_maxes, min_key)

                if min_pos == len(_maxes):
                    return iter(())

                min_idx = id27(_keys[min_pos], min_key)

        

        if max_key is None:
            max_pos = len(_maxes) - 1
            max_idx = len(_keys[max_pos])
        else:
            if inclusive[1]:
                max_pos = id27(_maxes, max_key)

                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_keys[max_pos])
                else:
                    max_idx = id27(_keys[max_pos], max_key)
            else:
                max_pos = id3(_maxes, max_key)

                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_keys[max_pos])
                else:
                    max_idx = id3(_keys[max_pos], max_key)

        return self._islice(min_pos, min_idx, max_pos, max_idx, reverse)

    id7 = id31


    def id3(self, value):
        return self.id37(self._key(value))


    def id27(self, value):
        return self.id35(self._key(value))

    bisect = id27


    def id25(self, key):
        _maxes = self._maxes

        if not _maxes:
            return 0

        pos = id3(_maxes, key)

        if pos == len(_maxes):
            return self._len

        idx = id3(self._keys[pos], key)

        return self._loc(pos, idx)

    id37 = id25


    def id33(self, key):
        _maxes = self._maxes

        if not _maxes:
            return 0

        pos = id27(_maxes, key)

        if pos == len(_maxes):
            return self._len

        idx = id27(self._keys[pos], key)

        return self._loc(pos, idx)

    id20 = id33
    id35 = id33


    def count(self, value):
        _maxes = self._maxes

        if not _maxes:
            return 0

        key = self._key(value)
        pos = id3(_maxes, key)

        if pos == len(_maxes):
            return 0

        _lists = self._lists
        _keys = self._keys
        idx = id3(_keys[pos], key)
        total = 0
        len_keys = len(_keys)
        id9 = len(_keys[pos])

        while True:
            if _keys[pos][idx] != key:
                return total
            if _lists[pos][idx] == value:
                total += 1
            idx += 1
            if idx == id9:
                pos += 1
                if pos == len_keys:
                    return total
                id9 = len(_keys[pos])
                idx = 0


    def copy(self):
        return self.__class__(self, key=self._key)

    id6 = copy


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
        key = self._key(value)
        pos = id3(_maxes, key)

        if pos == len(_maxes):
            raise ValueError('{0!r} is not in list'.format(value))

        stop -= 1
        _lists = self._lists
        _keys = self._keys
        idx = id3(_keys[pos], key)
        len_keys = len(_keys)
        id9 = len(_keys[pos])

        while True:
            if _keys[pos][idx] != key:
                raise ValueError('{0!r} is not in list'.format(value))
            if _lists[pos][idx] == value:
                loc = self._loc(pos, idx)
                if start <= loc <= stop:
                    return loc
                elif loc > stop:
                    break
            idx += 1
            if idx == id9:
                pos += 1
                if pos == len_keys:
                    raise ValueError('{0!r} is not in list'.format(value))
                id9 = len(_keys[pos])
                idx = 0

        raise ValueError('{0!r} is not in list'.format(value))


    def id1(self, other):
        values = reduce(iadd, self._lists, [])
        values.extend(other)
        return self.__class__(values, key=self._key)

    id15 = id1


    def id13(self, num):
        values = reduce(iadd, self._lists, []) * num
        return self.__class__(values, key=self._key)


    def id29(self):
        values = reduce(iadd, self._lists, [])
        return (type(self), (values, self.key))


    @recursive_repr()
    def id16(self):
        type_name = type(self).__name__
        return '{0}({1!r}, key={2!r})'.format(type_name, list(self), self._key)


    def _check(self):
        try:
            assert self._load >= 4
            assert len(self._maxes) == len(self._lists) == len(self._keys)
            assert self._len == sum(len(sublist) for sublist in self._lists)


            for sublist in self._keys:
                for pos in range(1, len(sublist)):
                    assert sublist[pos - 1] <= sublist[pos]
            for pos in range(1, len(self._keys)):
                assert self._keys[pos - 1][-1] <= self._keys[pos][0]

            for val_sublist, key_sublist in zip(self._lists, self._keys):
                assert len(val_sublist) == len(key_sublist)
                for val, key in zip(val_sublist, key_sublist):
                    assert self._key(val) == key

            for pos in range(len(self._maxes)):
                assert self._maxes[pos] == self._keys[pos][-1]

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
from sys import stdin,stdout
def comp(M,l,r):
    i=len(r)-1
    while i>=0:
        pos=l.id3(r[i])
        if pos==len(l):
            i-=1
            continue
        val=(l[pos]-r[i])//2
        ans[m[l[pos]]]=val
        ans[m[r[i]]]=val
        l.pop(pos)
        r.pop(i)
        i-=1
    while len(l)>1:
        x1=l.pop(0)
        x2=l.pop(0)
        val=(x1+x2)//2
        ans[m[x1]]=val
        ans[m[x2]]=val
    while len(r)>1:
        x1=r.pop()
        x2=r.pop()
        val=(M-x1+M-x2)//2
        ans[m[x1]]=val
        ans[m[x2]]=val
    if len(l)==1 and len(r)==1:
        x1=l.pop()
        x3=r.pop()
        x2=M-x3
        common=max(x1,x2)
        pos1=common-x1
        pos2=M-(common-x2)
        tot=common+(pos2-pos1)//2
        ans[m[x1]]=tot
        ans[m[x3]]=tot
for _ in range(int(stdin.readline())):
    n,M=[int(i) for i in stdin.readline().split()]
    a=[int(i) for i in stdin.readline().split()]
    s=[i for i in stdin.readline().split()]
    al=SortedList()
    bl=SortedList()
    ar=SortedList()
    br=SortedList()
    m={}
    ans=[-1 for i in range(n)]
    for i in range(n):
        m[a[i]]=i
        if a[i]%2==0:
            if s[i]=='L':
                al.add(a[i])
            else:
                ar.add(a[i])
        else:
            if s[i]=='L':
                bl.add(a[i])
            else:
                br.add(a[i])
    comp(M,al,ar)
    comp(M,bl,br)
    for i in ans:
        sys.stdout.write(str(i)+" ")
    sys.stdout.write("\n")
                
