
import random
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
 
 
def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()
 
 
if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
 
input = lambda: sys.stdin.readline().rstrip("\r\n")

class TreapMultiSet(object):
    root = 0
    size = 0

    def __init__(self, data=None):
        if data:
            data = sorted(data)
            self.root = treap_builder(data)
            self.size = len(data)

    def add(self, key):
        self.root = treap_insert(self.root, key)
        self.size += 1

    def remove(self, key):
        self.root = treap_erase(self.root, key)
        self.size -= 1

    def discard(self, key):
        try:
            self.remove(key)
        except KeyError:
            pass

    def ceiling(self, key):
        x = treap_ceiling(self.root, key)
        return treap_keys[x] if x else None

    def higher(self, key):
        x = treap_higher(self.root, key)
        return treap_keys[x] if x else None

    def floor(self, key):
        x = treap_floor(self.root, key)
        return treap_keys[x] if x else None

    def lower(self, key):
        x = treap_lower(self.root, key)
        return treap_keys[x] if x else None

    def max(self):
        return treap_keys[treap_max(self.root)]

    def min(self):
        return treap_keys[treap_min(self.root)]

    def __len__(self):
        return self.size

    def __nonzero__(self):
        return bool(self.root)

    __bool__ = __nonzero__

    def __contains__(self, key):
        return self.floor(key) == key

    def __repr__(self):
        return "TreapMultiSet({})".format(list(self))

    def __iter__(self):
        if not self.root:
            return iter([])
        out = []
        stack = [self.root]
        while stack:
            node = stack.pop()
            if node > 0:
                if right_child[node]:
                    stack.append(right_child[node])
                stack.append(~node)
                if left_child[node]:
                    stack.append(left_child[node])
            else:
                out.append(treap_keys[~node])
        return iter(out)


class TreapSet(TreapMultiSet):
    def add(self, key):
        self.root, duplicate = treap_insert_unique(self.root, key)
        if not duplicate:
            self.size += 1

    def __repr__(self):
        return "TreapSet({})".format(list(self))


class TreapHashSet(TreapMultiSet):
    def __init__(self, data=None):
        if data:
            self.keys = set(data)
            super(TreapHashSet, self).__init__(self.keys)
        else:
            self.keys = set()

    def add(self, key):
        if key not in self.keys:
            self.keys.add(key)
            super(TreapHashSet, self).add(key)

    def remove(self, key):
        self.keys.remove(key)
        super(TreapHashSet, self).remove(key)

    def discard(self, key):
        if key in self.keys:
            self.remove(key)

    def __contains__(self, key):
        return key in self.keys

    def __repr__(self):
        return "TreapHashSet({})".format(list(self))


class TreapHashMap(TreapMultiSet):
    def __init__(self, data=None):
        if data:
            self.map = dict(data)
            super(TreapHashMap, self).__init__(self.map.keys())
        else:
            self.map = dict()

    def __setitem__(self, key, value):
        if key not in self.map:
            super(TreapHashMap, self).add(key)
        self.map[key] = value

    def __getitem__(self, key):
        return self.map[key]

    def add(self, key):
        raise TypeError("add on TreapHashMap")

    def get(self, key, default=None):
        return self.map.get(key, default=default)

    def remove(self, key):
        self.map.pop(key)
        super(TreapHashMap, self).remove(key)

    def discard(self, key):
        if key in self.map:
            self.remove(key)

    def __contains__(self, key):
        return key in self.map

    def __repr__(self):
        return "TreapHashMap({})".format(list(self))


left_child = [0]
right_child = [0]
treap_keys = [0]
treap_prior = [0.0]
treap_key_cnt = [0]


def cnt(key):
    if key:
        return treap_key_cnt[key]
    return 0


def upd_cnt(key):
    if key:
        treap_key_cnt[key] = 1 + cnt(left_child[key]) + cnt(right_child[key])


def treap_builder(sorted_data):
    """Build a treap in O(n) time using sorted data"""

    def build(begin, end):
        if begin == end:
            return 0
        mid = (begin + end) // 2
        root = treap_create_node(sorted_data[mid])
        left_child[root] = build(begin, mid)
        right_child[root] = build(mid + 1, end)

        
        ind = root
        while True:
            lc = left_child[ind]
            rc = right_child[ind]

            if lc and treap_prior[lc] > treap_prior[ind]:
                if rc and treap_prior[rc] > treap_prior[rc]:
                    treap_prior[ind], treap_prior[rc] = treap_prior[rc], treap_prior[ind]
                    ind = rc
                else:
                    treap_prior[ind], treap_prior[lc] = treap_prior[lc], treap_prior[ind]
                    ind = lc
            elif rc and treap_prior[rc] > treap_prior[ind]:
                treap_prior[ind], treap_prior[rc] = treap_prior[rc], treap_prior[ind]
                ind = rc
            else:
                break
        return root

    return build(0, len(sorted_data))


def treap_create_node(key):
    treap_keys.append(key)
    treap_prior.append(random.random())
    left_child.append(0)
    right_child.append(0)
    treap_key_cnt.append(0)
    return len(treap_keys) - 1


