
import os as _os
import sys as _sys
from functools import lru_cache as _lru_cache
from importlib.abc import ExecutionLoader, MetaPathFinder
from importlib.machinery import ModuleSpec


class InlineImporter(ExecutionLoader, MetaPathFinder):

    version = None
    inlined_modules = {}
    namespace_packages = False

    @classmethod
    def find_spec(cls, fullname, path=None, target=None):
        """Find a spec for a given module.
        
        Because we only deal with our inlined module, we don't have to care about path or target.
        The import machinery also takes care of fully resolving all names, so we just have to deal with the fullnames.
        """
        if fullname in cls.inlined_modules:
            
            ms = ModuleSpec(fullname, cls, origin=cls.get_filename(fullname), is_package=cls.is_package(fullname))
            ms.has_location = True
            if cls.namespace_packages and ms.submodule_search_locations is not None:
                for p in _sys.path:
                    ms.submodule_search_locations.append(_os.path.join(p, _os.path.dirname(ms.origin)))
            return ms

        return None

    @staticmethod
    def _call_with_frames_removed(f, *args, **kwds):
        """remove_importlib_frames in import.c will always remove sequences
        of importlib frames that end with a call to this function

        Use it instead of a normal call in places where including the importlib
        frames introduces unwanted noise into the traceback (e.g. when executing
        module code)
        """
        return f(*args, **kwds)

    @classmethod
    def create_module(cls, spec):
        """Create a module using the default machinery."""
        return None

    @classmethod
    def exec_module(cls, module):
        """Execute the module."""
        code = cls.get_code(module.__name__)
        if code is None:
            raise ImportError("cannot load module {!r} when get_code() returns None".format(module.__name__))
        cls._call_with_frames_removed(exec, code, module.__dict__)

    @classmethod
    @_lru_cache(maxsize=None)
    def get_filename(cls, fullname):
        """Returns the 

        Raises ImportError if the module cannot be found.
        """
        if fullname not in cls.inlined_modules:
            raise ImportError

        mod = cls.inlined_modules[fullname]
        origin = fullname
        if mod[0]:
            origin = ".".join([origin, "__init__"])
        origin = ".".join([origin.replace(".", "/"), "py"])

        return origin

    @classmethod
    @_lru_cache(maxsize=None)
    def is_package(cls, fullname):
        if fullname not in cls.inlined_modules:
            raise ImportError

        return cls.inlined_modules[fullname][0]

    @classmethod
    def get_source(cls, fullname):
        if fullname not in cls.inlined_modules:
            raise ImportError

        return cls.inlined_modules[fullname][1]

    @classmethod
    def get_code(cls, fullname):
        """Method to return the code object for fullname.

        Should return None if not applicable (e.g. built-in module).
        Raise ImportError if the module cannot be found.
        """
        source = cls.get_source(fullname)
        if source is None:
            return None
        try:
            path = cls.get_filename(fullname)
        except ImportError:
            return cls.source_to_code(source)
        else:
            return cls.source_to_code(source, path)


