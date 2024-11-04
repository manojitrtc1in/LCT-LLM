from sys import stdin
import operator as op
from bisect import *
from itertools import chain, repeat, starmap
from functools import reduce


def fast2():
    import os, sys, atexit
    from cStringIO import StringIO as BytesIO
    
    sys.stdout = BytesIO()
    atexit.register(lambda: os.write(1, sys.stdout.getvalue()))
    return BytesIO(os.read(0, os.fstat(0).st_size)).readline


class SortedList():
    
    id2 = 500

    def __init__(self, iterable=None):
        
        self._len = 0
        self._load = self.id2
        self._lists = []
        self._maxes = []
        self._index = []
        self._offset = 0
        if iterable is not None:
            self.update(iterable)

    def clear(self):
        
        self._len = 0
        del self._lists[:]
        del self._maxes[:]
        del self._index[:]
        self._offset = 0

    def add(self, value):
        
        _lists = self._lists
        _maxes = self._maxes
        if _maxes:
            pos = id16(_maxes, value)
            if pos == len(_maxes):
                _lists[pos - 1].append(value)
                _maxes[pos - 1] = value
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
        pos = id3(_maxes, value)
        if pos == len(_maxes):
            return False

        _lists = self._lists
        idx = id3(_lists[pos], value)
        return _lists[pos][idx] == value

    def remove(self, value):
        
        _maxes = self._maxes
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
        reduce(list.id19, reversed(tree), self._index)
        self._offset = size * 2 - 1

    def id15(self, index):
        
        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)
            if step == 1 and start < stop:
                if start == 0 and stop == self._len:
                    return self.clear()
                elif self._len <= 8 * (stop - start):
                    values = self.id17(slice(None, start))
                    if stop < self._len:
                        values += self.id17(slice(stop, None))
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

    def id17(self, index):
        
        _lists = self._lists

        if isinstance(index, slice):
            start, stop, step = index.indices(self._len)

            if step == 1 and start < stop:
                if start == 0 and stop == self._len:
                    return reduce(list.id19, self._lists, [])

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
                result = reduce(list.id19, middle, prefix)
                result += _lists[stop_pos][:stop_idx]
                return result

            if step == -1 and start > stop:
                result = self.id17(slice(stop + 1, start + 1))
                result.reverse()
                return result

            indices = range(start, stop, step)
            return list(self.id17(index) for index in indices)
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

    def id25(self):
        
        return chain.from_iterable(self._lists)

    def id21(self):
        
        return chain.from_iterable(map(reversed, reversed(self._lists)))

    def id26(self):
        
        return self._len

    def id3(self, value):
        
        pos = id3(self._maxes, value)
        return self._len if pos == len(self._maxes) else self._loc(pos, id3(self._lists[pos], value))

    def id16(self, value):
        
        pos = id16(self._maxes, value)
        return self._len if pos == len(self._maxes) else self._loc(pos, id16(self._lists[pos], value))

    bisect = id16

    def count(self, value):
        
        _maxes = self._maxes
        if not _maxes:
            return 0

        pos_left = id3(_maxes, value)
        if pos_left == len(_maxes):
            return 0

        _lists = self._lists
        idx_left = id3(_lists[pos_left], value)
        pos_right = id16(_maxes, value)
        if pos_right == len(_maxes):
            return self._len - self._loc(pos_left, idx_left)

        idx_right = id16(_lists[pos_right], value)
        if pos_left == pos_right:
            return idx_right - idx_left

        right = self._loc(pos_right, idx_right)
        left = self._loc(pos_left, idx_left)
        return right - left

    def copy(self):
        
        return self.__class__(self)

    id5 = copy

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
            if start <= self.id16(value) - 1:
                return start
        raise ValueError('{0!r} is not in list'.format(value))

    def id1(self, other):
        
        values = reduce(list.id19, self._lists, [])
        values.extend(other)
        return self.__class__(values)

    id9 = id1

    def id19(self, other):
        
        self.update(other)
        return self

    def id8(self, num):
        
        values = reduce(list.id19, self._lists, []) * num
        return self.__class__(values)

    id0 = id8

    def id14(self, num):
        
        values = reduce(list.id19, self._lists, []) * num
        self.clear()
        self.update(values)
        return self

    def id24(seq_op):
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

    id7 = id24(op.eq)
    id13 = id24(op.ne)
    id22 = id24(op.lt)
    id12 = id24(op.gt)
    id18 = id24(op.le)
    id23 = id24(op.ge)
    id24 = staticmethod(id24)

    def id10(self):
        
        return 'SortedList({0})'.format(reduce(list.id19, self._lists, []))


class segmenttree:
    def __init__(self, n):
        self.tree, self.n = [0] * (2 * n), n

    
    def query(self, l, r):
        res = 0
        l += self.n
        r += self.n
        while l < r:
            if l & 1:
                res = max(self.tree[l], res)
                l += 1
            if r & 1:
                r -= 1
                res = max(self.tree[r], res)
            l >>= 1
            r >>= 1

        return res

    def update(self, ix, val):
        ix += self.n

        
        self.tree[ix] = val

        
        while ix > 1:
            self.tree[ix >> 1] = max(self.tree[ix], self.tree[ix ^ 1])
            ix >>= 1


input = fast2()
id20 = lambda: [str(x) for x in input().split()]
id6 = lambda n: [id20() for _ in range(n)]

n, out = int(input()), []
qur, dis, ma = id6(n << 1), SortedList([10 ** 5 + 1]), SortedList(list(range(1, n + 1)) + [10 ** 5 + 1])
ixs, tree = [0] * (n + 1), segmenttree(n)

for i in range(n << 1):
    if qur[i][0] == '+':
        out.append(ma[-2])
        tree.update(len(out) - 1, out[-1])
        ixs[ma[-2]] = len(out) - 1
        dis.add(ma.pop(-2))

    else:
        cur = int(qur[i][1])

        if dis[0] < cur or len(dis) == 1 or (i and qur[i - 1][0] == '-' and int(qur[i - 1][1]) > cur):
            print('NO')
            exit()
        elif dis[0] == cur:
            dis.pop(0)
        else:
            tree.update(ixs[dis[0]], cur)
            out[ixs[dis[0]]] = cur

            if tree.query(ixs[dis[0]], n) > cur:
                print('NO')
                exit()

            tem = dis.pop(0)
            ma.add(tem)
            ma.remove(cur)

    

print('YES\n%s' % (' '.join(map(str, out))))
