import io
import os

from collections import Counter, defaultdict, deque



class id10:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._sum = sum(values)
        self._load = _load
        self._lists = _lists = [values[i : i + _load] for i in range(0, _len, _load)]
        self._mins = [_list[0] for _list in _lists]
        self.id17 = [len(_list) for _list in _lists]
        self.id16 = []
        self.id3 = [sum(_list) for _list in _lists]
        self.id2 = []
        self._rebuild = True

    def id1(self):
        
        self.id16[:] = self.id17
        id16 = self.id16
        for i in range(len(id16)):
            if i | i + 1 < len(id16):
                id16[i | i + 1] += id16[i]

        self.id2[:] = self.id3
        id2 = self.id2
        for i in range(len(id2)):
            if i | i + 1 < len(id2):
                id2[i | i + 1] += id2[i]

        self._rebuild = False

    def id5(self, index, value):
        
        if not self._rebuild:
            id16 = self.id16
            while index < len(id16):
                id16[index] += value
                index |= index + 1

    def id13(self, index, value):
        
        if not self._rebuild:
            id16 = self.id2
            while index < len(id16):
                id16[index] += value
                index |= index + 1

    def id15(self, end):
        
        if self._rebuild:
            self.id1()

        id16 = self.id16
        x = 0
        while end:
            x += id16[end - 1]
            end &= end - 1
        return x

    def id6(self, end):
        
        if self._rebuild:
            self.id1()

        id16 = self.id2
        x = 0
        while end:
            x += id16[end - 1]
            end &= end - 1
        return x

    def id12(self, k):
        
        id17 = self.id17
        if k < id17[0]:
            return 0, k
        if k >= self._len - id17[-1]:
            return len(id17) - 1, k + id17[-1] - self._len
        if self._rebuild:
            self.id1()

        id16 = self.id16
        idx = -1
        for d in reversed(range(len(id16).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id16) and k >= id16[right_idx]:
                idx = right_idx
                k -= id16[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id17 = self.id17
        id3 = self.id3

        value = _lists[pos][idx]
        self._len -= 1
        self._sum -= value
        self.id5(pos, -1)
        self.id13(pos, -value)
        del _lists[pos][idx]
        id17[pos] -= 1
        id3[pos] -= value

        if id17[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id17[pos]
            del id3[pos]
            del _mins[pos]
            self._rebuild = True

    def _loc_left(self, value):
        
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
        
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        id17 = self.id17
        id3 = self.id3

        self._len += 1
        self._sum += value
        if _lists:
            pos, idx = self._loc_right(value)
            self.id5(pos, 1)
            self.id13(pos, value)
            _list = _lists[pos]
            _list.insert(idx, value)
            id17[pos] += 1
            id3[pos] += value
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                back = _list[_load:]
                old_len = id17[pos]
                old_sum = id3[pos]
                id11 = _load
                id0 = old_len - id11
                id8 = sum(back)
                id4 = old_sum - id8
                _lists.insert(pos + 1, back)
                id17.insert(pos + 1, id0)
                id3.insert(pos + 1, id8)
                _mins.insert(pos + 1, _list[_load])
                id17[pos] = id11
                id3[pos] = id4
                del _list[_load:]
                
                
                
                
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id17.append(1)
            id3.append(value)
            self._rebuild = True

    def discard(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_right(value)
            if idx and _lists[pos][idx - 1] == value:
                self._delete(pos, idx - 1)

    def remove(self, value):
        
        _len = self._len
        self.discard(value)
        if _len == self._len:
            raise ValueError("{0!r} not in list".format(value))

    def pop(self, index=-1):
        
        pos, idx = self.id12(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id7(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id15(pos) + idx

    def id20(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id15(pos) + idx

    def count(self, value):
        
        return self.id20(value) - self.id7(value)

    def id24(self):
        
        return self._len

    def id21(self, index):
        
        pos, idx = self.id12(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id14(self, index):
        
        pos, idx = self.id12(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id22(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id23(self):
        
        return (value for _list in self._lists for value in _list)

    def id9(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id18(self):
        
        return "SortedList({0})".format(list(self))

    def query(self, i, j):
        if i == j:
            return 0
        pos1, idx1 = self.id12(self._len + i if i < 0 else i)
        pos2, idx2 = self.id12(self._len + j if j < 0 else j)
        return (
            sum(self._lists[pos1][idx1:])
            + (self.id6(pos2) - self.id6(pos1 + 1))
            + sum(self._lists[pos2][:idx2])
        )

    def sum(self):
        return self._sum


class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id17 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id16 = []
        self._rebuild = True

    def id1(self):
        
        self.id16[:] = self.id17
        id16 = self.id16
        for i in range(len(id16)):
            if i | i + 1 < len(id16):
                id16[i | i + 1] += id16[i]
        self._rebuild = False

    def id5(self, index, value):
        
        if not self._rebuild:
            id16 = self.id16
            while index < len(id16):
                id16[index] += value
                index |= index + 1

    def id15(self, end):
        
        if self._rebuild:
            self.id1()

        id16 = self.id16
        x = 0
        while end:
            x += id16[end - 1]
            end &= end - 1
        return x

    def id12(self, k):
        
        id17 = self.id17
        if k < id17[0]:
            return 0, k
        if k >= self._len - id17[-1]:
            return len(id17) - 1, k + id17[-1] - self._len
        if self._rebuild:
            self.id1()

        id16 = self.id16
        idx = -1
        for d in reversed(range(len(id16).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id16) and k >= id16[right_idx]:
                idx = right_idx
                k -= id16[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id17 = self.id17

        self._len -= 1
        self.id5(pos, -1)
        del _lists[pos][idx]
        id17[pos] -= 1

        if id17[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id17[pos]
            del _mins[pos]
            self._rebuild = True

    def _loc_left(self, value):
        
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
        
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        id17 = self.id17

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id5(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id17[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id17.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id17[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id17.append(1)
            self._rebuild = True

    def discard(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_right(value)
            if idx and _lists[pos][idx - 1] == value:
                self._delete(pos, idx - 1)

    def remove(self, value):
        
        _len = self._len
        self.discard(value)
        if _len == self._len:
            raise ValueError('{0!r} not in list'.format(value))

    def pop(self, index=-1):
        
        pos, idx = self.id12(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id7(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id15(pos) + idx

    def id20(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id15(pos) + idx

    def count(self, value):
        
        return self.id20(value) - self.id7(value)

    def id24(self):
        
        return self._len

    def id21(self, index):
        
        pos, idx = self.id12(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id14(self, index):
        
        pos, idx = self.id12(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id22(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id23(self):
        
        return (value for _list in self._lists for value in _list)

    def id9(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id18(self):
        
        return 'SortedList({0})'.format(list(self))


def solve(N, queries):
    L = SortedList()
    F = SortedList()
    sumL = 0
    sumF = 0

    
    
    cand = id10()
    
    id19 = None

    def add(d, tp):
        nonlocal sumL, sumF, id19
        toAdd = d
        if tp == 0:
            F.add(d)
            sumF += d
        else:
            if not L or L[0] > d:
                
                toAdd = id19
                id19 = d
            L.add(d)
            sumL += d

        if toAdd is not None:
            cand.add(toAdd)

    def remove(d, tp):
        nonlocal sumL, sumF, id19
        toRemove = d
        if tp == 0:
            F.remove(d)
            sumF -= d
        else:
            L.remove(d)
            sumL -= d
            id19 = None if not L else L[0]
            if not L or id19 > d:
                
                toRemove = id19

        if toRemove is not None:
            cand.remove(toRemove)

    ans = []
    for tp, d in queries:
        if d > 0:
            
            add(d, tp)
        else:
            
            remove(-d, tp)
        ans.append(
            cand.query(max(0, len(cand) - len(L)), len(cand)) + sumL + sumF
        )

    return "\n".join(map(str, ans))


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    (N,) = [int(x) for x in input().split()]
    queries = ((int(x) for x in input().split()) for i in range(N))
    ans = solve(N, queries)
    print(ans)
