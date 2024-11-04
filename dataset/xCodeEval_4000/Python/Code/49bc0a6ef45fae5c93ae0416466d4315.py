import io
import os




def dijkstra(*args):
    
    
    return dijkstraHeapComparator(*args)
    
    


def dijkstraHeap(source, N, getAdj):
    

    
    

    from heapq import heappop, heappush

    inf = float("inf")
    dist = [inf] * N
    dist[source] = 0.0
    queue = [(0.0, float(source))]
    
    
    while queue:
        d, u = heappop(queue)
        u = int(u)
        if dist[u] == d:
            for v, w in getAdj(u):
                cost = d + w
                if cost < dist[v]:
                    dist[v] = cost
                    heappush(queue, (cost, float(v)))
    return dist


def dijkstraHeapComparatorWrong(source, N, getAdj):
    
    
    

    inf = float("inf")
    dist = [inf] * N
    dist[source] = 0.0
    inQueue = [0] * N
    inQueue[source] = 1
    queue = [source]
    

    def cmp_lt(u, v):
        return dist[u] < dist[v]

    heappush, heappop, _ = import_heapq(cmp_lt)

    while queue:
        u = heappop(queue)
        d = dist[u]
        inQueue[u] = 0
        for v, w in getAdj(u):
            cost = d + w
            if cost < dist[v]:
                dist[v] = cost
                if not inQueue[v]:
                    heappush(queue, v)
                    inQueue[v] = 1
                else:
                    
                    pass
    return dist


def dijkstraHeapComparator(source, N, getAdj):
    

    inf = float("inf")
    dist = [inf] * N
    dist[source] = 0.0

    def cmp_lt(u, v):
        return dist[u] < dist[v]

    heappush, heappop, _siftdown = import_heapq(cmp_lt)

    class ListWrapper:
        
        

        def __init__(self, maxN):
            self.arr = []
            self.loc = [-1] * maxN

        def append(self, x):
            arr = self.arr
            arr.append(x)
            self.loc[x] = len(arr) - 1

        def pop(self):
            ret = self.arr.pop()
            self.loc[ret] = -1
            return ret

        def index(self, x):
            return self.loc[x]

        def __setitem__(self, i, x):
            self.arr[i] = x
            self.loc[x] = i

        def __getitem__(self, i):
            return self.arr[i]

        def __len__(self):
            return len(self.arr)

    queue = ListWrapper(N)
    queue.append(source)
    

    while queue:
        u = heappop(queue)
        d = dist[u]
        for v, w in getAdj(u):
            cost = d + w
            if cost < dist[v]:
                dist[v] = cost
                heapIndex = queue.index(v)
                if heapIndex == -1:
                    heappush(queue, v)
                else:
                    _siftdown(queue, 0, heapIndex)
    return dist


def dijkstraSegTree(start, n, getAdj):
    
    
    
    
    
    
    

    if True:
        inf = -1

        def _min(a, b):
            return a if b == inf or inf != a < b else b

    else:
        inf = float("inf")
        _min = min

    class DistanceKeeper:
        def __init__(self, n):
            m = 1
            while m < n:
                m *= 2
            self.m = m
            self.data = 2 * m * [inf]
            self.dist = n * [inf]

        def __getitem__(self, x):
            return self.dist[x]

        def __setitem__(self, ind, x):
            data = self.data
            self.dist[ind] = x
            ind += self.m
            data[ind] = x
            ind >>= 1
            while ind:
                data[ind] = _min(data[2 * ind], data[2 * ind + 1])
                ind >>= 1

        def trav(self):
            m = self.m
            data = self.data
            dist = self.dist
            while data[1] != inf:
                x = data[1]

                ind = 1
                while ind < m:
                    ind = 2 * ind + (data[2 * ind] != x)
                ind -= m

                self[ind] = inf
                dist[ind] = x
                yield ind

    
    D = DistanceKeeper(n)
    D[start] = 0.0

    for node in D.trav():
        for nei, weight in getAdj(node):
            new_dist = D[node] + weight
            if D[nei] == inf or new_dist < D[nei]:
                D[nei] = new_dist
                
    
    
    return D.dist


