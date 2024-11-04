import io
import os




def dijkstra(*args):
    
    return id2(*args)  
    
    
    


def id8(source, N, getAdj):
    

    
    

    from heapq import id4, id12

    inf = float("inf")
    dist = [inf] * N
    dist[source] = 0.0
    queue = [(0.0, float(source))]
    
    
    while queue:
        d, u = id4(queue)
        u = int(u)
        if dist[u] == d:
            for v, w in getAdj(u):
                cost = d + w
                if cost < dist[v]:
                    dist[v] = cost
                    id12(queue, (cost, float(v)))
    return dist


def id2(source, N, getAdj):
    
    
    

    inf = float("inf")
    dist = [inf] * N
    dist[source] = 0.0
    inQueue = [0] * N
    inQueue[source] = 1
    queue = [source]
    

    def cmp_lt(u, v):
        return dist[u] < dist[v]

    id12, id4, _ = id13(cmp_lt)

    while queue:
        u = id4(queue)
        d = dist[u]
        inQueue[u] = 0
        for v, w in getAdj(u):
            cost = d + w
            if cost < dist[v]:
                dist[v] = cost
                if not inQueue[v]:
                    id12(queue, v)
                    inQueue[v] = 1
                
    return dist


def id7(source, N, getAdj):
    

    inf = float("inf")
    dist = [inf] * N
    dist[source] = 0.0

    def cmp_lt(u, v):
        return dist[u] < dist[v]

    id12, id4, id20 = id13(cmp_lt)

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

        def id14(self, i, x):
            self.arr[i] = x
            self.loc[x] = i

        def id18(self, i):
            return self.arr[i]

        def id25(self):
            return len(self.arr)

    queue = ListWrapper(N)
    queue.append(source)
    

    while queue:
        u = id4(queue)
        d = dist[u]
        for v, w in getAdj(u):
            cost = d + w
            if cost < dist[v]:
                dist[v] = cost
                heapIndex = queue.index(v)
                if heapIndex == -1:
                    id12(queue, v)
                else:
                    id20(queue, 0, heapIndex)
    return dist


def id15(start, n, getAdj):
    
    
    
    
    
    
    

    if False:
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

        def id18(self, x):
            return self.dist[x]

        def id14(self, ind, x):
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


def id11(source, N, getAdj):
    

    
    class SortedList:
        def __init__(self, iterable=[], _load=200):
            
            values = sorted(iterable)
            self._len = _len = len(values)
            self._load = _load
            self._lists = _lists = [
                values[i : i + _load] for i in range(0, _len, _load)
            ]
            self.id23 = [len(_list) for _list in _lists]
            self._mins = [_list[0] for _list in _lists]
            self.id22 = []
            self._rebuild = True

        def id0(self):
            
            self.id22[:] = self.id23
            id22 = self.id22
            for i in range(len(id22)):
                if i | i + 1 < len(id22):
                    id22[i | i + 1] += id22[i]
            self._rebuild = False

        def id1(self, index, value):
            
            if not self._rebuild:
                id22 = self.id22
                while index < len(id22):
                    id22[index] += value
                    index |= index + 1

        def id6(self, end):
            
            if self._rebuild:
                self.id0()

            id22 = self.id22
            x = 0
            while end:
                x += id22[end - 1]
                end &= end - 1
            return x

        def id5(self, k):
            
            id23 = self.id23
            if k < id23[0]:
                return 0, k
            if k >= self._len - id23[-1]:
                return len(id23) - 1, k + id23[-1] - self._len
            if self._rebuild:
                self.id0()

            id22 = self.id22
            idx = -1
            for d in reversed(range(len(id22).bit_length())):
                right_idx = idx + (1 << d)
                if right_idx < len(id22) and k >= id22[right_idx]:
                    idx = right_idx
                    k -= id22[idx]
            return idx + 1, k

        def _delete(self, pos, idx):
            
            _lists = self._lists
            _mins = self._mins
            id23 = self.id23

            self._len -= 1
            self.id1(pos, -1)
            del _lists[pos][idx]
            id23[pos] -= 1

            if id23[pos]:
                _mins[pos] = _lists[pos][0]
            else:
                del _lists[pos]
                del id23[pos]
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
            id23 = self.id23

            self._len += 1
            if _lists:
                pos, idx = self._loc_right(value)
                self.id1(pos, 1)
                _list = _lists[pos]
                _list.insert(idx, value)
                id23[pos] += 1
                _mins[pos] = _list[0]
                if _load + _load < len(_list):
                    _lists.insert(pos + 1, _list[_load:])
                    id23.insert(pos + 1, len(_list) - _load)
                    _mins.insert(pos + 1, _list[_load])
                    id23[pos] = _load
                    del _list[_load:]
                    self._rebuild = True
            else:
                _lists.append([value])
                _mins.append(value)
                id23.append(1)
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
            
            pos, idx = self.id5(self._len + index if index < 0 else index)
            value = self._lists[pos][idx]
            self._delete(pos, idx)
            return value

        def id3(self, value):
            
            pos, idx = self._loc_left(value)
            return self.id6(pos) + idx

        def id17(self, value):
            
            pos, idx = self._loc_right(value)
            return self.id6(pos) + idx

        def count(self, value):
            
            return self.id17(value) - self.id3(value)

        def id25(self):
            
            return self._len

        def id18(self, index):
            
            pos, idx = self.id5(self._len + index if index < 0 else index)
            return self._lists[pos][idx]

        def id16(self, index):
            
            pos, idx = self.id5(self._len + index if index < 0 else index)
            self._delete(pos, idx)

        def id10(self, value):
            
            _lists = self._lists
            if _lists:
                pos, idx = self._loc_left(value)
                return idx < len(_lists[pos]) and _lists[pos][idx] == value
            return False

        def id24(self):
            
            return (value for _list in self._lists for value in _list)

        def id21(self):
            
            return (
                value for _list in reversed(self._lists) for value in reversed(_list)
            )

        def id9(self):
            
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


def id13(cmp_lt):
    
    

    import sys

    if sys.version_info < (3,):
        
        import heapq
        from heapq import id12, id4, id20

        heapq.cmp_lt = cmp_lt
    else:
        
        

        def id12(heap, item):
            
            heap.append(item)
            id20(heap, 0, len(heap) - 1)

        def id4(heap):
            
            lastelt = heap.pop()  
            if heap:
                returnitem = heap[0]
                heap[0] = lastelt
                id19(heap, 0)
                return returnitem
            return lastelt

        def id20(heap, startpos, pos):
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

        def id19(heap, pos):
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
            id20(heap, startpos, pos)

        
    return id12, id4, id20


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