InlineImporter.version = '0.0.4'
InlineImporter.inlined_modules = {
    'lib.array2d': (False, "class Array2dView:\n    def __init__(self, arr, i_indices, j_indices):\n        self.arr = arr\n        self.i_indices = i_indices\n        self.j_indices = j_indices\n    \n    def _get_view(self, i, j):\n        i = self.i_indices[i]\n        j = self.j_indices[j]\n        return Array2dView(self.arr, i, j)\n\n    def get_ind(self, i, j):\n        return self.i_indices[i]+self.j_indices[j]\n    \n    def __getitem__(self, index):\n        i, j = index\n        try:\n            return self.arr[self.get_ind(i,j)]\n        except TypeError:\n            return self._get_view(i, j)\n    \n    def __setitem__(self, index, value):\n        i, j = index\n        try:\n            self.arr[self.get_ind(i,j)] = value\n        except TypeError:\n            x = self._get_view(i, j)\n            for i in x.i_indices:\n                for j in x.j_indices:\n                    self.arr[i+j] = value\n    \n    def __iter__(self):\n        for i in self.i_indices:\n            for j in self.j_indices:\n                yield self.arr[i+j]\n    \n    def __reversed__(self):\n        for i in reversed(self.i_indices):\n            for j in reversed(self.j_indices):\n                yield self.arr[i+j]\n    \n    def __str__(self):\n        m = max(len(str(v)) for v in self)\n        res = ['']*len(self.i_indices)\n        row = ['']*(len(self.j_indices)+2)\n        for ri,i in enumerate(self.i_indices):\n            if ri == 0:\n                row[0] = '['\n            else:\n                row[0] = ' '\n            if ri == len(self.i_indices)-1:\n                row[-1] = ']\\n'\n            for rj,j in enumerate(self.j_indices):\n                row[rj+1] = f'{str(self.arr[i+j]):>{m+1}}'\n            res[ri] = ''.join(row)\n        return '\\n'.join(res)\n    \n    def copy(self):\n        return Array2d(len(self.i_indices), len(self.j_indices), list(self))\n\n\nclass Array2d:\n    def __init__(self, n, m, arr):\n        self.n = n\n        self.m = m\n        self.arr = arr\n    \n    @classmethod\n    def full(cls, n, m, fill_value):\n        return cls(n, m, [fill_value]*(n*m))\n    \n    @classmethod\n    def from_list(cls, lst):\n        n,m = len(lst), len(lst[0])\n        arr = [lst[0]]*(n*m)\n        k = 0\n        for row in lst:\n            for v in row:\n                arr[k] = v\n                k += 1\n        return cls(n, m, arr)\n    \n    def _get_view(self, i, j):\n        i = tuple(range(0, self.n*self.m, self.m))[i]\n        j = tuple(range(self.m))[j]\n        return Array2dView(self.arr, i, j)\n\n    def get_ind(self, i, j):\n        return i*self.m+j\n\n    def __getitem__(self, index):\n        try:\n            return self.arr[self.get_ind(*index)]\n        except TypeError:\n            return self._get_view(*index)\n    \n    def __setitem__(self, index, value):\n        try:\n            self.arr[self.get_ind(*index)] = value\n        except TypeError:\n            x = self._get_view(*index)\n            for i in x.i_indices:\n                for j in x.j_indices:\n                    self.arr[i+j] = value\n    \n    def __iter__(self):\n        return iter(self.arr)\n    \n    def __reversed__(self):\n        return reversed(self.arr)\n    \n    def __str__(self):\n        m = max(len(str(v)) for v in self)\n        res = ['']*self.n\n        row = ['']*(self.m+2)\n        for i in range(self.n):\n            if i == 0:\n                row[0] = '['\n            else:\n                row[0] = ' '\n            if i == self.n-1:\n                row[-1] = ']\\n'\n            for j in range(self.m):\n                row[j+1] = f'{str(self.arr[i*self.m+j]):>{m+1}}'\n            res[i] = ''.join(row)\n        return '\\n'.join(res)\n\n    def __eq__(self, other):\n        return self.arr == other.arr\n\n    def copy(self):\n        return self.__class__(self.n, self.m, self.arr[:])\n\n    @property\n    def t(self):\n        arr = [self.arr[0]]*(len(self.arr))\n        x = 0\n        for i in range(self.n):\n            for j in range(self.m):\n                arr[j*self.n + i] = self.arr[x]\n                x += 1\n        return self.__class__(self.m, self.n, arr)\n"),
    'lib.data_structure': (False, 'from itertools import repeat\n\n\nclass DisjointSet:\n    def __init__(self, parent):\n        self.parent = parent\n\n    @classmethod\n    def empty(cls, size):\n        return cls([-1]*size)\n\n    def find(self, x):\n        stack = []\n        while self.parent[x] >= 0:\n            stack.append(x)\n            x = self.parent[x]\n        for y in stack:\n            self.parent[y] = x\n        return x\n\n    def union_reps(self, xr, yr):\n        if xr == yr:\n            return xr\n        if self.parent[xr] > self.parent[yr]:\n            xr, yr = yr, xr\n        self.parent[xr] += self.parent[yr]\n        self.parent[yr] = xr\n        return xr\n\n    def union(self, x, y):\n        return self.union_reps(self.find(x), self.find(y))\n\n    def group_size(self, x):\n        return -self.parent[self.find(x)]\n\n    def is_rep(self, x):\n        return self.parent[x] < 0\n\n\nclass SegmentTree:\n    """\n    ???????????????????????????????????\n    ???????????????????????????(???????????)\n    """\n\n    @classmethod\n    def all_identity(cls, operator, identity, size):\n        return cls(operator, identity, [identity] * (2 << (size - 1).bit_length()))\n\n    @classmethod\n    def from_initial_data(cls, operator, identity, data):\n        size = 1 << (len(data) - 1).bit_length()\n        temp = [identity] * (2 * size)\n        temp[size:size + len(data)] = data\n        data = temp\n\n        for i in reversed(range(size)):\n            data[i] = operator(data[2 * i], data[2 * i + 1])\n        return cls(operator, identity, data)\n\n    
    'lib.misc': (False, 'from typing import List, Any, Callable, Sequence, Union, Tuple, TypeVar\n\nV = TypeVar(\'V\')\n\nimport sys\nfrom functools import reduce\nfrom itertools import accumulate\nfrom lib.data_structure import BinaryIndexedTree, DisjointSet\nimport bisect\n\n\ndef general_bisect(ng: int, ok: int, judge: Callable[[int], V]) -> int:\n    """\n    ???????????????????O(log L)??????\n\n    :param ng: judge(ng)==False????\n    :param ok: judge(ok)==True????\n    :param judge: ??????????\n    :return: judge(x)==True???????????\n    """\n    while abs(ng - ok) > 1:\n        m = (ng + ok) // 2\n        if judge(m):\n            ok = m\n        else:\n            ng = m\n    return ok\n\n\ndef fibonacci_search(left: int, right: int, func: Union[Callable[[int], V], Sequence], inf: V = 2 ** 60) -> Tuple[\n    V, int]:\n    """\n    ??????????????????????????????O(log L)??????\n    ???(left, right)?????????\n\n    :param left: ?????????????\n    :param right: ?????????????\n    :param func: ??????\n    :param inf: func???\n    :return: (func????, ????????func???)\n    """\n    try:\n        func = func.__getitem__\n    except AttributeError:\n        pass\n    f1, f2 = 1, 1\n    while f1 + f2 < right - left:\n        f1, f2 = f1 + f2, f1\n    l = left\n    m1 = func(l + f2)\n    m2 = func(l + f1)\n    while f1 > 2:\n        f1, f2 = f2, f1 - f2\n        if m1 > m2:\n            l += f1\n            m1 = m2\n            m2 = func(l + f1) if l + f1 < right else inf\n        else:\n            m2 = m1\n            m1 = func(l + f2)\n    if m1 < m2:\n        return m1, l + 1\n    else:\n        return m2, l + 2\n\n\ndef max2(x: V, y: V) -> V:\n    return x if x > y else y\n\n\ndef min2(x: V, y: V) -> V:\n    return x if x < y else y\n\n\nread = sys.stdin.buffer.read\nreadline = sys.stdin.buffer.readline\n\n\ndef rerooting(rooted_tree, merge, identity, finalize):\n    """\n    merge: (T,T) -> T, (T, merge)?????\n    identity: ???\n    finalize: (T, V, V) -> T\n\n    ????????dp?????\n    dp[u,v] = finalize(merge(dp[v,k] for k in adj[v] if k != u), u, v)\n    ???(u,v)?? u->v\n    """\n    N = rooted_tree.n_vertices\n    parent = rooted_tree.parent\n    children = rooted_tree.children\n    order = rooted_tree.dfs_order\n\n    
    'lib': (True, ''),
}
_sys.meta_path.insert(2, InlineImporter)


from lib.misc import read, max2
from math import gcd

def solve(a, d):
    def helper(b):
        r = 0
        cnt = 0
        for v in b:
            if v:
                cnt += 1
            else:
                r = max2(r, cnt)
                cnt = 0
        for v in b:
            if v:
                cnt += 1
            else:
                r = max2(r, cnt)
                cnt = 0
        r = max2(r, cnt)
        return r

    res = 0
    q = gcd(len(a), d)
    for i0 in range(q):
        t = []
        i = i0
        for _ in range(len(a)//q):
            t.append(a[i])
            i = (i+d)%len(a)
        res = max2(res, helper(t))
    return -1 if res >= len(a)//q else res


mm = map(int, read().split())
t = next(mm)
for _ in range(t):
    n, d = next(mm), next(mm)
    a = [v for _,v in zip(range(n), mm)]
    print(solve(a, d))