
import random
import os
import sys
from io import BytesIO, IOBase

id31 = 8192



 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id31))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id31))
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

class id24(object):
    root = 0
    size = 0

    def __init__(self, data=None):
        if data:
            data = sorted(data)
            self.root = id11(data)
            self.size = len(data)

    def add(self, key):
        self.root = id22(self.root, key)
        self.size += 1

    def remove(self, key):
        self.root = id21(self.root, key)
        self.size -= 1

    def discard(self, key):
        try:
            self.remove(key)
        except KeyError:
            pass

    def ceiling(self, key):
        x = id29(self.root, key)
        return id1[x] if x else None

    def higher(self, key):
        x = id18(self.root, key)
        return id1[x] if x else None

    def floor(self, key):
        x = id17(self.root, key)
        return id1[x] if x else None

    def lower(self, key):
        x = id10(self.root, key)
        return id1[x] if x else None

    def max(self):
        return id1[id34(self.root)]

    def min(self):
        return id1[id15(self.root)]

    def id39(self):
        return self.size

    def id16(self):
        return bool(self.root)

    id9 = id16

    def id14(self, key):
        return self.floor(key) == key

    def id13(self):
        return "id24({})".format(list(self))

    def id38(self):
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
                out.append(id1[~node])
        return iter(out)


class id5(id24):
    def add(self, key):
        self.root, duplicate = id0(self.root, key)
        if not duplicate:
            self.size += 1

    def id13(self):
        return "id5({})".format(list(self))


class id25(id24):
    def __init__(self, data=None):
        if data:
            self.keys = set(data)
            super(id25, self).__init__(self.keys)
        else:
            self.keys = set()

    def add(self, key):
        if key not in self.keys:
            self.keys.add(key)
            super(id25, self).add(key)

    def remove(self, key):
        self.keys.remove(key)
        super(id25, self).remove(key)

    def discard(self, key):
        if key in self.keys:
            self.remove(key)

    def id14(self, key):
        return key in self.keys

    def id13(self):
        return "id25({})".format(list(self))


class id27(id24):
    def __init__(self, data=None):
        if data:
            self.map = dict(data)
            super(id27, self).__init__(self.map.keys())
        else:
            self.map = dict()

    def id20(self, key, value):
        if key not in self.map:
            super(id27, self).add(key)
        self.map[key] = value

    def id28(self, key):
        return self.map[key]

    def add(self, key):
        raise TypeError("add on id27")

    def get(self, key, default=None):
        return self.map.get(key, default=default)

    def remove(self, key):
        self.map.pop(key)
        super(id27, self).remove(key)

    def discard(self, key):
        if key in self.map:
            self.remove(key)

    def id14(self, key):
        return key in self.map

    def id13(self):
        return "id27({})".format(list(self))


left_child = [0]
right_child = [0]
id1 = [0]
id8 = [0.0]
id12 = [0]


def cnt(key):
    if key:
        return id12[key]
    return 0


def upd_cnt(key):
    if key:
        id12[key] = 1 + cnt(left_child[key]) + cnt(right_child[key])


def id11(sorted_data):
    

    def build(begin, end):
        if begin == end:
            return 0
        mid = (begin + end) // 2
        root = id37(sorted_data[mid])
        left_child[root] = build(begin, mid)
        right_child[root] = build(mid + 1, end)

        
        ind = root
        while True:
            lc = left_child[ind]
            rc = right_child[ind]

            if lc and id8[lc] > id8[ind]:
                if rc and id8[rc] > id8[rc]:
                    id8[ind], id8[rc] = id8[rc], id8[ind]
                    ind = rc
                else:
                    id8[ind], id8[lc] = id8[lc], id8[ind]
                    ind = lc
            elif rc and id8[rc] > id8[ind]:
                id8[ind], id8[rc] = id8[rc], id8[ind]
                ind = rc
            else:
                break
        return root

    return build(0, len(sorted_data))


def id37(key):
    id1.append(key)
    id8.append(random.random())
    left_child.append(0)
    right_child.append(0)
    id12.append(0)
    return len(id1) - 1


def id19(root, key):
    left_pos = right_pos = 0
    while root:
        if key < id1[root]:
            left_child[right_pos] = right_pos = root
            root = left_child[root]
        else:
            right_child[left_pos] = left_pos = root
            root = right_child[root]
    left, right = right_child[0], left_child[0]
    right_child[left_pos] = left_child[right_pos] = right_child[0] = left_child[0] = 0
    return left, right


