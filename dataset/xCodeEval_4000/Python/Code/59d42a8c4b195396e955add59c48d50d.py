''' E. Anonymity Is Important
https://codeforces.com/contest/1642/problem/E
'''

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
    var_and_vals = [f'{var}={val}' for var, val in zip(vnames, args)]
    prefix = f'{currentframe().f_back.f_lineno:02d}: '
    print(f'{prefix}{", ".join(var_and_vals)}')


INF = float('inf')



class SortedList:
    def __init__(self, iterable=[], _load=200):
        '''Initialize sorted list instance.'''
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self._list_lens = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self._fen_tree = []
        self._rebuild = True

    def add(self, value):
        '''Add `value` to sorted list.'''
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self._fen_update(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            _list_lens[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                _list_lens.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                _list_lens[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            _list_lens.append(1)
            self._rebuild = True

    def discard(self, value):
        '''Remove `value` from sorted list if it is a member.'''
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_right(value)
            if idx and _lists[pos][idx - 1] == value:
                self._delete(pos, idx - 1)

    def remove(self, value):
        '''Remove `value` from sorted list; `value` must be a member.'''
        _len = self._len
        self.discard(value)
        if _len == self._len: raise ValueError('{0!r} not in list'.format(value))

    def pop(self, index=-1):
        '''Remove and return value at `index` in sorted list.'''
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def bisect_left(self, value):
        '''Return the first index to insert `value` in the sorted list.'''
        pos, idx = self._loc_left(value)
        return self._fen_query(pos) + idx

    def bisect_right(self, value):
        '''Return the last index to insert `value` in the sorted list.'''
        pos, idx = self._loc_right(value)
        return self._fen_query(pos) + idx

    def count(self, value):
        '''Return number of occurrences of `value` in the sorted list.'''
        return self.bisect_right(value) - self.bisect_left(value)

    def _fen_build(self):
        '''Build a fenwick tree instance.'''
        self._fen_tree[:] = self._list_lens
        _fen_tree = self._fen_tree
        for i in range(len(_fen_tree)):
            if i | i + 1 < len(_fen_tree):
                _fen_tree[i | i + 1] += _fen_tree[i]
        self._rebuild = False

    def _fen_update(self, index, value):
        '''Update `fen_tree[index] += value`.'''
        if not self._rebuild:
            _fen_tree = self._fen_tree
            while index < len(_fen_tree):
                _fen_tree[index] += value
                index |= index + 1

    def _fen_query(self, end):
        '''Return `sum(_fen_tree[:end])`.'''
        if self._rebuild: self._fen_build()
        _fen_tree = self._fen_tree
        x = 0
        while end:
            x += _fen_tree[end - 1]
            end &= end - 1
        return x

    def _fen_findkth(self, k):
        '''Return a pair of (the largest `idx` such that `sum(_fen_tree[:idx]) <= k`, `k - sum(_fen_tree[:idx])`).'''
        _list_lens = self._list_lens
        if k < _list_lens[0]: return 0, k
        if k >= self._len - _list_lens[-1]: return len(_list_lens) - 1, k + _list_lens[-1] - self._len
        if self._rebuild: self._fen_build()

        _fen_tree = self._fen_tree
        idx = -1
        for d in reversed(range(len(_fen_tree).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(_fen_tree) and k >= _fen_tree[right_idx]:
                idx = right_idx
                k -= _fen_tree[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        '''Delete value at the given `(pos, idx)`.'''
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens

        self._len -= 1
        self._fen_update(pos, -1)
        del _lists[pos][idx]
        _list_lens[pos] -= 1

        if _list_lens[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del _list_lens[pos]
            del _mins[pos]
            self._rebuild = True

    def _loc_left(self, value):
        '''Return an index pair that corresponds to the first position of `value` in the sorted list.'''
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
        '''Return an index pair that corresponds to the last position of `value` in the sorted list.'''
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

    def __len__(self):
        '''Return the size of the sorted list.'''
        return self._len

    def __getitem__(self, index):
        '''Lookup value at `index` in sorted list.'''
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def __delitem__(self, index):
        '''Remove value at `index` from sorted list.'''
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def __contains__(self, value):
        '''Return true if `value` is an element of the sorted list.'''
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def __iter__(self):
        '''Return an iterator over the sorted list.'''
        return (value for _list in self._lists for value in _list)

    def __reversed__(self):
        '''Return a reverse iterator over the sorted list.'''
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def __repr__(self):
        '''Return string representation of sorted list.'''
        return 'SortedList({0})'.format(list(self))
 
    def val(self, it):  
        '''Return the value of the `it` in the sorted list.'''
        pos, idx = it
        return self._lists[pos][idx]
 
    def begin(self):  
        '''Return the begin of the it in the sorted list.'''
        return (0, 0)
 
    def end(self):  
        '''Return the end of the it in the sorted list.'''
        return (len(self._lists)-1, len(self._lists[-1])) if self._lists else (0, 0)
 
    def prev(self, it):  
        '''Return the previous `it` in the sorted list.'''
        if it == self.begin(): raise ValueError('{0!r} already list begin'.format(it))
        pos, idx = it
        return (pos, idx-1) if idx else (pos-1, len(self._lists[pos-1])-1)
 
    def next(self, it):  
        '''Return the next `it` in the sorted list.'''
        if it == self.end(): raise ValueError('{0!r} already list end'.format(it))
        pos, idx = it
        return (pos, idx+1) if pos+1 == len(self._lists) or idx+1 != len(self._lists[pos]) else (pos+1, 0)
 

class LazySegmentTree:
    def __init__(self, data, default=INF, func=min):
        '''
        initialize the lazy segment tree with data
        func must return one of its input (e.g. min/max, not mult/add/sub)
        '''
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
        '''push pending update on idx to its children'''
        
        q, self._lazy[idx] = self._lazy[idx], 0

        
        self._lazy[2 * idx] += q
        self._lazy[2 * idx + 1] += q
        self.data[2 * idx] += q
        self.data[2 * idx + 1] += q

    def _update(self, idx):
        '''update idx by pulling update from ancestors'''
        for i in reversed(range(1, idx.bit_length())):
            self._push(idx >> i)

    def _build(self, idx):
        '''make the changes to idx be known to its ancestors. CHANGE HERE'''
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1]) + self._lazy[idx]
            idx >>= 1

    def add(self, start, stop, value):
        '''lazily add value to [start, stop)'''
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
        """lazily set value to [start, stop)"""
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
        '''func of data[start, stop)'''
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

    def __len__(self):
        return self._len

    def __repr__(self):
        return 'LazySegmentTree({0})'.format(self.data)














def solve(N, Q, queries):
    
    cands = SortedList(list(range(N)))
    
    
    
    right = [INF] * N
    segtree = LazySegmentTree([INF]*N)
    
    res = []
    for ts in queries:
        if ts[0] == 0:
            l, r, x = ts[1]-1, ts[2]-1, ts[3]
            if x == 0:  
                if not cands: continue
                idx = cands.bisect_left(l)
                while idx < len(cands):
                    if cands[idx] > r: break
                    cands.remove(cands[idx])
            else:      
                if right[l] > r:
                    right[l] = r
                    segtree.set(l, l+1, r)

        else:
            j = ts[1] - 1
            if j not in cands: res.append('NO')
            else:
                idx = cands.bisect_left(j)
                l = cands[idx-1] if idx > 0 else -1
                r = cands[idx+1] if idx+1 < len(cands) else N
                k = segtree.query(l+1, r)
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
    