def dijkstraSortedList(source, N, getAdj):
    

    
    class SortedList:
        def __init__(self, iterable=[], _load=200):
            """Initialize sorted list instance."""
            values = sorted(iterable)
            self._len = _len = len(values)
            self._load = _load
            self._lists = _lists = [
                values[i : i + _load] for i in range(0, _len, _load)
            ]
            self._list_lens = [len(_list) for _list in _lists]
            self._mins = [_list[0] for _list in _lists]
            self._fen_tree = []
            self._rebuild = True

        def _fen_build(self):
            """Build a fenwick tree instance."""
            self._fen_tree[:] = self._list_lens
            _fen_tree = self._fen_tree
            for i in range(len(_fen_tree)):
                if i | i + 1 < len(_fen_tree):
                    _fen_tree[i | i + 1] += _fen_tree[i]
            self._rebuild = False

        def _fen_update(self, index, value):
            """Update `fen_tree[index] += value`."""
            if not self._rebuild:
                _fen_tree = self._fen_tree
                while index < len(_fen_tree):
                    _fen_tree[index] += value
                    index |= index + 1

        def _fen_query(self, end):
            """Return `sum(_fen_tree[:end])`."""
            if self._rebuild:
                self._fen_build()

            _fen_tree = self._fen_tree
            x = 0
            while end:
                x += _fen_tree[end - 1]
                end &= end - 1
            return x

        def _fen_findkth(self, k):
            """Return a pair of (the largest `idx` such that `sum(_fen_tree[:idx]) <= k`, `k - sum(_fen_tree[:idx])`)."""
            _list_lens = self._list_lens
            if k < _list_lens[0]:
                return 0, k
            if k >= self._len - _list_lens[-1]:
                return len(_list_lens) - 1, k + _list_lens[-1] - self._len
            if self._rebuild:
                self._fen_build()

            _fen_tree = self._fen_tree
            idx = -1
            for d in reversed(range(len(_fen_tree).bit_length())):
                right_idx = idx + (1 << d)
                if right_idx < len(_fen_tree) and k >= _fen_tree[right_idx]:
                    idx = right_idx
                    k -= _fen_tree[idx]
            return idx + 1, k

        def _delete(self, pos, idx):
            """Delete value at the given `(pos, idx)`."""
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
            """Return an index pair that corresponds to the first position of `value` in the sorted list."""
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
            """Return an index pair that corresponds to the last position of `value` in the sorted list."""
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
            """Add `value` to sorted list."""
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
            """Remove `value` from sorted list if it is a member."""
            _lists = self._lists
            if _lists:
                pos, idx = self._loc_right(value)
                if idx and _lists[pos][idx - 1] == value:
                    self._delete(pos, idx - 1)

        def remove(self, value):
            """Remove `value` from sorted list; `value` must be a member."""
            _len = self._len
            self.discard(value)
            if _len == self._len:
                raise ValueError("{0!r} not in list".format(value))

        def pop(self, index=-1):
            """Remove and return value at `index` in sorted list."""
            pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
            value = self._lists[pos][idx]
            self._delete(pos, idx)
            return value

        def bisect_left(self, value):
            """Return the first index to insert `value` in the sorted list."""
            pos, idx = self._loc_left(value)
            return self._fen_query(pos) + idx

        def bisect_right(self, value):
            """Return the last index to insert `value` in the sorted list."""
            pos, idx = self._loc_right(value)
            return self._fen_query(pos) + idx

        def count(self, value):
            """Return number of occurrences of `value` in the sorted list."""
            return self.bisect_right(value) - self.bisect_left(value)

        def __len__(self):
            """Return the size of the sorted list."""
            return self._len

        def __getitem__(self, index):
            """Lookup value at `index` in sorted list."""
            pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
            return self._lists[pos][idx]

        def __delitem__(self, index):
            """Remove value at `index` from sorted list."""
            pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
            self._delete(pos, idx)

        def __contains__(self, value):
            """Return true if `value` is an element of the sorted list."""
            _lists = self._lists
            if _lists:
                pos, idx = self._loc_left(value)
                return idx < len(_lists[pos]) and _lists[pos][idx] == value
            return False

        def __iter__(self):
            """Return an iterator over the sorted list."""
            return (value for _list in self._lists for value in _list)

        def __reversed__(self):
            """Return a reverse iterator over the sorted list."""
            return (
                value for _list in reversed(self._lists) for value in reversed(_list)
            )

        def __repr__(self):
            """Return string representation of sorted list."""
            return "SortedList({0})".format(list(self))

    

    inf = float("inf")
    dist = [inf] * N
    dist[source] = 0.0
    queue = SortedList([(0.0, float(source))])
    while queue:
        negD, u = queue.pop(-1)
        d = -negD
        u = int(u)
        for v, w in getAdj(u):
            prevCost = dist[v]
            cost = d + w
            if cost < prevCost:
                if prevCost != inf:
                    queue.discard((-prevCost, float(v)))
                dist[v] = cost
                queue.add((-cost, float(v)))
    return dist


def import_heapq(cmp_lt):
    
    

    import sys

    if sys.version_info < (3,):
        
        import heapq
        from heapq import heappush, heappop, _siftdown

        heapq.cmp_lt = cmp_lt
    else:
        
        

        def heappush(heap, item):
            """Push item onto heap, maintaining the heap invariant."""
            heap.append(item)
            _siftdown(heap, 0, len(heap) - 1)

        def heappop(heap):
            """Pop the smallest item off the heap, maintaining the heap invariant."""
            lastelt = heap.pop()  
            if heap:
                returnitem = heap[0]
                heap[0] = lastelt
                _siftup(heap, 0)
                return returnitem
            return lastelt

        def _siftdown(heap, startpos, pos):
            newitem = heap[pos]
            
            
            while pos > startpos:
                parentpos = (pos - 1) >> 1
                parent = heap[parentpos]
                if cmp_lt(newitem, parent):
                    heap[pos] = parent
                    pos = parentpos
                    continue
                break
            heap[pos] = newitem

        def _siftup(heap, pos):
            endpos = len(heap)
            startpos = pos
            newitem = heap[pos]
            
            childpos = 2 * pos + 1  
            while childpos < endpos:
                
                rightpos = childpos + 1
                if rightpos < endpos and not cmp_lt(heap[childpos], heap[rightpos]):
                    childpos = rightpos
                
                heap[pos] = heap[childpos]
                pos = childpos
                childpos = 2 * pos + 1
            
            
            heap[pos] = newitem
            _siftdown(heap, startpos, pos)

        
    return heappush, heappop, _siftdown


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    N, M = [int(x) for x in input().split()]
    graph = [[] for i in range(N)]
    for i in range(M):
        u, v, w = [int(x) for x in input().split()]
        u -= 1
        v -= 1
        graph[u].append((v, w))
        graph[v].append((u, w))

    
    
    def getAdj(node):
        u = node >> 2
        state = node & 3
        for v, w in graph[u]:
            vBase = v << 2
            
            yield vBase | state, w
            if not state & 1:
                
                yield vBase | state | 1, 0
            if not state & 2:
                
                yield vBase | state | 2, 2 * w
            if not state & 3:
                
                yield vBase | state | 3, w

    dist = dijkstra(0, 4 * N, getAdj)
    print(" ".join(str(int(dist[(u << 2) | 3])) for u in range(1, N)))
