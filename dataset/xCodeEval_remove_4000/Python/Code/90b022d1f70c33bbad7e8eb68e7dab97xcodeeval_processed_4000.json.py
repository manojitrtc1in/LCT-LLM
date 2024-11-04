
from __future__ import print_function
from bisect import id2, id22, insort
from collections import Sequence, MutableSequence
from functools import wraps
from itertools import chain, repeat, starmap
from math import log as log_e
import operator as op
from operator import iadd, add
from functools import reduce
from _dummy_thread import get_ident

def recursive_repr(func):
    repr_running = set()
    @wraps(func)
    def wrapper(self):
        "Return ellipsis on recursive re-entry to function."
        key = id(self), get_ident()
        if key in repr_running:
            return '...'
        repr_running.add(key)
        try:
            return func(self)
        finally:
            repr_running.discard(key)
    return wrapper
class SortedList(MutableSequence):
    def __init__(self, iterable=None, load=1000):
        self._len = 0
        self._lists = []
        self._maxes = []
        self._index = []
        self._load = load
        self._twice = load * 2
        self._half = load >> 1
        self._offset = 0
        if iterable is not None:
            self._update(iterable)
    def id8(cls, iterable=None, key=None, load=1000):
        if key is None:
            return object.id8(cls)
        else:
            if cls is SortedList:
                return id7(iterable=iterable, key=key, load=load)
            else:
                raise TypeError('inherit id7 for key argument')
    def clear(self):
        self._len = 0
        del self._lists[:]
        del self._maxes[:]
        del self._index[:]
    _clear = clear
    def add(self, val):
        _lists = self._lists
        _maxes = self._maxes
        if _maxes:
            pos = id22(_maxes, val)
            if pos == len(_maxes):
                pos -= 1
                _lists[pos].append(val)
                _maxes[pos] = val
            else:
                insort(_lists[pos], val)
            self._expand(pos)
        else:
            _lists.append([val])
            _maxes.append(val)
        self._len += 1
    def _expand(self, pos):
        _lists = self._lists
        _index = self._index
        if len(_lists[pos]) > self._twice:
            _maxes = self._maxes
            _load = self._load
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
    def id12(self, val):
        _maxes = self._maxes
        if not _maxes:
            return False
        pos = id2(_maxes, val)
        if pos == len(_maxes):
            return False
        _lists = self._lists
        idx = id2(_lists[pos], val)
        return _lists[pos][idx] == val
    def discard(self, val):
        _maxes = self._maxes
        if not _maxes:
            return
        pos = id2(_maxes, val)
        if pos == len(_maxes):
            return
        _lists = self._lists
        idx = id2(_lists[pos], val)
        if _lists[pos][idx] == val:
            self._delete(pos, idx)
    def remove(self, val):
        _maxes = self._maxes
        if not _maxes:
            raise ValueError('{0} not in list'.format(repr(val)))
        pos = id2(_maxes, val)
        if pos == len(_maxes):
            raise ValueError('{0} not in list'.format(repr(val)))
        _lists = self._lists
        idx = id2(_lists[pos], val)
        if _lists[pos][idx] == val:
            self._delete(pos, idx)
        else:
            raise ValueError('{0} not in list'.format(repr(val)))
    def _delete(self, pos, idx):
        _lists = self._lists
        _maxes = self._maxes
        _index = self._index
        _lists_pos = _lists[pos]
        del _lists_pos[idx]
        self._len -= 1
        id3 = len(_lists_pos)
        if id3 > self._half:
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
        elif id3:
            _maxes[pos] = _lists_pos[-1]
        else:
            del _lists[pos]
            del _maxes[pos]
            del _index[:]
    def _loc(self, pos, idx):
        if not pos:
            return idx
        _index = self._index
        if not len(_index):
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
        size = 2 ** (int(log_e(len(row1) - 1, 2)) + 1)
        row1.extend(repeat(0, size - len(row1)))
        tree = [row0, row1]
        while len(tree[-1]) > 1:
            head = iter(tree[-1])
            tail = iter(head)
            row = list(starmap(add, zip(head, tail)))
            tree.append(row)
        reduce(iadd, reversed(tree), self._index)
        self._offset = size * 2 - 1
    def id21(self, idx):
        if isinstance(idx, slice):
            start, stop, step = idx.indices(self._len)
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
            pos, idx = self._pos(idx)
            self._delete(pos, idx)
    _delitem = id21
    def id23(self, idx):
        _lists = self._lists
        if isinstance(idx, slice):
            start, stop, step = idx.indices(self._len)
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
                if idx == 0:
                    return _lists[0][0]
                elif idx == -1:
                    return _lists[-1][-1]
            else:
                raise IndexError('list index out of range')
            if 0 <= idx < len(_lists[0]):
                return _lists[0][idx]
            len_last = len(_lists[-1])
            if -len_last < idx < 0:
                return _lists[-1][len_last + idx]
            pos, idx = self._pos(idx)
            return _lists[pos][idx]
    _getitem = id23
    def _check_order(self, idx, val):
        _len = self._len
        _lists = self._lists
        pos, loc = self._pos(idx)
        if idx < 0:
            idx += _len
        
        
        if idx > 0:
            idx_prev = loc - 1
            pos_prev = pos
            if idx_prev < 0:
                pos_prev -= 1
                idx_prev = len(_lists[pos_prev]) - 1
            if _lists[pos_prev][idx_prev] > val:
                msg = '{0} not in sort order at index {1}'.format(repr(val), idx)
                raise ValueError(msg)
        
        
        if idx < (_len - 1):
            idx_next = loc + 1
            pos_next = pos
            if idx_next == len(_lists[pos_next]):
                pos_next += 1
                idx_next = 0
            if _lists[pos_next][idx_next] < val:
                msg = '{0} not in sort order at index {1}'.format(repr(val), idx)
                raise ValueError(msg)
    def id19(self, index, value):
        _lists = self._lists
        _maxes = self._maxes
        _check_order = self._check_order
        _pos = self._pos
        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)
            indices = range(start, stop, step)
            if step != 1:
                if not hasattr(value, 'id34'):
                    value = list(value)
                indices = list(indices)
                if len(value) != len(indices):
                    raise ValueError(
                        'attempt to assign sequence of size {0}'
                        ' to extended slice of size {1}'
                        .format(len(value), len(indices)))
                
                
                log = []
                _append = log.append
                for idx, val in zip(indices, value):
                    pos, loc = _pos(idx)
                    _append((idx, _lists[pos][loc], val))
                    _lists[pos][loc] = val
                    if len(_lists[pos]) == (loc + 1):
                        _maxes[pos] = val
                try:
                    
                    for idx, oldval, newval in log:
                        _check_order(idx, newval)
                except ValueError:
                    
                    for idx, oldval, newval in log:
                        pos, loc = _pos(idx)
                        _lists[pos][loc] = oldval
                        if len(_lists[pos]) == (loc + 1):
                            _maxes[pos] = oldval
                    raise
            else:
                if start == 0 and stop == self._len:
                    self._clear()
                    return self._update(value)
                
                
                if not isinstance(value, Sequence):
                    value = tuple(value) 
                
                iterator = range(1, len(value))
                if not all(value[pos - 1] <= value[pos] for pos in iterator):
                    raise ValueError('given sequence not in sort order')
                
                if not start or not len(value):
                    
                    pass
                else:
                    if self._getitem(start - 1) > value[0]:
                        msg = '{0} not in sort order at index {1}'.format(repr(value[0]), start)
                        raise ValueError(msg)
                if stop == len(self) or not len(value):
                    
                    pass
                else:
                    
                    
                    if self._getitem(stop) < value[-1]:
                        msg = '{0} not in sort order at index {1}'.format(repr(value[-1]), stop)
                        raise ValueError(msg)
                
                self._delitem(index)
                
                _insert = self.insert
                for idx, val in enumerate(value):
                    _insert(start + idx, val)
        else:
            pos, loc = _pos(index)
            _check_order(index, value)
            _lists[pos][loc] = value
            if len(_lists[pos]) == (loc + 1):
                _maxes[pos] = value
    def id33(self):
        return chain.from_iterable(self._lists)
    def id29(self):
        return chain.from_iterable(map(reversed, reversed(self._lists)))
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
        elif min_pos == max_pos and not reverse:
            return iter(_lists[min_pos][min_idx:max_idx])
        elif min_pos == max_pos and reverse:
            return reversed(_lists[min_pos][min_idx:max_idx])
        elif min_pos + 1 == max_pos and not reverse:
            return chain(_lists[min_pos][min_idx:], _lists[max_pos][:max_idx])
        elif min_pos + 1 == max_pos and reverse:
            return chain(
                reversed(_lists[max_pos][:max_idx]),
                reversed(_lists[min_pos][min_idx:]),
            )
        elif not reverse:
            return chain(
                _lists[min_pos][min_idx:],
                chain.from_iterable(_lists[(min_pos + 1):max_pos]),
                _lists[max_pos][:max_idx],
            )
        else:
            temp = map(reversed, reversed(_lists[(min_pos + 1):max_pos]))
            return chain(
                reversed(_lists[max_pos][:max_idx]),
                chain.from_iterable(temp),
                reversed(_lists[min_pos][min_idx:]),
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
                min_pos = id2(_maxes, minimum)
                if min_pos == len(_maxes):
                    return iter(())
                min_idx = id2(_lists[min_pos], minimum)
            else:
                min_pos = id22(_maxes, minimum)
                if min_pos == len(_maxes):
                    return iter(())
                min_idx = id22(_lists[min_pos], minimum)
        
        
        if maximum is None:
            max_pos = len(_maxes) - 1
            max_idx = len(_lists[max_pos])
        else:
            if inclusive[1]:
                max_pos = id22(_maxes, maximum)
                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_lists[max_pos])
                else:
                    max_idx = id22(_lists[max_pos], maximum)
            else:
                max_pos = id2(_maxes, maximum)
                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_lists[max_pos])
                else:
                    max_idx = id2(_lists[max_pos], maximum)
        return self._islice(min_pos, min_idx, max_pos, max_idx, reverse)
    def id34(self):
        return self._len
    def id2(self, val):
        _maxes = self._maxes
        if not _maxes:
            return 0
        pos = id2(_maxes, val)
        if pos == len(_maxes):
            return self._len
        idx = id2(self._lists[pos], val)
        return self._loc(pos, idx)
    def id22(self, val):
        _maxes = self._maxes
        if not _maxes:
            return 0
        pos = id22(_maxes, val)
        if pos == len(_maxes):
            return self._len
        idx = id22(self._lists[pos], val)
        return self._loc(pos, idx)
    bisect = id22
    id0 = id22
    def count(self, val):
        _maxes = self._maxes
        if not _maxes:
            return 0
        pos_left = id2(_maxes, val)
        if pos_left == len(_maxes):
            return 0
        _lists = self._lists
        idx_left = id2(_lists[pos_left], val)
        pos_right = id22(_maxes, val)
        if pos_right == len(_maxes):
            return self._len - self._loc(pos_left, idx_left)
        idx_right = id22(_lists[pos_right], val)
        if pos_left == pos_right:
            return idx_right - idx_left
        right = self._loc(pos_right, idx_right)
        left = self._loc(pos_left, idx_left)
        return right - left
    def copy(self):
        return self.__class__(self, load=self._load)
    id4 = copy
    def append(self, val):
        _lists = self._lists
        _maxes = self._maxes
        if not _maxes:
            _maxes.append(val)
            _lists.append([val])
            self._len = 1
            return
        pos = len(_lists) - 1
        if val < _lists[pos][-1]:
            msg = '{0} not in sort order at index {1}'.format(repr(val), self._len)
            raise ValueError(msg)
        _maxes[pos] = val
        _lists[pos].append(val)
        self._len += 1
        self._expand(pos)
    def extend(self, values):
        _lists = self._lists
        _maxes = self._maxes
        _load = self._load
        if not isinstance(values, list):
            values = list(values)
        if any(values[pos - 1] > values[pos]
               for pos in range(1, len(values))):
            raise ValueError('given sequence not in sort order')
        offset = 0
        if _maxes:
            if values[0] < _lists[-1][-1]:
                msg = '{0} not in sort order at index {1}'.format(repr(values[0]), self._len)
                raise ValueError(msg)
            if len(_lists[-1]) < self._half:
                _lists[-1].extend(values[:_load])
                _maxes[-1] = _lists[-1][-1]
                offset = _load
        len_lists = len(_lists)
        for idx in range(offset, len(values), _load):
            _lists.append(values[idx:(idx + _load)])
            _maxes.append(_lists[-1][-1])
        _index = self._index
        if len_lists == len(_lists):
            len_index = len(_index)
            if len_index > 0:
                len_values = len(values)
                child = len_index - 1
                while child:
                    _index[child] += len_values
                    child = (child - 1) >> 1
                _index[0] += len_values
        else:
            del _index[:]
        self._len += len(values)
    def insert(self, idx, val):
        _len = self._len
        _lists = self._lists
        _maxes = self._maxes
        if idx < 0:
            idx += _len
        if idx < 0:
            idx = 0
        if idx > _len:
            idx = _len
        if not _maxes:
            
            _maxes.append(val)
            _lists.append([val])
            self._len = 1
            return
        if not idx:
            if val > _lists[0][0]:
                msg = '{0} not in sort order at index {1}'.format(repr(val), 0)
                raise ValueError(msg)
            else:
                _lists[0].insert(0, val)
                self._expand(0)
                self._len += 1
                return
        if idx == _len:
            pos = len(_lists) - 1
            if _lists[pos][-1] > val:
                msg = '{0} not in sort order at index {1}'.format(repr(val), _len)
                raise ValueError(msg)
            else:
                _lists[pos].append(val)
                _maxes[pos] = _lists[pos][-1]
                self._expand(pos)
                self._len += 1
                return
        pos, idx = self._pos(idx)
        idx_before = idx - 1
        if idx_before < 0:
            pos_before = pos - 1
            idx_before = len(_lists[pos_before]) - 1
        else:
            pos_before = pos
        before = _lists[pos_before][idx_before]
        if before <= val <= _lists[pos][idx]:
            _lists[pos].insert(idx, val)
            self._expand(pos)
            self._len += 1
        else:
            msg = '{0} not in sort order at index {1}'.format(repr(val), idx)
            raise ValueError(msg)
    def pop(self, idx=-1):
        if not self._len:
            raise IndexError('pop index out of range')
        _lists = self._lists
        if idx == 0:
            val = _lists[0][0]
            self._delete(0, 0)
            return val
        if idx == -1:
            pos = len(_lists) - 1
            loc = len(_lists[pos]) - 1
            val = _lists[pos][loc]
            self._delete(pos, loc)
            return val
        if 0 <= idx < len(_lists[0]):
            val = _lists[0][idx]
            self._delete(0, idx)
            return val
        len_last = len(_lists[-1])
        if -len_last < idx < 0:
            pos = len(_lists) - 1
            loc = len_last + idx
            val = _lists[pos][loc]
            self._delete(pos, loc)
            return val
        pos, idx = self._pos(idx)
        val = _lists[pos][idx]
        self._delete(pos, idx)
        return val
    def index(self, val, start=None, stop=None):
        
        _len = self._len
        if not _len:
            raise ValueError('{0} is not in list'.format(repr(val)))
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
            raise ValueError('{0} is not in list'.format(repr(val)))
        _maxes = self._maxes
        pos_left = id2(_maxes, val)
        if pos_left == len(_maxes):
            raise ValueError('{0} is not in list'.format(repr(val)))
        _lists = self._lists
        idx_left = id2(_lists[pos_left], val)
        if _lists[pos_left][idx_left] != val:
            raise ValueError('{0} is not in list'.format(repr(val)))
        stop -= 1
        left = self._loc(pos_left, idx_left)
        if start <= left:
            if left <= stop:
                return left
        else:
            right = self.id0(val) - 1
            if start <= right:
                return start
        raise ValueError('{0} is not in list'.format(repr(val)))
    def id1(self, that):
        values = reduce(iadd, self._lists, [])
        values.extend(that)
        return self.__class__(values, load=self._load)
    def id26(self, that):
        self._update(that)
        return self
    def id10(self, that):
        values = reduce(iadd, self._lists, []) * that
        return self.__class__(values, load=self._load)
    def id17(self, that):
        values = reduce(iadd, self._lists, []) * that
        self._clear()
        self._update(values)
        return self
    def _make_cmp(self, seq_op, doc):
        "Make comparator method."
        def comparer(self, that):
            "Compare method for sorted list and sequence."
            
            if not isinstance(that, Sequence):
                return NotImplemented
            self_len = self._len
            len_that = len(that)
            if self_len != len_that:
                if seq_op is op.eq:
                    return False
                if seq_op is op.ne:
                    return True
            for alpha, beta in zip(self, that):
                if alpha != beta:
                    return seq_op(alpha, beta)
            return seq_op(self_len, len_that)
        comparer.__name__ = '__{0}__'.format(seq_op.__name__)
        doc_str = 'Return `True` if and only if Sequence is {0} `that`.'
        comparer.__doc__ = doc_str.format(doc)
        return comparer
    id9 = _make_cmp(None, op.eq, 'equal to')
    id16 = _make_cmp(None, op.ne, 'not equal to')
    id31 = _make_cmp(None, op.lt, 'less than')
    id13 = _make_cmp(None, op.gt, 'greater than')
    id24 = _make_cmp(None, op.le, 'less than or equal to')
    id32 = _make_cmp(None, op.ge, 'greater than or equal to')
    @recursive_repr
    def id11(self):
        temp = '{0}({1}, load={2})'
        return temp.format(
            self.__class__.__name__,
            repr(list(self)),
            repr(self._load)
        )
    def _check(self):
        try:
            
            assert self._load >= 4
            assert self._half == (self._load >> 1)
            assert self._twice == (self._load * 2)
            
            if self._maxes == []:
                assert self._lists == []
                return
            assert len(self._maxes) > 0 and len(self._lists) > 0
            
            assert all(sublist[pos - 1] <= sublist[pos]
                       for sublist in self._lists
                       for pos in range(1, len(sublist)))
            
            for pos in range(1, len(self._lists)):
                assert self._lists[pos - 1][-1] <= self._lists[pos][0]
            
            assert len(self._maxes) == len(self._lists)
            
            assert all(self._maxes[pos] == self._lists[pos][-1]
                       for pos in range(len(self._maxes)))
            
            assert all(len(sublist) <= self._twice for sublist in self._lists)
            
            
            assert all(len(self._lists[pos]) >= self._half
                       for pos in range(0, len(self._lists) - 1))
            
            assert self._len == sum(len(sublist) for sublist in self._lists)
            
            if len(self._index):
                assert len(self._index) == self._offset + len(self._lists)
                assert self._len == self._index[0]
                def id18(pos):
                    "Test positional indexing offset."
                    from_index = self._index[self._offset + pos]
                    return from_index == len(self._lists[pos])
                assert all(id18(pos)
                           for pos in range(len(self._lists)))
                for pos in range(self._offset):
                    child = (pos << 1) + 1
                    if child >= len(self._index):
                        assert self._index[pos] == 0
                    elif child + 1 == len(self._index):
                        assert self._index[pos] == self._index[child]
                    else:
                        child_sum = self._index[child] + self._index[child + 1]
                        assert self._index[pos] == child_sum
        except:
            import sys
            import traceback
            traceback.print_exc(file=sys.stdout)
            print('len', self._len)
            print('load', self._load, self._half, self._twice)
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
class id7(SortedList):
    def __init__(self, iterable=None, key=identity, load=1000):
        
        self._len = 0
        self._lists = []
        self._keys = []
        self._maxes = []
        self._index = []
        self._key = key
        self._load = load
        self._twice = load * 2
        self._half = load >> 1
        self._offset = 0
        if iterable is not None:
            self._update(iterable)
    def id8(cls, iterable=None, key=identity, load=1000):
        return object.id8(cls)
    def clear(self):
        self._len = 0
        del self._lists[:]
        del self._keys[:]
        del self._maxes[:]
        del self._index[:]
    _clear = clear
    def add(self, val):
        _lists = self._lists
        _keys = self._keys
        _maxes = self._maxes
        key = self._key(val)
        if _maxes:
            pos = id22(_maxes, key)
            if pos == len(_maxes):
                pos -= 1
                _lists[pos].append(val)
                _keys[pos].append(key)
                _maxes[pos] = key
            else:
                idx = id22(_keys[pos], key)
                _lists[pos].insert(idx, val)
                _keys[pos].insert(idx, key)
            self._expand(pos)
        else:
            _lists.append([val])
            _keys.append([key])
            _maxes.append(key)
        self._len += 1
    def _expand(self, pos):
        _lists = self._lists
        _keys = self._keys
        _index = self._index
        if len(_keys[pos]) > self._twice:
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
                values.extend(chain.from_iterable(_lists))
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
    def id12(self, val):
        _maxes = self._maxes
        if not _maxes:
            return False
        key = self._key(val)
        pos = id2(_maxes, key)
        if pos == len(_maxes):
            return False
        _lists = self._lists
        _keys = self._keys
        idx = id2(_keys[pos], key)
        len_keys = len(_keys)
        id6 = len(_keys[pos])
        while True:
            if _keys[pos][idx] != key:
                return False
            if _lists[pos][idx] == val:
                return True
            idx += 1
            if idx == id6:
                pos += 1
                if pos == len_keys:
                    return False
                id6 = len(_keys[pos])
                idx = 0
    def discard(self, val):
        _maxes = self._maxes
        if not _maxes:
            return
        key = self._key(val)
        pos = id2(_maxes, key)
        if pos == len(_maxes):
            return
        _lists = self._lists
        _keys = self._keys
        idx = id2(_keys[pos], key)
        len_keys = len(_keys)
        id6 = len(_keys[pos])
        while True:
            if _keys[pos][idx] != key:
                return
            if _lists[pos][idx] == val:
                self._delete(pos, idx)
                return
            idx += 1
            if idx == id6:
                pos += 1
                if pos == len_keys:
                    return
                id6 = len(_keys[pos])
                idx = 0
    def remove(self, val):
        _maxes = self._maxes
        if not _maxes:
            raise ValueError('{0} not in list'.format(repr(val)))
        key = self._key(val)
        pos = id2(_maxes, key)
        if pos == len(_maxes):
            raise ValueError('{0} not in list'.format(repr(val)))
        _lists = self._lists
        _keys = self._keys
        idx = id2(_keys[pos], key)
        len_keys = len(_keys)
        id6 = len(_keys[pos])
        while True:
            if _keys[pos][idx] != key:
                raise ValueError('{0} not in list'.format(repr(val)))
            if _lists[pos][idx] == val:
                self._delete(pos, idx)
                return
            idx += 1
            if idx == id6:
                pos += 1
                if pos == len_keys:
                    raise ValueError('{0} not in list'.format(repr(val)))
                id6 = len(_keys[pos])
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
        id14 = len(keys_pos)
        if id14 > self._half:
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
        elif id14:
            _maxes[pos] = keys_pos[-1]
        else:
            del _lists[pos]
            del _keys[pos]
            del _maxes[pos]
            del _index[:]
    def _check_order(self, idx, key, val):
        
        _len = self._len
        _keys = self._keys
        pos, loc = self._pos(idx)
        if idx < 0:
            idx += _len
        
        
        if idx > 0:
            idx_prev = loc - 1
            pos_prev = pos
            if idx_prev < 0:
                pos_prev -= 1
                idx_prev = len(_keys[pos_prev]) - 1
            if _keys[pos_prev][idx_prev] > key:
                msg = '{0} not in sort order at index {1}'.format(repr(val), idx)
                raise ValueError(msg)
        
        
        if idx < (_len - 1):
            idx_next = loc + 1
            pos_next = pos
            if idx_next == len(_keys[pos_next]):
                pos_next += 1
                idx_next = 0
            if _keys[pos_next][idx_next] < key:
                msg = '{0} not in sort order at index {1}'.format(repr(val), idx)
                raise ValueError(msg)
    def id19(self, index, value):
        _lists = self._lists
        _keys = self._keys
        _maxes = self._maxes
        _check_order = self._check_order
        _pos = self._pos
        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)
            indices = range(start, stop, step)
            if step != 1:
                if not hasattr(value, 'id34'):
                    value = list(value)
                indices = list(indices)
                if len(value) != len(indices):
                    raise ValueError(
                        'attempt to assign sequence of size {0}'
                        ' to extended slice of size {1}'
                        .format(len(value), len(indices)))
                
                
                log = []
                _append = log.append
                for idx, val in zip(indices, value):
                    pos, loc = _pos(idx)
                    key = self._key(val)
                    _append((idx, _keys[pos][loc], key, _lists[pos][loc], val))
                    _keys[pos][loc] = key
                    _lists[pos][loc] = val
                    if len(_keys[pos]) == (loc + 1):
                        _maxes[pos] = key
                try:
                    
                    for idx, oldkey, newkey, oldval, newval in log:
                        _check_order(idx, newkey, newval)
                except ValueError:
                    
                    for idx, oldkey, newkey, oldval, newval in log:
                        pos, loc = _pos(idx)
                        _keys[pos][loc] = oldkey
                        _lists[pos][loc] = oldval
                        if len(_keys[pos]) == (loc + 1):
                            _maxes[pos] = oldkey
                    raise
            else:
                if start == 0 and stop == self._len:
                    self._clear()
                    return self._update(value)
                
                
                if not isinstance(value, Sequence):
                    value = tuple(value) 
                
                keys = tuple(map(self._key, value))
                iterator = range(1, len(keys))
                if not all(keys[pos - 1] <= keys[pos] for pos in iterator):
                    raise ValueError('given sequence not in sort order')
                
                if not start or not len(value):
                    
                    pass
                else:
                    pos, loc = _pos(start - 1)
                    if _keys[pos][loc] > keys[0]:
                        msg = '{0} not in sort order at index {1}'.format(repr(value[0]), start)
                        raise ValueError(msg)
                if stop == len(self) or not len(value):
                    
                    pass
                else:
                    
                    
                    pos, loc = _pos(stop)
                    if _keys[pos][loc] < keys[-1]:
                        msg = '{0} not in sort order at index {1}'.format(repr(value[-1]), stop)
                        raise ValueError(msg)
                
                self._delitem(index)
                
                _insert = self.insert
                for idx, val in enumerate(value):
                    _insert(start + idx, val)
        else:
            pos, loc = _pos(index)
            key = self._key(value)
            _check_order(index, key, value)
            _lists[pos][loc] = value
            _keys[pos][loc] = key
            if len(_lists[pos]) == (loc + 1):
                _maxes[pos] = key
    def irange(self, minimum=None, maximum=None, inclusive=(True, True),
               reverse=False):
        minimum = self._key(minimum) if minimum is not None else None
        maximum = self._key(maximum) if maximum is not None else None
        return self.id5(
            min_key=minimum, max_key=maximum,
            inclusive=inclusive, reverse=reverse,
        )
    def id25(self, min_key=None, max_key=None, inclusive=(True, True),
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
                min_pos = id2(_maxes, min_key)
                if min_pos == len(_maxes):
                    return iter(())
                min_idx = id2(_keys[min_pos], min_key)
            else:
                min_pos = id22(_maxes, min_key)
                if min_pos == len(_maxes):
                    return iter(())
                min_idx = id22(_keys[min_pos], min_key)
        
        
        if max_key is None:
            max_pos = len(_maxes) - 1
            max_idx = len(_keys[max_pos])
        else:
            if inclusive[1]:
                max_pos = id22(_maxes, max_key)
                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_keys[max_pos])
                else:
                    max_idx = id22(_keys[max_pos], max_key)
            else:
                max_pos = id2(_maxes, max_key)
                if max_pos == len(_maxes):
                    max_pos -= 1
                    max_idx = len(_keys[max_pos])
                else:
                    max_idx = id2(_keys[max_pos], max_key)
        return self._islice(min_pos, min_idx, max_pos, max_idx, reverse)
    id5 = id25
    def id2(self, val):
        return self.id30(self._key(val))
    def id22(self, val):
        return self.id28(self._key(val))
    bisect = id22
    def id20(self, key):
        _maxes = self._maxes
        if not _maxes:
            return 0
        pos = id2(_maxes, key)
        if pos == len(_maxes):
            return self._len
        idx = id2(self._keys[pos], key)
        return self._loc(pos, idx)
    id30 = id20
    def id27(self, key):
        _maxes = self._maxes
        if not _maxes:
            return 0
        pos = id22(_maxes, key)
        if pos == len(_maxes):
            return self._len
        idx = id22(self._keys[pos], key)
        return self._loc(pos, idx)
    id15 = id27
    id28 = id27
    def count(self, val):
        _maxes = self._maxes
        if not _maxes:
            return 0
        key = self._key(val)
        pos = id2(_maxes, key)
        if pos == len(_maxes):
            return 0
        _lists = self._lists
        _keys = self._keys
        idx = id2(_keys[pos], key)
        total = 0
        len_keys = len(_keys)
        id6 = len(_keys[pos])
        while True:
            if _keys[pos][idx] != key:
                return total
            if _lists[pos][idx] == val:
                total += 1
            idx += 1
            if idx == id6:
                pos += 1
                if pos == len_keys:
                    return total
                id6 = len(_keys[pos])
                idx = 0
    def copy(self):
        return self.__class__(self, key=self._key, load=self._load)
    id4 = copy
    def append(self, val):
        _lists = self._lists
        _keys = self._keys
        _maxes = self._maxes
        key = self._key(val)
        if not _maxes:
            _maxes.append(key)
            _keys.append([key])
            _lists.append([val])
            self._len = 1
            return
        pos = len(_keys) - 1
        if key < _keys[pos][-1]:
            msg = '{0} not in sort order at index {1}'.format(repr(val), self._len)
            raise ValueError(msg)
        _lists[pos].append(val)
        _keys[pos].append(key)
        _maxes[pos] = key
        self._len += 1
        self._expand(pos)
    def extend(self, values):
        _lists = self._lists
        _keys = self._keys
        _maxes = self._maxes
        _load = self._load
        if not isinstance(values, list):
            values = list(values)
        keys = list(map(self._key, values))
        if any(keys[pos - 1] > keys[pos]
               for pos in range(1, len(keys))):
            raise ValueError('given sequence not in sort order')
        offset = 0
        if _maxes:
            if keys[0] < _keys[-1][-1]:
                msg = '{0} not in sort order at index {1}'.format(repr(values[0]), self._len)
                raise ValueError(msg)
            if len(_keys[-1]) < self._half:
                _lists[-1].extend(values[:_load])
                _keys[-1].extend(keys[:_load])
                _maxes[-1] = _keys[-1][-1]
                offset = _load
        len_keys = len(_keys)
        for idx in range(offset, len(keys), _load):
            _lists.append(values[idx:(idx + _load)])
            _keys.append(keys[idx:(idx + _load)])
            _maxes.append(_keys[-1][-1])
        _index = self._index
        if len_keys == len(_keys):
            len_index = len(_index)
            if len_index > 0:
                len_values = len(values)
                child = len_index - 1
                while child:
                    _index[child] += len_values
                    child = (child - 1) >> 1
                _index[0] += len_values
        else:
            del _index[:]
        self._len += len(values)
    def insert(self, idx, val):
        _len = self._len
        _lists = self._lists
        _keys = self._keys
        _maxes = self._maxes
        if idx < 0:
            idx += _len
        if idx < 0:
            idx = 0
        if idx > _len:
            idx = _len
        key = self._key(val)
        if not _maxes:
            self._len = 1
            _lists.append([val])
            _keys.append([key])
            _maxes.append(key)
            return
        if not idx:
            if key > _keys[0][0]:
                msg = '{0} not in sort order at index {1}'.format(repr(val), 0)
                raise ValueError(msg)
            else:
                self._len += 1
                _lists[0].insert(0, val)
                _keys[0].insert(0, key)
                self._expand(0)
                return
        if idx == _len:
            pos = len(_keys) - 1
            if _keys[pos][-1] > key:
                msg = '{0} not in sort order at index {1}'.format(repr(val), _len)
                raise ValueError(msg)
            else:
                self._len += 1
                _lists[pos].append(val)
                _keys[pos].append(key)
                _maxes[pos] = _keys[pos][-1]
                self._expand(pos)
                return
        pos, idx = self._pos(idx)
        idx_before = idx - 1
        if idx_before < 0:
            pos_before = pos - 1
            idx_before = len(_keys[pos_before]) - 1
        else:
            pos_before = pos
        before = _keys[pos_before][idx_before]
        if before <= key <= _keys[pos][idx]:
            self._len += 1
            _lists[pos].insert(idx, val)
            _keys[pos].insert(idx, key)
            self._expand(pos)
        else:
            msg = '{0} not in sort order at index {1}'.format(repr(val), idx)
            raise ValueError(msg)
    def index(self, val, start=None, stop=None):
        _len = self._len
        if not _len:
            raise ValueError('{0} is not in list'.format(repr(val)))
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
            raise ValueError('{0} is not in list'.format(repr(val)))
        _maxes = self._maxes
        key = self._key(val)
        pos = id2(_maxes, key)
        if pos == len(_maxes):
            raise ValueError('{0} is not in list'.format(repr(val)))
        stop -= 1
        _lists = self._lists
        _keys = self._keys
        idx = id2(_keys[pos], key)
        len_keys = len(_keys)
        id6 = len(_keys[pos])
        while True:
            if _keys[pos][idx] != key:
                raise ValueError('{0} is not in list'.format(repr(val)))
            if _lists[pos][idx] == val:
                loc = self._loc(pos, idx)
                if start <= loc <= stop:
                    return loc
                elif loc > stop:
                    break
            idx += 1
            if idx == id6:
                pos += 1
                if pos == len_keys:
                    raise ValueError('{0} is not in list'.format(repr(val)))
                id6 = len(_keys[pos])
                idx = 0
        raise ValueError('{0} is not in list'.format(repr(val)))
    def id1(self, that):
        values = reduce(iadd, self._lists, [])
        values.extend(that)
        return self.__class__(values, key=self._key, load=self._load)
    def id10(self, that):
        values = reduce(iadd, self._lists, []) * that
        return self.__class__(values, key=self._key, load=self._load)
    def id17(self, that):
        values = reduce(iadd, self._lists, []) * that
        self._clear()
        self._update(values)
        return self
    @recursive_repr
    def id11(self):
        temp = '{0}({1}, key={2}, load={3})'
        return temp.format(
            self.__class__.__name__,
            repr(list(self)),
            repr(self._key),
            repr(self._load)
        )
    def _check(self):
        try:
            
            assert self._load >= 4
            assert self._half == (self._load >> 1)
            assert self._twice == (self._load * 2)
            
            if self._maxes == []:
                assert self._keys == []
                assert self._lists == []
                return
            assert len(self._maxes) > 0 and len(self._keys) > 0 and len(self._lists) > 0
            
            assert all(sublist[pos - 1] <= sublist[pos]
                       for sublist in self._keys
                       for pos in range(1, len(sublist)))
            
            for pos in range(1, len(self._keys)):
                assert self._keys[pos - 1][-1] <= self._keys[pos][0]
            
            assert len(self._maxes) == len(self._lists) == len(self._keys)
            
            assert all(len(val_list) == len(key_list)
                       for val_list, key_list in zip(self._lists, self._keys))
            assert all(self._key(val) == key for val, key in
                       zip((_val for _val_list in self._lists for _val in _val_list),
                           (_key for _key_list in self._keys for _key in _key_list)))
            
            assert all(self._maxes[pos] == self._keys[pos][-1]
                       for pos in range(len(self._maxes)))
            
            assert all(len(sublist) <= self._twice for sublist in self._lists)
            
            
            assert all(len(self._lists[pos]) >= self._half
                       for pos in range(0, len(self._lists) - 1))
            
            assert self._len == sum(len(sublist) for sublist in self._lists)
            
            if len(self._index):
                assert len(self._index) == self._offset + len(self._lists)
                assert self._len == self._index[0]
                def id18(pos):
                    "Test positional indexing offset."
                    from_index = self._index[self._offset + pos]
                    return from_index == len(self._lists[pos])
                assert all(id18(pos)
                           for pos in range(len(self._lists)))
                for pos in range(self._offset):
                    child = (pos << 1) + 1
                    if self._index[pos] == 0:
                        assert child >= len(self._index)
                    elif child + 1 == len(self._index):
                        assert self._index[pos] == self._index[child]
                    else:
                        child_sum = self._index[child] + self._index[child + 1]
                        assert self._index[pos] == child_sum
        except:
            import sys
            import traceback
            traceback.print_exc(file=sys.stdout)
            print('len', self._len)
            print('load', self._load, self._half, self._twice)
            print('offset', self._offset)
            print('len_index', len(self._index))
            print('index', self._index)
            print('len_maxes', len(self._maxes))
            print('maxes', self._maxes)
            print('len_keys', len(self._keys))
            print('keys', self._keys)
            print('len_lists', len(self._lists))
            print('lists', self._lists)
            raise

n = int(input())
r = SortedList([(-1, -1)])
for x in map(int, input().split()):
    i = r.bisect((x+1, -1))-1
    y, p = r[i]
    if p != -1:
        print(p, end=' ')
    del r[i]
    r.add((y, x))
    r.add((x, x))
print()