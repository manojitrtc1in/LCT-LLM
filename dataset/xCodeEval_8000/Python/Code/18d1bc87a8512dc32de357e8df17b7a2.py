

from __future__ import print_function

import sys
import traceback

from bisect import bisect_left, bisect_right, insort
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
else:
    from functools import reduce
    try:
        from _thread import get_ident
    except ImportError:
        from _dummy_thread import get_ident


def recursive_repr(fillvalue='...'):
    "Decorator to make a repr function return fillvalue for a recursive call."
    
    
    

    def decorating_function(user_function):
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

    return decorating_function






class SortedList(MutableSequence):

    DEFAULT_LOAD_FACTOR = 1000


    def __init__(self, iterable=None, key=None):

        assert key is None
        self._len = 0
        self._load = self.DEFAULT_LOAD_FACTOR
        self._lists = []
        self._maxes = []
        self._index = []
        self._offset = 0

        if iterable is not None:
            self._update(iterable)



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
            pos = bisect_right(_maxes, value)

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
        _lists.extend(values[pos:(pos + _load)]
                      for pos in range(0, len(values), _load))
        _maxes.extend(sublist[-1] for sublist in _lists)
        self._len = len(values)
        del self._index[:]

    _update = update


    def __contains__(self, value):

        _maxes = self._maxes

        if not _maxes:
            return False

        pos = bisect_left(_maxes, value)

        if pos == len(_maxes):
            return False

        _lists = self._lists
        idx = bisect_left(_lists[pos], value)

        return _lists[pos][idx] == value


    def discard(self, value):
        """Remove `value` from sorted list if it is a member.
        If `value` is not a member, do nothing.
        Runtime complexity: `O(log(n))` -- approximate.
        >>> sl = SortedList([1, 2, 3, 4, 5])
        >>> sl.discard(5)
        >>> sl.discard(0)
        >>> sl == [1, 2, 3, 4]
        True
        :param value: `value` to discard from sorted list
        """
        _maxes = self._maxes

        if not _maxes:
            return

        pos = bisect_left(_maxes, value)

        if pos == len(_maxes):
            return

        _lists = self._lists
        idx = bisect_left(_lists[pos], value)

        if _lists[pos][idx] == value:
            self._delete(pos, idx)


    def remove(self, value):
        """Remove `value` from sorted list; `value` must be a member.
        If `value` is not a member, raise ValueError.
        Runtime complexity: `O(log(n))` -- approximate.
        >>> sl = SortedList([1, 2, 3, 4, 5])
        >>> sl.remove(5)
        >>> sl == [1, 2, 3, 4]
        True
        >>> sl.remove(0)
        Traceback (most recent call last):
          ...
        ValueError: 0 not in list
        :param value: `value` to remove from sorted list
        :raises ValueError: if `value` is not in sorted list
        """
        _maxes = self._maxes

        if not _maxes:
            raise ValueError('{0!r} not in list'.format(value))

        pos = bisect_left(_maxes, value)

        if pos == len(_maxes):
            raise ValueError('{0!r} not in list'.format(value))

        _lists = self._lists
        idx = bisect_left(_lists[pos], value)

        if _lists[pos][idx] == value:
            self._delete(pos, idx)
        else:
            raise ValueError('{0!r} not in list'.format(value))


    def _delete(self, pos, idx):
        """Delete value at the given `(pos, idx)`.
        Combines lists that are less than half the load level.
        Updates the index when the sublist length is more than half the load
        level. This requires decrementing the nodes in a traversal from the
        leaf node to the root. For an example traversal see
        ``SortedList._loc``.
        :param int pos: lists index
        :param int idx: sublist index
        """
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

            self._expand(prev)
        elif len_lists_pos:
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


    def __delitem__(self, index):

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


    def __getitem__(self, index):

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

    _getitem = __getitem__


    def __setitem__(self, index, value):

        message = 'use ``del sl[index]`` and ``sl.add(value)`` instead'
        raise NotImplementedError(message)


    def __iter__(self):

        return chain.from_iterable(self._lists)


    def __reversed__(self):

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
                return map(_lists[min_pos].__getitem__, indices)

            indices = range(min_idx, max_idx)
            return map(_lists[min_pos].__getitem__, indices)

        next_pos = min_pos + 1

        if next_pos == max_pos:
            if reverse:
                min_indices = range(min_idx, len(_lists[min_pos]))
                max_indices = range(max_idx)
                return chain(
                    map(_lists[max_pos].__getitem__, reversed(max_indices)),
                    map(_lists[min_pos].__getitem__, reversed(min_indices)),
                )

            min_indices = range(min_idx, len(_lists[min_pos]))
            max_indices = range(max_idx)
            return chain(
                map(_lists[min_pos].__getitem__, min_indices),
                map(_lists[max_pos].__getitem__, max_indices),
            )

        if reverse:
            min_indices = range(min_idx, len(_lists[min_pos]))
            sublist_indices = range(next_pos, max_pos)
            sublists = map(_lists.__getitem__, reversed(sublist_indices))
            max_indices = range(max_idx)
            return chain(
                map(_lists[max_pos].__getitem__, reversed(max_indices)),
                chain.from_iterable(map(reversed, sublists)),
                map(_lists[min_pos].__getitem__, reversed(min_indices)),
            )

        min_indices = range(min_idx, len(_lists[min_pos]))
        sublist_indices = range(next_pos, max_pos)
        sublists = map(_lists.__getitem__, sublist_indices)
        max_indices = range(max_idx)
        return chain(
            map(_lists[min_pos].__getitem__, min_indices),
            chain.from_iterable(sublists),
            map(_lists[max_pos].__getitem__, max_indices),
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
                min_pos = bisect_left(_maxes, minimum)

                if min_pos == len(_maxes):
                    return iter(())

                min_idx = bisect_left(_lists[min_pos], minimum)
            else:
                min_pos = bisect_right(_maxes, minimum)

                if min_pos == len(_maxes):
                    return iter(())

                min_idx = bisect_right(_lists[min_pos], minimum)

        
        

        if maximum is None:
            max_pos = len(_maxes) - 1
            max_idx = len(_lists[max_pos])
        else:
            if inclusive[1]:
                max_pos = bisect_right(_maxes, maximum)

                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_lists[max_pos])
                else:
                    max_idx = bisect_right(_lists[max_pos], maximum)
            else:
                max_pos = bisect_left(_maxes, maximum)

                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_lists[max_pos])
                else:
                    max_idx = bisect_left(_lists[max_pos], maximum)

        return self._islice(min_pos, min_idx, max_pos, max_idx, reverse)


    def __len__(self):

        return self._len


    def bisect_left(self, value):

        _maxes = self._maxes

        if not _maxes:
            return 0

        pos = bisect_left(_maxes, value)

        if pos == len(_maxes):
            return self._len

        idx = bisect_left(self._lists[pos], value)
        return self._loc(pos, idx)


    def bisect_right(self, value):

        _maxes = self._maxes

        if not _maxes:
            return 0

        pos = bisect_right(_maxes, value)

        if pos == len(_maxes):
            return self._len

        idx = bisect_right(self._lists[pos], value)
        return self._loc(pos, idx)

    bisect = bisect_right
    _bisect_right = bisect_right


    def count(self, value):

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

        return self.__class__(self)

    __copy__ = copy


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
            right = self._bisect_right(value) - 1

            if start <= right:
                return start

        raise ValueError('{0!r} is not in list'.format(value))


    def __add__(self, other):

        values = reduce(iadd, self._lists, [])
        values.extend(other)
        return self.__class__(values)

    __radd__ = __add__


    def __iadd__(self, other):

        self._update(other)
        return self


    def __mul__(self, num):

        values = reduce(iadd, self._lists, []) * num
        return self.__class__(values)

    __rmul__ = __mul__


    def __imul__(self, num):

        values = reduce(iadd, self._lists, []) * num
        self._clear()
        self._update(values)
        return self


    def __make_cmp(seq_op, symbol, doc):

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

        seq_op_name = seq_op.__name__
        comparer.__name__ = '__{0}__'.format(seq_op_name)
        doc_str = ""
        comparer.__doc__ = dedent(doc_str.format(doc, seq_op_name, symbol))
        return comparer


    __eq__ = __make_cmp(eq, '==', 'equal to')
    __ne__ = __make_cmp(ne, '!=', 'not equal to')
    __lt__ = __make_cmp(lt, '<', 'less than')
    __gt__ = __make_cmp(gt, '>', 'greater than')
    __le__ = __make_cmp(le, '<=', 'less than or equal to')
    __ge__ = __make_cmp(ge, '>=', 'greater than or equal to')
    __make_cmp = staticmethod(__make_cmp)


    def __reduce__(self):
        values = reduce(iadd, self._lists, [])
        return (type(self), (values,))


    @recursive_repr()
    def __repr__(self):

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