def id30(left, right):
    where, pos = left_child, 0
    while left and right:
        if id8[left] > id8[right]:
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


def id22(root, key):
    if not root:
        return id37(key)
    left, right = id19(root, key)
    return id30(id30(left, id37(key)), right)


def id0(root, key):
    if not root:
        return id37(key), False
    left, right = id19(root, key)
    if left and id1[left] == key:
        return id30(left, right), True
    return id30(id30(left, id37(key)), right), False


def id21(root, key):
    if not root:
        raise KeyError(key)
    if id1[root] == key:
        return id30(left_child[root], right_child[root])
    node = root
    while root and id1[root] != key:
        parent = root
        root = left_child[root] if key < id1[root] else right_child[root]
    if not root:
        raise KeyError(key)
    if root == left_child[parent]:
        left_child[parent] = id30(left_child[root], right_child[root])
    else:
        right_child[parent] = id30(left_child[root], right_child[root])

    return node

def id32(root, k):
    while root and id12[root] != k:
        if k < id12[root]:
            root = left_child[root]
        else:
            k -= id12[root]
            root = right_child[root]
    return root

def id29(root, key):
    while root and id1[root] < key:
        root = right_child[root]
    if not root:
        return 0
    min_node = root
    min_key = id1[root]
    while root:
        if id1[root] < key:
            root = right_child[root]
        else:
            if id1[root] < min_key:
                min_key = id1[root]
                min_node = root
            root = left_child[root]
    return min_node


def id18(root, key):
    while root and id1[root] <= key:
        root = right_child[root]
    if not root:
        return 0
    min_node = root
    min_key = id1[root]
    while root:
        if id1[root] <= key:
            root = right_child[root]
        else:
            if id1[root] < min_key:
                min_key = id1[root]
                min_node = root
            root = left_child[root]
    return min_node


def id17(root, key):
    while root and id1[root] > key:
        root = left_child[root]
    if not root:
        return 0
    max_node = root
    max_key = id1[root]
    while root:
        if id1[root] > key:
            root = left_child[root]
        else:
            if id1[root] > max_key:
                max_key = id1[root]
                max_node = root
            root = right_child[root]
    return max_node


def id10(root, key):
    while root and id1[root] >= key:
        root = left_child[root]
    if not root:
        return 0
    max_node = root
    max_key = id1[root]
    while root:
        if id1[root] >= key:
            root = left_child[root]
        else:
            if id1[root] > max_key:
                max_key = id1[root]
                max_node = root
            root = right_child[root]
    return max_node


def id15(root):
    if not root:
        raise ValueError("min on empty treap")
    while left_child[root]:
        root = left_child[root]
    return root


def id34(root):
    if not root:
        raise ValueError("max on empty treap")
    while right_child[root]:
        root = right_child[root]
    return root

class SortedList:
    
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id36 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id35 = []
        self._rebuild = True

    def id2(self):
        
        self.id35[:] = self.id36
        id35 = self.id35
        for i in range(len(id35)):
            if i | i + 1 < len(id35):
                id35[i | i + 1] += id35[i]
        self._rebuild = False

    def id3(self, index, value):
        
        if not self._rebuild:
            id35 = self.id35
            while index < len(id35):
                id35[index] += value
                index |= index + 1

    def id7(self, end):
        
        if self._rebuild:
            self.id2()

        id35 = self.id35
        x = 0
        while end:
            x += id35[end - 1]
            end &= end - 1
        return x

    def id6(self, k):
        
        id36 = self.id36
        if k < id36[0]:
            return 0, k
        if k >= self._len - id36[-1]:
            return len(id36) - 1, k + id36[-1] - self._len
        if self._rebuild:
            self.id2()

        id35 = self.id35
        idx = -1
        for d in reversed(range(len(id35).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id35) and k >= id35[right_idx]:
                idx = right_idx
                k -= id35[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id36 = self.id36

        self._len -= 1
        self.id3(pos, -1)
        del _lists[pos][idx]
        id36[pos] -= 1

        if id36[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id36[pos]
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
        id36 = self.id36

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id3(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id36[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id36.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id36[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id36.append(1)
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
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id4(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id7(pos) + idx

    def id26(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id7(pos) + idx

    def count(self, value):
        
        return self.id26(value) - self.id4(value)

    def id39(self):
        
        return self._len

    def id28(self, index):
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id23(self, index):
        
        pos, idx = self.id6(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id14(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id38(self):
        
        return (value for _list in self._lists for value in _list)

    def id33(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id13(self):
        
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
        
        
    
        
        
    
