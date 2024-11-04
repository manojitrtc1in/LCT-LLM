

import io, os, sys
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline  
output = sys.stdout.write

DEBUG = os.environ.get('debug') not in [None, '0']

if DEBUG:
    from inspect import currentframe, getframeinfo
    from re import search

def debug(*args):
    if not DEBUG: return
    frame = currentframe().f_back
    s = getframeinfo(frame).code_context[0]
    r = search(r"\((.*)\)", s).group(1)
    vnames = r.split(', ')
    id5 = [f'{var}={val}' for var, val in zip(vnames, args)]
    prefix = f'{currentframe().f_back.f_lineno:02d}: '
    print(f'{prefix}{", ".join(id5)}')


INF = float('inf')



class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id15 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id14 = []
        self._rebuild = True

    def add(self, value):
        
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        id15 = self.id15

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id15[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id15.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id15[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id15.append(1)
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
        if _len == self._len: raise ValueError('{0!r} not in list'.format(value))

    def pop(self, index=-1):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id2(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id4(pos) + idx

    def id10(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id4(pos) + idx

    def count(self, value):
        
        return self.id10(value) - self.id2(value)

    def id0(self):
        
        self.id14[:] = self.id15
        id14 = self.id14
        for i in range(len(id14)):
            if i | i + 1 < len(id14):
                id14[i | i + 1] += id14[i]
        self._rebuild = False

    def id1(self, index, value):
        
        if not self._rebuild:
            id14 = self.id14
            while index < len(id14):
                id14[index] += value
                index |= index + 1

    def id4(self, end):
        
        if self._rebuild: self.id0()
        id14 = self.id14
        x = 0
        while end:
            x += id14[end - 1]
            end &= end - 1
        return x

    def id3(self, k):
        
        id15 = self.id15
        if k < id15[0]: return 0, k
        if k >= self._len - id15[-1]: return len(id15) - 1, k + id15[-1] - self._len
        if self._rebuild: self.id0()

        id14 = self.id14
        idx = -1
        for d in reversed(range(len(id14).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id14) and k >= id14[right_idx]:
                idx = right_idx
                k -= id14[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id15 = self.id15

        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id15[pos] -= 1

        if id15[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id15[pos]
            del _mins[pos]
            self._rebuild = True

    def _loc_left(self, value):
        
        if not self._len: return 0, 0
        _lists = self._lists
        _mins = self._mins

        lo, pos = -1, len(_lists) - 1
        while lo + 1 < pos:
            mi = (lo + pos) >> 1
            if value <= _mins[mi]: pos = mi
            else: lo = mi

        if pos and value <= _lists[pos - 1][-1]: pos -= 1

        _list = _lists[pos]
        lo, idx = -1, len(_list)
        while lo + 1 < idx:
            mi = (lo + idx) >> 1
            if value <= _list[mi]: idx = mi
            else: lo = mi

        return pos, idx

    def _loc_right(self, value):
        
        if not self._len: return 0, 0
        _lists = self._lists
        _mins = self._mins

        pos, hi = 0, len(_lists)
        while pos + 1 < hi:
            mi = (pos + hi) >> 1
            if value < _mins[mi]: hi = mi
            else: pos = mi

        _list = _lists[pos]
        lo, idx = -1, len(_list)
        while lo + 1 < idx:
            mi = (lo + idx) >> 1
            if value < _list[mi]: idx = mi
            else: lo = mi

        return pos, idx

    def id17(self):
        
        return self._len

    def id11(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id9(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id8(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id16(self):
        
        return (value for _list in self._lists for value in _list)

    def id13(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id7(self):
        
        return 'SortedList({0})'.format(list(self))
 
    def val(self, it):  
        
        pos, idx = it
        return self._lists[pos][idx]
 
    def begin(self):  
        
        return (0, 0)
 
    def end(self):  
        
        return (len(self._lists)-1, len(self._lists[-1])) if self._lists else (0, 0)
 
    def prev(self, it):  
        
        if it == self.begin(): raise ValueError('{0!r} already list begin'.format(it))
        pos, idx = it
        return (pos, idx-1) if idx else (pos-1, len(self._lists[pos-1])-1)
 
    def next(self, it):  
        
        if it == self.end(): raise ValueError('{0!r} already list end'.format(it))
        pos, idx = it
        return (pos, idx+1) if pos+1 == len(self._lists) or idx+1 != len(self._lists[pos]) else (pos+1, 0)
 

class id6:
    def __init__(self, data, default=INF, func=min):
        
        self._default = default
        self._func = func

        self._len = len(data)                                   
        self._size = _size = 1 << (self._len - 1).bit_length()  
        self._lazy = [0] * (2 * _size)                          

        self.data = [default] * (2 * _size)                     
        self.data[_size:_size + self._len] = data               
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[2*i], self.data[2*i + 1])

    def _push(self, idx):
        
        
        q, self._lazy[idx] = self._lazy[idx], 0

        
        self._lazy[2 * idx] += q
        self._lazy[2 * idx + 1] += q
        self.data[2 * idx] += q
        self.data[2 * idx + 1] += q

    def _update(self, idx):
        
        for i in reversed(range(1, idx.bit_length())):
            self._push(idx >> i)

    def _build(self, idx):
        
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1]) + self._lazy[idx]
            idx >>= 1

    def add(self, start, stop, value):
        
        start = start_copy = start + self._size  
        stop = stop_copy = stop + self._size
        while start < stop:
            if start & 1:
                self._lazy[start] += value
                self.data[start] += value
                start += 1
            if stop & 1:
                stop -= 1
                self._lazy[stop] += value
                self.data[stop] += value
            start >>= 1
            stop >>= 1

        
        self._build(start_copy)
        self._build(stop_copy - 1)

    def set(self, start, stop, value):
        
        start = start_copy = start + self._size
        stop = stop_copy = stop + self._size
        while start < stop:
            if start & 1:
                self._lazy[start] = value
                self.data[start] = value
                start += 1
            if stop & 1:
                stop -= 1
                self._lazy[stop] = value
                self.data[stop] = value
            start >>= 1
            stop >>= 1
 
        
        self._build(start_copy)
        self._build(stop_copy - 1)

    def query(self, start, stop, default=INF):
        
        start += self._size
        stop += self._size

        
        self._update(start)
        self._update(stop - 1)

        res = default
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

    def id17(self):
        return self._len

    def id7(self):
        return 'id6({0})'.format(self.data)














def solve(N, Q, queries):
    
    cands = SortedList(list(range(N)))
    
    
    
    right = [INF] * N
    id12 = id6([INF]*N)
    
    res = []
    for ts in queries:
        if ts[0] == 0:
            l, r, x = ts[1]-1, ts[2]-1, ts[3]
            if x == 0:  
                if not cands: continue
                idx = cands.id2(l)
                while idx < len(cands):
                    if cands[idx] > r: break
                    cands.remove(cands[idx])
            else:      
                if right[l] > r:
                    right[l] = r
                    id12.set(l, l+1, r)

        else:
            j = ts[1] - 1
            if j not in cands: res.append('NO')
            else:
                idx = cands.id2(j)
                l = cands[idx-1] if idx > 0 else -1
                r = cands[idx+1] if idx+1 < len(cands) else N
                k = id12.query(l+1, r)
                if k < r: res.append('YES')
                else: res.append('N/A')
        
    return res


def test_re():
    import traceback
    import random
    random.seed(123)

    for _ in range(500):
        N = random.randint(1, 10)
        Q = random.randint(1, 5000)
        queries = []
        for _ in range(Q):
            if random.randint(0, 2) == 0:
                l = random.randint(1, max(1, N-1))
                r = random.randint(l, N)
                v = random.randint(0, 1)
                queries.append((0, l, r, v))
            else:
                j = random.randint(1, N)
                queries.append((1, j))
        try:
            solve(N, Q, queries)
        except Exception:
            print(traceback.format_exc())
    
    print('tests ran without RE')


def main():
    N, Q = list(map(int, input().split()))
    queries = [list(map(int, input().split())) for _ in range(Q)]
    out = solve(N, Q, queries)
    print('\n'.join(out))


if __name__ == '__main__':
    main()
    