def identity(value):
    "Identity function."
    return value
from itertools import chain
from operator import eq, ne, gt, ge, lt, le
from textwrap import dedent







try:
    from collections.abc import MutableSet, Sequence, Set
except ImportError:
    from collections import MutableSet, Sequence, Set






class SortedSet(MutableSet, Sequence):

    def __init__(self, iterable=None, key=None):
        self._key = key

        
        
        

        if not hasattr(self, '_set'):
            self._set = set()

        self._list = SortedList(self._set, key=key)

        

        _set = self._set
        self.isdisjoint = _set.isdisjoint
        self.issubset = _set.issubset
        self.issuperset = _set.issuperset

        

        _list = self._list
        self.bisect_left = _list.bisect_left
        self.bisect = _list.bisect
        self.bisect_right = _list.bisect_right
        self.index = _list.index
        self.irange = _list.irange
        self.islice = _list.islice
        self._reset = _list._reset

        if key is not None:
            self.bisect_key_left = _list.bisect_key_left
            self.bisect_key_right = _list.bisect_key_right
            self.bisect_key = _list.bisect_key
            self.irange_key = _list.irange_key

        if iterable is not None:
            self._update(iterable)


    @classmethod
    def _fromset(cls, values, key=None):
        """Initialize sorted set from existing set.
        Used internally by set operations that return a new set.
        """
        sorted_set = object.__new__(cls)
        sorted_set._set = values
        sorted_set.__init__(key=key)
        return sorted_set


    @property
    def key(self):
        """Function used to extract comparison key from values.
        Sorted set compares values directly when the key function is none.
        """
        return self._key


    def __contains__(self, value):
        return value in self._set


    def __getitem__(self, index):

        return self._list[index]


    def __delitem__(self, index):
        _set = self._set
        _list = self._list
        if isinstance(index, slice):
            values = _list[index]
            _set.difference_update(values)
        else:
            value = _list[index]
            _set.remove(value)
        del _list[index]


    def __make_cmp(set_op, symbol, doc):
        "Make comparator method."
        def comparer(self, other):
            "Compare method for sorted set and set."
            if isinstance(other, SortedSet):
                return set_op(self._set, other._set)
            elif isinstance(other, Set):
                return set_op(self._set, other)
            return NotImplemented

        set_op_name = set_op.__name__
        comparer.__name__ = '__{0}__'.format(set_op_name)
        doc_str = ""
        comparer.__doc__ = dedent(doc_str.format(doc, set_op_name, symbol))
        return comparer


    __eq__ = __make_cmp(eq, '==', 'equal to')
    __ne__ = __make_cmp(ne, '!=', 'not equal to')
    __lt__ = __make_cmp(lt, '<', 'a proper subset of')
    __gt__ = __make_cmp(gt, '>', 'a proper superset of')
    __le__ = __make_cmp(le, '<=', 'a subset of')
    __ge__ = __make_cmp(ge, '>=', 'a superset of')
    __make_cmp = staticmethod(__make_cmp)


    def __len__(self):

        return len(self._set)


    def __iter__(self):

        return iter(self._list)


    def __reversed__(self):

        return reversed(self._list)


    def add(self, value):

        _set = self._set
        if value not in _set:
            _set.add(value)
            self._list.add(value)

    _add = add


    def clear(self):

        self._set.clear()
        self._list.clear()


    def copy(self):

        return self._fromset(set(self._set), key=self._key)

    __copy__ = copy


    def count(self, value):

        return 1 if value in self._set else 0


    def discard(self, value):

        _set = self._set
        if value in _set:
            _set.remove(value)
            self._list.remove(value)

    _discard = discard


    def pop(self, index=-1):

        
        value = self._list.pop(index)
        self._set.remove(value)
        return value


    def remove(self, value):

        self._set.remove(value)
        self._list.remove(value)


    def difference(self, *iterables):

        diff = self._set.difference(*iterables)
        return self._fromset(diff, key=self._key)

    __sub__ = difference


    def difference_update(self, *iterables):

        _set = self._set
        _list = self._list
        values = set(chain(*iterables))
        if (4 * len(values)) > len(_set):
            _set.difference_update(values)
            _list.clear()
            _list.update(_set)
        else:
            _discard = self._discard
            for value in values:
                _discard(value)
        return self

    __isub__ = difference_update


    def intersection(self, *iterables):

        intersect = self._set.intersection(*iterables)
        return self._fromset(intersect, key=self._key)

    __and__ = intersection
    __rand__ = __and__


    def intersection_update(self, *iterables):

        _set = self._set
        _list = self._list
        _set.intersection_update(*iterables)
        _list.clear()
        _list.update(_set)
        return self

    __iand__ = intersection_update


    def symmetric_difference(self, other):

        diff = self._set.symmetric_difference(other)
        return self._fromset(diff, key=self._key)

    __xor__ = symmetric_difference
    __rxor__ = __xor__


    def symmetric_difference_update(self, other):

        _set = self._set
        _list = self._list
        _set.symmetric_difference_update(other)
        _list.clear()
        _list.update(_set)
        return self

    __ixor__ = symmetric_difference_update


    def union(self, *iterables):

        return self.__class__(chain(iter(self), *iterables), key=self._key)

    __or__ = union
    __ror__ = __or__


    def update(self, *iterables):

        _set = self._set
        _list = self._list
        values = set(chain(*iterables))
        if (4 * len(values)) > len(_set):
            _list = self._list
            _set.update(values)
            _list.clear()
            _list.update(_set)
        else:
            _add = self._add
            for value in values:
                _add(value)
        return self

    __ior__ = update
    _update = update


    def __reduce__(self):

        return (type(self), (self._set, self._key))


    @recursive_repr()
    def __repr__(self):

        _key = self._key
        key = '' if _key is None else ', key={0!r}'.format(_key)
        type_name = type(self).__name__
        return '{0}({1!r}{2})'.format(type_name, list(self), key)


    def _check(self):

        _set = self._set
        _list = self._list
        _list._check()
        assert len(_set) == len(_list)
        assert all(value in _set for value in _list)