def treap_split(root, key):
    left_pos = right_pos = 0
    while root:
        if key < treap_keys[root]:
            left_child[right_pos] = right_pos = root
            root = left_child[root]
        else:
            right_child[left_pos] = left_pos = root
            root = right_child[root]
    left, right = right_child[0], left_child[0]
    right_child[left_pos] = left_child[right_pos] = right_child[0] = left_child[0] = 0
    return left, right


def treap_merge(left, right):
    where, pos = left_child, 0
    while left and right:
        if treap_prior[left] > treap_prior[right]:
            where[pos] = pos = left
            where = right_child
            left = right_child[left]
        else:
            where[pos] = pos = right
            where = left_child
            right = left_child[right]
    where[pos] = left or right
    node = left_child[0]
    left_child[0] = 0
    return node


def treap_insert(root, key):
    if not root:
        return treap_create_node(key)
    left, right = treap_split(root, key)
    return treap_merge(treap_merge(left, treap_create_node(key)), right)


def treap_insert_unique(root, key):
    if not root:
        return treap_create_node(key), False
    left, right = treap_split(root, key)
    if left and treap_keys[left] == key:
        return treap_merge(left, right), True
    return treap_merge(treap_merge(left, treap_create_node(key)), right), False


def treap_erase(root, key):
    if not root:
        raise KeyError(key)
    if treap_keys[root] == key:
        return treap_merge(left_child[root], right_child[root])
    node = root
    while root and treap_keys[root] != key:
        parent = root
        root = left_child[root] if key < treap_keys[root] else right_child[root]
    if not root:
        raise KeyError(key)
    if root == left_child[parent]:
        left_child[parent] = treap_merge(left_child[root], right_child[root])
    else:
        right_child[parent] = treap_merge(left_child[root], right_child[root])

    return node

def treap_k_largest(root, k):
    while root and treap_key_cnt[root] != k:
        if k < treap_key_cnt[root]:
            root = left_child[root]
        else:
            k -= treap_key_cnt[root]
            root = right_child[root]
    return root

def treap_ceiling(root, key):
    while root and treap_keys[root] < key:
        root = right_child[root]
    if not root:
        return 0
    min_node = root
    min_key = treap_keys[root]
    while root:
        if treap_keys[root] < key:
            root = right_child[root]
        else:
            if treap_keys[root] < min_key:
                min_key = treap_keys[root]
                min_node = root
            root = left_child[root]
    return min_node


def treap_higher(root, key):
    while root and treap_keys[root] <= key:
        root = right_child[root]
    if not root:
        return 0
    min_node = root
    min_key = treap_keys[root]
    while root:
        if treap_keys[root] <= key:
            root = right_child[root]
        else:
            if treap_keys[root] < min_key:
                min_key = treap_keys[root]
                min_node = root
            root = left_child[root]
    return min_node


def treap_floor(root, key):
    while root and treap_keys[root] > key:
        root = left_child[root]
    if not root:
        return 0
    max_node = root
    max_key = treap_keys[root]
    while root:
        if treap_keys[root] > key:
            root = left_child[root]
        else:
            if treap_keys[root] > max_key:
                max_key = treap_keys[root]
                max_node = root
            root = right_child[root]
    return max_node


def treap_lower(root, key):
    while root and treap_keys[root] >= key:
        root = left_child[root]
    if not root:
        return 0
    max_node = root
    max_key = treap_keys[root]
    while root:
        if treap_keys[root] >= key:
            root = left_child[root]
        else:
            if treap_keys[root] > max_key:
                max_key = treap_keys[root]
                max_node = root
            root = right_child[root]
    return max_node


def treap_min(root):
    if not root:
        raise ValueError("min on empty treap")
    while left_child[root]:
        root = left_child[root]
    return root


def treap_max(root):
    if not root:
        raise ValueError("max on empty treap")
    while right_child[root]:
        root = right_child[root]
    return root

class SortedList:
    
    def __init__(self, iterable=[], _load=200):
        """Initialize sorted list instance."""
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
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
            raise ValueError('{0!r} not in list'.format(value))

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
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def __repr__(self):
        """Return string representation of sorted list."""
        return 'SortedList({0})'.format(list(self))
    
t = int(input())
for _ in range(t):
    input()
    n,d = map(int, input().split())
    arr = [0] + list(map(int, input().split()))
    treap = SortedList()
    left = [0 for i in range(len(arr))]
    right = [0 for i in range(len(arr))]
   
    for i in range(1,len(arr)):
        leng = arr[i] - arr[i - 1] - 1
        treap.add(leng)
        left[i] = leng
        right[i - 1] = leng

    ans = 0
    val = d - arr[-1] - 1
    for i in range(1, len(arr) - 1):
        leng_l = left[i]
        leng_r = right[i]
        comb = leng_l + leng_r + 1
        treap.add(comb)
        treap.remove(leng_l)
        treap.remove(leng_r)
        mx = max((treap[len(treap) - 1] - 1)//2, val)
        treap.add(mx)
        mi = treap[0]
        ans = max(ans, mi)
        
        treap.remove(mx)
        treap.remove(comb)
        treap.add(leng_l)
        treap.add(leng_r)

    treap.remove(left[-1])
    treap.add(d - arr[-2] - 1)
    ans = max(ans, treap[0])
    
    print(ans)
        
        
    
        
        
    