import math
import heapq,bisect
import sys
from collections import deque,defaultdict
from fractions import Fraction
mod=10**9+7
mod1=998244353

import os
import sys
from io import BytesIO, IOBase

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
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

class SegmentTree1:
    def __init__(self, data, default=9999999, func=lambda a, b: min(a , b)):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def __delitem__(self, idx):
        self[idx] = self._default

    def __getitem__(self, idx):
        return self.data[idx + self._size]

    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def __len__(self):
        return self._len

    def query(self, start, stop):
        if start == stop:
            return self.__getitem__(start)
        stop += 1
        start += self._size
        stop += self._size

        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res

    def __repr__(self):
        return "SegmentTree({0})".format(self.data)


class SegmentTree:
    def __init__(self, data, default=0, func=lambda a, b: a + b):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def __delitem__(self, idx):
        self[idx] = self._default

    def __getitem__(self, idx):
        return self.data[idx + self._size]

    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def __len__(self):
        return self._len

    def query(self, start, stop):
        if start == stop:
            return self.__getitem__(start)
        stop += 1
        start += self._size
        stop += self._size

        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res

    def __repr__(self):
        return "SegmentTree({0})".format(self.data)

class Factorial:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorials = [1, 1]
        self.invModulos = [0, 1]
        self.invFactorial_ = [1, 1]

    def calc(self, n):
        if n <= -1:
            print("Invalid argument to calculate n!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.factorials):
            return self.factorials[n]
        nextArr = [0] * (n + 1 - len(self.factorials))
        initialI = len(self.factorials)
        prev = self.factorials[-1]
        m = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = prev * i % m
        self.factorials += nextArr
        return self.factorials[n]

    def inv(self, n):
        if n <= -1:
            print("Invalid argument to calculate n^(-1)")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        p = self.MOD
        pi = n % p
        if pi < len(self.invModulos):
            return self.invModulos[pi]
        nextArr = [0] * (n + 1 - len(self.invModulos))
        initialI = len(self.invModulos)
        for i in range(initialI, min(p, n + 1)):
            next = -self.invModulos[p % i] * (p // i) % p
            self.invModulos.append(next)
        return self.invModulos[pi]

    def invFactorial(self, n):
        if n <= -1:
            print("Invalid argument to calculate (n^(-1))!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.invFactorial_):
            return self.invFactorial_[n]
        self.inv(n)  
        nextArr = [0] * (n + 1 - len(self.invFactorial_))
        initialI = len(self.invFactorial_)
        prev = self.invFactorial_[-1]
        p = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = (prev * self.invModulos[i % p]) % p
        self.invFactorial_ += nextArr
        return self.invFactorial_[n]


class Combination:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorial = Factorial(MOD)

    def ncr(self, n, k):
        if k < 0 or n < k:
            return 0
        k = min(k, n - k)
        f = self.factorial
        return f.calc(n) * f.invFactorial(max(n - k, k)) * f.invFactorial(min(k, n - k)) % self.MOD

def powm(a, n, m):
    if a == 1 or n == 0:
        return 1
    if n % 2 == 0:
        s = powm(a, n // 2, m)
        return s * s % m
    else:
        return a * powm(a, n - 1, m) % m

def sort_list(list1, list2):
    zipped_pairs = zip(list2, list1)

    z = [x for _, x in sorted(zipped_pairs)]

    return z

def product(l):
    por=1
    for i in range(len(l)):
        por*=l[i]
    return por

def binarySearchCount(arr, n, key):
    left = 0
    right = n - 1

    count = 0

    while (left <= right):
        mid = int((right + left) / 2)

        
        
        if (arr[mid] <= key):

            
            
            
            count = mid + 1
            left = mid + 1

        
        else:
            right = mid - 1

    return count

def countdig(n):
    c=0
    while(n>0):
        n//=10
        c+=1
    return c
def countGreater(arr, n, k):
    l = 0
    r = n - 1

    
    
    leftGreater = n

    
    while (l <= r):
        m = int(l + (r - l) / 2)

        
        
        if (arr[m] > k):
            leftGreater = m
            r = m - 1

        
        
        else:
            l = m + 1

    
    
    return (n - leftGreater)

for i in range(int(input())):
    a,b=map(int,input().split())
    s=SortedList([a,b])
    print(s[0]+s[1])